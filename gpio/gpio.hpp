#ifndef GPIO_HPP_
#define GPIO_HPP_

#include "stm32f4xx.hpp"
#include <cstdint>

using DeviceRegister = std::uint32_t volatile;
using ReservedField = uint32_t;

class GPIO
{
public:

    enum class PinNumber
    {
        Pin0  = 0U,
        Pin1  = 1U,
        Pin2  = 2U,
        Pin3  = 3U,
        Pin4  = 4U,
        Pin5  = 5U,
        Pin6  = 6U,
        Pin7  = 7U,
        Pin8  = 8U,
        Pin9  = 9U,
        Pin10 = 10U,
        Pin11 = 11U,
        Pin12 = 12U,
        Pin13 = 13U,
        Pin14 = 14U,
        Pin15 = 15U
    };

    enum class PinMode
    {
        Input  = 0x00U,
        Output = 0x01U,
        AltFcn = 0x02U,
        Analog = 0x03U
    };

    enum class PinSpeed
    {
        LowSpeed = 0x00U,
        MediumSpeed = 0x01U,
        HighSpeed = 0x02U,
        VeryHighSpeed = 0x03U
    };

    enum class PullUpPullDown
    {
        None = 0x00U,
        PullUp = 0x01U,
        PullDown = 0x02U
    };

    enum class OutputType
    {
        PushPull = 0U,
        OpenDrain = 1U
    };

    enum class AltFcnNumber
    {
        AltFcn0  = 0U,
        AltFcn1  = 1U,
        AltFcn2  = 2U,
        AltFcn3  = 3U,
        AltFcn4  = 4U,
        AltFcn5  = 5U,
        AltFcn6  = 6U,
        AltFcn7  = 7U,
        AltFcn8  = 8U,
        AltFcn9  = 9U,
        AltFcn10 = 10U,
        AltFcn11 = 11U,
        AltFcn12 = 12U,
        AltFcn13 = 13U,
        AltFcn14 = 14U,
        AltFcn15 = 15U
    };

    void SetPinMode(PinNumber pin, PinMode mode);
    void SetPinSpeed(PinNumber pin, PinSpeed speed);
    void SetPinPullUpPullDown(PinNumber pin, PullUpPullDown config);
    void SetPinOutputType(PinNumber pin, OutputType outputType);
    void SetPinAltFcn(PinNumber pin, AltFcnNumber altFcn);
    
    void ConfigureInputPin(PinNumber pin, PinSpeed speed);
    void ConfigureOutputPin(PinNumber pin, PinSpeed speed, PullUpPullDown pullUpPullDown, OutputType outputType);

    uint16_t Read();
    void Write(uint16_t value);

    uint8_t ReadPin(PinNumber pin);
    void WritePin(PinNumber pin, uint8_t value);

    void TogglePin(PinNumber pin);

private:

    DeviceRegister MODER;	    /* Address Offset 0x00. GPIO port mode register */
	DeviceRegister OTYPER;	    /* Address Offset 0x04. GPIO port output type register */
	DeviceRegister OSPEEDR;     /* Address Offset 0x08. GPIO port output speed register */
	DeviceRegister PUPDR;	    /* Address Offset 0x0C. GPIO port pull-up/pull-down register */
	DeviceRegister IDR;		    /* Address Offset 0x10. GPIO port input data register */
	DeviceRegister ODR;		    /* Address Offset 0x14. GPIO port output data register */
	DeviceRegister BSRR;		/* Address Offset 0x18. GPIO port bit set/reset register */
	DeviceRegister LCKR;		/* Address Offset 0x1C. GPIO port configuration lock register */
	DeviceRegister AFR[2];	    /* Address Offset 0x20. AFR[0] = GPIO alternate function low register, AFR[1] = GPIO alternate function high register */

    void SetRegField_1Bit(DeviceRegister & reg, uint8_t position, uint8_t value);
    void SetRegField_2Bits(DeviceRegister & reg, uint8_t position, uint8_t value);
};

#endif /* GPIO_HPP_ */