#ifndef RCC_HPP_
#define RCC_HPP_

#include "stm32f4xx.hpp"
#include "rcc_register_map.hpp"
#include <cstdint>
#include <unordered_map>

namespace stm32::rcc
{
	class RccPeripheral
	{
	public:

		enum class Peripheral
		{
			// AHB1
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
			// AHB2
			DCMI,
			CRYP,
			HASH,
			RNG,
			OTGFS,
			// AHB3
			FSMC,
			// APB1
			TIM2,
			TIM3,
			TIM4,
			TIM5,
			TIM6,
			TIM7,
			TIM12,
			TIM13,
			TIM14,
			WWDG,
			SPI2,
			SPI3,
			USART2,
			USART3,
			UART4,
			UART5,
			I2C1,
			I2C2,
			I2C3,
			CAN2,
			PWR,
			DAC,
			// APB2
			TIM1,
			TIM8,
			USART1,
			USART6,
			ADC1,
			ADC2,
			ADC3,
			SDIO,
			SPI1,
			SYSCFG,
			TIM9,
			TIM10,
			TIM11
		};

		void SetPeripheralClockEnabled(Peripheral peripheral, bool isEnabled);

		RccPeripheral(uint32_t addr) : 
			device(*reinterpret_cast<RccRegisterMap*>(addr)) { }

		RccPeripheral(IRccRegisterMap & device) : device(device) { }

		void SetSystemClockSource(SystemClock systemClockSource);
		uint32_t GetSystemClockFrequency() const;
		uint32_t GetAhbClockFrequency() const;
		uint32_t GetApb1ClockFrequency() const;
		uint32_t GetApb2ClockFrequency() const;

	private:

		uint32_t GetAhbPrescalar() const;
		uint32_t GetApbPrescalar(ApbPrescaler apbPrescaler) const;

		const uint32_t HsiSystemClockFrequencyHz = 16000000U;	// Internal RC oscillator.
		const uint32_t HseSystemClockFrequencyHz = 8000000U;	// External X2 crystal oscillator present on the STM32F4 Discovery Board.

		IRccRegisterMap & device;
	};
}
#endif