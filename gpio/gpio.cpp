#include "gpio.hpp"

namespace stm32::gpio
{
    void GpioPeripheral::SetPinMode(PinNumber pin, Mode mode)
    {
        switch (pin)
        {
        case PinNumber::Pin0  : device->set_MODER_MODER0 (mode); break;
        case PinNumber::Pin1  : device->set_MODER_MODER1 (mode); break;
        case PinNumber::Pin2  : device->set_MODER_MODER2 (mode); break;
        case PinNumber::Pin3  : device->set_MODER_MODER3 (mode); break;
        case PinNumber::Pin4  : device->set_MODER_MODER4 (mode); break;
        case PinNumber::Pin5  : device->set_MODER_MODER5 (mode); break;
        case PinNumber::Pin6  : device->set_MODER_MODER6 (mode); break;
        case PinNumber::Pin7  : device->set_MODER_MODER7 (mode); break;
        case PinNumber::Pin8  : device->set_MODER_MODER8 (mode); break;
        case PinNumber::Pin9  : device->set_MODER_MODER9 (mode); break;
        case PinNumber::Pin10 : device->set_MODER_MODER10(mode); break;
        case PinNumber::Pin11 : device->set_MODER_MODER11(mode); break;
        case PinNumber::Pin12 : device->set_MODER_MODER12(mode); break;
        case PinNumber::Pin13 : device->set_MODER_MODER13(mode); break;
        case PinNumber::Pin14 : device->set_MODER_MODER14(mode); break;
        case PinNumber::Pin15 : device->set_MODER_MODER15(mode); break;
        default               : break;
        }
    }

    void GpioPeripheral::SetPinSpeed(PinNumber pin, Speed speed)
    {
        switch (pin)
        {
        case PinNumber::Pin0  : device->set_OSPEEDR_OSPEEDR0 (speed); break;
        case PinNumber::Pin1  : device->set_OSPEEDR_OSPEEDR1 (speed); break;
        case PinNumber::Pin2  : device->set_OSPEEDR_OSPEEDR2 (speed); break;
        case PinNumber::Pin3  : device->set_OSPEEDR_OSPEEDR3 (speed); break;
        case PinNumber::Pin4  : device->set_OSPEEDR_OSPEEDR4 (speed); break;
        case PinNumber::Pin5  : device->set_OSPEEDR_OSPEEDR5 (speed); break;
        case PinNumber::Pin6  : device->set_OSPEEDR_OSPEEDR6 (speed); break;
        case PinNumber::Pin7  : device->set_OSPEEDR_OSPEEDR7 (speed); break;
        case PinNumber::Pin8  : device->set_OSPEEDR_OSPEEDR8 (speed); break;
        case PinNumber::Pin9  : device->set_OSPEEDR_OSPEEDR9 (speed); break;
        case PinNumber::Pin10 : device->set_OSPEEDR_OSPEEDR10(speed); break;
        case PinNumber::Pin11 : device->set_OSPEEDR_OSPEEDR11(speed); break;
        case PinNumber::Pin12 : device->set_OSPEEDR_OSPEEDR12(speed); break;
        case PinNumber::Pin13 : device->set_OSPEEDR_OSPEEDR13(speed); break;
        case PinNumber::Pin14 : device->set_OSPEEDR_OSPEEDR14(speed); break;
        case PinNumber::Pin15 : device->set_OSPEEDR_OSPEEDR15(speed); break;
        default               : break;
        }
    }

    void GpioPeripheral::SetPinPullUpPullDown(PinNumber pin, PullUpPullDown config)
    {
        switch (pin)
        {
        case PinNumber::Pin0  : device->set_PUPDR_PUPDR0 (config); break;
        case PinNumber::Pin1  : device->set_PUPDR_PUPDR1 (config); break;
        case PinNumber::Pin2  : device->set_PUPDR_PUPDR2 (config); break;
        case PinNumber::Pin3  : device->set_PUPDR_PUPDR3 (config); break;
        case PinNumber::Pin4  : device->set_PUPDR_PUPDR4 (config); break;
        case PinNumber::Pin5  : device->set_PUPDR_PUPDR5 (config); break;
        case PinNumber::Pin6  : device->set_PUPDR_PUPDR6 (config); break;
        case PinNumber::Pin7  : device->set_PUPDR_PUPDR7 (config); break;
        case PinNumber::Pin8  : device->set_PUPDR_PUPDR8 (config); break;
        case PinNumber::Pin9  : device->set_PUPDR_PUPDR9 (config); break;
        case PinNumber::Pin10 : device->set_PUPDR_PUPDR10(config); break;
        case PinNumber::Pin11 : device->set_PUPDR_PUPDR11(config); break;
        case PinNumber::Pin12 : device->set_PUPDR_PUPDR12(config); break;
        case PinNumber::Pin13 : device->set_PUPDR_PUPDR13(config); break;
        case PinNumber::Pin14 : device->set_PUPDR_PUPDR14(config); break;
        case PinNumber::Pin15 : device->set_PUPDR_PUPDR15(config); break;
        default               : break;
        }
    }

