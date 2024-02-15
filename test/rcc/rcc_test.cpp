#include "rcc_register_map_mock.hpp"
#include "rcc.hpp"
#include <cstring>

using namespace stm32::rcc;

class RccPeripheralTest : public ::testing::Test
{
public:
    RccPeripheralTest() : registerMap(registers), rcc(registerMap) { }
protected:

    void SetUp() override 
    {
        std::memset(&registers, 0, sizeof(registers));
    }

    void TearDown() override 
    {
        SetUp();
    }

    RccRegisters registers = {};
    RccRegisterMap registerMap;
    RccPeripheral rcc;
};

TEST_F(RccPeripheralTest, SetPeripheralClockEnabled)
{
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOA, true);
    EXPECT_EQ(0x00000001U, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOB, true);
    EXPECT_EQ(0x00000003U, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOC, true);
    EXPECT_EQ(0x00000007U, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOD, true);
    EXPECT_EQ(0x0000000FU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOE, true);
    EXPECT_EQ(0x0000001FU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOF, true);
    EXPECT_EQ(0x0000003FU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOG, true);
    EXPECT_EQ(0x0000007FU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOH, true);
    EXPECT_EQ(0x000000FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOI, true);
    EXPECT_EQ(0x000001FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::CRC, true);
    EXPECT_EQ(0x000011FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::BKPSRAM, true);
    EXPECT_EQ(0x000411FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::CCMDATARAM, true);
    EXPECT_EQ(0x001411FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::DMA1, true);
    EXPECT_EQ(0x003411FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::DMA2, true);
    EXPECT_EQ(0x007411FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::ETHMAC, true);
    EXPECT_EQ(0x027411FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::ETHMACTX, true);
    EXPECT_EQ(0x067411FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::ETHMACRX, true);
    EXPECT_EQ(0x0E7411FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::ETHMACPTP, true);
    EXPECT_EQ(0x1E7411FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::OTGHS, true);
    EXPECT_EQ(0x3E7411FFU, registers.AHB1ENR.Value);
    rcc.SetPeripheralClockEnabled(RccPeripheral::Peripheral::OTGHSULPI, true);
    EXPECT_EQ(0x7E7411FFU, registers.AHB1ENR.Value);
}

TEST_F(RccPeripheralTest, GetSystemClockFrequencyHsi)
{
    // SWS = HSI oscillator
    registers.CFGR.Value = 0x00000000U;

    uint32_t result = rcc.GetSystemClockFrequency();

    EXPECT_EQ(16000000U, result);
}

TEST_F(RccPeripheralTest, GetSystemClockFrequencyHse)
{
    // SWS = HSE oscillator
    registers.CFGR.Value = 0x00000004U;

    uint32_t result = rcc.GetSystemClockFrequency();

    EXPECT_EQ(8000000U, result);
}

TEST_F(RccPeripheralTest, GetSystemClockFrequencyPll)
{
    // SWS = PLL
    registers.CFGR.Value = 0x00000008U;

    uint32_t result = rcc.GetSystemClockFrequency();

    FAIL(); // TODO: Implement PLL.
}

TEST_F(RccPeripheralTest, GetSystemClockFrequencyInvalidSource)
{
    // SWS = Invalid Source
    registers.CFGR.Value = 0x0000000CU;

    uint32_t result = rcc.GetSystemClockFrequency();

    EXPECT_EQ(0U, result);
}

TEST_F(RccPeripheralTest, GetAhbClockFrequencyHsi)
{
    uint32_t result = 0;

    registers.CFGR.Value = 0x00000080U; // HSI. Div 2
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(8000000U, result);

    registers.CFGR.Value = 0x00000090U; // HSI. Div 4
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(4000000U, result);

    registers.CFGR.Value = 0x000000A0U; // HSI. Div 8
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(2000000U, result);

    registers.CFGR.Value = 0x000000B0U; // HSI. Div 16
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(1000000U, result);

    registers.CFGR.Value = 0x000000C0U; // HSI. Div 64
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(250000U, result);

    registers.CFGR.Value = 0x000000D0U; // HSI. Div 128
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(125000U, result);

    registers.CFGR.Value = 0x000000E0U; // HSI. Div 256
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(62500U, result);

    registers.CFGR.Value = 0x000000F0U; // HSI. Div 512
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(31250U, result);
}

