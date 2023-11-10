#ifndef EXTI_HPP_
#define EXTI_HPP_

#include "exti_register_map.hpp"

namespace stm32::exti
{
    class ExtiPeripheral
    {
    public:
        ExtiPeripheral(IExtiRegisterMap & device) : device(device) { }
        void SetIrqMask(uint8_t line, InterruptMask mask);
        void SetEventMask(uint8_t line, InterruptMask mask);
        void SetRisingTriggerEnabled(uint8_t line, bool isEnabled);
        void SetFallingTriggerEnabled(uint8_t line, bool isEnabled);
        void GenerateIrq(uint8_t line);
        void ClearPendingBit(uint8_t line);
    private:
        IExtiRegisterMap & device;
    };
}

#endif // EXTI_HPP_