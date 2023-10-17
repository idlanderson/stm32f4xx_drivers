#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "spi_register_map.hpp"

using namespace stm32::spi;
using namespace testing;

class MockSpiRegisterMap : public ISpiRegisterMap
{
public:

	// CR1 Fields
	MOCK_CONST_METHOD0(get_CR1_CPHA, ClockPhase());
	MOCK_CONST_METHOD0(get_CR1_CPOL, ClockPolarity());
	MOCK_CONST_METHOD0(get_CR1_MSTR, MasterSelection());
	MOCK_CONST_METHOD0(get_CR1_BR, BaudRateControl());
	MOCK_CONST_METHOD0(get_CR1_SPE, SpiEnable());
	MOCK_CONST_METHOD0(get_CR1_LSBFIRST, LsbFirst());
	MOCK_CONST_METHOD0(get_CR1_SSI, InternalSlaveSelect());
	MOCK_CONST_METHOD0(get_CR1_SSM, SoftwareSlaveManagement());
	MOCK_CONST_METHOD0(get_CR1_RXONLY, ReceiveOnly());
	MOCK_CONST_METHOD0(get_CR1_DFF, DataFrameFormat());
	MOCK_CONST_METHOD0(get_CR1_CRCNEXT, CrcTransferNext());
	MOCK_CONST_METHOD0(get_CR1_CRCEN, HardwareCrcCalculationEnable());
	MOCK_CONST_METHOD0(get_CR1_BIDIOE, OutputEnableInBidirectionalMode());
	MOCK_CONST_METHOD0(get_CR1_BIDIMODE, BidirectionalDataModeEnable());
	MOCK_METHOD1(set_CR1_CPHA, void(ClockPhase value));
	MOCK_METHOD1(set_CR1_CPOL, void(ClockPolarity value));
	MOCK_METHOD1(set_CR1_MSTR, void(MasterSelection value));
	MOCK_METHOD1(set_CR1_BR, void(BaudRateControl value));
	MOCK_METHOD1(set_CR1_SPE, void(SpiEnable value));
	MOCK_METHOD1(set_CR1_LSBFIRST, void(LsbFirst value));
	MOCK_METHOD1(set_CR1_SSI, void(InternalSlaveSelect value));
	MOCK_METHOD1(set_CR1_SSM, void(SoftwareSlaveManagement value));
	MOCK_METHOD1(set_CR1_RXONLY, void(ReceiveOnly value));
	MOCK_METHOD1(set_CR1_DFF, void(DataFrameFormat value));
	MOCK_METHOD1(set_CR1_CRCNEXT, void(CrcTransferNext value));
	MOCK_METHOD1(set_CR1_CRCEN, void(HardwareCrcCalculationEnable value));
	MOCK_METHOD1(set_CR1_BIDIOE, void(OutputEnableInBidirectionalMode value));
	MOCK_METHOD1(set_CR1_BIDIMODE, void(BidirectionalDataModeEnable value));

	// CR2 Fields
	MOCK_CONST_METHOD0(get_CR2_RXDMAEN, RxBufferDmaEnable());
	MOCK_CONST_METHOD0(get_CR2_TXDMAEN, TxBufferDmaEnable());
	MOCK_CONST_METHOD0(get_CR2_SSOE, SsOutputEnable());
	MOCK_CONST_METHOD0(get_CR2_FRF, FrameFormat());
	MOCK_CONST_METHOD0(get_CR2_ERRIE, ErrorInterruptEnable());
	MOCK_CONST_METHOD0(get_CR2_RXNEIE, RxBufferNotEmptyInterruptEnable());
	MOCK_CONST_METHOD0(get_CR2_TXEIE, TxBufferEmptyInterruptEnable());
	MOCK_METHOD1(set_CR2_RXDMAEN, void(RxBufferDmaEnable value));
	MOCK_METHOD1(set_CR2_TXDMAEN, void(TxBufferDmaEnable value));
	MOCK_METHOD1(set_CR2_SSOE, void(SsOutputEnable value));
	MOCK_METHOD1(set_CR2_FRF, void(FrameFormat value));
	MOCK_METHOD1(set_CR2_ERRIE, void(ErrorInterruptEnable value));
	MOCK_METHOD1(set_CR2_RXNEIE, void(RxBufferNotEmptyInterruptEnable value));
	MOCK_METHOD1(set_CR2_TXEIE, void(TxBufferEmptyInterruptEnable value));

