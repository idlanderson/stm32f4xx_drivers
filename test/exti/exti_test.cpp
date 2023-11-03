#include "exti_register_map_mock.hpp"
#include "exti.hpp"
#include <cstring>

class ExtiPeripheralTestWithMock : public ::testing::Test
{
public:
    ExtiPeripheralTestWithMock() : exti(registerMap) { }
protected:
    MockExtiRegisterMap registerMap;
    ExtiPeripheral exti;
};

class ExtiPeripheralTest : public ::testing::Test
{
public:
    ExtiPeripheralTest() : registerMap(registers), exti(registerMap) { }
protected:

    void SetUp() override 
    {
        std::memset(&registers, 0, sizeof(registers));
    }

    void TearDown() override 
    {
        SetUp();
    }

    ExtiRegisters registers = {};
    ExtiRegisterMap registerMap;
    ExtiPeripheral exti;
};

TEST_F(ExtiPeripheralTestWithMock, SetInterruptMask)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 23U; line++)
    {
        expected = (1U << line);
        EXPECT_CALL(registerMap, get_IMR_MR).Times(1);
        EXPECT_CALL(registerMap, set_IMR_MR(expected)).Times(1);
        exti.SetInterruptMask(line, InterruptMask::NotMasked);
    }
}

TEST_F(ExtiPeripheralTestWithMock, SetEventMask)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 23U; line++)
    {
        expected = (1U << line);
        EXPECT_CALL(registerMap, get_EMR_MR).Times(1);
        EXPECT_CALL(registerMap, set_EMR_MR(expected)).Times(1);
        exti.SetEventMask(line, InterruptMask::NotMasked);
    }
}

TEST_F(ExtiPeripheralTest, SetInterruptMask)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 22U; line++)
    {
        registers.IMR.Value = 0x00000000U;
        expected = (1U << line);

        exti.SetInterruptMask(line, InterruptMask::NotMasked);

        EXPECT_EQ(expected, registers.IMR.Value);
    }

    registers.IMR.Value = 0x00000000U;

    exti.SetInterruptMask(23U, InterruptMask::NotMasked);
    
    EXPECT_EQ(0x00000000U, registers.IMR.Value);
}

TEST_F(ExtiPeripheralTest, SetEventMask)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 22U; line++)
    {
        registers.EMR.Value = 0x00000000U;
        expected = (1U << line);

        exti.SetEventMask(line, InterruptMask::NotMasked);

        EXPECT_EQ(expected, registers.EMR.Value);
    }

    registers.EMR.Value = 0x00000000U;

    exti.SetEventMask(23U, InterruptMask::NotMasked);
    
    EXPECT_EQ(0x00000000U, registers.EMR.Value);
}

TEST_F(ExtiPeripheralTest, SetRisingTriggerEnabled)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 22U; line++)
    {
        registers.RTSR.Value = 0x00000000U;
        expected = (1U << line);

        exti.SetRisingTriggerEnabled(line, true);

        EXPECT_EQ(expected, registers.RTSR.Value);
    }

    registers.RTSR.Value = 0x00000000U;

    exti.SetRisingTriggerEnabled(23U, true);
    
    EXPECT_EQ(0x00000000U, registers.RTSR.Value);
}

TEST_F(ExtiPeripheralTest, SetFallingTriggerEnabled)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 22U; line++)
    {
        registers.FTSR.Value = 0x00000000U;
        expected = (1U << line);

        exti.SetFallingTriggerEnabled(line, true);

        EXPECT_EQ(expected, registers.FTSR.Value);
    }

    registers.FTSR.Value = 0x00000000U;

    exti.SetFallingTriggerEnabled(23U, true);
    
    EXPECT_EQ(0x00000000U, registers.FTSR.Value);
}