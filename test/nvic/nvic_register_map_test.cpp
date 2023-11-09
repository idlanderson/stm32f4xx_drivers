#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "nvic_register_map.hpp"

using namespace stm32::nvic;

TEST(ISER, SETENA)
{
	ISER_t reg;
	reg.Value = 0U;
	reg.Fields.SETENA = (uint32_t)4294967295U;
	EXPECT_EQ(0xFFFFFFFFU, reg.Value);
}

TEST(ICER, CLRENA)
{
	ICER_t reg;
	reg.Value = 0U;
	reg.Fields.CLRENA = (uint32_t)4294967295U;
	EXPECT_EQ(0xFFFFFFFFU, reg.Value);
}

TEST(ISPR, SETPEND)
{
	ISPR_t reg;
	reg.Value = 0U;
	reg.Fields.SETPEND = (uint32_t)4294967295U;
	EXPECT_EQ(0xFFFFFFFFU, reg.Value);
}

TEST(ICPR, CLRPEND)
{
	ICPR_t reg;
	reg.Value = 0U;
	reg.Fields.CLRPEND = (uint32_t)4294967295U;
	EXPECT_EQ(0xFFFFFFFFU, reg.Value);
}

TEST(IABR, ACTIVE)
{
	IABR_t reg;
	reg.Value = 0U;
	reg.Fields.ACTIVE = (uint32_t)4294967295U;
	EXPECT_EQ(0xFFFFFFFFU, reg.Value);
}

TEST(IPR, PRI)
{
	IPR_t reg;
	reg.Value = 0U;
	reg.Fields.PRI = (uint32_t)4294967295U;
	EXPECT_EQ(0xFFFFFFFFU, reg.Value);
}

TEST(STIR, INTID)
{
	STIR_t reg;
	reg.Value = 0U;
	reg.Fields.INTID = (uint32_t)255U;
	EXPECT_EQ(0x000000FFU, reg.Value);
}

