#ifndef GPIO_PORTS_H_
#define GPIO_PORTS_H_

#include "stm32f4xx.hpp"
#include "gpio.hpp"

namespace stm32::gpio
{
    GpioPeripheral GPIOA(GPIOA_BASEADDR);
    GpioPeripheral GPIOB(GPIOB_BASEADDR);
    GpioPeripheral GPIOC(GPIOC_BASEADDR);
    GpioPeripheral GPIOD(GPIOD_BASEADDR);
    GpioPeripheral GPIOE(GPIOE_BASEADDR);
    GpioPeripheral GPIOF(GPIOF_BASEADDR);
    GpioPeripheral GPIOG(GPIOG_BASEADDR);
    GpioPeripheral GPIOH(GPIOH_BASEADDR);
    GpioPeripheral GPIOI(GPIOI_BASEADDR);
}

#endif /* GPIO_PORTS_H_ */