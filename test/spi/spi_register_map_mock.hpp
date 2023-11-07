#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "spi_register_map.hpp"

using namespace stm32::spi;
using namespace testing;

class MockSpiRegisterMap : public ISpiRegisterMap
{
public:

	// CR1 Fields
	MOCK_METHOD(ClockPhase, get_CR1_CPHA, (), (const, override));
	MOCK_METHOD(ClockPolarity, get_CR1_CPOL, (), (const, override));
	MOCK_METHOD(MasterSelection, get_CR1_MSTR, (), (const, override));
	MOCK_METHOD(BaudRateControl, get_CR1_BR, (), (const, override));
	MOCK_METHOD(SpiEnable, get_CR1_SPE, (), (const, override));
	MOCK_METHOD(LsbFirst, get_CR1_LSBFIRST, (), (const, override));
	MOCK_METHOD(InternalSlaveSelect, get_CR1_SSI, (), (const, override));
	MOCK_METHOD(SoftwareSlaveManagement, get_CR1_SSM, (), (const, override));
	MOCK_METHOD(ReceiveOnly, get_CR1_RXONLY, (), (const, override));
	MOCK_METHOD(DataFrameFormat, get_CR1_DFF, (), (const, override));
	MOCK_METHOD(CrcTransferNext, get_CR1_CRCNEXT, (), (const, override));
	MOCK_METHOD(HardwareCrcCalculationEnable, get_CR1_CRCEN, (), (const, override));
	MOCK_METHOD(OutputEnableInBidirectionalMode, get_CR1_BIDIOE, (), (const, override));
	MOCK_METHOD(BidirectionalDataModeEnable, get_CR1_BIDIMODE, (), (const, override));
	MOCK_METHOD(void, set_CR1_CPHA, (ClockPhase), (override));
	MOCK_METHOD(void, set_CR1_CPOL, (ClockPolarity), (override));
	MOCK_METHOD(void, set_CR1_MSTR, (MasterSelection), (override));
	MOCK_METHOD(void, set_CR1_BR, (BaudRateControl), (override));
	MOCK_METHOD(void, set_CR1_SPE, (SpiEnable), (override));
	MOCK_METHOD(void, set_CR1_LSBFIRST, (LsbFirst), (override));
	MOCK_METHOD(void, set_CR1_SSI, (InternalSlaveSelect), (override));
	MOCK_METHOD(void, set_CR1_SSM, (SoftwareSlaveManagement), (override));
	MOCK_METHOD(void, set_CR1_RXONLY, (ReceiveOnly), (override));
	MOCK_METHOD(void, set_CR1_DFF, (DataFrameFormat), (override));
	MOCK_METHOD(void, set_CR1_CRCNEXT, (CrcTransferNext), (override));
	MOCK_METHOD(void, set_CR1_CRCEN, (HardwareCrcCalculationEnable), (override));
	MOCK_METHOD(void, set_CR1_BIDIOE, (OutputEnableInBidirectionalMode), (override));
	MOCK_METHOD(void, set_CR1_BIDIMODE, (BidirectionalDataModeEnable), (override));

	// CR2 Fields
	MOCK_METHOD(RxBufferDmaEnable, get_CR2_RXDMAEN, (), (const, override));
	MOCK_METHOD(TxBufferDmaEnable, get_CR2_TXDMAEN, (), (const, override));
	MOCK_METHOD(SsOutputEnable, get_CR2_SSOE, (), (const, override));
	MOCK_METHOD(FrameFormat, get_CR2_FRF, (), (const, override));
	MOCK_METHOD(ErrorInterruptEnable, get_CR2_ERRIE, (), (const, override));
	MOCK_METHOD(RxBufferNotEmptyInterruptEnable, get_CR2_RXNEIE, (), (const, override));
	MOCK_METHOD(TxBufferEmptyInterruptEnable, get_CR2_TXEIE, (), (const, override));
	MOCK_METHOD(void, set_CR2_RXDMAEN, (RxBufferDmaEnable), (override));
	MOCK_METHOD(void, set_CR2_TXDMAEN, (TxBufferDmaEnable), (override));
	MOCK_METHOD(void, set_CR2_SSOE, (SsOutputEnable), (override));
	MOCK_METHOD(void, set_CR2_FRF, (FrameFormat), (override));
	MOCK_METHOD(void, set_CR2_ERRIE, (ErrorInterruptEnable), (override));
	MOCK_METHOD(void, set_CR2_RXNEIE, (RxBufferNotEmptyInterruptEnable), (override));
	MOCK_METHOD(void, set_CR2_TXEIE, (TxBufferEmptyInterruptEnable), (override));

