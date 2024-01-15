#ifndef I2C_HPP_
#define I2C_HPP_

#include "stm32f4xx.hpp"
#include "i2c_register_map.hpp"
#include <vector>

using namespace std;

namespace stm32::i2c
{
    class I2CPeripheral
    {
    public:

        I2CPeripheral(II2CRegisterMap & device) : device(device) 
        {
            // According to the reference manual, OAR1 bit 14
            // should always be kept at 1 by software.
            device.set_OAR1_RESERVEDBIT14(1U);
        }

        I2CPeripheral(uint32_t addr) : device(*reinterpret_cast<I2CRegisterMap*>(addr)) 
        {
            // According to the reference manual, OAR1 bit 14
            // should always be kept at 1 by software.
            device.set_OAR1_RESERVEDBIT14(1U);
        }
        
        void SetAcknowledgeEnable(AcknowledgeEnable enable);
        void SetDeviceAddress(uint8_t address);
        void SetDeviceAddress(AddressingMode addressingMode, uint16_t address);
        void SetSerialClock(uint8_t peripheralClockMHz, uint16_t serialClockKHz);
        void SetSerialClock(uint8_t peripheralClockMHz, uint16_t serialClockKHz, FmModeDutyCycle fastModeDutyCycle);
        void MasterSendData(vector<uint8_t> & data, uint8_t slaveAddress);

    private:

        enum class ReadWriteFlag : uint8_t
        {
            Write = 0U,
            Read  = 1U
        };

        bool SetPeripheralClockFreq(uint8_t frequency);
        void GenerateStartCondition();
        void GenerateStopCondition();
        void ExecuteAddressPhase(uint8_t slaveAddress, ReadWriteFlag readWriteFlag);
        void SendDataByte(uint8_t byte);

        const uint8_t MinPeripheralClockMHz = 2U;
        const uint8_t MaxPeripheralClockMHz = 50U;
        const uint16_t MinSerialClockKHz = 1U;
        const uint16_t MaxSerialClockKHz_StandardMode = 100U;
        const uint16_t MaxSerialClockKHz_FastMode = 400U;
        const uint16_t TRiseMaxNs_StandardMode = 1000U; // See: https://www.nxp.com/docs/en/user-guide/UM10204.pdf
        const uint16_t TRiseMaxNs_FastMode = 300U;      // See: https://www.nxp.com/docs/en/user-guide/UM10204.pdf

        II2CRegisterMap & device;
    };
} // namespace stm32::i2c

#endif // I2C_HPP_