    void GpioPeripheral::SetPinOutputType(PinNumber pin, OutputType outputType)
    {
        switch (pin)
        {
        case PinNumber::Pin0  : device->set_OTYPER_OT0 (outputType); break;
        case PinNumber::Pin1  : device->set_OTYPER_OT1 (outputType); break;
        case PinNumber::Pin2  : device->set_OTYPER_OT2 (outputType); break;
        case PinNumber::Pin3  : device->set_OTYPER_OT3 (outputType); break;
        case PinNumber::Pin4  : device->set_OTYPER_OT4 (outputType); break;
        case PinNumber::Pin5  : device->set_OTYPER_OT5 (outputType); break;
        case PinNumber::Pin6  : device->set_OTYPER_OT6 (outputType); break;
        case PinNumber::Pin7  : device->set_OTYPER_OT7 (outputType); break;
        case PinNumber::Pin8  : device->set_OTYPER_OT8 (outputType); break;
        case PinNumber::Pin9  : device->set_OTYPER_OT9 (outputType); break;
        case PinNumber::Pin10 : device->set_OTYPER_OT10(outputType); break;
        case PinNumber::Pin11 : device->set_OTYPER_OT11(outputType); break;
        case PinNumber::Pin12 : device->set_OTYPER_OT12(outputType); break;
        case PinNumber::Pin13 : device->set_OTYPER_OT13(outputType); break;
        case PinNumber::Pin14 : device->set_OTYPER_OT14(outputType); break;
        case PinNumber::Pin15 : device->set_OTYPER_OT15(outputType); break;
        default               : break;
        }
    }

    void GpioPeripheral::SetPinAltFcn(PinNumber pin, AlternateFunction altFcn)
    {
        switch (pin)
        {
        case PinNumber::Pin0  : device->set_AFRL_AFRL0 (altFcn); break;
        case PinNumber::Pin1  : device->set_AFRL_AFRL1 (altFcn); break;
        case PinNumber::Pin2  : device->set_AFRL_AFRL2 (altFcn); break;
        case PinNumber::Pin3  : device->set_AFRL_AFRL3 (altFcn); break;
        case PinNumber::Pin4  : device->set_AFRL_AFRL4 (altFcn); break;
        case PinNumber::Pin5  : device->set_AFRL_AFRL5 (altFcn); break;
        case PinNumber::Pin6  : device->set_AFRL_AFRL6 (altFcn); break;
        case PinNumber::Pin7  : device->set_AFRL_AFRL7 (altFcn); break;
        case PinNumber::Pin8  : device->set_AFRH_AFRH8 (altFcn); break;
        case PinNumber::Pin9  : device->set_AFRH_AFRH9 (altFcn); break;
        case PinNumber::Pin10 : device->set_AFRH_AFRH10(altFcn); break;
        case PinNumber::Pin11 : device->set_AFRH_AFRH11(altFcn); break;
        case PinNumber::Pin12 : device->set_AFRH_AFRH12(altFcn); break;
        case PinNumber::Pin13 : device->set_AFRH_AFRH13(altFcn); break;
        case PinNumber::Pin14 : device->set_AFRH_AFRH14(altFcn); break;
        case PinNumber::Pin15 : device->set_AFRH_AFRH15(altFcn); break;
        default               : break;
        }
    }

    void GpioPeripheral::ConfigureInputPin(PinNumber pin, Speed speed)
    {
        this->SetPinMode(pin, Mode::Input);
        this->SetPinSpeed(pin, speed);
        this->SetPinPullUpPullDown(pin, PullUpPullDown::NoPullUpPullDown);
        this->SetPinOutputType(pin, OutputType::PushPull);
    }

    void GpioPeripheral::ConfigureOutputPin(PinNumber pin, Speed speed, PullUpPullDown pullUpPullDown, OutputType outputType)
    {
        this->SetPinMode(pin, Mode::GeneralPurposeOutput);
        this->SetPinSpeed(pin, speed);
        this->SetPinPullUpPullDown(pin, pullUpPullDown);
        this->SetPinOutputType(pin, outputType);
    }

