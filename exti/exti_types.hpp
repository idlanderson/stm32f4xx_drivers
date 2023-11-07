#ifndef EXTI_TYPES_HPP_
#define EXTI_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::exti
{
	using Reserved = uint32_t;

	enum class InterruptMask : uint32_t
	{
		Masked = 0U,
		NotMasked = 1U,
	};

	enum class EnableFlag : uint32_t
	{
		Disabled = 0U,
		Enabled = 1U,
	};

	enum class SoftwareInterrupt : uint32_t
	{
		NoInterrupt = 0U,
		TriggerInterrupt = 1U,
	};

	enum class PendingBit : uint32_t
	{
		NoTriggerRequestOccurred = 0U,
		TriggerRequestOccurred = 1U,
	};

}
#endif // EXTI_TYPES_HPP_