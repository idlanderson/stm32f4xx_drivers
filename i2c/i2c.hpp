#ifndef I2C_HPP_
#define I2C_HPP_

#include "stm32f4xx.hpp"
#include "i2c_register_map.hpp"
#include <vector>
#include <string>
#include <deque>
#include <functional>

using namespace std;

namespace stm32::i2c
{
    enum class RxTxState : uint8_t
    {
        Idle,
        Transmitting,
        Receiving
    };

    using ErrorCallback = function<void()>;
    using TxCompleteCallback = function<void()>;
    using RxCompleteCallback = function<void(vector<uint8_t> &)>;

    class I2CPeripheral
    {
    public:

        I2CPeripheral(II2CRegisterMap & device) : device(device) 
        {
            // According to the reference manual, OAR1 bit 14 should always be kept at 1 by software.
            device.set_OAR1_RESERVEDBIT14(1U);
        }

        I2CPeripheral(uint32_t addr) : I2CPeripheral(*reinterpret_cast<I2CRegisterMap*>(addr)) { }
        
        void SetDeviceAddress(uint8_t address);
        void SetDeviceAddress(AddressingMode addressingMode, uint16_t address);
        void SetSerialClock(uint8_t peripheralClockMHz, uint16_t serialClockKHz);
        void SetSerialClock(uint8_t peripheralClockMHz, uint16_t serialClockKHz, FmModeDutyCycle fastModeDutyCycle);

        void MasterWriteData(uint8_t data, uint8_t slaveAddress, bool useRepeatedStart = false);
        void MasterWriteData(const vector<uint8_t> & data, uint8_t slaveAddress, bool useRepeatedStart = false);
        void MasterWriteData(const string & data, uint8_t slaveAddress, bool useRepeatedStart = false);
        void MasterWriteData(const char * data, uint8_t slaveAddress, bool useRepeatedStart = false);
        
        vector<uint8_t> MasterReadData(uint32_t length, uint8_t slaveAddress, bool useRepeatedStart = false);

        RxTxState MasterWriteDataAsync(uint8_t data, uint8_t slaveAddress, TxCompleteCallback callback = {}, bool useRepeatedStart = false);
        RxTxState MasterWriteDataAsync(const vector<uint8_t> &data, uint8_t slaveAddress, TxCompleteCallback callback = {}, bool useRepeatedStart = false);
        RxTxState MasterWriteDataAsync(const string &data, uint8_t slaveAddress, TxCompleteCallback callback = {}, bool useRepeatedStart = false);
        RxTxState MasterWriteDataAsync(const char *data, uint8_t slaveAddress, TxCompleteCallback callback = {}, bool useRepeatedStart = false);

        RxTxState MasterReadDataAsync(uint32_t length, uint8_t slaveAddress, RxCompleteCallback callback = {}, bool useRepeatedStart = false);

        void CloseCommunication();
        
        void HandleEventIrq();
        void HandleErrorIrq();

        bool IsBusy();

        void OnBusError(ErrorCallback c) { busErrorCallback = c; }
        void OnArbitrationLost(ErrorCallback c) { arbitrationLostCallback = c; }
        void OnAcknowledgeFailure(ErrorCallback c) { acknowledgeFailureCallback = c; }
        void OnOverrunUnderrun(ErrorCallback c) { overrunUnderrunCallback = c; }
        void OnTimeout(ErrorCallback c) { timeoutCallback = c; }

    private:

        enum class ReadWriteFlag : uint8_t
        {
            Write = 0U,
            Read = 1U
        };

        void SetAcknowledgeEnable(AcknowledgeEnable enable);
        void SetInterruptsEnabled(InterruptEnable enable);
        void GenerateStartCondition();
        void GenerateStopCondition();
        void SendAddress(uint8_t slaveAddress, ReadWriteFlag readWriteFlag);
        void SendDataByte(uint8_t byte);
        void ClearAddressFlag();
        void ClearStopFlag();
        void WaitForStartBit();
        void WaitForAddressFlag();
        void WaitForRxData();

