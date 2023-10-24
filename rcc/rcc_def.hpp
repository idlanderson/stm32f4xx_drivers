#ifndef RCC_DEF_HPP_
#define RCC_DEF_HPP_

#include "rcc.hpp"

using namespace stm32::rcc;

RccPeripheral &RCC_ = *reinterpret_cast<RccPeripheral*>(RCC_BASEADDR);

#endif // RCC_DEF_HPP_