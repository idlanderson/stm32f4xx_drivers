#ifndef RCC_REGISTER_MAP_HPP_
#define RCC_REGISTER_MAP_HPP_

#include <cstdint>
#include "rcc_types.hpp"

using namespace std;

namespace stm32::rcc
{
	union ClockControlRegister
	{
		volatile struct
		{
			EnableFlag     HSION       : 1; // [0]     rw : Internal high-speed clock enable
			ReadyFlag      HSIRDY      : 1; // [1]     r  : Internal high-speed clock ready flag
			uint8_t        Reserved1   : 1; // [2]        : Reserved, must be kept at reset value
			uint8_t        HSITRIM     : 5; // [7:3]   rw : Internal high-speed clock trimming
			uint8_t        HSICAL      : 8; // [15:8]  r  : Internal high-speed clock calibration
			EnableFlag     HSEON       : 1; // [16]    rw : HSE clock enable
			ReadyFlag      HSERDY      : 1; // [17]    r  : HSE clock ready flag
			HseClockBypass HSEBYP      : 1; // [18]    rw : HSE clock bypass
			EnableFlag     CSSON       : 1; // [19]    rw : Clock security system enable
			uint8_t        Reserved2   : 4; // [23:20]    : Reserved, must be kept at reset value.
			EnableFlag     PLLON       : 1; // [24]    rw : Main PLL (PLL) enable
			ReadyFlag      PLLRDY      : 1; // [25]    r  : Main PLL (PLL) clock ready flag
			EnableFlag     PLLI2SON    : 1; // [26]    rw : PLLI2S enable
			ReadyFlag      PLLI2SRDY   : 1; // [27]    r  : PLLI2S clock ready flag
			uint32_t       Reserved3   : 4; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union PllConfigurationRegiser
	{
		volatile struct
		{
			uint8_t                            PLLM        : 5; // [4:0]   rw : Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
			uint16_t                           PLLN        : 9; // [14:6]  rw : Main PLL (PLL) multiplication factor for VCO
			uint8_t                            Reserved1   : 1; // [15]       : 
			MainPllDivisionFactor              PLLP        : 2; // [17:16] rw : Main PLL (PLL) division factor for main system clock
			uint8_t                            Reserved2   : 4; // [21:18]    : 
			MainPllAndAudioPllEntryClockSource PLLSRC      : 1; // [22]    rw : Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
			uint8_t                            Reserved3   : 1; // [23]       : 
			uint8_t                            PLLQ        : 4; // [27:24] rw : Main PLL (PLL) division factor for USB OTG FS SDIO and random number generator clocks
			uint32_t                           Reserved4   : 5; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union ClockConfigurationRegister
	{
		volatile struct
		{
			SystemClock                 SW          : 2; // [1:0]   rw : System clock switch
			SystemClock                 SWS         : 2; // [3:2]   r  : System clock switch status
			AhbPrescaler                HPRE        : 4; // [7:4]   rw : AHB prescaler
			uint8_t                     Reserved1   : 2; // [9:8]      : 
			ApbPrescaler                PPRE1       : 3; // [12:10] rw : APB Low speed prescaler (APB1)
			ApbPrescaler                PPRE2       : 3; // [15:13] rw : APB high-speed prescaler (APB2)
			uint8_t                     RTCPRE      : 5; // [20:16] rw : HSE division factor for RTC clock
			MicrocontrollerClockOutput1 MCO1        : 2; // [22:21] rw : Microcontroller clock output 1
			I2SClockSelection           I2SSCR      : 1; // [23]    rw : I2S clock selection
			McoPrescaler                MCO1PRE     : 3; // [26:24] rw : MCO1 prescaler
			McoPrescaler                MCO2PRE     : 3; // [29:27] rw : MCO2 prescaler
			MicrocontrollerClockOutput2 MCO2        : 2; // [31:30] rw : Microcontroller clock output 2
		} Fields;
		volatile uint32_t Value;
	};

	union ClockInterruptRegister
	{
		volatile struct
		{
			ReadyFlag                        LSIRDYF     : 1; // [0]     r  : 
			ReadyFlag                        LSERDYF     : 1; // [1]     r  : 
			ReadyFlag                        HSIRDYF     : 1; // [2]     r  : 
			ReadyFlag                        HSERDYF     : 1; // [3]     r  : 
			ReadyFlag                        PLLRDYF     : 1; // [4]     r  : 
			ReadyFlag                        PLLI2SRDYF  : 1; // [5]     r  : 
			uint8_t                          Reserved1   : 1; // [6]        : 
			ClockSecuritySystemInterruptFlag CSSF        : 1; // [7]     r  : 
			EnableFlag                       LSIRDYIE    : 1; // [8]     rw : 
			EnableFlag                       LSERDYIE    : 1; // [9]     rw : 
			EnableFlag                       HSIRDYIE    : 1; // [10]    rw : 
			EnableFlag                       HSERDYIE    : 1; // [11]    rw : 
			EnableFlag                       PLLRDYIE    : 1; // [12]    rw : 
			EnableFlag                       PLLI2SRDYIE : 1; // [13]    rw : 
			uint8_t                          Reserved2   : 2; // [15:14]    : 
			ClearFlag                        LSIRDYC     : 1; // [16]    w  : 
			ClearFlag                        LSERDYC     : 1; // [17]    w  : 
			ClearFlag                        HSIRDYC     : 1; // [18]    w  : 
			ClearFlag                        HSERDYC     : 1; // [19]    w  : 
			ClearFlag                        PLLRDYC     : 1; // [20]    w  : 
			ClearFlag                        PLLI2SRDYC  : 1; // [21]    w  : 
			uint8_t                          Reserved3   : 1; // [22]       : 
			ClearFlag                        CSSC        : 1; // [23]    w  : 
			uint32_t                         Reserved4   : 8; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Ahb1PeripheralResetRegister
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
			uint8_t   Reserved1   : 3; // [11:9]     : 
			ResetFlag CRCRST      : 1; // [12]    rw : 
			uint8_t   Reserved2   : 8; // [20:13]    : 
			ResetFlag DMA1RST     : 1; // [21]    rw : 
			ResetFlag DMA2RST     : 1; // [22]    rw : 
			uint8_t   Reserved3   : 2; // [24:23]    : 
			ResetFlag ETHMACRST   : 1; // [25]    rw : 
			uint8_t   Reserved4   : 3; // [28:26]    : 
			ResetFlag OTGHSRST    : 1; // [29]    rw : 
			uint32_t  Reserved5   : 2; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Ahb2PeripheralResetRegister
	{
		volatile struct
		{
			ResetFlag DCMIRST     : 1; // [0]     rw : 
			uint8_t   Reserved1   : 3; // [3:1]      : 
			ResetFlag CRYPRST     : 1; // [4]     rw : 
			ResetFlag HASHRST     : 1; // [5]     rw : 
			ResetFlag RNGRST      : 1; // [6]     rw : 
			ResetFlag OTGFSRST    : 1; // [7]     rw : 
			uint32_t  Reserved2   : 24; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Ahb3PeripheralResetRegister
	{
		volatile struct
		{
			ResetFlag FSMCRST     : 1; // [0]     rw : 
			uint32_t  Reserved1   : 31; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Apb1PeripheralResetRegister
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
			uint8_t   Reserved1   : 2; // [10:9]     : 
			ResetFlag WWDGRST     : 1; // [11]    rw : 
			uint8_t   Reserved2   : 2; // [13:12]    : 
			ResetFlag SPI2RST     : 1; // [14]    rw : 
			ResetFlag SPI3RST     : 1; // [15]    rw : 
			uint8_t   Reserved3   : 1; // [16]       : 
			ResetFlag UART2RST    : 1; // [17]    rw : 
			ResetFlag UART3RST    : 1; // [18]    rw : 
			ResetFlag UART4RST    : 1; // [19]    rw : 
			ResetFlag UART5RST    : 1; // [20]    rw : 
			ResetFlag I2C1RST     : 1; // [21]    rw : 
			ResetFlag I2C2RST     : 1; // [22]    rw : 
			ResetFlag I2C3RST     : 1; // [23]    rw : 
			uint8_t   Reserved4   : 1; // [24]       : 
			ResetFlag CAN1RST     : 1; // [25]    rw : 
			ResetFlag CAN2RST     : 1; // [26]    rw : 
			uint8_t   Reserved5   : 1; // [27]       : 
			ResetFlag PWRRST      : 1; // [28]    rw : 
			ResetFlag DACRST      : 1; // [29]    rw : 
			uint32_t  Reserved6   : 2; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Apb2PeripheralResetRegister
	{
		volatile struct
		{
			ResetFlag TIM1RST     : 1; // [0]     rw : 
			ResetFlag TIM8RST     : 1; // [1]     rw : 
			uint8_t   Reserved1   : 2; // [3:2]      : 
			ResetFlag USART1RST   : 1; // [4]     rw : 
			ResetFlag USART6RST   : 1; // [5]     rw : 
			uint8_t   Reserved2   : 2; // [7:6]      : 
			ResetFlag ADCRST      : 1; // [8]     rw : 
			uint8_t   Reserved3   : 2; // [10:9]     : 
			ResetFlag SDIORST     : 1; // [11]    rw : 
			ResetFlag SPI1RST     : 1; // [12]    rw : 
			uint8_t   Reserved4   : 1; // [13]       : 
			ResetFlag SYSCFGRST   : 1; // [14]    rw : 
			uint8_t   Reserved5   : 1; // [15]       : 
			ResetFlag TIM9RST     : 1; // [16]    rw : 
			ResetFlag TIM10RST    : 1; // [17]    rw : 
			ResetFlag TIM11RST    : 1; // [18]    rw : 
			uint32_t  Reserved6   : 13; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Ahb1PeripheralClockEnableRegister
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
			uint8_t    Reserved1   : 3; // [11:9]     : 
			EnableFlag CRCEN       : 1; // [12]    rw : 
			uint8_t    Reserved2   : 5; // [17:13]    : 
			EnableFlag BKPSRAMEN   : 1; // [18]    rw : 
			uint8_t    Reserved3   : 1; // [19]       : 
			EnableFlag CCMDATARAMEN : 1; // [20]    rw : 
			EnableFlag DMA1EN      : 1; // [21]    rw : 
			EnableFlag DMA2EN      : 1; // [22]    rw : 
			uint8_t    Reserved4   : 2; // [24:23]    : 
			EnableFlag ETHMACEN    : 1; // [25]    rw : 
			EnableFlag ETHMACTXEN  : 1; // [26]    rw : 
			EnableFlag ETHMACRXEN  : 1; // [27]    rw : 
			EnableFlag ETHMACPTPEN : 1; // [28]    rw : 
			EnableFlag OTGHSEN     : 1; // [29]    rw : 
			EnableFlag OTGHSULPIEN : 1; // [30]    rw : 
			uint32_t   Reserved5   : 1; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Ahb2PeripheralClockEnableRegister
	{
		volatile struct
		{
			EnableFlag DCMIEN      : 1; // [0]     rw : 
			uint8_t    Reserved1   : 3; // [3:1]      : 
			EnableFlag CRYPEN      : 1; // [4]     rw : 
			EnableFlag HASHEN      : 1; // [5]     rw : 
			EnableFlag RNGEN       : 1; // [6]     rw : 
			EnableFlag OTGFSEN     : 1; // [7]     rw : 
			uint32_t   Reserved2   : 24; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Ahb3PeripheralClockEnableRegister
	{
		volatile struct
		{
			EnableFlag FSMCEN      : 1; // [0]     rw : 
			uint32_t   Reserved1   : 31; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Apb1PeripheralClockEnableRegister
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
			uint8_t    Reserved1   : 2; // [10:9]     : 
			EnableFlag WWDGEN      : 1; // [11]    rw : 
			EnableFlag Reserved2   : 2; // [13:12]    : 
			EnableFlag SPI2EN      : 1; // [14]    rw : 
			EnableFlag SPI3EN      : 1; // [15]    rw : 
			uint8_t    Reserved3   : 1; // [16]       : 
			EnableFlag USART2EN    : 1; // [17]    rw : 
			EnableFlag USART3EN    : 1; // [18]    rw : 
			EnableFlag UART4EN     : 1; // [19]    rw : 
			EnableFlag UART5EN     : 1; // [20]    rw : 
			EnableFlag I2C1EN      : 1; // [21]    rw : 
			EnableFlag I2C2EN      : 1; // [22]    rw : 
			EnableFlag I2C3EN      : 1; // [23]    rw : 
			uint8_t    Reserved4   : 1; // [24]       : 
			EnableFlag CAN1EN      : 1; // [25]    rw : 
			EnableFlag CAN2EN      : 1; // [26]    rw : 
			uint8_t    Reserved5   : 1; // [27]       : 
			EnableFlag PWREN       : 1; // [28]    rw : 
			EnableFlag DACEN       : 1; // [29]    rw : 
			uint32_t   Reserved6   : 2; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Apb2PeripheralClockEnableRegister
	{
		volatile struct
		{
			EnableFlag TIM1EN      : 1; // [0]     rw : 
			EnableFlag TIM8EN      : 1; // [1]     rw : 
			uint8_t    Reserved1   : 2; // [3:2]      : 
			EnableFlag USART1EN    : 1; // [4]     rw : 
			EnableFlag USART6EN    : 1; // [5]     rw : 
			uint8_t    Reserved2   : 2; // [7:6]      : 
			EnableFlag ADC1EN      : 1; // [8]     rw : 
			EnableFlag ADC2EN      : 1; // [9]     rw : 
			EnableFlag ADC3EN      : 1; // [10]    rw : 
			EnableFlag SDIOEN      : 1; // [11]    rw : 
			EnableFlag SPI1EN      : 1; // [12]    rw : 
			uint8_t    Reserved3   : 1; // [13]       : 
			EnableFlag SYSCFGEN    : 1; // [14]    rw : 
			uint8_t    Reserved4   : 1; // [15]       : 
			EnableFlag TIM9EN      : 1; // [16]    rw : 
			EnableFlag TIM10EN     : 1; // [17]    rw : 
			EnableFlag TIM11EN     : 1; // [18]    rw : 
			uint32_t   Reserved5   : 13; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Ahb1PeripheralClockEnableInLowPowerModeRegister
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
			uint8_t    Reserved1   : 3; // [11:9]     : 
			EnableFlag CRCLPEN     : 1; // [12]    rw : 
			uint8_t    Reserved2   : 2; // [14:13]    : 
			EnableFlag FLITFLPEN   : 1; // [15]    rw : 
			EnableFlag SRAM1LPEN   : 1; // [16]    rw : 
			EnableFlag SRAM2LPEN   : 1; // [17]    rw : 
			EnableFlag BKPSRAMLPEN : 1; // [18]    rw : 
			uint8_t    Reserved3   : 2; // [20:19]    : 
			EnableFlag DMA1LPEN    : 1; // [21]    rw : 
			EnableFlag DMA2LPEN    : 1; // [22]    rw : 
			uint8_t    Reserved4   : 2; // [24:23]    : 
			EnableFlag ETHMACLPEN  : 1; // [25]    rw : 
			EnableFlag ETHMACTXLPEN : 1; // [26]    rw : 
			EnableFlag ETHMACRXLPEN : 1; // [27]    rw : 
			EnableFlag ETHMACPTPLPEN : 1; // [28]    rw : 
			EnableFlag OTGHSLPEN   : 1; // [29]    rw : 
			EnableFlag OTGHSULPILPEN : 1; // [30]    rw : 
			uint32_t   Reserved5   : 1; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Ahb2PeripheralClockEnableInLowPowerModeRegister
	{
		volatile struct
		{
			EnableFlag DCMILPEN    : 1; // [0]     rw : 
			uint8_t    Reserved1   : 3; // [3:1]      : 
			EnableFlag CRYPLPEN    : 1; // [4]     rw : 
			EnableFlag HASHLPEN    : 1; // [5]     rw : 
			EnableFlag RNGLPEN     : 1; // [6]     rw : 
			EnableFlag OTGFSLPEN   : 1; // [7]     rw : 
			uint32_t   Reserved2   : 24; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Ahb3PeripheralClockEnableInLowPowerModeRegister
	{
		volatile struct
		{
			EnableFlag FSMCLPEN    : 1; // [0]     rw : 
			uint32_t   Reserved1   : 31; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Apb1PeripheralClockEnableInLowPowerModeRegister
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
			uint8_t    Reserved1   : 2; // [10:9]     : 
			EnableFlag WWDGLPEN    : 1; // [11]    rw : 
			uint8_t    Reserved2   : 2; // [13:12]    : 
			EnableFlag SPI2LPEN    : 1; // [14]    rw : 
			EnableFlag SPI3LPEN    : 1; // [15]    rw : 
			uint8_t    Reserved3   : 1; // [16]       : 
			EnableFlag USART2LPEN  : 1; // [17]    rw : 
			EnableFlag USART3LPEN  : 1; // [18]    rw : 
			EnableFlag UART4LPEN   : 1; // [19]    rw : 
			EnableFlag UART5LPEN   : 1; // [20]    rw : 
			EnableFlag I2C1LPEN    : 1; // [21]    rw : 
			EnableFlag I2C2LPEN    : 1; // [22]    rw : 
			EnableFlag I2C3LPEN    : 1; // [23]    rw : 
			uint8_t    Reserved4   : 1; // [24]       : 
			EnableFlag CAN1LPEN    : 1; // [25]    rw : 
			EnableFlag CAN2LPEN    : 1; // [26]    rw : 
			uint8_t    Reserved5   : 1; // [27]       : 
			EnableFlag PWRLPEN     : 1; // [28]    rw : 
			EnableFlag DACLPEN     : 1; // [29]    rw : 
			uint32_t   Reserved6   : 2; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union Apb2PeripheralClockEnableInLowPowerModeRegister
	{
		volatile struct
		{
			EnableFlag TIM1LPEN    : 1; // [0]     rw : 
			EnableFlag TIM8LPEN    : 1; // [1]     rw : 
			uint8_t    Reserved1   : 2; // [3:2]      : 
			uint8_t    Reserved2   : 2; // [3:2]      : 
			EnableFlag USART1LPEN  : 1; // [4]     rw : 
			EnableFlag USART6LPEN  : 1; // [5]     rw : 
			EnableFlag ADC1LPEN    : 1; // [8]     rw : 
			EnableFlag ADC2LPEN    : 1; // [9]     rw : 
			EnableFlag ADC3LPEN    : 1; // [10]    rw : 
			EnableFlag SDIOLPEN    : 1; // [11]    rw : 
			EnableFlag SPI1LPEN    : 1; // [12]    rw : 
			uint8_t    Reserved3   : 1; // [13]       : 
			EnableFlag SYSCFGLPEN  : 1; // [14]    rw : 
			uint8_t    Reserved4   : 1; // [15]       : 
			EnableFlag TIM9LPEN    : 1; // [16]    rw : 
			EnableFlag TIM10LPEN   : 1; // [17]    rw : 
			EnableFlag TIM11LPEN   : 1; // [18]    rw : 
			uint32_t   Reserved5   : 13; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union BackupDomainControlRegister
	{
		volatile struct
		{
			EnableFlag                       LSEON       : 1; // [0]     rw : 
			ReadyFlag                        LSERDY      : 1; // [1]     r  : 
			ExternalLowSpeedOscillatorBypass LSEBYP      : 1; // [2]     rw : 
			uint8_t                          Reserved1   : 5; // [7:3]      : 
			RtcClockSourceSelection          RTCSEL      : 2; // [9:8]   rw : 
			uint8_t                          Reserved2   : 5; // [14:10]    : 
			EnableFlag                       RTCEN       : 1; // [15]    rw : 
			ResetFlag                        BDRST       : 1; // [16]    rw : 
			uint32_t                         Reserved3   : 15; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union ClockControlAndStatusRegister
	{
		volatile struct
		{
			EnableFlag        LSION       : 1; // [0]     rw : 
			ReadyFlag         LSIRDY      : 1; // [1]     r  : 
			uint32_t          Reserved1   : 22; // [23:2]     : 
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

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union uint32_t
	{
		volatile struct
		{
			uint32_t Reserved1   : 32; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	union SpreadSpectrumClockGenerationRegister
	{
		volatile struct
		{
			uint16_t     MODPER      : 13; // [12:0]  rw : Modulation period
			uint16_t     INCSTEP     : 15; // [27:13] rw : Incrementation step
			uint8_t      Reserved1   : 2; // [29:28]    : 
			SpreadSelect SPREADSEL   : 1; // [30]    rw : Spread Select
			EnableFlag   SSCGEN      : 1; // [31]    rw : Spread spectrum modulation enable
		} Fields;
		volatile uint32_t Value;
	};

	union PLLI2SConfigurationRegister
	{
		volatile struct
		{
			uint8_t  Reserved1   : 6; // [5:0]      : 
			uint16_t PLLI2SN     : 9; // [14:6]  rw : PLLI2S multiplication factor for VCO
			uint16_t Reserved2   : 13; // [27:15]    : 
			uint8_t  PLLI2SR     : 3; // [30:28] rw : PLLI2S division factor for I2S clocks
			uint32_t Reserved3   : 1; // Pad to 32 bits 
		} Fields;
		volatile uint32_t Value;
	};

	class IRccRegisterMap
	{
	public:

		// CR Fields
		virtual EnableFlag get_CR_HSION() const = 0;
		virtual ReadyFlag get_CR_HSIRDY() const = 0;
		virtual uint8_t get_CR_HSITRIM() const = 0;
		virtual uint8_t get_CR_HSICAL() const = 0;
		virtual EnableFlag get_CR_HSEON() const = 0;
		virtual ReadyFlag get_CR_HSERDY() const = 0;
		virtual HseClockBypass get_CR_HSEBYP() const = 0;
		virtual EnableFlag get_CR_CSSON() const = 0;
		virtual EnableFlag get_CR_PLLON() const = 0;
		virtual ReadyFlag get_CR_PLLRDY() const = 0;
		virtual EnableFlag get_CR_PLLI2SON() const = 0;
		virtual ReadyFlag get_CR_PLLI2SRDY() const = 0;
		virtual void set_CR_HSION(EnableFlag value) = 0;
		virtual void set_CR_HSITRIM(uint8_t value) = 0;
		virtual void set_CR_HSEON(EnableFlag value) = 0;
		virtual void set_CR_HSEBYP(HseClockBypass value) = 0;
		virtual void set_CR_CSSON(EnableFlag value) = 0;
		virtual void set_CR_PLLON(EnableFlag value) = 0;
		virtual void set_CR_PLLI2SON(EnableFlag value) = 0;

		// PLLCFGR Fields
		virtual uint8_t get_PLLCFGR_PLLM() const = 0;
		virtual uint16_t get_PLLCFGR_PLLN() const = 0;
		virtual MainPllDivisionFactor get_PLLCFGR_PLLP() const = 0;
		virtual MainPllAndAudioPllEntryClockSource get_PLLCFGR_PLLSRC() const = 0;
		virtual uint8_t get_PLLCFGR_PLLQ() const = 0;
		virtual void set_PLLCFGR_PLLM(uint8_t value) = 0;
		virtual void set_PLLCFGR_PLLN(uint16_t value) = 0;
		virtual void set_PLLCFGR_PLLP(MainPllDivisionFactor value) = 0;
		virtual void set_PLLCFGR_PLLSRC(MainPllAndAudioPllEntryClockSource value) = 0;
		virtual void set_PLLCFGR_PLLQ(uint8_t value) = 0;

		// CFGR Fields
		virtual SystemClock get_CFGR_SW() const = 0;
		virtual SystemClock get_CFGR_SWS() const = 0;
		virtual AhbPrescaler get_CFGR_HPRE() const = 0;
		virtual ApbPrescaler get_CFGR_PPRE1() const = 0;
		virtual ApbPrescaler get_CFGR_PPRE2() const = 0;
		virtual uint8_t get_CFGR_RTCPRE() const = 0;
		virtual MicrocontrollerClockOutput1 get_CFGR_MCO1() const = 0;
		virtual I2SClockSelection get_CFGR_I2SSCR() const = 0;
		virtual McoPrescaler get_CFGR_MCO1PRE() const = 0;
		virtual McoPrescaler get_CFGR_MCO2PRE() const = 0;
		virtual MicrocontrollerClockOutput2 get_CFGR_MCO2() const = 0;
		virtual void set_CFGR_SW(SystemClock value) = 0;
		virtual void set_CFGR_HPRE(AhbPrescaler value) = 0;
		virtual void set_CFGR_PPRE1(ApbPrescaler value) = 0;
		virtual void set_CFGR_PPRE2(ApbPrescaler value) = 0;
		virtual void set_CFGR_RTCPRE(uint8_t value) = 0;
		virtual void set_CFGR_MCO1(MicrocontrollerClockOutput1 value) = 0;
		virtual void set_CFGR_I2SSCR(I2SClockSelection value) = 0;
		virtual void set_CFGR_MCO1PRE(McoPrescaler value) = 0;
		virtual void set_CFGR_MCO2PRE(McoPrescaler value) = 0;
		virtual void set_CFGR_MCO2(MicrocontrollerClockOutput2 value) = 0;

		// CIR Fields
		virtual ReadyFlag get_CIR_LSIRDYF() const = 0;
		virtual ReadyFlag get_CIR_LSERDYF() const = 0;
		virtual ReadyFlag get_CIR_HSIRDYF() const = 0;
		virtual ReadyFlag get_CIR_HSERDYF() const = 0;
		virtual ReadyFlag get_CIR_PLLRDYF() const = 0;
		virtual ReadyFlag get_CIR_PLLI2SRDYF() const = 0;
		virtual ClockSecuritySystemInterruptFlag get_CIR_CSSF() const = 0;
		virtual EnableFlag get_CIR_LSIRDYIE() const = 0;
		virtual EnableFlag get_CIR_LSERDYIE() const = 0;
		virtual EnableFlag get_CIR_HSIRDYIE() const = 0;
		virtual EnableFlag get_CIR_HSERDYIE() const = 0;
		virtual EnableFlag get_CIR_PLLRDYIE() const = 0;
		virtual EnableFlag get_CIR_PLLI2SRDYIE() const = 0;
		virtual void set_CIR_LSIRDYIE(EnableFlag value) = 0;
		virtual void set_CIR_LSERDYIE(EnableFlag value) = 0;
		virtual void set_CIR_HSIRDYIE(EnableFlag value) = 0;
		virtual void set_CIR_HSERDYIE(EnableFlag value) = 0;
		virtual void set_CIR_PLLRDYIE(EnableFlag value) = 0;
		virtual void set_CIR_PLLI2SRDYIE(EnableFlag value) = 0;
		virtual void set_CIR_LSIRDYC(ClearFlag value) = 0;
		virtual void set_CIR_LSERDYC(ClearFlag value) = 0;
		virtual void set_CIR_HSIRDYC(ClearFlag value) = 0;
		virtual void set_CIR_HSERDYC(ClearFlag value) = 0;
		virtual void set_CIR_PLLRDYC(ClearFlag value) = 0;
		virtual void set_CIR_PLLI2SRDYC(ClearFlag value) = 0;
		virtual void set_CIR_CSSC(ClearFlag value) = 0;

		// AHB1RSTR Fields
		virtual ResetFlag get_AHB1RSTR_GPIOARST() const = 0;
		virtual ResetFlag get_AHB1RSTR_GPIOBRST() const = 0;
		virtual ResetFlag get_AHB1RSTR_GPIOCRST() const = 0;
		virtual ResetFlag get_AHB1RSTR_GPIODRST() const = 0;
		virtual ResetFlag get_AHB1RSTR_GPIOERST() const = 0;
		virtual ResetFlag get_AHB1RSTR_GPIOFRST() const = 0;
		virtual ResetFlag get_AHB1RSTR_GPIOGRST() const = 0;
		virtual ResetFlag get_AHB1RSTR_GPIOHRST() const = 0;
		virtual ResetFlag get_AHB1RSTR_GPIOIRST() const = 0;
		virtual ResetFlag get_AHB1RSTR_CRCRST() const = 0;
		virtual ResetFlag get_AHB1RSTR_DMA1RST() const = 0;
		virtual ResetFlag get_AHB1RSTR_DMA2RST() const = 0;
		virtual ResetFlag get_AHB1RSTR_ETHMACRST() const = 0;
		virtual ResetFlag get_AHB1RSTR_OTGHSRST() const = 0;
		virtual void set_AHB1RSTR_GPIOARST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_GPIOBRST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_GPIOCRST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_GPIODRST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_GPIOERST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_GPIOFRST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_GPIOGRST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_GPIOHRST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_GPIOIRST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_CRCRST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_DMA1RST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_DMA2RST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_ETHMACRST(ResetFlag value) = 0;
		virtual void set_AHB1RSTR_OTGHSRST(ResetFlag value) = 0;

		// AHB2RSTR Fields
		virtual ResetFlag get_AHB2RSTR_DCMIRST() const = 0;
		virtual ResetFlag get_AHB2RSTR_CRYPRST() const = 0;
		virtual ResetFlag get_AHB2RSTR_HASHRST() const = 0;
		virtual ResetFlag get_AHB2RSTR_RNGRST() const = 0;
		virtual ResetFlag get_AHB2RSTR_OTGFSRST() const = 0;
		virtual void set_AHB2RSTR_DCMIRST(ResetFlag value) = 0;
		virtual void set_AHB2RSTR_CRYPRST(ResetFlag value) = 0;
		virtual void set_AHB2RSTR_HASHRST(ResetFlag value) = 0;
		virtual void set_AHB2RSTR_RNGRST(ResetFlag value) = 0;
		virtual void set_AHB2RSTR_OTGFSRST(ResetFlag value) = 0;

		// AHB3RSTR Fields
		virtual ResetFlag get_AHB3RSTR_FSMCRST() const = 0;
		virtual void set_AHB3RSTR_FSMCRST(ResetFlag value) = 0;

		// Reserved1 Fields

		// APB1RSTR Fields
		virtual ResetFlag get_APB1RSTR_TIM2RST() const = 0;
		virtual ResetFlag get_APB1RSTR_TIM3RST() const = 0;
		virtual ResetFlag get_APB1RSTR_TIM4RST() const = 0;
		virtual ResetFlag get_APB1RSTR_TIM5RST() const = 0;
		virtual ResetFlag get_APB1RSTR_TIM6RST() const = 0;
		virtual ResetFlag get_APB1RSTR_TIM7RST() const = 0;
		virtual ResetFlag get_APB1RSTR_TIM12RST() const = 0;
		virtual ResetFlag get_APB1RSTR_TIM13RST() const = 0;
		virtual ResetFlag get_APB1RSTR_TIM14RST() const = 0;
		virtual ResetFlag get_APB1RSTR_WWDGRST() const = 0;
		virtual ResetFlag get_APB1RSTR_SPI2RST() const = 0;
		virtual ResetFlag get_APB1RSTR_SPI3RST() const = 0;
		virtual ResetFlag get_APB1RSTR_UART2RST() const = 0;
		virtual ResetFlag get_APB1RSTR_UART3RST() const = 0;
		virtual ResetFlag get_APB1RSTR_UART4RST() const = 0;
		virtual ResetFlag get_APB1RSTR_UART5RST() const = 0;
		virtual ResetFlag get_APB1RSTR_I2C1RST() const = 0;
		virtual ResetFlag get_APB1RSTR_I2C2RST() const = 0;
		virtual ResetFlag get_APB1RSTR_I2C3RST() const = 0;
		virtual ResetFlag get_APB1RSTR_CAN1RST() const = 0;
		virtual ResetFlag get_APB1RSTR_CAN2RST() const = 0;
		virtual ResetFlag get_APB1RSTR_PWRRST() const = 0;
		virtual ResetFlag get_APB1RSTR_DACRST() const = 0;
		virtual void set_APB1RSTR_TIM2RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_TIM3RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_TIM4RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_TIM5RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_TIM6RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_TIM7RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_TIM12RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_TIM13RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_TIM14RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_WWDGRST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_SPI2RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_SPI3RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_UART2RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_UART3RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_UART4RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_UART5RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_I2C1RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_I2C2RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_I2C3RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_CAN1RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_CAN2RST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_PWRRST(ResetFlag value) = 0;
		virtual void set_APB1RSTR_DACRST(ResetFlag value) = 0;

		// APB2RSTR Fields
		virtual ResetFlag get_APB2RSTR_TIM1RST() const = 0;
		virtual ResetFlag get_APB2RSTR_TIM8RST() const = 0;
		virtual ResetFlag get_APB2RSTR_USART1RST() const = 0;
		virtual ResetFlag get_APB2RSTR_USART6RST() const = 0;
		virtual ResetFlag get_APB2RSTR_ADCRST() const = 0;
		virtual ResetFlag get_APB2RSTR_SDIORST() const = 0;
		virtual ResetFlag get_APB2RSTR_SPI1RST() const = 0;
		virtual ResetFlag get_APB2RSTR_SYSCFGRST() const = 0;
		virtual ResetFlag get_APB2RSTR_TIM9RST() const = 0;
		virtual ResetFlag get_APB2RSTR_TIM10RST() const = 0;
		virtual ResetFlag get_APB2RSTR_TIM11RST() const = 0;
		virtual void set_APB2RSTR_TIM1RST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_TIM8RST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_USART1RST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_USART6RST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_ADCRST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_SDIORST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_SPI1RST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_SYSCFGRST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_TIM9RST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_TIM10RST(ResetFlag value) = 0;
		virtual void set_APB2RSTR_TIM11RST(ResetFlag value) = 0;

		// Reserved2 Fields

		// Reserved3 Fields

		// AHB1ENR Fields
		virtual EnableFlag get_AHB1ENR_GPIOAEN() const = 0;
		virtual EnableFlag get_AHB1ENR_GPIOBEN() const = 0;
		virtual EnableFlag get_AHB1ENR_GPIOCEN() const = 0;
		virtual EnableFlag get_AHB1ENR_GPIODEN() const = 0;
		virtual EnableFlag get_AHB1ENR_GPIOEEN() const = 0;
		virtual EnableFlag get_AHB1ENR_GPIOFEN() const = 0;
		virtual EnableFlag get_AHB1ENR_GPIOGEN() const = 0;
		virtual EnableFlag get_AHB1ENR_GPIOHEN() const = 0;
		virtual EnableFlag get_AHB1ENR_GPIOIEN() const = 0;
		virtual EnableFlag get_AHB1ENR_CRCEN() const = 0;
		virtual EnableFlag get_AHB1ENR_BKPSRAMEN() const = 0;
		virtual EnableFlag get_AHB1ENR_CCMDATARAMEN() const = 0;
		virtual EnableFlag get_AHB1ENR_DMA1EN() const = 0;
		virtual EnableFlag get_AHB1ENR_DMA2EN() const = 0;
		virtual EnableFlag get_AHB1ENR_ETHMACEN() const = 0;
		virtual EnableFlag get_AHB1ENR_ETHMACTXEN() const = 0;
		virtual EnableFlag get_AHB1ENR_ETHMACRXEN() const = 0;
		virtual EnableFlag get_AHB1ENR_ETHMACPTPEN() const = 0;
		virtual EnableFlag get_AHB1ENR_OTGHSEN() const = 0;
		virtual EnableFlag get_AHB1ENR_OTGHSULPIEN() const = 0;
		virtual void set_AHB1ENR_GPIOAEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_GPIOBEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_GPIOCEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_GPIODEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_GPIOEEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_GPIOFEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_GPIOGEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_GPIOHEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_GPIOIEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_CRCEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_BKPSRAMEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_CCMDATARAMEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_DMA1EN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_DMA2EN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_ETHMACEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_ETHMACTXEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_ETHMACRXEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_ETHMACPTPEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_OTGHSEN(EnableFlag value) = 0;
		virtual void set_AHB1ENR_OTGHSULPIEN(EnableFlag value) = 0;

		// AHB2ENR Fields
		virtual EnableFlag get_AHB2ENR_DCMIEN() const = 0;
		virtual EnableFlag get_AHB2ENR_CRYPEN() const = 0;
		virtual EnableFlag get_AHB2ENR_HASHEN() const = 0;
		virtual EnableFlag get_AHB2ENR_RNGEN() const = 0;
		virtual EnableFlag get_AHB2ENR_OTGFSEN() const = 0;
		virtual void set_AHB2ENR_DCMIEN(EnableFlag value) = 0;
		virtual void set_AHB2ENR_CRYPEN(EnableFlag value) = 0;
		virtual void set_AHB2ENR_HASHEN(EnableFlag value) = 0;
		virtual void set_AHB2ENR_RNGEN(EnableFlag value) = 0;
		virtual void set_AHB2ENR_OTGFSEN(EnableFlag value) = 0;

		// AHB3ENR Fields
		virtual EnableFlag get_AHB3ENR_FSMCEN() const = 0;
		virtual void set_AHB3ENR_FSMCEN(EnableFlag value) = 0;

		// Reserved4 Fields

		// APB1ENR Fields
		virtual EnableFlag get_APB1ENR_TIM2EN() const = 0;
		virtual EnableFlag get_APB1ENR_TIM3EN() const = 0;
		virtual EnableFlag get_APB1ENR_TIM4EN() const = 0;
		virtual EnableFlag get_APB1ENR_TIM5EN() const = 0;
		virtual EnableFlag get_APB1ENR_TIM6EN() const = 0;
		virtual EnableFlag get_APB1ENR_TIM7EN() const = 0;
		virtual EnableFlag get_APB1ENR_TIM12EN() const = 0;
		virtual EnableFlag get_APB1ENR_TIM13EN() const = 0;
		virtual EnableFlag get_APB1ENR_TIM14EN() const = 0;
		virtual EnableFlag get_APB1ENR_WWDGEN() const = 0;
		virtual EnableFlag get_APB1ENR_SPI2EN() const = 0;
		virtual EnableFlag get_APB1ENR_SPI3EN() const = 0;
		virtual EnableFlag get_APB1ENR_USART2EN() const = 0;
		virtual EnableFlag get_APB1ENR_USART3EN() const = 0;
		virtual EnableFlag get_APB1ENR_UART4EN() const = 0;
		virtual EnableFlag get_APB1ENR_UART5EN() const = 0;
		virtual EnableFlag get_APB1ENR_I2C1EN() const = 0;
		virtual EnableFlag get_APB1ENR_I2C2EN() const = 0;
		virtual EnableFlag get_APB1ENR_I2C3EN() const = 0;
		virtual EnableFlag get_APB1ENR_CAN1EN() const = 0;
		virtual EnableFlag get_APB1ENR_CAN2EN() const = 0;
		virtual EnableFlag get_APB1ENR_PWREN() const = 0;
		virtual EnableFlag get_APB1ENR_DACEN() const = 0;
		virtual void set_APB1ENR_TIM2EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_TIM3EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_TIM4EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_TIM5EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_TIM6EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_TIM7EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_TIM12EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_TIM13EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_TIM14EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_WWDGEN(EnableFlag value) = 0;
		virtual void set_APB1ENR_SPI2EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_SPI3EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_USART2EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_USART3EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_UART4EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_UART5EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_I2C1EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_I2C2EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_I2C3EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_CAN1EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_CAN2EN(EnableFlag value) = 0;
		virtual void set_APB1ENR_PWREN(EnableFlag value) = 0;
		virtual void set_APB1ENR_DACEN(EnableFlag value) = 0;

		// APB2ENR Fields
		virtual EnableFlag get_APB2ENR_TIM1EN() const = 0;
		virtual EnableFlag get_APB2ENR_TIM8EN() const = 0;
		virtual EnableFlag get_APB2ENR_USART1EN() const = 0;
		virtual EnableFlag get_APB2ENR_USART6EN() const = 0;
		virtual EnableFlag get_APB2ENR_ADC1EN() const = 0;
		virtual EnableFlag get_APB2ENR_ADC2EN() const = 0;
		virtual EnableFlag get_APB2ENR_ADC3EN() const = 0;
		virtual EnableFlag get_APB2ENR_SDIOEN() const = 0;
		virtual EnableFlag get_APB2ENR_SPI1EN() const = 0;
		virtual EnableFlag get_APB2ENR_SYSCFGEN() const = 0;
		virtual EnableFlag get_APB2ENR_TIM9EN() const = 0;
		virtual EnableFlag get_APB2ENR_TIM10EN() const = 0;
		virtual EnableFlag get_APB2ENR_TIM11EN() const = 0;
		virtual void set_APB2ENR_TIM1EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_TIM8EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_USART1EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_USART6EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_ADC1EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_ADC2EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_ADC3EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_SDIOEN(EnableFlag value) = 0;
		virtual void set_APB2ENR_SPI1EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_SYSCFGEN(EnableFlag value) = 0;
		virtual void set_APB2ENR_TIM9EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_TIM10EN(EnableFlag value) = 0;
		virtual void set_APB2ENR_TIM11EN(EnableFlag value) = 0;

		// Reserved5 Fields

		// Reserved6 Fields

		// AHB1LPENR Fields
		virtual EnableFlag get_AHB1LPENR_GPIOALPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_GPIOBLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_GPIOCLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_GPIODLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_GPIOELPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_GPIOFLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_GPIOGLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_GPIOHLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_GPIOILPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_CRCLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_FLITFLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_SRAM1LPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_SRAM2LPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_BKPSRAMLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_DMA1LPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_DMA2LPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_ETHMACLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_ETHMACTXLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_ETHMACRXLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_ETHMACPTPLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_OTGHSLPEN() const = 0;
		virtual EnableFlag get_AHB1LPENR_OTGHSULPILPEN() const = 0;
		virtual void set_AHB1LPENR_GPIOALPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_GPIOBLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_GPIOCLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_GPIODLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_GPIOELPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_GPIOFLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_GPIOGLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_GPIOHLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_GPIOILPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_CRCLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_FLITFLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_SRAM1LPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_SRAM2LPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_BKPSRAMLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_DMA1LPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_DMA2LPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_ETHMACLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_ETHMACTXLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_ETHMACRXLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_ETHMACPTPLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_OTGHSLPEN(EnableFlag value) = 0;
		virtual void set_AHB1LPENR_OTGHSULPILPEN(EnableFlag value) = 0;

		// AHB2LPENR Fields
		virtual EnableFlag get_AHB2LPENR_DCMILPEN() const = 0;
		virtual EnableFlag get_AHB2LPENR_CRYPLPEN() const = 0;
		virtual EnableFlag get_AHB2LPENR_HASHLPEN() const = 0;
		virtual EnableFlag get_AHB2LPENR_RNGLPEN() const = 0;
		virtual EnableFlag get_AHB2LPENR_OTGFSLPEN() const = 0;
		virtual void set_AHB2LPENR_DCMILPEN(EnableFlag value) = 0;
		virtual void set_AHB2LPENR_CRYPLPEN(EnableFlag value) = 0;
		virtual void set_AHB2LPENR_HASHLPEN(EnableFlag value) = 0;
		virtual void set_AHB2LPENR_RNGLPEN(EnableFlag value) = 0;
		virtual void set_AHB2LPENR_OTGFSLPEN(EnableFlag value) = 0;

		// AHB3LPENR Fields
		virtual EnableFlag get_AHB3LPENR_FSMCLPEN() const = 0;
		virtual void set_AHB3LPENR_FSMCLPEN(EnableFlag value) = 0;

		// Reserved7 Fields

		// APB1LPENR Fields
		virtual EnableFlag get_APB1LPENR_TIM2LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_TIM3LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_TIM4LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_TIM5LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_TIM6LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_TIM7LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_TIM12LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_TIM13LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_TIM14LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_WWDGLPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_SPI2LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_SPI3LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_USART2LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_USART3LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_UART4LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_UART5LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_I2C1LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_I2C2LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_I2C3LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_CAN1LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_CAN2LPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_PWRLPEN() const = 0;
		virtual EnableFlag get_APB1LPENR_DACLPEN() const = 0;
		virtual void set_APB1LPENR_TIM2LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_TIM3LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_TIM4LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_TIM5LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_TIM6LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_TIM7LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_TIM12LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_TIM13LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_TIM14LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_WWDGLPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_SPI2LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_SPI3LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_USART2LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_USART3LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_UART4LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_UART5LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_I2C1LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_I2C2LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_I2C3LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_CAN1LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_CAN2LPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_PWRLPEN(EnableFlag value) = 0;
		virtual void set_APB1LPENR_DACLPEN(EnableFlag value) = 0;

		// APB2LPENR Fields
		virtual EnableFlag get_APB2LPENR_TIM1LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_TIM8LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_USART1LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_USART6LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_ADC1LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_ADC2LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_ADC3LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_SDIOLPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_SPI1LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_SYSCFGLPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_TIM9LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_TIM10LPEN() const = 0;
		virtual EnableFlag get_APB2LPENR_TIM11LPEN() const = 0;
		virtual void set_APB2LPENR_TIM1LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_TIM8LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_USART1LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_USART6LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_ADC1LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_ADC2LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_ADC3LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_SDIOLPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_SPI1LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_SYSCFGLPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_TIM9LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_TIM10LPEN(EnableFlag value) = 0;
		virtual void set_APB2LPENR_TIM11LPEN(EnableFlag value) = 0;

		// Reserved8 Fields

		// Reserved9 Fields

		// BDCR Fields
		virtual EnableFlag get_BDCR_LSEON() const = 0;
		virtual ReadyFlag get_BDCR_LSERDY() const = 0;
		virtual ExternalLowSpeedOscillatorBypass get_BDCR_LSEBYP() const = 0;
		virtual RtcClockSourceSelection get_BDCR_RTCSEL() const = 0;
		virtual EnableFlag get_BDCR_RTCEN() const = 0;
		virtual ResetFlag get_BDCR_BDRST() const = 0;
		virtual void set_BDCR_LSEON(EnableFlag value) = 0;
		virtual void set_BDCR_LSEBYP(ExternalLowSpeedOscillatorBypass value) = 0;
		virtual void set_BDCR_RTCSEL(RtcClockSourceSelection value) = 0;
		virtual void set_BDCR_RTCEN(EnableFlag value) = 0;
		virtual void set_BDCR_BDRST(ResetFlag value) = 0;

		// CSR Fields
		virtual EnableFlag get_CSR_LSION() const = 0;
		virtual ReadyFlag get_CSR_LSIRDY() const = 0;
		virtual ClearFlag get_CSR_RMVF() const = 0;
		virtual ResetOccurredFlag get_CSR_BORRSTF() const = 0;
		virtual ResetOccurredFlag get_CSR_PINRSTF() const = 0;
		virtual ResetOccurredFlag get_CSR_PORRSTF() const = 0;
		virtual ResetOccurredFlag get_CSR_SFTRSTF() const = 0;
		virtual ResetOccurredFlag get_CSR_IWDGRSTF() const = 0;
		virtual ResetOccurredFlag get_CSR_WWDGRSTF() const = 0;
		virtual ResetOccurredFlag get_CSR_LPWRRSTF() const = 0;
		virtual void set_CSR_LSION(EnableFlag value) = 0;
		virtual void set_CSR_RMVF(ClearFlag value) = 0;

		// Reserved10 Fields

		// Reserved11 Fields

		// SSCGR Fields
		virtual uint16_t get_SSCGR_MODPER() const = 0;
		virtual uint16_t get_SSCGR_INCSTEP() const = 0;
		virtual SpreadSelect get_SSCGR_SPREADSEL() const = 0;
		virtual EnableFlag get_SSCGR_SSCGEN() const = 0;
		virtual void set_SSCGR_MODPER(uint16_t value) = 0;
		virtual void set_SSCGR_INCSTEP(uint16_t value) = 0;
		virtual void set_SSCGR_SPREADSEL(SpreadSelect value) = 0;
		virtual void set_SSCGR_SSCGEN(EnableFlag value) = 0;

		// PLLI2SCFGR Fields
		virtual uint16_t get_PLLI2SCFGR_PLLI2SN() const = 0;
		virtual uint8_t get_PLLI2SCFGR_PLLI2SR() const = 0;
		virtual void set_PLLI2SCFGR_PLLI2SN(uint16_t value) = 0;
		virtual void set_PLLI2SCFGR_PLLI2SR(uint8_t value) = 0;
	};

	class RccRegisterMap : public IRccRegisterMap
	{
	public:

		// CR Fields
		EnableFlag get_CR_HSION() const override { return CR.Fields.HSION; }
		ReadyFlag get_CR_HSIRDY() const override { return CR.Fields.HSIRDY; }
		uint8_t get_CR_HSITRIM() const override { return CR.Fields.HSITRIM; }
		uint8_t get_CR_HSICAL() const override { return CR.Fields.HSICAL; }
		EnableFlag get_CR_HSEON() const override { return CR.Fields.HSEON; }
		ReadyFlag get_CR_HSERDY() const override { return CR.Fields.HSERDY; }
		HseClockBypass get_CR_HSEBYP() const override { return CR.Fields.HSEBYP; }
		EnableFlag get_CR_CSSON() const override { return CR.Fields.CSSON; }
		EnableFlag get_CR_PLLON() const override { return CR.Fields.PLLON; }
		ReadyFlag get_CR_PLLRDY() const override { return CR.Fields.PLLRDY; }
		EnableFlag get_CR_PLLI2SON() const override { return CR.Fields.PLLI2SON; }
		ReadyFlag get_CR_PLLI2SRDY() const override { return CR.Fields.PLLI2SRDY; }
		void set_CR_HSION(EnableFlag value) override { CR.Fields.HSION = value; }
		void set_CR_HSITRIM(uint8_t value) override { CR.Fields.HSITRIM = value; }
		void set_CR_HSEON(EnableFlag value) override { CR.Fields.HSEON = value; }
		void set_CR_HSEBYP(HseClockBypass value) override { CR.Fields.HSEBYP = value; }
		void set_CR_CSSON(EnableFlag value) override { CR.Fields.CSSON = value; }
		void set_CR_PLLON(EnableFlag value) override { CR.Fields.PLLON = value; }
		void set_CR_PLLI2SON(EnableFlag value) override { CR.Fields.PLLI2SON = value; }

		// PLLCFGR Fields
		uint8_t get_PLLCFGR_PLLM() const override { return PLLCFGR.Fields.PLLM; }
		uint16_t get_PLLCFGR_PLLN() const override { return PLLCFGR.Fields.PLLN; }
		MainPllDivisionFactor get_PLLCFGR_PLLP() const override { return PLLCFGR.Fields.PLLP; }
		MainPllAndAudioPllEntryClockSource get_PLLCFGR_PLLSRC() const override { return PLLCFGR.Fields.PLLSRC; }
		uint8_t get_PLLCFGR_PLLQ() const override { return PLLCFGR.Fields.PLLQ; }
		void set_PLLCFGR_PLLM(uint8_t value) override { PLLCFGR.Fields.PLLM = value; }
		void set_PLLCFGR_PLLN(uint16_t value) override { PLLCFGR.Fields.PLLN = value; }
		void set_PLLCFGR_PLLP(MainPllDivisionFactor value) override { PLLCFGR.Fields.PLLP = value; }
		void set_PLLCFGR_PLLSRC(MainPllAndAudioPllEntryClockSource value) override { PLLCFGR.Fields.PLLSRC = value; }
		void set_PLLCFGR_PLLQ(uint8_t value) override { PLLCFGR.Fields.PLLQ = value; }

		// CFGR Fields
		SystemClock get_CFGR_SW() const override { return CFGR.Fields.SW; }
		SystemClock get_CFGR_SWS() const override { return CFGR.Fields.SWS; }
		AhbPrescaler get_CFGR_HPRE() const override { return CFGR.Fields.HPRE; }
		ApbPrescaler get_CFGR_PPRE1() const override { return CFGR.Fields.PPRE1; }
		ApbPrescaler get_CFGR_PPRE2() const override { return CFGR.Fields.PPRE2; }
		uint8_t get_CFGR_RTCPRE() const override { return CFGR.Fields.RTCPRE; }
		MicrocontrollerClockOutput1 get_CFGR_MCO1() const override { return CFGR.Fields.MCO1; }
		I2SClockSelection get_CFGR_I2SSCR() const override { return CFGR.Fields.I2SSCR; }
		McoPrescaler get_CFGR_MCO1PRE() const override { return CFGR.Fields.MCO1PRE; }
		McoPrescaler get_CFGR_MCO2PRE() const override { return CFGR.Fields.MCO2PRE; }
		MicrocontrollerClockOutput2 get_CFGR_MCO2() const override { return CFGR.Fields.MCO2; }
		void set_CFGR_SW(SystemClock value) override { CFGR.Fields.SW = value; }
		void set_CFGR_HPRE(AhbPrescaler value) override { CFGR.Fields.HPRE = value; }
		void set_CFGR_PPRE1(ApbPrescaler value) override { CFGR.Fields.PPRE1 = value; }
		void set_CFGR_PPRE2(ApbPrescaler value) override { CFGR.Fields.PPRE2 = value; }
		void set_CFGR_RTCPRE(uint8_t value) override { CFGR.Fields.RTCPRE = value; }
		void set_CFGR_MCO1(MicrocontrollerClockOutput1 value) override { CFGR.Fields.MCO1 = value; }
		void set_CFGR_I2SSCR(I2SClockSelection value) override { CFGR.Fields.I2SSCR = value; }
		void set_CFGR_MCO1PRE(McoPrescaler value) override { CFGR.Fields.MCO1PRE = value; }
		void set_CFGR_MCO2PRE(McoPrescaler value) override { CFGR.Fields.MCO2PRE = value; }
		void set_CFGR_MCO2(MicrocontrollerClockOutput2 value) override { CFGR.Fields.MCO2 = value; }

		// CIR Fields
		ReadyFlag get_CIR_LSIRDYF() const override { return CIR.Fields.LSIRDYF; }
		ReadyFlag get_CIR_LSERDYF() const override { return CIR.Fields.LSERDYF; }
		ReadyFlag get_CIR_HSIRDYF() const override { return CIR.Fields.HSIRDYF; }
		ReadyFlag get_CIR_HSERDYF() const override { return CIR.Fields.HSERDYF; }
		ReadyFlag get_CIR_PLLRDYF() const override { return CIR.Fields.PLLRDYF; }
		ReadyFlag get_CIR_PLLI2SRDYF() const override { return CIR.Fields.PLLI2SRDYF; }
		ClockSecuritySystemInterruptFlag get_CIR_CSSF() const override { return CIR.Fields.CSSF; }
		EnableFlag get_CIR_LSIRDYIE() const override { return CIR.Fields.LSIRDYIE; }
		EnableFlag get_CIR_LSERDYIE() const override { return CIR.Fields.LSERDYIE; }
		EnableFlag get_CIR_HSIRDYIE() const override { return CIR.Fields.HSIRDYIE; }
		EnableFlag get_CIR_HSERDYIE() const override { return CIR.Fields.HSERDYIE; }
		EnableFlag get_CIR_PLLRDYIE() const override { return CIR.Fields.PLLRDYIE; }
		EnableFlag get_CIR_PLLI2SRDYIE() const override { return CIR.Fields.PLLI2SRDYIE; }
		void set_CIR_LSIRDYIE(EnableFlag value) override { CIR.Fields.LSIRDYIE = value; }
		void set_CIR_LSERDYIE(EnableFlag value) override { CIR.Fields.LSERDYIE = value; }
		void set_CIR_HSIRDYIE(EnableFlag value) override { CIR.Fields.HSIRDYIE = value; }
		void set_CIR_HSERDYIE(EnableFlag value) override { CIR.Fields.HSERDYIE = value; }
		void set_CIR_PLLRDYIE(EnableFlag value) override { CIR.Fields.PLLRDYIE = value; }
		void set_CIR_PLLI2SRDYIE(EnableFlag value) override { CIR.Fields.PLLI2SRDYIE = value; }
		void set_CIR_LSIRDYC(ClearFlag value) override { CIR.Fields.LSIRDYC = value; }
		void set_CIR_LSERDYC(ClearFlag value) override { CIR.Fields.LSERDYC = value; }
		void set_CIR_HSIRDYC(ClearFlag value) override { CIR.Fields.HSIRDYC = value; }
		void set_CIR_HSERDYC(ClearFlag value) override { CIR.Fields.HSERDYC = value; }
		void set_CIR_PLLRDYC(ClearFlag value) override { CIR.Fields.PLLRDYC = value; }
		void set_CIR_PLLI2SRDYC(ClearFlag value) override { CIR.Fields.PLLI2SRDYC = value; }
		void set_CIR_CSSC(ClearFlag value) override { CIR.Fields.CSSC = value; }

		// AHB1RSTR Fields
		ResetFlag get_AHB1RSTR_GPIOARST() const override { return AHB1RSTR.Fields.GPIOARST; }
		ResetFlag get_AHB1RSTR_GPIOBRST() const override { return AHB1RSTR.Fields.GPIOBRST; }
		ResetFlag get_AHB1RSTR_GPIOCRST() const override { return AHB1RSTR.Fields.GPIOCRST; }
		ResetFlag get_AHB1RSTR_GPIODRST() const override { return AHB1RSTR.Fields.GPIODRST; }
		ResetFlag get_AHB1RSTR_GPIOERST() const override { return AHB1RSTR.Fields.GPIOERST; }
		ResetFlag get_AHB1RSTR_GPIOFRST() const override { return AHB1RSTR.Fields.GPIOFRST; }
		ResetFlag get_AHB1RSTR_GPIOGRST() const override { return AHB1RSTR.Fields.GPIOGRST; }
		ResetFlag get_AHB1RSTR_GPIOHRST() const override { return AHB1RSTR.Fields.GPIOHRST; }
		ResetFlag get_AHB1RSTR_GPIOIRST() const override { return AHB1RSTR.Fields.GPIOIRST; }
		ResetFlag get_AHB1RSTR_CRCRST() const override { return AHB1RSTR.Fields.CRCRST; }
		ResetFlag get_AHB1RSTR_DMA1RST() const override { return AHB1RSTR.Fields.DMA1RST; }
		ResetFlag get_AHB1RSTR_DMA2RST() const override { return AHB1RSTR.Fields.DMA2RST; }
		ResetFlag get_AHB1RSTR_ETHMACRST() const override { return AHB1RSTR.Fields.ETHMACRST; }
		ResetFlag get_AHB1RSTR_OTGHSRST() const override { return AHB1RSTR.Fields.OTGHSRST; }
		void set_AHB1RSTR_GPIOARST(ResetFlag value) override { AHB1RSTR.Fields.GPIOARST = value; }
		void set_AHB1RSTR_GPIOBRST(ResetFlag value) override { AHB1RSTR.Fields.GPIOBRST = value; }
		void set_AHB1RSTR_GPIOCRST(ResetFlag value) override { AHB1RSTR.Fields.GPIOCRST = value; }
		void set_AHB1RSTR_GPIODRST(ResetFlag value) override { AHB1RSTR.Fields.GPIODRST = value; }
		void set_AHB1RSTR_GPIOERST(ResetFlag value) override { AHB1RSTR.Fields.GPIOERST = value; }
		void set_AHB1RSTR_GPIOFRST(ResetFlag value) override { AHB1RSTR.Fields.GPIOFRST = value; }
		void set_AHB1RSTR_GPIOGRST(ResetFlag value) override { AHB1RSTR.Fields.GPIOGRST = value; }
		void set_AHB1RSTR_GPIOHRST(ResetFlag value) override { AHB1RSTR.Fields.GPIOHRST = value; }
		void set_AHB1RSTR_GPIOIRST(ResetFlag value) override { AHB1RSTR.Fields.GPIOIRST = value; }
		void set_AHB1RSTR_CRCRST(ResetFlag value) override { AHB1RSTR.Fields.CRCRST = value; }
		void set_AHB1RSTR_DMA1RST(ResetFlag value) override { AHB1RSTR.Fields.DMA1RST = value; }
		void set_AHB1RSTR_DMA2RST(ResetFlag value) override { AHB1RSTR.Fields.DMA2RST = value; }
		void set_AHB1RSTR_ETHMACRST(ResetFlag value) override { AHB1RSTR.Fields.ETHMACRST = value; }
		void set_AHB1RSTR_OTGHSRST(ResetFlag value) override { AHB1RSTR.Fields.OTGHSRST = value; }

		// AHB2RSTR Fields
		ResetFlag get_AHB2RSTR_DCMIRST() const override { return AHB2RSTR.Fields.DCMIRST; }
		ResetFlag get_AHB2RSTR_CRYPRST() const override { return AHB2RSTR.Fields.CRYPRST; }
		ResetFlag get_AHB2RSTR_HASHRST() const override { return AHB2RSTR.Fields.HASHRST; }
		ResetFlag get_AHB2RSTR_RNGRST() const override { return AHB2RSTR.Fields.RNGRST; }
		ResetFlag get_AHB2RSTR_OTGFSRST() const override { return AHB2RSTR.Fields.OTGFSRST; }
		void set_AHB2RSTR_DCMIRST(ResetFlag value) override { AHB2RSTR.Fields.DCMIRST = value; }
		void set_AHB2RSTR_CRYPRST(ResetFlag value) override { AHB2RSTR.Fields.CRYPRST = value; }
		void set_AHB2RSTR_HASHRST(ResetFlag value) override { AHB2RSTR.Fields.HASHRST = value; }
		void set_AHB2RSTR_RNGRST(ResetFlag value) override { AHB2RSTR.Fields.RNGRST = value; }
		void set_AHB2RSTR_OTGFSRST(ResetFlag value) override { AHB2RSTR.Fields.OTGFSRST = value; }

		// AHB3RSTR Fields
		ResetFlag get_AHB3RSTR_FSMCRST() const override { return AHB3RSTR.Fields.FSMCRST; }
		void set_AHB3RSTR_FSMCRST(ResetFlag value) override { AHB3RSTR.Fields.FSMCRST = value; }

		// Reserved1 Fields

		// APB1RSTR Fields
		ResetFlag get_APB1RSTR_TIM2RST() const override { return APB1RSTR.Fields.TIM2RST; }
		ResetFlag get_APB1RSTR_TIM3RST() const override { return APB1RSTR.Fields.TIM3RST; }
		ResetFlag get_APB1RSTR_TIM4RST() const override { return APB1RSTR.Fields.TIM4RST; }
		ResetFlag get_APB1RSTR_TIM5RST() const override { return APB1RSTR.Fields.TIM5RST; }
		ResetFlag get_APB1RSTR_TIM6RST() const override { return APB1RSTR.Fields.TIM6RST; }
		ResetFlag get_APB1RSTR_TIM7RST() const override { return APB1RSTR.Fields.TIM7RST; }
		ResetFlag get_APB1RSTR_TIM12RST() const override { return APB1RSTR.Fields.TIM12RST; }
		ResetFlag get_APB1RSTR_TIM13RST() const override { return APB1RSTR.Fields.TIM13RST; }
		ResetFlag get_APB1RSTR_TIM14RST() const override { return APB1RSTR.Fields.TIM14RST; }
		ResetFlag get_APB1RSTR_WWDGRST() const override { return APB1RSTR.Fields.WWDGRST; }
		ResetFlag get_APB1RSTR_SPI2RST() const override { return APB1RSTR.Fields.SPI2RST; }
		ResetFlag get_APB1RSTR_SPI3RST() const override { return APB1RSTR.Fields.SPI3RST; }
		ResetFlag get_APB1RSTR_UART2RST() const override { return APB1RSTR.Fields.UART2RST; }
		ResetFlag get_APB1RSTR_UART3RST() const override { return APB1RSTR.Fields.UART3RST; }
		ResetFlag get_APB1RSTR_UART4RST() const override { return APB1RSTR.Fields.UART4RST; }
		ResetFlag get_APB1RSTR_UART5RST() const override { return APB1RSTR.Fields.UART5RST; }
		ResetFlag get_APB1RSTR_I2C1RST() const override { return APB1RSTR.Fields.I2C1RST; }
		ResetFlag get_APB1RSTR_I2C2RST() const override { return APB1RSTR.Fields.I2C2RST; }
		ResetFlag get_APB1RSTR_I2C3RST() const override { return APB1RSTR.Fields.I2C3RST; }
		ResetFlag get_APB1RSTR_CAN1RST() const override { return APB1RSTR.Fields.CAN1RST; }
		ResetFlag get_APB1RSTR_CAN2RST() const override { return APB1RSTR.Fields.CAN2RST; }
		ResetFlag get_APB1RSTR_PWRRST() const override { return APB1RSTR.Fields.PWRRST; }
		ResetFlag get_APB1RSTR_DACRST() const override { return APB1RSTR.Fields.DACRST; }
		void set_APB1RSTR_TIM2RST(ResetFlag value) override { APB1RSTR.Fields.TIM2RST = value; }
		void set_APB1RSTR_TIM3RST(ResetFlag value) override { APB1RSTR.Fields.TIM3RST = value; }
		void set_APB1RSTR_TIM4RST(ResetFlag value) override { APB1RSTR.Fields.TIM4RST = value; }
		void set_APB1RSTR_TIM5RST(ResetFlag value) override { APB1RSTR.Fields.TIM5RST = value; }
		void set_APB1RSTR_TIM6RST(ResetFlag value) override { APB1RSTR.Fields.TIM6RST = value; }
		void set_APB1RSTR_TIM7RST(ResetFlag value) override { APB1RSTR.Fields.TIM7RST = value; }
		void set_APB1RSTR_TIM12RST(ResetFlag value) override { APB1RSTR.Fields.TIM12RST = value; }
		void set_APB1RSTR_TIM13RST(ResetFlag value) override { APB1RSTR.Fields.TIM13RST = value; }
		void set_APB1RSTR_TIM14RST(ResetFlag value) override { APB1RSTR.Fields.TIM14RST = value; }
		void set_APB1RSTR_WWDGRST(ResetFlag value) override { APB1RSTR.Fields.WWDGRST = value; }
		void set_APB1RSTR_SPI2RST(ResetFlag value) override { APB1RSTR.Fields.SPI2RST = value; }
		void set_APB1RSTR_SPI3RST(ResetFlag value) override { APB1RSTR.Fields.SPI3RST = value; }
		void set_APB1RSTR_UART2RST(ResetFlag value) override { APB1RSTR.Fields.UART2RST = value; }
		void set_APB1RSTR_UART3RST(ResetFlag value) override { APB1RSTR.Fields.UART3RST = value; }
		void set_APB1RSTR_UART4RST(ResetFlag value) override { APB1RSTR.Fields.UART4RST = value; }
		void set_APB1RSTR_UART5RST(ResetFlag value) override { APB1RSTR.Fields.UART5RST = value; }
		void set_APB1RSTR_I2C1RST(ResetFlag value) override { APB1RSTR.Fields.I2C1RST = value; }
		void set_APB1RSTR_I2C2RST(ResetFlag value) override { APB1RSTR.Fields.I2C2RST = value; }
		void set_APB1RSTR_I2C3RST(ResetFlag value) override { APB1RSTR.Fields.I2C3RST = value; }
		void set_APB1RSTR_CAN1RST(ResetFlag value) override { APB1RSTR.Fields.CAN1RST = value; }
		void set_APB1RSTR_CAN2RST(ResetFlag value) override { APB1RSTR.Fields.CAN2RST = value; }
		void set_APB1RSTR_PWRRST(ResetFlag value) override { APB1RSTR.Fields.PWRRST = value; }
		void set_APB1RSTR_DACRST(ResetFlag value) override { APB1RSTR.Fields.DACRST = value; }

		// APB2RSTR Fields
		ResetFlag get_APB2RSTR_TIM1RST() const override { return APB2RSTR.Fields.TIM1RST; }
		ResetFlag get_APB2RSTR_TIM8RST() const override { return APB2RSTR.Fields.TIM8RST; }
		ResetFlag get_APB2RSTR_USART1RST() const override { return APB2RSTR.Fields.USART1RST; }
		ResetFlag get_APB2RSTR_USART6RST() const override { return APB2RSTR.Fields.USART6RST; }
		ResetFlag get_APB2RSTR_ADCRST() const override { return APB2RSTR.Fields.ADCRST; }
		ResetFlag get_APB2RSTR_SDIORST() const override { return APB2RSTR.Fields.SDIORST; }
		ResetFlag get_APB2RSTR_SPI1RST() const override { return APB2RSTR.Fields.SPI1RST; }
		ResetFlag get_APB2RSTR_SYSCFGRST() const override { return APB2RSTR.Fields.SYSCFGRST; }
		ResetFlag get_APB2RSTR_TIM9RST() const override { return APB2RSTR.Fields.TIM9RST; }
		ResetFlag get_APB2RSTR_TIM10RST() const override { return APB2RSTR.Fields.TIM10RST; }
		ResetFlag get_APB2RSTR_TIM11RST() const override { return APB2RSTR.Fields.TIM11RST; }
		void set_APB2RSTR_TIM1RST(ResetFlag value) override { APB2RSTR.Fields.TIM1RST = value; }
		void set_APB2RSTR_TIM8RST(ResetFlag value) override { APB2RSTR.Fields.TIM8RST = value; }
		void set_APB2RSTR_USART1RST(ResetFlag value) override { APB2RSTR.Fields.USART1RST = value; }
		void set_APB2RSTR_USART6RST(ResetFlag value) override { APB2RSTR.Fields.USART6RST = value; }
		void set_APB2RSTR_ADCRST(ResetFlag value) override { APB2RSTR.Fields.ADCRST = value; }
		void set_APB2RSTR_SDIORST(ResetFlag value) override { APB2RSTR.Fields.SDIORST = value; }
		void set_APB2RSTR_SPI1RST(ResetFlag value) override { APB2RSTR.Fields.SPI1RST = value; }
		void set_APB2RSTR_SYSCFGRST(ResetFlag value) override { APB2RSTR.Fields.SYSCFGRST = value; }
		void set_APB2RSTR_TIM9RST(ResetFlag value) override { APB2RSTR.Fields.TIM9RST = value; }
		void set_APB2RSTR_TIM10RST(ResetFlag value) override { APB2RSTR.Fields.TIM10RST = value; }
		void set_APB2RSTR_TIM11RST(ResetFlag value) override { APB2RSTR.Fields.TIM11RST = value; }

		// Reserved2 Fields

		// Reserved3 Fields

		// AHB1ENR Fields
		EnableFlag get_AHB1ENR_GPIOAEN() const override { return AHB1ENR.Fields.GPIOAEN; }
		EnableFlag get_AHB1ENR_GPIOBEN() const override { return AHB1ENR.Fields.GPIOBEN; }
		EnableFlag get_AHB1ENR_GPIOCEN() const override { return AHB1ENR.Fields.GPIOCEN; }
		EnableFlag get_AHB1ENR_GPIODEN() const override { return AHB1ENR.Fields.GPIODEN; }
		EnableFlag get_AHB1ENR_GPIOEEN() const override { return AHB1ENR.Fields.GPIOEEN; }
		EnableFlag get_AHB1ENR_GPIOFEN() const override { return AHB1ENR.Fields.GPIOFEN; }
		EnableFlag get_AHB1ENR_GPIOGEN() const override { return AHB1ENR.Fields.GPIOGEN; }
		EnableFlag get_AHB1ENR_GPIOHEN() const override { return AHB1ENR.Fields.GPIOHEN; }
		EnableFlag get_AHB1ENR_GPIOIEN() const override { return AHB1ENR.Fields.GPIOIEN; }
		EnableFlag get_AHB1ENR_CRCEN() const override { return AHB1ENR.Fields.CRCEN; }
		EnableFlag get_AHB1ENR_BKPSRAMEN() const override { return AHB1ENR.Fields.BKPSRAMEN; }
		EnableFlag get_AHB1ENR_CCMDATARAMEN() const override { return AHB1ENR.Fields.CCMDATARAMEN; }
		EnableFlag get_AHB1ENR_DMA1EN() const override { return AHB1ENR.Fields.DMA1EN; }
		EnableFlag get_AHB1ENR_DMA2EN() const override { return AHB1ENR.Fields.DMA2EN; }
		EnableFlag get_AHB1ENR_ETHMACEN() const override { return AHB1ENR.Fields.ETHMACEN; }
		EnableFlag get_AHB1ENR_ETHMACTXEN() const override { return AHB1ENR.Fields.ETHMACTXEN; }
		EnableFlag get_AHB1ENR_ETHMACRXEN() const override { return AHB1ENR.Fields.ETHMACRXEN; }
		EnableFlag get_AHB1ENR_ETHMACPTPEN() const override { return AHB1ENR.Fields.ETHMACPTPEN; }
		EnableFlag get_AHB1ENR_OTGHSEN() const override { return AHB1ENR.Fields.OTGHSEN; }
		EnableFlag get_AHB1ENR_OTGHSULPIEN() const override { return AHB1ENR.Fields.OTGHSULPIEN; }
		void set_AHB1ENR_GPIOAEN(EnableFlag value) override { AHB1ENR.Fields.GPIOAEN = value; }
		void set_AHB1ENR_GPIOBEN(EnableFlag value) override { AHB1ENR.Fields.GPIOBEN = value; }
		void set_AHB1ENR_GPIOCEN(EnableFlag value) override { AHB1ENR.Fields.GPIOCEN = value; }
		void set_AHB1ENR_GPIODEN(EnableFlag value) override { AHB1ENR.Fields.GPIODEN = value; }
		void set_AHB1ENR_GPIOEEN(EnableFlag value) override { AHB1ENR.Fields.GPIOEEN = value; }
		void set_AHB1ENR_GPIOFEN(EnableFlag value) override { AHB1ENR.Fields.GPIOFEN = value; }
		void set_AHB1ENR_GPIOGEN(EnableFlag value) override { AHB1ENR.Fields.GPIOGEN = value; }
		void set_AHB1ENR_GPIOHEN(EnableFlag value) override { AHB1ENR.Fields.GPIOHEN = value; }
		void set_AHB1ENR_GPIOIEN(EnableFlag value) override { AHB1ENR.Fields.GPIOIEN = value; }
		void set_AHB1ENR_CRCEN(EnableFlag value) override { AHB1ENR.Fields.CRCEN = value; }
		void set_AHB1ENR_BKPSRAMEN(EnableFlag value) override { AHB1ENR.Fields.BKPSRAMEN = value; }
		void set_AHB1ENR_CCMDATARAMEN(EnableFlag value) override { AHB1ENR.Fields.CCMDATARAMEN = value; }
		void set_AHB1ENR_DMA1EN(EnableFlag value) override { AHB1ENR.Fields.DMA1EN = value; }
		void set_AHB1ENR_DMA2EN(EnableFlag value) override { AHB1ENR.Fields.DMA2EN = value; }
		void set_AHB1ENR_ETHMACEN(EnableFlag value) override { AHB1ENR.Fields.ETHMACEN = value; }
		void set_AHB1ENR_ETHMACTXEN(EnableFlag value) override { AHB1ENR.Fields.ETHMACTXEN = value; }
		void set_AHB1ENR_ETHMACRXEN(EnableFlag value) override { AHB1ENR.Fields.ETHMACRXEN = value; }
		void set_AHB1ENR_ETHMACPTPEN(EnableFlag value) override { AHB1ENR.Fields.ETHMACPTPEN = value; }
		void set_AHB1ENR_OTGHSEN(EnableFlag value) override { AHB1ENR.Fields.OTGHSEN = value; }
		void set_AHB1ENR_OTGHSULPIEN(EnableFlag value) override { AHB1ENR.Fields.OTGHSULPIEN = value; }

		// AHB2ENR Fields
		EnableFlag get_AHB2ENR_DCMIEN() const override { return AHB2ENR.Fields.DCMIEN; }
		EnableFlag get_AHB2ENR_CRYPEN() const override { return AHB2ENR.Fields.CRYPEN; }
		EnableFlag get_AHB2ENR_HASHEN() const override { return AHB2ENR.Fields.HASHEN; }
		EnableFlag get_AHB2ENR_RNGEN() const override { return AHB2ENR.Fields.RNGEN; }
		EnableFlag get_AHB2ENR_OTGFSEN() const override { return AHB2ENR.Fields.OTGFSEN; }
		void set_AHB2ENR_DCMIEN(EnableFlag value) override { AHB2ENR.Fields.DCMIEN = value; }
		void set_AHB2ENR_CRYPEN(EnableFlag value) override { AHB2ENR.Fields.CRYPEN = value; }
		void set_AHB2ENR_HASHEN(EnableFlag value) override { AHB2ENR.Fields.HASHEN = value; }
		void set_AHB2ENR_RNGEN(EnableFlag value) override { AHB2ENR.Fields.RNGEN = value; }
		void set_AHB2ENR_OTGFSEN(EnableFlag value) override { AHB2ENR.Fields.OTGFSEN = value; }

		// AHB3ENR Fields
		EnableFlag get_AHB3ENR_FSMCEN() const override { return AHB3ENR.Fields.FSMCEN; }
		void set_AHB3ENR_FSMCEN(EnableFlag value) override { AHB3ENR.Fields.FSMCEN = value; }

		// Reserved4 Fields

		// APB1ENR Fields
		EnableFlag get_APB1ENR_TIM2EN() const override { return APB1ENR.Fields.TIM2EN; }
		EnableFlag get_APB1ENR_TIM3EN() const override { return APB1ENR.Fields.TIM3EN; }
		EnableFlag get_APB1ENR_TIM4EN() const override { return APB1ENR.Fields.TIM4EN; }
		EnableFlag get_APB1ENR_TIM5EN() const override { return APB1ENR.Fields.TIM5EN; }
		EnableFlag get_APB1ENR_TIM6EN() const override { return APB1ENR.Fields.TIM6EN; }
		EnableFlag get_APB1ENR_TIM7EN() const override { return APB1ENR.Fields.TIM7EN; }
		EnableFlag get_APB1ENR_TIM12EN() const override { return APB1ENR.Fields.TIM12EN; }
		EnableFlag get_APB1ENR_TIM13EN() const override { return APB1ENR.Fields.TIM13EN; }
		EnableFlag get_APB1ENR_TIM14EN() const override { return APB1ENR.Fields.TIM14EN; }
		EnableFlag get_APB1ENR_WWDGEN() const override { return APB1ENR.Fields.WWDGEN; }
		EnableFlag get_APB1ENR_SPI2EN() const override { return APB1ENR.Fields.SPI2EN; }
		EnableFlag get_APB1ENR_SPI3EN() const override { return APB1ENR.Fields.SPI3EN; }
		EnableFlag get_APB1ENR_USART2EN() const override { return APB1ENR.Fields.USART2EN; }
		EnableFlag get_APB1ENR_USART3EN() const override { return APB1ENR.Fields.USART3EN; }
		EnableFlag get_APB1ENR_UART4EN() const override { return APB1ENR.Fields.UART4EN; }
		EnableFlag get_APB1ENR_UART5EN() const override { return APB1ENR.Fields.UART5EN; }
		EnableFlag get_APB1ENR_I2C1EN() const override { return APB1ENR.Fields.I2C1EN; }
		EnableFlag get_APB1ENR_I2C2EN() const override { return APB1ENR.Fields.I2C2EN; }
		EnableFlag get_APB1ENR_I2C3EN() const override { return APB1ENR.Fields.I2C3EN; }
		EnableFlag get_APB1ENR_CAN1EN() const override { return APB1ENR.Fields.CAN1EN; }
		EnableFlag get_APB1ENR_CAN2EN() const override { return APB1ENR.Fields.CAN2EN; }
		EnableFlag get_APB1ENR_PWREN() const override { return APB1ENR.Fields.PWREN; }
		EnableFlag get_APB1ENR_DACEN() const override { return APB1ENR.Fields.DACEN; }
		void set_APB1ENR_TIM2EN(EnableFlag value) override { APB1ENR.Fields.TIM2EN = value; }
		void set_APB1ENR_TIM3EN(EnableFlag value) override { APB1ENR.Fields.TIM3EN = value; }
		void set_APB1ENR_TIM4EN(EnableFlag value) override { APB1ENR.Fields.TIM4EN = value; }
		void set_APB1ENR_TIM5EN(EnableFlag value) override { APB1ENR.Fields.TIM5EN = value; }
		void set_APB1ENR_TIM6EN(EnableFlag value) override { APB1ENR.Fields.TIM6EN = value; }
		void set_APB1ENR_TIM7EN(EnableFlag value) override { APB1ENR.Fields.TIM7EN = value; }
		void set_APB1ENR_TIM12EN(EnableFlag value) override { APB1ENR.Fields.TIM12EN = value; }
		void set_APB1ENR_TIM13EN(EnableFlag value) override { APB1ENR.Fields.TIM13EN = value; }
		void set_APB1ENR_TIM14EN(EnableFlag value) override { APB1ENR.Fields.TIM14EN = value; }
		void set_APB1ENR_WWDGEN(EnableFlag value) override { APB1ENR.Fields.WWDGEN = value; }
		void set_APB1ENR_SPI2EN(EnableFlag value) override { APB1ENR.Fields.SPI2EN = value; }
		void set_APB1ENR_SPI3EN(EnableFlag value) override { APB1ENR.Fields.SPI3EN = value; }
		void set_APB1ENR_USART2EN(EnableFlag value) override { APB1ENR.Fields.USART2EN = value; }
		void set_APB1ENR_USART3EN(EnableFlag value) override { APB1ENR.Fields.USART3EN = value; }
		void set_APB1ENR_UART4EN(EnableFlag value) override { APB1ENR.Fields.UART4EN = value; }
		void set_APB1ENR_UART5EN(EnableFlag value) override { APB1ENR.Fields.UART5EN = value; }
		void set_APB1ENR_I2C1EN(EnableFlag value) override { APB1ENR.Fields.I2C1EN = value; }
		void set_APB1ENR_I2C2EN(EnableFlag value) override { APB1ENR.Fields.I2C2EN = value; }
		void set_APB1ENR_I2C3EN(EnableFlag value) override { APB1ENR.Fields.I2C3EN = value; }
		void set_APB1ENR_CAN1EN(EnableFlag value) override { APB1ENR.Fields.CAN1EN = value; }
		void set_APB1ENR_CAN2EN(EnableFlag value) override { APB1ENR.Fields.CAN2EN = value; }
		void set_APB1ENR_PWREN(EnableFlag value) override { APB1ENR.Fields.PWREN = value; }
		void set_APB1ENR_DACEN(EnableFlag value) override { APB1ENR.Fields.DACEN = value; }

		// APB2ENR Fields
		EnableFlag get_APB2ENR_TIM1EN() const override { return APB2ENR.Fields.TIM1EN; }
		EnableFlag get_APB2ENR_TIM8EN() const override { return APB2ENR.Fields.TIM8EN; }
		EnableFlag get_APB2ENR_USART1EN() const override { return APB2ENR.Fields.USART1EN; }
		EnableFlag get_APB2ENR_USART6EN() const override { return APB2ENR.Fields.USART6EN; }
		EnableFlag get_APB2ENR_ADC1EN() const override { return APB2ENR.Fields.ADC1EN; }
		EnableFlag get_APB2ENR_ADC2EN() const override { return APB2ENR.Fields.ADC2EN; }
		EnableFlag get_APB2ENR_ADC3EN() const override { return APB2ENR.Fields.ADC3EN; }
		EnableFlag get_APB2ENR_SDIOEN() const override { return APB2ENR.Fields.SDIOEN; }
		EnableFlag get_APB2ENR_SPI1EN() const override { return APB2ENR.Fields.SPI1EN; }
		EnableFlag get_APB2ENR_SYSCFGEN() const override { return APB2ENR.Fields.SYSCFGEN; }
		EnableFlag get_APB2ENR_TIM9EN() const override { return APB2ENR.Fields.TIM9EN; }
		EnableFlag get_APB2ENR_TIM10EN() const override { return APB2ENR.Fields.TIM10EN; }
		EnableFlag get_APB2ENR_TIM11EN() const override { return APB2ENR.Fields.TIM11EN; }
		void set_APB2ENR_TIM1EN(EnableFlag value) override { APB2ENR.Fields.TIM1EN = value; }
		void set_APB2ENR_TIM8EN(EnableFlag value) override { APB2ENR.Fields.TIM8EN = value; }
		void set_APB2ENR_USART1EN(EnableFlag value) override { APB2ENR.Fields.USART1EN = value; }
		void set_APB2ENR_USART6EN(EnableFlag value) override { APB2ENR.Fields.USART6EN = value; }
		void set_APB2ENR_ADC1EN(EnableFlag value) override { APB2ENR.Fields.ADC1EN = value; }
		void set_APB2ENR_ADC2EN(EnableFlag value) override { APB2ENR.Fields.ADC2EN = value; }
		void set_APB2ENR_ADC3EN(EnableFlag value) override { APB2ENR.Fields.ADC3EN = value; }
		void set_APB2ENR_SDIOEN(EnableFlag value) override { APB2ENR.Fields.SDIOEN = value; }
		void set_APB2ENR_SPI1EN(EnableFlag value) override { APB2ENR.Fields.SPI1EN = value; }
		void set_APB2ENR_SYSCFGEN(EnableFlag value) override { APB2ENR.Fields.SYSCFGEN = value; }
		void set_APB2ENR_TIM9EN(EnableFlag value) override { APB2ENR.Fields.TIM9EN = value; }
		void set_APB2ENR_TIM10EN(EnableFlag value) override { APB2ENR.Fields.TIM10EN = value; }
		void set_APB2ENR_TIM11EN(EnableFlag value) override { APB2ENR.Fields.TIM11EN = value; }

		// Reserved5 Fields

		// Reserved6 Fields

		// AHB1LPENR Fields
		EnableFlag get_AHB1LPENR_GPIOALPEN() const override { return AHB1LPENR.Fields.GPIOALPEN; }
		EnableFlag get_AHB1LPENR_GPIOBLPEN() const override { return AHB1LPENR.Fields.GPIOBLPEN; }
		EnableFlag get_AHB1LPENR_GPIOCLPEN() const override { return AHB1LPENR.Fields.GPIOCLPEN; }
		EnableFlag get_AHB1LPENR_GPIODLPEN() const override { return AHB1LPENR.Fields.GPIODLPEN; }
		EnableFlag get_AHB1LPENR_GPIOELPEN() const override { return AHB1LPENR.Fields.GPIOELPEN; }
		EnableFlag get_AHB1LPENR_GPIOFLPEN() const override { return AHB1LPENR.Fields.GPIOFLPEN; }
		EnableFlag get_AHB1LPENR_GPIOGLPEN() const override { return AHB1LPENR.Fields.GPIOGLPEN; }
		EnableFlag get_AHB1LPENR_GPIOHLPEN() const override { return AHB1LPENR.Fields.GPIOHLPEN; }
		EnableFlag get_AHB1LPENR_GPIOILPEN() const override { return AHB1LPENR.Fields.GPIOILPEN; }
		EnableFlag get_AHB1LPENR_CRCLPEN() const override { return AHB1LPENR.Fields.CRCLPEN; }
		EnableFlag get_AHB1LPENR_FLITFLPEN() const override { return AHB1LPENR.Fields.FLITFLPEN; }
		EnableFlag get_AHB1LPENR_SRAM1LPEN() const override { return AHB1LPENR.Fields.SRAM1LPEN; }
		EnableFlag get_AHB1LPENR_SRAM2LPEN() const override { return AHB1LPENR.Fields.SRAM2LPEN; }
		EnableFlag get_AHB1LPENR_BKPSRAMLPEN() const override { return AHB1LPENR.Fields.BKPSRAMLPEN; }
		EnableFlag get_AHB1LPENR_DMA1LPEN() const override { return AHB1LPENR.Fields.DMA1LPEN; }
		EnableFlag get_AHB1LPENR_DMA2LPEN() const override { return AHB1LPENR.Fields.DMA2LPEN; }
		EnableFlag get_AHB1LPENR_ETHMACLPEN() const override { return AHB1LPENR.Fields.ETHMACLPEN; }
		EnableFlag get_AHB1LPENR_ETHMACTXLPEN() const override { return AHB1LPENR.Fields.ETHMACTXLPEN; }
		EnableFlag get_AHB1LPENR_ETHMACRXLPEN() const override { return AHB1LPENR.Fields.ETHMACRXLPEN; }
		EnableFlag get_AHB1LPENR_ETHMACPTPLPEN() const override { return AHB1LPENR.Fields.ETHMACPTPLPEN; }
		EnableFlag get_AHB1LPENR_OTGHSLPEN() const override { return AHB1LPENR.Fields.OTGHSLPEN; }
		EnableFlag get_AHB1LPENR_OTGHSULPILPEN() const override { return AHB1LPENR.Fields.OTGHSULPILPEN; }
		void set_AHB1LPENR_GPIOALPEN(EnableFlag value) override { AHB1LPENR.Fields.GPIOALPEN = value; }
		void set_AHB1LPENR_GPIOBLPEN(EnableFlag value) override { AHB1LPENR.Fields.GPIOBLPEN = value; }
		void set_AHB1LPENR_GPIOCLPEN(EnableFlag value) override { AHB1LPENR.Fields.GPIOCLPEN = value; }
		void set_AHB1LPENR_GPIODLPEN(EnableFlag value) override { AHB1LPENR.Fields.GPIODLPEN = value; }
		void set_AHB1LPENR_GPIOELPEN(EnableFlag value) override { AHB1LPENR.Fields.GPIOELPEN = value; }
		void set_AHB1LPENR_GPIOFLPEN(EnableFlag value) override { AHB1LPENR.Fields.GPIOFLPEN = value; }
		void set_AHB1LPENR_GPIOGLPEN(EnableFlag value) override { AHB1LPENR.Fields.GPIOGLPEN = value; }
		void set_AHB1LPENR_GPIOHLPEN(EnableFlag value) override { AHB1LPENR.Fields.GPIOHLPEN = value; }
		void set_AHB1LPENR_GPIOILPEN(EnableFlag value) override { AHB1LPENR.Fields.GPIOILPEN = value; }
		void set_AHB1LPENR_CRCLPEN(EnableFlag value) override { AHB1LPENR.Fields.CRCLPEN = value; }
		void set_AHB1LPENR_FLITFLPEN(EnableFlag value) override { AHB1LPENR.Fields.FLITFLPEN = value; }
		void set_AHB1LPENR_SRAM1LPEN(EnableFlag value) override { AHB1LPENR.Fields.SRAM1LPEN = value; }
		void set_AHB1LPENR_SRAM2LPEN(EnableFlag value) override { AHB1LPENR.Fields.SRAM2LPEN = value; }
		void set_AHB1LPENR_BKPSRAMLPEN(EnableFlag value) override { AHB1LPENR.Fields.BKPSRAMLPEN = value; }
		void set_AHB1LPENR_DMA1LPEN(EnableFlag value) override { AHB1LPENR.Fields.DMA1LPEN = value; }
		void set_AHB1LPENR_DMA2LPEN(EnableFlag value) override { AHB1LPENR.Fields.DMA2LPEN = value; }
		void set_AHB1LPENR_ETHMACLPEN(EnableFlag value) override { AHB1LPENR.Fields.ETHMACLPEN = value; }
		void set_AHB1LPENR_ETHMACTXLPEN(EnableFlag value) override { AHB1LPENR.Fields.ETHMACTXLPEN = value; }
		void set_AHB1LPENR_ETHMACRXLPEN(EnableFlag value) override { AHB1LPENR.Fields.ETHMACRXLPEN = value; }
		void set_AHB1LPENR_ETHMACPTPLPEN(EnableFlag value) override { AHB1LPENR.Fields.ETHMACPTPLPEN = value; }
		void set_AHB1LPENR_OTGHSLPEN(EnableFlag value) override { AHB1LPENR.Fields.OTGHSLPEN = value; }
		void set_AHB1LPENR_OTGHSULPILPEN(EnableFlag value) override { AHB1LPENR.Fields.OTGHSULPILPEN = value; }

		// AHB2LPENR Fields
		EnableFlag get_AHB2LPENR_DCMILPEN() const override { return AHB2LPENR.Fields.DCMILPEN; }
		EnableFlag get_AHB2LPENR_CRYPLPEN() const override { return AHB2LPENR.Fields.CRYPLPEN; }
		EnableFlag get_AHB2LPENR_HASHLPEN() const override { return AHB2LPENR.Fields.HASHLPEN; }
		EnableFlag get_AHB2LPENR_RNGLPEN() const override { return AHB2LPENR.Fields.RNGLPEN; }
		EnableFlag get_AHB2LPENR_OTGFSLPEN() const override { return AHB2LPENR.Fields.OTGFSLPEN; }
		void set_AHB2LPENR_DCMILPEN(EnableFlag value) override { AHB2LPENR.Fields.DCMILPEN = value; }
		void set_AHB2LPENR_CRYPLPEN(EnableFlag value) override { AHB2LPENR.Fields.CRYPLPEN = value; }
		void set_AHB2LPENR_HASHLPEN(EnableFlag value) override { AHB2LPENR.Fields.HASHLPEN = value; }
		void set_AHB2LPENR_RNGLPEN(EnableFlag value) override { AHB2LPENR.Fields.RNGLPEN = value; }
		void set_AHB2LPENR_OTGFSLPEN(EnableFlag value) override { AHB2LPENR.Fields.OTGFSLPEN = value; }

		// AHB3LPENR Fields
		EnableFlag get_AHB3LPENR_FSMCLPEN() const override { return AHB3LPENR.Fields.FSMCLPEN; }
		void set_AHB3LPENR_FSMCLPEN(EnableFlag value) override { AHB3LPENR.Fields.FSMCLPEN = value; }

		// Reserved7 Fields

		// APB1LPENR Fields
		EnableFlag get_APB1LPENR_TIM2LPEN() const override { return APB1LPENR.Fields.TIM2LPEN; }
		EnableFlag get_APB1LPENR_TIM3LPEN() const override { return APB1LPENR.Fields.TIM3LPEN; }
		EnableFlag get_APB1LPENR_TIM4LPEN() const override { return APB1LPENR.Fields.TIM4LPEN; }
		EnableFlag get_APB1LPENR_TIM5LPEN() const override { return APB1LPENR.Fields.TIM5LPEN; }
		EnableFlag get_APB1LPENR_TIM6LPEN() const override { return APB1LPENR.Fields.TIM6LPEN; }
		EnableFlag get_APB1LPENR_TIM7LPEN() const override { return APB1LPENR.Fields.TIM7LPEN; }
		EnableFlag get_APB1LPENR_TIM12LPEN() const override { return APB1LPENR.Fields.TIM12LPEN; }
		EnableFlag get_APB1LPENR_TIM13LPEN() const override { return APB1LPENR.Fields.TIM13LPEN; }
		EnableFlag get_APB1LPENR_TIM14LPEN() const override { return APB1LPENR.Fields.TIM14LPEN; }
		EnableFlag get_APB1LPENR_WWDGLPEN() const override { return APB1LPENR.Fields.WWDGLPEN; }
		EnableFlag get_APB1LPENR_SPI2LPEN() const override { return APB1LPENR.Fields.SPI2LPEN; }
		EnableFlag get_APB1LPENR_SPI3LPEN() const override { return APB1LPENR.Fields.SPI3LPEN; }
		EnableFlag get_APB1LPENR_USART2LPEN() const override { return APB1LPENR.Fields.USART2LPEN; }
		EnableFlag get_APB1LPENR_USART3LPEN() const override { return APB1LPENR.Fields.USART3LPEN; }
		EnableFlag get_APB1LPENR_UART4LPEN() const override { return APB1LPENR.Fields.UART4LPEN; }
		EnableFlag get_APB1LPENR_UART5LPEN() const override { return APB1LPENR.Fields.UART5LPEN; }
		EnableFlag get_APB1LPENR_I2C1LPEN() const override { return APB1LPENR.Fields.I2C1LPEN; }
		EnableFlag get_APB1LPENR_I2C2LPEN() const override { return APB1LPENR.Fields.I2C2LPEN; }
		EnableFlag get_APB1LPENR_I2C3LPEN() const override { return APB1LPENR.Fields.I2C3LPEN; }
		EnableFlag get_APB1LPENR_CAN1LPEN() const override { return APB1LPENR.Fields.CAN1LPEN; }
		EnableFlag get_APB1LPENR_CAN2LPEN() const override { return APB1LPENR.Fields.CAN2LPEN; }
		EnableFlag get_APB1LPENR_PWRLPEN() const override { return APB1LPENR.Fields.PWRLPEN; }
		EnableFlag get_APB1LPENR_DACLPEN() const override { return APB1LPENR.Fields.DACLPEN; }
		void set_APB1LPENR_TIM2LPEN(EnableFlag value) override { APB1LPENR.Fields.TIM2LPEN = value; }
		void set_APB1LPENR_TIM3LPEN(EnableFlag value) override { APB1LPENR.Fields.TIM3LPEN = value; }
		void set_APB1LPENR_TIM4LPEN(EnableFlag value) override { APB1LPENR.Fields.TIM4LPEN = value; }
		void set_APB1LPENR_TIM5LPEN(EnableFlag value) override { APB1LPENR.Fields.TIM5LPEN = value; }
		void set_APB1LPENR_TIM6LPEN(EnableFlag value) override { APB1LPENR.Fields.TIM6LPEN = value; }
		void set_APB1LPENR_TIM7LPEN(EnableFlag value) override { APB1LPENR.Fields.TIM7LPEN = value; }
		void set_APB1LPENR_TIM12LPEN(EnableFlag value) override { APB1LPENR.Fields.TIM12LPEN = value; }
		void set_APB1LPENR_TIM13LPEN(EnableFlag value) override { APB1LPENR.Fields.TIM13LPEN = value; }
		void set_APB1LPENR_TIM14LPEN(EnableFlag value) override { APB1LPENR.Fields.TIM14LPEN = value; }
		void set_APB1LPENR_WWDGLPEN(EnableFlag value) override { APB1LPENR.Fields.WWDGLPEN = value; }
		void set_APB1LPENR_SPI2LPEN(EnableFlag value) override { APB1LPENR.Fields.SPI2LPEN = value; }
		void set_APB1LPENR_SPI3LPEN(EnableFlag value) override { APB1LPENR.Fields.SPI3LPEN = value; }
		void set_APB1LPENR_USART2LPEN(EnableFlag value) override { APB1LPENR.Fields.USART2LPEN = value; }
		void set_APB1LPENR_USART3LPEN(EnableFlag value) override { APB1LPENR.Fields.USART3LPEN = value; }
		void set_APB1LPENR_UART4LPEN(EnableFlag value) override { APB1LPENR.Fields.UART4LPEN = value; }
		void set_APB1LPENR_UART5LPEN(EnableFlag value) override { APB1LPENR.Fields.UART5LPEN = value; }
		void set_APB1LPENR_I2C1LPEN(EnableFlag value) override { APB1LPENR.Fields.I2C1LPEN = value; }
		void set_APB1LPENR_I2C2LPEN(EnableFlag value) override { APB1LPENR.Fields.I2C2LPEN = value; }
		void set_APB1LPENR_I2C3LPEN(EnableFlag value) override { APB1LPENR.Fields.I2C3LPEN = value; }
		void set_APB1LPENR_CAN1LPEN(EnableFlag value) override { APB1LPENR.Fields.CAN1LPEN = value; }
		void set_APB1LPENR_CAN2LPEN(EnableFlag value) override { APB1LPENR.Fields.CAN2LPEN = value; }
		void set_APB1LPENR_PWRLPEN(EnableFlag value) override { APB1LPENR.Fields.PWRLPEN = value; }
		void set_APB1LPENR_DACLPEN(EnableFlag value) override { APB1LPENR.Fields.DACLPEN = value; }

		// APB2LPENR Fields
		EnableFlag get_APB2LPENR_TIM1LPEN() const override { return APB2LPENR.Fields.TIM1LPEN; }
		EnableFlag get_APB2LPENR_TIM8LPEN() const override { return APB2LPENR.Fields.TIM8LPEN; }
		EnableFlag get_APB2LPENR_USART1LPEN() const override { return APB2LPENR.Fields.USART1LPEN; }
		EnableFlag get_APB2LPENR_USART6LPEN() const override { return APB2LPENR.Fields.USART6LPEN; }
		EnableFlag get_APB2LPENR_ADC1LPEN() const override { return APB2LPENR.Fields.ADC1LPEN; }
		EnableFlag get_APB2LPENR_ADC2LPEN() const override { return APB2LPENR.Fields.ADC2LPEN; }
		EnableFlag get_APB2LPENR_ADC3LPEN() const override { return APB2LPENR.Fields.ADC3LPEN; }
		EnableFlag get_APB2LPENR_SDIOLPEN() const override { return APB2LPENR.Fields.SDIOLPEN; }
		EnableFlag get_APB2LPENR_SPI1LPEN() const override { return APB2LPENR.Fields.SPI1LPEN; }
		EnableFlag get_APB2LPENR_SYSCFGLPEN() const override { return APB2LPENR.Fields.SYSCFGLPEN; }
		EnableFlag get_APB2LPENR_TIM9LPEN() const override { return APB2LPENR.Fields.TIM9LPEN; }
		EnableFlag get_APB2LPENR_TIM10LPEN() const override { return APB2LPENR.Fields.TIM10LPEN; }
		EnableFlag get_APB2LPENR_TIM11LPEN() const override { return APB2LPENR.Fields.TIM11LPEN; }
		void set_APB2LPENR_TIM1LPEN(EnableFlag value) override { APB2LPENR.Fields.TIM1LPEN = value; }
		void set_APB2LPENR_TIM8LPEN(EnableFlag value) override { APB2LPENR.Fields.TIM8LPEN = value; }
		void set_APB2LPENR_USART1LPEN(EnableFlag value) override { APB2LPENR.Fields.USART1LPEN = value; }
		void set_APB2LPENR_USART6LPEN(EnableFlag value) override { APB2LPENR.Fields.USART6LPEN = value; }
		void set_APB2LPENR_ADC1LPEN(EnableFlag value) override { APB2LPENR.Fields.ADC1LPEN = value; }
		void set_APB2LPENR_ADC2LPEN(EnableFlag value) override { APB2LPENR.Fields.ADC2LPEN = value; }
		void set_APB2LPENR_ADC3LPEN(EnableFlag value) override { APB2LPENR.Fields.ADC3LPEN = value; }
		void set_APB2LPENR_SDIOLPEN(EnableFlag value) override { APB2LPENR.Fields.SDIOLPEN = value; }
		void set_APB2LPENR_SPI1LPEN(EnableFlag value) override { APB2LPENR.Fields.SPI1LPEN = value; }
		void set_APB2LPENR_SYSCFGLPEN(EnableFlag value) override { APB2LPENR.Fields.SYSCFGLPEN = value; }
		void set_APB2LPENR_TIM9LPEN(EnableFlag value) override { APB2LPENR.Fields.TIM9LPEN = value; }
		void set_APB2LPENR_TIM10LPEN(EnableFlag value) override { APB2LPENR.Fields.TIM10LPEN = value; }
		void set_APB2LPENR_TIM11LPEN(EnableFlag value) override { APB2LPENR.Fields.TIM11LPEN = value; }

		// Reserved8 Fields

		// Reserved9 Fields

		// BDCR Fields
		EnableFlag get_BDCR_LSEON() const override { return BDCR.Fields.LSEON; }
		ReadyFlag get_BDCR_LSERDY() const override { return BDCR.Fields.LSERDY; }
		ExternalLowSpeedOscillatorBypass get_BDCR_LSEBYP() const override { return BDCR.Fields.LSEBYP; }
		RtcClockSourceSelection get_BDCR_RTCSEL() const override { return BDCR.Fields.RTCSEL; }
		EnableFlag get_BDCR_RTCEN() const override { return BDCR.Fields.RTCEN; }
		ResetFlag get_BDCR_BDRST() const override { return BDCR.Fields.BDRST; }
		void set_BDCR_LSEON(EnableFlag value) override { BDCR.Fields.LSEON = value; }
		void set_BDCR_LSEBYP(ExternalLowSpeedOscillatorBypass value) override { BDCR.Fields.LSEBYP = value; }
		void set_BDCR_RTCSEL(RtcClockSourceSelection value) override { BDCR.Fields.RTCSEL = value; }
		void set_BDCR_RTCEN(EnableFlag value) override { BDCR.Fields.RTCEN = value; }
		void set_BDCR_BDRST(ResetFlag value) override { BDCR.Fields.BDRST = value; }

		// CSR Fields
		EnableFlag get_CSR_LSION() const override { return CSR.Fields.LSION; }
		ReadyFlag get_CSR_LSIRDY() const override { return CSR.Fields.LSIRDY; }
		ClearFlag get_CSR_RMVF() const override { return CSR.Fields.RMVF; }
		ResetOccurredFlag get_CSR_BORRSTF() const override { return CSR.Fields.BORRSTF; }
		ResetOccurredFlag get_CSR_PINRSTF() const override { return CSR.Fields.PINRSTF; }
		ResetOccurredFlag get_CSR_PORRSTF() const override { return CSR.Fields.PORRSTF; }
		ResetOccurredFlag get_CSR_SFTRSTF() const override { return CSR.Fields.SFTRSTF; }
		ResetOccurredFlag get_CSR_IWDGRSTF() const override { return CSR.Fields.IWDGRSTF; }
		ResetOccurredFlag get_CSR_WWDGRSTF() const override { return CSR.Fields.WWDGRSTF; }
		ResetOccurredFlag get_CSR_LPWRRSTF() const override { return CSR.Fields.LPWRRSTF; }
		void set_CSR_LSION(EnableFlag value) override { CSR.Fields.LSION = value; }
		void set_CSR_RMVF(ClearFlag value) override { CSR.Fields.RMVF = value; }

		// Reserved10 Fields

		// Reserved11 Fields

		// SSCGR Fields
		uint16_t get_SSCGR_MODPER() const override { return SSCGR.Fields.MODPER; }
		uint16_t get_SSCGR_INCSTEP() const override { return SSCGR.Fields.INCSTEP; }
		SpreadSelect get_SSCGR_SPREADSEL() const override { return SSCGR.Fields.SPREADSEL; }
		EnableFlag get_SSCGR_SSCGEN() const override { return SSCGR.Fields.SSCGEN; }
		void set_SSCGR_MODPER(uint16_t value) override { SSCGR.Fields.MODPER = value; }
		void set_SSCGR_INCSTEP(uint16_t value) override { SSCGR.Fields.INCSTEP = value; }
		void set_SSCGR_SPREADSEL(SpreadSelect value) override { SSCGR.Fields.SPREADSEL = value; }
		void set_SSCGR_SSCGEN(EnableFlag value) override { SSCGR.Fields.SSCGEN = value; }

		// PLLI2SCFGR Fields
		uint16_t get_PLLI2SCFGR_PLLI2SN() const override { return PLLI2SCFGR.Fields.PLLI2SN; }
		uint8_t get_PLLI2SCFGR_PLLI2SR() const override { return PLLI2SCFGR.Fields.PLLI2SR; }
		void set_PLLI2SCFGR_PLLI2SN(uint16_t value) override { PLLI2SCFGR.Fields.PLLI2SN = value; }
		void set_PLLI2SCFGR_PLLI2SR(uint8_t value) override { PLLI2SCFGR.Fields.PLLI2SR = value; }

	private:

		ClockControlRegister CR; // Address Offset 0x0
		PllConfigurationRegiser PLLCFGR; // Address Offset 0x4
		ClockConfigurationRegister CFGR; // Address Offset 0x8
		ClockInterruptRegister CIR; // Address Offset 0xC
		Ahb1PeripheralResetRegister AHB1RSTR; // Address Offset 0x10
		Ahb2PeripheralResetRegister AHB2RSTR; // Address Offset 0x14
		Ahb3PeripheralResetRegister AHB3RSTR; // Address Offset 0x18
		uint32_t Reserved1; // Address Offset 0x1C
		Apb1PeripheralResetRegister APB1RSTR; // Address Offset 0x20
		Apb2PeripheralResetRegister APB2RSTR; // Address Offset 0x24
		uint32_t Reserved2; // Address Offset 0x28
		uint32_t Reserved3; // Address Offset 0x2C
		Ahb1PeripheralClockEnableRegister AHB1ENR; // Address Offset 0x30
		Ahb2PeripheralClockEnableRegister AHB2ENR; // Address Offset 0x34
		Ahb3PeripheralClockEnableRegister AHB3ENR; // Address Offset 0x38
		uint32_t Reserved4; // Address Offset 0x3C
		Apb1PeripheralClockEnableRegister APB1ENR; // Address Offset 0x40
		Apb2PeripheralClockEnableRegister APB2ENR; // Address Offset 0x44
		uint32_t Reserved5; // Address Offset 0x48
		uint32_t Reserved6; // Address Offset 0x4C
		Ahb1PeripheralClockEnableInLowPowerModeRegister AHB1LPENR; // Address Offset 0x50
		Ahb2PeripheralClockEnableInLowPowerModeRegister AHB2LPENR; // Address Offset 0x54
		Ahb3PeripheralClockEnableInLowPowerModeRegister AHB3LPENR; // Address Offset 0x58
		uint32_t Reserved7; // Address Offset 0x5C
		Apb1PeripheralClockEnableInLowPowerModeRegister APB1LPENR; // Address Offset 0x60
		Apb2PeripheralClockEnableInLowPowerModeRegister APB2LPENR; // Address Offset 0x64
		uint32_t Reserved8; // Address Offset 0x68
		uint32_t Reserved9; // Address Offset 0x6C
		BackupDomainControlRegister BDCR; // Address Offset 0x70
		ClockControlAndStatusRegister CSR; // Address Offset 0x74
		uint32_t Reserved10; // Address Offset 0x78
		uint32_t Reserved11; // Address Offset 0x7C
		SpreadSpectrumClockGenerationRegister SSCGR; // Address Offset 0x80
		PLLI2SConfigurationRegister PLLI2SCFGR; // Address Offset 0x84
	};
}
#endif // RCC_REGISTER_MAP_HPP_