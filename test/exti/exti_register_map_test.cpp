#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "exti_register_map.hpp"

using namespace stm32::exti;

TEST(IMR, MR)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR = (uint32_t)8388607U;
	EXPECT_EQ(0x007FFFFFU, reg.Value);
}

TEST(EMR, MR)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR = (uint32_t)8388607U;
	EXPECT_EQ(0x007FFFFFU, reg.Value);
}

TEST(RTSR, TR)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR = (uint32_t)8388607U;
	EXPECT_EQ(0x007FFFFFU, reg.Value);
}

TEST(FTSR, TR)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR = (uint32_t)8388607U;
	EXPECT_EQ(0x007FFFFFU, reg.Value);
}

TEST(SWIER, SWIER)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER = (uint32_t)8388607U;
	EXPECT_EQ(0x007FFFFFU, reg.Value);
}

TEST(PR, PR)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR = (uint32_t)8388607U;
	EXPECT_EQ(0x007FFFFFU, reg.Value);
}

