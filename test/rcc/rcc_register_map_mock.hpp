#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "rcc_register_map.hpp"

using namespace stm32::rcc;
using namespace testing;

class MockRccRegisterMap : public IRccRegisterMap
{
public:

	// CR Fields
	MOCK_CONST_METHOD0(get_CR_HSION, EnableFlag());
	MOCK_CONST_METHOD0(get_CR_HSIRDY, ReadyFlag());
	MOCK_CONST_METHOD0(get_CR_HSITRIM, uint32_t());
	MOCK_CONST_METHOD0(get_CR_HSICAL, uint32_t());
	MOCK_CONST_METHOD0(get_CR_HSEON, EnableFlag());
	MOCK_CONST_METHOD0(get_CR_HSERDY, ReadyFlag());
	MOCK_CONST_METHOD0(get_CR_HSEBYP, HseClockBypass());
	MOCK_CONST_METHOD0(get_CR_CSSON, EnableFlag());
	MOCK_CONST_METHOD0(get_CR_PLLON, EnableFlag());
	MOCK_CONST_METHOD0(get_CR_PLLRDY, ReadyFlag());
	MOCK_CONST_METHOD0(get_CR_PLLI2SON, EnableFlag());
	MOCK_CONST_METHOD0(get_CR_PLLI2SRDY, ReadyFlag());
	MOCK_METHOD1(set_CR_HSION, void(EnableFlag value));
	MOCK_METHOD1(set_CR_HSITRIM, void(uint32_t value));
	MOCK_METHOD1(set_CR_HSEON, void(EnableFlag value));
	MOCK_METHOD1(set_CR_HSEBYP, void(HseClockBypass value));
	MOCK_METHOD1(set_CR_CSSON, void(EnableFlag value));
	MOCK_METHOD1(set_CR_PLLON, void(EnableFlag value));
	MOCK_METHOD1(set_CR_PLLI2SON, void(EnableFlag value));

	// PLLCFGR Fields
	MOCK_CONST_METHOD0(get_PLLCFGR_PLLM, uint32_t());
	MOCK_CONST_METHOD0(get_PLLCFGR_PLLN, uint32_t());
	MOCK_CONST_METHOD0(get_PLLCFGR_PLLP, MainPllDivisionFactor());
	MOCK_CONST_METHOD0(get_PLLCFGR_PLLSRC, MainPllAndAudioPllEntryClockSource());
	MOCK_CONST_METHOD0(get_PLLCFGR_PLLQ, uint32_t());
	MOCK_METHOD1(set_PLLCFGR_PLLM, void(uint32_t value));
	MOCK_METHOD1(set_PLLCFGR_PLLN, void(uint32_t value));
	MOCK_METHOD1(set_PLLCFGR_PLLP, void(MainPllDivisionFactor value));
	MOCK_METHOD1(set_PLLCFGR_PLLSRC, void(MainPllAndAudioPllEntryClockSource value));
	MOCK_METHOD1(set_PLLCFGR_PLLQ, void(uint32_t value));

	// CFGR Fields
	MOCK_CONST_METHOD0(get_CFGR_SW, SystemClock());
	MOCK_CONST_METHOD0(get_CFGR_SWS, SystemClock());
	MOCK_CONST_METHOD0(get_CFGR_HPRE, AhbPrescaler());
	MOCK_CONST_METHOD0(get_CFGR_PPRE1, ApbPrescaler());
	MOCK_CONST_METHOD0(get_CFGR_PPRE2, ApbPrescaler());
	MOCK_CONST_METHOD0(get_CFGR_RTCPRE, uint32_t());
	MOCK_CONST_METHOD0(get_CFGR_MCO1, MicrocontrollerClockOutput1());
	MOCK_CONST_METHOD0(get_CFGR_I2SSCR, I2SClockSelection());
	MOCK_CONST_METHOD0(get_CFGR_MCO1PRE, McoPrescaler());
	MOCK_CONST_METHOD0(get_CFGR_MCO2PRE, McoPrescaler());
	MOCK_CONST_METHOD0(get_CFGR_MCO2, MicrocontrollerClockOutput2());
	MOCK_METHOD1(set_CFGR_SW, void(SystemClock value));
	MOCK_METHOD1(set_CFGR_HPRE, void(AhbPrescaler value));
	MOCK_METHOD1(set_CFGR_PPRE1, void(ApbPrescaler value));
	MOCK_METHOD1(set_CFGR_PPRE2, void(ApbPrescaler value));
	MOCK_METHOD1(set_CFGR_RTCPRE, void(uint32_t value));
	MOCK_METHOD1(set_CFGR_MCO1, void(MicrocontrollerClockOutput1 value));
	MOCK_METHOD1(set_CFGR_I2SSCR, void(I2SClockSelection value));
	MOCK_METHOD1(set_CFGR_MCO1PRE, void(McoPrescaler value));
	MOCK_METHOD1(set_CFGR_MCO2PRE, void(McoPrescaler value));
	MOCK_METHOD1(set_CFGR_MCO2, void(MicrocontrollerClockOutput2 value));

