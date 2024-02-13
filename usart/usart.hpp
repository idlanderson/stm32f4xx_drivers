#ifndef USART_HPP_
#define USART_HPP_

#include "stm32f4xx.hpp"
#include "usart_register_map.hpp"
#include <vector>

using namespace std;

namespace stm32::usart
{
    enum class UsartMode
    {
        Disabled,
        Rx,
        Tx,
        RxTx
    };

    enum class Parity
    {
        None,
        Even,
        Odd
    };

    class UsartPeripheral
    {
    public:
        UsartPeripheral(IUsartRegisterMap & device) : device(device) { }
        UsartPeripheral(uint32_t addr) : UsartPeripheral(*reinterpret_cast<UsartRegisterMap*>(addr)) { }

        void SetMode(UsartMode mode);
        void SetParity(Parity parity);
        void SetWordLength(WordLength wordLength);
        void SetStopBits(StopBits stopBits);
        void SetHardwareFlowControl(bool rtsEnable, bool ctsEnable);
        void SendData(const vector<uint8_t> & data);
    private:
        IUsartRegisterMap & device;
    };
}

#endif // USART_HPP_