#ifndef GPIO_PORTS_H_
#define GPIO_PORTS_H_

#include "stm32f4xx.hpp"
#include "gpio.hpp"

namespace stm32::gpio
{
    static GpioRegisterMap &GPIOAReg = *reinterpret_cast<GpioRegisterMap*>(GPIOA_BASEADDR);
    static GpioRegisterMap &GPIOBReg = *reinterpret_cast<GpioRegisterMap*>(GPIOB_BASEADDR);
    static GpioRegisterMap &GPIOCReg = *reinterpret_cast<GpioRegisterMap*>(GPIOC_BASEADDR);
    static GpioRegisterMap &GPIODReg = *reinterpret_cast<GpioRegisterMap*>(GPIOD_BASEADDR);
    static GpioRegisterMap &GPIOEReg = *reinterpret_cast<GpioRegisterMap*>(GPIOE_BASEADDR);
    static GpioRegisterMap &GPIOFReg = *reinterpret_cast<GpioRegisterMap*>(GPIOF_BASEADDR);
    static GpioRegisterMap &GPIOGReg = *reinterpret_cast<GpioRegisterMap*>(GPIOG_BASEADDR);
    static GpioRegisterMap &GPIOHReg = *reinterpret_cast<GpioRegisterMap*>(GPIOH_BASEADDR);
    static GpioRegisterMap &GPIOIReg = *reinterpret_cast<GpioRegisterMap*>(GPIOI_BASEADDR);

/*
    GpioPeripheral GPIOA(GPIOAReg);
    GpioPeripheral GPIOB(GPIOBReg);
    GpioPeripheral GPIOC(GPIOCReg);
    GpioPeripheral GPIOD(GPIODReg);
    GpioPeripheral GPIOE(GPIOEReg);
    GpioPeripheral GPIOF(GPIOFReg);
    GpioPeripheral GPIOG(GPIOGReg);
    GpioPeripheral GPIOH(GPIOHReg);
    GpioPeripheral GPIOI(GPIOIReg);
    */
}

#endif /* GPIO_PORTS_H_ */