	// CIR Fields
	MOCK_CONST_METHOD0(get_CIR_LSIRDYF, ReadyFlag());
	MOCK_CONST_METHOD0(get_CIR_LSERDYF, ReadyFlag());
	MOCK_CONST_METHOD0(get_CIR_HSIRDYF, ReadyFlag());
	MOCK_CONST_METHOD0(get_CIR_HSERDYF, ReadyFlag());
	MOCK_CONST_METHOD0(get_CIR_PLLRDYF, ReadyFlag());
	MOCK_CONST_METHOD0(get_CIR_PLLI2SRDYF, ReadyFlag());
	MOCK_CONST_METHOD0(get_CIR_CSSF, ClockSecuritySystemInterruptFlag());
	MOCK_CONST_METHOD0(get_CIR_LSIRDYIE, EnableFlag());
	MOCK_CONST_METHOD0(get_CIR_LSERDYIE, EnableFlag());
	MOCK_CONST_METHOD0(get_CIR_HSIRDYIE, EnableFlag());
	MOCK_CONST_METHOD0(get_CIR_HSERDYIE, EnableFlag());
	MOCK_CONST_METHOD0(get_CIR_PLLRDYIE, EnableFlag());
	MOCK_CONST_METHOD0(get_CIR_PLLI2SRDYIE, EnableFlag());
	MOCK_METHOD1(set_CIR_LSIRDYIE, void(EnableFlag value));
	MOCK_METHOD1(set_CIR_LSERDYIE, void(EnableFlag value));
	MOCK_METHOD1(set_CIR_HSIRDYIE, void(EnableFlag value));
	MOCK_METHOD1(set_CIR_HSERDYIE, void(EnableFlag value));
	MOCK_METHOD1(set_CIR_PLLRDYIE, void(EnableFlag value));
	MOCK_METHOD1(set_CIR_PLLI2SRDYIE, void(EnableFlag value));
	MOCK_METHOD1(set_CIR_LSIRDYC, void(ClearFlag value));
	MOCK_METHOD1(set_CIR_LSERDYC, void(ClearFlag value));
	MOCK_METHOD1(set_CIR_HSIRDYC, void(ClearFlag value));
	MOCK_METHOD1(set_CIR_HSERDYC, void(ClearFlag value));
	MOCK_METHOD1(set_CIR_PLLRDYC, void(ClearFlag value));
	MOCK_METHOD1(set_CIR_PLLI2SRDYC, void(ClearFlag value));
	MOCK_METHOD1(set_CIR_CSSC, void(ClearFlag value));

	// AHB1RSTR Fields
	MOCK_CONST_METHOD0(get_AHB1RSTR_GPIOARST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_GPIOBRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_GPIOCRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_GPIODRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_GPIOERST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_GPIOFRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_GPIOGRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_GPIOHRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_GPIOIRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_CRCRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_DMA1RST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_DMA2RST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_ETHMACRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB1RSTR_OTGHSRST, ResetFlag());
	MOCK_METHOD1(set_AHB1RSTR_GPIOARST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_GPIOBRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_GPIOCRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_GPIODRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_GPIOERST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_GPIOFRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_GPIOGRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_GPIOHRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_GPIOIRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_CRCRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_DMA1RST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_DMA2RST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_ETHMACRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB1RSTR_OTGHSRST, void(ResetFlag value));

	// AHB2RSTR Fields
	MOCK_CONST_METHOD0(get_AHB2RSTR_DCMIRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB2RSTR_CRYPRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB2RSTR_HASHRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB2RSTR_RNGRST, ResetFlag());
	MOCK_CONST_METHOD0(get_AHB2RSTR_OTGFSRST, ResetFlag());
	MOCK_METHOD1(set_AHB2RSTR_DCMIRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB2RSTR_CRYPRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB2RSTR_HASHRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB2RSTR_RNGRST, void(ResetFlag value));
	MOCK_METHOD1(set_AHB2RSTR_OTGFSRST, void(ResetFlag value));

