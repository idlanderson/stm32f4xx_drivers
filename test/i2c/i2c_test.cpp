#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "i2c.hpp"

using namespace stm32::i2c;
using namespace testing;

class I2CPeripheralTest : public ::testing::Test
{
public:
    I2CPeripheralTest() : registerMap(registers), i2c(registerMap) { }
protected:
    void SetUp() override { }
    void TearDown() override { }

    I2CRegisters registers = { };
    I2CRegisterMap registerMap;
    I2CPeripheral i2c;
};

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
    EXPECT_EQ(0x00004002U, registers.OAR1.Value);
    i2c.SetDeviceAddress(0x7FU);
    EXPECT_EQ(0x000040FEU, registers.OAR1.Value);
    i2c.SetDeviceAddress(0x80U);
    EXPECT_EQ(0x00004000U, registers.OAR1.Value);
}

TEST_F(I2CPeripheralTest, SetDeviceAddress10Bit)
{
    i2c.SetDeviceAddress(AddressingMode::_10BitSlaveAddress, 0x001U);
    EXPECT_EQ(0x0000C001U, registers.OAR1.Value);
    i2c.SetDeviceAddress(AddressingMode::_10BitSlaveAddress, 0x3FFU);
    EXPECT_EQ(0x0000C3FFU, registers.OAR1.Value);
    i2c.SetDeviceAddress(AddressingMode::_10BitSlaveAddress, 0x400U);
    EXPECT_EQ(0x0000C000U, registers.OAR1.Value);
}

TEST_F(I2CPeripheralTest, SetSerialClockStandardMode)
{
    i2c.SetSerialClock(16U, 100U);
    EXPECT_EQ(0x00000010U, registers.CR2.Value);
    EXPECT_EQ(0x00000050U, registers.CCR.Value);

    // Duty Cycle parameter should be ignored.
    i2c.SetSerialClock(50U, 100U, FmModeDutyCycle::LowHighRadio16Over9);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x000000FAU, registers.CCR.Value);

    i2c.SetSerialClock(50U, 1U);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x000001A8U, registers.CCR.Value);

    registers.CR2.Value = 0x00000000U;
    registers.CCR.Value = 0x00000000U;
    i2c.SetSerialClock(50U, 0U);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
    EXPECT_EQ(0x00000000U, registers.CCR.Value);

    registers.CR2.Value = 0x00000000U;
    registers.CCR.Value = 0x00000000U;
    i2c.SetSerialClock(51U, 100U);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
    EXPECT_EQ(0x00000000U, registers.CCR.Value);

    registers.CR2.Value = 0x00000000U;
    registers.CCR.Value = 0x00000000U;
    i2c.SetSerialClock(1U, 100U);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
    EXPECT_EQ(0x00000000U, registers.CCR.Value);
}

TEST_F(I2CPeripheralTest, SetSerialClockFastMode)
{
    i2c.SetSerialClock(50U, 400U, FmModeDutyCycle::LowHighRatio2);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x00008029U, registers.CCR.Value);

    i2c.SetSerialClock(50U, 400U, FmModeDutyCycle::LowHighRadio16Over9);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x0000C005U, registers.CCR.Value);

    i2c.SetSerialClock(50U, 400U);
    EXPECT_EQ(0x00000032U, registers.CR2.Value);
    EXPECT_EQ(0x00008029U, registers.CCR.Value);

    registers.CR2.Value = 0x00000000U;
    registers.CCR.Value = 0x00000000U;
    i2c.SetSerialClock(50U, 401U, FmModeDutyCycle::LowHighRatio2);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
    EXPECT_EQ(0x00000000U, registers.CCR.Value);
}