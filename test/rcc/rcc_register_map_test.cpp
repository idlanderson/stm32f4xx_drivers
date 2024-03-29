#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "rcc_register_map.hpp"

using namespace stm32::rcc;

TEST(CR, HSION)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.HSION = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(CR, HSIRDY)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.HSIRDY = (ReadyFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(CR, HSITRIM)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.HSITRIM = (uint32_t)31U;
	EXPECT_EQ(0x000000F8U, reg.Value);
}

TEST(CR, HSICAL)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.HSICAL = (uint32_t)255U;
	EXPECT_EQ(0x0000FF00U, reg.Value);
}

TEST(CR, HSEON)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.HSEON = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(CR, HSERDY)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.HSERDY = (ReadyFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(CR, HSEBYP)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.HSEBYP = (HseClockBypass)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(CR, CSSON)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.CSSON = (EnableFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(CR, PLLON)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLON = (EnableFlag)1U;
	EXPECT_EQ(0x01000000U, reg.Value);
}

TEST(CR, PLLRDY)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLRDY = (ReadyFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(CR, PLLI2SON)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SON = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(CR, PLLI2SRDY)
{
	CR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SRDY = (ReadyFlag)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(PLLCFGR, PLLM)
{
	PLLCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLM = (uint32_t)63U;
	EXPECT_EQ(0x0000003FU, reg.Value);
}

TEST(PLLCFGR, PLLN)
{
	PLLCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLN = (uint32_t)511U;
	EXPECT_EQ(0x00007FC0U, reg.Value);
}

TEST(PLLCFGR, PLLP)
{
	PLLCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLP = (MainPllDivisionFactor)3U;
	EXPECT_EQ(0x00030000U, reg.Value);
}

TEST(PLLCFGR, PLLSRC)
{
	PLLCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLSRC = (MainPllAndAudioPllEntryClockSource)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(PLLCFGR, PLLQ)
{
	PLLCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLQ = (uint32_t)15U;
	EXPECT_EQ(0x0F000000U, reg.Value);
}

TEST(CFGR, SW)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.SW = (SystemClock)3U;
	EXPECT_EQ(0x00000003U, reg.Value);
}

TEST(CFGR, SWS)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.SWS = (SystemClock)3U;
	EXPECT_EQ(0x0000000CU, reg.Value);
}

TEST(CFGR, HPRE)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.HPRE = (AhbPrescaler)15U;
	EXPECT_EQ(0x000000F0U, reg.Value);
}

TEST(CFGR, PPRE1)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PPRE1 = (ApbPrescaler)7U;
	EXPECT_EQ(0x00001C00U, reg.Value);
}

TEST(CFGR, PPRE2)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PPRE2 = (ApbPrescaler)7U;
	EXPECT_EQ(0x0000E000U, reg.Value);
}

TEST(CFGR, RTCPRE)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.RTCPRE = (uint32_t)31U;
	EXPECT_EQ(0x001F0000U, reg.Value);
}

TEST(CFGR, MCO1)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.MCO1 = (MicrocontrollerClockOutput1)3U;
	EXPECT_EQ(0x00600000U, reg.Value);
}

TEST(CFGR, I2SSCR)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.I2SSCR = (I2SClockSelection)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(CFGR, MCO1PRE)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.MCO1PRE = (McoPrescaler)7U;
	EXPECT_EQ(0x07000000U, reg.Value);
}

TEST(CFGR, MCO2PRE)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.MCO2PRE = (McoPrescaler)7U;
	EXPECT_EQ(0x38000000U, reg.Value);
}

TEST(CFGR, MCO2)
{
	CFGR_t reg;
	reg.Value = 0U;
	reg.Fields.MCO2 = (MicrocontrollerClockOutput2)3U;
	EXPECT_EQ(0xC0000000U, reg.Value);
}

