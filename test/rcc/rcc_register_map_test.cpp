#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "rcc_register_map.hpp"

using namespace stm32::rcc;

TEST(ClockControlRegister, HSION)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.HSION = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(ClockControlRegister, HSIRDY)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.HSIRDY = (ReadyFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(ClockControlRegister, Reserved1)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(ClockControlRegister, HSITRIM)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.HSITRIM = (uint8_t)31U;
	EXPECT_EQ(0x000000F8U, reg.Value);
}

TEST(ClockControlRegister, HSICAL)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.HSICAL = (uint8_t)255U;
	EXPECT_EQ(0x0000FF00U, reg.Value);
}

TEST(ClockControlRegister, HSEON)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.HSEON = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(ClockControlRegister, HSERDY)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.HSERDY = (ReadyFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(ClockControlRegister, HSEBYP)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.HSEBYP = (HseClockBypass)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(ClockControlRegister, CSSON)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.CSSON = (EnableFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(ClockControlRegister, Reserved2)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)15U;
	EXPECT_EQ(0x00F00000U, reg.Value);
}

TEST(ClockControlRegister, PLLON)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLON = (EnableFlag)1U;
	EXPECT_EQ(0x01000000U, reg.Value);
}

TEST(ClockControlRegister, PLLRDY)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLRDY = (ReadyFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(ClockControlRegister, PLLI2SON)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SON = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(ClockControlRegister, PLLI2SRDY)
{
	ClockControlRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SRDY = (ReadyFlag)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(PllConfigurationRegiser, PLLM)
{
	PllConfigurationRegiser reg;
	reg.Value = 0U;
	reg.Fields.PLLM = (uint8_t)31U;
	EXPECT_EQ(0x0000001FU, reg.Value);
}

TEST(PllConfigurationRegiser, PLLN)
{
	PllConfigurationRegiser reg;
	reg.Value = 0U;
	reg.Fields.PLLN = (uint16_t)511U;
	EXPECT_EQ(0x00007FC0U, reg.Value);
}

TEST(PllConfigurationRegiser, Reserved1)
{
	PllConfigurationRegiser reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(PllConfigurationRegiser, PLLP)
{
	PllConfigurationRegiser reg;
	reg.Value = 0U;
	reg.Fields.PLLP = (MainPllDivisionFactor)3U;
	EXPECT_EQ(0x00030000U, reg.Value);
}

TEST(PllConfigurationRegiser, Reserved2)
{
	PllConfigurationRegiser reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)15U;
	EXPECT_EQ(0x003C0000U, reg.Value);
}

TEST(PllConfigurationRegiser, PLLSRC)
{
	PllConfigurationRegiser reg;
	reg.Value = 0U;
	reg.Fields.PLLSRC = (MainPllAndAudioPllEntryClockSource)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(PllConfigurationRegiser, Reserved3)
{
	PllConfigurationRegiser reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(PllConfigurationRegiser, PLLQ)
{
	PllConfigurationRegiser reg;
	reg.Value = 0U;
	reg.Fields.PLLQ = (uint8_t)15U;
	EXPECT_EQ(0x0F000000U, reg.Value);
}

TEST(ClockConfigurationRegister, SW)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.SW = (SystemClock)3U;
	EXPECT_EQ(0x00000003U, reg.Value);
}

TEST(ClockConfigurationRegister, SWS)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.SWS = (SystemClock)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(ClockConfigurationRegister, HPRE)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.HPRE = (AhbPrescaler)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(ClockConfigurationRegister, Reserved1)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(ClockConfigurationRegister, PPRE1)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.PPRE1 = (ApbPrescaler)7U;
	EXPECT_EQ(0x00001C00U, reg.Value);
}

TEST(ClockConfigurationRegister, PPRE2)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.PPRE2 = (ApbPrescaler)7U;
	EXPECT_EQ(0x0000E000U, reg.Value);
}

TEST(ClockConfigurationRegister, RTCPRE)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.RTCPRE = (uint8_t)31U;
	EXPECT_EQ(0x001F0000U, reg.Value);
}

TEST(ClockConfigurationRegister, MCO1)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.MCO1 = (MicrocontrollerClockOutput1)3U;
	EXPECT_EQ(0x00600000U, reg.Value);
}

TEST(ClockConfigurationRegister, I2SSCR)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.I2SSCR = (I2SClockSelection)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(ClockConfigurationRegister, MCO1PRE)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.MCO1PRE = (McoPrescaler)7U;
	EXPECT_EQ(0x07000000U, reg.Value);
}

