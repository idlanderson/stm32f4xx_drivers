add_library(nvic STATIC "")

target_sources(nvic PRIVATE 
    nvic.cpp 
    nvic.hpp 
    nvic_def.hpp 
    nvic_register_map.hpp
    nvic_types.hpp)

target_include_directories(nvic PUBLIC ${CMAKE_SOURCE_DIR}/device)
target_include_directories(nvic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})