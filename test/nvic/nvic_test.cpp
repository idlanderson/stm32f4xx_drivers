#include "nvic.hpp"
#include "nvic_register_map_mock.hpp"
#include <iostream>
#include <vector>

using namespace testing;

static void EnableIrqTest(
    NvicPeripheral & nvic, 
    NvicRegisters & registers,
    uint8_t min, 
    uint8_t max, 
    uint8_t index)
{
    uint32_t expected = 0x00000000U;

    for (uint16_t irqNumber = (uint16_t)min; irqNumber <= (uint16_t)max; irqNumber++)
    {
        expected |= (1U << ((uint32_t)irqNumber - 32 * index));

        nvic.EnableIrq((IrqNumber)irqNumber);
        
        EXPECT_EQ(index == 0U ? expected : 0x00000000U, registers.ISER[0].Value);
        EXPECT_EQ(index == 1U ? expected : 0x00000000U, registers.ISER[1].Value);
        EXPECT_EQ(index == 2U ? expected : 0x00000000U, registers.ISER[2].Value);
        EXPECT_EQ(index == 3U ? expected : 0x00000000U, registers.ISER[3].Value);
        EXPECT_EQ(index == 4U ? expected : 0x00000000U, registers.ISER[4].Value);
        EXPECT_EQ(index == 5U ? expected : 0x00000000U, registers.ISER[5].Value);
        EXPECT_EQ(index == 6U ? expected : 0x00000000U, registers.ISER[6].Value);
        EXPECT_EQ(index == 7U ? expected : 0x00000000U, registers.ISER[7].Value);
    }
}

static void DisableIrqTest(
    NvicPeripheral & nvic, 
    NvicRegisters & registers,
    uint8_t min, 
    uint8_t max, 
    uint8_t index)
{
    uint32_t expected = 0x00000000U;

    for (uint16_t irqNumber = (uint16_t)min; irqNumber <= (uint16_t)max; irqNumber++)
    {
        expected |= (1U << ((uint32_t)irqNumber - 32 * index));

        nvic.DisableIrq((IrqNumber)irqNumber);
        
        EXPECT_EQ(index == 0U ? expected : 0x00000000U, registers.ICER[0].Value);
        EXPECT_EQ(index == 1U ? expected : 0x00000000U, registers.ICER[1].Value);
        EXPECT_EQ(index == 2U ? expected : 0x00000000U, registers.ICER[2].Value);
        EXPECT_EQ(index == 3U ? expected : 0x00000000U, registers.ICER[3].Value);
        EXPECT_EQ(index == 4U ? expected : 0x00000000U, registers.ICER[4].Value);
        EXPECT_EQ(index == 5U ? expected : 0x00000000U, registers.ICER[5].Value);
        EXPECT_EQ(index == 6U ? expected : 0x00000000U, registers.ICER[6].Value);
        EXPECT_EQ(index == 7U ? expected : 0x00000000U, registers.ICER[7].Value);
    }
}

static void SetPendingIrqTest(
    NvicPeripheral & nvic, 
    NvicRegisters & registers,
    uint8_t min, 
    uint8_t max, 
    uint8_t index)
{
    uint32_t expected = 0x00000000U;

    for (uint16_t irqNumber = (uint16_t)min; irqNumber <= (uint16_t)max; irqNumber++)
    {
        expected |= (1U << ((uint32_t)irqNumber - 32 * index));

        nvic.SetPendingIrq((IrqNumber)irqNumber);
        
        EXPECT_EQ(index == 0U ? expected : 0x00000000U, registers.ISPR[0].Value);
        EXPECT_EQ(index == 1U ? expected : 0x00000000U, registers.ISPR[1].Value);
        EXPECT_EQ(index == 2U ? expected : 0x00000000U, registers.ISPR[2].Value);
        EXPECT_EQ(index == 3U ? expected : 0x00000000U, registers.ISPR[3].Value);
        EXPECT_EQ(index == 4U ? expected : 0x00000000U, registers.ISPR[4].Value);
        EXPECT_EQ(index == 5U ? expected : 0x00000000U, registers.ISPR[5].Value);
        EXPECT_EQ(index == 6U ? expected : 0x00000000U, registers.ISPR[6].Value);
        EXPECT_EQ(index == 7U ? expected : 0x00000000U, registers.ISPR[7].Value);
    }
}

