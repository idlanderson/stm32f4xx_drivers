#ifndef SYSCFG_TYPES_HPP_
#define SYSCFG_TYPES_HPP_

#include <cstdint>

using namespace std;

namespace stm32::syscfg
{
	using Reserved = uint32_t;

	enum class MemoryMapping : uint32_t
	{
		MainFlashMemory = 0U,
		SystemFlashMemory = 1U,
		FsmcBank1 = 2U,
		EmbeddedSram = 3U,
	};

	enum class EthernetPhyInterface : uint32_t
	{
		MiiInterface = 0U,
		RmiiPhyInterface = 1U,
	};

	enum class ExtiConfiguration : uint32_t
	{
		PaxPin = 0U,
		PbxPin = 1U,
		PcxPin = 2U,
		PdxPin = 3U,
		PexPin = 4U,
		PfxPin = 5U,
		PgxPin = 6U,
		PhxPin = 7U,
		PixPin = 8U,
	};

	enum class CompensationCellPowerDown : uint32_t
	{
		PowerDownMode = 0U,
		Enabled = 1U,
	};

	enum class CompensationCellReadyFlag : uint32_t
	{
		NotReady = 0U,
		Ready = 1U,
	};

}
#endif // SYSCFG_TYPES_HPP_