TEST(ClockConfigurationRegister, MCO2PRE)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.MCO2PRE = (McoPrescaler)7U;
	EXPECT_EQ(0x38000000U, reg.Value);
}

TEST(ClockConfigurationRegister, MCO2)
{
	ClockConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.MCO2 = (MicrocontrollerClockOutput2)3U;
	EXPECT_EQ(0xC0000000U, reg.Value);
}

TEST(ClockInterruptRegister, LSIRDYF)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.LSIRDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(ClockInterruptRegister, LSERDYF)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.LSERDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(ClockInterruptRegister, HSIRDYF)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.HSIRDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(ClockInterruptRegister, HSERDYF)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.HSERDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(ClockInterruptRegister, PLLRDYF)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLRDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(ClockInterruptRegister, PLLI2SRDYF)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SRDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(ClockInterruptRegister, Reserved1)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(ClockInterruptRegister, CSSF)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.CSSF = (ClockSecuritySystemInterruptFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(ClockInterruptRegister, LSIRDYIE)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.LSIRDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(ClockInterruptRegister, LSERDYIE)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.LSERDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(ClockInterruptRegister, HSIRDYIE)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.HSIRDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(ClockInterruptRegister, HSERDYIE)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.HSERDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(ClockInterruptRegister, PLLRDYIE)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLRDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(ClockInterruptRegister, PLLI2SRDYIE)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SRDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(ClockInterruptRegister, Reserved2)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)3U;
	EXPECT_EQ(0x0000C000U, reg.Value);
}

TEST(ClockInterruptRegister, LSIRDYC)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.LSIRDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(ClockInterruptRegister, LSERDYC)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.LSERDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(ClockInterruptRegister, HSIRDYC)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.HSIRDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(ClockInterruptRegister, HSERDYC)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.HSERDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(ClockInterruptRegister, PLLRDYC)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLRDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(ClockInterruptRegister, PLLI2SRDYC)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SRDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(ClockInterruptRegister, Reserved3)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(ClockInterruptRegister, CSSC)
{
	ClockInterruptRegister reg;
	reg.Value = 0U;
	reg.Fields.CSSC = (ClearFlag)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, GPIOARST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOARST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, GPIOBRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOBRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, GPIOCRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOCRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, GPIODRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIODRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, GPIOERST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOERST = (ResetFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, GPIOFRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOFRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, GPIOGRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOGRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, GPIOHRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOHRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, GPIOIRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOIRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, Reserved1)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)7U;
	EXPECT_EQ(0x00000E00U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, CRCRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.CRCRST = (ResetFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, Reserved2)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)255U;
	EXPECT_EQ(0x001FE000U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, DMA1RST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.DMA1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, DMA2RST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.DMA2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, Reserved3)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)3U;
	EXPECT_EQ(0x01800000U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, ETHMACRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.ETHMACRST = (ResetFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, Reserved4)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved4 = (uint8_t)7U;
	EXPECT_EQ(0x1C000000U, reg.Value);
}

