#include "stm32f4xx.hpp"

namespace stm32
{
    uint8_t RegisterMap::GetField_1Bit(const DeviceRegister & reg, uint8_t bitPosition) const
    {
        return 0;
    }

    uint8_t RegisterMap::GetField_2Bit(const DeviceRegister & reg, uint8_t bitPosition) const
    {
        return 0U;
    }

    uint8_t RegisterMap::GetField_3Bit(const DeviceRegister & reg, uint8_t bitPosition) const
    {
        return 0U;
    }
    
    uint8_t RegisterMap::GetField_8Bit(const DeviceRegister & reg, uint8_t bitPosition) const
    {
        return 0U;
    }

    void RegisterMap::SetField_1Bit(DeviceRegister & reg, uint8_t bitPosition, uint8_t value)
    {
        if (bitPosition <= MaxPositionFor1BitField &&
            value       <= MaxValueFor1BitField)
        {
            reg &= ~(0x1U << bitPosition);
            reg |= value << bitPosition;
        }
    }

    void RegisterMap::SetField_2Bit(DeviceRegister & reg, uint8_t bitPosition, uint8_t value)
    {
        if (bitPosition <= MaxPositionFor2BitField &&
            value       <= MaxValueFor2BitField)
        {
            reg &= ~(0x3U << bitPosition); /* Clear the bits */
            reg |= value << bitPosition;   /* Populate the new value */
        }
    }

    void RegisterMap::SetField_3Bit(DeviceRegister & reg, uint8_t bitPosition, uint8_t value)
    {
        if (bitPosition <= MaxPositionFor3BitField &&
            value       <= MaxValueFor3BitField)
        {
            reg &= ~(0x7U << bitPosition); /* Clear the bits */
            reg |= value << bitPosition;   /* Populate the new value */
        }
    }

    void RegisterMap::SetField_8Bit(DeviceRegister & reg, uint8_t bitPosition, uint8_t value)
    {
        if (bitPosition <= MaxPositionFor8BitField &&
            value       <= MaxValueFor8BitField)
        {
            reg &= ~(0xFFU << bitPosition); /* Clear the bits */
            reg |= value << bitPosition;    /* Populate the new value */
        }
    }
}