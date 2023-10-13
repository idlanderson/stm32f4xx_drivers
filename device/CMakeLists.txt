add_library(device STATIC "")

target_sources(device PRIVATE stm32f4xx.cpp stm32f4xx.hpp)

target_include_directories(device INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})