#ifndef SPI_HPP_H_
#define SPI_HPP_H_

#include "stm32f4xx.hpp"
#include "spi_register_map.hpp"
#include <cstdint>
#include <vector>

namespace stm32::spi
{
    enum class BusConfig
    {
        FullDuplex,
        HalfDuplex,
        SimplexRxOnly
    };

    class SpiPeripheral
    {
    public:

        SpiPeripheral(ISpiRegisterMap & device) : device(device) { }
		SpiPeripheral(uint32_t addr) : device(*reinterpret_cast<SpiRegisterMap*>(addr)) { }

        DataFrameFormat GetDataFrameFormat() const;

        void SetDeviceMode(MasterSelection deviceMode);
        void SetBidirectionalMode(BidirectionalDataModeEnable mode);
        void SetRxOnly(ReceiveOnly rxOnly);
        void SetBusConfig(BusConfig busConfig);
        void SetOutputEnableInBidirectionalMode(OutputEnableInBidirectionalMode isEnabled);
        void SetDataFrameFormat(DataFrameFormat format);
        void SetClockPolarity(ClockPolarity polarity);
        void SetClockPhase(ClockPhase phase);
        void SetBaudRate(BaudRateControl baudRate);
        void SetSlaveManagement(SoftwareSlaveManagement slaveManagement);
        void SetInternalSlaveSelect(InternalSlaveSelect isEnabled);
        void SetSlaveSelectOutputEnabled(SsOutputEnable isEnabled);
        void SetEnabled(SpiEnable isEnabled);

        bool IsReceiveBufferNotEmpty() const;
        bool IsTransmitBufferEmpty() const;
        bool HasCrcErrorOccurred() const;
        bool HasModeFaultOccurred() const;
        bool HasOverrunOccurred() const;
        bool IsBusy() const;

        void SendData(std::vector<uint8_t> data);
        std::vector<uint8_t> ReceiveData(uint32_t length);

    private:

        ISpiRegisterMap & device;
    };
}

#endif // SPI_HPP_H_