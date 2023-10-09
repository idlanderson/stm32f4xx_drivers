#ifndef RCC_DEF_HPP_
#define RCC_DEF_HPP_

#include "rcc.hpp"

RCC &RCC_ = *reinterpret_cast<RCC*>(RCC_BASEADDR);

#endif // RCC_DEF_HPP_