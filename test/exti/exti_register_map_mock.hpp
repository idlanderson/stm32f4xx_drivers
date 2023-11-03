#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "exti_register_map.hpp"

using namespace stm32::exti;
using namespace testing;

class MockExtiRegisterMap : public IExtiRegisterMap
{
public:

	// IMR Fields
	MOCK_METHOD(uint32_t, get_IMR_MR, (), (const, override));
	MOCK_METHOD(void, set_IMR_MR, (uint32_t), (override));

	// EMR Fields
	MOCK_METHOD(uint32_t, get_EMR_MR, (), (const, override));
	MOCK_METHOD(void, set_EMR_MR, (uint32_t), (override));

	// RTSR Fields
	MOCK_METHOD(uint32_t, get_RTSR_TR, (), (const, override));
	MOCK_METHOD(void, set_RTSR_TR, (uint32_t), (override));

	// FTSR Fields
	MOCK_METHOD(uint32_t, get_FTSR_TR, (), (const, override));
	MOCK_METHOD(void, set_FTSR_TR, (uint32_t), (override));

	// SWIER Fields
	MOCK_METHOD(uint32_t, get_SWIER_SWIER, (), (const, override));
	MOCK_METHOD(void, set_SWIER_SWIER, (uint32_t), (override));

	// PR Fields
	MOCK_METHOD(uint32_t, get_PR_PR, (), (const, override));
	MOCK_METHOD(void, set_PR_PR, (uint32_t), (override));
};

