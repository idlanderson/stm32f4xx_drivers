add_executable(${PROJECT_NAME}.elf
    "stm32_startup.c"
    "syscalls.c"
    "main.cpp")

target_link_libraries(${PROJECT_NAME}.elf 
    rcc 
    gpio
    spi
    syscfg
    rcc
    nvic
    exti)