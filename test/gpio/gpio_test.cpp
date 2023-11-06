#include "gpio_register_map_mock.hpp"
#include "gpio.hpp"
#include <cstring>

using namespace stm32::gpio;

class GpioPeripheralTest : public ::testing::Test
{
public:
    GpioPeripheralTest() : registerMap(registers), gpio(registerMap) { }
protected:

    void SetUp() override 
    {
        std::memset(&registers, 0, sizeof(registers));
    }

    void TearDown() override 
    {
        SetUp();
    }

    GpioRegisters registers = {};
    GpioRegisterMap registerMap;
    GpioPeripheral gpio;
};

TEST_F(GpioPeripheralTest, SetPinModeAllValues)
{
    gpio.SetPinMode(PinNumber::Pin0, Mode::Input);
    EXPECT_EQ(0x00000000U, registers.MODER.Value);
    gpio.SetPinMode(PinNumber::Pin0, Mode::GeneralPurposeOutput);
    EXPECT_EQ(0x00000001U, registers.MODER.Value);
    gpio.SetPinMode(PinNumber::Pin0, Mode::AlternateFunction);
    EXPECT_EQ(0x00000002U, registers.MODER.Value);
    gpio.SetPinMode(PinNumber::Pin0, Mode::Analog);
    EXPECT_EQ(0x00000003U, registers.MODER.Value);
}

TEST_F(GpioPeripheralTest, SetPinModeAllPins)
{
    uint32_t expected = 0x00000000U;

    for (uint8_t pin = 0U; pin <= 15U; pin++)
    {
        expected |= (0x3U << (pin * 2U));
        gpio.SetPinMode((PinNumber)pin, Mode::Analog);
        EXPECT_EQ(expected, registers.MODER.Value);
    }
}

TEST_F(GpioPeripheralTest, SetPinOutputTypeAllValues)
{
    gpio.SetPinOutputType(PinNumber::Pin0, OutputType::PushPull);
    EXPECT_EQ(0x00000000U, registers.OTYPER.Value);
    gpio.SetPinOutputType(PinNumber::Pin0, OutputType::OpenDrain);
    EXPECT_EQ(0x00000001U, registers.OTYPER.Value);
}

TEST_F(GpioPeripheralTest, SetPinOutputTypeAllPins)
{
    uint32_t expected = 0x00000000U;

    for (uint8_t pin = 0U; pin <= 15U; pin++)
    {
        expected |= (0x1U << pin);
        gpio.SetPinOutputType((PinNumber)pin, OutputType::OpenDrain);
        EXPECT_EQ(expected, registers.OTYPER.Value);
    }
}

TEST_F(GpioPeripheralTest, SetPinSpeedAllPins)
{
    uint32_t expected = 0x00000000U;

    for (uint8_t pin = 0U; pin <= 15U; pin++)
    {
        expected |= (0x3U << (pin * 2U));
        gpio.SetPinSpeed((PinNumber)pin, Speed::VeryHighSpeed);
        EXPECT_EQ(expected, registers.OSPEEDR.Value);
    }
}

TEST_F(GpioPeripheralTest, SetPinSpeedAllValues)
{
    gpio.SetPinSpeed(PinNumber::Pin0, Speed::LowSpeed);
    EXPECT_EQ(0x00000000U, registers.OSPEEDR.Value);
    gpio.SetPinSpeed(PinNumber::Pin0, Speed::MediumSpeed);
    EXPECT_EQ(0x00000001U, registers.OSPEEDR.Value);
    gpio.SetPinSpeed(PinNumber::Pin0, Speed::HighSpeed);
    EXPECT_EQ(0x00000002U, registers.OSPEEDR.Value);
    gpio.SetPinSpeed(PinNumber::Pin0, Speed::VeryHighSpeed);
    EXPECT_EQ(0x00000003U, registers.OSPEEDR.Value);
}

TEST_F(GpioPeripheralTest, SetPinPullUpPullDownAllPins)
{
    uint32_t expected = 0x00000000U;

    for (uint8_t pin = 0U; pin <= 15U; pin++)
    {
        expected |= (0x2U << (pin * 2U));
        gpio.SetPinPullUpPullDown((PinNumber)pin, PullUpPullDown::PullDown);
        EXPECT_EQ(expected, registers.PUPDR.Value);
    }
}

TEST_F(GpioPeripheralTest, SetPinPullUpPullDownAllValues)
{
    gpio.SetPinPullUpPullDown(PinNumber::Pin0, PullUpPullDown::NoPullUpPullDown);
    EXPECT_EQ(0x00000000U, registers.PUPDR.Value);
    gpio.SetPinPullUpPullDown(PinNumber::Pin0, PullUpPullDown::PullUp);
    EXPECT_EQ(0x00000001U, registers.PUPDR.Value);
    gpio.SetPinPullUpPullDown(PinNumber::Pin0, PullUpPullDown::PullDown);
    EXPECT_EQ(0x00000002U, registers.PUPDR.Value);
}

