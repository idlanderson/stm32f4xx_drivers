#ifndef USART_HPP_
#define USART_HPP_

#include "stm32f4xx.hpp"
#include "usart_register_map.hpp"

using namespace std;

namespace stm32::usart
{
    class UsartPeripheral
    {
    public:
        UsartPeripheral(IUsartRegisterMap & device) : device(device) { }
        UsartPeripheral(uint32_t addr) : UsartPeripheral(*reinterpret_cast<UsartRegisterMap*>(addr)) { }
    private:
        IUsartRegisterMap & device;
    };
}

#endif // USART_HPP_