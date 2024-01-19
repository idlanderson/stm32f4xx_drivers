#ifndef I2C_DEF_HPP_
#define I2C_DEF_HPP_

#include "stm32f4xx.hpp"
#include "i2c.hpp"

using namespace std;

namespace stm32::i2c
{
    I2CRegisterMap I2C1RegMap(I2C1_BASEADDR);
    I2CRegisterMap I2C2RegMap(I2C2_BASEADDR);
    I2CRegisterMap I2C3RegMap(I2C3_BASEADDR);

    I2CPeripheral I2C1(I2C1RegMap);
    I2CPeripheral I2C2(I2C2RegMap);
    I2CPeripheral I2C3(I2C3RegMap);
} // namespace stm32::i2c

#endif // I2C_DEF_HPP_