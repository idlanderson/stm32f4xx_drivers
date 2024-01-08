# Pull down GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
    
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(rcc)
add_subdirectory(gpio)
add_subdirectory(spi)
add_subdirectory(i2c)
add_subdirectory(syscfg)
add_subdirectory(nvic)
add_subdirectory(exti)