#include "gpio_ports.hpp"
#include "rcc_def.hpp"
#include "spi_def.hpp"
#include "exti_def.hpp"
#include "nvic_def.hpp"
#include "syscfg_def.hpp"
#include "i2c_def.hpp"
#include <vector>
#include <cstdlib>
#include <stdio.h>

using namespace stm32::gpio;
using namespace stm32::rcc;
using namespace stm32::spi;
using namespace stm32::syscfg;
using namespace stm32::nvic;
using namespace stm32::exti;
using namespace stm32::i2c;

using Pin = stm32::gpio::PinNumber;
using PinSpeed = stm32::gpio::Speed;
using PullUpPullDown = stm32::gpio::PullUpPullDown;
using OutputType = stm32::gpio::OutputType;

void delay(uint32_t value)
{
	for (uint32_t i = 0U; i < value / 2U; i++);
}

void SpiInit(void)
{
    RCC.SetPeripheralClockEnabled(RccPeripheral::Peripheral::SYSCFG, true);
    RCC.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOB, true);
    RCC.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOD, true);
    RCC.SetPeripheralClockEnabled(RccPeripheral::Peripheral::SPI2, true);
    
    // PB12 = NSS
    // Apparently there is a hardware problem with the NSS pin. It always stays at 0 when using Hardware Slave Management.
    // We need to manually actuate the NSS line using the software.
    GPIOB.ConfigureOutputPin(
        Pin::Pin12, 
        Speed::VeryHighSpeed, 
        PullUpPullDown::NoPullUpPullDown, 
        OutputType::PushPull);

    // PB13 = SCLK
    GPIOB.ConfigureAltFcnPin(
        Pin::Pin13,
        Speed::VeryHighSpeed,
        PullUpPullDown::NoPullUpPullDown,
        OutputType::PushPull,
        AlternateFunction::Af5);
    
    // PB14 = MISO
    GPIOB.ConfigureAltFcnPin(
        Pin::Pin14,
        Speed::VeryHighSpeed,
        PullUpPullDown::NoPullUpPullDown,
        OutputType::PushPull,
        AlternateFunction::Af5);

    // PB15 = MOSI
    GPIOB.ConfigureAltFcnPin(
        Pin::Pin15,
        Speed::VeryHighSpeed,
        PullUpPullDown::NoPullUpPullDown,
        OutputType::PushPull,
        AlternateFunction::Af5);

    SPI2.SetBusConfig(BusConfig::FullDuplex);
    SPI2.SetDeviceMode(MasterSelection::Master);
    SPI2.SetBaudRate(BaudRateControl::FpclkDiv8);
    SPI2.SetDataFrameFormat(DataFrameFormat::_8Bit);
    SPI2.SetClockPolarity(ClockPolarity::CkTo0WhenIdle);
    SPI2.SetClockPhase(ClockPhase::FirstClockTransition);
    SPI2.SetSlaveManagement(SoftwareSlaveManagement::Disabled);
    SPI2.SetSlaveSelectOutputEnabled(SsOutputEnable::Enabled);
    SPI2.SetEnabled(SpiEnable::Enabled);

    // PD6 = Interrupt pin which notifies the master that data is available.
    // The flow is like this:
    //      GPIOD Pin 6 (falling edge) -> EXTI Line 6 -> NVIC IRQ Number 23 -> EXTI9_5_Handler()
    GPIOD.ConfigureInputPin(Pin::Pin6, Speed::VeryHighSpeed);
    
    // Configure GPIOD Pin 6 to trigger EXTI interrupt on line 6.
    SYSCFG.ConfigureGpioIrq(6U, ExtiConfiguration::PdxPin);

    // Unmask EXTI line 6. This will carry the external interrupt from PD6 to the NVIC.
    EXTI.SetIrqMask(6U, InterruptMask::NotMasked);
    EXTI.SetRisingTriggerEnabled(6U, false);
    EXTI.SetFallingTriggerEnabled(6U, true);

    // EXTI9_5 generates this IRQ Number 23 on the NVIC.
    NVIC.EnableIrq(IrqNumber::EXTI9_5);
    NVIC.SetIrqPriority(IrqNumber::EXTI9_5, 15U);

    // Enable the SPI2 interrupts. These will be triggered when the TXEIE and RXNEIE flags are set.
    // The handler is SPI2_Handler().
    NVIC.EnableIrq(IrqNumber::SPI2);
}

