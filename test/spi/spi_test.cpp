#include <gtest/gtest.h>
#include "spi.hpp"

class SPITest : public ::testing::Test
{
protected:

    SPI spi;

    void SetUp() override 
    {
        ResetRegisters(ptr);
    }

    void TearDown() override 
    {
        ResetRegisters(ptr);
    }

private:

    DeviceRegister * ptr = reinterpret_cast<DeviceRegister *>(&spi);

    void ResetRegisters(DeviceRegister * spiPtr)
    {
        for (uint8_t i = 0U; i < sizeof(spi) / sizeof(DeviceRegister); i++)
        {
            spiPtr[i] = 0U;
        }
    }
};

TEST_F(SPITest, Test01)
{
    std::vector<uint8_t> data = { 1, 2, 3 };

    //spi.SendData(data);
}