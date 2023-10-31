#ifndef EXTI_HPP_
#define EXTI_HPP_

#include "exti_register_map.hpp"

namespace stm32::exti
{
    class ExtiPeripheral
    {
    public:
        ExtiPeripheral(IExtiRegisterMap & device) : device(device) { }
        void SetInterruptMask(uint8_t line, InterruptMask mask);
        void SetEventMask(uint8_t line, InterruptMask mask);
    private:
        IExtiRegisterMap & device;
    };
}

#endif // EXTI_HPP_