#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "i2c_register_map.hpp"
#include <cstring>

using namespace stm32::i2c;
using namespace testing;

class MockI2CRegisterMap : public II2CRegisterMap
{
public:

	// CR1 Fields
	MOCK_METHOD(PeripheralEnable, get_CR1_PE, (), (const, override));
	MOCK_METHOD(AcknowledgeEnable, get_CR1_ACK, (), (const, override));
	MOCK_METHOD(void, set_CR1_PE, (PeripheralEnable), (override));
	MOCK_METHOD(void, set_CR1_ACK, (AcknowledgeEnable), (override));

	// CR2 Fields
	MOCK_METHOD(uint32_t, get_CR2_FREQ, (), (const, override));
	MOCK_METHOD(void, set_CR2_FREQ, (uint32_t), (override));

	// OAR1 Fields
	MOCK_METHOD(uint32_t, get_OAR1_ADD, (), (const, override));
	MOCK_METHOD(AddressingMode, get_OAR1_ADDMODE, (), (const, override));
	MOCK_METHOD(void, set_OAR1_ADD, (uint32_t), (override));
	MOCK_METHOD(void, set_OAR1_ADDMODE, (AddressingMode), (override));

	// OAR2 Fields
	MOCK_METHOD(DualAddressingModeEnable, get_OAR2_ENDUAL, (), (const, override));
	MOCK_METHOD(uint32_t, get_OAR2_ADD2, (), (const, override));
	MOCK_METHOD(void, set_OAR2_ENDUAL, (DualAddressingModeEnable), (override));
	MOCK_METHOD(void, set_OAR2_ADD2, (uint32_t), (override));

	// DR Fields
	MOCK_METHOD(uint32_t, get_DR_DR, (), (const, override));
	MOCK_METHOD(void, set_DR_DR, (uint32_t), (override));

	// SR1 Fields
	MOCK_METHOD(StartBit, get_SR1_SB, (), (const, override));
	MOCK_METHOD(AddressSentMatched, get_SR1_ADDR, (), (const, override));

	// SR2 Fields
	MOCK_METHOD(MasterSlave, get_SR2_MSL, (), (const, override));
	MOCK_METHOD(BusBusy, get_SR2_BUSY, (), (const, override));
	MOCK_METHOD(TransmitterReceiver, get_SR2_TRA, (), (const, override));

	// CCR Fields
	MOCK_METHOD(uint32_t, get_CCR_CCR, (), (const, override));
	MOCK_METHOD(FmModeDutyCycle, get_CCR_DUTY, (), (const, override));
	MOCK_METHOD(MasterModeSelection, get_CCR_FS, (), (const, override));
	MOCK_METHOD(void, set_CCR_CCR, (uint32_t), (override));
	MOCK_METHOD(void, set_CCR_DUTY, (FmModeDutyCycle), (override));
	MOCK_METHOD(void, set_CCR_FS, (MasterModeSelection), (override));
};

class I2CPeripheralTest : public ::testing::Test
{
public:
	I2CPeripheralTest() : registerMap(registers), i2c(registerMap) { }
protected:
	void SetUp() override { std::memset(&registers, 0, sizeof(registers)); } 
	void TearDown() override { SetUp(); }
	I2CRegisters registers = { };
	I2CRegisterMap registerMap;
	I2CPeripheral i2c;
};

class I2CPeripheralTestWithMock : public ::testing::Test
{
public:
	I2CPeripheralTestWithMock() : i2c(registerMap) { }
protected:
	MockI2CRegisterMap registerMap;
	I2CPeripheral i2c;
};