#ifndef SPI_DEF_HPP_H_
#define SPI_DEF_HPP_H_

#include "spi.hpp"

namespace stm32::spi
{
    SpiPeripheral SPI1(SPI1_BASEADDR);
    SpiPeripheral SPI2(SPI2_BASEADDR);
    SpiPeripheral SPI3(SPI3_BASEADDR);
    SpiPeripheral SPI4(SPI4_BASEADDR);
    SpiPeripheral SPI5(SPI5_BASEADDR);
    SpiPeripheral SPI6(SPI6_BASEADDR);
}

#endif // SPI_DEF_HPP_H_