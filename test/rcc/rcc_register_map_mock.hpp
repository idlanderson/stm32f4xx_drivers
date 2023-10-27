#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "rcc_register_map.hpp"

using namespace stm32::rcc;
using namespace testing;

class MockRccRegisterMap : public RccRegisterMap
{
public:

	// CR Fields
	MOCK_METHOD(EnableFlag, get_CR_HSION, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CR_HSIRDY, (), (const, override));
	MOCK_METHOD(uint32_t, get_CR_HSITRIM, (), (const, override));
	MOCK_METHOD(uint32_t, get_CR_HSICAL, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CR_HSEON, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CR_HSERDY, (), (const, override));
	MOCK_METHOD(HseClockBypass, get_CR_HSEBYP, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CR_CSSON, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CR_PLLON, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CR_PLLRDY, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CR_PLLI2SON, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CR_PLLI2SRDY, (), (const, override));
	MOCK_METHOD(void, set_CR_HSION, (EnableFlag), (override));
	MOCK_METHOD(void, set_CR_HSITRIM, (uint32_t), (override));
	MOCK_METHOD(void, set_CR_HSEON, (EnableFlag), (override));
	MOCK_METHOD(void, set_CR_HSEBYP, (HseClockBypass), (override));
	MOCK_METHOD(void, set_CR_CSSON, (EnableFlag), (override));
	MOCK_METHOD(void, set_CR_PLLON, (EnableFlag), (override));
	MOCK_METHOD(void, set_CR_PLLI2SON, (EnableFlag), (override));

	// PLLCFGR Fields
	MOCK_METHOD(uint32_t, get_PLLCFGR_PLLM, (), (const, override));
	MOCK_METHOD(uint32_t, get_PLLCFGR_PLLN, (), (const, override));
	MOCK_METHOD(MainPllDivisionFactor, get_PLLCFGR_PLLP, (), (const, override));
	MOCK_METHOD(MainPllAndAudioPllEntryClockSource, get_PLLCFGR_PLLSRC, (), (const, override));
	MOCK_METHOD(uint32_t, get_PLLCFGR_PLLQ, (), (const, override));
	MOCK_METHOD(void, set_PLLCFGR_PLLM, (uint32_t), (override));
	MOCK_METHOD(void, set_PLLCFGR_PLLN, (uint32_t), (override));
	MOCK_METHOD(void, set_PLLCFGR_PLLP, (MainPllDivisionFactor), (override));
	MOCK_METHOD(void, set_PLLCFGR_PLLSRC, (MainPllAndAudioPllEntryClockSource), (override));
	MOCK_METHOD(void, set_PLLCFGR_PLLQ, (uint32_t), (override));

	// CFGR Fields
	MOCK_METHOD(SystemClock, get_CFGR_SW, (), (const, override));
	MOCK_METHOD(SystemClock, get_CFGR_SWS, (), (const, override));
	MOCK_METHOD(AhbPrescaler, get_CFGR_HPRE, (), (const, override));
	MOCK_METHOD(ApbPrescaler, get_CFGR_PPRE1, (), (const, override));
	MOCK_METHOD(ApbPrescaler, get_CFGR_PPRE2, (), (const, override));
	MOCK_METHOD(uint32_t, get_CFGR_RTCPRE, (), (const, override));
	MOCK_METHOD(MicrocontrollerClockOutput1, get_CFGR_MCO1, (), (const, override));
	MOCK_METHOD(I2SClockSelection, get_CFGR_I2SSCR, (), (const, override));
	MOCK_METHOD(McoPrescaler, get_CFGR_MCO1PRE, (), (const, override));
	MOCK_METHOD(McoPrescaler, get_CFGR_MCO2PRE, (), (const, override));
	MOCK_METHOD(MicrocontrollerClockOutput2, get_CFGR_MCO2, (), (const, override));
	MOCK_METHOD(void, set_CFGR_SW, (SystemClock), (override));
	MOCK_METHOD(void, set_CFGR_HPRE, (AhbPrescaler), (override));
	MOCK_METHOD(void, set_CFGR_PPRE1, (ApbPrescaler), (override));
	MOCK_METHOD(void, set_CFGR_PPRE2, (ApbPrescaler), (override));
	MOCK_METHOD(void, set_CFGR_RTCPRE, (uint32_t), (override));
	MOCK_METHOD(void, set_CFGR_MCO1, (MicrocontrollerClockOutput1), (override));
	MOCK_METHOD(void, set_CFGR_I2SSCR, (I2SClockSelection), (override));
	MOCK_METHOD(void, set_CFGR_MCO1PRE, (McoPrescaler), (override));
	MOCK_METHOD(void, set_CFGR_MCO2PRE, (McoPrescaler), (override));
	MOCK_METHOD(void, set_CFGR_MCO2, (MicrocontrollerClockOutput2), (override));

