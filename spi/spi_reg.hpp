#ifndef SPI_REG_HPP_
#define SPI_REG_HPP_

#include "stm32f4xx.hpp"
#include <cstdint>
#include <vector>

using DeviceRegister = std::uint32_t volatile;

class ISpiRegisters
{
public:

	virtual DeviceRegister GetCR1() const = 0;
	virtual DeviceRegister GetCR2() const = 0;
	virtual DeviceRegister GetSR() const = 0;
	virtual DeviceRegister GetDR() const = 0;
	virtual DeviceRegister GetCRCPR() const = 0;
	virtual DeviceRegister GetRXCRCR() const = 0;
	virtual DeviceRegister GetTXCRCR() const = 0;
	virtual DeviceRegister GetI2SCFGR() const = 0;
	virtual DeviceRegister GetI2SPR() const = 0;

	virtual void SetCR1(DeviceRegister value) = 0;		/* Address Offset 0x00.  */
	virtual void SetCR2(DeviceRegister value) = 0;		/* Address Offset 0x04.  */
	virtual void SetSR(DeviceRegister value) = 0;			/* Address Offset 0x08.  */
	virtual void SetDR(DeviceRegister value) = 0;			/* Address Offset 0x0C.  */
	virtual void SetCRCPR(DeviceRegister value) = 0;		/* Address Offset 0x10.  */
	virtual void SetRXCRCR(DeviceRegister value) = 0;		/* Address Offset 0x14.  */
	virtual void SetTXCRCR(DeviceRegister value) = 0;		/* Address Offset 0x18.  */
	virtual void SetI2SCFGR(DeviceRegister value) = 0;	/* Address Offset 0x1C.  */
	virtual void SetI2SPR(DeviceRegister value) = 0;		/* Address Offset 0x20.  */
};

class SpiRegisters : public ISpiRegisters
{
public:

	DeviceRegister GetCR1() const override     { return this->CR1; }
	DeviceRegister GetCR2() const override     { return this->CR2; }
	DeviceRegister GetSR() const override      { return this->SR; }
	DeviceRegister GetDR() const override      { return this->DR; }
	DeviceRegister GetCRCPR() const override   { return this->CRCPR; }
	DeviceRegister GetRXCRCR() const override  { return this->RXCRCR; }
	DeviceRegister GetTXCRCR() const override  { return this->TXCRCR; }
	DeviceRegister GetI2SCFGR() const override { return this->I2SCFGR; }
	DeviceRegister GetI2SPR() const override   { return this->I2SPR; }

	void SetCR1(DeviceRegister value) override     { this->CR1     = value; }
	void SetCR2(DeviceRegister value) override     { this->CR2     = value; }
	void SetSR(DeviceRegister value) override      { this->SR      = value; }
	void SetDR(DeviceRegister value) override      { this->DR      = value; }
	void SetCRCPR(DeviceRegister value) override   { this->CRCPR   = value; }
	void SetRXCRCR(DeviceRegister value) override  { this->RXCRCR  = value; }
	void SetTXCRCR(DeviceRegister value) override  { this->TXCRCR  = value; }
	void SetI2SCFGR(DeviceRegister value) override { this->I2SCFGR = value; }
	void SetI2SPR(DeviceRegister value) override   { this->I2SPR   = value; }

private:

	DeviceRegister CR1;			/* Address Offset 0x00.  */
	DeviceRegister CR2;			/* Address Offset 0x04.  */
	DeviceRegister SR;			/* Address Offset 0x08.  */
	DeviceRegister DR;			/* Address Offset 0x0C.  */
	DeviceRegister CRCPR;		/* Address Offset 0x10.  */
	DeviceRegister RXCRCR;		/* Address Offset 0x14.  */
	DeviceRegister TXCRCR;		/* Address Offset 0x18.  */
	DeviceRegister I2SCFGR;		/* Address Offset 0x1C.  */
	DeviceRegister I2SPR;		/* Address Offset 0x20.  */
};

#endif // SPI_REG_HPP_
