add_executable(
    usart_test
    usart_test.cpp
    usart_register_map_test.cpp
)

target_link_libraries(
    usart_test
    usart
    gtest_main
    gmock_main
)

include(GoogleTest)
gtest_discover_tests(usart_test)