add_library(exti STATIC "")

target_sources(exti PRIVATE 
    exti.cpp 
    exti.hpp 
    #exti_def.hpp 
    exti_register_map.hpp
    exti_types.hpp)

target_include_directories(exti PUBLIC ${CMAKE_SOURCE_DIR}/device)
target_include_directories(exti INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})