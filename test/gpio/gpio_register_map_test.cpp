#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gpio_register_map.hpp"

using namespace stm32::gpio;

TEST(PortModeRegister, MODER0)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER0 = (PortMode)3U;
	EXPECT_EQ(0x00000003U, reg.Value);
}

TEST(PortModeRegister, MODER1)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER1 = (PortMode)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(PortModeRegister, MODER2)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER2 = (PortMode)3U;
	EXPECT_EQ(0x00000030U, reg.Value);
}

TEST(PortModeRegister, MODER3)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER3 = (PortMode)3U;
	EXPECT_EQ(0x000000C0U, reg.Value);
}

TEST(PortModeRegister, MODER4)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER4 = (PortMode)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(PortModeRegister, MODER5)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER5 = (PortMode)3U;
	EXPECT_EQ(0x00000C00U, reg.Value);
}

TEST(PortModeRegister, MODER6)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER6 = (PortMode)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(PortModeRegister, MODER7)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER7 = (PortMode)3U;
	EXPECT_EQ(0x0000C000U, reg.Value);
}

TEST(PortModeRegister, MODER8)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER8 = (PortMode)3U;
	EXPECT_EQ(0x00030000U, reg.Value);
}

TEST(PortModeRegister, MODER9)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER9 = (PortMode)3U;
	EXPECT_EQ(0x000C0000U, reg.Value);
}

TEST(PortModeRegister, MODER10)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER10 = (PortMode)3U;
	EXPECT_EQ(0x00300000U, reg.Value);
}

TEST(PortModeRegister, MODER11)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER11 = (PortMode)3U;
	EXPECT_EQ(0x00C00000U, reg.Value);
}

TEST(PortModeRegister, MODER12)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER12 = (PortMode)3U;
	EXPECT_EQ(0x03000000U, reg.Value);
}

TEST(PortModeRegister, MODER13)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER13 = (PortMode)3U;
	EXPECT_EQ(0x0C000000U, reg.Value);
}

TEST(PortModeRegister, MODER14)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER14 = (PortMode)3U;
	EXPECT_EQ(0x30000000U, reg.Value);
}

TEST(PortModeRegister, MODER15)
{
	PortModeRegister reg;
	reg.Value = 0U;
	reg.Fields.MODER15 = (PortMode)3U;
	EXPECT_EQ(0xC0000000U, reg.Value);
}

TEST(PortOutputTypeRegister, OT0)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT0 = (OutputType)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(PortOutputTypeRegister, OT1)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT1 = (OutputType)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(PortOutputTypeRegister, OT2)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT2 = (OutputType)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(PortOutputTypeRegister, OT3)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT3 = (OutputType)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(PortOutputTypeRegister, OT4)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT4 = (OutputType)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(PortOutputTypeRegister, OT5)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT5 = (OutputType)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(PortOutputTypeRegister, OT6)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT6 = (OutputType)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(PortOutputTypeRegister, OT7)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT7 = (OutputType)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(PortOutputTypeRegister, OT8)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT8 = (OutputType)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(PortOutputTypeRegister, OT9)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT9 = (OutputType)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(PortOutputTypeRegister, OT10)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT10 = (OutputType)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(PortOutputTypeRegister, OT11)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT11 = (OutputType)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(PortOutputTypeRegister, OT12)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT12 = (OutputType)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(PortOutputTypeRegister, OT13)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT13 = (OutputType)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(PortOutputTypeRegister, OT14)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT14 = (OutputType)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(PortOutputTypeRegister, OT15)
{
	PortOutputTypeRegister reg;
	reg.Value = 0U;
	reg.Fields.OT15 = (OutputType)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR0)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR0 = (OutputSpeed)3U;
	EXPECT_EQ(0x00000003U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR1)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR1 = (OutputSpeed)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR2)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR2 = (OutputSpeed)3U;
	EXPECT_EQ(0x00000030U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR3)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR3 = (OutputSpeed)3U;
	EXPECT_EQ(0x000000C0U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR4)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR4 = (OutputSpeed)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR5)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR5 = (OutputSpeed)3U;
	EXPECT_EQ(0x00000C00U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR6)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR6 = (OutputSpeed)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR7)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR7 = (OutputSpeed)3U;
	EXPECT_EQ(0x0000C000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR8)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR8 = (OutputSpeed)3U;
	EXPECT_EQ(0x00030000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR9)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR9 = (OutputSpeed)3U;
	EXPECT_EQ(0x000C0000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR10)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR10 = (OutputSpeed)3U;
	EXPECT_EQ(0x00300000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR11)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR11 = (OutputSpeed)3U;
	EXPECT_EQ(0x00C00000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR12)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR12 = (OutputSpeed)3U;
	EXPECT_EQ(0x03000000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR13)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR13 = (OutputSpeed)3U;
	EXPECT_EQ(0x0C000000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR14)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR14 = (OutputSpeed)3U;
	EXPECT_EQ(0x30000000U, reg.Value);
}

