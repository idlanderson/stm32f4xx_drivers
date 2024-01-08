add_executable(
    i2c_test
    i2c_test.cpp
    i2c_register_map_test.cpp
)

target_link_libraries(
    i2c_test
    i2c
    gtest_main
    gmock_main
)

include(GoogleTest)
gtest_discover_tests(i2c_test)