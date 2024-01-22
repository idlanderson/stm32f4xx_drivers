#include "i2c.hpp"
#include "i2c_register_map_mock.hpp"

TEST_F(I2CPeripheralTest, SetAcknowledgeEnable)
{
    i2c.SetAcknowledgeEnable(AcknowledgeEnable::NoAcknowledgeReturned);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    i2c.SetAcknowledgeEnable(AcknowledgeEnable::AcknowledgeReturned);
    EXPECT_EQ(0x00000400U, registers.CR1.Value);
}

TEST_F(I2CPeripheralTest, SetDeviceAddress7Bit)
{
    i2c.SetDeviceAddress(0x01U);
    EXPECT_EQ(0x00000002U, registers.OAR1.Value);
    i2c.SetDeviceAddress(0x7FU);
    EXPECT_EQ(0x000000FEU, registers.OAR1.Value);
    i2c.SetDeviceAddress(0x80U);
    EXPECT_EQ(0x00000000U, registers.OAR1.Value);
}

TEST_F(I2CPeripheralTest, SetDeviceAddress10Bit)
{
    i2c.SetDeviceAddress(AddressingMode::_10BitSlaveAddress, 0x001U);
    EXPECT_EQ(0x00008001U, registers.OAR1.Value);
    i2c.SetDeviceAddress(AddressingMode::_10BitSlaveAddress, 0x3FFU);
    EXPECT_EQ(0x000083FFU, registers.OAR1.Value);
    i2c.SetDeviceAddress(AddressingMode::_10BitSlaveAddress, 0x400U);
    EXPECT_EQ(0x00008000U, registers.OAR1.Value);
}

TEST_F(I2CPeripheralTest, SetSerialClockStandardMode)
{
    i2c.SetSerialClock(16U, 100U);
    EXPECT_EQ(0x00000010U, registers.CR2.Value);
    EXPECT_EQ(0x00000050U, registers.CCR.Value);
    EXPECT_EQ(0x00000011U, registers.TRISE.Value);

    // Duty Cycle parameter should be ignored.
    i2c.SetSerialClock(50U, 100U, FmModeDutyCycle::Ratio16Over9);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x000000FAU, registers.CCR.Value);
    EXPECT_EQ(0x00000033U, registers.TRISE.Value);

    i2c.SetSerialClock(50U, 1U);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x000001A8U, registers.CCR.Value);
    EXPECT_EQ(0x00000033U, registers.TRISE.Value);

    registers.CR2.Value = 0x00000000U;
    registers.CCR.Value = 0x00000000U;
    registers.TRISE.Value = 0x00000000U;
    i2c.SetSerialClock(50U, 0U);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
    EXPECT_EQ(0x00000000U, registers.CCR.Value);
    EXPECT_EQ(0x00000000U, registers.TRISE.Value);

    registers.CR2.Value = 0x00000000U;
    registers.CCR.Value = 0x00000000U;
    registers.TRISE.Value = 0x00000000U;
    i2c.SetSerialClock(51U, 100U);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
    EXPECT_EQ(0x00000000U, registers.CCR.Value);
    EXPECT_EQ(0x00000000U, registers.TRISE.Value);

    registers.CR2.Value = 0x00000000U;
    registers.CCR.Value = 0x00000000U;
    registers.TRISE.Value = 0x00000000U;
    i2c.SetSerialClock(1U, 100U);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
    EXPECT_EQ(0x00000000U, registers.CCR.Value);
    EXPECT_EQ(0x00000000U, registers.TRISE.Value);

    i2c.SetSerialClock(2U, 100U);
    EXPECT_EQ(0x00000003U, registers.TRISE.Value);
}

TEST_F(I2CPeripheralTest, SetSerialClockFastMode)
{
    i2c.SetSerialClock(50U, 400U, FmModeDutyCycle::Ratio2);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x00008029U, registers.CCR.Value);
    EXPECT_EQ(0x00000010U, registers.TRISE.Value);

    i2c.SetSerialClock(50U, 400U, FmModeDutyCycle::Ratio16Over9);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x0000C005U, registers.CCR.Value);
    EXPECT_EQ(0x00000010U, registers.TRISE.Value);

    i2c.SetSerialClock(50U, 400U);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x00008029U, registers.CCR.Value);
    EXPECT_EQ(0x00000010U, registers.TRISE.Value);

    registers.CR2.Value = 0x00000000U;
    registers.CCR.Value = 0x00000000U;
    registers.TRISE.Value = 0x00000000U;
    i2c.SetSerialClock(50U, 401U, FmModeDutyCycle::Ratio2);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
    EXPECT_EQ(0x00000000U, registers.CCR.Value);
    EXPECT_EQ(0x00000000U, registers.TRISE.Value);

    i2c.SetSerialClock(2U, 400U, FmModeDutyCycle::Ratio2);
    EXPECT_EQ(0x00000001U, registers.TRISE.Value);
}

TEST_F(I2CPeripheralTestWithMock, MasterWriteData)
{
    // Start condition
    EXPECT_CALL(registerMap, set_CR1_START(StartGeneration::StartGeneration)).Times(1);
    EXPECT_CALL(registerMap, get_SR1_SB())
        .Times(1)
        .WillOnce(Return(StartBit::StartConditionGenerated));

    // Address phase
    EXPECT_CALL(registerMap, set_DR_DR(0x02U)).Times(1);
    EXPECT_CALL(registerMap, get_SR1_ADDR())
        .Times(2)
        .WillRepeatedly(Return(AddressSentMatched::AddressMatchedOrTransmitted));
    EXPECT_CALL(registerMap, get_SR2_BUSY()).Times(1);

    // Data transmission
    EXPECT_CALL(registerMap, get_SR1_TxE())
        .Times(3)
        .WillRepeatedly(Return(DataRegisterEmpty::Empty));
    EXPECT_CALL(registerMap, set_DR_DR(0xABU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0xCDU)).Times(1);

    // Waiting for byte transfer completion
    EXPECT_CALL(registerMap, get_SR1_BTF())
        .Times(1)
        .WillRepeatedly(Return(ByteTransferFinished::Succeeded));

    // Stop condition
    EXPECT_CALL(registerMap, set_CR1_STOP(StopGeneration::StopGeneration)).Times(1);

    vector<uint8_t> data = { 0xABU, 0xCDU };
    i2c.MasterWriteData(data, 0x01U);
}