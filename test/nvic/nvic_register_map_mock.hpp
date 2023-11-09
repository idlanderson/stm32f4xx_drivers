#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "nvic_register_map.hpp"

using namespace stm32::nvic;
using namespace testing;

class MockNvicRegisterMap : public INvicRegisterMap
{
public:

	// ISER Fields
	MOCK_METHOD(uint32_t, get_ISER_SETENA, (uint16_t), (const, override));
	MOCK_METHOD(void, set_ISER_SETENA, (uint16_t, uint32_t), (override));

	// ICER Fields
	MOCK_METHOD(uint32_t, get_ICER_CLRENA, (uint16_t), (const, override));
	MOCK_METHOD(void, set_ICER_CLRENA, (uint16_t, uint32_t), (override));

	// ISPR Fields
	MOCK_METHOD(uint32_t, get_ISPR_SETPEND, (uint16_t), (const, override));
	MOCK_METHOD(void, set_ISPR_SETPEND, (uint16_t, uint32_t), (override));

	// ICPR Fields
	MOCK_METHOD(uint32_t, get_ICPR_CLRPEND, (uint16_t), (const, override));
	MOCK_METHOD(void, set_ICPR_CLRPEND, (uint16_t, uint32_t), (override));

	// IABR Fields
	MOCK_METHOD(uint32_t, get_IABR_ACTIVE, (uint16_t), (const, override));
	MOCK_METHOD(void, set_IABR_ACTIVE, (uint16_t, uint32_t), (override));

	// IPR Fields
	MOCK_METHOD(uint32_t, get_IPR_PRI, (uint16_t), (const, override));
	MOCK_METHOD(void, set_IPR_PRI, (uint16_t, uint32_t), (override));

	// STIR Fields
	MOCK_METHOD(uint32_t, get_STIR_INTID, (), (const, override));
	MOCK_METHOD(void, set_STIR_INTID, (uint32_t), (override));
};

