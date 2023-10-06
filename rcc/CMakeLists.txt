add_library(rcc STATIC "")

target_sources(rcc PRIVATE rcc.cpp rcc.hpp rcc_def.hpp)

target_include_directories(rcc PUBLIC ${CMAKE_SOURCE_DIR}/device)
target_include_directories(rcc INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})