add_executable(
    nvic_test
    nvic_test.cpp
    nvic_register_map_test.cpp
)

target_link_libraries(
    nvic_test
    nvic
    gtest_main
    gmock_main
)

include(GoogleTest)
gtest_discover_tests(nvic_test)