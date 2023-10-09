#ifndef SPI_HPP_H_
#define SPI_HPP_H_

#include "stm32f4xx.hpp"
#include "spi_reg.hpp"
#include <cstdint>
#include <vector>

using DeviceRegister = std::uint32_t volatile;

class SPI
{
public:

    enum class DeviceMode
    {
        Slave = 0U,
        Master = 1U
    };

    enum class BusConfig
    {
        FullDuplex = 0U,
        HalfDuplex = 1U,
        SimplexRxOnly = 2U
    };

    enum class RxOnly
    {
        FullDuplex_TxAndRx    = 0U,
        OutputDisabled_RxOnly = 1U
    };

    enum class BaudRate
    {
        Div2   = 0U,
        Div4   = 1U,
        Div8   = 2U,
        Div16  = 3U,
        Div32  = 4U,
        Div64  = 5U,
        Div128 = 6U,
        Div256 = 7U
    };

    enum class DataFrameFormat
    {
        EightBit  = 0U,
        SixteenBit = 1U
    };

    enum class ClockPolarity
    {
        Low = 0U,  
        High = 1U
    };

    enum class ClockPhase
    {
        FirstEdge = 0U,
        SecondEdge = 1U
    };

    enum class SlaveManagement
    {
        Hardware = 0U,
        Software = 1U
    };

    enum class BidirectionalMode
    {
        Unidirectional = 0U,
        Bidirectional  = 1U
    };

    enum class OutputEnableInBidirectionalMode
    {
        Disabled_RxOnly = 0U,
        Enabled_TxOnly  = 1U
    };

    DataFrameFormat GetDataFrameFormat() const;

    void SetDeviceMode(DeviceMode deviceMode);
    void SetBidirectionalMode(BidirectionalMode mode);
    void SetRxOnly(RxOnly rxOnly);
    void SetBusConfig(BusConfig busConfig);
    void SetOutputEnableInBidirectionalMode(OutputEnableInBidirectionalMode isEnabled);
    void SetDataFrameFormat(DataFrameFormat format);
    void SetClockPolarity(ClockPolarity polarity);
    void SetClockPhase(ClockPhase phase);
    void SetBaudRate(BaudRate baudRate);
    void SetSlaveManagement(SlaveManagement slaveManagement);
    void SetInternalSlaveSelect(bool isEnabled);
    void SetSlaveSelectOutputEnabled(bool isEnabled);
    
    void PeripheralControl(bool isEnabled);

    bool IsReceiveBufferNotEmpty() const;
    bool IsTransmitBufferEmpty() const;
    bool HasCrcErrorOccurred() const;
    bool HasModeFaultOccurred() const;
    bool HasOverrunOccurred() const;
    bool IsBusy() const;

    uint32_t ReadData() const;
    void WriteData(uint32_t data);

private:

	DeviceRegister CR1;			/* Address Offset 0x00.  */
	DeviceRegister CR2;			/* Address Offset 0x04.  */
	DeviceRegister SR;			/* Address Offset 0x08.  */
	DeviceRegister DR;			/* Address Offset 0x0C.  */
	DeviceRegister CRCPR;		/* Address Offset 0x10.  */
	DeviceRegister RXCRCR;		/* Address Offset 0x14.  */
	DeviceRegister TXCRCR;		/* Address Offset 0x18.  */
	DeviceRegister I2SCFGR;		/* Address Offset 0x1C.  */
	DeviceRegister I2SPR;		/* Address Offset 0x20.  */

    void SetRegField_1Bit(DeviceRegister & reg, uint8_t position, uint8_t value);
    void SetRegField_2Bits(DeviceRegister & reg, uint8_t position, uint8_t value);
    void SetRegField_3Bits(DeviceRegister & reg, uint8_t position, uint8_t value);

    const uint8_t MaxPositionFor1BitField = 31U;
    const uint8_t MaxValueFor1BitField    = 1U;
    const uint8_t MaxPositionFor2BitField = 15U;
    const uint8_t MaxValueFor2BitField    = 3U;
    const uint8_t MaxPositionFor3BitField = 10U;
    const uint8_t MaxValueFor3BitField    = 7U;
};

#endif // SPI_HPP_H_