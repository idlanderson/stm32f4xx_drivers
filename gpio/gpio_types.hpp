#ifndef GPIO_TYPES_HPP_
#define GPIO_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::gpio
{
	using Reserved = uint32_t;

	enum class Mode
	{
		Input = 0U,
		GeneralPurposeOutput = 1U,
		AlternateFunction = 2U,
		Analog = 3U,
	};

	enum class OutputType
	{
		PushPull = 0U,
		OpenDrain = 1U,
	};

	enum class Speed
	{
		LowSpeed = 0U,
		MediumSpeed = 1U,
		HighSpeed = 2U,
		VeryHighSpeed = 3U,
	};

	enum class PullUpPullDown
	{
		NoPullUpPullDown = 0U,
		PullUp = 1U,
		PullDown = 2U,
	};

	enum class PortConfigurationLock
	{
		NotLocked = 0U,
		Locked = 1U,
	};

	enum class PortConfigurationLockKey
	{
		KeyNotActive = 0U,
		KeyActive = 1U,
	};

	enum class AlternateFunction
	{
		Af0 = 0U,
		Af1 = 1U,
		Af2 = 2U,
		Af3 = 3U,
		Af4 = 4U,
		Af5 = 5U,
		Af6 = 6U,
		Af7 = 7U,
		Af8 = 8U,
		Af9 = 9U,
		Af10 = 10U,
		Af11 = 11U,
		Af12 = 12U,
		Af13 = 13U,
		Af14 = 14U,
		Af15 = 15U,
	};

}
#endif // GPIO_TYPES_HPP_