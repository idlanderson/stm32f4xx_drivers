add_executable(
    gpio_test
    gpio_test.cpp
    gpio_register_map_test.cpp
)

target_link_libraries(
    gpio_test
    gpio
    gtest_main
    gmock_main
)

include(GoogleTest)
gtest_discover_tests(gpio_test)