TEST_F(RccPeripheralTest, GetAhbClockFrequencyHse)
{
    uint32_t result = 0;

    registers.CFGR.Value = 0x00000084U; // HSE. Div 2
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(4000000U, result);

    registers.CFGR.Value = 0x00000094U; // HSE. Div 4
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(2000000U, result);

    registers.CFGR.Value = 0x000000A4U; // HSE. Div 8
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(1000000U, result);

    registers.CFGR.Value = 0x000000B4U; // HSE. Div 16
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(500000U, result);

    registers.CFGR.Value = 0x000000C4U; // HSE. Div 64
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(125000U, result);

    registers.CFGR.Value = 0x000000D4U; // HSE. Div 128
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(62500U, result);

    registers.CFGR.Value = 0x000000E4U; // HSE. Div 256
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(31250U, result);

    registers.CFGR.Value = 0x000000F4U; // HSE. Div 512
    result = rcc.GetAhbClockFrequency();
    EXPECT_EQ(15625U, result);
}

TEST_F(RccPeripheralTest, GetApb1ClockFrequencyHsi)
{
    uint32_t result = 0;

    registers.CFGR.Value = 0x00001080U; // HSI. AHB Div 2, APB1 Div 2
    result = rcc.GetApb1ClockFrequency();
    EXPECT_EQ(4000000U, result);

    registers.CFGR.Value = 0x00001480U; // HSI. AHB Div 2, APB1 Div 4
    result = rcc.GetApb1ClockFrequency();
    EXPECT_EQ(2000000U, result);

    registers.CFGR.Value = 0x00001880U; // HSI. AHB Div 2, APB1 Div 8
    result = rcc.GetApb1ClockFrequency();
    EXPECT_EQ(1000000U, result);

    registers.CFGR.Value = 0x00001C80U; // HSI. AHB Div 2, APB1 Div 16
    result = rcc.GetApb1ClockFrequency();
    EXPECT_EQ(500000U, result);
}

TEST_F(RccPeripheralTest, GetApb2ClockFrequencyHsi)
{
    uint32_t result = 0;

    registers.CFGR.Value = 0x00008080U; // HSI. AHB Div 2, APB2 Div 2
    result = rcc.GetApb2ClockFrequency();
    EXPECT_EQ(4000000U, result);

    registers.CFGR.Value = 0x0000A080U; // HSI. AHB Div 2, APB2 Div 4
    result = rcc.GetApb2ClockFrequency();
    EXPECT_EQ(2000000U, result);

    registers.CFGR.Value = 0x0000C080U; // HSI. AHB Div 2, APB2 Div 8
    result = rcc.GetApb2ClockFrequency();
    EXPECT_EQ(1000000U, result);

    registers.CFGR.Value = 0x0000E080U; // HSI. AHB Div 2, APB2 Div 16
    result = rcc.GetApb2ClockFrequency();
    EXPECT_EQ(500000U, result);
}

TEST_F(RccPeripheralTest, SetSystemClockSource)
{
    rcc.SetSystemClockSource(SystemClock::HseOscillator);
    EXPECT_EQ(0x00000001U, registers.CFGR.Value);

    rcc.SetSystemClockSource(SystemClock::Pll);
    EXPECT_EQ(0x00000002U, registers.CFGR.Value);

    rcc.SetSystemClockSource(SystemClock::HsiOscillator);
    EXPECT_EQ(0x00000000U, registers.CFGR.Value);
}