add_executable(
    gpio_test
    gpio_test.cpp
)

target_link_libraries(
    gpio_test
    gpio
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(gpio_test)