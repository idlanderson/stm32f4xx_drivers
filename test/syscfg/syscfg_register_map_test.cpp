#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "syscfg_register_map.hpp"

using namespace stm32::syscfg;

TEST(MEMRMP, MEM_MODE)
{
	MEMRMP_t reg;
	reg.Value = 0U;
	reg.Fields.MEM_MODE = (MemoryMapping)3U;
	EXPECT_EQ(0x00000003U, reg.Value);
}

TEST(PMC, MII_RMII_SEL)
{
	PMC_t reg;
	reg.Value = 0U;
	reg.Fields.MII_RMII_SEL = (EthernetPhyInterface)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(EXTICR1, EXTI0)
{
	EXTICR1_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI0 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(EXTICR1, EXTI1)
{
	EXTICR1_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI1 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(EXTICR1, EXTI2)
{
	EXTICR1_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI2 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x00000F00U, reg.Value);
}

TEST(EXTICR1, EXTI3)
{
	EXTICR1_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI3 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x0000F000U, reg.Value);
}

TEST(EXTICR2, EXTI4)
{
	EXTICR2_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI4 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(EXTICR2, EXTI5)
{
	EXTICR2_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI5 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(EXTICR2, EXTI6)
{
	EXTICR2_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI6 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x00000F00U, reg.Value);
}

TEST(EXTICR2, EXTI7)
{
	EXTICR2_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI7 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x0000F000U, reg.Value);
}

TEST(EXTICR3, EXTI8)
{
	EXTICR3_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI8 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(EXTICR3, EXTI9)
{
	EXTICR3_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI9 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(EXTICR3, EXTI10)
{
	EXTICR3_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI10 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x00000F00U, reg.Value);
}

TEST(EXTICR3, EXTI11)
{
	EXTICR3_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI11 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x0000F000U, reg.Value);
}

TEST(EXTICR4, EXTI12)
{
	EXTICR4_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI12 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(EXTICR4, EXTI13)
{
	EXTICR4_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI13 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(EXTICR4, EXTI14)
{
	EXTICR4_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI14 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x00000F00U, reg.Value);
}

TEST(EXTICR4, EXTI15)
{
	EXTICR4_t reg;
	reg.Value = 0U;
	reg.Fields.EXTI15 = (ExtiConfiguration)15U;
	EXPECT_EQ(0x0000F000U, reg.Value);
}

TEST(CMPCR, CMP_PD)
{
	CMPCR_t reg;
	reg.Value = 0U;
	reg.Fields.CMP_PD = (CompensationCellPowerDown)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(CMPCR, READY)
{
	CMPCR_t reg;
	reg.Value = 0U;
	reg.Fields.READY = (CompensationCellReadyFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

