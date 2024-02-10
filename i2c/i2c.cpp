#include "i2c.hpp"

namespace stm32::i2c
{
    /// @return bool value indicating whether or not the I2C peripheral is currently busy, either transmitting or receiving.
    bool I2CPeripheral::IsBusy()
    {
        return stateInfo.State() != RxTxState::Idle;
    }

    /// @brief Configures the serial clock of the I2C peripheral.
    /// @param peripheralClockMHz The peripheral clock frequency, in MHz. Valid values: 2 to 50 MHz.
    /// @param serialClockKHz The targeted serial clock in KHz. Valid values: 1 to 400 KHz. The maximum clock speed for
    /// Standard Mode is 100 KHz. Anything above 100 KHz is considered Fast Mode. If a Fast Mode frequency is used, then
    /// the duty cycle defaults to a ratio of 2.
    void I2CPeripheral::SetSerialClock(uint8_t peripheralClockMHz, uint16_t serialClockKHz)
    {
        SetSerialClock(peripheralClockMHz, serialClockKHz, (FmModeDutyCycle)0U);
    }

    /// @brief Configures the serial clock of the I2C peripheral.
    /// @param peripheralClockMHz The peripheral clock frequency, in MHz. Valid values: 2 to 50 MHz.
    /// @param serialClockKHz The targeted serial clock in KHz. Valid values: 1 to 400 KHz. The maximum clock speed for
    /// Standard Mode is 100 KHz. Anything above 100 KHz is considered Fast Mode.
    /// @param fastModeDutyCycle The duty cycle to use in Fast Mode, either a ratio of 2 or 16/9.
    void I2CPeripheral::SetSerialClock(uint8_t peripheralClockMHz, uint16_t serialClockKHz, FmModeDutyCycle fastModeDutyCycle)
    {
        if (peripheralClockMHz >= MinPeripheralClockMHz &&
            peripheralClockMHz <= MaxPeripheralClockMHz &&
            serialClockKHz     >= MinSerialClockKHz &&
            serialClockKHz     <= MaxSerialClockKHz_FastMode)
        {
            device.set_CR1_PE(PeripheralEnable::PeripheralEnable);

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

    /// @brief Sets the device's slave address. A 7-bit address is assumed.
    /// @param address The device's 7-bit slave address. Valid values: 0-127
    void I2CPeripheral::SetDeviceAddress(uint8_t address)
    {
        SetDeviceAddress(AddressingMode::_7BitSlaveAddress, static_cast<uint16_t>(address));
    }

    /// @brief Sets the device's slave address. Either a 7-bit or 10-bit slave address can be supplied.
    /// @param addressingMode The addressing mode (7-bit or 10-bit).
    /// @param address The device's slave address. Valid values for 7-bit: 0-127. Valid values for 10-bit: 0-1023
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

    /// @brief Writes one byte of data in Master Mode to the specified slave address. 
    /// This function will block until the write is complete.
    /// @param data The data byte to write.
    /// @param slaveAddress The address of the slave.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    void I2CPeripheral::MasterWriteData(uint8_t data, uint8_t slaveAddress, bool useRepeatedStart)
    {
        vector<uint8_t> v { data };
        MasterWriteData(v, slaveAddress, useRepeatedStart);
    }

    /// @brief Writes a C-style character string in Master Mode to the specified slave address.
    /// This function will block until the write is complete.
    /// @param data A pointer to the character string to write.
    /// @param slaveAddress The address of the slave.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    void I2CPeripheral::MasterWriteData(const char * data, uint8_t slaveAddress, bool useRepeatedStart)
    {
        string s(data);
        MasterWriteData(s, slaveAddress, useRepeatedStart);
    }

    /// @brief Writes an std::string in Master Mode to the specified slave address.
    /// This function will block until the write is complete.
    /// @param data The string to write.
    /// @param slaveAddress The address of the slave.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    void I2CPeripheral::MasterWriteData(const string & data, uint8_t slaveAddress, bool useRepeatedStart)
    {
        vector<uint8_t> dataVector(data.begin(), data.end());
        MasterWriteData(dataVector, slaveAddress, useRepeatedStart);
    }

    /// @brief Writes data in Master Mode to the specified slave address.
    /// This function will block until the write is complete.
    /// @param data The data to write.
    /// @param slaveAddress The address of the slave.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    void I2CPeripheral::MasterWriteData(const vector<uint8_t> & data, uint8_t slaveAddress, bool useRepeatedStart)
    {
        SetAcknowledgeEnable(AcknowledgeEnable::AcknowledgeReturned);

        GenerateStartCondition();
        WaitForStartBit();

        SendAddress(slaveAddress, ReadWriteFlag::Write);
        WaitForAddressFlag();
        ClearAddressFlag();

        for (uint8_t byte : data)
        {
            SendDataByte(byte);
        }

        while (device.get_SR1_TxE() != DataRegisterEmpty::Empty);
        while (device.get_SR1_BTF() != ByteTransferFinished::Succeeded);

        if (!useRepeatedStart)
        {
            GenerateStopCondition();
        }
    }

    /// @brief Reads data in Master Mode from the specified slave address.
    /// This function will block until the write is complete.
    /// @param length The length of the data to read.
    /// @param slaveAddress The address of the slave.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    /// @return A vector containing the data read from the slave.
    vector<uint8_t> I2CPeripheral::MasterReadData(uint32_t length, uint8_t slaveAddress, bool useRepeatedStart)
    {
        vector<uint8_t> data;

        if (length == 0U) return data;

        SetAcknowledgeEnable(AcknowledgeEnable::AcknowledgeReturned);

        GenerateStartCondition();
        WaitForStartBit();

        SendAddress(slaveAddress, ReadWriteFlag::Read);
        WaitForAddressFlag();
        ClearAddressFlag();

        if (length == 1)
        {
            MasterReadData_SingleByte(useRepeatedStart, data);
        }
        else if (length > 1)
        {
            MasterReadData_MultiByte(length, useRepeatedStart, data);
        }

        SetAcknowledgeEnable(AcknowledgeEnable::AcknowledgeReturned);

        return data;
    }

    inline void I2CPeripheral::MasterReadData_SingleByte(bool useRepeatedStart, std::vector<uint8_t> & data)
    {
        SetAcknowledgeEnable(AcknowledgeEnable::NoAcknowledgeReturned);

        if (!useRepeatedStart)
        {
            GenerateStopCondition();
        }

        WaitForRxData();

        // Read the data.
        uint8_t dataByte = device.get_DR_DR();
        data.push_back(dataByte);
    }

    inline void I2CPeripheral::MasterReadData_MultiByte(uint32_t length, bool useRepeatedStart, std::vector<uint8_t> & data)
    {
        for (uint32_t i = length; i > 0U; i--)
        {
            WaitForRxData();

            if (i == 2U)
            {
                SetAcknowledgeEnable(AcknowledgeEnable::NoAcknowledgeReturned);

                if (!useRepeatedStart)
                {
                    GenerateStopCondition();
                }
            }

            // Read the data.
            uint8_t dataByte = device.get_DR_DR();
            data.push_back(dataByte);
        }
    }

    /// @brief Writes one byte of data in Master Mode to the specified slave address. 
    /// This function is non-blocking.
    /// @param data The data byte to write.
    /// @param slaveAddress The address of the slave.
    /// @param callback The application-supplied callback which to invoke when the write operation is complete.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    /// @return RxTxState, indicating the current state of the I2C peripheral.
    RxTxState I2CPeripheral::MasterWriteDataAsync(uint8_t data, uint8_t slaveAddress, TxCompleteCallback callback, bool useRepeatedStart)
    {
        vector<uint8_t> v { data };
        return MasterWriteDataAsync(v, slaveAddress, callback, useRepeatedStart);
    }

    /// @brief Writes a C-style character string in Master Mode to the specified slave address.
    /// This function is non-blocking.
    /// @param data The data byte to write.
    /// @param slaveAddress The address of the slave.
    /// @param callback The application-supplied callback which to invoke when the write operation is complete.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    /// @return RxTxState, indicating the current state of the I2C peripheral.
    RxTxState I2CPeripheral::MasterWriteDataAsync(const char * data, uint8_t slaveAddress, TxCompleteCallback callback, bool useRepeatedStart)
    {
        string s(data);
        return MasterWriteDataAsync(s, slaveAddress, callback, useRepeatedStart);
    }

    /// @brief Writes an std::string in Master Mode to the specified slave address.
    /// This function is non-blocking.
    /// @param data The data byte to write.
    /// @param slaveAddress The address of the slave.
    /// @param callback The application-supplied callback which to invoke when the write operation is complete.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    /// @return RxTxState, indicating the current state of the I2C peripheral.
    RxTxState I2CPeripheral::MasterWriteDataAsync(const string & data, uint8_t slaveAddress, TxCompleteCallback callback, bool useRepeatedStart)
    {
        vector<uint8_t> dataVector(data.begin(), data.end());
        return MasterWriteDataAsync(dataVector, slaveAddress, callback, useRepeatedStart);
    }

    /// @brief Writes data in Master Mode to the specified slave address. This function is non-blocking.
    /// @param data The data byte to write.
    /// @param slaveAddress The address of the slave.
    /// @param callback The application-supplied callback which to invoke when the write operation is complete.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    /// @return RxTxState, indicating the current state of the I2C peripheral.
    /// @details This function utilizes the hardware interrupts to transmit the data asynchronously. The sequence of events is as follows:
    ///  Master enables interrupts
    ///  Master generates the Start condition
    ///  EV5 IRQ: SB = 1 (Start condition generated)
    ///      Master clears SB (Read SR1 and write DR with Address)
    ///      Master transmits Slave Address with R/W = 0 (Write)
    ///      Slave sends ACK
    ///  EV6 IRQ: ADDR = 1 (Address transmitted)
    ///      Master clears ADDR (Read SR1 and SR2)
    ///  EV8_1 IRQ: TxE = 1 (Shift register empty, DR empty)
    ///      Master transmits the first byte
    ///      Slave sends ACK
    ///  EV8 IRQ: TxE = 1 (Shift register not empty, DR empty)
    ///      Master transmits next byte
    ///      Slave sends ACK
    ///      EV8 repeats until all bytes are transmitted...
    ///  EV8_2 IRQ: TxE = 1 and BTF = 1 (Shift register empty, DR empty). This indicates that the transmission is complete.
    ///      Master generates the Stop condition
    ///      Master disables interrupts
    /// See the "Transfer sequence diagram for master transmitter" in the Reference Manual.
    RxTxState I2CPeripheral::MasterWriteDataAsync(const vector<uint8_t> & data, uint8_t slaveAddress, TxCompleteCallback callback, bool useRepeatedStart)
    {
        if (stateInfo.State() == RxTxState::Idle)
        {
            txCompleteCallback = callback;

            stateInfo.BeginWrite(slaveAddress, data, useRepeatedStart);

            SetInterruptsEnabled(InterruptEnable::InterruptEnable);

            GenerateStartCondition();

            // Next: IRQ EV5 (SB=1) will be triggered. See HandleEventIrq_SB.
        }

        return stateInfo.State();
    }

    /// @brief Reads data in Master Mode from the specified slave address. This function is non-blocking.
    /// @param length The length of the data to read.
    /// @param slaveAddress The address of the slave.
    /// @param callback The application-supplied callback which to invoke when the read operation is complete.
    /// @param useRepeatedStart Specifies whether or not to use Repeated Start.
    /// @return RxTxState, indicating the current state of the I2C peripheral.
    /// @details This function utilizes the hardware interrupts to read the data asynchronously. The sequence of events is as follows:
    ///  Master enables interrupts
    ///  Master generates Start condition
    ///  EV5 IRQ: SB = 1 (Start condition generated)
    ///      Master clears SB (Read SR1 and write DR with Address)
    ///      Master transmits Slave Address with R/W = 1 (Read)
    ///      Slave sends ACK
    ///  EV6 IRQ: ADDR = 1 (Address transmitted)
    ///      If only 1 byte is expected from the Slave:
    ///         Master disables ACK
    ///      Master clears ADDR (Read SR1 and SR2)
    ///  Slave transmits a byte to Master
    ///      If only 1 byte is expected:
    ///         Master sends NACK. EV7_1b IRQ will occur next.
    ///      Otherwise:
    ///         Master sends ACK. EV7 IRQ will occur next.
    ///  EV7 IRQ: RxNE = 1 (DR is full, more bytes expected)
    ///      Master reads DR
    ///  Slave continues to send bytes, and EV7 repeats, until...
    ///  EV7_1a IRQ: RxNE = 1 (DR is full, 2nd last byte arriving)
    ///      Master reads DR. Only 1 byte is left to receive.
    ///      Master disables ACK
    ///  EV7_1b IRQ: RxNE = 1 (DR is full, last byte is arriving)
    ///      Master reads DR. All bytes have been received.
    ///      Master generates Stop condition
    RxTxState I2CPeripheral::MasterReadDataAsync(uint32_t length, uint8_t slaveAddress, RxCompleteCallback callback, bool useRepeatedStart)
    {
        if (stateInfo.State() == RxTxState::Idle && length > 0U)
        {
            rxCompleteCallback = callback;

            stateInfo.BeginRead(slaveAddress, length, useRepeatedStart);

            SetInterruptsEnabled(InterruptEnable::InterruptEnable);

            GenerateStartCondition();

            // Next: IRQ EV5 (SB=1) will be triggered. See HandleEventIrq_SB.
        }

        return stateInfo.State();
    }

    void I2CPeripheral::SlaveWriteData(uint8_t data)
    {
        if (device.get_SR2_MSL() == MasterSlave::SlaveMode)
        {
            device.set_DR_DR(data);
        }
    }

    uint8_t I2CPeripheral::SlaveReadData()
    {
        return device.get_SR2_MSL() == MasterSlave::SlaveMode ? device.get_DR_DR() : 0U;
    }

    void I2CPeripheral::CloseCommunication()
    {
        if (device.get_SR2_MSL() == MasterSlave::MasterMode)
        {
            GenerateStopCondition();
        }

        SetInterruptsEnabled(InterruptEnable::InterruptDisable);
        SetAcknowledgeEnable(AcknowledgeEnable::AcknowledgeReturned);

        stateInfo.Reset();
    }

    /// @brief This function is meant to be invoked from an interrupt service routine to handle I2C_EV interrupts.
    void I2CPeripheral::HandleEventIrq()
    {
        if (device.get_CR2_ITEVTEN() == InterruptEnable::InterruptEnable)
        {
            if (device.get_SR1_SB() == StartBit::StartConditionGenerated)
            {
                HandleEventIrq_SB();
            }

            if (device.get_SR1_ADDR() == AddressSentMatched::AddressMatchedOrTransmitted)
            {
                HandleEventIrq_ADDR();
            }

            if (device.get_SR1_BTF() == ByteTransferFinished::Succeeded)
            {
                HandleEventIrq_BTF();
            }

            if (device.get_SR1_STOPF() == StopDetection::StopConditionDetected)
            {
                HandleEventIrq_STOPF();
            }

            if (device.get_CR2_ITBUFEN() == InterruptEnable::InterruptEnable)
            {
                if (device.get_SR1_TxE() == DataRegisterEmpty::Empty)
                {
                    HandleEventIrq_TxE();
                }

                if (device.get_SR1_RxNE() == DataRegisterNotEmpty::NotEmpty)
                {
                    HandleEventIrq_RxNE();
                }
            }
        }
    }

    inline void I2CPeripheral::HandleEventIrq_SB()
    {
        // IRQ EV5 (SB=1)
        // SB flag is set (Master Mode only). The Start Condition was generated successfully.

        if (device.get_SR2_MSL() == MasterSlave::MasterMode)
        {
            // Execute the address phase. SB will be cleared when DR is written.
            SendAddress(
                stateInfo.SlaveAddress(), 
                stateInfo.State() == RxTxState::Transmitting ? ReadWriteFlag::Write : ReadWriteFlag::Read);

            // Next: IRQ EV6 (ADDR=1) will be triggered.
        }
    }

    inline void I2CPeripheral::HandleEventIrq_ADDR()
    {
        // Master Mode: IRQ EV6 (ADDR=1). The address was successfully sent and ACK'ed.
        // Slave Mode:  IRQ EV1 (ADDR=1). The address was successfully matched.
        
        if (device.get_SR2_MSL() == MasterSlave::MasterMode && 
            stateInfo.State() == RxTxState::Receiving && 
            stateInfo.LengthToRead() == 1U)
        {
            // When receiving only one byte in Master Mode, the ACK bit needs to be disabled during EV6,
            // before clearing the ADDR flag (below). This will cause the master to generate a NACK,
            // which tells the slave that no more bytes should be written.
            SetAcknowledgeEnable(AcknowledgeEnable::NoAcknowledgeReturned);
        }
        
        ClearAddressFlag();

        // Next: 
        //  Master Transmission:
        //      IRQ EV8_1 (TxE = 1) will be triggered. See HandleEventIrq_TxE.
        //  Master Reception:
        //      Slave will transmit a byte.
        //      IRQ EV7/EV7_1 (RxNE = 1) will be triggered. See HandleEventIrq_RxNE.
        //  Slave Transmission:
        //      IRQ EV3-1/EV3 (TxE = 1) will be triggered. HandleEventIrq_TxE.
        //  Slave Reception:
        //      Master will transmit a byte.
        //      IRQ EV2 (RxNE = 1) will be triggered. See HandleEventIrq_RxNE.
    }

    inline void I2CPeripheral::HandleEventIrq_TxE()
    {
        if (device.get_SR2_MSL() == MasterSlave::MasterMode)
        {
            // Master transmitter. IRQ EV8 (TxE=1). DR is ready to receive a byte.

            if (stateInfo.State() == RxTxState::Transmitting && stateInfo.HasMoreDataToWrite())
            {
                device.set_DR_DR(stateInfo.NextDataToWrite());

                // Next:
                //  If there are more data bytes to be transmitted:
                //      IRQ EV8 will be triggered again.
                //  Otherwise (i.e. we're done transmiting):
                //      IRQ EV8_2 will be triggered. See HandleEventIrq_BTF.
            }
        }
        else
        {
            // Slave transmitter. IRQ EV3-1 or IRV EV3 (TxE=1).

            if (device.get_SR2_TRA() == TransmitterReceiver::DataBytesTransmitted)
            {
                // Slave device is in transmitter mode (i.e. the Master is requesting data).
                // Notify the application to send data. The application can call
                // SlaveWriteData to send the next byte.

                if (slaveDataRequestCallback)
                {
                    slaveDataRequestCallback();
                }
            }
        }
    }

    inline void I2CPeripheral::HandleEventIrq_BTF()
    {
        // IRQ EV8_2 (BTF=1). The BTF flag has a complex interpretation, so some explanation may be helpful.
        
        // During Transmission:
        //  When TxE = 1. DR and the underlying shift register are both empty.
        //  BTF indicates that the I2C peripheral is ready to send the next byte of data, but the software hasn't
        //  yet written any data to DR, so there's nothing to send. The clock will be stretched by the master until
        //  the software writes to DR, if clock stretching is enabled (CR1_NOSTRETCH=0). Otherwise a duplicate byte 
        //  of data will be sent and an underrun error will occur (see the SR1_OVR flag).
        //  This situation can have two interpretations:
        //  1) There are more bytes yet to send, but the software isn't yet ready to send the next byte, for whatever
        //     reason. The software may be too slow in populating the DR register. This could potentially indicate
        //     something abnormal with the software.
        //  2) There are no more bytes left to send and we've reached the end of the transmission. The transmission
        //     can be closed. This is the normal method used by the software to know when to end a transmission.

        // During Reception:
        //  When RxNE = 1. DR and the underlying shift register are both full.
        //  BTF indicates that the I2C peripheral has already received two bytes (one in DR and the other in the shift
        //  register) and is ready to receive a third byte, but there's no place to put the third byte, since both DR
        //  and the shift register are full. This situation occurs when the software has not read the data out of DR
        //  before the next byte has been received. If clock stetching is enabled (CR1_NOSTRETCH=0), the master will 
        //  stetch the clock until the software reads DR and BTF becomes 0 again. If clock stretching is disabled, 
        //  the third byte will be lost, and an overrun error will occur (see the SR1_OVR flag).

        if (stateInfo.State() == RxTxState::Transmitting && 
            device.get_SR1_TxE() == DataRegisterEmpty::Empty &&
            !stateInfo.HasMoreDataToWrite())
        {
            // During transmission: BTF = 1 and TxE = 1 and there's nothing left to send. Close the transmission.

            GenerateStopCondition();

            SetInterruptsEnabled(InterruptEnable::InterruptDisable);

            stateInfo.Done();

            if (txCompleteCallback)
            {
                txCompleteCallback();
            }
        }
    }

    inline void I2CPeripheral::HandleEventIrq_RxNE()
    {
        if (device.get_SR2_MSL() == MasterSlave::MasterMode)
        {
            HandleEventIrq_RxNE_MasterMode();
        }
        else if (device.get_SR2_MSL() == MasterSlave::SlaveMode)
        {
            HandleEventIrq_RxNE_SlaveMode();
        }
    }

    inline void I2CPeripheral::HandleEventIrq_RxNE_MasterMode()
    {
        if (stateInfo.State() == RxTxState::Receiving)
        {
            // Master receiver. IRQ EV7 or EV7_1a/b (RxNE=1)

            stateInfo.ReadDataByte(device.get_DR_DR()); // Read the Data.

            if (stateInfo.LengthToRead() > 1U && stateInfo.RemainingLengthToRead() == 1U)
            {
                // EV7_1a. During multi-byte reception, disable the ACK on the second last byte.
                // The master will send a NACK to the slave, indicating that no more data
                // should be sent.
                SetAcknowledgeEnable(AcknowledgeEnable::NoAcknowledgeReturned);
            }

            if (stateInfo.RemainingLengthToRead() == 0U)
            {
                // EV7_1b. All bytes have now been received.

                if (!stateInfo.UseRepeatedStart())
                {
                    GenerateStopCondition();
                }

                SetInterruptsEnabled(InterruptEnable::InterruptDisable);
                SetAcknowledgeEnable(AcknowledgeEnable::AcknowledgeReturned);

                stateInfo.Done();

                if (rxCompleteCallback)
                {
                    rxCompleteCallback(stateInfo.RxData());
                }
            }
        }
    }

    inline void I2CPeripheral::HandleEventIrq_RxNE_SlaveMode()
    {
        if (device.get_SR2_TRA() == TransmitterReceiver::DataBytesReceived)
        {
            // Slave receiver. IRQ EV2 (RxNE=1). Notify the application that
            // a byte has been received from the Master. The application can
            // call SlaveReadData to read the received byte.

            if (slaveDataReceivedCallback)
            {
                slaveDataReceivedCallback();
            }
        }
    }

    inline void I2CPeripheral::HandleEventIrq_STOPF()
    {
        // STOPF flag is set (Slave Mode only).

        if (device.get_SR2_MSL() == MasterSlave::SlaveMode)
        {
            ClearStopFlag();

            if (stopFlagCallback)
            {
                stopFlagCallback();
            }
        }
    }

    /// @brief This function is meant to be invoked from an interrupt service routine to handle I2C_ER interrupts.
    void I2CPeripheral::HandleErrorIrq()
    {
        if (device.get_CR2_ITERREN() == InterruptEnable::InterruptEnable)
        {
            HandleErrorIrq_BERR();
            HandleErrorIrq_ARLO();
            HandleErrorIrq_AF();
            HandleErrorIrq_OVR();
            HandleErrorIrq_TIMEOUT();

            stateInfo.Done();
        }
    }

    inline void I2CPeripheral::HandleErrorIrq_BERR()
    {
        if (device.get_SR1_BERR() == BusError::MisplacedStartOrStopCondition)
        {
            device.set_SR1_BERR(BusError::NoMisplacedStartOrStopCondition);

            if (busErrorCallback)
            {
                busErrorCallback();
            }
        }
    }

    inline void I2CPeripheral::HandleErrorIrq_ARLO()
    {
        if (device.get_SR1_ARLO() == ArbitrationLost::ArbitrationLostDetected)
        {
            device.set_SR1_ARLO(ArbitrationLost::NoArbitrationLostDetected);

            if (arbitrationLostCallback)
            {
                arbitrationLostCallback();
            }
        }
    }

    inline void I2CPeripheral::HandleErrorIrq_AF()
    {
        if (device.get_SR1_AF() == AcknowledgeFailure::AcknowledgeFailure)
        {
            device.set_SR1_AF(AcknowledgeFailure::NoAcknowledgeFailure);

            if (acknowledgeFailureCallback)
            {
                acknowledgeFailureCallback();
            }
        }
    }

    inline void I2CPeripheral::HandleErrorIrq_OVR()
    {
        if (device.get_SR1_OVR() == OverrunUnderrun::OverrunOrUnderrun)
        {
            device.set_SR1_OVR(OverrunUnderrun::NoOverrunUnderrun);

            if (overrunUnderrunCallback)
            {
                overrunUnderrunCallback();
            }
        }
    }

    inline void I2CPeripheral::HandleErrorIrq_TIMEOUT()
    {
        if (device.get_SR1_TIMEOUT() == TimeoutError::TimeoutError)
        {
            device.set_SR1_TIMEOUT(TimeoutError::NoTimeoutError);

            if (timeoutCallback)
            {
                timeoutCallback();
            }
        }
    }

    inline void I2CPeripheral::SetAcknowledgeEnable(AcknowledgeEnable enable)
    {
        device.set_CR1_ACK(enable);
    }

    inline void I2CPeripheral::SetInterruptsEnabled(InterruptEnable enable)
    {
        device.set_CR2_ITEVTEN(enable);
        device.set_CR2_ITERREN(enable);
        device.set_CR2_ITBUFEN(enable);
    }

    inline void I2CPeripheral::GenerateStartCondition()
    {
        device.set_CR1_START(StartGeneration::StartGeneration);
    }

    inline void I2CPeripheral::GenerateStopCondition()
    {
        device.set_CR1_STOP(StopGeneration::StopGeneration);
    }

    inline void I2CPeripheral::SendAddress(uint8_t slaveAddress, ReadWriteFlag readWriteFlag)
    {
        uint8_t readWriteBit = static_cast<uint8_t>(readWriteFlag) & 0x01U; 
        uint8_t addressByte = (slaveAddress << 1U) | readWriteBit;
        device.set_DR_DR(addressByte);
    }

    inline void I2CPeripheral::WaitForStartBit()
    {
        while (device.get_SR1_SB() != StartBit::StartConditionGenerated);
    }

    inline void I2CPeripheral::WaitForAddressFlag()
    {
        while (device.get_SR1_ADDR() != AddressSentMatched::AddressMatchedOrTransmitted);
    }

    inline void I2CPeripheral::WaitForRxData()
    {
        // Wait for the RxNE flag to indicate that the Rx data register is not empty.
        while (device.get_SR1_RxNE() != DataRegisterNotEmpty::NotEmpty);
    }

    inline void I2CPeripheral::ClearAddressFlag()
    {
        // Clear the ADDR flag.
        // According to the STM32 reference manual:
        // "This bit is cleared by software reading SR1 register followed reading SR2"
        // See the definition of the ADDR field in the I2C_SR1 register.
        (void)device.get_SR1_ADDR();    // Reading any field should work.
        (void)device.get_SR2_BUSY();    // Reading any field should work.
    }

    inline void I2CPeripheral::ClearStopFlag()
    {
        // According to the reference manual, STOPF can be cleared by the
        // software by first reading SR1, and then writing to CR1. 
        // It seems any value will do.
        (void)device.get_SR1_STOPF();
        device.set_CR1_STOP(device.get_CR1_STOP());
    }

    inline void I2CPeripheral::SendDataByte(uint8_t byte)
    {
        while (device.get_SR1_TxE() != DataRegisterEmpty::Empty);
        
        device.set_DR_DR(byte);
    }
} // namespace stm32::i2c
