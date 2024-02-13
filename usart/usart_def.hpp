#ifndef USART_DEF_HPP_
#define USART_DEF_HPP_

#include "stm32f4xx.hpp"
#include "usart.hpp"

using namespace std;

namespace stm32::usart
{
    UsartRegisterMap USART1RegMap(USART1_BASEADDR);
    UsartRegisterMap USART2RegMap(USART2_BASEADDR);
    UsartRegisterMap USART3RegMap(USART3_BASEADDR);
    UsartRegisterMap UART4RegMap(UART4_BASEADDR);
    UsartRegisterMap UART5RegMap(UART5_BASEADDR);
    UsartRegisterMap USART6RegMap(USART6_BASEADDR);

    UsartPeripheral USART1(USART1RegMap);
    UsartPeripheral USART2(USART2RegMap);
    UsartPeripheral USART3(USART3RegMap);
    UsartPeripheral UART4(UART4RegMap);
    UsartPeripheral UART5(UART5RegMap);
    UsartPeripheral USART6(USART6RegMap);
} // namespace stm32::usart

#endif // USART_DEF_HPP_