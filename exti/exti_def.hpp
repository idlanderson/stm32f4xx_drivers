#ifndef EXTI_DEF_HPP_
#define EXTI_DEF_HPP_

#include "exti.hpp"

namespace stm32::exti
{
    ExtiRegisterMap extiRegMap(EXTI_BASEADDR);
    ExtiPeripheral EXTI(extiRegMap);
}

#endif // EXTI_DEF_HPP_