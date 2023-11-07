add_executable(
    syscfg_test
    syscfg_test.cpp
    syscfg_register_map_test.cpp
)

target_link_libraries(
    syscfg_test
    syscfg
    gtest_main
    gmock_main
)

include(GoogleTest)
gtest_discover_tests(syscfg_test)