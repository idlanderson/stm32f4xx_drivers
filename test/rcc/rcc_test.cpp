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