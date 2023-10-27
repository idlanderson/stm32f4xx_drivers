#ifndef SPI_TYPES_HPP_
#define SPI_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::spi
{
	using Reserved = uint32_t;

	enum class ClockPhase
	{
		FirstClockTransition = 0U,
		SecondClockTransition = 1U,
	};

	enum class ClockPolarity
	{
		CkTo0WhenIdle = 0U,
		CkTo1WhenIdle = 1U,
	};

	enum class MasterSelection
	{
		Slave = 0U,
		Master = 1U,
	};

	enum class BaudRateControl
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

	enum class SpiEnable
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class LsbFirst
	{
		MsbTransmittedFirst = 0U,
		LsbTransmittedFirst = 1U,
	};

	enum class InternalSlaveSelect
	{
		DriveNssLow = 0U,
		DriveNssHigh = 1U,
	};

	enum class SoftwareSlaveManagement
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class ReceiveOnly
	{
		FullDuplex = 0U,
		OutputDisabled = 1U,
	};

	enum class DataFrameFormat
	{
		_8Bit = 0U,
		_16Bit = 1U,
	};

	enum class CrcTransferNext
	{
		DataPhase = 0U,
		NextTransferIsCrc = 1U,
	};

	enum class HardwareCrcCalculationEnable
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class OutputEnableInBidirectionalMode
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class BidirectionalDataModeEnable
	{
		_2LineUnidirectional = 0U,
		_1LineBidirectional = 1U,
	};

	enum class RxBufferDmaEnable
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class TxBufferDmaEnable
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class SsOutputEnable
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class FrameFormat
	{
		MotorolaMode = 0U,
		TiMode = 1U,
	};

	enum class ErrorInterruptEnable
	{
		Masked = 0U,
		Enabled = 1U,
	};

	enum class RxBufferNotEmptyInterruptEnable
	{
		Masked = 0U,
		NotMasked = 1U,
	};

	enum class TxBufferEmptyInterruptEnable
	{
		Masked = 0U,
		NotMasked = 1U,
	};

	enum class ReceiveBufferNotEmpty
	{
		Empty = 0U,
		NotEmpty = 1U,
	};

	enum class TransmitBufferEmpty
	{
		NotEmpty = 0U,
		Empty = 1U,
	};

	enum class ChannelSide
	{
		Left = 0U,
		Right = 1U,
	};

	enum class UnderrunFlag
	{
		NoUnderrunOccurred = 0U,
		UnderrunOccurred = 1U,
	};

	enum class CrcErrorFlag
	{
		Matches = 0U,
		DoesNotMatch = 1U,
	};

	enum class ModeFault
	{
		NoModeFault = 0U,
		ModeFault = 1U,
	};

	enum class OverrunFlag
	{
		NoOverrunOccurred = 0U,
		OverrunOccurred = 1U,
	};

	enum class BusyFlag
	{
		NotBusy = 0U,
		Busy = 1U,
	};

	enum class FrameFormatError
	{
		NoFrameFormatError = 0U,
		FrameFormatErrorOccurred = 1U,
	};

	enum class ChannelLength
	{
		_16Bit = 0U,
		_32Bit = 1U,
	};

	enum class DataLengthToBeTransferred
	{
		_16Bit = 0U,
		_24Bit = 1U,
		_32Bit = 2U,
		NotAllowed = 3U,
	};

	enum class SteadyStateClockPolarity
	{
		Low = 0U,
		High = 1U,
	};

	enum class I2SStandardSelection
	{
		I2SPhilipsStandard = 0U,
		MsbJustifiedStandard = 1U,
		LsbJustifiedStandard = 2U,
		PcmStandard = 3U,
	};

	enum class PcmFrameSynchronization
	{
		ShortFrame = 0U,
		LongFrame = 1U,
	};

	enum class I2SConfigurationMode
	{
		SlaveTransmit = 0U,
		SlaveReceive = 1U,
		MasterTransmit = 2U,
		MasterReceive = 3U,
	};

	enum class I2SEnable
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class I2SModeSelection
	{
		SpiMode = 0U,
		I2SMode = 1U,
	};

	enum class OddFactorForThePrescaler
	{
		I2SdivTimes2 = 0U,
		I2SdivTimes2Plus1 = 1U,
	};

	enum class MasterClockOutputEnable
	{
		Disabled = 0U,
		Enabled = 1U,
	};

}
#endif // SPI_TYPES_HPP_