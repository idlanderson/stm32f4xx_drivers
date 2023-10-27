#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "spi_register_map.hpp"

using namespace stm32::spi;

TEST(CR1, CPHA)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.CPHA = (ClockPhase)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(CR1, CPOL)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.CPOL = (ClockPolarity)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(CR1, MSTR)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.MSTR = (MasterSelection)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(CR1, BR)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.BR = (BaudRateControl)7U;
	EXPECT_EQ(0x00000038U, reg.Value);
}

TEST(CR1, SPE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.SPE = (SpiEnable)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(CR1, LSBFIRST)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.LSBFIRST = (LsbFirst)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(CR1, SSI)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.SSI = (InternalSlaveSelect)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(CR1, SSM)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.SSM = (SoftwareSlaveManagement)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(CR1, RXONLY)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.RXONLY = (ReceiveOnly)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(CR1, DFF)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.DFF = (DataFrameFormat)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(CR1, CRCNEXT)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.CRCNEXT = (CrcTransferNext)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(CR1, CRCEN)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.CRCEN = (HardwareCrcCalculationEnable)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(CR1, BIDIOE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.BIDIOE = (OutputEnableInBidirectionalMode)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(CR1, BIDIMODE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.BIDIMODE = (BidirectionalDataModeEnable)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(CR2, RXDMAEN)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.RXDMAEN = (RxBufferDmaEnable)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(CR2, TXDMAEN)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.TXDMAEN = (TxBufferDmaEnable)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(CR2, SSOE)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.SSOE = (SsOutputEnable)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(CR2, FRF)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.FRF = (FrameFormat)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(CR2, ERRIE)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.ERRIE = (ErrorInterruptEnable)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(CR2, RXNEIE)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.RXNEIE = (RxBufferNotEmptyInterruptEnable)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(CR2, TXEIE)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.TXEIE = (TxBufferEmptyInterruptEnable)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(SR, RXNE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.RXNE = (ReceiveBufferNotEmpty)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(SR, TXE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.TXE = (TransmitBufferEmpty)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(SR, CHSIDE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.CHSIDE = (ChannelSide)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(SR, UDR)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.UDR = (UnderrunFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(SR, CRCERR)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.CRCERR = (CrcErrorFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(SR, MODF)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.MODF = (ModeFault)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(SR, OVR)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.OVR = (OverrunFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(SR, BSY)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.BSY = (BusyFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(SR, FRE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.FRE = (FrameFormatError)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(DR, DR)
{
	DR_t reg;
	reg.Value = 0U;
	reg.Fields.DR = (uint32_t)65535U;
	EXPECT_EQ(0x0000FFFFU, reg.Value);
}

TEST(CRCPR, CRCPOLY)
{
	CRCPR_t reg;
	reg.Value = 0U;
	reg.Fields.CRCPOLY = (uint32_t)65535U;
	EXPECT_EQ(0x0000FFFFU, reg.Value);
}

TEST(RXCRCR, RXCRC)
{
	RXCRCR_t reg;
	reg.Value = 0U;
	reg.Fields.RXCRC = (uint32_t)65535U;
	EXPECT_EQ(0x0000FFFFU, reg.Value);
}

TEST(TXCRCR, TXCRC)
{
	TXCRCR_t reg;
	reg.Value = 0U;
	reg.Fields.TXCRC = (uint32_t)65535U;
	EXPECT_EQ(0x0000FFFFU, reg.Value);
}

TEST(I2SCFGR, CHLEN)
{
	I2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.CHLEN = (ChannelLength)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(I2SCFGR, DATLEN)
{
	I2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.DATLEN = (DataLengthToBeTransferred)3U;
	EXPECT_EQ(0x00000006U, reg.Value);
}

TEST(I2SCFGR, CKPOL)
{
	I2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.CKPOL = (SteadyStateClockPolarity)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(I2SCFGR, I2SSTD)
{
	I2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.I2SSTD = (I2SStandardSelection)3U;
	EXPECT_EQ(0x00000030U, reg.Value);
}

TEST(I2SCFGR, PCMSYNC)
{
	I2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.PCMSYNC = (PcmFrameSynchronization)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(I2SCFGR, I2SCFG)
{
	I2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.I2SCFG = (I2SConfigurationMode)3U;
	EXPECT_EQ(0x00000300U, reg.Value);
}

TEST(I2SCFGR, I2SE)
{
	I2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.I2SE = (I2SEnable)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(I2SCFGR, I2SMOD)
{
	I2SCFGR_t reg;
	reg.Value = 0U;
	reg.Fields.I2SMOD = (I2SModeSelection)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(I2SPR, I2SDIV)
{
	I2SPR_t reg;
	reg.Value = 0U;
	reg.Fields.I2SDIV = (uint32_t)255U;
	EXPECT_EQ(0x000000FFU, reg.Value);
}

TEST(I2SPR, ODD)
{
	I2SPR_t reg;
	reg.Value = 0U;
	reg.Fields.ODD = (OddFactorForThePrescaler)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(I2SPR, MCKOE)
{
	I2SPR_t reg;
	reg.Value = 0U;
	reg.Fields.MCKOE = (MasterClockOutputEnable)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

