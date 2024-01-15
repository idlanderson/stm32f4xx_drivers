#ifndef I2C_TYPES_HPP_
#define I2C_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::i2c
{
	using Reserved = uint32_t;

	enum class PeripheralEnable : uint32_t
	{
		PeripheralDisable = 0U,
		PeripheralEnable = 1U,
	};

	enum class ClockStretchingDisable : uint32_t
	{
		ClockStretchingEnabled = 0U,
		ClockStretchingDisabled = 1U,
	};

	enum class StartGeneration : uint32_t
	{
		NoStartGeneration = 0U,
		StartGeneration = 1U,
	};

	enum class StopGeneration : uint32_t
	{
		NoStopGeneration = 0U,
		StopGeneration = 1U,
	};

	enum class AcknowledgeEnable : uint32_t
	{
		NoAcknowledgeReturned = 0U,
		AcknowledgeReturned = 1U,
	};

	enum class AddressingMode : uint32_t
	{
		_7BitSlaveAddress = 0U,
		_10BitSlaveAddress = 1U,
	};

	enum class DualAddressingModeEnable : uint32_t
	{
		OnlyOar1 = 0U,
		BothOar1AndOar2 = 1U,
	};

	enum class StartBit : uint32_t
	{
		NoStartCondition = 0U,
		StartConditionGenerated = 1U,
	};

	enum class AddressSentMatched : uint32_t
	{
		AddressMismatchedOrNotTransmitted = 0U,
		AddressMatchedOrTransmitted = 1U,
	};

	enum class ByteTransferFinished : uint32_t
	{
		NotDone = 0U,
		Succeeded = 1U,
	};

	enum class StopDetection : uint32_t
	{
		NoStopConditionDetected = 0U,
		StopConditionDetected = 1U,
	};

	enum class DataRegisterNotEmpty : uint32_t
	{
		Empty = 0U,
		NotEmpty = 1U,
	};

	enum class DataRegisterEmpty : uint32_t
	{
		NotEmpty = 0U,
		Empty = 1U,
	};

	enum class BusError : uint32_t
	{
		NoMisplacedStartOrStopCondition = 0U,
		MisplacedStartOrStopCondition = 1U,
	};

	enum class ArbitrationLost : uint32_t
	{
		NoArbitrationLostDetected = 0U,
		ArbitrationLostDetected = 1U,
	};

	enum class AcknowledgeFailure : uint32_t
	{
		NoAcknowledgeFailure = 0U,
		AcknowledgeFailure = 1U,
	};

	enum class OverrunUnderrun : uint32_t
	{
		NoOverrunUnderrun = 0U,
		OverrunOrUnderrun = 1U,
	};

	enum class TimeoutError : uint32_t
	{
		NoTimeoutError = 0U,
		TimeoutError = 1U,
	};

	enum class MasterSlave : uint32_t
	{
		SlaveMode = 0U,
		MasterMode = 1U,
	};

	enum class BusBusy : uint32_t
	{
		NoCommunication = 0U,
		CommunicationOngoing = 1U,
	};

	enum class TransmitterReceiver : uint32_t
	{
		DataBytesReceived = 0U,
		DataBytesTransmitted = 1U,
	};

	enum class FmModeDutyCycle : uint32_t
	{
		Ratio2 = 0U,
		Ratio16Over9 = 1U,
	};

	enum class MasterModeSelection : uint32_t
	{
		StandardMode = 0U,
		FastMode = 1U,
	};

}
#endif // I2C_TYPES_HPP_