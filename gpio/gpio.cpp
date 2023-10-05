#include "gpio.hpp"

#define MAX_POSITION_FOR_1_BIT_FIELD    31U
#define MAX_VALUE_FOR_1_BIT_FIELD       1U
#define MAX_POSITION_FOR_2_BIT_FIELD    15U
#define MAX_VALUE_FOR_2_BIT_FIELD       0x3U

void GPIO::SetRegField_1Bit(DeviceRegister & reg, uint8_t position, uint8_t value)
{
    if (position <= MAX_POSITION_FOR_1_BIT_FIELD &&
        value    <= MAX_VALUE_FOR_1_BIT_FIELD)
    {
        reg &= ~(0x1U << position);
        reg |= value << position;
    }
}

void GPIO::SetRegField_2Bits(DeviceRegister & reg, uint8_t position, uint8_t value)
{
    if (position <= MAX_POSITION_FOR_2_BIT_FIELD &&
        value    <= MAX_VALUE_FOR_2_BIT_FIELD)
    {
        reg &= ~(0x3U << (2U * position)); /* Clear the bits */
        reg |= value << (2U * position);   /* Populate the new value */
    }
}

void GPIO::SetPinMode(PinNumber pin, PinMode mode)
{
    SetRegField_2Bits(this->MODER, (uint8_t)pin, (uint8_t)mode);
}

void GPIO::SetPinSpeed(PinNumber pin, PinSpeed speed)
{
    SetRegField_2Bits(this->OSPEEDR, (uint8_t)pin, (uint8_t)speed);
}

void GPIO::SetPinPullUpPullDown(PinNumber pin, PullUpPullDown config)
{
    SetRegField_2Bits(this->PUPDR, (uint8_t)pin, (uint8_t)config);
}

void GPIO::SetPinOutputType(PinNumber pin, OutputType outputType)
{
    SetRegField_1Bit(this->OTYPER, (uint8_t)pin, (uint8_t)outputType);
}

void GPIO::SetAltFcn(PinNumber pin, AltFcnNumber altFcn)
{
    uint8_t registerIndex      = (uint8_t)pin / 8U;
    uint8_t positionInRegister = (uint8_t)pin % 8U;

    this->AFR[registerIndex] &= ~(0xFU << (4U * positionInRegister));
    this->AFR[registerIndex] |= (uint8_t)altFcn << (4U * positionInRegister);
}

uint8_t GPIO::ReadPin(PinNumber pin)
{
    return (uint8_t)((this->IDR >> (uint8_t)pin) & 0x00000001U);
}

uint16_t GPIO::Read()
{
    return ((uint16_t)this->IDR & 0x0000FFFFU);
}

void GPIO::WritePin(PinNumber pin, uint8_t value)
{
    if (value > 0U)
    {
        this->ODR |= (1U << (uint8_t)pin);
    }
    else
    {
        this->ODR &= ~(1U << (uint8_t)pin);
    }
}

void GPIO::Write(uint16_t value)
{
    this->ODR = (uint32_t)value;
}