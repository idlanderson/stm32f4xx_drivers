#ifndef SPI_TYPES_HPP_
#define SPI_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::spi
{
	enum class ClockPhase : uint8_t
	{
		FirstClockTransition = 0U,
		SecondClockTransition = 1U,
	};

	enum class ClockPolarity : uint8_t
	{
		CkTo0WhenIdle = 0U,
		CkTo1WhenIdle = 1U,
	};

	enum class MasterSelection : uint8_t
	{
		Slave = 0U,
		Master = 1U,
	};

	enum class BaudRateControl : uint8_t
	{
		FpclkDiv2 = 0U,
		FpclkDiv4 = 1U,
		FpclkDiv8 = 2U,
		FpclkDiv16 = 3U,
		FpclkDiv32 = 4U,
		FpclkDiv64 = 5U,
		FpclkDiv128 = 6U,
		FpclkDiv256 = 7U,
	};

	enum class SpiEnable : uint8_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class LsbFirst : uint8_t
	{
		MsbTransmittedFirst = 0U,
		LsbTransmittedFirst = 1U,
	};

	enum class InternalSlaveSelect : uint8_t
	{
		DriveNssLow = 0U,
		DriveNssHigh = 1U,
	};

	enum class SoftwareSlaveManagement : uint8_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class ReceiveOnly : uint8_t
	{
		FullDuplex = 0U,
		OutputDisabled = 1U,
	};

	enum class DataFrameFormat : uint8_t
	{
		_8Bit = 0U,
		_16Bit = 1U,
	};

	enum class CrcTransferNext : uint8_t
	{
		DataPhase = 0U,
		NextTransferIsCrc = 1U,
	};

	enum class HardwareCrcCalculationEnable : uint8_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class OutputEnableInBidirectionalMode : uint8_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class BidirectionalDataModeEnable : uint8_t
	{
		_2LineUnidirectional = 0U,
		_1LineBidirectional = 1U,
	};

	enum class RxBufferDmaEnable : uint8_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class TxBufferDmaEnable : uint8_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class SsOutputEnable : uint8_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class FrameFormat : uint8_t
	{
		MotorolaMode = 0U,
		TiMode = 1U,
	};

	enum class ErrorInterruptEnable : uint8_t
	{
		Masked = 0U,
		Enabled = 1U,
	};

	enum class RxBufferNotEmptyInterruptEnable : uint8_t
	{
		Masked = 0U,
		NotMasked = 1U,
	};

	enum class TxBufferEmptyInterruptEnable : uint8_t
	{
		Masked = 0U,
		NotMasked = 1U,
	};

	enum class ReceiveBufferNotEmpty : uint8_t
	{
		Empty = 0U,
		NotEmpty = 1U,
	};

	enum class TransmitBufferEmpty : uint8_t
	{
		NotEmpty = 0U,
		Empty = 1U,
	};

	enum class ChannelSide : uint8_t
	{
		Left = 0U,
		Right = 1U,
	};

	enum class UnderrunFlag : uint8_t
	{
		NoUnderrunOccurred = 0U,
		UnderrunOccurred = 1U,
	};

	enum class CrcErrorFlag : uint8_t
	{
		Matches = 0U,
		DoesNotMatch = 1U,
	};

	enum class ModeFault : uint8_t
	{
		NoModeFault = 0U,
		ModeFault = 1U,
	};

	enum class OverrunFlag : uint8_t
	{
		NoOverrunOccurred = 0U,
		OverrunOccurred = 1U,
	};

	enum class BusyFlag : uint8_t
	{
		NotBusy = 0U,
		Busy = 1U,
	};

	enum class FrameFormatError : uint8_t
	{
		NoFrameFormatError = 0U,
		FrameFormatErrorOccurred = 1U,
	};

	enum class ChannelLength : uint8_t
	{
		_16Bit = 0U,
		_32Bit = 1U,
	};

	enum class DataLengthToBeTransferred : uint8_t
	{
		_16Bit = 0U,
		_24Bit = 1U,
		_32Bit = 2U,
		NotAllowed = 3U,
	};

	enum class SteadyStateClockPolarity : uint8_t
	{
		Low = 0U,
		High = 1U,
	};

	enum class I2SStandardSelection : uint8_t
	{
		I2SPhilipsStandard = 0U,
		MsbJustifiedStandard = 1U,
		LsbJustifiedStandard = 2U,
		PcmStandard = 3U,
	};

	enum class PcmFrameSynchronization : uint8_t
	{
		ShortFrame = 0U,
		LongFrame = 1U,
	};

	enum class I2SConfigurationMode : uint8_t
	{
		SlaveTransmit = 0U,
		SlaveReceive = 1U,
		MasterTransmit = 2U,
		MasterReceive = 3U,
	};

	enum class I2SEnable : uint8_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class I2SModeSelection : uint8_t
	{
		SpiMode = 0U,
		I2SMode = 1U,
	};

	enum class OddFactorForThePrescaler : uint8_t
	{
		I2SdivTimes2 = 0U,
		I2SdivTimes2Plus1 = 1U,
	};

	enum class MasterClockOutputEnable : uint8_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

}
#endif // SPI_TYPES_HPP_