add_library(usart STATIC "")

target_sources(usart PRIVATE 
    usart.cpp 
    usart.hpp
    usart_def.hpp
    usart_register_map.hpp
    usart_types.hpp)

target_include_directories(usart PUBLIC ${CMAKE_SOURCE_DIR}/device)
target_include_directories(usart INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})