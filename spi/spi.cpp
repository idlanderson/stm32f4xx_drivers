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
/*
    void SpiPeripheral::SetBusConfig(BusConfig busConfig)
    {
        if (busConfig == BusConfig::FullDuplex)
        {
            SetBidirectionalMode(BidirectionalMode::Unidirectional);
            SetRxOnly(RxOnly::FullDuplex_TxAndRx);
        }
        else if (busConfig == BusConfig::HalfDuplex)
        {
            SetBidirectionalMode(BidirectionalMode::Bidirectional);
            SetRxOnly(RxOnly::FullDuplex_TxAndRx);
        }
        else if (busConfig == BusConfig::SimplexRxOnly)
        {
            SetBidirectionalMode(BidirectionalMode::Unidirectional);
            SetRxOnly(RxOnly::OutputDisabled_RxOnly);
        }
    }
*/

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

    void SpiPeripheral::SendData(std::vector<uint8_t> data)
    {
        uint32_t remainingLengthToSend = data.size();
        uint32_t currentIndex = 0U;
        DataFrameFormat dataFrameFormat = GetDataFrameFormat();

        while (remainingLengthToSend > 0U)
        {
            while (!IsTransmitBufferEmpty());

            if (dataFrameFormat == DataFrameFormat::Value0)
            {
                device.set_DR_DR(0x0000U | data[currentIndex]);
                remainingLengthToSend--;
                currentIndex++;
            }
            else if (dataFrameFormat == DataFrameFormat::Value1)
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

    std::vector<uint8_t> SpiPeripheral::ReceiveData(uint32_t length)
    {
        uint32_t remainingLengthToReceive = length;
        DataFrameFormat dataFrameFormat = GetDataFrameFormat();
        std::vector<uint8_t> dataReceived;

        while (remainingLengthToReceive > 0U)
        {
            while (!IsReceiveBufferNotEmpty()); // While the RxBuffer is NOT NOT empty (i.e. while it's empty).

            if (dataFrameFormat == DataFrameFormat::Value0)
            {
                uint8_t data = (uint8_t)device.get_DR_DR();
                dataReceived.push_back(data);
                remainingLengthToReceive--;
            }
            else if (dataFrameFormat == DataFrameFormat::Value1)
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
}