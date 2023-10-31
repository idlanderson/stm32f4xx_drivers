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
    {
        testing::InSequence s;
        EXPECT_CALL(registerMap, set_IMR_MR0(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR1(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR2(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR3(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR4(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR5(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR6(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR7(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR8(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR9(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR10(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR11(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR12(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR13(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR14(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR15(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR16(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR17(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR18(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR19(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR20(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR21(InterruptMask::NotMasked));
        EXPECT_CALL(registerMap, set_IMR_MR22(InterruptMask::NotMasked));
    }

    for (uint8_t line = 0U; line <= 23U; line++)
    {
        exti.SetInterruptMask(line, InterruptMask::NotMasked);
    }
}

TEST_F(ExtiPeripheralTest, SetInterruptMask)
{
    exti.SetInterruptMask(0U, InterruptMask::NotMasked);

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