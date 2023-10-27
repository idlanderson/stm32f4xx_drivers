#include "gpio_ports.hpp"
#include "rcc_def.hpp"
#include "spi_def.hpp"
#include <type_traits>

using namespace stm32::gpio;
using namespace stm32::rcc;
using namespace stm32::spi;

using Pin = stm32::gpio::PinNumber;
using PinSpeed = stm32::gpio::Speed;
using PullUpPullDown = stm32::gpio::PullUpPullDown;
using OutputType = stm32::gpio::OutputType;

void delay(void)
{
	for (uint32_t i = 0U; i < 500000U / 2U; i++);
}

bool IsUserButtonB1Pressed(void)
{
    return (GPIOA.ReadPin(Pin::Pin0) == 1U);
}

void WaitForButtonPress(void)
{
    while (!IsUserButtonB1Pressed())
    {
        delay();
    }
}

int main()
{
    stm32::rcc::Init();
    stm32::gpio::Init();
    stm32::spi::Init();

    RCC.SetAHB1PeripheralClockEnabled(RccPeripheral::Ahb1Peripheral::GPIOA, true);
    RCC.SetAHB1PeripheralClockEnabled(RccPeripheral::Ahb1Peripheral::GPIOD, true);

    GPIOA.ConfigureInputPin(Pin::Pin0, PinSpeed::VeryHighSpeed);

    GPIOD.ConfigureOutputPin(
        Pin::Pin12, 
        PinSpeed::VeryHighSpeed, 
        PullUpPullDown::NoPullUpPullDown, 
        OutputType::PushPull);

    GPIOD.ConfigureOutputPin(
        Pin::Pin13, 
        PinSpeed::VeryHighSpeed, 
        PullUpPullDown::NoPullUpPullDown, 
        OutputType::PushPull);

    GPIOD.ConfigureOutputPin(
        Pin::Pin14, 
        PinSpeed::VeryHighSpeed, 
        PullUpPullDown::NoPullUpPullDown, 
        OutputType::PushPull);

    GPIOD.ConfigureOutputPin(
        Pin::Pin15, 
        PinSpeed::VeryHighSpeed, 
        PullUpPullDown::NoPullUpPullDown, 
        OutputType::PushPull);

    GPIOD.WritePin(Pin::Pin12, 1U);
    GPIOD.WritePin(Pin::Pin13, 1U);
    GPIOD.WritePin(Pin::Pin14, 1U);
    GPIOD.WritePin(Pin::Pin15, 1U);

    for (;;)
    {
        delay();

        if (GPIOA.ReadPin(Pin::Pin0) == 1U)
        {
            GPIOD.TogglePin(Pin::Pin12);
            GPIOD.TogglePin(Pin::Pin13);
            GPIOD.TogglePin(Pin::Pin14);
            GPIOD.TogglePin(Pin::Pin15);
        }
    }

    return 0U;
}