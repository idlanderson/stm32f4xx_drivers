#ifdef __cplusplus
#extern "C" {
#endif

#include <stdint.h>

#define SRAM_START  0x20000000U
#define SRAM_SIZE   (128U * 1024U)
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE))
#define STACK_START SRAM_END

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _la_data;

typedef void (*FuncPtr)();

extern FuncPtr __preinit_array_start[];
extern FuncPtr __preinit_array_end[];
extern FuncPtr __init_array_start[];
extern FuncPtr __init_array_end[];
extern FuncPtr __fini_array_start[];
extern FuncPtr __fini_array_end[];

int main(void);
void __libc_init_array(void);

void Reset_Handler(void);
void NMI_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void DebugMonitor_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void WWDG_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void PVD_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_Handler(void)               __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void RCC_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void EXTI0_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void EXTI1_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void EXTI2_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void EXTI3_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void EXTI4_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void ADC_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void CAN1_TX_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void CAN1_RX0_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void TIM2_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void TIM3_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void TIM4_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void SPI1_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void SPI2_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void USART1_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void USART2_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void USART3_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void OTG_FS_WKUP_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_TIM12_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void FSMC_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void SDIO_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void TIM5_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void SPI3_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void UART4_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void UART5_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void TIM7_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void ETH_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
void ETH_WKUP_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void CAN2_TX_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void CAN2_RX0_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void CAN2_RX1_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void CAN2_SCE_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void OTG_FS_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_Handler(void)             __attribute__((weak, alias("Default_Handler")));
void USART6_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_Handler(void)                  __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void OTG_HS_WKUP_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void OTG_HS_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void DCMI_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void CRYP_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void HASH_RNG_Handler(void)                 __attribute__((weak, alias("Default_Handler")));
void FPU_Handler(void)                      __attribute__((weak, alias("Default_Handler")));

// Reserved places should be 0.

