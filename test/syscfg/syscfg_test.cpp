#include "syscfg_register_map_mock.hpp"
#include "syscfg.hpp"
#include <cstring>
#include <iostream>

using namespace stm32::syscfg;
using namespace testing;
using ::testing::Return;

class SyscfgPeripheralTest : public ::testing::Test
{
public:
    SyscfgPeripheralTest() : registerMap(registers), syscfg(registerMap) { }
protected:

    void SetUp() override 
    {
        std::memset(&registers, 0, sizeof(registers));
    }

    void TearDown() override 
    {
        SetUp();
    }

    SyscfgRegisters registers = {};
    SyscfgRegisterMap registerMap;
    SyscfgPeripheral syscfg;
};

TEST_F(SyscfgPeripheralTest, ConfigureGpioIrq)
{
    uint32_t expected = 0x00000000U;

    for (uint8_t line = 0U; line <= 3U; line++)
    {
        expected |= (8U << (line * 4U));
        syscfg.ConfigureGpioIrq(line, ExtiConfiguration::PixPin);
        EXPECT_EQ(expected, registers.EXTICR1.Value);
    }

    expected = 0x00000000U;

    for (uint8_t line = 4U; line <= 7U; line++)
    {
        expected |= (8U << ((line - 4U) * 4U));
        syscfg.ConfigureGpioIrq(line, ExtiConfiguration::PixPin);
        EXPECT_EQ(expected, registers.EXTICR2.Value);
    }

    expected = 0x00000000U;

    for (uint8_t line = 8U; line <= 11U; line++)
    {
        expected |= (8U << ((line - 8U) * 4U));
        syscfg.ConfigureGpioIrq(line, ExtiConfiguration::PixPin);
        EXPECT_EQ(expected, registers.EXTICR3.Value);
    }

    expected = 0x00000000U;

    for (uint8_t line = 12U; line <= 15U; line++)
    {
        expected |= (8U << ((line - 12U) * 4U));
        syscfg.ConfigureGpioIrq(line, ExtiConfiguration::PixPin);
        EXPECT_EQ(expected, registers.EXTICR4.Value);
    }
}

TEST_F(SyscfgPeripheralTest, SetMemoryMapping)
{
    syscfg.SetMemoryMapping(MemoryMapping::MainFlashMemory);
    EXPECT_EQ(0x00000000U, registers.MEMRMP.Value);
    syscfg.SetMemoryMapping(MemoryMapping::SystemFlashMemory);
    EXPECT_EQ(0x00000001U, registers.MEMRMP.Value);
    syscfg.SetMemoryMapping(MemoryMapping::FsmcBank1);
    EXPECT_EQ(0x00000002U, registers.MEMRMP.Value);
    syscfg.SetMemoryMapping(MemoryMapping::EmbeddedSram);
    EXPECT_EQ(0x00000003U, registers.MEMRMP.Value);
}