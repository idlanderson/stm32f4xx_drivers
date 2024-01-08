#include "spi.hpp"

namespace stm32::spi
{
    void SpiPeripheral::SetDeviceMode(MasterSelection deviceMode)
    {
        device.set_CR1_MSTR(deviceMode);
    }

    void SpiPeripheral::SetBidirectionalMode(BidirectionalDataModeEnable mode)
    {
        device.set_CR1_BIDIMODE(mode);
    }

    void SpiPeripheral::SetOutputEnableInBidirectionalMode(OutputEnableInBidirectionalMode isEnabled)
    {
        device.set_CR1_BIDIOE(isEnabled);
    }

    void SpiPeripheral::SetRxOnly(ReceiveOnly rxOnly)
    {
        device.set_CR1_RXONLY(rxOnly);
    }

    void SpiPeripheral::SetBusConfig(BusConfig busConfig)
    {
        if (busConfig == BusConfig::FullDuplex)
        {
            SetBidirectionalMode(BidirectionalDataModeEnable::_2LineUnidirectional);
            SetRxOnly(ReceiveOnly::FullDuplex);
        }
        else if (busConfig == BusConfig::HalfDuplex)
        {
            SetBidirectionalMode(BidirectionalDataModeEnable::_1LineBidirectional);
            SetRxOnly(ReceiveOnly::FullDuplex);
        }
        else if (busConfig == BusConfig::SimplexRxOnly)
        {
            SetBidirectionalMode(BidirectionalDataModeEnable::_2LineUnidirectional);
            SetRxOnly(ReceiveOnly::OutputDisabled);
        }
    }

    DataFrameFormat SpiPeripheral::GetDataFrameFormat() const
    {
        return device.get_CR1_DFF();
    }

    void SpiPeripheral::SetDataFrameFormat(DataFrameFormat format)
    {
        device.set_CR1_DFF(format);
    }

    void SpiPeripheral::SetClockPolarity(ClockPolarity polarity)
    {
        device.set_CR1_CPOL(polarity);
    }

    void SpiPeripheral::SetClockPhase(ClockPhase phase)
    {
        device.set_CR1_CPHA(phase);
    }

    void SpiPeripheral::SetBaudRate(BaudRateControl baudRate)
    {
        device.set_CR1_BR(baudRate);
    }

    void SpiPeripheral::SetSlaveManagement(SoftwareSlaveManagement slaveManagement)
    {
        device.set_CR1_SSM(slaveManagement);
    }

    void SpiPeripheral::SetInternalSlaveSelect(InternalSlaveSelect isEnabled)
    {
        device.set_CR1_SSI(isEnabled);
    }

    void SpiPeripheral::SetSlaveSelectOutputEnabled(SsOutputEnable isEnabled)
    {
        device.set_CR2_SSOE(isEnabled);
    }

    void SpiPeripheral::SetEnabled(SpiEnable isEnabled)
    {
        device.set_CR1_SPE(isEnabled);
    }

    bool SpiPeripheral::IsReceiveBufferNotEmpty() const
    {
        return (bool)device.get_SR_RXNE();
    }

    bool SpiPeripheral::IsTransmitBufferEmpty() const
    {
        return (bool)device.get_SR_TXE();
    }

    bool SpiPeripheral::HasCrcErrorOccurred() const
    {
        return (bool)device.get_SR_CRCERR();
    }

    bool SpiPeripheral::HasModeFaultOccurred() const
    {
        return (bool)device.get_SR_MODF();
    }

    bool SpiPeripheral::HasOverrunOccurred() const
    {
        return (bool)device.get_SR_OVR();
    }

    bool SpiPeripheral::IsBusy() const
    {
        return (bool)device.get_SR_BSY();
    }

    void SpiPeripheral::SendData(const SpiData & data)
    {
        uint32_t remainingLengthToSend = data.size();
        uint32_t currentIndex = 0U;
        DataFrameFormat dataFrameFormat = GetDataFrameFormat();

        while (remainingLengthToSend > 0U)
        {
            while (!IsTransmitBufferEmpty());

            if (dataFrameFormat == DataFrameFormat::_8Bit)
            {
                device.set_DR_DR(0x0000U | data[currentIndex]);
                remainingLengthToSend--;
                currentIndex++;
            }
            else if (dataFrameFormat == DataFrameFormat::_16Bit)
            {
                device.set_DR_DR((data[currentIndex] << 8U) | data[currentIndex + 1U]);
                remainingLengthToSend -= 2U;
                currentIndex += 2U;
            }
            else
            {
                remainingLengthToSend = 0U;
            }
        }
    }

