#include "rcc.hpp"

namespace stm32::rcc
{
    void RccPeripheral::SetAHB1PeripheralClockEnabled(AHB1_Peripheral peripheral, bool isEnabled)
    {
        if (isEnabled)
        {
            device.set_AHB1ENR_GPIOAEN(EnableFlag::Enable);
            //this->AHB1ENR |= (1U << (uint8_t)peripheral);
        }
        else
        {
            //this->AHB1ENR &= ~(1U << (uint8_t)peripheral);
        }
    }
}