TEST(Ahb1PeripheralResetRegister, OTGHSRST)
{
	Ahb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.OTGHSRST = (ResetFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(Ahb2PeripheralResetRegister, DCMIRST)
{
	Ahb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.DCMIRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Ahb2PeripheralResetRegister, Reserved1)
{
	Ahb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)7U;
	EXPECT_EQ(0x0000000EU, reg.Value);
}

TEST(Ahb2PeripheralResetRegister, CRYPRST)
{
	Ahb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.CRYPRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Ahb2PeripheralResetRegister, HASHRST)
{
	Ahb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.HASHRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Ahb2PeripheralResetRegister, RNGRST)
{
	Ahb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.RNGRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(Ahb2PeripheralResetRegister, OTGFSRST)
{
	Ahb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.OTGFSRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(Ahb3PeripheralResetRegister, FSMCRST)
{
	Ahb3PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.FSMCRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, TIM2RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, TIM3RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM3RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, TIM4RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM4RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, TIM5RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM5RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, TIM6RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM6RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, TIM7RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM7RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, TIM12RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM12RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, TIM13RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM13RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, TIM14RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM14RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, Reserved1)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)3U;
	EXPECT_EQ(0x00000600U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, WWDGRST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.WWDGRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, Reserved2)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, SPI2RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.SPI2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, SPI3RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.SPI3RST = (ResetFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, Reserved3)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, UART2RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.UART2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, UART3RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.UART3RST = (ResetFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, UART4RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.UART4RST = (ResetFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, UART5RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.UART5RST = (ResetFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, I2C1RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.I2C1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, I2C2RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.I2C2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, I2C3RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.I2C3RST = (ResetFlag)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, Reserved4)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved4 = (uint8_t)1U;
	EXPECT_EQ(0x01000000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, CAN1RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.CAN1RST = (ResetFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, CAN2RST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.CAN2RST = (ResetFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, Reserved5)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved5 = (uint8_t)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, PWRRST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.PWRRST = (ResetFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(Apb1PeripheralResetRegister, DACRST)
{
	Apb1PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.DACRST = (ResetFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, TIM1RST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, TIM8RST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM8RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, Reserved1)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(Apb2PeripheralResetRegister, USART1RST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.USART1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, USART6RST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.USART6RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, Reserved2)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)3U;
	EXPECT_EQ(0x000000C0U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, ADCRST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.ADCRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, Reserved3)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)3U;
	EXPECT_EQ(0x00000600U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, SDIORST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.SDIORST = (ResetFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, SPI1RST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.SPI1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, Reserved4)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved4 = (uint8_t)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, SYSCFGRST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.SYSCFGRST = (ResetFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, Reserved5)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved5 = (uint8_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, TIM9RST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM9RST = (ResetFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, TIM10RST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM10RST = (ResetFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(Apb2PeripheralResetRegister, TIM11RST)
{
	Apb2PeripheralResetRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM11RST = (ResetFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, GPIOAEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOAEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, GPIOBEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOBEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, GPIOCEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOCEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, GPIODEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIODEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, GPIOEEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOEEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, GPIOFEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOFEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, GPIOGEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOGEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, GPIOHEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOHEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, GPIOIEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOIEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, Reserved1)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)7U;
	EXPECT_EQ(0x00000E00U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, CRCEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.CRCEN = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, Reserved2)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)31U;
	EXPECT_EQ(0x0003E000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, BKPSRAMEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.BKPSRAMEN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, Reserved3)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, CCMDATARAMEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.CCMDATARAMEN = (EnableFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, DMA1EN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.DMA1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, DMA2EN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.DMA2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, Reserved4)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved4 = (uint8_t)3U;
	EXPECT_EQ(0x01800000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, ETHMACEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.ETHMACEN = (EnableFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, ETHMACTXEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.ETHMACTXEN = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, ETHMACRXEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.ETHMACRXEN = (EnableFlag)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, ETHMACPTPEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.ETHMACPTPEN = (EnableFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, OTGHSEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.OTGHSEN = (EnableFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableRegister, OTGHSULPIEN)
{
	Ahb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.OTGHSULPIEN = (EnableFlag)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableRegister, DCMIEN)
{
	Ahb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.DCMIEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableRegister, Reserved1)
{
	Ahb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)7U;
	EXPECT_EQ(0x0000000EU, reg.Value);
}

TEST(Ahb2PeripheralClockEnableRegister, CRYPEN)
{
	Ahb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.CRYPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableRegister, HASHEN)
{
	Ahb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.HASHEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableRegister, RNGEN)
{
	Ahb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.RNGEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableRegister, OTGFSEN)
{
	Ahb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.OTGFSEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(Ahb3PeripheralClockEnableRegister, FSMCEN)
{
	Ahb3PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.FSMCEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, TIM2EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, TIM3EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, TIM4EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM4EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, TIM5EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM5EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, TIM6EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM6EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, TIM7EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM7EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, TIM12EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM12EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, TIM13EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM13EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, TIM14EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM14EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, Reserved1)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)3U;
	EXPECT_EQ(0x00000600U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, WWDGEN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.WWDGEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, Reserved2)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (EnableFlag)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, SPI2EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.SPI2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, SPI3EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.SPI3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, Reserved3)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, USART2EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.USART2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, USART3EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.USART3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, UART4EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.UART4EN = (EnableFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, UART5EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.UART5EN = (EnableFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, I2C1EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.I2C1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, I2C2EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.I2C2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, I2C3EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.I2C3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, Reserved4)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved4 = (uint8_t)1U;
	EXPECT_EQ(0x01000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, CAN1EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.CAN1EN = (EnableFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, CAN2EN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.CAN2EN = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, Reserved5)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved5 = (uint8_t)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, PWREN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.PWREN = (EnableFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableRegister, DACEN)
{
	Apb1PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.DACEN = (EnableFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, TIM1EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, TIM8EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM8EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, Reserved1)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, USART1EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.USART1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, USART6EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.USART6EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, Reserved2)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)3U;
	EXPECT_EQ(0x000000C0U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, ADC1EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.ADC1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, ADC2EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.ADC2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, ADC3EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.ADC3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, SDIOEN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.SDIOEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, SPI1EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.SPI1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, Reserved3)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, SYSCFGEN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.SYSCFGEN = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, Reserved4)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved4 = (uint8_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, TIM9EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM9EN = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, TIM10EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM10EN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableRegister, TIM11EN)
{
	Apb2PeripheralClockEnableRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM11EN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, GPIOALPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOALPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, GPIOBLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOBLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, GPIOCLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOCLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, GPIODLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIODLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, GPIOELPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOELPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, GPIOFLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOFLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, GPIOGLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOGLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, GPIOHLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOHLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, GPIOILPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.GPIOILPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, Reserved1)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)7U;
	EXPECT_EQ(0x00000E00U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, CRCLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.CRCLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, Reserved2)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)3U;
	EXPECT_EQ(0x00006000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, FLITFLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.FLITFLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, SRAM1LPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.SRAM1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, SRAM2LPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.SRAM2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, BKPSRAMLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.BKPSRAMLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, Reserved3)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)3U;
	EXPECT_EQ(0x00180000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, DMA1LPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.DMA1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, DMA2LPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.DMA2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, Reserved4)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved4 = (uint8_t)3U;
	EXPECT_EQ(0x01800000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, ETHMACLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.ETHMACLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, ETHMACTXLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.ETHMACTXLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, ETHMACRXLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.ETHMACRXLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, ETHMACPTPLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.ETHMACPTPLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, OTGHSLPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.OTGHSLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(Ahb1PeripheralClockEnableInLowPowerModeRegister, OTGHSULPILPEN)
{
	Ahb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.OTGHSULPILPEN = (EnableFlag)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableInLowPowerModeRegister, DCMILPEN)
{
	Ahb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.DCMILPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableInLowPowerModeRegister, Reserved1)
{
	Ahb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)7U;
	EXPECT_EQ(0x0000000EU, reg.Value);
}

TEST(Ahb2PeripheralClockEnableInLowPowerModeRegister, CRYPLPEN)
{
	Ahb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.CRYPLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableInLowPowerModeRegister, HASHLPEN)
{
	Ahb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.HASHLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableInLowPowerModeRegister, RNGLPEN)
{
	Ahb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.RNGLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(Ahb2PeripheralClockEnableInLowPowerModeRegister, OTGFSLPEN)
{
	Ahb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.OTGFSLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(Ahb3PeripheralClockEnableInLowPowerModeRegister, FSMCLPEN)
{
	Ahb3PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.FSMCLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, TIM2LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, TIM3LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, TIM4LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM4LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, TIM5LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM5LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, TIM6LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM6LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, TIM7LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM7LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, TIM12LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM12LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, TIM13LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM13LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, TIM14LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM14LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, Reserved1)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)3U;
	EXPECT_EQ(0x00000600U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, WWDGLPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.WWDGLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, Reserved2)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, SPI2LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.SPI2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, SPI3LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.SPI3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, Reserved3)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, USART2LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.USART2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, USART3LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.USART3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, UART4LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.UART4LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, UART5LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.UART5LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, I2C1LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.I2C1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, I2C2LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.I2C2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, I2C3LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.I2C3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, Reserved4)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved4 = (uint8_t)1U;
	EXPECT_EQ(0x01000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, CAN1LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.CAN1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, CAN2LPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.CAN2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, Reserved5)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved5 = (uint8_t)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, PWRLPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.PWRLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(Apb1PeripheralClockEnableInLowPowerModeRegister, DACLPEN)
{
	Apb1PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.DACLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, TIM1LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, TIM8LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM8LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, Reserved1)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, Reserved2)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, USART1LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.USART1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, USART6LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.USART6LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, ADC1LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.ADC1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, ADC2LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.ADC2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, ADC3LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.ADC3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, SDIOLPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.SDIOLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, SPI1LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.SPI1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, Reserved3)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved3 = (uint8_t)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, SYSCFGLPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.SYSCFGLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, Reserved4)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved4 = (uint8_t)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, TIM9LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM9LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, TIM10LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM10LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(Apb2PeripheralClockEnableInLowPowerModeRegister, TIM11LPEN)
{
	Apb2PeripheralClockEnableInLowPowerModeRegister reg;
	reg.Value = 0U;
	reg.Fields.TIM11LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(BackupDomainControlRegister, LSEON)
{
	BackupDomainControlRegister reg;
	reg.Value = 0U;
	reg.Fields.LSEON = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(BackupDomainControlRegister, LSERDY)
{
	BackupDomainControlRegister reg;
	reg.Value = 0U;
	reg.Fields.LSERDY = (ReadyFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(BackupDomainControlRegister, LSEBYP)
{
	BackupDomainControlRegister reg;
	reg.Value = 0U;
	reg.Fields.LSEBYP = (ExternalLowSpeedOscillatorBypass)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(BackupDomainControlRegister, Reserved1)
{
	BackupDomainControlRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)31U;
	EXPECT_EQ(0x000000F8U, reg.Value);
}

TEST(BackupDomainControlRegister, RTCSEL)
{
	BackupDomainControlRegister reg;
	reg.Value = 0U;
	reg.Fields.RTCSEL = (RtcClockSourceSelection)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(BackupDomainControlRegister, Reserved2)
{
	BackupDomainControlRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint8_t)31U;
	EXPECT_EQ(0x00007C00U, reg.Value);
}

TEST(BackupDomainControlRegister, RTCEN)
{
	BackupDomainControlRegister reg;
	reg.Value = 0U;
	reg.Fields.RTCEN = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(BackupDomainControlRegister, BDRST)
{
	BackupDomainControlRegister reg;
	reg.Value = 0U;
	reg.Fields.BDRST = (ResetFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(ClockControlAndStatusRegister, LSION)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.LSION = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(ClockControlAndStatusRegister, LSIRDY)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.LSIRDY = (ReadyFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(ClockControlAndStatusRegister, Reserved1)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint32_t)4194303U;
	EXPECT_EQ(0x00FFFFFCU, reg.Value);
}

TEST(ClockControlAndStatusRegister, RMVF)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.RMVF = (ClearFlag)1U;
	EXPECT_EQ(0x01000000U, reg.Value);
}

TEST(ClockControlAndStatusRegister, BORRSTF)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.BORRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(ClockControlAndStatusRegister, PINRSTF)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.PINRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(ClockControlAndStatusRegister, PORRSTF)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.PORRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(ClockControlAndStatusRegister, SFTRSTF)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.SFTRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(ClockControlAndStatusRegister, IWDGRSTF)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.IWDGRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(ClockControlAndStatusRegister, WWDGRSTF)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.WWDGRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(ClockControlAndStatusRegister, LPWRRSTF)
{
	ClockControlAndStatusRegister reg;
	reg.Value = 0U;
	reg.Fields.LPWRRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x80000000U, reg.Value);
}

TEST(SpreadSpectrumClockGenerationRegister, MODPER)
{
	SpreadSpectrumClockGenerationRegister reg;
	reg.Value = 0U;
	reg.Fields.MODPER = (uint16_t)8191U;
	EXPECT_EQ(0x00001FFFU, reg.Value);
}

TEST(SpreadSpectrumClockGenerationRegister, INCSTEP)
{
	SpreadSpectrumClockGenerationRegister reg;
	reg.Value = 0U;
	reg.Fields.INCSTEP = (uint16_t)32767U;
	EXPECT_EQ(0x0FFFE000U, reg.Value);
}

TEST(SpreadSpectrumClockGenerationRegister, Reserved1)
{
	SpreadSpectrumClockGenerationRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)3U;
	EXPECT_EQ(0x30000000U, reg.Value);
}

TEST(SpreadSpectrumClockGenerationRegister, SPREADSEL)
{
	SpreadSpectrumClockGenerationRegister reg;
	reg.Value = 0U;
	reg.Fields.SPREADSEL = (SpreadSelect)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(SpreadSpectrumClockGenerationRegister, SSCGEN)
{
	SpreadSpectrumClockGenerationRegister reg;
	reg.Value = 0U;
	reg.Fields.SSCGEN = (EnableFlag)1U;
	EXPECT_EQ(0x80000000U, reg.Value);
}

TEST(PLLI2SConfigurationRegister, Reserved1)
{
	PLLI2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved1 = (uint8_t)63U;
	EXPECT_EQ(0x0000003FU, reg.Value);
}

TEST(PLLI2SConfigurationRegister, PLLI2SN)
{
	PLLI2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SN = (uint16_t)511U;
	EXPECT_EQ(0x00007FC0U, reg.Value);
}

TEST(PLLI2SConfigurationRegister, Reserved2)
{
	PLLI2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.Reserved2 = (uint16_t)8191U;
	EXPECT_EQ(0x0FFF8000U, reg.Value);
}

TEST(PLLI2SConfigurationRegister, PLLI2SR)
{
	PLLI2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SR = (uint8_t)7U;
	EXPECT_EQ(0x70000000U, reg.Value);
}

