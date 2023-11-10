#include "exti_register_map_mock.hpp"
#include "exti.hpp"
#include <cstring>

// This test fixture uses a "real" copy of ExtiRegisterMap and ExtiRegisters.
// ExtiRegisters registers:
//      The structure which, on the microcontroller, points to the actual addresses of the memory-mapped registers of the EXTI peripheral.
//      For the unit tests, this struct will just be a RAM-copy, but it will allow the unit tests to validate that the registers have been
//      written to the correct values. This will not completely confirm that it will work correctly on the actual hardware, but at least
//      it is possible to confirm that the correct bits are written for particular fields.
// ExtiRegisterMap registerMap:
//      This is a "wrapper" around ExtiRegisters and provides accessors to read and write the register fields. This can be mocked if needed.
//      In this text fixture, this class is not mocked.
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

// This test fixture uses a "mock" version of ExtiRegisterMap which GMock can use to validate that the 
// correct get and set accessors were called at the appropriate times.
class ExtiPeripheralTestWithMock : public ::testing::Test
{
public:
    ExtiPeripheralTestWithMock() : exti(registerMap) { }
protected:
    MockExtiRegisterMap registerMap;
    ExtiPeripheral exti;
};

TEST_F(ExtiPeripheralTestWithMock, SetIrqMask)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 23U; line++)
    {
        expected = (1U << line);
        EXPECT_CALL(registerMap, get_IMR_MR).Times(1);
        EXPECT_CALL(registerMap, set_IMR_MR(expected)).Times(1);
        exti.SetIrqMask(line, InterruptMask::NotMasked);
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

TEST_F(ExtiPeripheralTest, SetIrqMask)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 22U; line++)
    {
        registers.IMR.Value = 0x00000000U;
        expected = (1U << line);

        exti.SetIrqMask(line, InterruptMask::NotMasked);

        EXPECT_EQ(expected, registers.IMR.Value);
    }

    registers.IMR.Value = 0x00000000U;

    exti.SetIrqMask(23U, InterruptMask::NotMasked);
    
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

TEST_F(ExtiPeripheralTest, GenerateIrq)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 22U; line++)
    {
        registers.SWIER.Value = 0x00000000U;
        expected = (1U << line);

        exti.GenerateIrq(line);

        EXPECT_EQ(expected, registers.SWIER.Value);
    }

    registers.SWIER.Value = 0x00000000U;

    exti.GenerateIrq(23U);
    
    EXPECT_EQ(0x00000000U, registers.SWIER.Value);
}

TEST_F(ExtiPeripheralTest, ClearPendingBit)
{
    uint32_t expected = 0U;

    for (uint8_t line = 0U; line <= 22U; line++)
    {
        registers.PR.Value = 0x00000000U;
        expected = (1U << line);

        exti.ClearPendingBit(line);

        EXPECT_EQ(expected, registers.PR.Value);
    }

    registers.PR.Value = 0x00000000U;

    exti.ClearPendingBit(23U);
    
    EXPECT_EQ(0x00000000U, registers.PR.Value);
}