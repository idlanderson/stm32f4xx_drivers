#ifndef RCC_DEF_HPP_
#define RCC_DEF_HPP_

#include "rcc.hpp"

namespace stm32::rcc
{
    RccRegisterMap &RCCReg = *reinterpret_cast<RccRegisterMap*>(RCC_BASEADDR);

    RccPeripheral RCC(RCCReg);
}

#endif // RCC_DEF_HPP_