static void ClearPendingIrqTest(
    NvicPeripheral & nvic, 
    NvicRegisters & registers,
    uint8_t min, 
    uint8_t max, 
    uint8_t index)
{
    uint32_t expected = 0x00000000U;

    for (uint16_t irqNumber = (uint16_t)min; irqNumber <= (uint16_t)max; irqNumber++)
    {
        expected |= (1U << ((uint32_t)irqNumber - 32 * index));

        nvic.ClearPendingIrq((IrqNumber)irqNumber);
        
        EXPECT_EQ(index == 0U ? expected : 0x00000000U, registers.ICPR[0].Value);
        EXPECT_EQ(index == 1U ? expected : 0x00000000U, registers.ICPR[1].Value);
        EXPECT_EQ(index == 2U ? expected : 0x00000000U, registers.ICPR[2].Value);
        EXPECT_EQ(index == 3U ? expected : 0x00000000U, registers.ICPR[3].Value);
        EXPECT_EQ(index == 4U ? expected : 0x00000000U, registers.ICPR[4].Value);
        EXPECT_EQ(index == 5U ? expected : 0x00000000U, registers.ICPR[5].Value);
        EXPECT_EQ(index == 6U ? expected : 0x00000000U, registers.ICPR[6].Value);
        EXPECT_EQ(index == 7U ? expected : 0x00000000U, registers.ICPR[7].Value);
    }
}

static void IsIrqActiveTest(
    NvicPeripheral & nvic, 
    NvicRegisters & registers,
    uint8_t min, 
    uint8_t max, 
    uint8_t index)
{
    for (uint16_t irqNumber = (uint16_t)min; irqNumber <= (uint16_t)max; irqNumber++)
    {
        registers.IABR[index].Value = (1U << ((uint32_t)irqNumber - 32 * index));

        bool isActive = nvic.IsIrqActive((IrqNumber)irqNumber);
        
        EXPECT_TRUE(isActive);
    }
}

TEST_F(NvicPeripheralTest, EnableIrq0to31)
{
    EnableIrqTest(nvic, registers, 0U,   31U, 0U);
}

TEST_F(NvicPeripheralTest, EnableIrq32to63)
{
    EnableIrqTest(nvic, registers, 32U,  63U, 1U);
}

TEST_F(NvicPeripheralTest, EnableIrq64to95)
{
    EnableIrqTest(nvic, registers, 64U,  95U, 2U);
}

TEST_F(NvicPeripheralTest, EnableIrq96to127)
{
    EnableIrqTest(nvic, registers, 96U,  127U, 3U);
}

TEST_F(NvicPeripheralTest, EnableIrq128to159)
{
    EnableIrqTest(nvic, registers, 128U, 159U, 4U);
}

TEST_F(NvicPeripheralTest, EnableIrq160to191)
{
    EnableIrqTest(nvic, registers, 160U, 191U, 5U);
}

TEST_F(NvicPeripheralTest, EnableIrq192to223)
{
    EnableIrqTest(nvic, registers, 192U, 223U, 6U);
}

TEST_F(NvicPeripheralTest, EnableIrq224to255)
{
    EnableIrqTest(nvic, registers, 224U, 255U, 7U);
}

TEST_F(NvicPeripheralTest, DisableIrq0to31)
{
    DisableIrqTest(nvic, registers, 0U,   31U, 0U);
}

TEST_F(NvicPeripheralTest, DisableIrq32to63)
{
    DisableIrqTest(nvic, registers, 32U,  63U, 1U);
}

TEST_F(NvicPeripheralTest, DisableIrq64to95)
{
    DisableIrqTest(nvic, registers, 64U,  95U, 2U);
}

TEST_F(NvicPeripheralTest, DisableIrq96to127)
{
    DisableIrqTest(nvic, registers, 96U,  127U, 3U);
}

TEST_F(NvicPeripheralTest, DisableIrq128to159)
{
    DisableIrqTest(nvic, registers, 128U, 159U, 4U);
}

TEST_F(NvicPeripheralTest, DisableIrq160to191)
{
    DisableIrqTest(nvic, registers, 160U, 191U, 5U);
}

TEST_F(NvicPeripheralTest, DisableIrq192to223)
{
    DisableIrqTest(nvic, registers, 192U, 223U, 6U);
}

TEST_F(NvicPeripheralTest, DisableIrq224to255)
{
    DisableIrqTest(nvic, registers, 224U, 255U, 7U);
}

TEST_F(NvicPeripheralTest, SetPendingIrq0to31)
{
    SetPendingIrqTest(nvic, registers, 0U,   31U, 0U);
}

TEST_F(NvicPeripheralTest, SetPendingIrq32to63)
{
    SetPendingIrqTest(nvic, registers, 32U,  63U, 1U);
}

TEST_F(NvicPeripheralTest, SetPendingIrq64to95)
{
    SetPendingIrqTest(nvic, registers, 64U,  95U, 2U);
}

TEST_F(NvicPeripheralTest, SetPendingIrq96to127)
{
    SetPendingIrqTest(nvic, registers, 96U,  127U, 3U);
}

