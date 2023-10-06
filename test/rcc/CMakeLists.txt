add_executable(
    rcc_test
    rcc_test.cpp
)

target_link_libraries(
    rcc_test
    rcc
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(rcc_test)