	// CIR Fields
	MOCK_METHOD(ReadyFlag, get_CIR_LSIRDYF, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CIR_LSERDYF, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CIR_HSIRDYF, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CIR_HSERDYF, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CIR_PLLRDYF, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CIR_PLLI2SRDYF, (), (const, override));
	MOCK_METHOD(ClockSecuritySystemInterruptFlag, get_CIR_CSSF, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CIR_LSIRDYIE, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CIR_LSERDYIE, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CIR_HSIRDYIE, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CIR_HSERDYIE, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CIR_PLLRDYIE, (), (const, override));
	MOCK_METHOD(EnableFlag, get_CIR_PLLI2SRDYIE, (), (const, override));
	MOCK_METHOD(void, set_CIR_LSIRDYIE, (EnableFlag), (override));
	MOCK_METHOD(void, set_CIR_LSERDYIE, (EnableFlag), (override));
	MOCK_METHOD(void, set_CIR_HSIRDYIE, (EnableFlag), (override));
	MOCK_METHOD(void, set_CIR_HSERDYIE, (EnableFlag), (override));
	MOCK_METHOD(void, set_CIR_PLLRDYIE, (EnableFlag), (override));
	MOCK_METHOD(void, set_CIR_PLLI2SRDYIE, (EnableFlag), (override));
	MOCK_METHOD(void, set_CIR_LSIRDYC, (ClearFlag), (override));
	MOCK_METHOD(void, set_CIR_LSERDYC, (ClearFlag), (override));
	MOCK_METHOD(void, set_CIR_HSIRDYC, (ClearFlag), (override));
	MOCK_METHOD(void, set_CIR_HSERDYC, (ClearFlag), (override));
	MOCK_METHOD(void, set_CIR_PLLRDYC, (ClearFlag), (override));
	MOCK_METHOD(void, set_CIR_PLLI2SRDYC, (ClearFlag), (override));
	MOCK_METHOD(void, set_CIR_CSSC, (ClearFlag), (override));

