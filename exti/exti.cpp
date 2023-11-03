#include "exti.hpp"

namespace stm32::exti
{
    void ExtiPeripheral::SetInterruptMask(uint8_t line, InterruptMask mask)
    {
        uint32_t mr = device.get_IMR_MR();

        mr &= ~(0x1U << line);
        mr |= ((uint8_t)mask & 0x1U) << line;

        device.set_IMR_MR(mr);
    }

    void ExtiPeripheral::SetEventMask(uint8_t line, InterruptMask mask)
    {
        uint32_t mr = device.get_EMR_MR();

        mr &= ~(0x1U << line);
        mr |= ((uint8_t)mask & 0x1U) << line;

        device.set_EMR_MR(mr);
    }

    void ExtiPeripheral::SetRisingTriggerEnabled(uint8_t line, bool isEnabled)
    {
        uint32_t tr = device.get_RTSR_TR();

        tr &= ~(0x1U << line);
        tr |= ((uint8_t)isEnabled & 0x1U) << line;

        device.set_RTSR_TR(tr);
    }

    void ExtiPeripheral::SetFallingTriggerEnabled(uint8_t line, bool isEnabled)
    {
        uint32_t tr = device.get_FTSR_TR();

        tr &= ~(0x1U << line);
        tr |= ((uint8_t)isEnabled & 0x1U) << line;

        device.set_FTSR_TR(tr);
    }

    void ExtiPeripheral::GenerateInterruptRequest(uint8_t line)
    {
        uint32_t swier = device.get_SWIER_SWIER();

        // Writing 1 to the SWIER bit will set the corresponding PR bit to 1.
        swier |= 0x1U << line;

        device.set_SWIER_SWIER(swier);
    }

    void ExtiPeripheral::ClearPendingBit(uint8_t line)
    {
        uint32_t pr = device.get_PR_PR();

        // Writing 1 to the pending bit will clear it.
        pr |= 0x1U << line;

        device.set_PR_PR(pr);
    }
}