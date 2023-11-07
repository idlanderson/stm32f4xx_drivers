#ifndef SYSCFG_DEF_HPP_
#define SYSCFG_DEF_HPP_

#include "stm32f4xx.hpp"
#include "syscfg.hpp"

namespace stm32::syscfg
{
    SyscfgRegisterMap syscfgRegMap(SYSCFG_BASEADDR);
    SyscfgPeripheral SYSCFG(syscfgRegMap);
}

#endif // SYSCFG_DEF_HPP_