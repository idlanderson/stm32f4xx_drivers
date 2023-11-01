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

		enum class Ahb1Peripheral
		{
			GPIOA,
			GPIOB,
			GPIOC,
			GPIOD,
			GPIOE,
			GPIOF,
			GPIOG,
			GPIOH,
			GPIOI,
			CRC,
			BKPSRAM,
			CCMDATARAM,
			DMA1,
			DMA2,
			ETHMAC,
			ETHMACTX,
			ETHMACRX,
			ETHMACPTP,
			OTGHS,
			OTGHSULPI,
		};

		void SetAHB1PeripheralClockEnabled(Ahb1Peripheral peripheral, bool isEnabled);
	
		RccPeripheral(IRccRegisterMap & device) : device(device) { }

	private:

		IRccRegisterMap & device;
	};
}
#endif