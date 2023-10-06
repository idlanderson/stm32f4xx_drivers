#ifndef RCC_HPP_
#define RCC_HPP_

#include "stm32f4xx.hpp"
#include <cstdint>

using DeviceRegister = std::uint32_t volatile;
using ReservedField = uint32_t;

class RCC
{

public:

    enum class AHB1_Peripheral
    {
        GPIOA = 0U,
        GPIOB = 1U,
        GPIOC = 2U,
        GPIOD = 3U,
        GPIOE = 4U,
        GPIOF = 5U,
        GPIOG = 6U,
        GPIOH = 7U,
        GPIOI = 8U,
		CRC   = 12U,
		BKPSRAM = 18U,
		CCMDATARAM = 20U,
		DMA1 = 21U,
		DMA2 = 22U,
		ETHMAC = 25U,
		ETHMACTX = 26U,
		ETHMACRX = 27U,
		ETHMACPTP = 28U,
		OTGHS = 29U,
		OTGHSULPI = 30U
    };

    void SetAHB1PeripheralClockEnabled(AHB1_Peripheral peripheral, bool isEnabled);

private:

	DeviceRegister CR;			/* Address Offset 0x00. RCC clock control register */
	DeviceRegister PLLCFGR;		/* Address Offset 0x04. RCC PLL configuration register */
	DeviceRegister CFGR;		/* Address Offset 0x08. RCC clock configuration register */
	DeviceRegister CIR;			/* Address Offset 0x0C. RCC clock interrupt register */
	DeviceRegister AHB1RSTR;	/* Address Offset 0x10. RCC AHB1 peripheral reset register */
	DeviceRegister AHB2RSTR;	/* Address Offset 0x14. RCC AHB2 peripheral reset register */
	DeviceRegister AHB3RSTR;	/* Address Offset 0x18. RCC AHB3 peripheral reset register */
	ReservedField  Rsrvd1;		/* Address Offset 0x1C. Reserved */
	DeviceRegister APB1RSTR;	/* Address Offset 0x20. RCC APB1 peripheral reset register */
	DeviceRegister APB2RSTR;	/* Address Offset 0x24. RCC APB2 peripheral reset register */
	ReservedField  Rsrvd2;		/* Address Offset 0x28. Reserved */
	ReservedField  Rsrvd3;		/* Address Offset 0x2C. Reserved */
	DeviceRegister AHB1ENR;		/* Address Offset 0x30. RCC AHB1 peripheral clock enable register */
	DeviceRegister AHB2ENR;		/* Address Offset 0x34. RCC AHB2 peripheral clock enable register */
	DeviceRegister AHB3ENR;		/* Address Offset 0x38. RCC AHB3 peripheral clock enable register */
	ReservedField  Rsrvd4;		/* Address Offset 0x3C. Reserved */
	DeviceRegister APB1ENR;		/* Address Offset 0x40. RCC APB1 peripheral clock enable register */
	DeviceRegister APB2ENR;		/* Address Offset 0x44. RCC APB2 peripheral clock enable register */
	ReservedField  Rsrvd5;		/* Address Offset 0x48. Reserved */
	ReservedField  Rsrvd6;		/* Address Offset 0x4C. Reserved */
	DeviceRegister AHB1LPENR;	/* Address Offset 0x50. RCC AHB1 peripheral clock enable in low power mode register */
	DeviceRegister AHB2LPENR;	/* Address Offset 0x54. RCC AHB2 peripheral clock enable in low power mode register */
	DeviceRegister AHB3LPENR;	/* Address Offset 0x58. RCC AHB3 peripheral clock enable in low power mode register */
	ReservedField  Rsrvd7;		/* Address Offset 0x5C. Reserved */
	DeviceRegister APB1LPENR;	/* Address Offset 0x60. RCC APB1 peripheral clock enable in low power mode register */
	DeviceRegister APB2LPENR;	/* Address Offset 0x64. RCC APB2 peripheral clock enabled in low power mode */
	ReservedField  Rsrvd8;		/* Address Offset 0x68. Reserved */
	ReservedField  Rsrvd9;		/* Address Offset 0x6C. Reserved */
	DeviceRegister BDCR;		/* Address Offset 0x70. RCC Backup domain control register */
	DeviceRegister CSR;			/* Address Offset 0x74. RCC clock control & status register */
	ReservedField  Rsrvd10;		/* Address Offset 0x78. Reserved */
	ReservedField  Rsrvd11;		/* Address Offset 0x7C. Reserved */
	DeviceRegister SSCGR;		/* Address Offset 0x80. RCC spread spectrum clock generation register */
	DeviceRegister PLLI2SCFGR;	/* Address Offset 0x84. RCC PLLI2S configuration register */
};

#endif