#ifndef GPIO_PORTS_H_
#define GPIO_PORTS_H_

#include "stm32f4xx.hpp"
#include "gpio.hpp"

namespace stm32::gpio
{
    GpioPeripheral GPIOA;
    GpioPeripheral GPIOB;
    GpioPeripheral GPIOC;
    GpioPeripheral GPIOD;
    GpioPeripheral GPIOE;
    GpioPeripheral GPIOF;
    GpioPeripheral GPIOG;
    GpioPeripheral GPIOH;
    GpioPeripheral GPIOI;

    void Init()
    {
        GPIOA.Init(GPIOA_BASEADDR);
        GPIOB.Init(GPIOB_BASEADDR);
        GPIOC.Init(GPIOC_BASEADDR);
        GPIOD.Init(GPIOD_BASEADDR);
        GPIOE.Init(GPIOE_BASEADDR);
        GPIOF.Init(GPIOF_BASEADDR);
        GPIOG.Init(GPIOG_BASEADDR);
        GPIOH.Init(GPIOH_BASEADDR);
        GPIOI.Init(GPIOI_BASEADDR);
    }
}

#endif /* GPIO_PORTS_H_ */