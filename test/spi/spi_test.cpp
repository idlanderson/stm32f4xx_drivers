#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "spi.hpp"

using namespace stm32::spi;

class MockSpiRegisterMap : public ISpiRegisterMap
{
public:
    // CR1 Fields.
    MOCK_METHOD(uint8_t, getBIDIMODE, (), (const, override));
    MOCK_METHOD(uint8_t, getBIDIOE, (), (const, override));
    MOCK_METHOD(uint8_t, getCRCEN, (), (const, override));
    MOCK_METHOD(uint8_t, getCRCNEXT, (), (const, override));
    MOCK_METHOD(uint8_t, getDFF, (), (const, override));
    MOCK_METHOD(uint8_t, getRXONLY, (), (const, override));
    MOCK_METHOD(uint8_t, getSSM, (), (const, override));
    MOCK_METHOD(uint8_t, getSSI, (), (const, override));
    MOCK_METHOD(uint8_t, getLSBFIRST, (), (const, override));
    MOCK_METHOD(uint8_t, getSPE, (), (const, override));
    MOCK_METHOD(uint8_t, getBR, (), (const, override));
    MOCK_METHOD(uint8_t, getMSTR, (), (const, override));
    MOCK_METHOD(uint8_t, getCPOL, (), (const, override));
    MOCK_METHOD(uint8_t, getCPHA, (), (const, override));

    MOCK_METHOD(void, setBIDIMODE, (uint8_t value), (override));
    MOCK_METHOD(void, setBIDIOE, (uint8_t value), (override));
    MOCK_METHOD(void, setCRCEN, (uint8_t value), (override));
    MOCK_METHOD(void, setCRCNEXT, (uint8_t value), (override));
    MOCK_METHOD(void, setDFF, (uint8_t value), (override));
    MOCK_METHOD(void, setRXONLY, (uint8_t value), (override));
    MOCK_METHOD(void, setSSM, (uint8_t value), (override));
    MOCK_METHOD(void, setSSI, (uint8_t value), (override));
    MOCK_METHOD(void, setLSBFIRST, (uint8_t value), (override));
    MOCK_METHOD(void, setSPE, (uint8_t value), (override));
    MOCK_METHOD(void, setBR, (uint8_t value), (override));
    MOCK_METHOD(void, setMSTR, (uint8_t value), (override));
    MOCK_METHOD(void, setCPOL, (uint8_t value), (override));
    MOCK_METHOD(void, setCPHA, (uint8_t value), (override));

    // CR2 Fields.
    MOCK_METHOD(uint8_t, getRXNEIE, (), (const, override));
    MOCK_METHOD(uint8_t, getERRIE, (), (const, override));
    MOCK_METHOD(uint8_t, getFRF, (), (const, override));
    MOCK_METHOD(uint8_t, getSSOE, (), (const, override));
    MOCK_METHOD(uint8_t, getTXDMAEN, (), (const, override));
    MOCK_METHOD(uint8_t, getRXDMAEN, (), (const, override));
    MOCK_METHOD(void, setRXNEIE, (uint8_t value), (override));
    MOCK_METHOD(void, setERRIE, (uint8_t value), (override));
    MOCK_METHOD(void, setFRF, (uint8_t value), (override));
    MOCK_METHOD(void, setSSOE, (uint8_t value), (override));
    MOCK_METHOD(void, setTXDMAEN, (uint8_t value), (override));
    MOCK_METHOD(void, setRXDMAEN, (uint8_t value), (override));

    // SR Fields.
    MOCK_METHOD(uint8_t, getFRE, (), (const, override));
    MOCK_METHOD(uint8_t, getBSY, (), (const, override));
    MOCK_METHOD(uint8_t, getOVR, (), (const, override));
    MOCK_METHOD(uint8_t, getMODF, (), (const, override));
    MOCK_METHOD(uint8_t, getCRCERR, (), (const, override));
    MOCK_METHOD(uint8_t, getUDR, (), (const, override));
    MOCK_METHOD(uint8_t, getCHSIDE, (), (const, override));
    MOCK_METHOD(uint8_t, getTXE, (), (const, override));
    MOCK_METHOD(uint8_t, getRXNE, (), (const, override));
    MOCK_METHOD(void, setCRCERR, (uint8_t value), (override));

    // DR.
    MOCK_METHOD(uint16_t, getDR, (), (const, override));
    MOCK_METHOD(void,     setDR, (uint16_t value), (override));

    // CRCPR.
    MOCK_METHOD(uint16_t, getCRCPR, (), (const, override));
    MOCK_METHOD(void,     setCRCPR, (uint16_t value), (override));

    // RXCRCR and TXCRCR.
    MOCK_METHOD(uint16_t, getRXCRCR, (), (const, override));
    MOCK_METHOD(uint16_t, getTXCRCR, (), (const, override));

    // I2SCFGR.
    MOCK_METHOD(uint8_t, getI2SMOD, (), (const, override));
    MOCK_METHOD(uint8_t, getI2SE, (), (const, override));
    MOCK_METHOD(uint8_t, getI2SCFG, (), (const, override));
    MOCK_METHOD(uint8_t, getPCMSYNC, (), (const, override));
    MOCK_METHOD(uint8_t, getI2SSTD, (), (const, override));
    MOCK_METHOD(uint8_t, getCKPOL, (), (const, override));
    MOCK_METHOD(uint8_t, getDATLEN, (), (const, override));
    MOCK_METHOD(uint8_t, getCHLEN, (), (const, override));
    MOCK_METHOD(void, setI2SMOD, (uint8_t value), (override));
    MOCK_METHOD(void, setI2SE, (uint8_t value), (override));
    MOCK_METHOD(void, setI2SCFG, (uint8_t value), (override));
    MOCK_METHOD(void, setPCMSYNC, (uint8_t value), (override));
    MOCK_METHOD(void, setI2SSTD, (uint8_t value), (override));
    MOCK_METHOD(void, setCKPOL, (uint8_t value), (override));
    MOCK_METHOD(void, setDATLEN, (uint8_t value), (override));
    MOCK_METHOD(void, setCHLEN, (uint8_t value), (override));

    // I2SPR
    MOCK_METHOD(uint8_t, getMCKOE, (), (const, override));
    MOCK_METHOD(uint8_t, getODD, (), (const, override));
    MOCK_METHOD(uint8_t, getI2SDIV, (), (const, override));
    MOCK_METHOD(void, setMCKOE, (uint8_t value), (override));
    MOCK_METHOD(void, setODD, (uint8_t value), (override));
    MOCK_METHOD(void, setI2SDIV, (uint8_t value), (override));
};

class SpiPeripheralTest : public ::testing::Test
{
public:
    SpiPeripheralTest() : spi(spiRegisters) {}
protected:
    MockSpiRegisterMap spiRegisters;
    SpiPeripheral spi;
};

TEST_F(SpiPeripheralTest, SetDeviceModeMaster)
{
    EXPECT_CALL(spiRegisters, setMSTR(1U)).Times(1);

    spi.SetDeviceMode(DeviceMode::Master);
}

TEST_F(SpiPeripheralTest, SetDeviceModeSlave)
{
    EXPECT_CALL(spiRegisters, setMSTR(0U)).Times(1);

    spi.SetDeviceMode(DeviceMode::Slave);
}