	// AHB3RSTR Fields
	MOCK_CONST_METHOD0(get_AHB3RSTR_FSMCRST, ResetFlag());
	MOCK_METHOD1(set_AHB3RSTR_FSMCRST, void(ResetFlag value));

	// APB1RSTR Fields
	MOCK_CONST_METHOD0(get_APB1RSTR_TIM2RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_TIM3RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_TIM4RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_TIM5RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_TIM6RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_TIM7RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_TIM12RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_TIM13RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_TIM14RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_WWDGRST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_SPI2RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_SPI3RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_UART2RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_UART3RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_UART4RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_UART5RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_I2C1RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_I2C2RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_I2C3RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_CAN1RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_CAN2RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_PWRRST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB1RSTR_DACRST, ResetFlag());
	MOCK_METHOD1(set_APB1RSTR_TIM2RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_TIM3RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_TIM4RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_TIM5RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_TIM6RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_TIM7RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_TIM12RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_TIM13RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_TIM14RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_WWDGRST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_SPI2RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_SPI3RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_UART2RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_UART3RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_UART4RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_UART5RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_I2C1RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_I2C2RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_I2C3RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_CAN1RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_CAN2RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_PWRRST, void(ResetFlag value));
	MOCK_METHOD1(set_APB1RSTR_DACRST, void(ResetFlag value));

	// APB2RSTR Fields
	MOCK_CONST_METHOD0(get_APB2RSTR_TIM1RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_TIM8RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_USART1RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_USART6RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_ADCRST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_SDIORST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_SPI1RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_SYSCFGRST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_TIM9RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_TIM10RST, ResetFlag());
	MOCK_CONST_METHOD0(get_APB2RSTR_TIM11RST, ResetFlag());
	MOCK_METHOD1(set_APB2RSTR_TIM1RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_TIM8RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_USART1RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_USART6RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_ADCRST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_SDIORST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_SPI1RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_SYSCFGRST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_TIM9RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_TIM10RST, void(ResetFlag value));
	MOCK_METHOD1(set_APB2RSTR_TIM11RST, void(ResetFlag value));

	// AHB1ENR Fields
	MOCK_CONST_METHOD0(get_AHB1ENR_GPIOAEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_GPIOBEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_GPIOCEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_GPIODEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_GPIOEEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_GPIOFEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_GPIOGEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_GPIOHEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_GPIOIEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_CRCEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_BKPSRAMEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_CCMDATARAMEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_DMA1EN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_DMA2EN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_ETHMACEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_ETHMACTXEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_ETHMACRXEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_ETHMACPTPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_OTGHSEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1ENR_OTGHSULPIEN, EnableFlag());
	MOCK_METHOD1(set_AHB1ENR_GPIOAEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_GPIOBEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_GPIOCEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_GPIODEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_GPIOEEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_GPIOFEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_GPIOGEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_GPIOHEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_GPIOIEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_CRCEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_BKPSRAMEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_CCMDATARAMEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_DMA1EN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_DMA2EN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_ETHMACEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_ETHMACTXEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_ETHMACRXEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_ETHMACPTPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_OTGHSEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1ENR_OTGHSULPIEN, void(EnableFlag value));

	// AHB2ENR Fields
	MOCK_CONST_METHOD0(get_AHB2ENR_DCMIEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB2ENR_CRYPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB2ENR_HASHEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB2ENR_RNGEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB2ENR_OTGFSEN, EnableFlag());
	MOCK_METHOD1(set_AHB2ENR_DCMIEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB2ENR_CRYPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB2ENR_HASHEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB2ENR_RNGEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB2ENR_OTGFSEN, void(EnableFlag value));

	// AHB3ENR Fields
	MOCK_CONST_METHOD0(get_AHB3ENR_FSMCEN, EnableFlag());
	MOCK_METHOD1(set_AHB3ENR_FSMCEN, void(EnableFlag value));

