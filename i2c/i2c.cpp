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
                fastModeDutyCycle == FmModeDutyCycle::Ratio2 ? 3U : 25U;

            uint16_t ccr = static_cast<uint16_t>(peripheralClockMHz * 1000000U / (ccrMultiplier * serialClockKHz * 1000U));
            device.set_CCR_CCR(ccr & 0x0FFFU);

            // TRISE calculation.
            // Standard mode: TRise (max) = 1000 ns
            // Fast Mode:     TRise (max) = 300 ns
            // See: https://www.nxp.com/docs/en/user-guide/UM10204.pdf
            uint16_t triseMax = mode == MasterModeSelection::StandardMode ? TRiseMaxNs_StandardMode : TRiseMaxNs_FastMode;
            uint32_t triseReg = ((peripheralClockMHz * triseMax) / 1000U) + 1U;
            device.set_TRISE_TRISE(triseReg & 0x3FU);
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

    void I2CPeripheral::MasterSendData(vector<uint8_t> & data, uint8_t slaveAddress)
    {
        GenerateStartCondition();

        ExecuteAddressPhase(slaveAddress, ReadWriteFlag::Write);

        for (uint8_t byte : data)
        {
            SendDataByte(byte);
        }

        while (device.get_SR1_TxE() != DataRegisterEmpty::Empty);
        while (device.get_SR1_BTF() != ByteTransferFinished::Succeeded);

        GenerateStopCondition();
    }

    void I2CPeripheral::GenerateStartCondition()
    {
        // Generate the start condition by setting the START flag in CR1.
        device.set_CR1_START(StartGeneration::StartGeneration);

        // Wait until the start condition is generated.
        while (device.get_SR1_SB() != StartBit::StartConditionGenerated);
    }

    void I2CPeripheral::GenerateStopCondition()
    {
        device.set_CR1_STOP(StopGeneration::StopGeneration);
    }

    void I2CPeripheral::ExecuteAddressPhase(uint8_t slaveAddress, ReadWriteFlag readWriteFlag)
    {
        // Send the address with the read/write bit.
        uint8_t readWriteBit = static_cast<uint8_t>(readWriteFlag) & 0x01U; 
        uint8_t addressByte = (slaveAddress << 1U) | readWriteBit;
        device.set_DR_DR(addressByte);

        // Wait until the address has been matched.
        while (device.get_SR1_ADDR() != AddressSentMatched::AddressMatchedOrTransmitted);

        // Clear the ADDR flag.
        // According to the STM32 reference manual:
        // "This bit is cleared by software reading SR1 register followed reading SR2"
        // See the definition of the ADDR field in the I2C_SR1 register.
        (void)device.get_SR1_ADDR();    // Reading any field should work.
        (void)device.get_SR2_BUSY();    // Reading any field should work.
    }

    void I2CPeripheral::SendDataByte(uint8_t byte)
    {
        // First wait for the TXE flag to indicate that the data register is empty.
        while (device.get_SR1_TxE() != DataRegisterEmpty::Empty);
        
        // Transmit the byte.
        device.set_DR_DR(byte);
    }
} // namespace stm32::i2c