	// SR Fields
	MOCK_METHOD(ReceiveBufferNotEmpty, get_SR_RXNE, (), (const, override));
	MOCK_METHOD(TransmitBufferEmpty, get_SR_TXE, (), (const, override));
	MOCK_METHOD(ChannelSide, get_SR_CHSIDE, (), (const, override));
	MOCK_METHOD(UnderrunFlag, get_SR_UDR, (), (const, override));
	MOCK_METHOD(CrcErrorFlag, get_SR_CRCERR, (), (const, override));
	MOCK_METHOD(ModeFault, get_SR_MODF, (), (const, override));
	MOCK_METHOD(OverrunFlag, get_SR_OVR, (), (const, override));
	MOCK_METHOD(BusyFlag, get_SR_BSY, (), (const, override));
	MOCK_METHOD(FrameFormatError, get_SR_FRE, (), (const, override));
	MOCK_METHOD(void, set_SR_CRCERR, (CrcErrorFlag), (override));

	// DR Fields
	MOCK_METHOD(uint32_t, get_DR_DR, (), (const, override));
	MOCK_METHOD(void, set_DR_DR, (uint32_t), (override));

	// CRCPR Fields
	MOCK_METHOD(uint32_t, get_CRCPR_CRCPOLY, (), (const, override));
	MOCK_METHOD(void, set_CRCPR_CRCPOLY, (uint32_t), (override));

	// RXCRCR Fields
	MOCK_METHOD(uint32_t, get_RXCRCR_RXCRC, (), (const, override));

	// TXCRCR Fields
	MOCK_METHOD(uint32_t, get_TXCRCR_TXCRC, (), (const, override));

	// I2SCFGR Fields
	MOCK_METHOD(ChannelLength, get_I2SCFGR_CHLEN, (), (const, override));
	MOCK_METHOD(DataLengthToBeTransferred, get_I2SCFGR_DATLEN, (), (const, override));
	MOCK_METHOD(SteadyStateClockPolarity, get_I2SCFGR_CKPOL, (), (const, override));
	MOCK_METHOD(I2SStandardSelection, get_I2SCFGR_I2SSTD, (), (const, override));
	MOCK_METHOD(PcmFrameSynchronization, get_I2SCFGR_PCMSYNC, (), (const, override));
	MOCK_METHOD(I2SConfigurationMode, get_I2SCFGR_I2SCFG, (), (const, override));
	MOCK_METHOD(I2SEnable, get_I2SCFGR_I2SE, (), (const, override));
	MOCK_METHOD(I2SModeSelection, get_I2SCFGR_I2SMOD, (), (const, override));
	MOCK_METHOD(void, set_I2SCFGR_CHLEN, (ChannelLength), (override));
	MOCK_METHOD(void, set_I2SCFGR_DATLEN, (DataLengthToBeTransferred), (override));
	MOCK_METHOD(void, set_I2SCFGR_CKPOL, (SteadyStateClockPolarity), (override));
	MOCK_METHOD(void, set_I2SCFGR_I2SSTD, (I2SStandardSelection), (override));
	MOCK_METHOD(void, set_I2SCFGR_PCMSYNC, (PcmFrameSynchronization), (override));
	MOCK_METHOD(void, set_I2SCFGR_I2SCFG, (I2SConfigurationMode), (override));
	MOCK_METHOD(void, set_I2SCFGR_I2SE, (I2SEnable), (override));
	MOCK_METHOD(void, set_I2SCFGR_I2SMOD, (I2SModeSelection), (override));

	// I2SPR Fields
	MOCK_METHOD(uint32_t, get_I2SPR_I2SDIV, (), (const, override));
	MOCK_METHOD(OddFactorForThePrescaler, get_I2SPR_ODD, (), (const, override));
	MOCK_METHOD(MasterClockOutputEnable, get_I2SPR_MCKOE, (), (const, override));
	MOCK_METHOD(void, set_I2SPR_I2SDIV, (uint32_t), (override));
	MOCK_METHOD(void, set_I2SPR_ODD, (OddFactorForThePrescaler), (override));
	MOCK_METHOD(void, set_I2SPR_MCKOE, (MasterClockOutputEnable), (override));
};