TEST(PortOutputSpeedRegister, OSPEEDR15)
{
	PortOutputSpeedRegister reg;
	reg.Value = 0U;
	reg.Fields.OSPEEDR15 = (OutputSpeed)3U;
	EXPECT_EQ(0xC0000000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR0)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR0 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00000003U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR1)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR1 = (PullUpPullDown)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR2)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR2 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00000030U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR3)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR3 = (PullUpPullDown)3U;
	EXPECT_EQ(0x000000C0U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR4)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR4 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR5)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR5 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00000C00U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR6)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR6 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR7)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR7 = (PullUpPullDown)3U;
	EXPECT_EQ(0x0000C000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR8)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR8 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00030000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR9)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR9 = (PullUpPullDown)3U;
	EXPECT_EQ(0x000C0000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR10)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR10 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00300000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR11)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR11 = (PullUpPullDown)3U;
	EXPECT_EQ(0x00C00000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR12)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR12 = (PullUpPullDown)3U;
	EXPECT_EQ(0x03000000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR13)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR13 = (PullUpPullDown)3U;
	EXPECT_EQ(0x0C000000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR14)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR14 = (PullUpPullDown)3U;
	EXPECT_EQ(0x30000000U, reg.Value);
}

TEST(PortPullUpPullDownRegister, PUPDR15)
{
	PortPullUpPullDownRegister reg;
	reg.Value = 0U;
	reg.Fields.PUPDR15 = (PullUpPullDown)3U;
	EXPECT_EQ(0xC0000000U, reg.Value);
}

