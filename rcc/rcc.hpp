#ifndef RCC_HPP_
#define RCC_HPP_

#include "stm32f4xx.hpp"
#include "rcc_register_map.hpp"
#include <cstdint>

namespace stm32::rcc
{
	class RccPeripheral
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
	
		RccPeripheral(IRccRegisterMap & device) : device(device) {}

	private:

		IRccRegisterMap & device;
	};
}
#endif