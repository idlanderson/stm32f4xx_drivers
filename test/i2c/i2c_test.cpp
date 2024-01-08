#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "i2c.hpp"

using namespace stm32::i2c;
using namespace testing;

class I2CPeripheralTest : public ::testing::Test
{
public:
    I2CPeripheralTest() { }
protected:
    void SetUp() override { }
    void TearDown() override { }
    I2CPeripheral test;
};

TEST(I2CTest, Test1)
{
    EXPECT_TRUE(true);
}