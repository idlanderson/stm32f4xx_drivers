#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gpio_register_map.hpp"

using namespace stm32::gpio;

TEST(MODER, MODER0)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER0 = (Mode)3U;
	EXPECT_EQ(0x00000003U, reg.Value);
}

TEST(MODER, MODER1)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER1 = (Mode)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(MODER, MODER2)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER2 = (Mode)3U;
	EXPECT_EQ(0x00000030U, reg.Value);
}

TEST(MODER, MODER3)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER3 = (Mode)3U;
	EXPECT_EQ(0x000000C0U, reg.Value);
}

TEST(MODER, MODER4)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER4 = (Mode)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(MODER, MODER5)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER5 = (Mode)3U;
	EXPECT_EQ(0x00000C00U, reg.Value);
}

TEST(MODER, MODER6)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER6 = (Mode)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(MODER, MODER7)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER7 = (Mode)3U;
	EXPECT_EQ(0x0000C000U, reg.Value);
}

TEST(MODER, MODER8)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER8 = (Mode)3U;
	EXPECT_EQ(0x00030000U, reg.Value);
}

TEST(MODER, MODER9)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER9 = (Mode)3U;
	EXPECT_EQ(0x000C0000U, reg.Value);
}

TEST(MODER, MODER10)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER10 = (Mode)3U;
	EXPECT_EQ(0x00300000U, reg.Value);
}

TEST(MODER, MODER11)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER11 = (Mode)3U;
	EXPECT_EQ(0x00C00000U, reg.Value);
}

TEST(MODER, MODER12)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER12 = (Mode)3U;
	EXPECT_EQ(0x03000000U, reg.Value);
}

TEST(MODER, MODER13)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER13 = (Mode)3U;
	EXPECT_EQ(0x0C000000U, reg.Value);
}

TEST(MODER, MODER14)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER14 = (Mode)3U;
	EXPECT_EQ(0x30000000U, reg.Value);
}

TEST(MODER, MODER15)
{
	MODER_t reg;
	reg.Value = 0U;
	reg.Fields.MODER15 = (Mode)3U;
	EXPECT_EQ(0xC0000000U, reg.Value);
}

TEST(OTYPER, OT0)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT0 = (OutputType)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(OTYPER, OT1)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT1 = (OutputType)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(OTYPER, OT2)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT2 = (OutputType)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(OTYPER, OT3)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT3 = (OutputType)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(OTYPER, OT4)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT4 = (OutputType)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(OTYPER, OT5)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT5 = (OutputType)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(OTYPER, OT6)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT6 = (OutputType)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(OTYPER, OT7)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT7 = (OutputType)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(OTYPER, OT8)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT8 = (OutputType)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(OTYPER, OT9)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT9 = (OutputType)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(OTYPER, OT10)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT10 = (OutputType)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(OTYPER, OT11)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT11 = (OutputType)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(OTYPER, OT12)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT12 = (OutputType)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(OTYPER, OT13)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT13 = (OutputType)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(OTYPER, OT14)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT14 = (OutputType)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(OTYPER, OT15)
{
	OTYPER_t reg;
	reg.Value = 0U;
	reg.Fields.OT15 = (OutputType)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR0)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR0 = (Speed)3U;
	EXPECT_EQ(0x00000003U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR1)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR1 = (Speed)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(OSPEEDR, OSPEEDR2)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR2 = (Speed)3U;
	EXPECT_EQ(0x00000030U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR3)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR3 = (Speed)3U;
	EXPECT_EQ(0x000000C0U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR4)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR4 = (Speed)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR5)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR5 = (Speed)3U;
	EXPECT_EQ(0x00000C00U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR6)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR6 = (Speed)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR7)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR7 = (Speed)3U;
	EXPECT_EQ(0x0000C000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR8)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR8 = (Speed)3U;
	EXPECT_EQ(0x00030000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR9)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR9 = (Speed)3U;
	EXPECT_EQ(0x000C0000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR10)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR10 = (Speed)3U;
	EXPECT_EQ(0x00300000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR11)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR11 = (Speed)3U;
	EXPECT_EQ(0x00C00000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR12)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR12 = (Speed)3U;
	EXPECT_EQ(0x03000000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR13)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR13 = (Speed)3U;
	EXPECT_EQ(0x0C000000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR14)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR14 = (Speed)3U;
	EXPECT_EQ(0x30000000U, reg.Value);
}

TEST(OSPEEDR, OSPEEDR15)
{
	OSPEEDR_t reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR15 = (Speed)3U;
	EXPECT_EQ(0xC0000000U, reg.Value);
}

TEST(PUPDR, PUPDR0)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR0 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00000003U, reg.Value);
}

TEST(PUPDR, PUPDR1)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR1 = (PullUpPullDown)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(PUPDR, PUPDR2)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR2 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00000030U, reg.Value);
}

TEST(PUPDR, PUPDR3)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR3 = (PullUpPullDown)3U;
	EXPECT_EQ(0x000000C0U, reg.Value);
}

