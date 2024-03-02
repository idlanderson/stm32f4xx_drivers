cmake_minimum_required(VERSION 3.27.2)

option(BUILD_TESTS "Build the unit tests" OFF)

if (NOT BUILD_TESTS)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/toolchain.cmake")
else()
    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_CXX_COMPILER "g++")
endif()

# CMake normally attempts a 'test compile and link'. This will fail when
# using the ARM cross-compiler with the custom linker flags we have set
# in the toolchain file. Setting this variable to 'STATIC_LIBRARY' tells
# CMake not to run the linker.
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(drivers_cpp
    VERSION 1.0
    DESCRIPTION "STM32F4xx Drivers (C++)"
    LANGUAGES C CXX)

if (BUILD_TESTS)
    add_compile_options(-ggdb -fprofile-arcs -ftest-coverage -fprofile-abs-path)
    add_link_options(-lgcov --coverage)
    add_subdirectory(test)
else()
    add_subdirectory(app)
endif()

add_subdirectory(rcc)
add_subdirectory(gpio)
add_subdirectory(spi)
add_subdirectory(i2c)
add_subdirectory(usart)
add_subdirectory(syscfg)
add_subdirectory(nvic)
add_subdirectory(exti)