	// APB1ENR Fields
	MOCK_CONST_METHOD0(get_APB1ENR_TIM2EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_TIM3EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_TIM4EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_TIM5EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_TIM6EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_TIM7EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_TIM12EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_TIM13EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_TIM14EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_WWDGEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_SPI2EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_SPI3EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_USART2EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_USART3EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_UART4EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_UART5EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_I2C1EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_I2C2EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_I2C3EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_CAN1EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_CAN2EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_PWREN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1ENR_DACEN, EnableFlag());
	MOCK_METHOD1(set_APB1ENR_TIM2EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_TIM3EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_TIM4EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_TIM5EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_TIM6EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_TIM7EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_TIM12EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_TIM13EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_TIM14EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_WWDGEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_SPI2EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_SPI3EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_USART2EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_USART3EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_UART4EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_UART5EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_I2C1EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_I2C2EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_I2C3EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_CAN1EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_CAN2EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_PWREN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1ENR_DACEN, void(EnableFlag value));

	// APB2ENR Fields
	MOCK_CONST_METHOD0(get_APB2ENR_TIM1EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_TIM8EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_USART1EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_USART6EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_ADC1EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_ADC2EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_ADC3EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_SDIOEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_SPI1EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_SYSCFGEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_TIM9EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_TIM10EN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2ENR_TIM11EN, EnableFlag());
	MOCK_METHOD1(set_APB2ENR_TIM1EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_TIM8EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_USART1EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_USART6EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_ADC1EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_ADC2EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_ADC3EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_SDIOEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_SPI1EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_SYSCFGEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_TIM9EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_TIM10EN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2ENR_TIM11EN, void(EnableFlag value));

	// AHB1LPENR Fields
	MOCK_CONST_METHOD0(get_AHB1LPENR_GPIOALPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_GPIOBLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_GPIOCLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_GPIODLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_GPIOELPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_GPIOFLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_GPIOGLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_GPIOHLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_GPIOILPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_CRCLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_FLITFLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_SRAM1LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_SRAM2LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_BKPSRAMLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_DMA1LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_DMA2LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_ETHMACLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_ETHMACTXLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_ETHMACRXLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_ETHMACPTPLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_OTGHSLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB1LPENR_OTGHSULPILPEN, EnableFlag());
	MOCK_METHOD1(set_AHB1LPENR_GPIOALPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_GPIOBLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_GPIOCLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_GPIODLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_GPIOELPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_GPIOFLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_GPIOGLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_GPIOHLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_GPIOILPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_CRCLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_FLITFLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_SRAM1LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_SRAM2LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_BKPSRAMLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_DMA1LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_DMA2LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_ETHMACLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_ETHMACTXLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_ETHMACRXLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_ETHMACPTPLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_OTGHSLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB1LPENR_OTGHSULPILPEN, void(EnableFlag value));

	// AHB2LPENR Fields
	MOCK_CONST_METHOD0(get_AHB2LPENR_DCMILPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB2LPENR_CRYPLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB2LPENR_HASHLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB2LPENR_RNGLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_AHB2LPENR_OTGFSLPEN, EnableFlag());
	MOCK_METHOD1(set_AHB2LPENR_DCMILPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB2LPENR_CRYPLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB2LPENR_HASHLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB2LPENR_RNGLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_AHB2LPENR_OTGFSLPEN, void(EnableFlag value));

	// AHB3LPENR Fields
	MOCK_CONST_METHOD0(get_AHB3LPENR_FSMCLPEN, EnableFlag());
	MOCK_METHOD1(set_AHB3LPENR_FSMCLPEN, void(EnableFlag value));

	// APB1LPENR Fields
	MOCK_CONST_METHOD0(get_APB1LPENR_TIM2LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_TIM3LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_TIM4LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_TIM5LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_TIM6LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_TIM7LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_TIM12LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_TIM13LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_TIM14LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_WWDGLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_SPI2LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_SPI3LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_USART2LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_USART3LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_UART4LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_UART5LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_I2C1LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_I2C2LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_I2C3LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_CAN1LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_CAN2LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_PWRLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB1LPENR_DACLPEN, EnableFlag());
	MOCK_METHOD1(set_APB1LPENR_TIM2LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_TIM3LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_TIM4LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_TIM5LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_TIM6LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_TIM7LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_TIM12LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_TIM13LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_TIM14LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_WWDGLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_SPI2LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_SPI3LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_USART2LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_USART3LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_UART4LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_UART5LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_I2C1LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_I2C2LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_I2C3LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_CAN1LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_CAN2LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_PWRLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB1LPENR_DACLPEN, void(EnableFlag value));

