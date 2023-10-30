#include "rcc.hpp"

namespace stm32::rcc
{
    void RccPeripheral::SetAHB1PeripheralClockEnabled(Ahb1Peripheral peripheral, bool isEnabled)
    {
        EnableFlag enableFlag = isEnabled ? EnableFlag::Enable : EnableFlag::Disable;

        switch (peripheral)
        {
        case Ahb1Peripheral::GPIOA:      device.set_AHB1ENR_GPIOAEN(enableFlag); break;
        case Ahb1Peripheral::GPIOB:      device.set_AHB1ENR_GPIOBEN(enableFlag); break;
        case Ahb1Peripheral::GPIOC:      device.set_AHB1ENR_GPIOCEN(enableFlag); break;
        case Ahb1Peripheral::GPIOD:      device.set_AHB1ENR_GPIODEN(enableFlag); break;
        case Ahb1Peripheral::GPIOE:      device.set_AHB1ENR_GPIOEEN(enableFlag); break;
        case Ahb1Peripheral::GPIOF:      device.set_AHB1ENR_GPIOFEN(enableFlag); break;
        case Ahb1Peripheral::GPIOG:      device.set_AHB1ENR_GPIOGEN(enableFlag); break;
        case Ahb1Peripheral::GPIOH:      device.set_AHB1ENR_GPIOHEN(enableFlag); break;
        case Ahb1Peripheral::GPIOI:      device.set_AHB1ENR_GPIOIEN(enableFlag); break;
        case Ahb1Peripheral::CRC:        device.set_AHB1ENR_CRCEN(enableFlag); break;
        case Ahb1Peripheral::BKPSRAM:    device.set_AHB1ENR_BKPSRAMEN(enableFlag); break;
        case Ahb1Peripheral::CCMDATARAM: device.set_AHB1ENR_CCMDATARAMEN(enableFlag); break;
        case Ahb1Peripheral::DMA1:       device.set_AHB1ENR_DMA1EN(enableFlag); break;
        case Ahb1Peripheral::DMA2:       device.set_AHB1ENR_DMA2EN(enableFlag); break;
        case Ahb1Peripheral::ETHMAC:     device.set_AHB1ENR_ETHMACEN(enableFlag); break;
        case Ahb1Peripheral::ETHMACTX:   device.set_AHB1ENR_ETHMACTXEN(enableFlag); break;
        case Ahb1Peripheral::ETHMACRX:   device.set_AHB1ENR_ETHMACRXEN(enableFlag); break;
        case Ahb1Peripheral::ETHMACPTP:  device.set_AHB1ENR_ETHMACPTPEN(enableFlag); break;
        case Ahb1Peripheral::OTGHS:      device.set_AHB1ENR_OTGHSEN(enableFlag); break;
        case Ahb1Peripheral::OTGHSULPI:  device.set_AHB1ENR_OTGHSULPIEN(enableFlag); break;
        default: break;
        }
    }
}