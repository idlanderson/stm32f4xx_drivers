#ifndef SPI_REGISTER_MAP_HPP_
#define SPI_REGISTER_MAP_HPP_

#include <cstdint>
#include "spi_types.hpp"

using namespace std;

namespace stm32::spi
{
	union CR1_t
	{
		volatile struct
		{
			ClockPhase                      CPHA        : 1; // [0]     rw : Clock phase
			ClockPolarity                   CPOL        : 1; // [1]     rw : Clock polarity
			MasterSelection                 MSTR        : 1; // [2]     rw : Master selection
			BaudRateControl                 BR          : 3; // [3:5]   rw : Baud rate control
			SpiEnable                       SPE         : 1; // [6]     rw : SPI enable
			LsbFirst                        LSBFIRST    : 1; // [7]     rw : LSB First
			InternalSlaveSelect             SSI         : 1; // [8]     rw : Internal slave select
			SoftwareSlaveManagement         SSM         : 1; // [9]     rw : Software slave management
			ReceiveOnly                     RXONLY      : 1; // [10]    rw : Receive only
			DataFrameFormat                 DFF         : 1; // [11]    rw : Data frame format
			CrcTransferNext                 CRCNEXT     : 1; // [12]    rw : CRC transfer next
			HardwareCrcCalculationEnable    CRCEN       : 1; // [13]    rw : Hardware CRC calculation enable
			OutputEnableInBidirectionalMode BIDIOE      : 1; // [14]    rw : Output enable in bidirectional mode
			BidirectionalDataModeEnable     BIDIMODE    : 1; // [15]    rw : Bidirectional data mode enable
			Reserved                        Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CR2_t
	{
		volatile struct
		{
			RxBufferDmaEnable               RXDMAEN     : 1; // [0]     rw : Rx buffer DMA enable
			TxBufferDmaEnable               TXDMAEN     : 1; // [1]     rw : Tx buffer DMA enable
			SsOutputEnable                  SSOE        : 1; // [2]     rw : SS output enable
			Reserved                        Reserved1   : 1; // [3]        : RESERVED FIELD.
			FrameFormat                     FRF         : 1; // [4]     rw : Frame format
			ErrorInterruptEnable            ERRIE       : 1; // [5]     rw : Error interrupt enable
			RxBufferNotEmptyInterruptEnable RXNEIE      : 1; // [6]     rw : RX buffer not empty interrupt enable
			TxBufferEmptyInterruptEnable    TXEIE       : 1; // [7]     rw : Tx buffer empty interrupt enable
			Reserved                        Reserved2   : 24; // [8:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union SR_t
	{
		volatile struct
		{
			ReceiveBufferNotEmpty RXNE        : 1; // [0]     r  : Receive buffer not empty
			TransmitBufferEmpty   TXE         : 1; // [1]     r  : Transmit buffer empty
			ChannelSide           CHSIDE      : 1; // [2]     r  : Channel side
			UnderrunFlag          UDR         : 1; // [3]     r  : Underrun flag
			CrcErrorFlag          CRCERR      : 1; // [4]     rw : CRC error flag
			ModeFault             MODF        : 1; // [5]     r  : Mode fault
			OverrunFlag           OVR         : 1; // [6]     r  : Overrun flag
			BusyFlag              BSY         : 1; // [7]     r  : Busy flag
			FrameFormatError      FRE         : 1; // [8]     r  : Frame format error
			Reserved              Reserved1   : 23; // [9:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union DR_t
	{
		volatile struct
		{
			uint32_t DR          : 16; // [0:15]  rw : Data register
			Reserved Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CRCPR_t
	{
		volatile struct
		{
			uint32_t CRCPOLY     : 16; // [0:15]  rw : CRC polynomial register
			Reserved Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union RXCRCR_t
	{
		volatile struct
		{
			uint32_t RXCRC       : 16; // [0:15]  r  : Rx CRC register
			Reserved Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union TXCRCR_t
	{
		volatile struct
		{
			uint32_t TXCRC       : 16; // [0:15]  r  : Tx CRC register
			Reserved Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union I2SCFGR_t
	{
		volatile struct
		{
			ChannelLength             CHLEN       : 1; // [0]     rw : Channel length
			DataLengthToBeTransferred DATLEN      : 2; // [1:2]   rw : Data length to be transferred
			SteadyStateClockPolarity  CKPOL       : 1; // [3]     rw : Steady state clock polarity
			I2SStandardSelection      I2SSTD      : 2; // [4:5]   rw : I2S standard selection
			Reserved                  Reserved1   : 1; // [6]        : RESERVED FIELD.
			PcmFrameSynchronization   PCMSYNC     : 1; // [7]     rw : PCM frame synchronization
			I2SConfigurationMode      I2SCFG      : 2; // [8:9]   rw : I2S configuration mode
			I2SEnable                 I2SE        : 1; // [10]    rw : I2S Enable
			I2SModeSelection          I2SMOD      : 1; // [11]    rw : I2S mode selection
			Reserved                  Reserved2   : 20; // [12:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union I2SPR_t
	{
		volatile struct
		{
			uint32_t                 I2SDIV      : 8; // [0:7]   rw : I2S Linear prescaler
			OddFactorForThePrescaler ODD         : 1; // [8]     rw : Odd factor for the prescaler
			MasterClockOutputEnable  MCKOE       : 1; // [9]     rw : Master clock output enable
			Reserved                 Reserved1   : 22; // [10:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	class SpiRegisterMap
	{
	public:

		// CR1 Fields
		ClockPhase get_CR1_CPHA() const { return CR1.Fields.CPHA; }
		ClockPolarity get_CR1_CPOL() const { return CR1.Fields.CPOL; }
		MasterSelection get_CR1_MSTR() const { return CR1.Fields.MSTR; }
		BaudRateControl get_CR1_BR() const { return CR1.Fields.BR; }
		SpiEnable get_CR1_SPE() const { return CR1.Fields.SPE; }
		LsbFirst get_CR1_LSBFIRST() const { return CR1.Fields.LSBFIRST; }
		InternalSlaveSelect get_CR1_SSI() const { return CR1.Fields.SSI; }
		SoftwareSlaveManagement get_CR1_SSM() const { return CR1.Fields.SSM; }
		ReceiveOnly get_CR1_RXONLY() const { return CR1.Fields.RXONLY; }
		DataFrameFormat get_CR1_DFF() const { return CR1.Fields.DFF; }
		CrcTransferNext get_CR1_CRCNEXT() const { return CR1.Fields.CRCNEXT; }
		HardwareCrcCalculationEnable get_CR1_CRCEN() const { return CR1.Fields.CRCEN; }
		OutputEnableInBidirectionalMode get_CR1_BIDIOE() const { return CR1.Fields.BIDIOE; }
		BidirectionalDataModeEnable get_CR1_BIDIMODE() const { return CR1.Fields.BIDIMODE; }
		void set_CR1_CPHA(ClockPhase value) { CR1.Fields.CPHA = value; }
		void set_CR1_CPOL(ClockPolarity value) { CR1.Fields.CPOL = value; }
		void set_CR1_MSTR(MasterSelection value) { CR1.Fields.MSTR = value; }
		void set_CR1_BR(BaudRateControl value) { CR1.Fields.BR = value; }
		void set_CR1_SPE(SpiEnable value) { CR1.Fields.SPE = value; }
		void set_CR1_LSBFIRST(LsbFirst value) { CR1.Fields.LSBFIRST = value; }
		void set_CR1_SSI(InternalSlaveSelect value) { CR1.Fields.SSI = value; }
		void set_CR1_SSM(SoftwareSlaveManagement value) { CR1.Fields.SSM = value; }
		void set_CR1_RXONLY(ReceiveOnly value) { CR1.Fields.RXONLY = value; }
		void set_CR1_DFF(DataFrameFormat value) { CR1.Fields.DFF = value; }
		void set_CR1_CRCNEXT(CrcTransferNext value) { CR1.Fields.CRCNEXT = value; }
		void set_CR1_CRCEN(HardwareCrcCalculationEnable value) { CR1.Fields.CRCEN = value; }
		void set_CR1_BIDIOE(OutputEnableInBidirectionalMode value) { CR1.Fields.BIDIOE = value; }
		void set_CR1_BIDIMODE(BidirectionalDataModeEnable value) { CR1.Fields.BIDIMODE = value; }

		// CR2 Fields
		RxBufferDmaEnable get_CR2_RXDMAEN() const { return CR2.Fields.RXDMAEN; }
		TxBufferDmaEnable get_CR2_TXDMAEN() const { return CR2.Fields.TXDMAEN; }
		SsOutputEnable get_CR2_SSOE() const { return CR2.Fields.SSOE; }
		FrameFormat get_CR2_FRF() const { return CR2.Fields.FRF; }
		ErrorInterruptEnable get_CR2_ERRIE() const { return CR2.Fields.ERRIE; }
		RxBufferNotEmptyInterruptEnable get_CR2_RXNEIE() const { return CR2.Fields.RXNEIE; }
		TxBufferEmptyInterruptEnable get_CR2_TXEIE() const { return CR2.Fields.TXEIE; }
		void set_CR2_RXDMAEN(RxBufferDmaEnable value) { CR2.Fields.RXDMAEN = value; }
		void set_CR2_TXDMAEN(TxBufferDmaEnable value) { CR2.Fields.TXDMAEN = value; }
		void set_CR2_SSOE(SsOutputEnable value) { CR2.Fields.SSOE = value; }
		void set_CR2_FRF(FrameFormat value) { CR2.Fields.FRF = value; }
		void set_CR2_ERRIE(ErrorInterruptEnable value) { CR2.Fields.ERRIE = value; }
		void set_CR2_RXNEIE(RxBufferNotEmptyInterruptEnable value) { CR2.Fields.RXNEIE = value; }
		void set_CR2_TXEIE(TxBufferEmptyInterruptEnable value) { CR2.Fields.TXEIE = value; }

		// SR Fields
		ReceiveBufferNotEmpty get_SR_RXNE() const { return SR.Fields.RXNE; }
		TransmitBufferEmpty get_SR_TXE() const { return SR.Fields.TXE; }
		ChannelSide get_SR_CHSIDE() const { return SR.Fields.CHSIDE; }
		UnderrunFlag get_SR_UDR() const { return SR.Fields.UDR; }
		CrcErrorFlag get_SR_CRCERR() const { return SR.Fields.CRCERR; }
		ModeFault get_SR_MODF() const { return SR.Fields.MODF; }
		OverrunFlag get_SR_OVR() const { return SR.Fields.OVR; }
		BusyFlag get_SR_BSY() const { return SR.Fields.BSY; }
		FrameFormatError get_SR_FRE() const { return SR.Fields.FRE; }
		void set_SR_CRCERR(CrcErrorFlag value) { SR.Fields.CRCERR = value; }

		// DR Fields
		uint32_t get_DR_DR() const { return DR.Fields.DR; }
		void set_DR_DR(uint32_t value) { DR.Fields.DR = value; }

		// CRCPR Fields
		uint32_t get_CRCPR_CRCPOLY() const { return CRCPR.Fields.CRCPOLY; }
		void set_CRCPR_CRCPOLY(uint32_t value) { CRCPR.Fields.CRCPOLY = value; }

		// RXCRCR Fields
		uint32_t get_RXCRCR_RXCRC() const { return RXCRCR.Fields.RXCRC; }

		// TXCRCR Fields
		uint32_t get_TXCRCR_TXCRC() const { return TXCRCR.Fields.TXCRC; }

		// I2SCFGR Fields
		ChannelLength get_I2SCFGR_CHLEN() const { return I2SCFGR.Fields.CHLEN; }
		DataLengthToBeTransferred get_I2SCFGR_DATLEN() const { return I2SCFGR.Fields.DATLEN; }
		SteadyStateClockPolarity get_I2SCFGR_CKPOL() const { return I2SCFGR.Fields.CKPOL; }
		I2SStandardSelection get_I2SCFGR_I2SSTD() const { return I2SCFGR.Fields.I2SSTD; }
		PcmFrameSynchronization get_I2SCFGR_PCMSYNC() const { return I2SCFGR.Fields.PCMSYNC; }
		I2SConfigurationMode get_I2SCFGR_I2SCFG() const { return I2SCFGR.Fields.I2SCFG; }
		I2SEnable get_I2SCFGR_I2SE() const { return I2SCFGR.Fields.I2SE; }
		I2SModeSelection get_I2SCFGR_I2SMOD() const { return I2SCFGR.Fields.I2SMOD; }
		void set_I2SCFGR_CHLEN(ChannelLength value) { I2SCFGR.Fields.CHLEN = value; }
		void set_I2SCFGR_DATLEN(DataLengthToBeTransferred value) { I2SCFGR.Fields.DATLEN = value; }
		void set_I2SCFGR_CKPOL(SteadyStateClockPolarity value) { I2SCFGR.Fields.CKPOL = value; }
		void set_I2SCFGR_I2SSTD(I2SStandardSelection value) { I2SCFGR.Fields.I2SSTD = value; }
		void set_I2SCFGR_PCMSYNC(PcmFrameSynchronization value) { I2SCFGR.Fields.PCMSYNC = value; }
		void set_I2SCFGR_I2SCFG(I2SConfigurationMode value) { I2SCFGR.Fields.I2SCFG = value; }
		void set_I2SCFGR_I2SE(I2SEnable value) { I2SCFGR.Fields.I2SE = value; }
		void set_I2SCFGR_I2SMOD(I2SModeSelection value) { I2SCFGR.Fields.I2SMOD = value; }

		// I2SPR Fields
		uint32_t get_I2SPR_I2SDIV() const { return I2SPR.Fields.I2SDIV; }
		OddFactorForThePrescaler get_I2SPR_ODD() const { return I2SPR.Fields.ODD; }
		MasterClockOutputEnable get_I2SPR_MCKOE() const { return I2SPR.Fields.MCKOE; }
		void set_I2SPR_I2SDIV(uint32_t value) { I2SPR.Fields.I2SDIV = value; }
		void set_I2SPR_ODD(OddFactorForThePrescaler value) { I2SPR.Fields.ODD = value; }
		void set_I2SPR_MCKOE(MasterClockOutputEnable value) { I2SPR.Fields.MCKOE = value; }

	private:

		CR1_t CR1; // Address Offset 0x0
		CR2_t CR2; // Address Offset 0x4
		SR_t SR; // Address Offset 0x8
		DR_t DR; // Address Offset 0xC
		CRCPR_t CRCPR; // Address Offset 0x10
		RXCRCR_t RXCRCR; // Address Offset 0x14
		TXCRCR_t TXCRCR; // Address Offset 0x18
		I2SCFGR_t I2SCFGR; // Address Offset 0x1C
		I2SPR_t I2SPR; // Address Offset 0x20
	};
}
#endif // SPI_REGISTER_MAP_HPP_