TEST_F(NvicPeripheralTest, SetPendingIrq128to159)
{
    SetPendingIrqTest(nvic, registers, 128U, 159U, 4U);
}

TEST_F(NvicPeripheralTest, SetPendingIrq160to191)
{
    SetPendingIrqTest(nvic, registers, 160U, 191U, 5U);
}

TEST_F(NvicPeripheralTest, SetPendingIrq192to223)
{
    SetPendingIrqTest(nvic, registers, 192U, 223U, 6U);
}

TEST_F(NvicPeripheralTest, SetPendingIrq224to255)
{
    SetPendingIrqTest(nvic, registers, 224U, 255U, 7U);
}

TEST_F(NvicPeripheralTest, ClearPendingIrq0to31)
{
    ClearPendingIrqTest(nvic, registers, 0U,   31U, 0U);
}

TEST_F(NvicPeripheralTest, ClearPendingIrq32to63)
{
    ClearPendingIrqTest(nvic, registers, 32U,  63U, 1U);
}

TEST_F(NvicPeripheralTest, ClearPendingIrq64to95)
{
    ClearPendingIrqTest(nvic, registers, 64U,  95U, 2U);
}

TEST_F(NvicPeripheralTest, ClearPendingIrq96to127)
{
    ClearPendingIrqTest(nvic, registers, 96U,  127U, 3U);
}

TEST_F(NvicPeripheralTest, ClearPendingIrq128to159)
{
    ClearPendingIrqTest(nvic, registers, 128U, 159U, 4U);
}

TEST_F(NvicPeripheralTest, ClearPendingIrq160to191)
{
    ClearPendingIrqTest(nvic, registers, 160U, 191U, 5U);
}

TEST_F(NvicPeripheralTest, ClearPendingIrq192to223)
{
    ClearPendingIrqTest(nvic, registers, 192U, 223U, 6U);
}

TEST_F(NvicPeripheralTest, ClearPendingIrq224to255)
{
    ClearPendingIrqTest(nvic, registers, 224U, 255U, 7U);
}

TEST_F(NvicPeripheralTest, IsIrqActive0to31)
{
    IsIrqActiveTest(nvic, registers, 0U,   31U, 0U);
}

TEST_F(NvicPeripheralTest, IsIrqActive32to63)
{
    IsIrqActiveTest(nvic, registers, 32U,  63U, 1U);
}

TEST_F(NvicPeripheralTest, IsIrqActive64to95)
{
    IsIrqActiveTest(nvic, registers, 64U,  95U, 2U);
}

TEST_F(NvicPeripheralTest, IsIrqActive96to127)
{
    IsIrqActiveTest(nvic, registers, 96U,  127U, 3U);
}

TEST_F(NvicPeripheralTest, IsIrqActive128to159)
{
    IsIrqActiveTest(nvic, registers, 128U, 159U, 4U);
}

TEST_F(NvicPeripheralTest, IsIrqActive160to191)
{
    IsIrqActiveTest(nvic, registers, 160U, 191U, 5U);
}

TEST_F(NvicPeripheralTest, IsIrqActive192to223)
{
    IsIrqActiveTest(nvic, registers, 192U, 223U, 6U);
}

TEST_F(NvicPeripheralTest, IsIrqActive224to255)
{
    IsIrqActiveTest(nvic, registers, 224U, 255U, 7U);
}

TEST_F(NvicPeripheralTest, IsIrqActiveReturnsFalse)
{
    registers.IABR[0].Value = 0xFFFFFFFEU;
    bool isActive = nvic.IsIrqActive(IrqNumber::WWDG);
    EXPECT_FALSE(isActive);

    registers.IABR[0].Value = 0xFFFFFFF7U;
    isActive = nvic.IsIrqActive(IrqNumber::RTC_WKUP);
    EXPECT_FALSE(isActive);
}

