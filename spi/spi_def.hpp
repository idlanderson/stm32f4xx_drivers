#ifndef SPI_DEF_HPP_H_
#define SPI_DEF_HPP_H_

#include "spi.hpp"

namespace stm32::spi
{
    SpiPeripheral SPI1;
    SpiPeripheral SPI2;
    SpiPeripheral SPI3;
    SpiPeripheral SPI4;
    SpiPeripheral SPI5;
    SpiPeripheral SPI6;

    void Init()
    {
        SPI1.Init(reinterpret_cast<SpiRegisterMap*>(SPI1_BASEADDR));
        SPI2.Init(reinterpret_cast<SpiRegisterMap*>(SPI2_BASEADDR));
        SPI3.Init(reinterpret_cast<SpiRegisterMap*>(SPI3_BASEADDR));
        SPI4.Init(reinterpret_cast<SpiRegisterMap*>(SPI4_BASEADDR));
        SPI5.Init(reinterpret_cast<SpiRegisterMap*>(SPI5_BASEADDR));
        SPI6.Init(reinterpret_cast<SpiRegisterMap*>(SPI6_BASEADDR));
    }
}

#endif // SPI_DEF_HPP_H_