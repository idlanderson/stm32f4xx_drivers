#ifndef SPI_DEF_HPP_H_
#define SPI_DEF_HPP_H_

#include "spi.hpp"

namespace stm32::spi
{
    SpiRegisterMap spi1RegMap(SPI1_BASEADDR);
    SpiRegisterMap spi2RegMap(SPI2_BASEADDR);
    SpiRegisterMap spi3RegMap(SPI3_BASEADDR);
    SpiRegisterMap spi4RegMap(SPI4_BASEADDR);
    SpiRegisterMap spi5RegMap(SPI5_BASEADDR);
    SpiRegisterMap spi6RegMap(SPI6_BASEADDR);

    SpiPeripheral SPI1(spi1RegMap);
    SpiPeripheral SPI2(spi2RegMap);
    SpiPeripheral SPI3(spi3RegMap);
    SpiPeripheral SPI4(spi4RegMap);
    SpiPeripheral SPI5(spi5RegMap);
    SpiPeripheral SPI6(spi6RegMap);
}

#endif // SPI_DEF_HPP_H_