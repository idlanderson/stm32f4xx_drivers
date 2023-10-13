#ifndef SPI_DEF_HPP_H_
#define SPI_DEF_HPP_H_

#include "spi.hpp"

namespace stm32::spi
{
    static SpiRegisterMap &SPI1Reg = *reinterpret_cast<SpiRegisterMap*>(SPI1_BASEADDR);
    static SpiRegisterMap &SPI2Reg = *reinterpret_cast<SpiRegisterMap*>(SPI2_BASEADDR);
    static SpiRegisterMap &SPI3Reg = *reinterpret_cast<SpiRegisterMap*>(SPI3_BASEADDR);
    static SpiRegisterMap &SPI4Reg = *reinterpret_cast<SpiRegisterMap*>(SPI4_BASEADDR);
    static SpiRegisterMap &SPI5Reg = *reinterpret_cast<SpiRegisterMap*>(SPI5_BASEADDR);
    static SpiRegisterMap &SPI6Reg = *reinterpret_cast<SpiRegisterMap*>(SPI6_BASEADDR);

    SpiPeripheral SPI1(SPI1Reg);
    SpiPeripheral SPI2(SPI2Reg);
    SpiPeripheral SPI3(SPI3Reg);
    SpiPeripheral SPI4(SPI4Reg);
    SpiPeripheral SPI5(SPI5Reg);
    SpiPeripheral SPI6(SPI6Reg);
}

#endif // SPI_DEF_HPP_H_