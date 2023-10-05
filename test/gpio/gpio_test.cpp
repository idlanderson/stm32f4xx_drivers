#include <gtest/gtest.h>
#include "gpio.hpp"

#define NUMBER_OF_REGISTERS_IN_GPIO 10
#define MODER_INDEX   0

using Pin = GPIO::PinNumber;
using Mode = GPIO::PinMode;

class GPIOTest : public ::testing::Test
{
protected:

    GPIO gpio;

    void SetUp() override 
    {
        ResetRegisters(ptr);
    }

    void TearDown() override 
    {
        ResetRegisters(ptr);
    }

    DeviceRegister & MODER() { return ptr[MODER_INDEX]; }

private:

    DeviceRegister * ptr = reinterpret_cast<DeviceRegister *>(&gpio);

    void ResetRegisters(DeviceRegister * gpioPtr)
    {
        for (uint8_t i = 0U; i < NUMBER_OF_REGISTERS_IN_GPIO; i++)
        {
            gpioPtr[i] = 0U;
        }
    }
};

TEST_F(GPIOTest, AllPinsModeInput)
{
    uint32_t expected_MODER = 0x00000000U;

    for (uint8_t pin = (uint8_t)Pin::Pin0; pin <= (uint8_t)Pin::Pin15; pin++)
    {
        MODER() = 0xFFFFFFFFU;
        expected_MODER = 0xFFFFFFFFU & ~(3U << pin * 2U);

        gpio.SetPinMode((Pin)pin, Mode::Input);

        EXPECT_EQ(expected_MODER, MODER());
    }
}

TEST_F(GPIOTest, AllPinsModeOutput)
{
    uint32_t expected_MODER = 0x00000000U;

    for (uint8_t pin = (uint8_t)Pin::Pin0; pin <= (uint8_t)Pin::Pin15; pin++)
    {
        MODER() = 0x00000000U;
        expected_MODER = (1U << pin * 2U);

        gpio.SetPinMode((Pin)pin, Mode::Output);

        EXPECT_EQ(expected_MODER, MODER());
    }
}

TEST_F(GPIOTest, AllPinsModeAltFcn)
{
    uint32_t expected_MODER = 0x00000000U;

    for (uint8_t pin = (uint8_t)Pin::Pin0; pin <= (uint8_t)Pin::Pin15; pin++)
    {
        MODER() = 0x00000000U;
        expected_MODER = (2U << pin * 2U);

        gpio.SetPinMode((Pin)pin, Mode::AltFcn);

        EXPECT_EQ(expected_MODER, MODER());
    }
}

TEST_F(GPIOTest, AllPinsModeAnalog)
{
    uint32_t expected_MODER = 0x00000000U;

    for (uint8_t pin = (uint8_t)Pin::Pin0; pin <= (uint8_t)Pin::Pin15; pin++)
    {
        MODER() = 0x00000000U;
        expected_MODER = (3U << pin * 2U);

        gpio.SetPinMode((Pin)pin, Mode::Analog);

        EXPECT_EQ(expected_MODER, MODER());
    }
}