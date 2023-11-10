/*
*   Device-specific header file for the STM32F4xx MCU.
*/

#ifndef STM32F4XX_H_
#define STM32F4XX_H_

#include <cstdint>

/* Base Addresses of Flash and SRAM memories */

#define FLASH_BASEADDR		0x08000000U		/* Flash */
#define SRAM1_BASEADDR		0x20000000U		/* SRAM1 = 112 KB */
#define SRAM2_BASEADDR		0x20001C00U		/* SRAM2 = 16 KB */
#define ROM_BASEADDR		0x1FFF0000U		/* System Memory */
#define SRAM				SRAM1_BASEADDR	/* Start of SRAM1 */

/* AHBx and APBx Bus Peripheral base addresses */

#define PERIPH_BASE			0x40000000U		/* Base address for all peripherals */
#define APB1PERIPH_BASE		PERIPH_BASE		/* Base address for peripherals on APB1 bus. */
#define APB2PERIPH_BASE		0x40010000U		/* Base address for peripherals on APB2 bus. */
#define AHB1PERIPH_BASE		0x40020000U		/* Base address for peripherals on AHB1 bus. */
#define AHB2PERIPH_BASE		0x50000000U		/* Base address for peripherals on AHB2 bus. */

/* Base addresses for peripherals on AHB1 bus */

#define GPIOA_BASEADDR		(AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASEADDR		(AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASEADDR		(AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASEADDR		(AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASEADDR		(AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASEADDR		(AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASEADDR		(AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASEADDR		(AHB1PERIPH_BASE + 0x1C00U)
#define GPIOI_BASEADDR		(AHB1PERIPH_BASE + 0x2000U)
#define RCC_BASEADDR		(AHB1PERIPH_BASE + 0x3800U)

/* Base addresses for peripherals on APB1 bus */

#define I2C1_BASEADDR		(APB1PERIPH_BASE + 0x5400U)
#define I2C2_BASEADDR		(APB1PERIPH_BASE + 0x5800U)
#define I2C3_BASEADDR		(APB1PERIPH_BASE + 0x5C00U)
#define SPI2_BASEADDR		(APB1PERIPH_BASE + 0x3800U)
#define SPI3_BASEADDR		(APB1PERIPH_BASE + 0x3C00U)
#define USART2_BASEADDR		(APB1PERIPH_BASE + 0x4400U)
#define USART3_BASEADDR		(APB1PERIPH_BASE + 0x4800U)
#define UART4_BASEADDR		(APB1PERIPH_BASE + 0x4C00U)
#define UART5_BASEADDR		(APB1PERIPH_BASE + 0x5000U)

/* Base addresses for peripherals on APB2 bus */

#define EXTI_BASEADDR		(APB2PERIPH_BASE + 0x3C00U)
#define SPI1_BASEADDR		(APB2PERIPH_BASE + 0x3000U)
#define SPI4_BASEADDR		(APB2PERIPH_BASE + 0x3400U)
#define SPI5_BASEADDR		(APB2PERIPH_BASE + 0x5000U)
#define SPI6_BASEADDR		(APB2PERIPH_BASE + 0x5400U)
#define USART1_BASEADDR		(APB2PERIPH_BASE + 0x1000U)
#define USART6_BASEADDR		(APB2PERIPH_BASE + 0x1400U)
#define SYSCFG_BASEADDR		(APB2PERIPH_BASE + 0x3800U)
#define EXTI_BASEADDR		(APB2PERIPH_BASE + 0x3C00U)

/* Base address for the NVIC */

#define NVIC_BASEADDR       (0xE000E100U)

#endif /* STM32F4XX_H_ */
