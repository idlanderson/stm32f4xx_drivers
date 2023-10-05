add_library(gpio STATIC "")

target_sources(gpio PRIVATE gpio.cpp gpio.hpp gpio_ports.hpp)

target_include_directories(gpio PUBLIC ${CMAKE_SOURCE_DIR}/device)
target_include_directories(gpio INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})