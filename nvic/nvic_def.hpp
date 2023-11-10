#ifndef NVIC_DEF_HPP_
#define NVIC_DEF_HPP_

#include "nvic.hpp"

namespace stm32::nvic
{
    NvicRegisterMap nvicRegMap(NVIC_BASEADDR);
    NvicPeripheral NVIC(nvicRegMap);
}

#endif // NVIC_DEF_HPP_