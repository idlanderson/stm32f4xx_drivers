#include "nvic.hpp"
#include <iostream>

namespace stm32::nvic
{
    void NvicPeripheral::EnableIrq(IrqNumber irqNumber)
    {
        uint32_t index = static_cast<uint32_t>(irqNumber) / 32U;
        uint32_t bit = static_cast<uint32_t>(irqNumber) - (32U * index);

        uint32_t iser = device.get_ISER_SETENA(index);

        iser |= (1U << bit);

        device.set_ISER_SETENA(index, iser);
    }

    void NvicPeripheral::DisableIrq(IrqNumber irqNumber)
    {
        uint32_t index = static_cast<uint32_t>(irqNumber) / 32U;
        uint32_t bit = static_cast<uint32_t>(irqNumber) - (32U * index);

        uint32_t icer = device.get_ICER_CLRENA(index);

        icer |= (1U << bit);

        device.set_ICER_CLRENA(index, icer);
    }

    void NvicPeripheral::SetPendingIrq(IrqNumber irqNumber)
    {
        uint32_t index = static_cast<uint32_t>(irqNumber) / 32U;
        uint32_t bit = static_cast<uint32_t>(irqNumber) - (32U * index);

        uint32_t ispr = device.get_ISPR_SETPEND(index);

        ispr |= (1U << bit);

        device.set_ISPR_SETPEND(index, ispr);
    }

    void NvicPeripheral::ClearPendingIrq(IrqNumber irqNumber)
    {
        uint32_t index = static_cast<uint32_t>(irqNumber) / 32U;
        uint32_t bit = static_cast<uint32_t>(irqNumber) - (32U * index);

        uint32_t icpr = device.get_ICPR_CLRPEND(index);

        icpr |= (1U << bit);

        device.set_ICPR_CLRPEND(index, icpr);
    }

    bool NvicPeripheral::IsIrqActive(IrqNumber irqNumber)
    {
        uint32_t index = static_cast<uint32_t>(irqNumber) / 32U;
        uint32_t bit = static_cast<uint32_t>(irqNumber) - (32U * index);

        uint32_t iabr = device.get_IABR_ACTIVE(index);

        return static_cast<bool>((iabr >> bit) & 0x1U);
    }

    std::vector<IrqNumber> NvicPeripheral::GetActiveIrqs()
    {
        std::vector<IrqNumber> activeIrqs;

        for (uint32_t index = 0U; index < device.get_IABR_size(); index++)
        {
            uint32_t iabr = device.get_IABR_ACTIVE(index);

            for (uint32_t bit = 0U; bit <= 31; bit++)
            {
                if (((iabr >> bit) & 0x1U) != 0U)
                {
                    IrqNumber irqNumber = static_cast<IrqNumber>(bit + 32U * index);
                    activeIrqs.push_back(irqNumber);
                }
            }
        }

        return activeIrqs;
    }

    void NvicPeripheral::SetIrqPriority(IrqNumber irqNumber, IrqPriority irqPriority)
    {
        uint32_t index = static_cast<uint32_t>(irqNumber) / 4U;

        if (index >= device.get_IPR_size())
        {
            return;
        }

        uint32_t bit = static_cast<uint32_t>(irqNumber) * 8U - (32U * index);

        uint32_t ipr = device.get_IPR_PRI(index);

        ipr &= ~(0xFFU << bit);
        ipr |= static_cast<uint32_t>(irqPriority << bit);

        device.set_IPR_PRI(index, ipr);
    }

    void NvicPeripheral::TriggerIrq(IrqNumber irqNumber)
    {
        device.set_STIR_INTID(static_cast<uint32_t>(irqNumber));
    }
}