#include <gtest/gtest.h>
#include "rcc.hpp"

#define AHB1ENR_INDEX   12

class RCCTest : public ::testing::Test
{
protected:

    RCC rcc;

    void SetUp() override 
    {
        ResetRegisters(ptr);
    }

    void TearDown() override 
    {
        ResetRegisters(ptr);
    }

    DeviceRegister & AHB1ENR() { return ptr[AHB1ENR_INDEX]; }

private:

    DeviceRegister * ptr = reinterpret_cast<DeviceRegister *>(&rcc);

    void ResetRegisters(DeviceRegister * rccPtr)
    {
        for (uint8_t i = 0U; i < sizeof(rcc) / sizeof(DeviceRegister); i++)
        {
            rccPtr[i] = 0U;
        }
    }
};

TEST_F(RCCTest, SetAHB1PeripheralClockEnabled)
{
    rcc.SetAHB1PeripheralClockEnabled(RCC::AHB1_Peripheral::GPIOA, true);

    EXPECT_EQ(0x00000001U, AHB1ENR());
}