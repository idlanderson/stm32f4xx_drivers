#include "syscfg.hpp"

namespace stm32::syscfg
{
    void SyscfgPeripheral::SetMemoryMapping(MemoryMapping memoryMapping)
    {
        device.set_MEMRMP_MEM_MODE(memoryMapping);
    }

    void SyscfgPeripheral::ConfigureGpioInterrupt(uint8_t extiLine, ExtiConfiguration extiConfiguration)
    {
        switch (extiLine)
        {
        case 0U:  device.set_EXTICR1_EXTI0 (extiConfiguration); break;
        case 1U:  device.set_EXTICR1_EXTI1 (extiConfiguration); break;
        case 2U:  device.set_EXTICR1_EXTI2 (extiConfiguration); break;
        case 3U:  device.set_EXTICR1_EXTI3 (extiConfiguration); break;
        case 4U:  device.set_EXTICR2_EXTI4 (extiConfiguration); break;
        case 5U:  device.set_EXTICR2_EXTI5 (extiConfiguration); break;
        case 6U:  device.set_EXTICR2_EXTI6 (extiConfiguration); break;
        case 7U:  device.set_EXTICR2_EXTI7 (extiConfiguration); break;
        case 8U:  device.set_EXTICR3_EXTI8 (extiConfiguration); break;
        case 9U:  device.set_EXTICR3_EXTI9 (extiConfiguration); break;
        case 10U: device.set_EXTICR3_EXTI10(extiConfiguration); break;
        case 11U: device.set_EXTICR3_EXTI11(extiConfiguration); break;
        case 12U: device.set_EXTICR4_EXTI12(extiConfiguration); break;
        case 13U: device.set_EXTICR4_EXTI13(extiConfiguration); break;
        case 14U: device.set_EXTICR4_EXTI14(extiConfiguration); break;
        case 15U: device.set_EXTICR4_EXTI15(extiConfiguration); break;
        default : break;
        }
    }
}