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
		LowHighRatio2 = 0U,
		LowHighRadio16Over9 = 1U,
	};

	enum class MasterModeSelection : uint32_t
	{
		StandardMode = 0U,
		FastMode = 1U,
	};

}
#endif // I2C_TYPES_HPP_