	// APB2LPENR Fields
	MOCK_CONST_METHOD0(get_APB2LPENR_TIM1LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_TIM8LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_USART1LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_USART6LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_ADC1LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_ADC2LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_ADC3LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_SDIOLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_SPI1LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_SYSCFGLPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_TIM9LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_TIM10LPEN, EnableFlag());
	MOCK_CONST_METHOD0(get_APB2LPENR_TIM11LPEN, EnableFlag());
	MOCK_METHOD1(set_APB2LPENR_TIM1LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_TIM8LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_USART1LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_USART6LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_ADC1LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_ADC2LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_ADC3LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_SDIOLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_SPI1LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_SYSCFGLPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_TIM9LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_TIM10LPEN, void(EnableFlag value));
	MOCK_METHOD1(set_APB2LPENR_TIM11LPEN, void(EnableFlag value));

	// BDCR Fields
	MOCK_CONST_METHOD0(get_BDCR_LSEON, EnableFlag());
	MOCK_CONST_METHOD0(get_BDCR_LSERDY, ReadyFlag());
	MOCK_CONST_METHOD0(get_BDCR_LSEBYP, ExternalLowSpeedOscillatorBypass());
	MOCK_CONST_METHOD0(get_BDCR_RTCSEL, RtcClockSourceSelection());
	MOCK_CONST_METHOD0(get_BDCR_RTCEN, EnableFlag());
	MOCK_CONST_METHOD0(get_BDCR_BDRST, ResetFlag());
	MOCK_METHOD1(set_BDCR_LSEON, void(EnableFlag value));
	MOCK_METHOD1(set_BDCR_LSEBYP, void(ExternalLowSpeedOscillatorBypass value));
	MOCK_METHOD1(set_BDCR_RTCSEL, void(RtcClockSourceSelection value));
	MOCK_METHOD1(set_BDCR_RTCEN, void(EnableFlag value));
	MOCK_METHOD1(set_BDCR_BDRST, void(ResetFlag value));

	// CSR Fields
	MOCK_CONST_METHOD0(get_CSR_LSION, EnableFlag());
	MOCK_CONST_METHOD0(get_CSR_LSIRDY, ReadyFlag());
	MOCK_CONST_METHOD0(get_CSR_RMVF, ClearFlag());
	MOCK_CONST_METHOD0(get_CSR_BORRSTF, ResetOccurredFlag());
	MOCK_CONST_METHOD0(get_CSR_PINRSTF, ResetOccurredFlag());
	MOCK_CONST_METHOD0(get_CSR_PORRSTF, ResetOccurredFlag());
	MOCK_CONST_METHOD0(get_CSR_SFTRSTF, ResetOccurredFlag());
	MOCK_CONST_METHOD0(get_CSR_IWDGRSTF, ResetOccurredFlag());
	MOCK_CONST_METHOD0(get_CSR_WWDGRSTF, ResetOccurredFlag());
	MOCK_CONST_METHOD0(get_CSR_LPWRRSTF, ResetOccurredFlag());
	MOCK_METHOD1(set_CSR_LSION, void(EnableFlag value));
	MOCK_METHOD1(set_CSR_RMVF, void(ClearFlag value));

	// SSCGR Fields
	MOCK_CONST_METHOD0(get_SSCGR_MODPER, uint32_t());
	MOCK_CONST_METHOD0(get_SSCGR_INCSTEP, uint32_t());
	MOCK_CONST_METHOD0(get_SSCGR_SPREADSEL, SpreadSelect());
	MOCK_CONST_METHOD0(get_SSCGR_SSCGEN, EnableFlag());
	MOCK_METHOD1(set_SSCGR_MODPER, void(uint32_t value));
	MOCK_METHOD1(set_SSCGR_INCSTEP, void(uint32_t value));
	MOCK_METHOD1(set_SSCGR_SPREADSEL, void(SpreadSelect value));
	MOCK_METHOD1(set_SSCGR_SSCGEN, void(EnableFlag value));

	// PLLI2SCFGR Fields
	MOCK_CONST_METHOD0(get_PLLI2SCFGR_PLLI2SN, uint32_t());
	MOCK_CONST_METHOD0(get_PLLI2SCFGR_PLLI2SR, uint32_t());
	MOCK_METHOD1(set_PLLI2SCFGR_PLLI2SN, void(uint32_t value));
	MOCK_METHOD1(set_PLLI2SCFGR_PLLI2SR, void(uint32_t value));
};

