#ifndef SPI_TYPES_HPP_
#define SPI_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::spi
{
	enum class ClockPhase : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class ClockPolarity : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class MasterSelection : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class BaudRateControl : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
		Value2 = 2U,
		Value3 = 3U,
		Value4 = 4U,
		Value5 = 5U,
		Value6 = 6U,
		Value7 = 7U,
	};

	enum class SpiEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class LsbFirst : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class InternalSlaveSelect : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class SoftwareSlaveManagement : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class ReceiveOnly : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class DataFrameFormat : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class CrcTransferNext : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class HardwareCrcCalculationEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class OutputEnableInBidirectionalMode : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class BidirectionalDataModeEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class RxBufferDmaEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class TxBufferDmaEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class SsOutputEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class FrameFormat : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class ErrorInterruptEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class RxBufferNotEmptyInterruptEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class TxBufferEmptyInterruptEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class ReceiveBufferNotEmpty : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class TransmitBufferEmpty : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class ChannelSide : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class UnderrunFlag : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class CrcErrorFlag : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class ModeFault : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class OverrunFlag : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class BusyFlag : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class FrameFormatError : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class ChannelLength : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class DataLengthToBeTransferred : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
		Value2 = 2U,
		Value3 = 3U,
	};

	enum class SteadyStateClockPolarity : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class I2SStandardSelection : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
		Value2 = 2U,
		Value3 = 3U,
	};

	enum class PcmFrameSynchronization : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class I2SConfigurationMode : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
		Value2 = 2U,
		Value3 = 3U,
	};

	enum class I2SEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class I2SModeSelection : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class OddFactorForThePrescaler : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

	enum class MasterClockOutputEnable : uint8_t
	{
		Value0 = 0U,
		Value1 = 1U,
	};

}
#endif // SPI_TYPES_HPP_