TEST(CIR, LSIRDYF)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.LSIRDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(CIR, LSERDYF)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.LSERDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(CIR, HSIRDYF)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.HSIRDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(CIR, HSERDYF)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.HSERDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(CIR, PLLRDYF)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLRDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(CIR, PLLI2SRDYF)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SRDYF = (ReadyFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(CIR, CSSF)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.CSSF = (ClockSecuritySystemInterruptFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(CIR, LSIRDYIE)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.LSIRDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(CIR, LSERDYIE)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.LSERDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(CIR, HSIRDYIE)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.HSIRDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(CIR, HSERDYIE)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.HSERDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(CIR, PLLRDYIE)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLRDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(CIR, PLLI2SRDYIE)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SRDYIE = (EnableFlag)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(CIR, LSIRDYC)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.LSIRDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(CIR, LSERDYC)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.LSERDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(CIR, HSIRDYC)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.HSIRDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(CIR, HSERDYC)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.HSERDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(CIR, PLLRDYC)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLRDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(CIR, PLLI2SRDYC)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SRDYC = (ClearFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(CIR, CSSC)
{
	CIR_t reg;
	reg.Value = 0U;
	reg.Fields.CSSC = (ClearFlag)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(AHB1RSTR, GPIOARST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOARST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(AHB1RSTR, GPIOBRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOBRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(AHB1RSTR, GPIOCRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOCRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(AHB1RSTR, GPIODRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIODRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(AHB1RSTR, GPIOERST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOERST = (ResetFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(AHB1RSTR, GPIOFRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOFRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(AHB1RSTR, GPIOGRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOGRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(AHB1RSTR, GPIOHRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOHRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(AHB1RSTR, GPIOIRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOIRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(AHB1RSTR, CRCRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.CRCRST = (ResetFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(AHB1RSTR, DMA1RST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.DMA1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(AHB1RSTR, DMA2RST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.DMA2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(AHB1RSTR, ETHMACRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.ETHMACRST = (ResetFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(AHB1RSTR, OTGHSRST)
{
	AHB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.OTGHSRST = (ResetFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(AHB2RSTR, DCMIRST)
{
	AHB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.DCMIRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(AHB2RSTR, CRYPRST)
{
	AHB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.CRYPRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(AHB2RSTR, HASHRST)
{
	AHB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.HASHRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(AHB2RSTR, RNGRST)
{
	AHB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.RNGRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(AHB2RSTR, OTGFSRST)
{
	AHB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.OTGFSRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(AHB3RSTR, FSMCRST)
{
	AHB3RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.FSMCRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(APB1RSTR, TIM2RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(APB1RSTR, TIM3RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM3RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(APB1RSTR, TIM4RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM4RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(APB1RSTR, TIM5RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM5RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(APB1RSTR, TIM6RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM6RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(APB1RSTR, TIM7RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM7RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(APB1RSTR, TIM12RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM12RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(APB1RSTR, TIM13RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM13RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(APB1RSTR, TIM14RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM14RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(APB1RSTR, WWDGRST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.WWDGRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(APB1RSTR, SPI2RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.SPI2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(APB1RSTR, SPI3RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.SPI3RST = (ResetFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(APB1RSTR, UART2RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.UART2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(APB1RSTR, UART3RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.UART3RST = (ResetFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(APB1RSTR, UART4RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.UART4RST = (ResetFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(APB1RSTR, UART5RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.UART5RST = (ResetFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(APB1RSTR, I2C1RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.I2C1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(APB1RSTR, I2C2RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.I2C2RST = (ResetFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(APB1RSTR, I2C3RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.I2C3RST = (ResetFlag)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(APB1RSTR, CAN1RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.CAN1RST = (ResetFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(APB1RSTR, CAN2RST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.CAN2RST = (ResetFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(APB1RSTR, PWRRST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.PWRRST = (ResetFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(APB1RSTR, DACRST)
{
	APB1RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.DACRST = (ResetFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(APB2RSTR, TIM1RST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(APB2RSTR, TIM8RST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM8RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(APB2RSTR, USART1RST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.USART1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(APB2RSTR, USART6RST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.USART6RST = (ResetFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(APB2RSTR, ADCRST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.ADCRST = (ResetFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(APB2RSTR, SDIORST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.SDIORST = (ResetFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(APB2RSTR, SPI1RST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.SPI1RST = (ResetFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(APB2RSTR, SYSCFGRST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.SYSCFGRST = (ResetFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(APB2RSTR, TIM9RST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM9RST = (ResetFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(APB2RSTR, TIM10RST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM10RST = (ResetFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(APB2RSTR, TIM11RST)
{
	APB2RSTR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM11RST = (ResetFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(AHB1ENR, GPIOAEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOAEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(AHB1ENR, GPIOBEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOBEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(AHB1ENR, GPIOCEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOCEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(AHB1ENR, GPIODEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIODEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(AHB1ENR, GPIOEEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOEEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(AHB1ENR, GPIOFEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOFEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(AHB1ENR, GPIOGEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOGEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(AHB1ENR, GPIOHEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOHEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(AHB1ENR, GPIOIEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOIEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(AHB1ENR, CRCEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.CRCEN = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(AHB1ENR, BKPSRAMEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.BKPSRAMEN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(AHB1ENR, CCMDATARAMEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.CCMDATARAMEN = (EnableFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(AHB1ENR, DMA1EN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.DMA1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(AHB1ENR, DMA2EN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.DMA2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(AHB1ENR, ETHMACEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.ETHMACEN = (EnableFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(AHB1ENR, ETHMACTXEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.ETHMACTXEN = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(AHB1ENR, ETHMACRXEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.ETHMACRXEN = (EnableFlag)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(AHB1ENR, ETHMACPTPEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.ETHMACPTPEN = (EnableFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(AHB1ENR, OTGHSEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.OTGHSEN = (EnableFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(AHB1ENR, OTGHSULPIEN)
{
	AHB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.OTGHSULPIEN = (EnableFlag)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(AHB2ENR, DCMIEN)
{
	AHB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.DCMIEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(AHB2ENR, CRYPEN)
{
	AHB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.CRYPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(AHB2ENR, HASHEN)
{
	AHB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.HASHEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(AHB2ENR, RNGEN)
{
	AHB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.RNGEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(AHB2ENR, OTGFSEN)
{
	AHB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.OTGFSEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(AHB3ENR, FSMCEN)
{
	AHB3ENR_t reg;
	reg.Value = 0U;
	reg.Fields.FSMCEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(APB1ENR, TIM2EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(APB1ENR, TIM3EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(APB1ENR, TIM4EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM4EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(APB1ENR, TIM5EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM5EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(APB1ENR, TIM6EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM6EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(APB1ENR, TIM7EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM7EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(APB1ENR, TIM12EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM12EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(APB1ENR, TIM13EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM13EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(APB1ENR, TIM14EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM14EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(APB1ENR, WWDGEN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.WWDGEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(APB1ENR, SPI2EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.SPI2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(APB1ENR, SPI3EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.SPI3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(APB1ENR, USART2EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.USART2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(APB1ENR, USART3EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.USART3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(APB1ENR, UART4EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.UART4EN = (EnableFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(APB1ENR, UART5EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.UART5EN = (EnableFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(APB1ENR, I2C1EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.I2C1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(APB1ENR, I2C2EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.I2C2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(APB1ENR, I2C3EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.I2C3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(APB1ENR, CAN1EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.CAN1EN = (EnableFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(APB1ENR, CAN2EN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.CAN2EN = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(APB1ENR, PWREN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.PWREN = (EnableFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(APB1ENR, DACEN)
{
	APB1ENR_t reg;
	reg.Value = 0U;
	reg.Fields.DACEN = (EnableFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(APB2ENR, TIM1EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(APB2ENR, TIM8EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM8EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(APB2ENR, USART1EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.USART1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(APB2ENR, USART6EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.USART6EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(APB2ENR, ADC1EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.ADC1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(APB2ENR, ADC2EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.ADC2EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(APB2ENR, ADC3EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.ADC3EN = (EnableFlag)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(APB2ENR, SDIOEN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.SDIOEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(APB2ENR, SPI1EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.SPI1EN = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(APB2ENR, SYSCFGEN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.SYSCFGEN = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(APB2ENR, TIM9EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM9EN = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(APB2ENR, TIM10EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM10EN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(APB2ENR, TIM11EN)
{
	APB2ENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM11EN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(AHB1LPENR, GPIOALPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOALPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(AHB1LPENR, GPIOBLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOBLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(AHB1LPENR, GPIOCLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOCLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(AHB1LPENR, GPIODLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIODLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(AHB1LPENR, GPIOELPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOELPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(AHB1LPENR, GPIOFLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOFLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(AHB1LPENR, GPIOGLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOGLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(AHB1LPENR, GPIOHLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOHLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(AHB1LPENR, GPIOILPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.GPIOILPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(AHB1LPENR, CRCLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.CRCLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(AHB1LPENR, FLITFLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.FLITFLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(AHB1LPENR, SRAM1LPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.SRAM1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(AHB1LPENR, SRAM2LPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.SRAM2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(AHB1LPENR, BKPSRAMLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.BKPSRAMLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(AHB1LPENR, DMA1LPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.DMA1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(AHB1LPENR, DMA2LPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.DMA2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(AHB1LPENR, ETHMACLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.ETHMACLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(AHB1LPENR, ETHMACTXLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.ETHMACTXLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(AHB1LPENR, ETHMACRXLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.ETHMACRXLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(AHB1LPENR, ETHMACPTPLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.ETHMACPTPLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(AHB1LPENR, OTGHSLPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.OTGHSLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(AHB1LPENR, OTGHSULPILPEN)
{
	AHB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.OTGHSULPILPEN = (EnableFlag)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(AHB2LPENR, DCMILPEN)
{
	AHB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.DCMILPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(AHB2LPENR, CRYPLPEN)
{
	AHB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.CRYPLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(AHB2LPENR, HASHLPEN)
{
	AHB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.HASHLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(AHB2LPENR, RNGLPEN)
{
	AHB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.RNGLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(AHB2LPENR, OTGFSLPEN)
{
	AHB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.OTGFSLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(AHB3LPENR, FSMCLPEN)
{
	AHB3LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.FSMCLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(APB1LPENR, TIM2LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(APB1LPENR, TIM3LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(APB1LPENR, TIM4LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM4LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(APB1LPENR, TIM5LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM5LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(APB1LPENR, TIM6LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM6LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(APB1LPENR, TIM7LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM7LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(APB1LPENR, TIM12LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM12LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(APB1LPENR, TIM13LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM13LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(APB1LPENR, TIM14LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM14LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(APB1LPENR, WWDGLPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.WWDGLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(APB1LPENR, SPI2LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.SPI2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(APB1LPENR, SPI3LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.SPI3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(APB1LPENR, USART2LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.USART2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(APB1LPENR, USART3LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.USART3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(APB1LPENR, UART4LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.UART4LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(APB1LPENR, UART5LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.UART5LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(APB1LPENR, I2C1LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.I2C1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(APB1LPENR, I2C2LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.I2C2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(APB1LPENR, I2C3LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.I2C3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00800000U, reg.Value);
}

TEST(APB1LPENR, CAN1LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.CAN1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(APB1LPENR, CAN2LPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.CAN2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(APB1LPENR, PWRLPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.PWRLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(APB1LPENR, DACLPEN)
{
	APB1LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.DACLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(APB2LPENR, TIM1LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(APB2LPENR, TIM8LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM8LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(APB2LPENR, USART1LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.USART1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(APB2LPENR, USART6LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.USART6LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(APB2LPENR, ADC1LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.ADC1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(APB2LPENR, ADC2LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.ADC2LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(APB2LPENR, ADC3LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.ADC3LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(APB2LPENR, SDIOLPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.SDIOLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(APB2LPENR, SPI1LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.SPI1LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(APB2LPENR, SYSCFGLPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.SYSCFGLPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(APB2LPENR, TIM9LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM9LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(APB2LPENR, TIM10LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM10LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(APB2LPENR, TIM11LPEN)
{
	APB2LPENR_t reg;
	reg.Value = 0U;
	reg.Fields.TIM11LPEN = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(BDCR, LSEON)
{
	BDCR_t reg;
	reg.Value = 0U;
	reg.Fields.LSEON = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(BDCR, LSERDY)
{
	BDCR_t reg;
	reg.Value = 0U;
	reg.Fields.LSERDY = (ReadyFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(BDCR, LSEBYP)
{
	BDCR_t reg;
	reg.Value = 0U;
	reg.Fields.LSEBYP = (ExternalLowSpeedOscillatorBypass)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(BDCR, RTCSEL)
{
	BDCR_t reg;
	reg.Value = 0U;
	reg.Fields.RTCSEL = (RtcClockSourceSelection)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(BDCR, RTCEN)
{
	BDCR_t reg;
	reg.Value = 0U;
	reg.Fields.RTCEN = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(BDCR, BDRST)
{
	BDCR_t reg;
	reg.Value = 0U;
	reg.Fields.BDRST = (ResetFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(CSR, LSION)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.LSION = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(CSR, LSIRDY)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.LSIRDY = (ReadyFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(CSR, RMVF)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.RMVF = (ClearFlag)1U;
	EXPECT_EQ(0x01000000U, reg.Value);
}

TEST(CSR, BORRSTF)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.BORRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x02000000U, reg.Value);
}

TEST(CSR, PINRSTF)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.PINRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x04000000U, reg.Value);
}

TEST(CSR, PORRSTF)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.PORRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x08000000U, reg.Value);
}

TEST(CSR, SFTRSTF)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.SFTRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x10000000U, reg.Value);
}

TEST(CSR, IWDGRSTF)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.IWDGRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x20000000U, reg.Value);
}

TEST(CSR, WWDGRSTF)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.WWDGRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(CSR, LPWRRSTF)
{
	CSR_t reg;
	reg.Value = 0U;
	reg.Fields.LPWRRSTF = (ResetOccurredFlag)1U;
	EXPECT_EQ(0x80000000U, reg.Value);
}

TEST(SSCGR, MODPER)
{
	SSCGR_t reg;
	reg.Value = 0U;
	reg.Fields.MODPER = (uint32_t)8191U;
	EXPECT_EQ(0x00001FFFU, reg.Value);
}

TEST(SSCGR, INCSTEP)
{
	SSCGR_t reg;
	reg.Value = 0U;
	reg.Fields.INCSTEP = (uint32_t)32767U;
	EXPECT_EQ(0x0FFFE000U, reg.Value);
}

TEST(SSCGR, SPREADSEL)
{
	SSCGR_t reg;
	reg.Value = 0U;
	reg.Fields.SPREADSEL = (SpreadSelect)1U;
	EXPECT_EQ(0x40000000U, reg.Value);
}

TEST(SSCGR, SSCGEN)
{
	SSCGR_t reg;
	reg.Value = 0U;
	reg.Fields.SSCGEN = (EnableFlag)1U;
	EXPECT_EQ(0x80000000U, reg.Value);
}

TEST(PLLI2SCFGR, PLLI2SN)
{
	PLLI2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SN = (uint32_t)511U;
	EXPECT_EQ(0x00007FC0U, reg.Value);
}

TEST(PLLI2SCFGR, PLLI2SR)
{
	PLLI2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PLLI2SR = (uint32_t)7U;
	EXPECT_EQ(0x70000000U, reg.Value);
}

