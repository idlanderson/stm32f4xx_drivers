# 'Generic' tells CMake that we're cross-compiling for an embedded target.
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(LINUX)
    set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
    set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
else()
    set(CMAKE_C_COMPILER "arm-none-eabi-gcc.exe")
    set(CMAKE_CXX_COMPILER "arm-none-eabi-g++.exe")
endif()

add_compile_options(
    -c 
    -mcpu=cortex-m4
    -mthumb
    -mfloat-abi=soft
    $<$<COMPILE_LANGUAGE:C>:-std=gnu11>
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
    -Wall
    -O0
    -ggdb
    )
add_link_options(-mcpu=cortex-m4 -mthumb -mfloat-abi=soft -T ${PROJECT_SOURCE_DIR}/device/stm32f4xx.ld -Wl,-Map=drivers.map)