        void MasterReadData_MultiByte(uint32_t length, bool useRepeatedStart, std::vector<uint8_t> & ata);
        void MasterReadData_SingleByte(bool useRepeatedStart, std::vector<uint8_t> & data);

        void HandleEventIrq_SB();
        void HandleEventIrq_ADDR();
        void HandleEventIrq_BTF();
        void HandleEventIrq_TxE();
        void HandleEventIrq_RxNE();
        void HandleEventIrq_STOPF();

        void HandleErrorIrq_BERR();
        void HandleErrorIrq_ARLO();
        void HandleErrorIrq_AF();
        void HandleErrorIrq_OVR();
        void HandleErrorIrq_TIMEOUT();

        const uint8_t  MinPeripheralClockMHz = 2U;
        const uint8_t  MaxPeripheralClockMHz = 50U;
        const uint16_t MinSerialClockKHz = 1U;
        const uint16_t MaxSerialClockKHz_StandardMode = 100U;
        const uint16_t MaxSerialClockKHz_FastMode = 400U;
        const uint16_t TRiseMaxNs_StandardMode = 1000U; // See: https://www.nxp.com/docs/en/user-guide/UM10204.pdf
        const uint16_t TRiseMaxNs_FastMode = 300U;      // See: https://www.nxp.com/docs/en/user-guide/UM10204.pdf

        II2CRegisterMap & device;

        class StateInfo
        {
        public:

            RxTxState State() { return state; }
            uint8_t SlaveAddress() { return slaveAddress; }
            uint32_t LengthToRead() { return lengthToRead; }
            uint32_t RemainingLengthToRead() { return static_cast<uint32_t>(lengthToRead - rxBuffer.size()); }
            bool HasMoreDataToWrite() { return txBuffer.size() > 0U; }
            uint8_t NextDataToWrite()
            {
                if (txBuffer.size() > 0U)
                {
                    uint8_t data = txBuffer.front();
                    txBuffer.pop_front();
                    return data;
                }
                else
                {
                    return 0U;
                }
            }
            bool UseRepeatedStart() { return useRepeatedStart; }
            vector<uint8_t> &RxData() { return rxBuffer; }

            void BeginWrite(uint8_t slaveAddress, const vector<uint8_t> &dataToWrite, bool useRepeatedStart)
            {
                this->state = RxTxState::Transmitting;
                this->slaveAddress = slaveAddress;
                this->txBuffer.assign(dataToWrite.begin(), dataToWrite.end());
                this->rxBuffer.clear();
                this->lengthToRead = 0U;
                this->useRepeatedStart = useRepeatedStart;
            }

            void BeginRead(uint8_t slaveAddress, uint32_t lengthToRead, bool useRepeatedStart)
            {
                this->state = RxTxState::Receiving;
                this->slaveAddress = slaveAddress;
                this->txBuffer.clear();
                this->rxBuffer.clear();
                this->lengthToRead = lengthToRead;
                this->useRepeatedStart = useRepeatedStart;
            }

            void ReadDataByte(uint8_t data)
            {
                this->rxBuffer.push_back(data);
            }

            void Done()
            {
                this->state = RxTxState::Idle;
                this->slaveAddress = 0U;
                this->txBuffer.clear();
                this->lengthToRead = 0U;
                this->useRepeatedStart = false;
            }

            void Reset()
            {
                Done();
                this->rxBuffer.clear();
            }

        private:

            RxTxState state = RxTxState::Idle;
            uint8_t slaveAddress = 0x00U;
            uint32_t lengthToRead = 0U;
            deque<uint8_t> txBuffer = {};
            vector<uint8_t> rxBuffer = {};
            bool useRepeatedStart = false;
        };

        StateInfo stateInfo;

        TxCompleteCallback txCompleteCallback;
        RxCompleteCallback rxCompleteCallback;
        ErrorCallback stopFlagCallback;
        ErrorCallback busErrorCallback;
        ErrorCallback arbitrationLostCallback;
        ErrorCallback acknowledgeFailureCallback;
        ErrorCallback overrunUnderrunCallback;
        ErrorCallback timeoutCallback;
    };
} // namespace stm32::i2c

#endif // I2C_HPP_