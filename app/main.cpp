#include "gpio_ports.hpp"

using Pin = GPIO::PinNumber;

int main()
{
    GPIOA.SetPinMode(Pin::Pin0, GPIO::PinMode::Input);
    GPIOA.SetPinSpeed(Pin::Pin0, GPIO::PinSpeed::VeryHighSpeed);
    GPIOA.SetPinPullUpPullDown(Pin::Pin0, GPIO::PullUpPullDown::None);
    GPIOA.SetPinOutputType(Pin::Pin0, GPIO::OutputType::PushPull);
    GPIOA.SetAltFcn((Pin)16, GPIO::AltFcnNumber::AltFcn0);

    GPIOA.Read();
    GPIOA.ReadPin(Pin::Pin0);
    GPIOA.Write(4U);
    GPIOA.WritePin(Pin::Pin0, 1U);

    return 0U;
}