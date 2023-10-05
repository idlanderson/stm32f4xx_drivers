#ifndef GPIO_PORTS_H_
#define GPIO_PORTS_H_

#include "gpio.hpp"

GPIO &GPIOA = *reinterpret_cast<GPIO*>(GPIOA_BASEADDR);
GPIO &GPIOB = *reinterpret_cast<GPIO*>(GPIOB_BASEADDR);
GPIO &GPIOC = *reinterpret_cast<GPIO*>(GPIOC_BASEADDR);
GPIO &GPIOD = *reinterpret_cast<GPIO*>(GPIOD_BASEADDR);
GPIO &GPIOE = *reinterpret_cast<GPIO*>(GPIOE_BASEADDR);
GPIO &GPIOF = *reinterpret_cast<GPIO*>(GPIOF_BASEADDR);
GPIO &GPIOG = *reinterpret_cast<GPIO*>(GPIOG_BASEADDR);
GPIO &GPIOH = *reinterpret_cast<GPIO*>(GPIOH_BASEADDR);
GPIO &GPIOI = *reinterpret_cast<GPIO*>(GPIOI_BASEADDR);

#endif /* GPIO_PORTS_H_ */