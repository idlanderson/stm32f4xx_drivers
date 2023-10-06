#ifndef RCC_DEF_HPP_
#define RCC_DEF_HPP_

#include "rcc.hpp"

RCC &rcc = *reinterpret_cast<RCC*>(RCC_BASEADDR);

#endif // RCC_DEF_HPP_