    SpiData SpiPeripheral::ReceiveData(uint32_t length)
    {
        uint32_t remainingLengthToReceive = length;
        DataFrameFormat dataFrameFormat = GetDataFrameFormat();
        SpiData dataReceived;

        while (remainingLengthToReceive > 0U)
        {
            while (!IsReceiveBufferNotEmpty()); // While the RxBuffer is NOT NOT empty (i.e. while it's empty).

            if (dataFrameFormat == DataFrameFormat::_8Bit)
            {
                uint8_t data = (uint8_t)device.get_DR_DR();
                dataReceived.push_back(data);
                remainingLengthToReceive--;
            }
            else if (dataFrameFormat == DataFrameFormat::_16Bit)
            {
                uint16_t data = (uint16_t)device.get_DR_DR();
                dataReceived.push_back((uint8_t)(0x000000FFU & (data >> 8U)));
                dataReceived.push_back((uint8_t)(0x000000FFU & data));
                remainingLengthToReceive -= 2U;
            }
            else
            {
                remainingLengthToReceive = 0U;
            }
        }

        return dataReceived;
    }

    void SpiPeripheral::SendDataAsync(const SpiData & data)
    {
        if (state != SpiState::Ready)
        {
            return;
        }

        state = SpiState::Sending;
        txBuffer.assign(data.begin(), data.end());
        device.set_CR2_TXEIE(TxBufferEmptyInterruptEnable::NotMasked);
    }

    void SpiPeripheral::ReceiveDataAsync(uint32_t length)
    {
        if (state != SpiState::Ready)
        {
            return;
        }

        state = SpiState::Receiving;
        rxLength = length;
        device.set_CR2_RXNEIE(RxBufferNotEmptyInterruptEnable::NotMasked);
    }

    void SpiPeripheral::HandleIrq()
    {
        if (device.get_CR2_TXEIE() == TxBufferEmptyInterruptEnable::NotMasked &&
            device.get_SR_TXE() == TransmitBufferEmpty::Empty)
        {
            HandleSendDataIrq();
        }
        else if (
            device.get_CR2_RXNEIE() == RxBufferNotEmptyInterruptEnable::NotMasked &&
            device.get_SR_RXNE() == ReceiveBufferNotEmpty::NotEmpty)
        {
            HandleReceiveDataIrq();
        }
        else if (
            device.get_CR2_ERRIE() == ErrorInterruptEnable::Enabled &&
            device.get_SR_OVR() == OverrunFlag::OverrunOccurred)
        {
            HandleOverrunErrorIrq();
        }
        else
        {
            // TODO: Handle unknown IRQ.
        }
    }

    void SpiPeripheral::HandleSendDataIrq()
    {
        auto dataFrameFormat = GetDataFrameFormat();

        if (dataFrameFormat == DataFrameFormat::_8Bit)
        {
            uint8_t byteToSend = txBuffer[0];
            device.set_DR_DR(byteToSend);
            txBuffer.erase(txBuffer.begin());
        }
        else if (dataFrameFormat == DataFrameFormat::_16Bit)
        {
            uint8_t data0 = txBuffer[0];
            uint8_t data1 = txBuffer[1];
            txBuffer.erase(txBuffer.begin());
            txBuffer.erase(txBuffer.begin());
            device.set_DR_DR((data0 << 8U) | data1);
        }

        if (txBuffer.size() <= 0U)
        {
            device.set_CR2_TXEIE(TxBufferEmptyInterruptEnable::Masked);
            state = SpiState::Ready;

            // TODO: Call a callback.
        }
    }

    void SpiPeripheral::HandleReceiveDataIrq()
    {
        auto dataFrameFormat = GetDataFrameFormat();

        if (dataFrameFormat == DataFrameFormat::_8Bit)
        {
            uint8_t data = (uint8_t)device.get_DR_DR();
            rxBuffer.push_back(data);
            rxLength--;
        }
        else if (dataFrameFormat == DataFrameFormat::_16Bit)
        {
            uint16_t data = (uint16_t)device.get_DR_DR();
            rxBuffer.push_back((uint8_t)(0x000000FFU & (data >> 8U)));
            rxBuffer.push_back((uint8_t)(0x000000FFU & data));
            rxLength -= 2U;
        }

        if (rxLength <= 0U)
        {
            device.set_CR2_RXNEIE(RxBufferNotEmptyInterruptEnable::Masked);
            state = SpiState::Ready;

            // TODO: Call a callback.
        }
    }

    void SpiPeripheral::HandleOverrunErrorIrq()
    {
        // Clear the OVR flag.
        device.get_DR_DR();
        device.get_SR_OVR();
    }
}