TEST(PUPDR, PUPDR4)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR4 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(PUPDR, PUPDR5)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR5 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00000C00U, reg.Value);
}

TEST(PUPDR, PUPDR6)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR6 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(PUPDR, PUPDR7)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR7 = (PullUpPullDown)3U;
	EXPECT_EQ(0x0000C000U, reg.Value);
}

TEST(PUPDR, PUPDR8)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR8 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00030000U, reg.Value);
}

TEST(PUPDR, PUPDR9)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR9 = (PullUpPullDown)3U;
	EXPECT_EQ(0x000C0000U, reg.Value);
}

TEST(PUPDR, PUPDR10)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR10 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00300000U, reg.Value);
}

TEST(PUPDR, PUPDR11)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR11 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00C00000U, reg.Value);
}

TEST(PUPDR, PUPDR12)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR12 = (PullUpPullDown)3U;
	EXPECT_EQ(0x03000000U, reg.Value);
}

TEST(PUPDR, PUPDR13)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR13 = (PullUpPullDown)3U;
	EXPECT_EQ(0x0C000000U, reg.Value);
}

TEST(PUPDR, PUPDR14)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR14 = (PullUpPullDown)3U;
	EXPECT_EQ(0x30000000U, reg.Value);
}

TEST(PUPDR, PUPDR15)
{
	PUPDR_t reg;
	reg.Value = 0U;
	reg.Fields.PUPDR15 = (PullUpPullDown)3U;
	EXPECT_EQ(0xC0000000U, reg.Value);
}

