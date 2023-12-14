#include "rcc.hpp"

namespace stm32::rcc
{
    void RccPeripheral::SetPeripheralClockEnabled(Peripheral peripheral, bool isEnabled)
    {
        EnableFlag enableFlag = isEnabled ? EnableFlag::Enable : EnableFlag::Disable;

        switch (peripheral)
        {
        case Peripheral::GPIOA: device.set_AHB1ENR_GPIOAEN(enableFlag); break;
        case Peripheral::GPIOB: device.set_AHB1ENR_GPIOBEN(enableFlag); break;
        case Peripheral::GPIOC: device.set_AHB1ENR_GPIOCEN(enableFlag); break;
        case Peripheral::GPIOD: device.set_AHB1ENR_GPIODEN(enableFlag); break;
        case Peripheral::GPIOE: device.set_AHB1ENR_GPIOEEN(enableFlag); break;
        case Peripheral::GPIOF: device.set_AHB1ENR_GPIOFEN(enableFlag); break;
        case Peripheral::GPIOG: device.set_AHB1ENR_GPIOGEN(enableFlag); break;
        case Peripheral::GPIOH: device.set_AHB1ENR_GPIOHEN(enableFlag); break;
        case Peripheral::GPIOI: device.set_AHB1ENR_GPIOIEN(enableFlag); break;
        case Peripheral::CRC: device.set_AHB1ENR_CRCEN(enableFlag); break;
        case Peripheral::BKPSRAM: device.set_AHB1ENR_BKPSRAMEN(enableFlag); break;
        case Peripheral::CCMDATARAM: device.set_AHB1ENR_CCMDATARAMEN(enableFlag); break;
        case Peripheral::DMA1: device.set_AHB1ENR_DMA1EN(enableFlag); break;
        case Peripheral::DMA2: device.set_AHB1ENR_DMA2EN(enableFlag); break;
        case Peripheral::ETHMAC: device.set_AHB1ENR_ETHMACEN(enableFlag); break;
        case Peripheral::ETHMACTX: device.set_AHB1ENR_ETHMACTXEN(enableFlag); break;
        case Peripheral::ETHMACRX: device.set_AHB1ENR_ETHMACRXEN(enableFlag); break;
        case Peripheral::ETHMACPTP: device.set_AHB1ENR_ETHMACPTPEN(enableFlag); break;
        case Peripheral::OTGHS: device.set_AHB1ENR_OTGHSEN(enableFlag); break;
        case Peripheral::OTGHSULPI: device.set_AHB1ENR_OTGHSULPIEN(enableFlag); break;
        case Peripheral::DCMI: device.set_AHB2ENR_DCMIEN(enableFlag); break;
        case Peripheral::CRYP: device.set_AHB2ENR_CRYPEN(enableFlag); break;
        case Peripheral::HASH: device.set_AHB2ENR_HASHEN(enableFlag); break;
        case Peripheral::RNG: device.set_AHB2ENR_RNGEN(enableFlag); break;
        case Peripheral::OTGFS: device.set_AHB2ENR_OTGFSEN(enableFlag); break;
        case Peripheral::FSMC: device.set_AHB3ENR_FSMCEN(enableFlag); break;
        case Peripheral::TIM2: device.set_APB1ENR_TIM2EN(enableFlag); break;
        case Peripheral::TIM3: device.set_APB1ENR_TIM3EN(enableFlag); break;
        case Peripheral::TIM4: device.set_APB1ENR_TIM4EN(enableFlag); break;
        case Peripheral::TIM5: device.set_APB1ENR_TIM5EN(enableFlag); break;
        case Peripheral::TIM6: device.set_APB1ENR_TIM6EN(enableFlag); break;
        case Peripheral::TIM7: device.set_APB1ENR_TIM7EN(enableFlag); break;
        case Peripheral::TIM12: device.set_APB1ENR_TIM12EN(enableFlag); break;
        case Peripheral::TIM13: device.set_APB1ENR_TIM13EN(enableFlag); break;
        case Peripheral::TIM14: device.set_APB1ENR_TIM14EN(enableFlag); break;
        case Peripheral::WWDG: device.set_APB1ENR_WWDGEN(enableFlag); break;
        case Peripheral::SPI2: device.set_APB1ENR_SPI2EN(enableFlag); break;
        case Peripheral::SPI3: device.set_APB1ENR_SPI3EN(enableFlag); break;
        case Peripheral::USART2: device.set_APB1ENR_USART2EN(enableFlag); break;
        case Peripheral::USART3: device.set_APB1ENR_USART3EN(enableFlag); break;
        case Peripheral::UART4: device.set_APB1ENR_UART4EN(enableFlag); break;
        case Peripheral::UART5: device.set_APB1ENR_UART5EN(enableFlag); break;
        case Peripheral::I2C1: device.set_APB1ENR_I2C1EN(enableFlag); break;
        case Peripheral::I2C2: device.set_APB1ENR_I2C2EN(enableFlag); break;
        case Peripheral::I2C3: device.set_APB1ENR_I2C3EN(enableFlag); break;
        case Peripheral::CAN2: device.set_APB1ENR_CAN2EN(enableFlag); break;
        case Peripheral::PWR: device.set_APB1ENR_PWREN(enableFlag); break;
        case Peripheral::DAC: device.set_APB1ENR_DACEN(enableFlag); break;
        case Peripheral::TIM1: device.set_APB2ENR_TIM1EN(enableFlag); break;
        case Peripheral::TIM8: device.set_APB2ENR_TIM8EN(enableFlag); break;
        case Peripheral::USART1: device.set_APB2ENR_USART1EN(enableFlag); break;
        case Peripheral::USART6: device.set_APB2ENR_USART6EN(enableFlag); break;
        case Peripheral::ADC1: device.set_APB2ENR_ADC1EN(enableFlag); break;
        case Peripheral::ADC2: device.set_APB2ENR_ADC2EN(enableFlag); break;
        case Peripheral::ADC3: device.set_APB2ENR_ADC3EN(enableFlag); break;
        case Peripheral::SDIO: device.set_APB2ENR_SDIOEN(enableFlag); break;
        case Peripheral::SPI1: device.set_APB2ENR_SPI1EN(enableFlag); break;
        case Peripheral::SYSCFG: device.set_APB2ENR_SYSCFGEN(enableFlag); break;
        case Peripheral::TIM9: device.set_APB2ENR_TIM9EN(enableFlag); break;
        case Peripheral::TIM10: device.set_APB2ENR_TIM10EN(enableFlag); break;
        case Peripheral::TIM11: device.set_APB2ENR_TIM11EN(enableFlag); break;
        default: break;
        }
    }
}