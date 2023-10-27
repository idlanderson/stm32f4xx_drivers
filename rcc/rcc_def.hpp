#ifndef RCC_DEF_HPP_
#define RCC_DEF_HPP_

#include "rcc.hpp"

namespace stm32::rcc
{
    RccPeripheral RCC;

    void Init()
    {
        RCC.Init(RCC_BASEADDR);
    }
}

#endif // RCC_DEF_HPP_