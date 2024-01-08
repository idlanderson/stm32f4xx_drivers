add_library(i2c STATIC "")

target_sources(i2c PRIVATE 
    i2c.cpp 
    i2c.hpp
    i2c_def.hpp
    i2c_register_map.hpp
    i2c_types.hpp)

target_include_directories(i2c PUBLIC ${CMAKE_SOURCE_DIR}/device)
target_include_directories(i2c INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})