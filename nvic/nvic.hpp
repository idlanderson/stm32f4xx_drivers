#ifndef NVIC_HPP_
#define NVIC_HPP_

#include "nvic_register_map.hpp"
#include <vector>

namespace stm32::nvic
{
    using IrqPriority = uint8_t;

    // This list is for the STM32F405xx/07xx and STM32F415xx/17xx microcontroller families
    enum class IrqNumber : uint8_t
    {
        WWDG = 0U,
        PVD = 1U,
        TAMP_STAMP = 2U,
        RTC_WKUP = 3U,
        FLASH = 4U,
        RCC = 5U,
        EXTI0 = 6U,
        EXTI1 = 7U,
        EXTI2 = 8U,
        EXTI3 = 9U,
        EXTI4 = 10U,
        DMA1_Stream0 = 11U,
        DMA1_Stream1 = 12U,
        DMA1_Stream2 = 13U,
        DMA1_Stream3 = 14U,
        DMA1_Stream4 = 15U,
        DMA1_Stream5 = 16U,
        DMA1_Stream6 = 17U,
        ADC = 18U,
        CAN1_TX = 19U,
        CAN1_RX0 = 20U,
        CAN1_RX1 = 21U,
        CAN1_SCE = 22U,
        EXTI9_5 = 23U,
        TIM1_BRK_TIM9 = 24U,
        TIM1_UP_TIM10 = 25U,
        TIM1_TRG_COM_TIM11 = 26U,
        TIM1_CC = 27U,
        TIM2 = 28U,
        TIM3 = 29U,
        TIM4 = 30U,
        I2C1_EV = 31U,
        I2C1_ER = 32U,
        I2C2_EV = 33U,
        I2C2_ER = 34U,
        SPI1 = 35U,
        SPI2 = 36U,
        USART1 = 37U,
        USART2 = 38U,
        USART3 = 39U,
        EXTI15_10 = 40U,
        RTC_Alarm = 41U,
        OTG_FS_WKUP = 42U,
        TIM8_BRK_TIM12 = 43U,
        TIM8_UP_TIM13 = 44U,
        TIM8_TRG_COM_TIM14 = 45U,
        TIM8_CC = 46U,
        DMA1_Stream7 = 47U,
        FSMC = 48U,
        SDIO = 49U,
        TIM5 = 50U,
        SPI3 = 51U,
        UART4 = 52U,
        UART5 = 53U,
        TIM6_DACTIM6 = 54U,
        TIM7 = 55U,
        DMA2_Stream0 = 56U,
        DMA2_Stream1 = 57U,
        DMA2_Stream2 = 58U,
        DMA2_Stream3 = 59U,
        DMA2_Stream4 = 60U,
        ETH = 61U,
        ETH_WKUP = 62U,
        CAN2_TX = 63U,
        CAN2_RX0 = 64U,
        CAN2_RX1 = 65U,
        CAN2_SCE = 66U,
        OTG_FS = 67U,
        DMA2_Stream5 = 68U,
        DMA2_Stream6 = 69U,
        DMA2_Stream7 = 70U,
        USART6 = 71U,
        I2C3_EV = 72U,
        I2C3_ER = 73U,
        OTG_HS_EP1_OUT = 74U,
        OTG_HS_EP1_IN = 75U,
        OTG_HS_WKUP = 76U,
        OTG_HS = 77U,
        DCMI = 78U,
        CRYP = 79U,
        HASH_RNG = 80U,
        FPU = 81U
    };

    class NvicPeripheral
    {
    public:
        NvicPeripheral(INvicRegisterMap & device) : device(device) { }
        void EnableIrq(IrqNumber irqNumber);
        void DisableIrq(IrqNumber irqNumber);
        void SetPendingIrq(IrqNumber irqNumber);
        void ClearPendingIrq(IrqNumber irqNumber);
        bool IsIrqActive(IrqNumber irqNumber);
        std::vector<IrqNumber> GetActiveIrqs();
        void SetIrqPriority(IrqNumber irqNumber, IrqPriority irqPriority);
        void TriggerInterrupt(IrqNumber irqNumber);
    private:
        INvicRegisterMap & device;
    };
}

#endif // NVIC_HPP_