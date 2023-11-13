#ifndef SPI_HPP_H_
#define SPI_HPP_H_

#include "stm32f4xx.hpp"
#include "spi_register_map.hpp"
#include <cstdint>
#include <vector>

namespace stm32::spi
{
    using SpiData = std::vector<uint8_t>;

    enum class BusConfig
    {
        FullDuplex,
        HalfDuplex,
        SimplexRxOnly
    };

    enum class SpiState
    {
        Ready,
        Sending,
        Receiving
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

        void SendData(const SpiData & data);
        SpiData ReceiveData(uint32_t length);

        void SendDataAsync(const SpiData & data);
        void ReceiveDataAsync(uint32_t length);

        void HandleIrq();

    private:

        void HandleSendDataIrq();
        void HandleReceiveDataIrq();
        void HandleOverrunErrorIrq();

        ISpiRegisterMap & device;

        SpiState state = SpiState::Ready;

        SpiData txBuffer;
        SpiData rxBuffer;
        uint32_t rxLength = 0U;
    };
}

#endif // SPI_HPP_H_