uint32_t vectors[] __attribute__((section(".isr_vector"))) =
{
    STACK_START,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)&SVCall_Handler,
    (uint32_t)&DebugMonitor_Handler,
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,
    (uint32_t)&WWDG_Handler,
    (uint32_t)&PVD_Handler,
    (uint32_t)&TAMP_STAMP_Handler,
    (uint32_t)&RTC_WKUP_Handler,
    0,
    (uint32_t)&RCC_Handler,
    (uint32_t)&EXTI0_Handler,
    (uint32_t)&EXTI1_Handler,
    (uint32_t)&EXTI2_Handler,
    (uint32_t)&EXTI3_Handler,
    (uint32_t)&EXTI4_Handler,
    (uint32_t)&DMA1_Stream0_Handler,
    (uint32_t)&DMA1_Stream1_Handler,
    (uint32_t)&DMA1_Stream2_Handler,
    (uint32_t)&DMA1_Stream3_Handler,
    (uint32_t)&DMA1_Stream4_Handler,
    (uint32_t)&DMA1_Stream5_Handler,
    (uint32_t)&DMA1_Stream6_Handler,
    (uint32_t)&ADC_Handler,
    (uint32_t)&CAN1_TX_Handler,
    (uint32_t)&CAN1_RX0_Handler,
    (uint32_t)&CAN1_RX1_Handler,
    (uint32_t)&CAN1_SCE_Handler,
    (uint32_t)&EXTI9_5_Handler,
    (uint32_t)&TIM1_BRK_TIM9_Handler,
    (uint32_t)&TIM1_UP_TIM10_Handler,
    (uint32_t)&TIM1_TRG_COM_TIM11_Handler,
    (uint32_t)&TIM1_CC_Handler,
    (uint32_t)&TIM2_Handler,
    (uint32_t)&TIM3_Handler,
    (uint32_t)&TIM4_Handler,
    (uint32_t)&I2C1_EV_Handler,
    (uint32_t)&I2C1_ER_Handler,
    (uint32_t)&I2C2_EV_Handler,
    (uint32_t)&I2C2_ER_Handler,
    (uint32_t)&SPI1_Handler,
    (uint32_t)&SPI2_Handler,
    (uint32_t)&USART1_Handler,
    (uint32_t)&USART2_Handler,
    (uint32_t)&USART3_Handler,
    (uint32_t)&EXTI15_10_Handler,
    (uint32_t)&RTC_Alarm_Handler,
    (uint32_t)&OTG_FS_WKUP_Handler,
    (uint32_t)&TIM8_BRK_TIM12_Handler,
    (uint32_t)&TIM8_UP_TIM13_Handler,
    (uint32_t)&TIM8_TRG_COM_TIM14_Handler,
    (uint32_t)&TIM8_CC_Handler,
    (uint32_t)&DMA1_Stream7_Handler,
    (uint32_t)&FSMC_Handler,
    (uint32_t)&SDIO_Handler,
    (uint32_t)&TIM5_Handler,
    (uint32_t)&SPI3_Handler,
    (uint32_t)&UART4_Handler,
    (uint32_t)&UART5_Handler,
    (uint32_t)&TIM6_DAC_Handler,
    (uint32_t)&TIM7_Handler,
    (uint32_t)&DMA2_Stream0_Handler,
    (uint32_t)&DMA2_Stream1_Handler,
    (uint32_t)&DMA2_Stream2_Handler,
    (uint32_t)&DMA2_Stream3_Handler,
    (uint32_t)&DMA2_Stream4_Handler,
    (uint32_t)&ETH_Handler,
    (uint32_t)&ETH_WKUP_Handler,
    (uint32_t)&CAN2_TX_Handler,
    (uint32_t)&CAN2_RX0_Handler,
    (uint32_t)&CAN2_RX1_Handler,
    (uint32_t)&CAN2_SCE_Handler,
    (uint32_t)&OTG_FS_Handler,
    (uint32_t)&DMA2_Stream5_Handler,
    (uint32_t)&DMA2_Stream6_Handler,
    (uint32_t)&DMA2_Stream7_Handler,
    (uint32_t)&USART6_Handler,
    (uint32_t)&I2C3_EV_Handler,
    (uint32_t)&I2C3_ER_Handler,
    (uint32_t)&OTG_HS_EP1_OUT_Handler,
    (uint32_t)&OTG_HS_EP1_IN_Handler,
    (uint32_t)&OTG_HS_WKUP_Handler,
    (uint32_t)&OTG_HS_Handler,
    (uint32_t)&DCMI_Handler,
    (uint32_t)&CRYP_Handler,
    (uint32_t)&HASH_RNG_Handler,
    (uint32_t)&FPU_Handler
};

void Default_Handler(void)
{
    while(1);
}

// Credit for this code: https://github.com/cortexm/baremetal/blob/master/src/startup/startup.cpp
void call_init_array(void) 
{
    FuncPtr * array = __preinit_array_start;
    while (array < __preinit_array_end) 
    {
        (*array)();
        array++;
    }

    array = __init_array_start;
    while (array < __init_array_end) 
    {
        (*array)();
        array++;
    }
}

// Credit for this code: https://github.com/cortexm/baremetal/blob/master/src/startup/startup.cpp
void call_fini_array(void) 
{
    FuncPtr * array = __fini_array_start;
    while (array < __fini_array_end) {
        (*array)();
        array++;
    }
}

void copy_data_section(void)
{
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint8_t * dest = (uint8_t *)&_sdata;    // SRAM
    uint8_t * src  = (uint8_t *)&_la_data;  // FLASH

    for (uint32_t i = 0U; i < size; i++)
    {
        *dest++ = *src++;
    }
}

void init_bss(void)
{
    uint32_t size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    uint8_t * dest = (uint8_t *)&_sbss;

    for (uint32_t i = 0U; i < size; i++)
    {
        *dest++ = 0U;
    }
}

void Reset_Handler(void)
{
    // Copy .data section to SRAM
    copy_data_section();

    // Initialize .bss section to 0 in SRAM
    init_bss();

    // Call init function of std library (needed if you are using std libraries)
    __libc_init_array();

    // Call constructors
    call_init_array();

    // Invoke main()
    main();

    // Call destructors
    call_fini_array();
}

#ifdef __cplusplus
}
#endif