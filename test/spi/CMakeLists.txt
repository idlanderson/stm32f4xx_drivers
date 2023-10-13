add_executable(
    spi_test
    spi_test.cpp
)

target_link_libraries(
    spi_test
    spi
    device
    gtest_main
    gmock_main
)

include(GoogleTest)
gtest_discover_tests(spi_test)