TEST(PortInputDataRegister, IDR0)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR0 = (uint8_t)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(PortInputDataRegister, IDR1)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR1 = (uint8_t)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(PortInputDataRegister, IDR2)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR2 = (uint8_t)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(PortInputDataRegister, IDR3)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR3 = (uint8_t)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(PortInputDataRegister, IDR4)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR4 = (uint8_t)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(PortInputDataRegister, IDR5)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR5 = (uint8_t)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(PortInputDataRegister, IDR6)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR6 = (uint8_t)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(PortInputDataRegister, IDR7)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR7 = (uint8_t)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(PortInputDataRegister, IDR8)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR8 = (uint8_t)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(PortInputDataRegister, IDR9)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR9 = (uint8_t)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(PortInputDataRegister, IDR10)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR10 = (uint8_t)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(PortInputDataRegister, IDR11)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR11 = (uint8_t)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(PortInputDataRegister, IDR12)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR12 = (uint8_t)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(PortInputDataRegister, IDR13)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR13 = (uint8_t)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(PortInputDataRegister, IDR14)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR14 = (uint8_t)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(PortInputDataRegister, IDR15)
{
	PortInputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.IDR15 = (uint8_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(PortOutputDataRegister, ODR0)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR0 = (uint8_t)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(PortOutputDataRegister, ODR1)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR1 = (uint8_t)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(PortOutputDataRegister, ODR2)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR2 = (uint8_t)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(PortOutputDataRegister, ODR3)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR3 = (uint8_t)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(PortOutputDataRegister, ODR4)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR4 = (uint8_t)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(PortOutputDataRegister, ODR5)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR5 = (uint8_t)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(PortOutputDataRegister, ODR6)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR6 = (uint8_t)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(PortOutputDataRegister, ODR7)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR7 = (uint8_t)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(PortOutputDataRegister, ODR8)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR8 = (uint8_t)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(PortOutputDataRegister, ODR9)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR9 = (uint8_t)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(PortOutputDataRegister, ODR10)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR10 = (uint8_t)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(PortOutputDataRegister, ODR11)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR11 = (uint8_t)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(PortOutputDataRegister, ODR12)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR12 = (uint8_t)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(PortOutputDataRegister, ODR13)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR13 = (uint8_t)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(PortOutputDataRegister, ODR14)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR14 = (uint8_t)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(PortOutputDataRegister, ODR15)
{
	PortOutputDataRegister reg;
	reg.Value = 0U;
	reg.Fields.ODR15 = (uint8_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(PortBitSetResetRegister, BS0)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS0 = (uint8_t)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(PortBitSetResetRegister, BS1)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS1 = (uint8_t)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(PortBitSetResetRegister, BS2)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS2 = (uint8_t)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(PortBitSetResetRegister, BS3)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS3 = (uint8_t)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(PortBitSetResetRegister, BS4)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS4 = (uint8_t)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(PortBitSetResetRegister, BS5)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS5 = (uint8_t)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(PortBitSetResetRegister, BS6)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS6 = (uint8_t)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(PortBitSetResetRegister, BS7)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS7 = (uint8_t)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(PortBitSetResetRegister, BS8)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS8 = (uint8_t)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(PortBitSetResetRegister, BS9)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS9 = (uint8_t)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(PortBitSetResetRegister, BS10)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS10 = (uint8_t)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(PortBitSetResetRegister, BS11)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS11 = (uint8_t)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(PortBitSetResetRegister, BS12)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS12 = (uint8_t)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(PortBitSetResetRegister, BS13)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS13 = (uint8_t)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(PortBitSetResetRegister, BS14)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS14 = (uint8_t)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(PortBitSetResetRegister, BS15)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BS15 = (uint8_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR0)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR0 = (uint8_t)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR1)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR1 = (uint8_t)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR2)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR2 = (uint8_t)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR3)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR3 = (uint8_t)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR4)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR4 = (uint8_t)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR5)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR5 = (uint8_t)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR6)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR6 = (uint8_t)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR7)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR7 = (uint8_t)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR8)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR8 = (uint8_t)1U;
	EXPECT_EQ(0x01000000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR9)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR9 = (uint8_t)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR10)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR10 = (uint8_t)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR11)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR11 = (uint8_t)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR12)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR12 = (uint8_t)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR13)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR13 = (uint8_t)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR14)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR14 = (uint8_t)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(PortBitSetResetRegister, BR15)
{
	PortBitSetResetRegister reg;
	reg.Value = 0U;
	reg.Fields.BR15 = (uint8_t)1U;
	EXPECT_EQ(0x80000000U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK0)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK0 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK1)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK1 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK2)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK2 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK3)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK3 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK4)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK4 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK5)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK5 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK6)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK6 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK7)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK7 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK8)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK8 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK9)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK9 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK10)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK10 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK11)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK11 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK12)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK12 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK13)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK13 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK14)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK14 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCK15)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCK15 = (PortConfigurationLock)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(PortConfigurationLockRegister, LCKK)
{
	PortConfigurationLockRegister reg;
	reg.Value = 0U;
	reg.Fields.LCKK = (PortConfigurationLockKey)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(AlternateFunctionLowRegister, AFRL0)
{
	AlternateFunctionLowRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRL0 = (AlternateFunction)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(AlternateFunctionLowRegister, AFRL1)
{
	AlternateFunctionLowRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRL1 = (AlternateFunction)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(AlternateFunctionLowRegister, AFRL2)
{
	AlternateFunctionLowRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRL2 = (AlternateFunction)15U;
	EXPECT_EQ(0x00000F00U, reg.Value);
}

TEST(AlternateFunctionLowRegister, AFRL3)
{
	AlternateFunctionLowRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRL3 = (AlternateFunction)15U;
	EXPECT_EQ(0x0000F000U, reg.Value);
}

TEST(AlternateFunctionLowRegister, AFRL4)
{
	AlternateFunctionLowRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRL4 = (AlternateFunction)15U;
	EXPECT_EQ(0x000F0000U, reg.Value);
}

TEST(AlternateFunctionLowRegister, AFRL5)
{
	AlternateFunctionLowRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRL5 = (AlternateFunction)15U;
	EXPECT_EQ(0x00F00000U, reg.Value);
}

TEST(AlternateFunctionLowRegister, AFRL6)
{
	AlternateFunctionLowRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRL6 = (AlternateFunction)15U;
	EXPECT_EQ(0x0F000000U, reg.Value);
}

TEST(AlternateFunctionLowRegister, AFRL7)
{
	AlternateFunctionLowRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRL7 = (AlternateFunction)15U;
	EXPECT_EQ(0xF0000000U, reg.Value);
}

TEST(AlternateFunctionHighRegister, AFRH8)
{
	AlternateFunctionHighRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRH8 = (AlternateFunction)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(AlternateFunctionHighRegister, AFRH9)
{
	AlternateFunctionHighRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRH9 = (AlternateFunction)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(AlternateFunctionHighRegister, AFRH10)
{
	AlternateFunctionHighRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRH10 = (AlternateFunction)15U;
	EXPECT_EQ(0x00000F00U, reg.Value);
}

TEST(AlternateFunctionHighRegister, AFRH11)
{
	AlternateFunctionHighRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRH11 = (AlternateFunction)15U;
	EXPECT_EQ(0x0000F000U, reg.Value);
}

TEST(AlternateFunctionHighRegister, AFRH12)
{
	AlternateFunctionHighRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRH12 = (AlternateFunction)15U;
	EXPECT_EQ(0x000F0000U, reg.Value);
}

TEST(AlternateFunctionHighRegister, AFRH13)
{
	AlternateFunctionHighRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRH13 = (AlternateFunction)15U;
	EXPECT_EQ(0x00F00000U, reg.Value);
}

TEST(AlternateFunctionHighRegister, AFRH14)
{
	AlternateFunctionHighRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRH14 = (AlternateFunction)15U;
	EXPECT_EQ(0x0F000000U, reg.Value);
}

TEST(AlternateFunctionHighRegister, AFRH15)
{
	AlternateFunctionHighRegister reg;
	reg.Value = 0U;
	reg.Fields.AFRH15 = (AlternateFunction)15U;
	EXPECT_EQ(0xF0000000U, reg.Value);
}

