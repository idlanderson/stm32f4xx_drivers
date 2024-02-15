#include "rcc.hpp"

namespace stm32::rcc
{
    void RccPeripheral::SetSystemClockSource(SystemClock systemClockSource)
    {
        device.set_CFGR_SW(systemClockSource);
    }
    
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

    uint32_t RccPeripheral::GetSystemClockFrequency() const
    {
        SystemClock systemClockSource = device.get_CFGR_SWS();
        uint32_t systemClockFrequency = 0U;

        if (systemClockSource == SystemClock::HsiOscillator)
        {
            // Internal (HSI) oscillator.
            systemClockFrequency = HsiSystemClockFrequencyHz;
        }
        else if (systemClockSource == SystemClock::HseOscillator)
        {
            // External (HSE) oscillator.
            systemClockFrequency = HseSystemClockFrequencyHz;
        }
        else if (systemClockSource == SystemClock::Pll)
        {
            // PLL. TODO: Implement support for PLL.
            systemClockFrequency = 0;
        }
        else
        {
            // Invalid clock source.
            systemClockFrequency = 0;
        }

        return systemClockFrequency;
    }

    uint32_t RccPeripheral::GetAhbClockFrequency() const
    {
        uint32_t systemClockFrequency = GetSystemClockFrequency();
        uint32_t ahbPrescaler = GetAhbPrescalar();

        // AHB Clock = SYSCLK / AHB Prescalar
        return systemClockFrequency / ahbPrescaler;
    }

    uint32_t RccPeripheral::GetApb1ClockFrequency() const
    {
        uint32_t ahbClock = GetAhbClockFrequency();
        uint32_t apb1Prescaler = GetApbPrescalar(device.get_CFGR_PPRE1());

        // APBx Peripheral Clock = AHB Clock / APBx Prescalar
        return ahbClock / apb1Prescaler;
    }

    uint32_t RccPeripheral::GetApb2ClockFrequency() const
    {
        uint32_t ahbClock = GetAhbClockFrequency();
        uint32_t apb1Prescaler = GetApbPrescalar(device.get_CFGR_PPRE2());

        // APBx Peripheral Clock = AHB Clock / APBx Prescalar
        return ahbClock / apb1Prescaler;
    }

    inline uint32_t RccPeripheral::GetAhbPrescalar() const
    {
        AhbPrescaler ahbPrescaler = device.get_CFGR_HPRE();

        switch (ahbPrescaler)
        {
        case AhbPrescaler::SystemClockDividedBy2:
            return 2U;
        case AhbPrescaler::SystemClockDividedBy4:
            return 4U;
        case AhbPrescaler::SystemClockDividedBy8:
            return 8U;
        case AhbPrescaler::SystemClockDividedBy16:
            return 16U;
        case AhbPrescaler::SystemClockDividedBy64:
            return 64U;
        case AhbPrescaler::SystemClockDividedBy128:
            return 128U;
        case AhbPrescaler::SystemClockDividedBy256:
            return 256U;
        case AhbPrescaler::SystemClockDividedBy512:
            return 512U;
        default:
            return 1U;
        }
    }

    inline uint32_t RccPeripheral::GetApbPrescalar(ApbPrescaler apbPrescaler) const
    {
        switch (apbPrescaler)
        {
        case ApbPrescaler::AhbClockDividedBy2:
            return 2U;
        case ApbPrescaler::AhbClockDividedBy4:
            return 4U;
        case ApbPrescaler::AhbClockDividedBy8:
            return 8U;
        case ApbPrescaler::AhbClockDividedBy16:
            return 16U;
        default:
            return 1U;
        }
    }
}