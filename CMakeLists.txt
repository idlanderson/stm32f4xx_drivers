cmake_minimum_required(VERSION 3.27.2)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/toolchain.cmake")

# CMake normally attempts a 'test compile and link'. This will fail when
# using the ARM cross-compiler with the custom linker flags we have set
# in the toolchain file. Setting this variable to 'STATIC_LIBRARY' tells
# CMake not to run the linker.
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(drivers_cpp
    VERSION 1.0
    DESCRIPTION "STM32F4xx Drivers (C++)"
    LANGUAGES C CXX)

add_subdirectory(gpio)
add_subdirectory(app)