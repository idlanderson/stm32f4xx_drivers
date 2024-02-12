#ifndef USART_TYPES_HPP_
#define USART_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::usart
{
	using Reserved = uint32_t;

	enum class ParityError : uint32_t
	{
		NoParityError = 0U,
		ParityError = 1U,
	};

	enum class FramingError : uint32_t
	{
		NoFramingErrorDetected = 0U,
		FramingErrorOrBreakDetected = 1U,
	};

	enum class NoiceDetectedFlag : uint32_t
	{
		NoNoiseDetected = 0U,
		NoiseDetected = 1U,
	};

	enum class OverrunError : uint32_t
	{
		NoOverrunError = 0U,
		OverrunErrorDetected = 1U,
	};

	enum class IdleLineDetected : uint32_t
	{
		NoIdleLineDetected = 0U,
		IdleLineDetected = 1U,
	};

	enum class ReadDataRegisterNotEmpty : uint32_t
	{
		DataNotReceived = 0U,
		ReceivedDataReady = 1U,
	};

	enum class TransmissionComplete : uint32_t
	{
		NotComplete = 0U,
		Complete = 1U,
	};

	enum class TransmitDataRegisterEmpty : uint32_t
	{
		NotTransferredToShiftRegister = 0U,
		TransferredToShiftRegister = 1U,
	};

	enum class LinBreakDetectionFlag : uint32_t
	{
		NotDetected = 0U,
		Detected = 1U,
	};

	enum class CtsFlag : uint32_t
	{
		NoChangeOnCtsLine = 0U,
		ChanGeOnCtsLine = 1U,
	};

	enum class SendBreak : uint32_t
	{
		NoBreakTransmitted = 0U,
		BreakTransmitted = 1U,
	};

	enum class ReceiverWakeup : uint32_t
	{
		ActiveMode = 0U,
		MuteMode = 1U,
	};

	enum class ReceiverEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class TransmitterEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class IdleInterruptEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class RxneInterruptEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class TcInterruptEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class TxeInterruptEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class PeInterruptEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class ParitySelection : uint32_t
	{
		Even = 0U,
		Odd = 1U,
	};

	enum class ParityControlEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class WakeupMethod : uint32_t
	{
		IdleLine = 0U,
		AddressMark = 1U,
	};

	enum class WordLength : uint32_t
	{
		_8DataBits = 0U,
		_9DataBits = 1U,
	};

	enum class UsartEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class OversamplingMode : uint32_t
	{
		By16 = 0U,
		By8 = 1U,
	};

	enum class LinBreakDetectionLength : uint32_t
	{
		_10BitBreakDetection = 0U,
		_11BitBreakDetection = 1U,
	};

	enum class LinBreakDetectionInterruptEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class LastBitClockPulse : uint32_t
	{
		NotOutputToCk = 0U,
		OutputToCk = 1U,
	};

	enum class ClockPhase : uint32_t
	{
		_1StClockTransition = 0U,
		_2NdClockTransition = 1U,
	};

	enum class ClockPolarity : uint32_t
	{
		LowOnCk = 0U,
		HighOnCk = 1U,
	};

	enum class ClockEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class StopBits : uint32_t
	{
		_1StopBit = 0U,
		_05StopBit = 1U,
		_2StopBits = 2U,
		_15StopBits = 3U,
	};

	enum class LinModeEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class ErrorInterruptEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class IrdaModeEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class IrdaLowPower : uint32_t
	{
		NormalMode = 0U,
		LowPowerMode = 1U,
	};

	enum class HalfDuplexSelection : uint32_t
	{
		NotSelected = 0U,
		Selected = 1U,
	};

	enum class SmartcardNackEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class SmartcardModeEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class DmaEnableReciever : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class DmaEnableTransmitter : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class RtsEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class CtsEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class CtsInterruptEnable : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class OneSampleBitMethodEnable : uint32_t
	{
		ThreeSampleBit = 0U,
		OneSampleBit = 1U,
	};

}
#endif // USART_TYPES_HPP_