TEST_F(GpioPeripheralTest, SetPinAltFcnAllValues)
{
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af0);
    EXPECT_EQ(0x00000000U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af1);
    EXPECT_EQ(0x00000001U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af2);
    EXPECT_EQ(0x00000002U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af3);
    EXPECT_EQ(0x00000003U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af4);
    EXPECT_EQ(0x00000004U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af5);
    EXPECT_EQ(0x00000005U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af6);
    EXPECT_EQ(0x00000006U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af7);
    EXPECT_EQ(0x00000007U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af8);
    EXPECT_EQ(0x00000008U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af9);
    EXPECT_EQ(0x00000009U, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af10);
    EXPECT_EQ(0x0000000AU, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af11);
    EXPECT_EQ(0x0000000BU, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af12);
    EXPECT_EQ(0x0000000CU, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af13);
    EXPECT_EQ(0x0000000DU, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af14);
    EXPECT_EQ(0x0000000EU, registers.AFRL.Value);
    gpio.SetPinAltFcn(PinNumber::Pin0, AlternateFunction::Af15);
    EXPECT_EQ(0x0000000FU, registers.AFRL.Value);
}

TEST_F(GpioPeripheralTest, SetPinAltFcnAllPins)
{
    uint32_t expected = 0x00000000U;

    for (uint8_t pin = 0U; pin <= 7U; pin++)
    {
        expected |= (0xFU << (pin * 4U));
        gpio.SetPinAltFcn((PinNumber)pin, AlternateFunction::Af15);
        EXPECT_EQ(expected, registers.AFRL.Value);
    }

    expected = 0x00000000U;

    for (uint8_t pin = 8U; pin <= 15U; pin++)
    {
        expected |= (0xFU << (pin * 4U));
        gpio.SetPinAltFcn((PinNumber)pin, AlternateFunction::Af15);
        EXPECT_EQ(expected, registers.AFRH.Value);
    }
}

TEST_F(GpioPeripheralTest, ConfigureInputPin)
{
    gpio.ConfigureInputPin(PinNumber::Pin0, Speed::VeryHighSpeed);
    EXPECT_EQ(0x00000000U, registers.MODER.Value);
    EXPECT_EQ(0x00000003U, registers.OSPEEDR.Value);
    EXPECT_EQ(0x00000000U, registers.PUPDR.Value);
    EXPECT_EQ(0x00000000U, registers.OTYPER.Value);
}

TEST_F(GpioPeripheralTest, ConfigureOutputPin)
{
    gpio.ConfigureOutputPin(
        PinNumber::Pin0,
        Speed::VeryHighSpeed,
        PullUpPullDown::PullUp,
        OutputType::OpenDrain);

    EXPECT_EQ(0x00000001U, registers.MODER.Value);
    EXPECT_EQ(0x00000003U, registers.OSPEEDR.Value);
    EXPECT_EQ(0x00000001U, registers.PUPDR.Value);
    EXPECT_EQ(0x00000001U, registers.OTYPER.Value);
}

TEST_F(GpioPeripheralTest, ReadPin)
{
    for (uint8_t pin = 0U; pin <= 15U; pin++)
    {
        registers.IDR.Value = (1U << pin);
        EXPECT_EQ(1U, gpio.ReadPin((PinNumber)pin));
    }

    for (uint8_t pin = 0U; pin <= 15U; pin++)
    {
        registers.IDR.Value = 0xFFFFFFFFU & ~(1U << pin);
        EXPECT_EQ(0U, gpio.ReadPin((PinNumber)pin));
    }
}

TEST_F(GpioPeripheralTest, WritePin)
{
    uint32_t expected = 0x00000000U;

    for (uint8_t pin = 0U; pin <= 15U; pin++)
    {
        registers.ODR.Value = 0x00000000U;
        expected = (1U << pin);
        gpio.WritePin((PinNumber)pin, 1U);
        EXPECT_EQ(expected, registers.ODR.Value);
    }

    for (uint8_t pin = 0U; pin <= 15U; pin++)
    {
        registers.ODR.Value = 0xFFFFFFFFU;
        expected = 0xFFFFFFFFU & ~(1U << pin);
        gpio.WritePin((PinNumber)pin, 0U);
        EXPECT_EQ(expected, registers.ODR.Value);
    }
}

TEST_F(GpioPeripheralTest, TogglePin)
{
    uint32_t expected = 0x00000000U;

    for (uint8_t pin = 0U; pin <= 15U; pin++)
    {
        registers.ODR.Value = 0x00000000U;
        expected = (1U << pin);
        gpio.TogglePin((PinNumber)pin);
        EXPECT_EQ(expected, registers.ODR.Value);
        gpio.TogglePin((PinNumber)pin);
        EXPECT_EQ(0x00000000U, registers.ODR.Value);
    }
}