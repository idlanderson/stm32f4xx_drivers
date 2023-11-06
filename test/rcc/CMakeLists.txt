add_executable(
    rcc_test
    rcc_test.cpp
    rcc_register_map_test.cpp
)

target_link_libraries(
    rcc_test
    rcc
    gtest_main
    gmock_main
)

include(GoogleTest)
gtest_discover_tests(rcc_test)