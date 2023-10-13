#include <gtest/gtest.h>
#include "spi.hpp"

using namespace stm32::spi;

class SpiPeripheralTest : public ::testing::Test
{
public:

    SpiPeripheralTest() : spi(spiRegisters) {}

protected:

    SpiRegisterMap spiRegisters;
    SpiPeripheral spi;

    void SetUp() override 
    {
        
    }

    void TearDown() override 
    {
        
    }

private:

};

TEST_F(SpiPeripheralTest, Test01)
{
    
}