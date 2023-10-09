#ifndef SPI_DEF_HPP_H_
#define SPI_DEF_HPP_H_

#include "spi.hpp"

SPI &SPI1 = *reinterpret_cast<SPI*>(SPI1_BASEADDR);
SPI &SPI2 = *reinterpret_cast<SPI*>(SPI2_BASEADDR);
SPI &SPI3 = *reinterpret_cast<SPI*>(SPI3_BASEADDR);
SPI &SPI4 = *reinterpret_cast<SPI*>(SPI4_BASEADDR);
SPI &SPI5 = *reinterpret_cast<SPI*>(SPI5_BASEADDR);
SPI &SPI6 = *reinterpret_cast<SPI*>(SPI6_BASEADDR);

#endif // SPI_DEF_HPP_H_