bool spiDataAvailable = false;

void LedAndButtonInit()
{
    RCC.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOA, true);
    RCC.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOD, true);

    GPIOA.ConfigureInputPin(Pin::Pin0, PinSpeed::VeryHighSpeed);

    GPIOD.ConfigureOutputPin(
        Pin::Pin12, 
        PinSpeed::VeryHighSpeed, 
        PullUpPullDown::NoPullUpPullDown, 
        OutputType::PushPull);

    GPIOD.ConfigureOutputPin(
        Pin::Pin13, 
        PinSpeed::VeryHighSpeed, 
        PullUpPullDown::NoPullUpPullDown, 
        OutputType::PushPull);

    GPIOD.ConfigureOutputPin(
        Pin::Pin14, 
        PinSpeed::VeryHighSpeed, 
        PullUpPullDown::NoPullUpPullDown, 
        OutputType::PushPull);

    GPIOD.ConfigureOutputPin(
        Pin::Pin15, 
        PinSpeed::VeryHighSpeed, 
        PullUpPullDown::NoPullUpPullDown, 
        OutputType::PushPull);
}

void SpiAsyncRxExercise()
{
    SpiInit();

    stm32::spi::SpiData dummyTx = { 0xAB };

    for (;;)
    {
        while (!spiDataAvailable);

        SPI2.SendDataAsync(dummyTx);
        SPI2.ReceiveDataAsync(1);

        spiDataAvailable = false;
    }
}

void I2CInit()
{
    RCC.SetPeripheralClockEnabled(RccPeripheral::Peripheral::GPIOB, true);
    RCC.SetPeripheralClockEnabled(RccPeripheral::Peripheral::I2C1, true);

    // I2C1 SCL = PB6 Alternate Function 4
    GPIOB.ConfigureAltFcnPin(
        PinNumber::Pin6,
        Speed::VeryHighSpeed,
        PullUpPullDown::PullUp,
        OutputType::OpenDrain,
        AlternateFunction::Af4);

    // I2C1 SDA = PB7 Alternate Function 4
    GPIOB.ConfigureAltFcnPin(
        PinNumber::Pin7,
        Speed::VeryHighSpeed,
        PullUpPullDown::PullUp,
        OutputType::OpenDrain,
        AlternateFunction::Af4);

    I2C1.SetSerialClock(16U, 100U);
}

void I2CTxExercise()
{
    I2CInit();

    LedAndButtonInit();

    GPIOD.WritePin(Pin::Pin12, 1U);
    GPIOD.WritePin(Pin::Pin13, 1U);
    GPIOD.WritePin(Pin::Pin14, 1U);
    GPIOD.WritePin(Pin::Pin15, 1U);

    for (;;)
    {
        delay(500000U);

        if (GPIOA.ReadPin(Pin::Pin0) == 1U)
        {
            I2C1.MasterWriteData("Hello world!", 0x68U, false);

            GPIOD.TogglePin(Pin::Pin12);
            GPIOD.TogglePin(Pin::Pin13);
            GPIOD.TogglePin(Pin::Pin14);
            GPIOD.TogglePin(Pin::Pin15);
        }
    }
}

#define ARDUINO                 0x68U
#define I2C_READ_DATA_LENGTH    0x51U
#define I2C_READ_DATA           0x52U

