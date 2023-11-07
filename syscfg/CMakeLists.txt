add_library(syscfg STATIC "")

target_sources(syscfg PRIVATE 
    syscfg.cpp 
    syscfg.hpp
    syscfg_def.hpp
    syscfg_register_map.hpp
    syscfg_types.hpp)

target_include_directories(syscfg PUBLIC ${CMAKE_SOURCE_DIR}/device)
target_include_directories(syscfg INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})