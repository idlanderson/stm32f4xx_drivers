add_library(spi STATIC "")

target_sources(spi PRIVATE 
    spi.cpp 
    spi.hpp
    spi_def.hpp
    spi_register_map.hpp
    spi_types.hpp)

target_include_directories(spi PUBLIC ${CMAKE_SOURCE_DIR}/device)
target_include_directories(spi INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})