#ifndef GPIO_HPP_
#define GPIO_HPP_

#include "gpio_register_map.hpp"

namespace stm32::gpio
{
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
    
    class GpioPeripheral
    {
    public:

        GpioPeripheral(uint32_t addr) : device(*reinterpret_cast<GpioRegisterMap*>(addr)) { }
        GpioPeripheral(IGpioRegisterMap & device) : device(device) { }

        void SetPinMode(PinNumber pin, Mode mode);
        void SetPinSpeed(PinNumber pin, Speed speed);
        void SetPinPullUpPullDown(PinNumber pin, PullUpPullDown config);
        void SetPinOutputType(PinNumber pin, OutputType outputType);
        void SetPinAltFcn(PinNumber pin, AlternateFunction altFcn);
        
        void ConfigureInputPin(PinNumber pin, Speed speed);
        void ConfigureOutputPin(PinNumber pin, Speed speed, PullUpPullDown pullUpPullDown, OutputType outputType);

        uint8_t ReadPin(PinNumber pin);
        void WritePin(PinNumber pin, uint8_t value);

        void TogglePin(PinNumber pin);

    private:

        IGpioRegisterMap & device;
    };
}

#endif /* GPIO_HPP_ */