#ifndef RCC_DEF_HPP_
#define RCC_DEF_HPP_

#include "rcc.hpp"

namespace stm32::rcc
{
    RccRegisterMap rccRegMap(RCC_BASEADDR);
    RccPeripheral RCC(rccRegMap);
}

#endif // RCC_DEF_HPP_