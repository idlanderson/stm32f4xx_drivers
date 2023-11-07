#ifndef RCC_TYPES_HPP_
#define RCC_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::rcc
{
	using Reserved = uint32_t;

	enum class EnableFlag : uint32_t
	{
		Disable = 0U,
		Enable = 1U,
	};

	enum class ReadyFlag : uint32_t
	{
		NotReady = 0U,
		Ready = 1U,
	};

	enum class HseClockBypass : uint32_t
	{
		NotBypassed = 0U,
		Bypassed = 1U,
	};

	enum class MainPllDivisionFactor : uint32_t
	{
		PllpEquals2 = 0U,
		PllpEquals4 = 1U,
		PllpEquals6 = 2U,
		PllpEquals8 = 3U,
	};

	enum class MainPllAndAudioPllEntryClockSource : uint32_t
	{
		HsiClock = 0U,
		HseOscillator = 1U,
	};

	enum class SystemClock : uint32_t
	{
		HsiOscillator = 0U,
		HseOscillator = 1U,
		Pll = 2U,
	};

	enum class AhbPrescaler : uint32_t
	{
		SystemClockDividedBy2 = 8U,
		SystemClockDividedBy4 = 9U,
		SystemClockDividedBy8 = 10U,
		SystemClockDividedBy16 = 11U,
		SystemClockDividedBy64 = 12U,
		SystemClockDividedBy128 = 13U,
		SystemClockDividedBy256 = 14U,
		SystemClockDividedBy512 = 15U,
	};

	enum class ApbPrescaler : uint32_t
	{
		AhbClockDividedBy2 = 4U,
		AhbClockDividedBy4 = 5U,
		AhbClockDividedBy8 = 6U,
		AhbClockDividedBy16 = 7U,
	};

	enum class MicrocontrollerClockOutput1 : uint32_t
	{
		HsiClock = 0U,
		LseOscillator = 1U,
		HseOscillator = 2U,
		PllClock = 3U,
	};

	enum class I2SClockSelection : uint32_t
	{
		Plli2SClock = 0U,
		ExternalClock = 1U,
	};

	enum class McoPrescaler : uint32_t
	{
		DivisionBy2 = 4U,
		DivisionBy3 = 5U,
		DivisionBy4 = 6U,
		DivisionBy5 = 7U,
	};

	enum class MicrocontrollerClockOutput2 : uint32_t
	{
		SystemClock = 0U,
		Plli2SClock = 1U,
		HseOscillator = 2U,
		PllClock = 3U,
	};

	enum class ClockSecuritySystemInterruptFlag : uint32_t
	{
		NoClockSecurityInterrupt = 0U,
		ClockSecurityInterrupt = 1U,
	};

	enum class ClearFlag : uint32_t
	{
		NoEffect = 0U,
		Clear = 1U,
	};

	enum class ResetFlag : uint32_t
	{
		DoNotReset = 0U,
		Reset = 1U,
	};

	enum class ExternalLowSpeedOscillatorBypass : uint32_t
	{
		NotBypassed = 0U,
		Bypassed = 1U,
	};

	enum class RtcClockSourceSelection : uint32_t
	{
		NoClock = 0U,
		LseOscillator = 1U,
		LsiOscillator = 2U,
		HseOscillator = 3U,
	};

	enum class ResetOccurredFlag : uint32_t
	{
		NoResetOccurred = 0U,
		ResetOccurred = 1U,
	};

	enum class SpreadSelect : uint32_t
	{
		CenterSpread = 0U,
		DownSpread = 1U,
	};

}
#endif // RCC_TYPES_HPP_