    uint8_t GpioPeripheral::ReadPin(PinNumber pin)
    {
        switch (pin)
        {
        case PinNumber::Pin0  : return device->get_IDR_IDR0 ();
        case PinNumber::Pin1  : return device->get_IDR_IDR1 ();
        case PinNumber::Pin2  : return device->get_IDR_IDR2 ();
        case PinNumber::Pin3  : return device->get_IDR_IDR3 ();
        case PinNumber::Pin4  : return device->get_IDR_IDR4 ();
        case PinNumber::Pin5  : return device->get_IDR_IDR5 ();
        case PinNumber::Pin6  : return device->get_IDR_IDR6 ();
        case PinNumber::Pin7  : return device->get_IDR_IDR7 ();
        case PinNumber::Pin8  : return device->get_IDR_IDR8 ();
        case PinNumber::Pin9  : return device->get_IDR_IDR9 ();
        case PinNumber::Pin10 : return device->get_IDR_IDR10();
        case PinNumber::Pin11 : return device->get_IDR_IDR11();
        case PinNumber::Pin12 : return device->get_IDR_IDR12();
        case PinNumber::Pin13 : return device->get_IDR_IDR13();
        case PinNumber::Pin14 : return device->get_IDR_IDR14();
        case PinNumber::Pin15 : return device->get_IDR_IDR15();
        default               : return 0U;
        }
    }

    uint16_t GpioPeripheral::Read()
    {
        //return ((uint16_t)this->IDR & 0x0000FFFFU);
        return 0U;
    }

    void GpioPeripheral::WritePin(PinNumber pin, uint8_t value)
    {
        switch (pin)
        {
        case PinNumber::Pin0  : device->set_ODR_ODR0 (value); break;
        case PinNumber::Pin1  : device->set_ODR_ODR1 (value); break;
        case PinNumber::Pin2  : device->set_ODR_ODR2 (value); break;
        case PinNumber::Pin3  : device->set_ODR_ODR3 (value); break;
        case PinNumber::Pin4  : device->set_ODR_ODR4 (value); break;
        case PinNumber::Pin5  : device->set_ODR_ODR5 (value); break;
        case PinNumber::Pin6  : device->set_ODR_ODR6 (value); break;
        case PinNumber::Pin7  : device->set_ODR_ODR7 (value); break;
        case PinNumber::Pin8  : device->set_ODR_ODR8 (value); break;
        case PinNumber::Pin9  : device->set_ODR_ODR9 (value); break;
        case PinNumber::Pin10 : device->set_ODR_ODR10(value); break;
        case PinNumber::Pin11 : device->set_ODR_ODR11(value); break;
        case PinNumber::Pin12 : device->set_ODR_ODR12(value); break;
        case PinNumber::Pin13 : device->set_ODR_ODR13(value); break;
        case PinNumber::Pin14 : device->set_ODR_ODR14(value); break;
        case PinNumber::Pin15 : device->set_ODR_ODR15(value); break;
        default               : break;
        }
    }

    void GpioPeripheral::Write(uint16_t value)
    {
        //this->ODR = (uint32_t)value;
    }

    void GpioPeripheral::TogglePin(PinNumber pin)
    {
        switch (pin)
        {
        case PinNumber::Pin0  : device->set_ODR_ODR0 (~device->get_ODR_ODR0 ()); break;
        case PinNumber::Pin1  : device->set_ODR_ODR1 (~device->get_ODR_ODR1 ()); break;
        case PinNumber::Pin2  : device->set_ODR_ODR2 (~device->get_ODR_ODR2 ()); break;
        case PinNumber::Pin3  : device->set_ODR_ODR3 (~device->get_ODR_ODR3 ()); break;
        case PinNumber::Pin4  : device->set_ODR_ODR4 (~device->get_ODR_ODR4 ()); break;
        case PinNumber::Pin5  : device->set_ODR_ODR5 (~device->get_ODR_ODR5 ()); break;
        case PinNumber::Pin6  : device->set_ODR_ODR6 (~device->get_ODR_ODR6 ()); break;
        case PinNumber::Pin7  : device->set_ODR_ODR7 (~device->get_ODR_ODR7 ()); break;
        case PinNumber::Pin8  : device->set_ODR_ODR8 (~device->get_ODR_ODR8 ()); break;
        case PinNumber::Pin9  : device->set_ODR_ODR9 (~device->get_ODR_ODR9 ()); break;
        case PinNumber::Pin10 : device->set_ODR_ODR10(~device->get_ODR_ODR10()); break;
        case PinNumber::Pin11 : device->set_ODR_ODR11(~device->get_ODR_ODR11()); break;
        case PinNumber::Pin12 : device->set_ODR_ODR12(~device->get_ODR_ODR12()); break;
        case PinNumber::Pin13 : device->set_ODR_ODR13(~device->get_ODR_ODR13()); break;
        case PinNumber::Pin14 : device->set_ODR_ODR14(~device->get_ODR_ODR14()); break;
        case PinNumber::Pin15 : device->set_ODR_ODR15(~device->get_ODR_ODR15()); break;
        default               : break;
        }
    }
}