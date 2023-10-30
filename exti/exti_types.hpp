#ifndef EXTI_TYPES_HPP_
#define EXTI_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::exti
{
	using Reserved = uint32_t;

	enum class InterruptMask
	{
		Masked = 0U,
		NotMasked = 1U,
	};

	enum class EnableFlag
	{
		Disabled = 0U,
		Disabled = 1U,
	};

	enum class SoftwareInterrupt
	{
		NoInterrupt = 0U,
		TriggerInterrupt = 1U,
	};

	enum class PendingBit
	{
		NoTriggerRequestOccurred = 0U,
		TriggerRequestOccurred = 1U,
	};

}
#endif // EXTI_TYPES_HPP_