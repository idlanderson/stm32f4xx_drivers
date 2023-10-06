#include "rcc.hpp"

void RCC::SetAHB1PeripheralClockEnabled(AHB1_Peripheral peripheral, bool isEnabled)
{
    if (isEnabled)
    {
        this->AHB1ENR |= (1U << (uint8_t)peripheral);
    }
    else
    {
        this->AHB1ENR &= ~(1U << (uint8_t)peripheral);
    }
}