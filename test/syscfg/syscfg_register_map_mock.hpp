#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "syscfg_register_map.hpp"

using namespace stm32::syscfg;
using namespace testing;

class MockSyscfgRegisterMap : public ISyscfgRegisterMap
{
public:

	// MEMRMP Fields
	MOCK_METHOD(MemoryMapping, get_MEMRMP_MEM_MODE, (), (const, override));
	MOCK_METHOD(void, set_MEMRMP_MEM_MODE, (MemoryMapping), (override));

	// PMC Fields
	MOCK_METHOD(EthernetPhyInterface, get_PMC_MII_RMII_SEL, (), (const, override));
	MOCK_METHOD(void, set_PMC_MII_RMII_SEL, (EthernetPhyInterface), (override));

	// EXTICR1 Fields
	MOCK_METHOD(ExtiConfiguration, get_EXTICR1_EXTI0, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR1_EXTI1, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR1_EXTI2, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR1_EXTI3, (), (const, override));
	MOCK_METHOD(void, set_EXTICR1_EXTI0, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR1_EXTI1, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR1_EXTI2, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR1_EXTI3, (ExtiConfiguration), (override));

	// EXTICR2 Fields
	MOCK_METHOD(ExtiConfiguration, get_EXTICR2_EXTI4, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR2_EXTI5, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR2_EXTI6, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR2_EXTI7, (), (const, override));
	MOCK_METHOD(void, set_EXTICR2_EXTI4, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR2_EXTI5, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR2_EXTI6, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR2_EXTI7, (ExtiConfiguration), (override));

	// EXTICR3 Fields
	MOCK_METHOD(ExtiConfiguration, get_EXTICR3_EXTI8, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR3_EXTI9, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR3_EXTI10, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR3_EXTI11, (), (const, override));
	MOCK_METHOD(void, set_EXTICR3_EXTI8, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR3_EXTI9, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR3_EXTI10, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR3_EXTI11, (ExtiConfiguration), (override));

	// EXTICR4 Fields
	MOCK_METHOD(ExtiConfiguration, get_EXTICR4_EXTI12, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR4_EXTI13, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR4_EXTI14, (), (const, override));
	MOCK_METHOD(ExtiConfiguration, get_EXTICR4_EXTI15, (), (const, override));
	MOCK_METHOD(void, set_EXTICR4_EXTI12, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR4_EXTI13, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR4_EXTI14, (ExtiConfiguration), (override));
	MOCK_METHOD(void, set_EXTICR4_EXTI15, (ExtiConfiguration), (override));

	// CMPCR Fields
	MOCK_METHOD(CompensationCellPowerDown, get_CMPCR_CMP_PD, (), (const, override));
	MOCK_METHOD(CompensationCellReadyFlag, get_CMPCR_READY, (), (const, override));
	MOCK_METHOD(void, set_CMPCR_CMP_PD, (CompensationCellPowerDown), (override));
};