	// AHB1RSTR Fields
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_GPIOARST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_GPIOBRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_GPIOCRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_GPIODRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_GPIOERST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_GPIOFRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_GPIOGRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_GPIOHRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_GPIOIRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_CRCRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_DMA1RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_DMA2RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_ETHMACRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB1RSTR_OTGHSRST, (), (const, override));
	MOCK_METHOD(void, set_AHB1RSTR_GPIOARST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_GPIOBRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_GPIOCRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_GPIODRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_GPIOERST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_GPIOFRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_GPIOGRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_GPIOHRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_GPIOIRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_CRCRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_DMA1RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_DMA2RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_ETHMACRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB1RSTR_OTGHSRST, (ResetFlag), (override));

	// AHB2RSTR Fields
	MOCK_METHOD(ResetFlag, get_AHB2RSTR_DCMIRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB2RSTR_CRYPRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB2RSTR_HASHRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB2RSTR_RNGRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_AHB2RSTR_OTGFSRST, (), (const, override));
	MOCK_METHOD(void, set_AHB2RSTR_DCMIRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB2RSTR_CRYPRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB2RSTR_HASHRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB2RSTR_RNGRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_AHB2RSTR_OTGFSRST, (ResetFlag), (override));

	// AHB3RSTR Fields
	MOCK_METHOD(ResetFlag, get_AHB3RSTR_FSMCRST, (), (const, override));
	MOCK_METHOD(void, set_AHB3RSTR_FSMCRST, (ResetFlag), (override));

	// APB1RSTR Fields
	MOCK_METHOD(ResetFlag, get_APB1RSTR_TIM2RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_TIM3RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_TIM4RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_TIM5RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_TIM6RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_TIM7RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_TIM12RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_TIM13RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_TIM14RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_WWDGRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_SPI2RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_SPI3RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_UART2RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_UART3RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_UART4RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_UART5RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_I2C1RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_I2C2RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_I2C3RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_CAN1RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_CAN2RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_PWRRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB1RSTR_DACRST, (), (const, override));
	MOCK_METHOD(void, set_APB1RSTR_TIM2RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_TIM3RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_TIM4RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_TIM5RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_TIM6RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_TIM7RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_TIM12RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_TIM13RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_TIM14RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_WWDGRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_SPI2RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_SPI3RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_UART2RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_UART3RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_UART4RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_UART5RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_I2C1RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_I2C2RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_I2C3RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_CAN1RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_CAN2RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_PWRRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB1RSTR_DACRST, (ResetFlag), (override));

	// APB2RSTR Fields
	MOCK_METHOD(ResetFlag, get_APB2RSTR_TIM1RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_TIM8RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_USART1RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_USART6RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_ADCRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_SDIORST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_SPI1RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_SYSCFGRST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_TIM9RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_TIM10RST, (), (const, override));
	MOCK_METHOD(ResetFlag, get_APB2RSTR_TIM11RST, (), (const, override));
	MOCK_METHOD(void, set_APB2RSTR_TIM1RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_TIM8RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_USART1RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_USART6RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_ADCRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_SDIORST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_SPI1RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_SYSCFGRST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_TIM9RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_TIM10RST, (ResetFlag), (override));
	MOCK_METHOD(void, set_APB2RSTR_TIM11RST, (ResetFlag), (override));

	// AHB1ENR Fields
	MOCK_METHOD(EnableFlag, get_AHB1ENR_GPIOAEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_GPIOBEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_GPIOCEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_GPIODEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_GPIOEEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_GPIOFEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_GPIOGEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_GPIOHEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_GPIOIEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_CRCEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_BKPSRAMEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_CCMDATARAMEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_DMA1EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_DMA2EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_ETHMACEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_ETHMACTXEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_ETHMACRXEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_ETHMACPTPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_OTGHSEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1ENR_OTGHSULPIEN, (), (const, override));
	MOCK_METHOD(void, set_AHB1ENR_GPIOAEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_GPIOBEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_GPIOCEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_GPIODEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_GPIOEEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_GPIOFEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_GPIOGEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_GPIOHEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_GPIOIEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_CRCEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_BKPSRAMEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_CCMDATARAMEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_DMA1EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_DMA2EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_ETHMACEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_ETHMACTXEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_ETHMACRXEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_ETHMACPTPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_OTGHSEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1ENR_OTGHSULPIEN, (EnableFlag), (override));

	// AHB2ENR Fields
	MOCK_METHOD(EnableFlag, get_AHB2ENR_DCMIEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB2ENR_CRYPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB2ENR_HASHEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB2ENR_RNGEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB2ENR_OTGFSEN, (), (const, override));
	MOCK_METHOD(void, set_AHB2ENR_DCMIEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB2ENR_CRYPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB2ENR_HASHEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB2ENR_RNGEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB2ENR_OTGFSEN, (EnableFlag), (override));

	// AHB3ENR Fields
	MOCK_METHOD(EnableFlag, get_AHB3ENR_FSMCEN, (), (const, override));
	MOCK_METHOD(void, set_AHB3ENR_FSMCEN, (EnableFlag), (override));

	// APB1ENR Fields
	MOCK_METHOD(EnableFlag, get_APB1ENR_TIM2EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_TIM3EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_TIM4EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_TIM5EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_TIM6EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_TIM7EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_TIM12EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_TIM13EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_TIM14EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_WWDGEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_SPI2EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_SPI3EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_USART2EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_USART3EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_UART4EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_UART5EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_I2C1EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_I2C2EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_I2C3EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_CAN1EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_CAN2EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_PWREN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1ENR_DACEN, (), (const, override));
	MOCK_METHOD(void, set_APB1ENR_TIM2EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_TIM3EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_TIM4EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_TIM5EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_TIM6EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_TIM7EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_TIM12EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_TIM13EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_TIM14EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_WWDGEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_SPI2EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_SPI3EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_USART2EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_USART3EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_UART4EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_UART5EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_I2C1EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_I2C2EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_I2C3EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_CAN1EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_CAN2EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_PWREN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1ENR_DACEN, (EnableFlag), (override));

	// APB2ENR Fields
	MOCK_METHOD(EnableFlag, get_APB2ENR_TIM1EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_TIM8EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_USART1EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_USART6EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_ADC1EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_ADC2EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_ADC3EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_SDIOEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_SPI1EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_SYSCFGEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_TIM9EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_TIM10EN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2ENR_TIM11EN, (), (const, override));
	MOCK_METHOD(void, set_APB2ENR_TIM1EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_TIM8EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_USART1EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_USART6EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_ADC1EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_ADC2EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_ADC3EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_SDIOEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_SPI1EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_SYSCFGEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_TIM9EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_TIM10EN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2ENR_TIM11EN, (EnableFlag), (override));

	// AHB1LPENR Fields
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_GPIOALPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_GPIOBLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_GPIOCLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_GPIODLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_GPIOELPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_GPIOFLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_GPIOGLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_GPIOHLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_GPIOILPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_CRCLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_FLITFLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_SRAM1LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_SRAM2LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_BKPSRAMLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_DMA1LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_DMA2LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_ETHMACLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_ETHMACTXLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_ETHMACRXLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_ETHMACPTPLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_OTGHSLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB1LPENR_OTGHSULPILPEN, (), (const, override));
	MOCK_METHOD(void, set_AHB1LPENR_GPIOALPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_GPIOBLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_GPIOCLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_GPIODLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_GPIOELPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_GPIOFLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_GPIOGLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_GPIOHLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_GPIOILPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_CRCLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_FLITFLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_SRAM1LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_SRAM2LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_BKPSRAMLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_DMA1LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_DMA2LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_ETHMACLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_ETHMACTXLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_ETHMACRXLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_ETHMACPTPLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_OTGHSLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB1LPENR_OTGHSULPILPEN, (EnableFlag), (override));

	// AHB2LPENR Fields
	MOCK_METHOD(EnableFlag, get_AHB2LPENR_DCMILPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB2LPENR_CRYPLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB2LPENR_HASHLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB2LPENR_RNGLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_AHB2LPENR_OTGFSLPEN, (), (const, override));
	MOCK_METHOD(void, set_AHB2LPENR_DCMILPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB2LPENR_CRYPLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB2LPENR_HASHLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB2LPENR_RNGLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_AHB2LPENR_OTGFSLPEN, (EnableFlag), (override));

	// AHB3LPENR Fields
	MOCK_METHOD(EnableFlag, get_AHB3LPENR_FSMCLPEN, (), (const, override));
	MOCK_METHOD(void, set_AHB3LPENR_FSMCLPEN, (EnableFlag), (override));

	// APB1LPENR Fields
	MOCK_METHOD(EnableFlag, get_APB1LPENR_TIM2LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_TIM3LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_TIM4LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_TIM5LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_TIM6LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_TIM7LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_TIM12LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_TIM13LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_TIM14LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_WWDGLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_SPI2LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_SPI3LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_USART2LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_USART3LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_UART4LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_UART5LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_I2C1LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_I2C2LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_I2C3LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_CAN1LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_CAN2LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_PWRLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB1LPENR_DACLPEN, (), (const, override));
	MOCK_METHOD(void, set_APB1LPENR_TIM2LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_TIM3LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_TIM4LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_TIM5LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_TIM6LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_TIM7LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_TIM12LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_TIM13LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_TIM14LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_WWDGLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_SPI2LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_SPI3LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_USART2LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_USART3LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_UART4LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_UART5LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_I2C1LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_I2C2LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_I2C3LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_CAN1LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_CAN2LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_PWRLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB1LPENR_DACLPEN, (EnableFlag), (override));

	// APB2LPENR Fields
	MOCK_METHOD(EnableFlag, get_APB2LPENR_TIM1LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_TIM8LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_USART1LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_USART6LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_ADC1LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_ADC2LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_ADC3LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_SDIOLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_SPI1LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_SYSCFGLPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_TIM9LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_TIM10LPEN, (), (const, override));
	MOCK_METHOD(EnableFlag, get_APB2LPENR_TIM11LPEN, (), (const, override));
	MOCK_METHOD(void, set_APB2LPENR_TIM1LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_TIM8LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_USART1LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_USART6LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_ADC1LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_ADC2LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_ADC3LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_SDIOLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_SPI1LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_SYSCFGLPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_TIM9LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_TIM10LPEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_APB2LPENR_TIM11LPEN, (EnableFlag), (override));

	// BDCR Fields
	MOCK_METHOD(EnableFlag, get_BDCR_LSEON, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_BDCR_LSERDY, (), (const, override));
	MOCK_METHOD(ExternalLowSpeedOscillatorBypass, get_BDCR_LSEBYP, (), (const, override));
	MOCK_METHOD(RtcClockSourceSelection, get_BDCR_RTCSEL, (), (const, override));
	MOCK_METHOD(EnableFlag, get_BDCR_RTCEN, (), (const, override));
	MOCK_METHOD(ResetFlag, get_BDCR_BDRST, (), (const, override));
	MOCK_METHOD(void, set_BDCR_LSEON, (EnableFlag), (override));
	MOCK_METHOD(void, set_BDCR_LSEBYP, (ExternalLowSpeedOscillatorBypass), (override));
	MOCK_METHOD(void, set_BDCR_RTCSEL, (RtcClockSourceSelection), (override));
	MOCK_METHOD(void, set_BDCR_RTCEN, (EnableFlag), (override));
	MOCK_METHOD(void, set_BDCR_BDRST, (ResetFlag), (override));

	// CSR Fields
	MOCK_METHOD(EnableFlag, get_CSR_LSION, (), (const, override));
	MOCK_METHOD(ReadyFlag, get_CSR_LSIRDY, (), (const, override));
	MOCK_METHOD(ClearFlag, get_CSR_RMVF, (), (const, override));
	MOCK_METHOD(ResetOccurredFlag, get_CSR_BORRSTF, (), (const, override));
	MOCK_METHOD(ResetOccurredFlag, get_CSR_PINRSTF, (), (const, override));
	MOCK_METHOD(ResetOccurredFlag, get_CSR_PORRSTF, (), (const, override));
	MOCK_METHOD(ResetOccurredFlag, get_CSR_SFTRSTF, (), (const, override));
	MOCK_METHOD(ResetOccurredFlag, get_CSR_IWDGRSTF, (), (const, override));
	MOCK_METHOD(ResetOccurredFlag, get_CSR_WWDGRSTF, (), (const, override));
	MOCK_METHOD(ResetOccurredFlag, get_CSR_LPWRRSTF, (), (const, override));
	MOCK_METHOD(void, set_CSR_LSION, (EnableFlag), (override));
	MOCK_METHOD(void, set_CSR_RMVF, (ClearFlag), (override));

	// SSCGR Fields
	MOCK_METHOD(uint32_t, get_SSCGR_MODPER, (), (const, override));
	MOCK_METHOD(uint32_t, get_SSCGR_INCSTEP, (), (const, override));
	MOCK_METHOD(SpreadSelect, get_SSCGR_SPREADSEL, (), (const, override));
	MOCK_METHOD(EnableFlag, get_SSCGR_SSCGEN, (), (const, override));
	MOCK_METHOD(void, set_SSCGR_MODPER, (uint32_t), (override));
	MOCK_METHOD(void, set_SSCGR_INCSTEP, (uint32_t), (override));
	MOCK_METHOD(void, set_SSCGR_SPREADSEL, (SpreadSelect), (override));
	MOCK_METHOD(void, set_SSCGR_SSCGEN, (EnableFlag), (override));

	// PLLI2SCFGR Fields
	MOCK_METHOD(uint32_t, get_PLLI2SCFGR_PLLI2SN, (), (const, override));
	MOCK_METHOD(uint32_t, get_PLLI2SCFGR_PLLI2SR, (), (const, override));
	MOCK_METHOD(void, set_PLLI2SCFGR_PLLI2SN, (uint32_t), (override));
	MOCK_METHOD(void, set_PLLI2SCFGR_PLLI2SR, (uint32_t), (override));
};

