#include "i2c.hpp"

namespace stm32::i2c
{
    void I2CPeripheral::SetAcknowledgeEnable(AcknowledgeEnable enable)
    {
        device.set_CR1_ACK(enable);
    }

    void I2CPeripheral::SetSerialClock(uint8_t peripheralClockMHz, uint16_t serialClockKHz)
    {
        SetSerialClock(peripheralClockMHz, serialClockKHz, (FmModeDutyCycle)0U);
    }

    void I2CPeripheral::SetSerialClock(uint8_t peripheralClockMHz, uint16_t serialClockKHz, FmModeDutyCycle fastModeDutyCycle)
    {
        if (peripheralClockMHz >= MinPeripheralClockMHz &&
            peripheralClockMHz <= MaxPeripheralClockMHz &&
            serialClockKHz     >= MinSerialClockKHz &&
            serialClockKHz     <= MaxSerialClockKHz_FastMode)
        {
            device.set_CR2_FREQ(peripheralClockMHz);

            MasterModeSelection mode = 
                serialClockKHz > MaxSerialClockKHz_StandardMode ? 
                MasterModeSelection::FastMode : 
                MasterModeSelection::StandardMode;

            device.set_CCR_FS(mode);

            if (mode == MasterModeSelection::FastMode)
            {
                device.set_CCR_DUTY(fastModeDutyCycle);
            }

            // CCR calculation.
            // Standard Mode:
            //      CCR = FPCLK1 / (2 * FSCL)
            // Fast Mode (Duty Cycle = 0 (tlow / thigh = 2)):
            //      CCR = FPCLK1 / (3 * FSCL)
            // Fast Mode (Duty Cycle = 1 (tlow / thigh = 16/9)):
            //      CCR = FPCLK1 / (25 * FSCL)
            // See the definition of the CCR field in the I2C_CCR register in the reference manual.
            uint8_t ccrMultiplier = 
                mode == MasterModeSelection::StandardMode ? 2U :
                fastModeDutyCycle == FmModeDutyCycle::LowHighRatio2 ? 3U : 25U;

            uint16_t ccr = static_cast<uint16_t>(peripheralClockMHz * 1000000U / (ccrMultiplier * serialClockKHz * 1000U));
            device.set_CCR_CCR(ccr & 0x0FFFU);
        }
    }

    void I2CPeripheral::SetDeviceAddress(uint8_t address)
    {
        SetDeviceAddress(AddressingMode::_7BitSlaveAddress, static_cast<uint16_t>(address));
    }

    void I2CPeripheral::SetDeviceAddress(AddressingMode addressingMode, uint16_t address)
    {
        device.set_OAR1_ADDMODE(addressingMode);

        if (addressingMode == AddressingMode::_10BitSlaveAddress)
        {
            device.set_OAR1_ADD(address & 0x03FFU);
        }
        else if (addressingMode == AddressingMode::_7BitSlaveAddress)
        {
            device.set_OAR1_ADD((address & 0x7FU) << 1U);
        }
    }
} // namespace stm32::i2c
