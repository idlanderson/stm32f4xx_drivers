#include "spi.hpp"

namespace stm32::spi
{
    void SpiPeripheral::SetDeviceMode(DeviceMode deviceMode)
    {
        device.setMSTR((uint8_t)deviceMode);
    }

    void SpiPeripheral::SetBidirectionalMode(BidirectionalMode mode)
    {
        device.setBIDIMODE((uint8_t)mode);
    }

    void SpiPeripheral::SetOutputEnableInBidirectionalMode(OutputEnableInBidirectionalMode isEnabled)
    {
        device.setBIDIOE((uint8_t)isEnabled);
    }

    void SpiPeripheral::SetRxOnly(RxOnly rxOnly)
    {
        device.setRXONLY((uint8_t)rxOnly);
    }

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

    DataFrameFormat SpiPeripheral::GetDataFrameFormat() const
    {
        return (DataFrameFormat)device.getDFF();
    }

    void SpiPeripheral::SetDataFrameFormat(DataFrameFormat format)
    {
        device.setDFF((uint8_t)format);
    }

    void SpiPeripheral::SetClockPolarity(ClockPolarity polarity)
    {
        device.setCPOL((uint8_t)polarity);
    }

    void SpiPeripheral::SetClockPhase(ClockPhase phase)
    {
        device.setCPHA((uint8_t)phase);
    }

    void SpiPeripheral::SetBaudRate(BaudRate baudRate)
    {
        device.setBR((uint8_t)baudRate);
    }

    void SpiPeripheral::SetSlaveManagement(SlaveManagement slaveManagement)
    {
        device.setSSM((uint8_t)slaveManagement);
    }

    void SpiPeripheral::SetInternalSlaveSelect(bool isEnabled)
    {
        device.setSSI((uint8_t)isEnabled);
    }

    void SpiPeripheral::SetSlaveSelectOutputEnabled(bool isEnabled)
    {
        device.setSSOE((uint8_t)isEnabled);
    }

    void SpiPeripheral::SetEnabled(bool isEnabled)
    {
        device.setSPE((uint8_t)isEnabled);
    }

    bool SpiPeripheral::IsReceiveBufferNotEmpty() const
    {
        return (bool)device.getRXNE();
    }

    bool SpiPeripheral::IsTransmitBufferEmpty() const
    {
        return (bool)device.getTXE();
    }

    bool SpiPeripheral::HasCrcErrorOccurred() const
    {
        return (bool)device.getCRCERR();
    }

    bool SpiPeripheral::HasModeFaultOccurred() const
    {
        return (bool)device.getMODF();
    }

    bool SpiPeripheral::HasOverrunOccurred() const
    {
        return (bool)device.getOVR();
    }

    bool SpiPeripheral::IsBusy() const
    {
        return (bool)device.getBSY();
    }

    void SpiPeripheral::SendData(std::vector<uint8_t> data)
    {
        uint32_t remainingLengthToSend = data.size();
        uint32_t currentIndex = 0U;
        DataFrameFormat dataFrameFormat = GetDataFrameFormat();

        while (remainingLengthToSend > 0U)
        {
            while (!IsTransmitBufferEmpty());

            if (dataFrameFormat == DataFrameFormat::EightBit)
            {
                device.setDR(0x0000U | data[currentIndex]);
                remainingLengthToSend--;
                currentIndex++;
            }
            else if (dataFrameFormat == DataFrameFormat::SixteenBit)
            {
                device.setDR((data[currentIndex] << 8U) | data[currentIndex + 1U]);
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

            if (dataFrameFormat == DataFrameFormat::EightBit)
            {
                uint8_t data = (uint8_t)device.getDR();
                dataReceived.push_back(data);
                remainingLengthToReceive--;
            }
            else if (dataFrameFormat == DataFrameFormat::SixteenBit)
            {
                uint16_t data = (uint16_t)device.getDR();
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