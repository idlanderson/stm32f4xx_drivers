#ifndef GPIO_PORTS_H_
#define GPIO_PORTS_H_

#include "stm32f4xx.hpp"
#include "gpio.hpp"

namespace stm32::gpio
{
    GpioRegisterMap GPIOARegMap(GPIOA_BASEADDR);
    GpioRegisterMap GPIOBRegMap(GPIOB_BASEADDR);
    GpioRegisterMap GPIOCRegMap(GPIOC_BASEADDR);
    GpioRegisterMap GPIODRegMap(GPIOD_BASEADDR);
    GpioRegisterMap GPIOERegMap(GPIOE_BASEADDR);
    GpioRegisterMap GPIOFRegMap(GPIOF_BASEADDR);
    GpioRegisterMap GPIOGRegMap(GPIOG_BASEADDR);
    GpioRegisterMap GPIOHRegMap(GPIOH_BASEADDR);
    GpioRegisterMap GPIOIRegMap(GPIOI_BASEADDR);

    GpioPeripheral GPIOA(GPIOARegMap);
    GpioPeripheral GPIOB(GPIOBRegMap);
    GpioPeripheral GPIOC(GPIOCRegMap);
    GpioPeripheral GPIOD(GPIODRegMap);
    GpioPeripheral GPIOE(GPIOERegMap);
    GpioPeripheral GPIOF(GPIOFRegMap);
    GpioPeripheral GPIOG(GPIOGRegMap);
    GpioPeripheral GPIOH(GPIOHRegMap);
    GpioPeripheral GPIOI(GPIOIRegMap);
}

#endif /* GPIO_PORTS_H_ */