TEST_F(NvicPeripheralTest, GetActiveIrqs)
{
    registers.IABR[0].Value = 0x00000001U;

    auto activeIrqs = nvic.GetActiveIrqs();

    EXPECT_THAT(activeIrqs, ElementsAre(IrqNumber::WWDG));

    registers.IABR[0].Value = 0x00000003U;

    activeIrqs = nvic.GetActiveIrqs();

    EXPECT_THAT(activeIrqs, ElementsAre(
        IrqNumber::WWDG,
        IrqNumber::PVD));

    registers.IABR[0].Value = 0x00000007U;

    activeIrqs = nvic.GetActiveIrqs();

    EXPECT_THAT(activeIrqs, ElementsAre(
        IrqNumber::WWDG,
        IrqNumber::PVD,
        IrqNumber::TAMP_STAMP));

    registers.IABR[0].Value = 0x00000000U;
    registers.IABR[1].Value = 0x00000001U;

    activeIrqs = nvic.GetActiveIrqs();

    EXPECT_THAT(activeIrqs, ElementsAre(
        IrqNumber::I2C1_ER));

    registers.IABR[0].Value = 0x00000000U;
    registers.IABR[1].Value = 0x00000000U;
    registers.IABR[2].Value = 0x00020000U;

    activeIrqs = nvic.GetActiveIrqs();

    EXPECT_THAT(activeIrqs, ElementsAre(
        IrqNumber::FPU));

    registers.IABR[0].Value = 0xFFFFFFFFU;
    registers.IABR[1].Value = 0xFFFFFFFFU;
    registers.IABR[2].Value = 0xFFFFFFFFU;
    registers.IABR[3].Value = 0xFFFFFFFFU;
    registers.IABR[4].Value = 0xFFFFFFFFU;
    registers.IABR[5].Value = 0xFFFFFFFFU;
    registers.IABR[6].Value = 0xFFFFFFFFU;
    registers.IABR[7].Value = 0xFFFFFFFFU;

    // This will check for overflow, to make sure the GetActiveIrqs method does
    // not go past the end of the last IABR register.
    registers.Reserved5[0]  = 0xFFFFFFFFU;

    activeIrqs = nvic.GetActiveIrqs();

    EXPECT_EQ(256U, activeIrqs.size());
}

TEST_F(NvicPeripheralTest, SetIrqPriority)
{
    nvic.SetIrqPriority(IrqNumber::WWDG, 255U);
    EXPECT_EQ(0x000000FFU, registers.IPR[0].Value);
    nvic.SetIrqPriority(IrqNumber::PVD, 255U);
    EXPECT_EQ(0x0000FFFFU, registers.IPR[0].Value);
    nvic.SetIrqPriority(IrqNumber::TAMP_STAMP, 255U);
    EXPECT_EQ(0x00FFFFFFU, registers.IPR[0].Value);
    nvic.SetIrqPriority(IrqNumber::RTC_WKUP, 255U);
    EXPECT_EQ(0xFFFFFFFFU, registers.IPR[0].Value);

    nvic.SetIrqPriority(IrqNumber::FLASH, 255U);
    EXPECT_EQ(0x000000FFU, registers.IPR[1].Value);
    nvic.SetIrqPriority(IrqNumber::RCC, 255U);
    EXPECT_EQ(0x0000FFFFU, registers.IPR[1].Value);
    nvic.SetIrqPriority(IrqNumber::EXTI0, 255U);
    EXPECT_EQ(0x00FFFFFFU, registers.IPR[1].Value);
    nvic.SetIrqPriority(IrqNumber::EXTI1, 255U);
    EXPECT_EQ(0xFFFFFFFFU, registers.IPR[1].Value);

    nvic.SetIrqPriority(IrqNumber::EXTI2, 255U);
    EXPECT_EQ(0x000000FFU, registers.IPR[2].Value);
    nvic.SetIrqPriority(IrqNumber::EXTI3, 255U);
    EXPECT_EQ(0x0000FFFFU, registers.IPR[2].Value);
    nvic.SetIrqPriority(IrqNumber::EXTI4, 255U);
    EXPECT_EQ(0x00FFFFFFU, registers.IPR[2].Value);
    nvic.SetIrqPriority(IrqNumber::DMA1_Stream0, 255U);
    EXPECT_EQ(0xFFFFFFFFU, registers.IPR[2].Value);

    nvic.SetIrqPriority((IrqNumber)236U, 255U);
    EXPECT_EQ(0x000000FFU, registers.IPR[59].Value);
    nvic.SetIrqPriority((IrqNumber)237U, 255U);
    EXPECT_EQ(0x0000FFFFU, registers.IPR[59].Value);
    nvic.SetIrqPriority((IrqNumber)238U, 255U);
    EXPECT_EQ(0x00FFFFFFU, registers.IPR[59].Value);
    nvic.SetIrqPriority((IrqNumber)239U, 255U);
    EXPECT_EQ(0xFFFFFFFFU, registers.IPR[59].Value);

    // This is beyond the bounds of the IPR registers.
    nvic.SetIrqPriority((IrqNumber)240U, 255U);
    EXPECT_EQ(0x00000000U, registers.Reserved6[0]);
}

TEST_F(NvicPeripheralTest, SetIrqPriorityAllValues)
{
    for (uint16_t priority = 0U; priority <= 255; priority++)
    {
        nvic.SetIrqPriority(IrqNumber::WWDG, (uint8_t)priority);
        EXPECT_EQ(priority, registers.IPR[0].Value);
    }
}