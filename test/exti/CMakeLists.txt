add_executable(
    exti_test
    exti_test.cpp
    exti_register_map_test.cpp
)

target_link_libraries(
    exti_test
    exti
    gtest_main
    gmock_main
)

include(GoogleTest)
gtest_discover_tests(exti_test)