void I2CRxExercise()
{
    I2CInit();

    LedAndButtonInit();

    GPIOD.WritePin(Pin::Pin12, 1U);
    GPIOD.WritePin(Pin::Pin13, 1U);
    GPIOD.WritePin(Pin::Pin14, 1U);
    GPIOD.WritePin(Pin::Pin15, 1U);

    for (;;)
    {
        delay(500000U);

        if (GPIOA.ReadPin(Pin::Pin0) == 1U)
        {
            I2C1.MasterWriteData(I2C_READ_DATA_LENGTH, ARDUINO, true);
            
            auto length = I2C1.MasterReadData(1U, ARDUINO, true);

            printf("Length = %d\n", static_cast<int>(length[0]));

            I2C1.MasterWriteData(I2C_READ_DATA, ARDUINO, true);
            auto data = I2C1.MasterReadData(length[0], ARDUINO, false);

            for (auto d : data)
            {
                printf("%c", d);
            }
            
            GPIOD.TogglePin(Pin::Pin12);
            GPIOD.TogglePin(Pin::Pin13);
            GPIOD.TogglePin(Pin::Pin14);
            GPIOD.TogglePin(Pin::Pin15);
        }
    }
}

void I2CAsyncExercise()
{
    I2CInit();

    NVIC.EnableIrq(IrqNumber::I2C1_EV);
    NVIC.EnableIrq(IrqNumber::I2C1_ER);

    LedAndButtonInit();

    GPIOD.WritePin(Pin::Pin12, 1U);
    GPIOD.WritePin(Pin::Pin13, 1U);
    GPIOD.WritePin(Pin::Pin14, 1U);
    GPIOD.WritePin(Pin::Pin15, 1U);

    printf("I2C1 initialized. Waiting for button press...\n");

    I2C1.OnBusError([]() 
    { 
        printf("Bus Error\n"); 
        I2C1.CloseCommunication();
    });

    I2C1.OnArbitrationLost([]() 
    { 
        printf("Arbitration Lost\n"); 
        I2C1.CloseCommunication();
    });

    I2C1.OnAcknowledgeFailure([]() 
    { 
        printf("Acknowledge Failure\n");
        I2C1.CloseCommunication();
    });

    I2C1.OnOverrunUnderrun([]() 
    { 
        printf("Overrun/Underrun\n"); 
        I2C1.CloseCommunication();
    });

    I2C1.OnTimeout([]() 
    { 
        printf("Timeout\n"); 
        I2C1.CloseCommunication();
    });

    for (;;)
    {
        delay(500000U);

        if (GPIOA.ReadPin(Pin::Pin0) == 1U)
        {
            printf("Button pressed.\n");

            I2C1.MasterWriteDataAsync(I2C_READ_DATA_LENGTH, ARDUINO);

            while(I2C1.IsBusy());

            uint8_t length = 0;

            I2C1.MasterReadDataAsync(1U, ARDUINO, [& length](vector<uint8_t> & receivedData)
            { 
                length = receivedData[0];
            });

            while(I2C1.IsBusy());

            printf("Read 1 complete. Length = %d\n", length);

            I2C1.MasterWriteDataAsync(I2C_READ_DATA, ARDUINO);

            while(I2C1.IsBusy());

            string result;

            I2C1.MasterReadDataAsync(length, ARDUINO, [& result](vector<uint8_t> & receivedData)
            {
                result.assign(receivedData.begin(), receivedData.end());
            });

            while(I2C1.IsBusy());

            printf("Read 2 complete. Data = %s\n", result.c_str());

            GPIOD.TogglePin(Pin::Pin12);
            GPIOD.TogglePin(Pin::Pin13);
            GPIOD.TogglePin(Pin::Pin14);
            GPIOD.TogglePin(Pin::Pin15);
        }
    }
}

int main()
{
    I2CAsyncExercise();

    return 0U;
}

#ifdef __cplusplus
extern "C" {
#endif

void EXTI9_5_Handler(void)
{
    EXTI.ClearPendingBit(6);
    NVIC.ClearPendingIrq(IrqNumber::EXTI9_5);
    spiDataAvailable = true;
}

void SPI2_Handler(void)
{
    SPI2.HandleIrq();
}

void I2C1_EV_Handler(void)
{
    NVIC.ClearPendingIrq(IrqNumber::I2C1_EV);
    I2C1.HandleEventIrq();
}

void I2C1_ER_Handler(void)
{
    NVIC.ClearPendingIrq(IrqNumber::I2C1_ER);
    I2C1.HandleErrorIrq();
}

#ifdef __cplusplus
}
#endif