	// SR Fields
	MOCK_CONST_METHOD0(get_SR_RXNE, ReceiveBufferNotEmpty());
	MOCK_CONST_METHOD0(get_SR_TXE, TransmitBufferEmpty());
	MOCK_CONST_METHOD0(get_SR_CHSIDE, ChannelSide());
	MOCK_CONST_METHOD0(get_SR_UDR, UnderrunFlag());
	MOCK_CONST_METHOD0(get_SR_CRCERR, CrcErrorFlag());
	MOCK_CONST_METHOD0(get_SR_MODF, ModeFault());
	MOCK_CONST_METHOD0(get_SR_OVR, OverrunFlag());
	MOCK_CONST_METHOD0(get_SR_BSY, BusyFlag());
	MOCK_CONST_METHOD0(get_SR_FRE, FrameFormatError());
	MOCK_METHOD1(set_SR_CRCERR, void(CrcErrorFlag value));

	// DR Fields
	MOCK_CONST_METHOD0(get_DR_DR, uint16_t());
	MOCK_METHOD1(set_DR_DR, void(uint16_t value));

	// CRCPR Fields
	MOCK_CONST_METHOD0(get_CRCPR_CRCPOLY, uint16_t());
	MOCK_METHOD1(set_CRCPR_CRCPOLY, void(uint16_t value));

	// RXCRCR Fields
	MOCK_CONST_METHOD0(get_RXCRCR_RXCRC, uint16_t());

	// TXCRCR Fields
	MOCK_CONST_METHOD0(get_TXCRCR_TXCRC, uint16_t());

	// I2SCFGR Fields
	MOCK_CONST_METHOD0(get_I2SCFGR_CHLEN, ChannelLength());
	MOCK_CONST_METHOD0(get_I2SCFGR_DATLEN, DataLengthToBeTransferred());
	MOCK_CONST_METHOD0(get_I2SCFGR_CKPOL, SteadyStateClockPolarity());
	MOCK_CONST_METHOD0(get_I2SCFGR_I2SSTD, I2SStandardSelection());
	MOCK_CONST_METHOD0(get_I2SCFGR_PCMSYNC, PcmFrameSynchronization());
	MOCK_CONST_METHOD0(get_I2SCFGR_I2SCFG, I2SConfigurationMode());
	MOCK_CONST_METHOD0(get_I2SCFGR_I2SE, I2SEnable());
	MOCK_CONST_METHOD0(get_I2SCFGR_I2SMOD, I2SModeSelection());
	MOCK_METHOD1(set_I2SCFGR_CHLEN, void(ChannelLength value));
	MOCK_METHOD1(set_I2SCFGR_DATLEN, void(DataLengthToBeTransferred value));
	MOCK_METHOD1(set_I2SCFGR_CKPOL, void(SteadyStateClockPolarity value));
	MOCK_METHOD1(set_I2SCFGR_I2SSTD, void(I2SStandardSelection value));
	MOCK_METHOD1(set_I2SCFGR_PCMSYNC, void(PcmFrameSynchronization value));
	MOCK_METHOD1(set_I2SCFGR_I2SCFG, void(I2SConfigurationMode value));
	MOCK_METHOD1(set_I2SCFGR_I2SE, void(I2SEnable value));
	MOCK_METHOD1(set_I2SCFGR_I2SMOD, void(I2SModeSelection value));

	// I2SPR Fields
	MOCK_CONST_METHOD0(get_I2SPR_I2SDIV, uint8_t());
	MOCK_CONST_METHOD0(get_I2SPR_ODD, OddFactorForThePrescaler());
	MOCK_CONST_METHOD0(get_I2SPR_MCKOE, MasterClockOutputEnable());
	MOCK_METHOD1(set_I2SPR_I2SDIV, void(uint8_t value));
	MOCK_METHOD1(set_I2SPR_ODD, void(OddFactorForThePrescaler value));
	MOCK_METHOD1(set_I2SPR_MCKOE, void(MasterClockOutputEnable value));
};

