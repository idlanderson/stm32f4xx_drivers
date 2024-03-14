#ifndef USART_HPP_
#define USART_HPP_

#include "stm32f4xx.hpp"
#include "usart_register_map.hpp"
#include <vector>
#include <string>
#include <functional>

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

    enum class RxTxState : uint8_t
    {
        Idle,
        Transmitting,
        Receiving
    };

    using TxCompleteCallback = function<void()>;
    using RxCompleteCallback = function<void(vector<uint8_t> &)>;

    class UsartPeripheral
    {
    public:

        UsartPeripheral(IUsartRegisterMap & device) : device(device) { }
        UsartPeripheral(uint32_t addr) : UsartPeripheral(*reinterpret_cast<UsartRegisterMap*>(addr)) { }

        void SetMode(UsartMode mode);
        void SetBaudRate(uint32_t peripheralClockInHz, uint32_t baudRate, OversamplingMode oversamplingMode);
        void SetParity(Parity parity);
        void SetWordLength(WordLength wordLength);
        void SetStopBits(StopBits stopBits);
        void SetHardwareFlowControl(bool rtsEnable, bool ctsEnable);

        void SendData(const vector<uint8_t> & data);
        void SendData(const string & data);
        void SendData(const char * data);
        vector<uint8_t> ReceiveData(uint32_t length);
        
        void SendDataAsync(const vector<uint8_t> & data, TxCompleteCallback callback = {});
        void SendDataAsync(const string & data, TxCompleteCallback callback = {});
        void SendDataAsync(const char * data, TxCompleteCallback callback = {});
        void ReceiveDataAsync(uint32_t length, RxCompleteCallback callback = {});

        bool IsBusy();

        void HandleIrq();

    private:

        void HandleIrq_TXE();
        void HandleIrq_RXNE();

        void SendNext(const vector<uint8_t> & data, uint16_t & i);
        void ReceiveNext(vector<uint8_t> & data, uint32_t length);

        IUsartRegisterMap & device;

        RxTxState state = RxTxState::Idle;

        WordLength wordLength = WordLength::_8DataBits;
        ParityControlEnable parityEnabled = ParityControlEnable::Disabled;

        vector<uint8_t> txBuffer = {};
        uint16_t txBufferIndex = 0U;
        TxCompleteCallback txCompleteCallback = {};

        vector<uint8_t> rxBuffer = {};
        uint32_t rxLength = 0U;
        RxCompleteCallback rxCompleteCallback = {};
    };
}

#endif // USART_HPP_