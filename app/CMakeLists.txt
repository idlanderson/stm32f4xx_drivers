add_executable(${PROJECT_NAME}.elf
    "stm32_startup.c"
    "syscalls.c"
    "main.cpp")

target_link_libraries(${PROJECT_NAME}.elf 
    rcc 
    gpio
    spi
    i2c
    usart
    syscfg
    rcc
    nvic
    exti)