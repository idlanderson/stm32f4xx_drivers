#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "spi_register_map.hpp"

using namespace stm32::spi;

TEST(ControlRegister1, CPHA)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.CPHA = (ClockPhase)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(ControlRegister1, CPOL)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.CPOL = (ClockPolarity)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(ControlRegister1, MSTR)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.MSTR = (MasterSelection)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(ControlRegister1, BR)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.BR = (BaudRateControl)7U;
	EXPECT_EQ(0x00000038U, reg.Value);
}

TEST(ControlRegister1, SPE)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.SPE = (SpiEnable)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(ControlRegister1, LSBFIRST)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.LSBFIRST = (LsbFirst)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(ControlRegister1, SSI)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.SSI = (InternalSlaveSelect)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(ControlRegister1, SSM)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.SSM = (SoftwareSlaveManagement)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(ControlRegister1, RXONLY)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.RXONLY = (ReceiveOnly)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(ControlRegister1, DFF)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.DFF = (DataFrameFormat)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(ControlRegister1, CRCNEXT)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.CRCNEXT = (CrcTransferNext)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(ControlRegister1, CRCEN)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.CRCEN = (HardwareCrcCalculationEnable)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(ControlRegister1, BIDIOE)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.BIDIOE = (OutputEnableInBidirectionalMode)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(ControlRegister1, BIDIMODE)
{
	ControlRegister1 reg;
	reg.Value = 0U;
	reg.Fields.BIDIMODE = (BidirectionalDataModeEnable)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(ControlRegister2, RXDMAEN)
{
	ControlRegister2 reg;
	reg.Value = 0U;
	reg.Fields.RXDMAEN = (RxBufferDmaEnable)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(ControlRegister2, TXDMAEN)
{
	ControlRegister2 reg;
	reg.Value = 0U;
	reg.Fields.TXDMAEN = (TxBufferDmaEnable)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(ControlRegister2, SSOE)
{
	ControlRegister2 reg;
	reg.Value = 0U;
	reg.Fields.SSOE = (SsOutputEnable)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(ControlRegister2, RESERVED1)
{
	ControlRegister2 reg;
	reg.Value = 0U;
	reg.Fields.RESERVED1 = (uint8_t)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(ControlRegister2, FRF)
{
	ControlRegister2 reg;
	reg.Value = 0U;
	reg.Fields.FRF = (FrameFormat)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(ControlRegister2, ERRIE)
{
	ControlRegister2 reg;
	reg.Value = 0U;
	reg.Fields.ERRIE = (ErrorInterruptEnable)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(ControlRegister2, RXNEIE)
{
	ControlRegister2 reg;
	reg.Value = 0U;
	reg.Fields.RXNEIE = (RxBufferNotEmptyInterruptEnable)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(ControlRegister2, TXEIE)
{
	ControlRegister2 reg;
	reg.Value = 0U;
	reg.Fields.TXEIE = (TxBufferEmptyInterruptEnable)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(StatusRegister, RXNE)
{
	StatusRegister reg;
	reg.Value = 0U;
	reg.Fields.RXNE = (ReceiveBufferNotEmpty)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(StatusRegister, TXE)
{
	StatusRegister reg;
	reg.Value = 0U;
	reg.Fields.TXE = (TransmitBufferEmpty)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(StatusRegister, CHSIDE)
{
	StatusRegister reg;
	reg.Value = 0U;
	reg.Fields.CHSIDE = (ChannelSide)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(StatusRegister, UDR)
{
	StatusRegister reg;
	reg.Value = 0U;
	reg.Fields.UDR = (UnderrunFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(StatusRegister, CRCERR)
{
	StatusRegister reg;
	reg.Value = 0U;
	reg.Fields.CRCERR = (CrcErrorFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(StatusRegister, MODF)
{
	StatusRegister reg;
	reg.Value = 0U;
	reg.Fields.MODF = (ModeFault)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(StatusRegister, OVR)
{
	StatusRegister reg;
	reg.Value = 0U;
	reg.Fields.OVR = (OverrunFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(StatusRegister, BSY)
{
	StatusRegister reg;
	reg.Value = 0U;
	reg.Fields.BSY = (BusyFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(StatusRegister, FRE)
{
	StatusRegister reg;
	reg.Value = 0U;
	reg.Fields.FRE = (FrameFormatError)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(DataRegister, DR)
{
	DataRegister reg;
	reg.Value = 0U;
	reg.Fields.DR = (uint16_t)65535U;
	EXPECT_EQ(0x0000FFFFU, reg.Value);
}

TEST(CrcPolynomialRegister, CRCPOLY)
{
	CrcPolynomialRegister reg;
	reg.Value = 0U;
	reg.Fields.CRCPOLY = (uint16_t)65535U;
	EXPECT_EQ(0x0000FFFFU, reg.Value);
}

TEST(RxCrcRegister, RXCRC)
{
	RxCrcRegister reg;
	reg.Value = 0U;
	reg.Fields.RXCRC = (uint16_t)65535U;
	EXPECT_EQ(0x0000FFFFU, reg.Value);
}

TEST(TxCrcRegister, TXCRC)
{
	TxCrcRegister reg;
	reg.Value = 0U;
	reg.Fields.TXCRC = (uint16_t)65535U;
	EXPECT_EQ(0x0000FFFFU, reg.Value);
}

TEST(I2SConfigurationRegister, CHLEN)
{
	I2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.CHLEN = (ChannelLength)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(I2SConfigurationRegister, DATLEN)
{
	I2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.DATLEN = (DataLengthToBeTransferred)3U;
	EXPECT_EQ(0x00000006U, reg.Value);
}

TEST(I2SConfigurationRegister, CKPOL)
{
	I2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.CKPOL = (SteadyStateClockPolarity)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(I2SConfigurationRegister, I2SSTD)
{
	I2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.I2SSTD = (I2SStandardSelection)3U;
	EXPECT_EQ(0x00000030U, reg.Value);
}

TEST(I2SConfigurationRegister, RESERVED1)
{
	I2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.RESERVED1 = (uint8_t)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(I2SConfigurationRegister, PCMSYNC)
{
	I2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.PCMSYNC = (PcmFrameSynchronization)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(I2SConfigurationRegister, I2SCFG)
{
	I2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.I2SCFG = (I2SConfigurationMode)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(I2SConfigurationRegister, I2SE)
{
	I2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.I2SE = (I2SEnable)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(I2SConfigurationRegister, I2SMOD)
{
	I2SConfigurationRegister reg;
	reg.Value = 0U;
	reg.Fields.I2SMOD = (I2SModeSelection)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(I2SPrescalarRegister, I2SDIV)
{
	I2SPrescalarRegister reg;
	reg.Value = 0U;
	reg.Fields.I2SDIV = (uint8_t)255U;
	EXPECT_EQ(0x000000FFU, reg.Value);
}

TEST(I2SPrescalarRegister, ODD)
{
	I2SPrescalarRegister reg;
	reg.Value = 0U;
	reg.Fields.ODD = (OddFactorForThePrescaler)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(I2SPrescalarRegister, MCKOE)
{
	I2SPrescalarRegister reg;
	reg.Value = 0U;
	reg.Fields.MCKOE = (MasterClockOutputEnable)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