TEST(IDR, IDR0)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR0 = (uint32_t)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(IDR, IDR1)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR1 = (uint32_t)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(IDR, IDR2)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR2 = (uint32_t)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(IDR, IDR3)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR3 = (uint32_t)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(IDR, IDR4)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR4 = (uint32_t)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(IDR, IDR5)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR5 = (uint32_t)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(IDR, IDR6)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR6 = (uint32_t)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(IDR, IDR7)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR7 = (uint32_t)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(IDR, IDR8)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR8 = (uint32_t)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(IDR, IDR9)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR9 = (uint32_t)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(IDR, IDR10)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR10 = (uint32_t)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(IDR, IDR11)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR11 = (uint32_t)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(IDR, IDR12)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR12 = (uint32_t)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(IDR, IDR13)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR13 = (uint32_t)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(IDR, IDR14)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR14 = (uint32_t)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(IDR, IDR15)
{
	IDR_t reg;
	reg.Value = 0U;
	reg.Fields.IDR15 = (uint32_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(ODR, ODR0)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR0 = (uint32_t)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(ODR, ODR1)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR1 = (uint32_t)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(ODR, ODR2)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR2 = (uint32_t)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(ODR, ODR3)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR3 = (uint32_t)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(ODR, ODR4)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR4 = (uint32_t)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(ODR, ODR5)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR5 = (uint32_t)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(ODR, ODR6)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR6 = (uint32_t)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(ODR, ODR7)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR7 = (uint32_t)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(ODR, ODR8)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR8 = (uint32_t)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(ODR, ODR9)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR9 = (uint32_t)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(ODR, ODR10)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR10 = (uint32_t)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(ODR, ODR11)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR11 = (uint32_t)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(ODR, ODR12)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR12 = (uint32_t)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(ODR, ODR13)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR13 = (uint32_t)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(ODR, ODR14)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR14 = (uint32_t)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(ODR, ODR15)
{
	ODR_t reg;
	reg.Value = 0U;
	reg.Fields.ODR15 = (uint32_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(BSRR, BS0)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS0 = (uint32_t)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(BSRR, BS1)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS1 = (uint32_t)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(BSRR, BS2)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS2 = (uint32_t)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(BSRR, BS3)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS3 = (uint32_t)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(BSRR, BS4)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS4 = (uint32_t)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(BSRR, BS5)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS5 = (uint32_t)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(BSRR, BS6)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS6 = (uint32_t)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(BSRR, BS7)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS7 = (uint32_t)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(BSRR, BS8)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS8 = (uint32_t)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(BSRR, BS9)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS9 = (uint32_t)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(BSRR, BS10)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS10 = (uint32_t)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(BSRR, BS11)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS11 = (uint32_t)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(BSRR, BS12)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS12 = (uint32_t)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(BSRR, BS13)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS13 = (uint32_t)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(BSRR, BS14)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS14 = (uint32_t)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(BSRR, BS15)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BS15 = (uint32_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(BSRR, BR0)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR0 = (uint32_t)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(BSRR, BR1)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR1 = (uint32_t)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(BSRR, BR2)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR2 = (uint32_t)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(BSRR, BR3)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR3 = (uint32_t)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(BSRR, BR4)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR4 = (uint32_t)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(BSRR, BR5)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR5 = (uint32_t)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(BSRR, BR6)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR6 = (uint32_t)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(BSRR, BR7)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR7 = (uint32_t)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(BSRR, BR8)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR8 = (uint32_t)1U;
	EXPECT_EQ(0x01000000U, reg.Value);
}

TEST(BSRR, BR9)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR9 = (uint32_t)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(BSRR, BR10)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR10 = (uint32_t)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(BSRR, BR11)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR11 = (uint32_t)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(BSRR, BR12)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR12 = (uint32_t)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(BSRR, BR13)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR13 = (uint32_t)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(BSRR, BR14)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR14 = (uint32_t)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(BSRR, BR15)
{
	BSRR_t reg;
	reg.Value = 0U;
	reg.Fields.BR15 = (uint32_t)1U;
	EXPECT_EQ(0x80000000U, reg.Value);
}

TEST(LCKR, LCK0)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK0 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(LCKR, LCK1)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK1 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(LCKR, LCK2)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK2 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(LCKR, LCK3)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK3 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(LCKR, LCK4)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK4 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(LCKR, LCK5)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK5 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(LCKR, LCK6)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK6 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(LCKR, LCK7)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK7 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(LCKR, LCK8)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK8 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(LCKR, LCK9)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK9 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(LCKR, LCK10)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK10 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(LCKR, LCK11)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK11 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(LCKR, LCK12)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK12 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(LCKR, LCK13)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK13 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(LCKR, LCK14)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK14 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(LCKR, LCK15)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCK15 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(LCKR, LCKK)
{
	LCKR_t reg;
	reg.Value = 0U;
	reg.Fields.LCKK = (PortConfigurationLockKey)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(AFRL, AFRL0)
{
	AFRL_t reg;
	reg.Value = 0U;
	reg.Fields.AFRL0 = (AlternateFunction)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(AFRL, AFRL1)
{
	AFRL_t reg;
	reg.Value = 0U;
	reg.Fields.AFRL1 = (AlternateFunction)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(AFRL, AFRL2)
{
	AFRL_t reg;
	reg.Value = 0U;
	reg.Fields.AFRL2 = (AlternateFunction)15U;
	EXPECT_EQ(0x00000F00U, reg.Value);
}

TEST(AFRL, AFRL3)
{
	AFRL_t reg;
	reg.Value = 0U;
	reg.Fields.AFRL3 = (AlternateFunction)15U;
	EXPECT_EQ(0x0000F000U, reg.Value);
}

TEST(AFRL, AFRL4)
{
	AFRL_t reg;
	reg.Value = 0U;
	reg.Fields.AFRL4 = (AlternateFunction)15U;
	EXPECT_EQ(0x000F0000U, reg.Value);
}

TEST(AFRL, AFRL5)
{
	AFRL_t reg;
	reg.Value = 0U;
	reg.Fields.AFRL5 = (AlternateFunction)15U;
	EXPECT_EQ(0x00F00000U, reg.Value);
}

TEST(AFRL, AFRL6)
{
	AFRL_t reg;
	reg.Value = 0U;
	reg.Fields.AFRL6 = (AlternateFunction)15U;
	EXPECT_EQ(0x0F000000U, reg.Value);
}

TEST(AFRL, AFRL7)
{
	AFRL_t reg;
	reg.Value = 0U;
	reg.Fields.AFRL7 = (AlternateFunction)15U;
	EXPECT_EQ(0xF0000000U, reg.Value);
}

TEST(AFRH, AFRH8)
{
	AFRH_t reg;
	reg.Value = 0U;
	reg.Fields.AFRH8 = (AlternateFunction)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(AFRH, AFRH9)
{
	AFRH_t reg;
	reg.Value = 0U;
	reg.Fields.AFRH9 = (AlternateFunction)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(AFRH, AFRH10)
{
	AFRH_t reg;
	reg.Value = 0U;
	reg.Fields.AFRH10 = (AlternateFunction)15U;
	EXPECT_EQ(0x00000F00U, reg.Value);
}

TEST(AFRH, AFRH11)
{
	AFRH_t reg;
	reg.Value = 0U;
	reg.Fields.AFRH11 = (AlternateFunction)15U;
	EXPECT_EQ(0x0000F000U, reg.Value);
}

TEST(AFRH, AFRH12)
{
	AFRH_t reg;
	reg.Value = 0U;
	reg.Fields.AFRH12 = (AlternateFunction)15U;
	EXPECT_EQ(0x000F0000U, reg.Value);
}

TEST(AFRH, AFRH13)
{
	AFRH_t reg;
	reg.Value = 0U;
	reg.Fields.AFRH13 = (AlternateFunction)15U;
	EXPECT_EQ(0x00F00000U, reg.Value);
}

TEST(AFRH, AFRH14)
{
	AFRH_t reg;
	reg.Value = 0U;
	reg.Fields.AFRH14 = (AlternateFunction)15U;
	EXPECT_EQ(0x0F000000U, reg.Value);
}

TEST(AFRH, AFRH15)
{
	AFRH_t reg;
	reg.Value = 0U;
	reg.Fields.AFRH15 = (AlternateFunction)15U;
	EXPECT_EQ(0xF0000000U, reg.Value);
}

