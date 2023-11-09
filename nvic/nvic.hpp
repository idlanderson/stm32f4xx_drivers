#ifndef NVIC_HPP_
#define NVIC_HPP_

#include "nvic_register_map.hpp"

namespace stm32::nvic
{
    class NvicPeripheral
    {
    public:
        NvicPeripheral(INvicRegisterMap & device) : device(device) { }
    private:
        INvicRegisterMap & device;
    };
}

#endif // NVIC_HPP_