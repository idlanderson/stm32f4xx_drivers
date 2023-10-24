#ifndef RCC_TYPES_HPP_
#define RCC_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::rcc
{
	enum class EnableFlag
	{
		Disable = 0U,
		Enable = 1U,
	};

	enum class ReadyFlag
	{
		NotReady = 0U,
		Ready = 1U,
	};

	enum class HseClockBypass
	{
		NotBypassed = 0U,
		Bypassed = 1U,
	};

	enum class MainPllDivisionFactor
	{
		PllpEquals2 = 0U,
		PllpEquals4 = 1U,
		PllpEquals6 = 2U,
		PllpEquals8 = 3U,
	};

	enum class MainPllAndAudioPllEntryClockSource
	{
		HsiClock = 0U,
		HseOscillator = 1U,
	};

	enum class SystemClock
	{
		HsiOscillator = 0U,
		HseOscillator = 1U,
		Pll = 2U,
	};

	enum class AhbPrescaler
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

	enum class ApbPrescaler
	{
		AhbClockDividedBy2 = 4U,
		AhbClockDividedBy4 = 5U,
		AhbClockDividedBy8 = 6U,
		AhbClockDividedBy16 = 7U,
	};

	enum class MicrocontrollerClockOutput1
	{
		HsiClock = 0U,
		LseOscillator = 1U,
		HseOscillator = 2U,
		PllClock = 3U,
	};

	enum class I2SClockSelection
	{
		Plli2SClock = 0U,
		ExternalClock = 1U,
	};

	enum class McoPrescaler
	{
		DivisionBy2 = 4U,
		DivisionBy3 = 5U,
		DivisionBy4 = 6U,
		DivisionBy5 = 7U,
	};

	enum class MicrocontrollerClockOutput2
	{
		SystemClock = 0U,
		Plli2SClock = 1U,
		HseOscillator = 2U,
		PllClock = 3U,
	};

	enum class ClockSecuritySystemInterruptFlag
	{
		NoClockSecurityInterrupt = 0U,
		ClockSecurityInterrupt = 1U,
	};

	enum class ClearFlag
	{
		NoEffect = 0U,
		Clear = 1U,
	};

	enum class ResetFlag
	{
		DoNotReset = 0U,
		Reset = 1U,
	};

	enum class ExternalLowSpeedOscillatorBypass
	{
		NotBypassed = 0U,
		Bypassed = 1U,
	};

	enum class RtcClockSourceSelection
	{
		NoClock = 0U,
		LseOscillator = 1U,
		LsiOscillator = 2U,
		HseOscillator = 3U,
	};

	enum class ResetOccurredFlag
	{
		NoResetOccurred = 0U,
		ResetOccurred = 1U,
	};

	enum class SpreadSelect
	{
		CenterSpread = 0U,
		DownSpread = 1U,
	};

}
#endif // RCC_TYPES_HPP_