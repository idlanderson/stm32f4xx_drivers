#ifndef RCC_REGISTER_MAP_HPP_
#define RCC_REGISTER_MAP_HPP_

#include <cstdint>
#include "rcc_types.hpp"

using namespace std;

namespace stm32::rcc
{
	union CR_t
	{
		volatile struct
		{
			EnableFlag     HSION       : 1; // [0]     rw : Internal high-speed clock enable
			ReadyFlag      HSIRDY      : 1; // [1]     r  : Internal high-speed clock ready flag
			Reserved       Reserved1   : 1; // [2]        : RESERVED FIELD.
			uint32_t       HSITRIM     : 5; // [3:7]   rw : Internal high-speed clock trimming
			uint32_t       HSICAL      : 8; // [8:15]  r  : Internal high-speed clock calibration
			EnableFlag     HSEON       : 1; // [16]    rw : HSE clock enable
			ReadyFlag      HSERDY      : 1; // [17]    r  : HSE clock ready flag
			HseClockBypass HSEBYP      : 1; // [18]    rw : HSE clock bypass
			EnableFlag     CSSON       : 1; // [19]    rw : Clock security system enable
			Reserved       Reserved2   : 4; // [20:23]    : RESERVED FIELD.
			EnableFlag     PLLON       : 1; // [24]    rw : Main PLL (PLL) enable
			ReadyFlag      PLLRDY      : 1; // [25]    r  : Main PLL (PLL) clock ready flag
			EnableFlag     PLLI2SON    : 1; // [26]    rw : PLLI2S enable
			ReadyFlag      PLLI2SRDY   : 1; // [27]    r  : PLLI2S clock ready flag
			Reserved       Reserved3   : 4; // [28:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union PLLCFGR_t
	{
		volatile struct
		{
			uint32_t                           PLLM        : 6; // [0:5]   rw : Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
			uint32_t                           PLLN        : 9; // [6:14]  rw : Main PLL (PLL) multiplication factor for VCO
			Reserved                           Reserved1   : 1; // [15]       : RESERVED FIELD.
			MainPllDivisionFactor              PLLP        : 2; // [16:17] rw : Main PLL (PLL) division factor for main system clock
			Reserved                           Reserved2   : 4; // [18:21]    : RESERVED FIELD.
			MainPllAndAudioPllEntryClockSource PLLSRC      : 1; // [22]    rw : Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
			Reserved                           Reserved3   : 1; // [23]       : RESERVED FIELD.
			uint32_t                           PLLQ        : 4; // [24:27] rw : Main PLL (PLL) division factor for USB OTG FS SDIO and random number generator clocks
			Reserved                           Reserved4   : 4; // [28:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CFGR_t
	{
		volatile struct
		{
			SystemClock                 SW          : 2; // [0:1]   rw : System clock switch
			SystemClock                 SWS         : 2; // [2:3]   r  : System clock switch status
			AhbPrescaler                HPRE        : 4; // [4:7]   rw : AHB prescaler
			Reserved                    Reserved1   : 2; // [8:9]      : RESERVED FIELD.
			ApbPrescaler                PPRE1       : 3; // [10:12] rw : APB Low speed prescaler (APB1)
			ApbPrescaler                PPRE2       : 3; // [13:15] rw : APB high-speed prescaler (APB2)
			uint32_t                    RTCPRE      : 5; // [16:20] rw : HSE division factor for RTC clock
			MicrocontrollerClockOutput1 MCO1        : 2; // [21:22] rw : Microcontroller clock output 1
			I2SClockSelection           I2SSCR      : 1; // [23]    rw : I2S clock selection
			McoPrescaler                MCO1PRE     : 3; // [24:26] rw : MCO1 prescaler
			McoPrescaler                MCO2PRE     : 3; // [27:29] rw : MCO2 prescaler
			MicrocontrollerClockOutput2 MCO2        : 2; // [30:31] rw : Microcontroller clock output 2
		} Fields;
		volatile uint32_t Value;
	};

	union CIR_t
	{
		volatile struct
		{
			ReadyFlag                        LSIRDYF     : 1; // [0]     r  : 
			ReadyFlag                        LSERDYF     : 1; // [1]     r  : 
			ReadyFlag                        HSIRDYF     : 1; // [2]     r  : 
			ReadyFlag                        HSERDYF     : 1; // [3]     r  : 
			ReadyFlag                        PLLRDYF     : 1; // [4]     r  : 
			ReadyFlag                        PLLI2SRDYF  : 1; // [5]     r  : 
			Reserved                         Reserved1   : 1; // [6]        : RESERVED FIELD.
			ClockSecuritySystemInterruptFlag CSSF        : 1; // [7]     r  : 
			EnableFlag                       LSIRDYIE    : 1; // [8]     rw : 
			EnableFlag                       LSERDYIE    : 1; // [9]     rw : 
			EnableFlag                       HSIRDYIE    : 1; // [10]    rw : 
			EnableFlag                       HSERDYIE    : 1; // [11]    rw : 
			EnableFlag                       PLLRDYIE    : 1; // [12]    rw : 
			EnableFlag                       PLLI2SRDYIE : 1; // [13]    rw : 
			Reserved                         Reserved2   : 2; // [14:15]    : RESERVED FIELD.
			ClearFlag                        LSIRDYC     : 1; // [16]    w  : 
			ClearFlag                        LSERDYC     : 1; // [17]    w  : 
			ClearFlag                        HSIRDYC     : 1; // [18]    w  : 
			ClearFlag                        HSERDYC     : 1; // [19]    w  : 
			ClearFlag                        PLLRDYC     : 1; // [20]    w  : 
			ClearFlag                        PLLI2SRDYC  : 1; // [21]    w  : 
			Reserved                         Reserved3   : 1; // [22]       : RESERVED FIELD.
			ClearFlag                        CSSC        : 1; // [23]    w  : 
			Reserved                         Reserved4   : 8; // [24:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AHB1RSTR_t
	{
		volatile struct
		{
			ResetFlag GPIOARST    : 1; // [0]     rw : 
			ResetFlag GPIOBRST    : 1; // [1]     rw : 
			ResetFlag GPIOCRST    : 1; // [2]     rw : 
			ResetFlag GPIODRST    : 1; // [3]     rw : 
			ResetFlag GPIOERST    : 1; // [4]     rw : 
			ResetFlag GPIOFRST    : 1; // [5]     rw : 
			ResetFlag GPIOGRST    : 1; // [6]     rw : 
			ResetFlag GPIOHRST    : 1; // [7]     rw : 
			ResetFlag GPIOIRST    : 1; // [8]     rw : 
			Reserved  Reserved1   : 3; // [9:11]     : RESERVED FIELD.
			ResetFlag CRCRST      : 1; // [12]    rw : 
			Reserved  Reserved2   : 8; // [13:20]    : RESERVED FIELD.
			ResetFlag DMA1RST     : 1; // [21]    rw : 
			ResetFlag DMA2RST     : 1; // [22]    rw : 
			Reserved  Reserved3   : 2; // [23:24]    : RESERVED FIELD.
			ResetFlag ETHMACRST   : 1; // [25]    rw : 
			Reserved  Reserved4   : 3; // [26:28]    : RESERVED FIELD.
			ResetFlag OTGHSRST    : 1; // [29]    rw : 
			Reserved  Reserved5   : 2; // [30:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AHB2RSTR_t
	{
		volatile struct
		{
			ResetFlag DCMIRST     : 1; // [0]     rw : 
			Reserved  Reserved1   : 3; // [1:3]      : RESERVED FIELD.
			ResetFlag CRYPRST     : 1; // [4]     rw : 
			ResetFlag HASHRST     : 1; // [5]     rw : 
			ResetFlag RNGRST      : 1; // [6]     rw : 
			ResetFlag OTGFSRST    : 1; // [7]     rw : 
			Reserved  Reserved2   : 24; // [8:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AHB3RSTR_t
	{
		volatile struct
		{
			ResetFlag FSMCRST     : 1; // [0]     rw : 
			Reserved  Reserved1   : 31; // [1:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union APB1RSTR_t
	{
		volatile struct
		{
			ResetFlag TIM2RST     : 1; // [0]     rw : 
			ResetFlag TIM3RST     : 1; // [1]     rw : 
			ResetFlag TIM4RST     : 1; // [2]     rw : 
			ResetFlag TIM5RST     : 1; // [3]     rw : 
			ResetFlag TIM6RST     : 1; // [4]     rw : 
			ResetFlag TIM7RST     : 1; // [5]     rw : 
			ResetFlag TIM12RST    : 1; // [6]     rw : 
			ResetFlag TIM13RST    : 1; // [7]     rw : 
			ResetFlag TIM14RST    : 1; // [8]     rw : 
			Reserved  Reserved1   : 2; // [9:10]     : RESERVED FIELD.
			ResetFlag WWDGRST     : 1; // [11]    rw : 
			Reserved  Reserved2   : 2; // [12:13]    : RESERVED FIELD.
			ResetFlag SPI2RST     : 1; // [14]    rw : 
			ResetFlag SPI3RST     : 1; // [15]    rw : 
			Reserved  Reserved3   : 1; // [16]       : RESERVED FIELD.
			ResetFlag UART2RST    : 1; // [17]    rw : 
			ResetFlag UART3RST    : 1; // [18]    rw : 
			ResetFlag UART4RST    : 1; // [19]    rw : 
			ResetFlag UART5RST    : 1; // [20]    rw : 
			ResetFlag I2C1RST     : 1; // [21]    rw : 
			ResetFlag I2C2RST     : 1; // [22]    rw : 
			ResetFlag I2C3RST     : 1; // [23]    rw : 
			Reserved  Reserved4   : 1; // [24]       : RESERVED FIELD.
			ResetFlag CAN1RST     : 1; // [25]    rw : 
			ResetFlag CAN2RST     : 1; // [26]    rw : 
			Reserved  Reserved5   : 1; // [27]       : RESERVED FIELD.
			ResetFlag PWRRST      : 1; // [28]    rw : 
			ResetFlag DACRST      : 1; // [29]    rw : 
			Reserved  Reserved6   : 2; // [30:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union APB2RSTR_t
	{
		volatile struct
		{
			ResetFlag TIM1RST     : 1; // [0]     rw : 
			ResetFlag TIM8RST     : 1; // [1]     rw : 
			Reserved  Reserved1   : 2; // [2:3]      : RESERVED FIELD.
			ResetFlag USART1RST   : 1; // [4]     rw : 
			ResetFlag USART6RST   : 1; // [5]     rw : 
			Reserved  Reserved2   : 2; // [6:7]      : RESERVED FIELD.
			ResetFlag ADCRST      : 1; // [8]     rw : 
			Reserved  Reserved3   : 2; // [9:10]     : RESERVED FIELD.
			ResetFlag SDIORST     : 1; // [11]    rw : 
			ResetFlag SPI1RST     : 1; // [12]    rw : 
			Reserved  Reserved4   : 1; // [13]       : RESERVED FIELD.
			ResetFlag SYSCFGRST   : 1; // [14]    rw : 
			Reserved  Reserved5   : 1; // [15]       : RESERVED FIELD.
			ResetFlag TIM9RST     : 1; // [16]    rw : 
			ResetFlag TIM10RST    : 1; // [17]    rw : 
			ResetFlag TIM11RST    : 1; // [18]    rw : 
			Reserved  Reserved6   : 13; // [19:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AHB1ENR_t
	{
		volatile struct
		{
			EnableFlag GPIOAEN     : 1; // [0]     rw : 
			EnableFlag GPIOBEN     : 1; // [1]     rw : 
			EnableFlag GPIOCEN     : 1; // [2]     rw : 
			EnableFlag GPIODEN     : 1; // [3]     rw : 
			EnableFlag GPIOEEN     : 1; // [4]     rw : 
			EnableFlag GPIOFEN     : 1; // [5]     rw : 
			EnableFlag GPIOGEN     : 1; // [6]     rw : 
			EnableFlag GPIOHEN     : 1; // [7]     rw : 
			EnableFlag GPIOIEN     : 1; // [8]     rw : 
			Reserved   Reserved1   : 3; // [9:11]     : RESERVED FIELD.
			EnableFlag CRCEN       : 1; // [12]    rw : 
			Reserved   Reserved2   : 5; // [13:17]    : RESERVED FIELD.
			EnableFlag BKPSRAMEN   : 1; // [18]    rw : 
			Reserved   Reserved3   : 1; // [19]       : RESERVED FIELD.
			EnableFlag CCMDATARAMEN : 1; // [20]    rw : 
			EnableFlag DMA1EN      : 1; // [21]    rw : 
			EnableFlag DMA2EN      : 1; // [22]    rw : 
			Reserved   Reserved4   : 2; // [23:24]    : RESERVED FIELD.
			EnableFlag ETHMACEN    : 1; // [25]    rw : 
			EnableFlag ETHMACTXEN  : 1; // [26]    rw : 
			EnableFlag ETHMACRXEN  : 1; // [27]    rw : 
			EnableFlag ETHMACPTPEN : 1; // [28]    rw : 
			EnableFlag OTGHSEN     : 1; // [29]    rw : 
			EnableFlag OTGHSULPIEN : 1; // [30]    rw : 
			Reserved   Reserved5   : 1; // [31]       : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AHB2ENR_t
	{
		volatile struct
		{
			EnableFlag DCMIEN      : 1; // [0]     rw : 
			Reserved   Reserved1   : 3; // [1:3]      : RESERVED FIELD.
			EnableFlag CRYPEN      : 1; // [4]     rw : 
			EnableFlag HASHEN      : 1; // [5]     rw : 
			EnableFlag RNGEN       : 1; // [6]     rw : 
			EnableFlag OTGFSEN     : 1; // [7]     rw : 
			Reserved   Reserved2   : 24; // [8:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AHB3ENR_t
	{
		volatile struct
		{
			EnableFlag FSMCEN      : 1; // [0]     rw : 
			Reserved   Reserved1   : 31; // [1:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union APB1ENR_t
	{
		volatile struct
		{
			EnableFlag TIM2EN      : 1; // [0]     rw : 
			EnableFlag TIM3EN      : 1; // [1]     rw : 
			EnableFlag TIM4EN      : 1; // [2]     rw : 
			EnableFlag TIM5EN      : 1; // [3]     rw : 
			EnableFlag TIM6EN      : 1; // [4]     rw : 
			EnableFlag TIM7EN      : 1; // [5]     rw : 
			EnableFlag TIM12EN     : 1; // [6]     rw : 
			EnableFlag TIM13EN     : 1; // [7]     rw : 
			EnableFlag TIM14EN     : 1; // [8]     rw : 
			Reserved   Reserved1   : 2; // [9:10]     : RESERVED FIELD.
			EnableFlag WWDGEN      : 1; // [11]    rw : 
			Reserved   Reserved2   : 2; // [12:13]    : RESERVED FIELD.
			EnableFlag SPI2EN      : 1; // [14]    rw : 
			EnableFlag SPI3EN      : 1; // [15]    rw : 
			Reserved   Reserved3   : 1; // [16]       : RESERVED FIELD.
			EnableFlag USART2EN    : 1; // [17]    rw : 
			EnableFlag USART3EN    : 1; // [18]    rw : 
			EnableFlag UART4EN     : 1; // [19]    rw : 
			EnableFlag UART5EN     : 1; // [20]    rw : 
			EnableFlag I2C1EN      : 1; // [21]    rw : 
			EnableFlag I2C2EN      : 1; // [22]    rw : 
			EnableFlag I2C3EN      : 1; // [23]    rw : 
			Reserved   Reserved4   : 1; // [24]       : RESERVED FIELD.
			EnableFlag CAN1EN      : 1; // [25]    rw : 
			EnableFlag CAN2EN      : 1; // [26]    rw : 
			Reserved   Reserved5   : 1; // [27]       : RESERVED FIELD.
			EnableFlag PWREN       : 1; // [28]    rw : 
			EnableFlag DACEN       : 1; // [29]    rw : 
			Reserved   Reserved6   : 2; // [30:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union APB2ENR_t
	{
		volatile struct
		{
			EnableFlag TIM1EN      : 1; // [0]     rw : 
			EnableFlag TIM8EN      : 1; // [1]     rw : 
			Reserved   Reserved1   : 2; // [2:3]      : RESERVED FIELD.
			EnableFlag USART1EN    : 1; // [4]     rw : 
			EnableFlag USART6EN    : 1; // [5]     rw : 
			Reserved   Reserved2   : 2; // [6:7]      : RESERVED FIELD.
			EnableFlag ADC1EN      : 1; // [8]     rw : 
			EnableFlag ADC2EN      : 1; // [9]     rw : 
			EnableFlag ADC3EN      : 1; // [10]    rw : 
			EnableFlag SDIOEN      : 1; // [11]    rw : 
			EnableFlag SPI1EN      : 1; // [12]    rw : 
			Reserved   Reserved3   : 1; // [13]       : RESERVED FIELD.
			EnableFlag SYSCFGEN    : 1; // [14]    rw : 
			Reserved   Reserved4   : 1; // [15]       : RESERVED FIELD.
			EnableFlag TIM9EN      : 1; // [16]    rw : 
			EnableFlag TIM10EN     : 1; // [17]    rw : 
			EnableFlag TIM11EN     : 1; // [18]    rw : 
			Reserved   Reserved5   : 13; // [19:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AHB1LPENR_t
	{
		volatile struct
		{
			EnableFlag GPIOALPEN   : 1; // [0]     rw : 
			EnableFlag GPIOBLPEN   : 1; // [1]     rw : 
			EnableFlag GPIOCLPEN   : 1; // [2]     rw : 
			EnableFlag GPIODLPEN   : 1; // [3]     rw : 
			EnableFlag GPIOELPEN   : 1; // [4]     rw : 
			EnableFlag GPIOFLPEN   : 1; // [5]     rw : 
			EnableFlag GPIOGLPEN   : 1; // [6]     rw : 
			EnableFlag GPIOHLPEN   : 1; // [7]     rw : 
			EnableFlag GPIOILPEN   : 1; // [8]     rw : 
			Reserved   Reserved1   : 3; // [9:11]     : RESERVED FIELD.
			EnableFlag CRCLPEN     : 1; // [12]    rw : 
			Reserved   Reserved2   : 2; // [13:14]    : RESERVED FIELD.
			EnableFlag FLITFLPEN   : 1; // [15]    rw : 
			EnableFlag SRAM1LPEN   : 1; // [16]    rw : 
			EnableFlag SRAM2LPEN   : 1; // [17]    rw : 
			EnableFlag BKPSRAMLPEN : 1; // [18]    rw : 
			Reserved   Reserved3   : 2; // [19:20]    : RESERVED FIELD.
			EnableFlag DMA1LPEN    : 1; // [21]    rw : 
			EnableFlag DMA2LPEN    : 1; // [22]    rw : 
			Reserved   Reserved4   : 2; // [23:24]    : RESERVED FIELD.
			EnableFlag ETHMACLPEN  : 1; // [25]    rw : 
			EnableFlag ETHMACTXLPEN : 1; // [26]    rw : 
			EnableFlag ETHMACRXLPEN : 1; // [27]    rw : 
			EnableFlag ETHMACPTPLPEN : 1; // [28]    rw : 
			EnableFlag OTGHSLPEN   : 1; // [29]    rw : 
			EnableFlag OTGHSULPILPEN : 1; // [30]    rw : 
			Reserved   Reserved5   : 1; // [31]       : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AHB2LPENR_t
	{
		volatile struct
		{
			EnableFlag DCMILPEN    : 1; // [0]     rw : 
			Reserved   Reserved1   : 3; // [1:3]      : RESERVED FIELD.
			EnableFlag CRYPLPEN    : 1; // [4]     rw : 
			EnableFlag HASHLPEN    : 1; // [5]     rw : 
			EnableFlag RNGLPEN     : 1; // [6]     rw : 
			EnableFlag OTGFSLPEN   : 1; // [7]     rw : 
			Reserved   Reserved2   : 24; // [8:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AHB3LPENR_t
	{
		volatile struct
		{
			EnableFlag FSMCLPEN    : 1; // [0]     rw : 
			Reserved   Reserved1   : 31; // [1:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union APB1LPENR_t
	{
		volatile struct
		{
			EnableFlag TIM2LPEN    : 1; // [0]     rw : 
			EnableFlag TIM3LPEN    : 1; // [1]     rw : 
			EnableFlag TIM4LPEN    : 1; // [2]     rw : 
			EnableFlag TIM5LPEN    : 1; // [3]     rw : 
			EnableFlag TIM6LPEN    : 1; // [4]     rw : 
			EnableFlag TIM7LPEN    : 1; // [5]     rw : 
			EnableFlag TIM12LPEN   : 1; // [6]     rw : 
			EnableFlag TIM13LPEN   : 1; // [7]     rw : 
			EnableFlag TIM14LPEN   : 1; // [8]     rw : 
			Reserved   Reserved1   : 2; // [9:10]     : RESERVED FIELD.
			EnableFlag WWDGLPEN    : 1; // [11]    rw : 
			Reserved   Reserved2   : 2; // [12:13]    : RESERVED FIELD.
			EnableFlag SPI2LPEN    : 1; // [14]    rw : 
			EnableFlag SPI3LPEN    : 1; // [15]    rw : 
			Reserved   Reserved3   : 1; // [16]       : RESERVED FIELD.
			EnableFlag USART2LPEN  : 1; // [17]    rw : 
			EnableFlag USART3LPEN  : 1; // [18]    rw : 
			EnableFlag UART4LPEN   : 1; // [19]    rw : 
			EnableFlag UART5LPEN   : 1; // [20]    rw : 
			EnableFlag I2C1LPEN    : 1; // [21]    rw : 
			EnableFlag I2C2LPEN    : 1; // [22]    rw : 
			EnableFlag I2C3LPEN    : 1; // [23]    rw : 
			Reserved   Reserved4   : 1; // [24]       : RESERVED FIELD.
			EnableFlag CAN1LPEN    : 1; // [25]    rw : 
			EnableFlag CAN2LPEN    : 1; // [26]    rw : 
			Reserved   Reserved5   : 1; // [27]       : RESERVED FIELD.
			EnableFlag PWRLPEN     : 1; // [28]    rw : 
			EnableFlag DACLPEN     : 1; // [29]    rw : 
			Reserved   Reserved6   : 2; // [30:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union APB2LPENR_t
	{
		volatile struct
		{
			EnableFlag TIM1LPEN    : 1; // [0]     rw : 
			EnableFlag TIM8LPEN    : 1; // [1]     rw : 
			Reserved   Reserved1   : 2; // [2:3]      : RESERVED FIELD.
			EnableFlag USART1LPEN  : 1; // [4]     rw : 
			EnableFlag USART6LPEN  : 1; // [5]     rw : 
			Reserved   Reserved2   : 2; // [6:7]      : RESERVED FIELD.
			EnableFlag ADC1LPEN    : 1; // [8]     rw : 
			EnableFlag ADC2LPEN    : 1; // [9]     rw : 
			EnableFlag ADC3LPEN    : 1; // [10]    rw : 
			EnableFlag SDIOLPEN    : 1; // [11]    rw : 
			EnableFlag SPI1LPEN    : 1; // [12]    rw : 
			Reserved   Reserved3   : 1; // [13]       : RESERVED FIELD.
			EnableFlag SYSCFGLPEN  : 1; // [14]    rw : 
			Reserved   Reserved4   : 1; // [15]       : RESERVED FIELD.
			EnableFlag TIM9LPEN    : 1; // [16]    rw : 
			EnableFlag TIM10LPEN   : 1; // [17]    rw : 
			EnableFlag TIM11LPEN   : 1; // [18]    rw : 
			Reserved   Reserved5   : 13; // [19:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union BDCR_t
	{
		volatile struct
		{
			EnableFlag                       LSEON       : 1; // [0]     rw : 
			ReadyFlag                        LSERDY      : 1; // [1]     r  : 
			ExternalLowSpeedOscillatorBypass LSEBYP      : 1; // [2]     rw : 
			Reserved                         Reserved1   : 5; // [3:7]      : RESERVED FIELD.
			RtcClockSourceSelection          RTCSEL      : 2; // [8:9]   rw : 
			Reserved                         Reserved2   : 5; // [10:14]    : RESERVED FIELD.
			EnableFlag                       RTCEN       : 1; // [15]    rw : 
			ResetFlag                        BDRST       : 1; // [16]    rw : 
			Reserved                         Reserved3   : 15; // [17:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CSR_t
	{
		volatile struct
		{
			EnableFlag        LSION       : 1; // [0]     rw : 
			ReadyFlag         LSIRDY      : 1; // [1]     r  : 
			Reserved          Reserved1   : 22; // [2:23]     : RESERVED FIELD.
			ClearFlag         RMVF        : 1; // [24]    rw : 
			ResetOccurredFlag BORRSTF     : 1; // [25]    r  : 
			ResetOccurredFlag PINRSTF     : 1; // [26]    r  : 
			ResetOccurredFlag PORRSTF     : 1; // [27]    r  : 
			ResetOccurredFlag SFTRSTF     : 1; // [28]    r  : 
			ResetOccurredFlag IWDGRSTF    : 1; // [29]    r  : 
			ResetOccurredFlag WWDGRSTF    : 1; // [30]    r  : 
			ResetOccurredFlag LPWRRSTF    : 1; // [31]    r  : 
		} Fields;
		volatile uint32_t Value;
	};

	union SSCGR_t
	{
		volatile struct
		{
			uint32_t     MODPER      : 13; // [0:12]  rw : Modulation period
			uint32_t     INCSTEP     : 15; // [13:27] rw : Incrementation step
			Reserved     Reserved1   : 2; // [28:29]    : RESERVED FIELD.
			SpreadSelect SPREADSEL   : 1; // [30]    rw : Spread Select
			EnableFlag   SSCGEN      : 1; // [31]    rw : Spread spectrum modulation enable
		} Fields;
		volatile uint32_t Value;
	};

	union PLLI2SCFGR_t
	{
		volatile struct
		{
			Reserved Reserved1   : 6; // [0:5]      : RESERVED FIELD.
			uint32_t PLLI2SN     : 9; // [6:14]  rw : PLLI2S multiplication factor for VCO
			Reserved Reserved2   : 13; // [15:27]    : RESERVED FIELD.
			uint32_t PLLI2SR     : 3; // [28:30] rw : PLLI2S division factor for I2S clocks
			Reserved Reserved3   : 1; // [31]       : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	class RccRegisterMap
	{
	public:

		// CR Fields
		EnableFlag get_CR_HSION() const { return CR.Fields.HSION; }
		ReadyFlag get_CR_HSIRDY() const { return CR.Fields.HSIRDY; }
		uint32_t get_CR_HSITRIM() const { return CR.Fields.HSITRIM; }
		uint32_t get_CR_HSICAL() const { return CR.Fields.HSICAL; }
		EnableFlag get_CR_HSEON() const { return CR.Fields.HSEON; }
		ReadyFlag get_CR_HSERDY() const { return CR.Fields.HSERDY; }
		HseClockBypass get_CR_HSEBYP() const { return CR.Fields.HSEBYP; }
		EnableFlag get_CR_CSSON() const { return CR.Fields.CSSON; }
		EnableFlag get_CR_PLLON() const { return CR.Fields.PLLON; }
		ReadyFlag get_CR_PLLRDY() const { return CR.Fields.PLLRDY; }
		EnableFlag get_CR_PLLI2SON() const { return CR.Fields.PLLI2SON; }
		ReadyFlag get_CR_PLLI2SRDY() const { return CR.Fields.PLLI2SRDY; }
		void set_CR_HSION(EnableFlag value) { CR.Fields.HSION = value; }
		void set_CR_HSITRIM(uint32_t value) { CR.Fields.HSITRIM = value; }
		void set_CR_HSEON(EnableFlag value) { CR.Fields.HSEON = value; }
		void set_CR_HSEBYP(HseClockBypass value) { CR.Fields.HSEBYP = value; }
		void set_CR_CSSON(EnableFlag value) { CR.Fields.CSSON = value; }
		void set_CR_PLLON(EnableFlag value) { CR.Fields.PLLON = value; }
		void set_CR_PLLI2SON(EnableFlag value) { CR.Fields.PLLI2SON = value; }

		// PLLCFGR Fields
		uint32_t get_PLLCFGR_PLLM() const { return PLLCFGR.Fields.PLLM; }
		uint32_t get_PLLCFGR_PLLN() const { return PLLCFGR.Fields.PLLN; }
		MainPllDivisionFactor get_PLLCFGR_PLLP() const { return PLLCFGR.Fields.PLLP; }
		MainPllAndAudioPllEntryClockSource get_PLLCFGR_PLLSRC() const { return PLLCFGR.Fields.PLLSRC; }
		uint32_t get_PLLCFGR_PLLQ() const { return PLLCFGR.Fields.PLLQ; }
		void set_PLLCFGR_PLLM(uint32_t value) { PLLCFGR.Fields.PLLM = value; }
		void set_PLLCFGR_PLLN(uint32_t value) { PLLCFGR.Fields.PLLN = value; }
		void set_PLLCFGR_PLLP(MainPllDivisionFactor value) { PLLCFGR.Fields.PLLP = value; }
		void set_PLLCFGR_PLLSRC(MainPllAndAudioPllEntryClockSource value) { PLLCFGR.Fields.PLLSRC = value; }
		void set_PLLCFGR_PLLQ(uint32_t value) { PLLCFGR.Fields.PLLQ = value; }

		// CFGR Fields
		SystemClock get_CFGR_SW() const { return CFGR.Fields.SW; }
		SystemClock get_CFGR_SWS() const { return CFGR.Fields.SWS; }
		AhbPrescaler get_CFGR_HPRE() const { return CFGR.Fields.HPRE; }
		ApbPrescaler get_CFGR_PPRE1() const { return CFGR.Fields.PPRE1; }
		ApbPrescaler get_CFGR_PPRE2() const { return CFGR.Fields.PPRE2; }
		uint32_t get_CFGR_RTCPRE() const { return CFGR.Fields.RTCPRE; }
		MicrocontrollerClockOutput1 get_CFGR_MCO1() const { return CFGR.Fields.MCO1; }
		I2SClockSelection get_CFGR_I2SSCR() const { return CFGR.Fields.I2SSCR; }
		McoPrescaler get_CFGR_MCO1PRE() const { return CFGR.Fields.MCO1PRE; }
		McoPrescaler get_CFGR_MCO2PRE() const { return CFGR.Fields.MCO2PRE; }
		MicrocontrollerClockOutput2 get_CFGR_MCO2() const { return CFGR.Fields.MCO2; }
		void set_CFGR_SW(SystemClock value) { CFGR.Fields.SW = value; }
		void set_CFGR_HPRE(AhbPrescaler value) { CFGR.Fields.HPRE = value; }
		void set_CFGR_PPRE1(ApbPrescaler value) { CFGR.Fields.PPRE1 = value; }
		void set_CFGR_PPRE2(ApbPrescaler value) { CFGR.Fields.PPRE2 = value; }
		void set_CFGR_RTCPRE(uint32_t value) { CFGR.Fields.RTCPRE = value; }
		void set_CFGR_MCO1(MicrocontrollerClockOutput1 value) { CFGR.Fields.MCO1 = value; }
		void set_CFGR_I2SSCR(I2SClockSelection value) { CFGR.Fields.I2SSCR = value; }
		void set_CFGR_MCO1PRE(McoPrescaler value) { CFGR.Fields.MCO1PRE = value; }
		void set_CFGR_MCO2PRE(McoPrescaler value) { CFGR.Fields.MCO2PRE = value; }
		void set_CFGR_MCO2(MicrocontrollerClockOutput2 value) { CFGR.Fields.MCO2 = value; }

		// CIR Fields
		ReadyFlag get_CIR_LSIRDYF() const { return CIR.Fields.LSIRDYF; }
		ReadyFlag get_CIR_LSERDYF() const { return CIR.Fields.LSERDYF; }
		ReadyFlag get_CIR_HSIRDYF() const { return CIR.Fields.HSIRDYF; }
		ReadyFlag get_CIR_HSERDYF() const { return CIR.Fields.HSERDYF; }
		ReadyFlag get_CIR_PLLRDYF() const { return CIR.Fields.PLLRDYF; }
		ReadyFlag get_CIR_PLLI2SRDYF() const { return CIR.Fields.PLLI2SRDYF; }
		ClockSecuritySystemInterruptFlag get_CIR_CSSF() const { return CIR.Fields.CSSF; }
		EnableFlag get_CIR_LSIRDYIE() const { return CIR.Fields.LSIRDYIE; }
		EnableFlag get_CIR_LSERDYIE() const { return CIR.Fields.LSERDYIE; }
		EnableFlag get_CIR_HSIRDYIE() const { return CIR.Fields.HSIRDYIE; }
		EnableFlag get_CIR_HSERDYIE() const { return CIR.Fields.HSERDYIE; }
		EnableFlag get_CIR_PLLRDYIE() const { return CIR.Fields.PLLRDYIE; }
		EnableFlag get_CIR_PLLI2SRDYIE() const { return CIR.Fields.PLLI2SRDYIE; }
		void set_CIR_LSIRDYIE(EnableFlag value) { CIR.Fields.LSIRDYIE = value; }
		void set_CIR_LSERDYIE(EnableFlag value) { CIR.Fields.LSERDYIE = value; }
		void set_CIR_HSIRDYIE(EnableFlag value) { CIR.Fields.HSIRDYIE = value; }
		void set_CIR_HSERDYIE(EnableFlag value) { CIR.Fields.HSERDYIE = value; }
		void set_CIR_PLLRDYIE(EnableFlag value) { CIR.Fields.PLLRDYIE = value; }
		void set_CIR_PLLI2SRDYIE(EnableFlag value) { CIR.Fields.PLLI2SRDYIE = value; }
		void set_CIR_LSIRDYC(ClearFlag value) { CIR.Fields.LSIRDYC = value; }
		void set_CIR_LSERDYC(ClearFlag value) { CIR.Fields.LSERDYC = value; }
		void set_CIR_HSIRDYC(ClearFlag value) { CIR.Fields.HSIRDYC = value; }
		void set_CIR_HSERDYC(ClearFlag value) { CIR.Fields.HSERDYC = value; }
		void set_CIR_PLLRDYC(ClearFlag value) { CIR.Fields.PLLRDYC = value; }
		void set_CIR_PLLI2SRDYC(ClearFlag value) { CIR.Fields.PLLI2SRDYC = value; }
		void set_CIR_CSSC(ClearFlag value) { CIR.Fields.CSSC = value; }

		// AHB1RSTR Fields
		ResetFlag get_AHB1RSTR_GPIOARST() const { return AHB1RSTR.Fields.GPIOARST; }
		ResetFlag get_AHB1RSTR_GPIOBRST() const { return AHB1RSTR.Fields.GPIOBRST; }
		ResetFlag get_AHB1RSTR_GPIOCRST() const { return AHB1RSTR.Fields.GPIOCRST; }
		ResetFlag get_AHB1RSTR_GPIODRST() const { return AHB1RSTR.Fields.GPIODRST; }
		ResetFlag get_AHB1RSTR_GPIOERST() const { return AHB1RSTR.Fields.GPIOERST; }
		ResetFlag get_AHB1RSTR_GPIOFRST() const { return AHB1RSTR.Fields.GPIOFRST; }
		ResetFlag get_AHB1RSTR_GPIOGRST() const { return AHB1RSTR.Fields.GPIOGRST; }
		ResetFlag get_AHB1RSTR_GPIOHRST() const { return AHB1RSTR.Fields.GPIOHRST; }
		ResetFlag get_AHB1RSTR_GPIOIRST() const { return AHB1RSTR.Fields.GPIOIRST; }
		ResetFlag get_AHB1RSTR_CRCRST() const { return AHB1RSTR.Fields.CRCRST; }
		ResetFlag get_AHB1RSTR_DMA1RST() const { return AHB1RSTR.Fields.DMA1RST; }
		ResetFlag get_AHB1RSTR_DMA2RST() const { return AHB1RSTR.Fields.DMA2RST; }
		ResetFlag get_AHB1RSTR_ETHMACRST() const { return AHB1RSTR.Fields.ETHMACRST; }
		ResetFlag get_AHB1RSTR_OTGHSRST() const { return AHB1RSTR.Fields.OTGHSRST; }
		void set_AHB1RSTR_GPIOARST(ResetFlag value) { AHB1RSTR.Fields.GPIOARST = value; }
		void set_AHB1RSTR_GPIOBRST(ResetFlag value) { AHB1RSTR.Fields.GPIOBRST = value; }
		void set_AHB1RSTR_GPIOCRST(ResetFlag value) { AHB1RSTR.Fields.GPIOCRST = value; }
		void set_AHB1RSTR_GPIODRST(ResetFlag value) { AHB1RSTR.Fields.GPIODRST = value; }
		void set_AHB1RSTR_GPIOERST(ResetFlag value) { AHB1RSTR.Fields.GPIOERST = value; }
		void set_AHB1RSTR_GPIOFRST(ResetFlag value) { AHB1RSTR.Fields.GPIOFRST = value; }
		void set_AHB1RSTR_GPIOGRST(ResetFlag value) { AHB1RSTR.Fields.GPIOGRST = value; }
		void set_AHB1RSTR_GPIOHRST(ResetFlag value) { AHB1RSTR.Fields.GPIOHRST = value; }
		void set_AHB1RSTR_GPIOIRST(ResetFlag value) { AHB1RSTR.Fields.GPIOIRST = value; }
		void set_AHB1RSTR_CRCRST(ResetFlag value) { AHB1RSTR.Fields.CRCRST = value; }
		void set_AHB1RSTR_DMA1RST(ResetFlag value) { AHB1RSTR.Fields.DMA1RST = value; }
		void set_AHB1RSTR_DMA2RST(ResetFlag value) { AHB1RSTR.Fields.DMA2RST = value; }
		void set_AHB1RSTR_ETHMACRST(ResetFlag value) { AHB1RSTR.Fields.ETHMACRST = value; }
		void set_AHB1RSTR_OTGHSRST(ResetFlag value) { AHB1RSTR.Fields.OTGHSRST = value; }

		// AHB2RSTR Fields
		ResetFlag get_AHB2RSTR_DCMIRST() const { return AHB2RSTR.Fields.DCMIRST; }
		ResetFlag get_AHB2RSTR_CRYPRST() const { return AHB2RSTR.Fields.CRYPRST; }
		ResetFlag get_AHB2RSTR_HASHRST() const { return AHB2RSTR.Fields.HASHRST; }
		ResetFlag get_AHB2RSTR_RNGRST() const { return AHB2RSTR.Fields.RNGRST; }
		ResetFlag get_AHB2RSTR_OTGFSRST() const { return AHB2RSTR.Fields.OTGFSRST; }
		void set_AHB2RSTR_DCMIRST(ResetFlag value) { AHB2RSTR.Fields.DCMIRST = value; }
		void set_AHB2RSTR_CRYPRST(ResetFlag value) { AHB2RSTR.Fields.CRYPRST = value; }
		void set_AHB2RSTR_HASHRST(ResetFlag value) { AHB2RSTR.Fields.HASHRST = value; }
		void set_AHB2RSTR_RNGRST(ResetFlag value) { AHB2RSTR.Fields.RNGRST = value; }
		void set_AHB2RSTR_OTGFSRST(ResetFlag value) { AHB2RSTR.Fields.OTGFSRST = value; }

		// AHB3RSTR Fields
		ResetFlag get_AHB3RSTR_FSMCRST() const { return AHB3RSTR.Fields.FSMCRST; }
		void set_AHB3RSTR_FSMCRST(ResetFlag value) { AHB3RSTR.Fields.FSMCRST = value; }

		// APB1RSTR Fields
		ResetFlag get_APB1RSTR_TIM2RST() const { return APB1RSTR.Fields.TIM2RST; }
		ResetFlag get_APB1RSTR_TIM3RST() const { return APB1RSTR.Fields.TIM3RST; }
		ResetFlag get_APB1RSTR_TIM4RST() const { return APB1RSTR.Fields.TIM4RST; }
		ResetFlag get_APB1RSTR_TIM5RST() const { return APB1RSTR.Fields.TIM5RST; }
		ResetFlag get_APB1RSTR_TIM6RST() const { return APB1RSTR.Fields.TIM6RST; }
		ResetFlag get_APB1RSTR_TIM7RST() const { return APB1RSTR.Fields.TIM7RST; }
		ResetFlag get_APB1RSTR_TIM12RST() const { return APB1RSTR.Fields.TIM12RST; }
		ResetFlag get_APB1RSTR_TIM13RST() const { return APB1RSTR.Fields.TIM13RST; }
		ResetFlag get_APB1RSTR_TIM14RST() const { return APB1RSTR.Fields.TIM14RST; }
		ResetFlag get_APB1RSTR_WWDGRST() const { return APB1RSTR.Fields.WWDGRST; }
		ResetFlag get_APB1RSTR_SPI2RST() const { return APB1RSTR.Fields.SPI2RST; }
		ResetFlag get_APB1RSTR_SPI3RST() const { return APB1RSTR.Fields.SPI3RST; }
		ResetFlag get_APB1RSTR_UART2RST() const { return APB1RSTR.Fields.UART2RST; }
		ResetFlag get_APB1RSTR_UART3RST() const { return APB1RSTR.Fields.UART3RST; }
		ResetFlag get_APB1RSTR_UART4RST() const { return APB1RSTR.Fields.UART4RST; }
		ResetFlag get_APB1RSTR_UART5RST() const { return APB1RSTR.Fields.UART5RST; }
		ResetFlag get_APB1RSTR_I2C1RST() const { return APB1RSTR.Fields.I2C1RST; }
		ResetFlag get_APB1RSTR_I2C2RST() const { return APB1RSTR.Fields.I2C2RST; }
		ResetFlag get_APB1RSTR_I2C3RST() const { return APB1RSTR.Fields.I2C3RST; }
		ResetFlag get_APB1RSTR_CAN1RST() const { return APB1RSTR.Fields.CAN1RST; }
		ResetFlag get_APB1RSTR_CAN2RST() const { return APB1RSTR.Fields.CAN2RST; }
		ResetFlag get_APB1RSTR_PWRRST() const { return APB1RSTR.Fields.PWRRST; }
		ResetFlag get_APB1RSTR_DACRST() const { return APB1RSTR.Fields.DACRST; }
		void set_APB1RSTR_TIM2RST(ResetFlag value) { APB1RSTR.Fields.TIM2RST = value; }
		void set_APB1RSTR_TIM3RST(ResetFlag value) { APB1RSTR.Fields.TIM3RST = value; }
		void set_APB1RSTR_TIM4RST(ResetFlag value) { APB1RSTR.Fields.TIM4RST = value; }
		void set_APB1RSTR_TIM5RST(ResetFlag value) { APB1RSTR.Fields.TIM5RST = value; }
		void set_APB1RSTR_TIM6RST(ResetFlag value) { APB1RSTR.Fields.TIM6RST = value; }
		void set_APB1RSTR_TIM7RST(ResetFlag value) { APB1RSTR.Fields.TIM7RST = value; }
		void set_APB1RSTR_TIM12RST(ResetFlag value) { APB1RSTR.Fields.TIM12RST = value; }
		void set_APB1RSTR_TIM13RST(ResetFlag value) { APB1RSTR.Fields.TIM13RST = value; }
		void set_APB1RSTR_TIM14RST(ResetFlag value) { APB1RSTR.Fields.TIM14RST = value; }
		void set_APB1RSTR_WWDGRST(ResetFlag value) { APB1RSTR.Fields.WWDGRST = value; }
		void set_APB1RSTR_SPI2RST(ResetFlag value) { APB1RSTR.Fields.SPI2RST = value; }
		void set_APB1RSTR_SPI3RST(ResetFlag value) { APB1RSTR.Fields.SPI3RST = value; }
		void set_APB1RSTR_UART2RST(ResetFlag value) { APB1RSTR.Fields.UART2RST = value; }
		void set_APB1RSTR_UART3RST(ResetFlag value) { APB1RSTR.Fields.UART3RST = value; }
		void set_APB1RSTR_UART4RST(ResetFlag value) { APB1RSTR.Fields.UART4RST = value; }
		void set_APB1RSTR_UART5RST(ResetFlag value) { APB1RSTR.Fields.UART5RST = value; }
		void set_APB1RSTR_I2C1RST(ResetFlag value) { APB1RSTR.Fields.I2C1RST = value; }
		void set_APB1RSTR_I2C2RST(ResetFlag value) { APB1RSTR.Fields.I2C2RST = value; }
		void set_APB1RSTR_I2C3RST(ResetFlag value) { APB1RSTR.Fields.I2C3RST = value; }
		void set_APB1RSTR_CAN1RST(ResetFlag value) { APB1RSTR.Fields.CAN1RST = value; }
		void set_APB1RSTR_CAN2RST(ResetFlag value) { APB1RSTR.Fields.CAN2RST = value; }
		void set_APB1RSTR_PWRRST(ResetFlag value) { APB1RSTR.Fields.PWRRST = value; }
		void set_APB1RSTR_DACRST(ResetFlag value) { APB1RSTR.Fields.DACRST = value; }

		// APB2RSTR Fields
		ResetFlag get_APB2RSTR_TIM1RST() const { return APB2RSTR.Fields.TIM1RST; }
		ResetFlag get_APB2RSTR_TIM8RST() const { return APB2RSTR.Fields.TIM8RST; }
		ResetFlag get_APB2RSTR_USART1RST() const { return APB2RSTR.Fields.USART1RST; }
		ResetFlag get_APB2RSTR_USART6RST() const { return APB2RSTR.Fields.USART6RST; }
		ResetFlag get_APB2RSTR_ADCRST() const { return APB2RSTR.Fields.ADCRST; }
		ResetFlag get_APB2RSTR_SDIORST() const { return APB2RSTR.Fields.SDIORST; }
		ResetFlag get_APB2RSTR_SPI1RST() const { return APB2RSTR.Fields.SPI1RST; }
		ResetFlag get_APB2RSTR_SYSCFGRST() const { return APB2RSTR.Fields.SYSCFGRST; }
		ResetFlag get_APB2RSTR_TIM9RST() const { return APB2RSTR.Fields.TIM9RST; }
		ResetFlag get_APB2RSTR_TIM10RST() const { return APB2RSTR.Fields.TIM10RST; }
		ResetFlag get_APB2RSTR_TIM11RST() const { return APB2RSTR.Fields.TIM11RST; }
		void set_APB2RSTR_TIM1RST(ResetFlag value) { APB2RSTR.Fields.TIM1RST = value; }
		void set_APB2RSTR_TIM8RST(ResetFlag value) { APB2RSTR.Fields.TIM8RST = value; }
		void set_APB2RSTR_USART1RST(ResetFlag value) { APB2RSTR.Fields.USART1RST = value; }
		void set_APB2RSTR_USART6RST(ResetFlag value) { APB2RSTR.Fields.USART6RST = value; }
		void set_APB2RSTR_ADCRST(ResetFlag value) { APB2RSTR.Fields.ADCRST = value; }
		void set_APB2RSTR_SDIORST(ResetFlag value) { APB2RSTR.Fields.SDIORST = value; }
		void set_APB2RSTR_SPI1RST(ResetFlag value) { APB2RSTR.Fields.SPI1RST = value; }
		void set_APB2RSTR_SYSCFGRST(ResetFlag value) { APB2RSTR.Fields.SYSCFGRST = value; }
		void set_APB2RSTR_TIM9RST(ResetFlag value) { APB2RSTR.Fields.TIM9RST = value; }
		void set_APB2RSTR_TIM10RST(ResetFlag value) { APB2RSTR.Fields.TIM10RST = value; }
		void set_APB2RSTR_TIM11RST(ResetFlag value) { APB2RSTR.Fields.TIM11RST = value; }

		// AHB1ENR Fields
		EnableFlag get_AHB1ENR_GPIOAEN() const { return AHB1ENR.Fields.GPIOAEN; }
		EnableFlag get_AHB1ENR_GPIOBEN() const { return AHB1ENR.Fields.GPIOBEN; }
		EnableFlag get_AHB1ENR_GPIOCEN() const { return AHB1ENR.Fields.GPIOCEN; }
		EnableFlag get_AHB1ENR_GPIODEN() const { return AHB1ENR.Fields.GPIODEN; }
		EnableFlag get_AHB1ENR_GPIOEEN() const { return AHB1ENR.Fields.GPIOEEN; }
		EnableFlag get_AHB1ENR_GPIOFEN() const { return AHB1ENR.Fields.GPIOFEN; }
		EnableFlag get_AHB1ENR_GPIOGEN() const { return AHB1ENR.Fields.GPIOGEN; }
		EnableFlag get_AHB1ENR_GPIOHEN() const { return AHB1ENR.Fields.GPIOHEN; }
		EnableFlag get_AHB1ENR_GPIOIEN() const { return AHB1ENR.Fields.GPIOIEN; }
		EnableFlag get_AHB1ENR_CRCEN() const { return AHB1ENR.Fields.CRCEN; }
		EnableFlag get_AHB1ENR_BKPSRAMEN() const { return AHB1ENR.Fields.BKPSRAMEN; }
		EnableFlag get_AHB1ENR_CCMDATARAMEN() const { return AHB1ENR.Fields.CCMDATARAMEN; }
		EnableFlag get_AHB1ENR_DMA1EN() const { return AHB1ENR.Fields.DMA1EN; }
		EnableFlag get_AHB1ENR_DMA2EN() const { return AHB1ENR.Fields.DMA2EN; }
		EnableFlag get_AHB1ENR_ETHMACEN() const { return AHB1ENR.Fields.ETHMACEN; }
		EnableFlag get_AHB1ENR_ETHMACTXEN() const { return AHB1ENR.Fields.ETHMACTXEN; }
		EnableFlag get_AHB1ENR_ETHMACRXEN() const { return AHB1ENR.Fields.ETHMACRXEN; }
		EnableFlag get_AHB1ENR_ETHMACPTPEN() const { return AHB1ENR.Fields.ETHMACPTPEN; }
		EnableFlag get_AHB1ENR_OTGHSEN() const { return AHB1ENR.Fields.OTGHSEN; }
		EnableFlag get_AHB1ENR_OTGHSULPIEN() const { return AHB1ENR.Fields.OTGHSULPIEN; }
		void set_AHB1ENR_GPIOAEN(EnableFlag value) { AHB1ENR.Fields.GPIOAEN = value; }
		void set_AHB1ENR_GPIOBEN(EnableFlag value) { AHB1ENR.Fields.GPIOBEN = value; }
		void set_AHB1ENR_GPIOCEN(EnableFlag value) { AHB1ENR.Fields.GPIOCEN = value; }
		void set_AHB1ENR_GPIODEN(EnableFlag value) { AHB1ENR.Fields.GPIODEN = value; }
		void set_AHB1ENR_GPIOEEN(EnableFlag value) { AHB1ENR.Fields.GPIOEEN = value; }
		void set_AHB1ENR_GPIOFEN(EnableFlag value) { AHB1ENR.Fields.GPIOFEN = value; }
		void set_AHB1ENR_GPIOGEN(EnableFlag value) { AHB1ENR.Fields.GPIOGEN = value; }
		void set_AHB1ENR_GPIOHEN(EnableFlag value) { AHB1ENR.Fields.GPIOHEN = value; }
		void set_AHB1ENR_GPIOIEN(EnableFlag value) { AHB1ENR.Fields.GPIOIEN = value; }
		void set_AHB1ENR_CRCEN(EnableFlag value) { AHB1ENR.Fields.CRCEN = value; }
		void set_AHB1ENR_BKPSRAMEN(EnableFlag value) { AHB1ENR.Fields.BKPSRAMEN = value; }
		void set_AHB1ENR_CCMDATARAMEN(EnableFlag value) { AHB1ENR.Fields.CCMDATARAMEN = value; }
		void set_AHB1ENR_DMA1EN(EnableFlag value) { AHB1ENR.Fields.DMA1EN = value; }
		void set_AHB1ENR_DMA2EN(EnableFlag value) { AHB1ENR.Fields.DMA2EN = value; }
		void set_AHB1ENR_ETHMACEN(EnableFlag value) { AHB1ENR.Fields.ETHMACEN = value; }
		void set_AHB1ENR_ETHMACTXEN(EnableFlag value) { AHB1ENR.Fields.ETHMACTXEN = value; }
		void set_AHB1ENR_ETHMACRXEN(EnableFlag value) { AHB1ENR.Fields.ETHMACRXEN = value; }
		void set_AHB1ENR_ETHMACPTPEN(EnableFlag value) { AHB1ENR.Fields.ETHMACPTPEN = value; }
		void set_AHB1ENR_OTGHSEN(EnableFlag value) { AHB1ENR.Fields.OTGHSEN = value; }
		void set_AHB1ENR_OTGHSULPIEN(EnableFlag value) { AHB1ENR.Fields.OTGHSULPIEN = value; }

		// AHB2ENR Fields
		EnableFlag get_AHB2ENR_DCMIEN() const { return AHB2ENR.Fields.DCMIEN; }
		EnableFlag get_AHB2ENR_CRYPEN() const { return AHB2ENR.Fields.CRYPEN; }
		EnableFlag get_AHB2ENR_HASHEN() const { return AHB2ENR.Fields.HASHEN; }
		EnableFlag get_AHB2ENR_RNGEN() const { return AHB2ENR.Fields.RNGEN; }
		EnableFlag get_AHB2ENR_OTGFSEN() const { return AHB2ENR.Fields.OTGFSEN; }
		void set_AHB2ENR_DCMIEN(EnableFlag value) { AHB2ENR.Fields.DCMIEN = value; }
		void set_AHB2ENR_CRYPEN(EnableFlag value) { AHB2ENR.Fields.CRYPEN = value; }
		void set_AHB2ENR_HASHEN(EnableFlag value) { AHB2ENR.Fields.HASHEN = value; }
		void set_AHB2ENR_RNGEN(EnableFlag value) { AHB2ENR.Fields.RNGEN = value; }
		void set_AHB2ENR_OTGFSEN(EnableFlag value) { AHB2ENR.Fields.OTGFSEN = value; }

		// AHB3ENR Fields
		EnableFlag get_AHB3ENR_FSMCEN() const { return AHB3ENR.Fields.FSMCEN; }
		void set_AHB3ENR_FSMCEN(EnableFlag value) { AHB3ENR.Fields.FSMCEN = value; }

		// APB1ENR Fields
		EnableFlag get_APB1ENR_TIM2EN() const { return APB1ENR.Fields.TIM2EN; }
		EnableFlag get_APB1ENR_TIM3EN() const { return APB1ENR.Fields.TIM3EN; }
		EnableFlag get_APB1ENR_TIM4EN() const { return APB1ENR.Fields.TIM4EN; }
		EnableFlag get_APB1ENR_TIM5EN() const { return APB1ENR.Fields.TIM5EN; }
		EnableFlag get_APB1ENR_TIM6EN() const { return APB1ENR.Fields.TIM6EN; }
		EnableFlag get_APB1ENR_TIM7EN() const { return APB1ENR.Fields.TIM7EN; }
		EnableFlag get_APB1ENR_TIM12EN() const { return APB1ENR.Fields.TIM12EN; }
		EnableFlag get_APB1ENR_TIM13EN() const { return APB1ENR.Fields.TIM13EN; }
		EnableFlag get_APB1ENR_TIM14EN() const { return APB1ENR.Fields.TIM14EN; }
		EnableFlag get_APB1ENR_WWDGEN() const { return APB1ENR.Fields.WWDGEN; }
		EnableFlag get_APB1ENR_SPI2EN() const { return APB1ENR.Fields.SPI2EN; }
		EnableFlag get_APB1ENR_SPI3EN() const { return APB1ENR.Fields.SPI3EN; }
		EnableFlag get_APB1ENR_USART2EN() const { return APB1ENR.Fields.USART2EN; }
		EnableFlag get_APB1ENR_USART3EN() const { return APB1ENR.Fields.USART3EN; }
		EnableFlag get_APB1ENR_UART4EN() const { return APB1ENR.Fields.UART4EN; }
		EnableFlag get_APB1ENR_UART5EN() const { return APB1ENR.Fields.UART5EN; }
		EnableFlag get_APB1ENR_I2C1EN() const { return APB1ENR.Fields.I2C1EN; }
		EnableFlag get_APB1ENR_I2C2EN() const { return APB1ENR.Fields.I2C2EN; }
		EnableFlag get_APB1ENR_I2C3EN() const { return APB1ENR.Fields.I2C3EN; }
		EnableFlag get_APB1ENR_CAN1EN() const { return APB1ENR.Fields.CAN1EN; }
		EnableFlag get_APB1ENR_CAN2EN() const { return APB1ENR.Fields.CAN2EN; }
		EnableFlag get_APB1ENR_PWREN() const { return APB1ENR.Fields.PWREN; }
		EnableFlag get_APB1ENR_DACEN() const { return APB1ENR.Fields.DACEN; }
		void set_APB1ENR_TIM2EN(EnableFlag value) { APB1ENR.Fields.TIM2EN = value; }
		void set_APB1ENR_TIM3EN(EnableFlag value) { APB1ENR.Fields.TIM3EN = value; }
		void set_APB1ENR_TIM4EN(EnableFlag value) { APB1ENR.Fields.TIM4EN = value; }
		void set_APB1ENR_TIM5EN(EnableFlag value) { APB1ENR.Fields.TIM5EN = value; }
		void set_APB1ENR_TIM6EN(EnableFlag value) { APB1ENR.Fields.TIM6EN = value; }
		void set_APB1ENR_TIM7EN(EnableFlag value) { APB1ENR.Fields.TIM7EN = value; }
		void set_APB1ENR_TIM12EN(EnableFlag value) { APB1ENR.Fields.TIM12EN = value; }
		void set_APB1ENR_TIM13EN(EnableFlag value) { APB1ENR.Fields.TIM13EN = value; }
		void set_APB1ENR_TIM14EN(EnableFlag value) { APB1ENR.Fields.TIM14EN = value; }
		void set_APB1ENR_WWDGEN(EnableFlag value) { APB1ENR.Fields.WWDGEN = value; }
		void set_APB1ENR_SPI2EN(EnableFlag value) { APB1ENR.Fields.SPI2EN = value; }
		void set_APB1ENR_SPI3EN(EnableFlag value) { APB1ENR.Fields.SPI3EN = value; }
		void set_APB1ENR_USART2EN(EnableFlag value) { APB1ENR.Fields.USART2EN = value; }
		void set_APB1ENR_USART3EN(EnableFlag value) { APB1ENR.Fields.USART3EN = value; }
		void set_APB1ENR_UART4EN(EnableFlag value) { APB1ENR.Fields.UART4EN = value; }
		void set_APB1ENR_UART5EN(EnableFlag value) { APB1ENR.Fields.UART5EN = value; }
		void set_APB1ENR_I2C1EN(EnableFlag value) { APB1ENR.Fields.I2C1EN = value; }
		void set_APB1ENR_I2C2EN(EnableFlag value) { APB1ENR.Fields.I2C2EN = value; }
		void set_APB1ENR_I2C3EN(EnableFlag value) { APB1ENR.Fields.I2C3EN = value; }
		void set_APB1ENR_CAN1EN(EnableFlag value) { APB1ENR.Fields.CAN1EN = value; }
		void set_APB1ENR_CAN2EN(EnableFlag value) { APB1ENR.Fields.CAN2EN = value; }
		void set_APB1ENR_PWREN(EnableFlag value) { APB1ENR.Fields.PWREN = value; }
		void set_APB1ENR_DACEN(EnableFlag value) { APB1ENR.Fields.DACEN = value; }

		// APB2ENR Fields
		EnableFlag get_APB2ENR_TIM1EN() const { return APB2ENR.Fields.TIM1EN; }
		EnableFlag get_APB2ENR_TIM8EN() const { return APB2ENR.Fields.TIM8EN; }
		EnableFlag get_APB2ENR_USART1EN() const { return APB2ENR.Fields.USART1EN; }
		EnableFlag get_APB2ENR_USART6EN() const { return APB2ENR.Fields.USART6EN; }
		EnableFlag get_APB2ENR_ADC1EN() const { return APB2ENR.Fields.ADC1EN; }
		EnableFlag get_APB2ENR_ADC2EN() const { return APB2ENR.Fields.ADC2EN; }
		EnableFlag get_APB2ENR_ADC3EN() const { return APB2ENR.Fields.ADC3EN; }
		EnableFlag get_APB2ENR_SDIOEN() const { return APB2ENR.Fields.SDIOEN; }
		EnableFlag get_APB2ENR_SPI1EN() const { return APB2ENR.Fields.SPI1EN; }
		EnableFlag get_APB2ENR_SYSCFGEN() const { return APB2ENR.Fields.SYSCFGEN; }
		EnableFlag get_APB2ENR_TIM9EN() const { return APB2ENR.Fields.TIM9EN; }
		EnableFlag get_APB2ENR_TIM10EN() const { return APB2ENR.Fields.TIM10EN; }
		EnableFlag get_APB2ENR_TIM11EN() const { return APB2ENR.Fields.TIM11EN; }
		void set_APB2ENR_TIM1EN(EnableFlag value) { APB2ENR.Fields.TIM1EN = value; }
		void set_APB2ENR_TIM8EN(EnableFlag value) { APB2ENR.Fields.TIM8EN = value; }
		void set_APB2ENR_USART1EN(EnableFlag value) { APB2ENR.Fields.USART1EN = value; }
		void set_APB2ENR_USART6EN(EnableFlag value) { APB2ENR.Fields.USART6EN = value; }
		void set_APB2ENR_ADC1EN(EnableFlag value) { APB2ENR.Fields.ADC1EN = value; }
		void set_APB2ENR_ADC2EN(EnableFlag value) { APB2ENR.Fields.ADC2EN = value; }
		void set_APB2ENR_ADC3EN(EnableFlag value) { APB2ENR.Fields.ADC3EN = value; }
		void set_APB2ENR_SDIOEN(EnableFlag value) { APB2ENR.Fields.SDIOEN = value; }
		void set_APB2ENR_SPI1EN(EnableFlag value) { APB2ENR.Fields.SPI1EN = value; }
		void set_APB2ENR_SYSCFGEN(EnableFlag value) { APB2ENR.Fields.SYSCFGEN = value; }
		void set_APB2ENR_TIM9EN(EnableFlag value) { APB2ENR.Fields.TIM9EN = value; }
		void set_APB2ENR_TIM10EN(EnableFlag value) { APB2ENR.Fields.TIM10EN = value; }
		void set_APB2ENR_TIM11EN(EnableFlag value) { APB2ENR.Fields.TIM11EN = value; }

		// AHB1LPENR Fields
		EnableFlag get_AHB1LPENR_GPIOALPEN() const { return AHB1LPENR.Fields.GPIOALPEN; }
		EnableFlag get_AHB1LPENR_GPIOBLPEN() const { return AHB1LPENR.Fields.GPIOBLPEN; }
		EnableFlag get_AHB1LPENR_GPIOCLPEN() const { return AHB1LPENR.Fields.GPIOCLPEN; }
		EnableFlag get_AHB1LPENR_GPIODLPEN() const { return AHB1LPENR.Fields.GPIODLPEN; }
		EnableFlag get_AHB1LPENR_GPIOELPEN() const { return AHB1LPENR.Fields.GPIOELPEN; }
		EnableFlag get_AHB1LPENR_GPIOFLPEN() const { return AHB1LPENR.Fields.GPIOFLPEN; }
		EnableFlag get_AHB1LPENR_GPIOGLPEN() const { return AHB1LPENR.Fields.GPIOGLPEN; }
		EnableFlag get_AHB1LPENR_GPIOHLPEN() const { return AHB1LPENR.Fields.GPIOHLPEN; }
		EnableFlag get_AHB1LPENR_GPIOILPEN() const { return AHB1LPENR.Fields.GPIOILPEN; }
		EnableFlag get_AHB1LPENR_CRCLPEN() const { return AHB1LPENR.Fields.CRCLPEN; }
		EnableFlag get_AHB1LPENR_FLITFLPEN() const { return AHB1LPENR.Fields.FLITFLPEN; }
		EnableFlag get_AHB1LPENR_SRAM1LPEN() const { return AHB1LPENR.Fields.SRAM1LPEN; }
		EnableFlag get_AHB1LPENR_SRAM2LPEN() const { return AHB1LPENR.Fields.SRAM2LPEN; }
		EnableFlag get_AHB1LPENR_BKPSRAMLPEN() const { return AHB1LPENR.Fields.BKPSRAMLPEN; }
		EnableFlag get_AHB1LPENR_DMA1LPEN() const { return AHB1LPENR.Fields.DMA1LPEN; }
		EnableFlag get_AHB1LPENR_DMA2LPEN() const { return AHB1LPENR.Fields.DMA2LPEN; }
		EnableFlag get_AHB1LPENR_ETHMACLPEN() const { return AHB1LPENR.Fields.ETHMACLPEN; }
		EnableFlag get_AHB1LPENR_ETHMACTXLPEN() const { return AHB1LPENR.Fields.ETHMACTXLPEN; }
		EnableFlag get_AHB1LPENR_ETHMACRXLPEN() const { return AHB1LPENR.Fields.ETHMACRXLPEN; }
		EnableFlag get_AHB1LPENR_ETHMACPTPLPEN() const { return AHB1LPENR.Fields.ETHMACPTPLPEN; }
		EnableFlag get_AHB1LPENR_OTGHSLPEN() const { return AHB1LPENR.Fields.OTGHSLPEN; }
		EnableFlag get_AHB1LPENR_OTGHSULPILPEN() const { return AHB1LPENR.Fields.OTGHSULPILPEN; }
		void set_AHB1LPENR_GPIOALPEN(EnableFlag value) { AHB1LPENR.Fields.GPIOALPEN = value; }
		void set_AHB1LPENR_GPIOBLPEN(EnableFlag value) { AHB1LPENR.Fields.GPIOBLPEN = value; }
		void set_AHB1LPENR_GPIOCLPEN(EnableFlag value) { AHB1LPENR.Fields.GPIOCLPEN = value; }
		void set_AHB1LPENR_GPIODLPEN(EnableFlag value) { AHB1LPENR.Fields.GPIODLPEN = value; }
		void set_AHB1LPENR_GPIOELPEN(EnableFlag value) { AHB1LPENR.Fields.GPIOELPEN = value; }
		void set_AHB1LPENR_GPIOFLPEN(EnableFlag value) { AHB1LPENR.Fields.GPIOFLPEN = value; }
		void set_AHB1LPENR_GPIOGLPEN(EnableFlag value) { AHB1LPENR.Fields.GPIOGLPEN = value; }
		void set_AHB1LPENR_GPIOHLPEN(EnableFlag value) { AHB1LPENR.Fields.GPIOHLPEN = value; }
		void set_AHB1LPENR_GPIOILPEN(EnableFlag value) { AHB1LPENR.Fields.GPIOILPEN = value; }
		void set_AHB1LPENR_CRCLPEN(EnableFlag value) { AHB1LPENR.Fields.CRCLPEN = value; }
		void set_AHB1LPENR_FLITFLPEN(EnableFlag value) { AHB1LPENR.Fields.FLITFLPEN = value; }
		void set_AHB1LPENR_SRAM1LPEN(EnableFlag value) { AHB1LPENR.Fields.SRAM1LPEN = value; }
		void set_AHB1LPENR_SRAM2LPEN(EnableFlag value) { AHB1LPENR.Fields.SRAM2LPEN = value; }
		void set_AHB1LPENR_BKPSRAMLPEN(EnableFlag value) { AHB1LPENR.Fields.BKPSRAMLPEN = value; }
		void set_AHB1LPENR_DMA1LPEN(EnableFlag value) { AHB1LPENR.Fields.DMA1LPEN = value; }
		void set_AHB1LPENR_DMA2LPEN(EnableFlag value) { AHB1LPENR.Fields.DMA2LPEN = value; }
		void set_AHB1LPENR_ETHMACLPEN(EnableFlag value) { AHB1LPENR.Fields.ETHMACLPEN = value; }
		void set_AHB1LPENR_ETHMACTXLPEN(EnableFlag value) { AHB1LPENR.Fields.ETHMACTXLPEN = value; }
		void set_AHB1LPENR_ETHMACRXLPEN(EnableFlag value) { AHB1LPENR.Fields.ETHMACRXLPEN = value; }
		void set_AHB1LPENR_ETHMACPTPLPEN(EnableFlag value) { AHB1LPENR.Fields.ETHMACPTPLPEN = value; }
		void set_AHB1LPENR_OTGHSLPEN(EnableFlag value) { AHB1LPENR.Fields.OTGHSLPEN = value; }
		void set_AHB1LPENR_OTGHSULPILPEN(EnableFlag value) { AHB1LPENR.Fields.OTGHSULPILPEN = value; }

		// AHB2LPENR Fields
		EnableFlag get_AHB2LPENR_DCMILPEN() const { return AHB2LPENR.Fields.DCMILPEN; }
		EnableFlag get_AHB2LPENR_CRYPLPEN() const { return AHB2LPENR.Fields.CRYPLPEN; }
		EnableFlag get_AHB2LPENR_HASHLPEN() const { return AHB2LPENR.Fields.HASHLPEN; }
		EnableFlag get_AHB2LPENR_RNGLPEN() const { return AHB2LPENR.Fields.RNGLPEN; }
		EnableFlag get_AHB2LPENR_OTGFSLPEN() const { return AHB2LPENR.Fields.OTGFSLPEN; }
		void set_AHB2LPENR_DCMILPEN(EnableFlag value) { AHB2LPENR.Fields.DCMILPEN = value; }
		void set_AHB2LPENR_CRYPLPEN(EnableFlag value) { AHB2LPENR.Fields.CRYPLPEN = value; }
		void set_AHB2LPENR_HASHLPEN(EnableFlag value) { AHB2LPENR.Fields.HASHLPEN = value; }
		void set_AHB2LPENR_RNGLPEN(EnableFlag value) { AHB2LPENR.Fields.RNGLPEN = value; }
		void set_AHB2LPENR_OTGFSLPEN(EnableFlag value) { AHB2LPENR.Fields.OTGFSLPEN = value; }

		// AHB3LPENR Fields
		EnableFlag get_AHB3LPENR_FSMCLPEN() const { return AHB3LPENR.Fields.FSMCLPEN; }
		void set_AHB3LPENR_FSMCLPEN(EnableFlag value) { AHB3LPENR.Fields.FSMCLPEN = value; }

		// APB1LPENR Fields
		EnableFlag get_APB1LPENR_TIM2LPEN() const { return APB1LPENR.Fields.TIM2LPEN; }
		EnableFlag get_APB1LPENR_TIM3LPEN() const { return APB1LPENR.Fields.TIM3LPEN; }
		EnableFlag get_APB1LPENR_TIM4LPEN() const { return APB1LPENR.Fields.TIM4LPEN; }
		EnableFlag get_APB1LPENR_TIM5LPEN() const { return APB1LPENR.Fields.TIM5LPEN; }
		EnableFlag get_APB1LPENR_TIM6LPEN() const { return APB1LPENR.Fields.TIM6LPEN; }
		EnableFlag get_APB1LPENR_TIM7LPEN() const { return APB1LPENR.Fields.TIM7LPEN; }
		EnableFlag get_APB1LPENR_TIM12LPEN() const { return APB1LPENR.Fields.TIM12LPEN; }
		EnableFlag get_APB1LPENR_TIM13LPEN() const { return APB1LPENR.Fields.TIM13LPEN; }
		EnableFlag get_APB1LPENR_TIM14LPEN() const { return APB1LPENR.Fields.TIM14LPEN; }
		EnableFlag get_APB1LPENR_WWDGLPEN() const { return APB1LPENR.Fields.WWDGLPEN; }
		EnableFlag get_APB1LPENR_SPI2LPEN() const { return APB1LPENR.Fields.SPI2LPEN; }
		EnableFlag get_APB1LPENR_SPI3LPEN() const { return APB1LPENR.Fields.SPI3LPEN; }
		EnableFlag get_APB1LPENR_USART2LPEN() const { return APB1LPENR.Fields.USART2LPEN; }
		EnableFlag get_APB1LPENR_USART3LPEN() const { return APB1LPENR.Fields.USART3LPEN; }
		EnableFlag get_APB1LPENR_UART4LPEN() const { return APB1LPENR.Fields.UART4LPEN; }
		EnableFlag get_APB1LPENR_UART5LPEN() const { return APB1LPENR.Fields.UART5LPEN; }
		EnableFlag get_APB1LPENR_I2C1LPEN() const { return APB1LPENR.Fields.I2C1LPEN; }
		EnableFlag get_APB1LPENR_I2C2LPEN() const { return APB1LPENR.Fields.I2C2LPEN; }
		EnableFlag get_APB1LPENR_I2C3LPEN() const { return APB1LPENR.Fields.I2C3LPEN; }
		EnableFlag get_APB1LPENR_CAN1LPEN() const { return APB1LPENR.Fields.CAN1LPEN; }
		EnableFlag get_APB1LPENR_CAN2LPEN() const { return APB1LPENR.Fields.CAN2LPEN; }
		EnableFlag get_APB1LPENR_PWRLPEN() const { return APB1LPENR.Fields.PWRLPEN; }
		EnableFlag get_APB1LPENR_DACLPEN() const { return APB1LPENR.Fields.DACLPEN; }
		void set_APB1LPENR_TIM2LPEN(EnableFlag value) { APB1LPENR.Fields.TIM2LPEN = value; }
		void set_APB1LPENR_TIM3LPEN(EnableFlag value) { APB1LPENR.Fields.TIM3LPEN = value; }
		void set_APB1LPENR_TIM4LPEN(EnableFlag value) { APB1LPENR.Fields.TIM4LPEN = value; }
		void set_APB1LPENR_TIM5LPEN(EnableFlag value) { APB1LPENR.Fields.TIM5LPEN = value; }
		void set_APB1LPENR_TIM6LPEN(EnableFlag value) { APB1LPENR.Fields.TIM6LPEN = value; }
		void set_APB1LPENR_TIM7LPEN(EnableFlag value) { APB1LPENR.Fields.TIM7LPEN = value; }
		void set_APB1LPENR_TIM12LPEN(EnableFlag value) { APB1LPENR.Fields.TIM12LPEN = value; }
		void set_APB1LPENR_TIM13LPEN(EnableFlag value) { APB1LPENR.Fields.TIM13LPEN = value; }
		void set_APB1LPENR_TIM14LPEN(EnableFlag value) { APB1LPENR.Fields.TIM14LPEN = value; }
		void set_APB1LPENR_WWDGLPEN(EnableFlag value) { APB1LPENR.Fields.WWDGLPEN = value; }
		void set_APB1LPENR_SPI2LPEN(EnableFlag value) { APB1LPENR.Fields.SPI2LPEN = value; }
		void set_APB1LPENR_SPI3LPEN(EnableFlag value) { APB1LPENR.Fields.SPI3LPEN = value; }
		void set_APB1LPENR_USART2LPEN(EnableFlag value) { APB1LPENR.Fields.USART2LPEN = value; }
		void set_APB1LPENR_USART3LPEN(EnableFlag value) { APB1LPENR.Fields.USART3LPEN = value; }
		void set_APB1LPENR_UART4LPEN(EnableFlag value) { APB1LPENR.Fields.UART4LPEN = value; }
		void set_APB1LPENR_UART5LPEN(EnableFlag value) { APB1LPENR.Fields.UART5LPEN = value; }
		void set_APB1LPENR_I2C1LPEN(EnableFlag value) { APB1LPENR.Fields.I2C1LPEN = value; }
		void set_APB1LPENR_I2C2LPEN(EnableFlag value) { APB1LPENR.Fields.I2C2LPEN = value; }
		void set_APB1LPENR_I2C3LPEN(EnableFlag value) { APB1LPENR.Fields.I2C3LPEN = value; }
		void set_APB1LPENR_CAN1LPEN(EnableFlag value) { APB1LPENR.Fields.CAN1LPEN = value; }
		void set_APB1LPENR_CAN2LPEN(EnableFlag value) { APB1LPENR.Fields.CAN2LPEN = value; }
		void set_APB1LPENR_PWRLPEN(EnableFlag value) { APB1LPENR.Fields.PWRLPEN = value; }
		void set_APB1LPENR_DACLPEN(EnableFlag value) { APB1LPENR.Fields.DACLPEN = value; }

		// APB2LPENR Fields
		EnableFlag get_APB2LPENR_TIM1LPEN() const { return APB2LPENR.Fields.TIM1LPEN; }
		EnableFlag get_APB2LPENR_TIM8LPEN() const { return APB2LPENR.Fields.TIM8LPEN; }
		EnableFlag get_APB2LPENR_USART1LPEN() const { return APB2LPENR.Fields.USART1LPEN; }
		EnableFlag get_APB2LPENR_USART6LPEN() const { return APB2LPENR.Fields.USART6LPEN; }
		EnableFlag get_APB2LPENR_ADC1LPEN() const { return APB2LPENR.Fields.ADC1LPEN; }
		EnableFlag get_APB2LPENR_ADC2LPEN() const { return APB2LPENR.Fields.ADC2LPEN; }
		EnableFlag get_APB2LPENR_ADC3LPEN() const { return APB2LPENR.Fields.ADC3LPEN; }
		EnableFlag get_APB2LPENR_SDIOLPEN() const { return APB2LPENR.Fields.SDIOLPEN; }
		EnableFlag get_APB2LPENR_SPI1LPEN() const { return APB2LPENR.Fields.SPI1LPEN; }
		EnableFlag get_APB2LPENR_SYSCFGLPEN() const { return APB2LPENR.Fields.SYSCFGLPEN; }
		EnableFlag get_APB2LPENR_TIM9LPEN() const { return APB2LPENR.Fields.TIM9LPEN; }
		EnableFlag get_APB2LPENR_TIM10LPEN() const { return APB2LPENR.Fields.TIM10LPEN; }
		EnableFlag get_APB2LPENR_TIM11LPEN() const { return APB2LPENR.Fields.TIM11LPEN; }
		void set_APB2LPENR_TIM1LPEN(EnableFlag value) { APB2LPENR.Fields.TIM1LPEN = value; }
		void set_APB2LPENR_TIM8LPEN(EnableFlag value) { APB2LPENR.Fields.TIM8LPEN = value; }
		void set_APB2LPENR_USART1LPEN(EnableFlag value) { APB2LPENR.Fields.USART1LPEN = value; }
		void set_APB2LPENR_USART6LPEN(EnableFlag value) { APB2LPENR.Fields.USART6LPEN = value; }
		void set_APB2LPENR_ADC1LPEN(EnableFlag value) { APB2LPENR.Fields.ADC1LPEN = value; }
		void set_APB2LPENR_ADC2LPEN(EnableFlag value) { APB2LPENR.Fields.ADC2LPEN = value; }
		void set_APB2LPENR_ADC3LPEN(EnableFlag value) { APB2LPENR.Fields.ADC3LPEN = value; }
		void set_APB2LPENR_SDIOLPEN(EnableFlag value) { APB2LPENR.Fields.SDIOLPEN = value; }
		void set_APB2LPENR_SPI1LPEN(EnableFlag value) { APB2LPENR.Fields.SPI1LPEN = value; }
		void set_APB2LPENR_SYSCFGLPEN(EnableFlag value) { APB2LPENR.Fields.SYSCFGLPEN = value; }
		void set_APB2LPENR_TIM9LPEN(EnableFlag value) { APB2LPENR.Fields.TIM9LPEN = value; }
		void set_APB2LPENR_TIM10LPEN(EnableFlag value) { APB2LPENR.Fields.TIM10LPEN = value; }
		void set_APB2LPENR_TIM11LPEN(EnableFlag value) { APB2LPENR.Fields.TIM11LPEN = value; }

		// BDCR Fields
		EnableFlag get_BDCR_LSEON() const { return BDCR.Fields.LSEON; }
		ReadyFlag get_BDCR_LSERDY() const { return BDCR.Fields.LSERDY; }
		ExternalLowSpeedOscillatorBypass get_BDCR_LSEBYP() const { return BDCR.Fields.LSEBYP; }
		RtcClockSourceSelection get_BDCR_RTCSEL() const { return BDCR.Fields.RTCSEL; }
		EnableFlag get_BDCR_RTCEN() const { return BDCR.Fields.RTCEN; }
		ResetFlag get_BDCR_BDRST() const { return BDCR.Fields.BDRST; }
		void set_BDCR_LSEON(EnableFlag value) { BDCR.Fields.LSEON = value; }
		void set_BDCR_LSEBYP(ExternalLowSpeedOscillatorBypass value) { BDCR.Fields.LSEBYP = value; }
		void set_BDCR_RTCSEL(RtcClockSourceSelection value) { BDCR.Fields.RTCSEL = value; }
		void set_BDCR_RTCEN(EnableFlag value) { BDCR.Fields.RTCEN = value; }
		void set_BDCR_BDRST(ResetFlag value) { BDCR.Fields.BDRST = value; }

		// CSR Fields
		EnableFlag get_CSR_LSION() const { return CSR.Fields.LSION; }
		ReadyFlag get_CSR_LSIRDY() const { return CSR.Fields.LSIRDY; }
		ClearFlag get_CSR_RMVF() const { return CSR.Fields.RMVF; }
		ResetOccurredFlag get_CSR_BORRSTF() const { return CSR.Fields.BORRSTF; }
		ResetOccurredFlag get_CSR_PINRSTF() const { return CSR.Fields.PINRSTF; }
		ResetOccurredFlag get_CSR_PORRSTF() const { return CSR.Fields.PORRSTF; }
		ResetOccurredFlag get_CSR_SFTRSTF() const { return CSR.Fields.SFTRSTF; }
		ResetOccurredFlag get_CSR_IWDGRSTF() const { return CSR.Fields.IWDGRSTF; }
		ResetOccurredFlag get_CSR_WWDGRSTF() const { return CSR.Fields.WWDGRSTF; }
		ResetOccurredFlag get_CSR_LPWRRSTF() const { return CSR.Fields.LPWRRSTF; }
		void set_CSR_LSION(EnableFlag value) { CSR.Fields.LSION = value; }
		void set_CSR_RMVF(ClearFlag value) { CSR.Fields.RMVF = value; }

		// SSCGR Fields
		uint32_t get_SSCGR_MODPER() const { return SSCGR.Fields.MODPER; }
		uint32_t get_SSCGR_INCSTEP() const { return SSCGR.Fields.INCSTEP; }
		SpreadSelect get_SSCGR_SPREADSEL() const { return SSCGR.Fields.SPREADSEL; }
		EnableFlag get_SSCGR_SSCGEN() const { return SSCGR.Fields.SSCGEN; }
		void set_SSCGR_MODPER(uint32_t value) { SSCGR.Fields.MODPER = value; }
		void set_SSCGR_INCSTEP(uint32_t value) { SSCGR.Fields.INCSTEP = value; }
		void set_SSCGR_SPREADSEL(SpreadSelect value) { SSCGR.Fields.SPREADSEL = value; }
		void set_SSCGR_SSCGEN(EnableFlag value) { SSCGR.Fields.SSCGEN = value; }

		// PLLI2SCFGR Fields
		uint32_t get_PLLI2SCFGR_PLLI2SN() const { return PLLI2SCFGR.Fields.PLLI2SN; }
		uint32_t get_PLLI2SCFGR_PLLI2SR() const { return PLLI2SCFGR.Fields.PLLI2SR; }
		void set_PLLI2SCFGR_PLLI2SN(uint32_t value) { PLLI2SCFGR.Fields.PLLI2SN = value; }
		void set_PLLI2SCFGR_PLLI2SR(uint32_t value) { PLLI2SCFGR.Fields.PLLI2SR = value; }

	private:

		CR_t CR; // Address Offset 0x0
		PLLCFGR_t PLLCFGR; // Address Offset 0x4
		CFGR_t CFGR; // Address Offset 0x8
		CIR_t CIR; // Address Offset 0xC
		AHB1RSTR_t AHB1RSTR; // Address Offset 0x10
		AHB2RSTR_t AHB2RSTR; // Address Offset 0x14
		AHB3RSTR_t AHB3RSTR; // Address Offset 0x18
		Reserved Reserved1; // Address Offset 0x1C
		APB1RSTR_t APB1RSTR; // Address Offset 0x20
		APB2RSTR_t APB2RSTR; // Address Offset 0x24
		Reserved Reserved2; // Address Offset 0x28
		Reserved Reserved3; // Address Offset 0x2C
		AHB1ENR_t AHB1ENR; // Address Offset 0x30
		AHB2ENR_t AHB2ENR; // Address Offset 0x34
		AHB3ENR_t AHB3ENR; // Address Offset 0x38
		Reserved Reserved4; // Address Offset 0x3C
		APB1ENR_t APB1ENR; // Address Offset 0x40
		APB2ENR_t APB2ENR; // Address Offset 0x44
		Reserved Reserved5; // Address Offset 0x48
		Reserved Reserved6; // Address Offset 0x4C
		AHB1LPENR_t AHB1LPENR; // Address Offset 0x50
		AHB2LPENR_t AHB2LPENR; // Address Offset 0x54
		AHB3LPENR_t AHB3LPENR; // Address Offset 0x58
		Reserved Reserved7; // Address Offset 0x5C
		APB1LPENR_t APB1LPENR; // Address Offset 0x60
		APB2LPENR_t APB2LPENR; // Address Offset 0x64
		Reserved Reserved8; // Address Offset 0x68
		Reserved Reserved9; // Address Offset 0x6C
		BDCR_t BDCR; // Address Offset 0x70
		CSR_t CSR; // Address Offset 0x74
		Reserved Reserved10; // Address Offset 0x78
		Reserved Reserved11; // Address Offset 0x7C
		SSCGR_t SSCGR; // Address Offset 0x80
		PLLI2SCFGR_t PLLI2SCFGR; // Address Offset 0x84
	};
}
#endif // RCC_REGISTER_MAP_HPP_