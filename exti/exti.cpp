#include "exti.hpp"

namespace stm32::exti
{
    void ExtiPeripheral::SetInterruptMask(uint8_t line, InterruptMask mask)
    {
        switch(line)
        {
            case 0U:  device.set_IMR_MR0(mask);  break;
            case 1U:  device.set_IMR_MR1(mask);  break;
            case 2U:  device.set_IMR_MR2(mask);  break;
            case 3U:  device.set_IMR_MR3(mask);  break;
            case 4U:  device.set_IMR_MR4(mask);  break;
            case 5U:  device.set_IMR_MR5(mask);  break;
            case 6U:  device.set_IMR_MR6(mask);  break;
            case 7U:  device.set_IMR_MR7(mask);  break;
            case 8U:  device.set_IMR_MR8(mask);  break;
            case 9U:  device.set_IMR_MR9(mask);  break;
            case 10U: device.set_IMR_MR10(mask); break;
            case 11U: device.set_IMR_MR11(mask); break;
            case 12U: device.set_IMR_MR12(mask); break;
            case 13U: device.set_IMR_MR13(mask); break;
            case 14U: device.set_IMR_MR14(mask); break;
            case 15U: device.set_IMR_MR15(mask); break;
            case 16U: device.set_IMR_MR16(mask); break;
            case 17U: device.set_IMR_MR17(mask); break;
            case 18U: device.set_IMR_MR18(mask); break;
            case 19U: device.set_IMR_MR19(mask); break;
            case 20U: device.set_IMR_MR20(mask); break;
            case 21U: device.set_IMR_MR21(mask); break;
            case 22U: device.set_IMR_MR22(mask); break;
            default: break;
        }
    }

    void ExtiPeripheral::SetEventMask(uint8_t line, InterruptMask mask)
    {
        switch(line)
        {
            case 0U:  device.set_EMR_MR0(mask);  break;
            case 1U:  device.set_EMR_MR1(mask);  break;
            case 2U:  device.set_EMR_MR2(mask);  break;
            case 3U:  device.set_EMR_MR3(mask);  break;
            case 4U:  device.set_EMR_MR4(mask);  break;
            case 5U:  device.set_EMR_MR5(mask);  break;
            case 6U:  device.set_EMR_MR6(mask);  break;
            case 7U:  device.set_EMR_MR7(mask);  break;
            case 8U:  device.set_EMR_MR8(mask);  break;
            case 9U:  device.set_EMR_MR9(mask);  break;
            case 10U: device.set_EMR_MR10(mask); break;
            case 11U: device.set_EMR_MR11(mask); break;
            case 12U: device.set_EMR_MR12(mask); break;
            case 13U: device.set_EMR_MR13(mask); break;
            case 14U: device.set_EMR_MR14(mask); break;
            case 15U: device.set_EMR_MR15(mask); break;
            case 16U: device.set_EMR_MR16(mask); break;
            case 17U: device.set_EMR_MR17(mask); break;
            case 18U: device.set_EMR_MR18(mask); break;
            case 19U: device.set_EMR_MR19(mask); break;
            case 20U: device.set_EMR_MR20(mask); break;
            case 21U: device.set_EMR_MR21(mask); break;
            case 22U: device.set_EMR_MR22(mask); break;
            default: break;
        }
    }
}