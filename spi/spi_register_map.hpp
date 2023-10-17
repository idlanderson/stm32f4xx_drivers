#ifndef SPI_REGISTER_MAP_HPP_
#define SPI_REGISTER_MAP_HPP_

#include <cstdint>
#include "spi_types.hpp"

using namespace std;

namespace stm32::spi
{
	union ControlRegister1
	{
		volatile struct
		{
			ClockPhase                      CPHA      : 1; // [0]    rw : Clock phase
			ClockPolarity                   CPOL      : 1; // [1]    rw : Clock polarity
			MasterSelection                 MSTR      : 1; // [2]    rw : Master selection
			BaudRateControl                 BR        : 3; // [5:3]  rw : Baud rate control
			SpiEnable                       SPE       : 1; // [6]    rw : SPI enable
			LsbFirst                        LSBFIRST  : 1; // [7]    rw : LSB First
			InternalSlaveSelect             SSI       : 1; // [8]    rw : Internal slave select
			SoftwareSlaveManagement         SSM       : 1; // [9]    rw : Software slave management
			ReceiveOnly                     RXONLY    : 1; // [10]   rw : Receive only
			DataFrameFormat                 DFF       : 1; // [11]   rw : Data frame format
			CrcTransferNext                 CRCNEXT   : 1; // [12]   rw : CRC transfer next
			HardwareCrcCalculationEnable    CRCEN     : 1; // [13]   rw : Hardware CRC calculation enable
			OutputEnableInBidirectionalMode BIDIOE    : 1; // [14]   rw : Output enable in bidirectional mode
			BidirectionalDataModeEnable     BIDIMODE  : 1; // [15]   rw : Bidirectional data mode enable
			uint32_t                        RESERVED1 : 16;
		} Fields;
		volatile uint32_t Value;
	};

	union ControlRegister2
	{
		volatile struct
		{
			RxBufferDmaEnable               RXDMAEN   : 1; // [0]    rw : Rx buffer DMA enable
			TxBufferDmaEnable               TXDMAEN   : 1; // [1]    rw : Tx buffer DMA enable
			SsOutputEnable                  SSOE      : 1; // [2]    rw : SS output enable
			uint8_t                         RESERVED1 : 1; // [3]       : Reserved. Forced to 0 by hardware
			FrameFormat                     FRF       : 1; // [4]    rw : Frame format
			ErrorInterruptEnable            ERRIE     : 1; // [5]    rw : Error interrupt enable
			RxBufferNotEmptyInterruptEnable RXNEIE    : 1; // [6]    rw : RX buffer not empty interrupt enable
			TxBufferEmptyInterruptEnable    TXEIE     : 1; // [7]    rw : Tx buffer empty interrupt enable
			uint32_t                        RESERVED2 : 24;
		} Fields;
		volatile uint32_t Value;
	};

	union StatusRegister
	{
		volatile struct
		{
			ReceiveBufferNotEmpty RXNE      : 1; // [0]    r  : Receive buffer not empty
			TransmitBufferEmpty   TXE       : 1; // [1]    r  : Transmit buffer empty
			ChannelSide           CHSIDE    : 1; // [2]    r  : Channel side
			UnderrunFlag          UDR       : 1; // [3]    r  : Underrun flag
			CrcErrorFlag          CRCERR    : 1; // [4]    rw : CRC error flag
			ModeFault             MODF      : 1; // [5]    r  : Mode fault
			OverrunFlag           OVR       : 1; // [6]    r  : Overrun flag
			BusyFlag              BSY       : 1; // [7]    r  : Busy flag
			FrameFormatError      FRE       : 1; // [8]    r  : Frame format error
			uint32_t              RESERVED1 : 23;
		} Fields;
		volatile uint32_t Value;
	};

	union DataRegister
	{
		volatile struct
		{
			uint16_t DR        : 16; // [15:0] rw : Data register
			uint32_t RESERVED1 : 16;
		} Fields;
		volatile uint32_t Value;
	};

	union CrcPolynomialRegister
	{
		volatile struct
		{
			uint16_t CRCPOLY   : 16; // [15:0] rw : CRC polynomial register
			uint32_t RESERVED1 : 16;
		} Fields;
		volatile uint32_t Value;
	};

	union RxCrcRegister
	{
		volatile struct
		{
			uint16_t RXCRC     : 16; // [15:0] r  : Rx CRC register
			uint32_t RESERVED1 : 16;
		} Fields;
		volatile uint32_t Value;
	};

	union TxCrcRegister
	{
		volatile struct
		{
			uint16_t TXCRC     : 16; // [15:0] r  : Tx CRC register
			uint32_t RESERVED1 : 16;
		} Fields;
		volatile uint32_t Value;
	};

	union I2SConfigurationRegister
	{
		volatile struct
		{
			ChannelLength             CHLEN     : 1; // [0]    rw : Channel length
			DataLengthToBeTransferred DATLEN    : 2; // [2:1]  rw : Data length to be transferred
			SteadyStateClockPolarity  CKPOL     : 1; // [3]    rw : Steady state clock polarity
			I2SStandardSelection      I2SSTD    : 2; // [5:4]  rw : I2S standard selection
			uint8_t                   RESERVED1 : 1; // [6]       : Reserved: forced at 0 by hardware
			PcmFrameSynchronization   PCMSYNC   : 1; // [7]    rw : PCM frame synchronization
			I2SConfigurationMode      I2SCFG    : 2; // [9:8]  rw : I2S configuration mode
			I2SEnable                 I2SE      : 1; // [10]   rw : I2S Enable
			I2SModeSelection          I2SMOD    : 1; // [11]   rw : I2S mode selection
			uint32_t                  RESERVED2 : 20;
		} Fields;
		volatile uint32_t Value;
	};

	union I2SPrescalarRegister
	{
		volatile struct
		{
			uint8_t                  I2SDIV    : 8; // [7:0]  rw : I2S Linear prescaler
			OddFactorForThePrescaler ODD       : 1; // [8]    rw : Odd factor for the prescaler
			MasterClockOutputEnable  MCKOE     : 1; // [9]    rw : Master clock output enable
			uint32_t                 RESERVED1 : 22;
		} Fields;
		volatile uint32_t Value;
	};

	class ISpiRegisterMap
	{
	public:

		// CR1 Fields
		virtual ClockPhase get_CR1_CPHA() const = 0;
		virtual ClockPolarity get_CR1_CPOL() const = 0;
		virtual MasterSelection get_CR1_MSTR() const = 0;
		virtual BaudRateControl get_CR1_BR() const = 0;
		virtual SpiEnable get_CR1_SPE() const = 0;
		virtual LsbFirst get_CR1_LSBFIRST() const = 0;
		virtual InternalSlaveSelect get_CR1_SSI() const = 0;
		virtual SoftwareSlaveManagement get_CR1_SSM() const = 0;
		virtual ReceiveOnly get_CR1_RXONLY() const = 0;
		virtual DataFrameFormat get_CR1_DFF() const = 0;
		virtual CrcTransferNext get_CR1_CRCNEXT() const = 0;
		virtual HardwareCrcCalculationEnable get_CR1_CRCEN() const = 0;
		virtual OutputEnableInBidirectionalMode get_CR1_BIDIOE() const = 0;
		virtual BidirectionalDataModeEnable get_CR1_BIDIMODE() const = 0;
		virtual void set_CR1_CPHA(ClockPhase value) = 0;
		virtual void set_CR1_CPOL(ClockPolarity value) = 0;
		virtual void set_CR1_MSTR(MasterSelection value) = 0;
		virtual void set_CR1_BR(BaudRateControl value) = 0;
		virtual void set_CR1_SPE(SpiEnable value) = 0;
		virtual void set_CR1_LSBFIRST(LsbFirst value) = 0;
		virtual void set_CR1_SSI(InternalSlaveSelect value) = 0;
		virtual void set_CR1_SSM(SoftwareSlaveManagement value) = 0;
		virtual void set_CR1_RXONLY(ReceiveOnly value) = 0;
		virtual void set_CR1_DFF(DataFrameFormat value) = 0;
		virtual void set_CR1_CRCNEXT(CrcTransferNext value) = 0;
		virtual void set_CR1_CRCEN(HardwareCrcCalculationEnable value) = 0;
		virtual void set_CR1_BIDIOE(OutputEnableInBidirectionalMode value) = 0;
		virtual void set_CR1_BIDIMODE(BidirectionalDataModeEnable value) = 0;

		// CR2 Fields
		virtual RxBufferDmaEnable get_CR2_RXDMAEN() const = 0;
		virtual TxBufferDmaEnable get_CR2_TXDMAEN() const = 0;
		virtual SsOutputEnable get_CR2_SSOE() const = 0;
		virtual FrameFormat get_CR2_FRF() const = 0;
		virtual ErrorInterruptEnable get_CR2_ERRIE() const = 0;
		virtual RxBufferNotEmptyInterruptEnable get_CR2_RXNEIE() const = 0;
		virtual TxBufferEmptyInterruptEnable get_CR2_TXEIE() const = 0;
		virtual void set_CR2_RXDMAEN(RxBufferDmaEnable value) = 0;
		virtual void set_CR2_TXDMAEN(TxBufferDmaEnable value) = 0;
		virtual void set_CR2_SSOE(SsOutputEnable value) = 0;
		virtual void set_CR2_FRF(FrameFormat value) = 0;
		virtual void set_CR2_ERRIE(ErrorInterruptEnable value) = 0;
		virtual void set_CR2_RXNEIE(RxBufferNotEmptyInterruptEnable value) = 0;
		virtual void set_CR2_TXEIE(TxBufferEmptyInterruptEnable value) = 0;

		// SR Fields
		virtual ReceiveBufferNotEmpty get_SR_RXNE() const = 0;
		virtual TransmitBufferEmpty get_SR_TXE() const = 0;
		virtual ChannelSide get_SR_CHSIDE() const = 0;
		virtual UnderrunFlag get_SR_UDR() const = 0;
		virtual CrcErrorFlag get_SR_CRCERR() const = 0;
		virtual ModeFault get_SR_MODF() const = 0;
		virtual OverrunFlag get_SR_OVR() const = 0;
		virtual BusyFlag get_SR_BSY() const = 0;
		virtual FrameFormatError get_SR_FRE() const = 0;
		virtual void set_SR_CRCERR(CrcErrorFlag value) = 0;

		// DR Fields
		virtual uint16_t get_DR_DR() const = 0;
		virtual void set_DR_DR(uint16_t value) = 0;

		// CRCPR Fields
		virtual uint16_t get_CRCPR_CRCPOLY() const = 0;
		virtual void set_CRCPR_CRCPOLY(uint16_t value) = 0;

		// RXCRCR Fields
		virtual uint16_t get_RXCRCR_RXCRC() const = 0;

		// TXCRCR Fields
		virtual uint16_t get_TXCRCR_TXCRC() const = 0;

		// I2SCFGR Fields
		virtual ChannelLength get_I2SCFGR_CHLEN() const = 0;
		virtual DataLengthToBeTransferred get_I2SCFGR_DATLEN() const = 0;
		virtual SteadyStateClockPolarity get_I2SCFGR_CKPOL() const = 0;
		virtual I2SStandardSelection get_I2SCFGR_I2SSTD() const = 0;
		virtual PcmFrameSynchronization get_I2SCFGR_PCMSYNC() const = 0;
		virtual I2SConfigurationMode get_I2SCFGR_I2SCFG() const = 0;
		virtual I2SEnable get_I2SCFGR_I2SE() const = 0;
		virtual I2SModeSelection get_I2SCFGR_I2SMOD() const = 0;
		virtual void set_I2SCFGR_CHLEN(ChannelLength value) = 0;
		virtual void set_I2SCFGR_DATLEN(DataLengthToBeTransferred value) = 0;
		virtual void set_I2SCFGR_CKPOL(SteadyStateClockPolarity value) = 0;
		virtual void set_I2SCFGR_I2SSTD(I2SStandardSelection value) = 0;
		virtual void set_I2SCFGR_PCMSYNC(PcmFrameSynchronization value) = 0;
		virtual void set_I2SCFGR_I2SCFG(I2SConfigurationMode value) = 0;
		virtual void set_I2SCFGR_I2SE(I2SEnable value) = 0;
		virtual void set_I2SCFGR_I2SMOD(I2SModeSelection value) = 0;

		// I2SPR Fields
		virtual uint8_t get_I2SPR_I2SDIV() const = 0;
		virtual OddFactorForThePrescaler get_I2SPR_ODD() const = 0;
		virtual MasterClockOutputEnable get_I2SPR_MCKOE() const = 0;
		virtual void set_I2SPR_I2SDIV(uint8_t value) = 0;
		virtual void set_I2SPR_ODD(OddFactorForThePrescaler value) = 0;
		virtual void set_I2SPR_MCKOE(MasterClockOutputEnable value) = 0;
	};

	class SpiRegisterMap : public ISpiRegisterMap
	{
	public:

		// CR1 Fields
		ClockPhase get_CR1_CPHA() const override { return CR1.Fields.CPHA; }
		ClockPolarity get_CR1_CPOL() const override { return CR1.Fields.CPOL; }
		MasterSelection get_CR1_MSTR() const override { return CR1.Fields.MSTR; }
		BaudRateControl get_CR1_BR() const override { return CR1.Fields.BR; }
		SpiEnable get_CR1_SPE() const override { return CR1.Fields.SPE; }
		LsbFirst get_CR1_LSBFIRST() const override { return CR1.Fields.LSBFIRST; }
		InternalSlaveSelect get_CR1_SSI() const override { return CR1.Fields.SSI; }
		SoftwareSlaveManagement get_CR1_SSM() const override { return CR1.Fields.SSM; }
		ReceiveOnly get_CR1_RXONLY() const override { return CR1.Fields.RXONLY; }
		DataFrameFormat get_CR1_DFF() const override { return CR1.Fields.DFF; }
		CrcTransferNext get_CR1_CRCNEXT() const override { return CR1.Fields.CRCNEXT; }
		HardwareCrcCalculationEnable get_CR1_CRCEN() const override { return CR1.Fields.CRCEN; }
		OutputEnableInBidirectionalMode get_CR1_BIDIOE() const override { return CR1.Fields.BIDIOE; }
		BidirectionalDataModeEnable get_CR1_BIDIMODE() const override { return CR1.Fields.BIDIMODE; }
		void set_CR1_CPHA(ClockPhase value) override { CR1.Fields.CPHA = value; }
		void set_CR1_CPOL(ClockPolarity value) override { CR1.Fields.CPOL = value; }
		void set_CR1_MSTR(MasterSelection value) override { CR1.Fields.MSTR = value; }
		void set_CR1_BR(BaudRateControl value) override { CR1.Fields.BR = value; }
		void set_CR1_SPE(SpiEnable value) override { CR1.Fields.SPE = value; }
		void set_CR1_LSBFIRST(LsbFirst value) override { CR1.Fields.LSBFIRST = value; }
		void set_CR1_SSI(InternalSlaveSelect value) override { CR1.Fields.SSI = value; }
		void set_CR1_SSM(SoftwareSlaveManagement value) override { CR1.Fields.SSM = value; }
		void set_CR1_RXONLY(ReceiveOnly value) override { CR1.Fields.RXONLY = value; }
		void set_CR1_DFF(DataFrameFormat value) override { CR1.Fields.DFF = value; }
		void set_CR1_CRCNEXT(CrcTransferNext value) override { CR1.Fields.CRCNEXT = value; }
		void set_CR1_CRCEN(HardwareCrcCalculationEnable value) override { CR1.Fields.CRCEN = value; }
		void set_CR1_BIDIOE(OutputEnableInBidirectionalMode value) override { CR1.Fields.BIDIOE = value; }
		void set_CR1_BIDIMODE(BidirectionalDataModeEnable value) override { CR1.Fields.BIDIMODE = value; }

		// CR2 Fields
		RxBufferDmaEnable get_CR2_RXDMAEN() const override { return CR2.Fields.RXDMAEN; }
		TxBufferDmaEnable get_CR2_TXDMAEN() const override { return CR2.Fields.TXDMAEN; }
		SsOutputEnable get_CR2_SSOE() const override { return CR2.Fields.SSOE; }
		FrameFormat get_CR2_FRF() const override { return CR2.Fields.FRF; }
		ErrorInterruptEnable get_CR2_ERRIE() const override { return CR2.Fields.ERRIE; }
		RxBufferNotEmptyInterruptEnable get_CR2_RXNEIE() const override { return CR2.Fields.RXNEIE; }
		TxBufferEmptyInterruptEnable get_CR2_TXEIE() const override { return CR2.Fields.TXEIE; }
		void set_CR2_RXDMAEN(RxBufferDmaEnable value) override { CR2.Fields.RXDMAEN = value; }
		void set_CR2_TXDMAEN(TxBufferDmaEnable value) override { CR2.Fields.TXDMAEN = value; }
		void set_CR2_SSOE(SsOutputEnable value) override { CR2.Fields.SSOE = value; }
		void set_CR2_FRF(FrameFormat value) override { CR2.Fields.FRF = value; }
		void set_CR2_ERRIE(ErrorInterruptEnable value) override { CR2.Fields.ERRIE = value; }
		void set_CR2_RXNEIE(RxBufferNotEmptyInterruptEnable value) override { CR2.Fields.RXNEIE = value; }
		void set_CR2_TXEIE(TxBufferEmptyInterruptEnable value) override { CR2.Fields.TXEIE = value; }

		// SR Fields
		ReceiveBufferNotEmpty get_SR_RXNE() const override { return SR.Fields.RXNE; }
		TransmitBufferEmpty get_SR_TXE() const override { return SR.Fields.TXE; }
		ChannelSide get_SR_CHSIDE() const override { return SR.Fields.CHSIDE; }
		UnderrunFlag get_SR_UDR() const override { return SR.Fields.UDR; }
		CrcErrorFlag get_SR_CRCERR() const override { return SR.Fields.CRCERR; }
		ModeFault get_SR_MODF() const override { return SR.Fields.MODF; }
		OverrunFlag get_SR_OVR() const override { return SR.Fields.OVR; }
		BusyFlag get_SR_BSY() const override { return SR.Fields.BSY; }
		FrameFormatError get_SR_FRE() const override { return SR.Fields.FRE; }
		void set_SR_CRCERR(CrcErrorFlag value) override { SR.Fields.CRCERR = value; }

		// DR Fields
		uint16_t get_DR_DR() const override { return DR.Fields.DR; }
		void set_DR_DR(uint16_t value) override { DR.Fields.DR = value; }

		// CRCPR Fields
		uint16_t get_CRCPR_CRCPOLY() const override { return CRCPR.Fields.CRCPOLY; }
		void set_CRCPR_CRCPOLY(uint16_t value) override { CRCPR.Fields.CRCPOLY = value; }

		// RXCRCR Fields
		uint16_t get_RXCRCR_RXCRC() const override { return RXCRCR.Fields.RXCRC; }

		// TXCRCR Fields
		uint16_t get_TXCRCR_TXCRC() const override { return TXCRCR.Fields.TXCRC; }

		// I2SCFGR Fields
		ChannelLength get_I2SCFGR_CHLEN() const override { return I2SCFGR.Fields.CHLEN; }
		DataLengthToBeTransferred get_I2SCFGR_DATLEN() const override { return I2SCFGR.Fields.DATLEN; }
		SteadyStateClockPolarity get_I2SCFGR_CKPOL() const override { return I2SCFGR.Fields.CKPOL; }
		I2SStandardSelection get_I2SCFGR_I2SSTD() const override { return I2SCFGR.Fields.I2SSTD; }
		PcmFrameSynchronization get_I2SCFGR_PCMSYNC() const override { return I2SCFGR.Fields.PCMSYNC; }
		I2SConfigurationMode get_I2SCFGR_I2SCFG() const override { return I2SCFGR.Fields.I2SCFG; }
		I2SEnable get_I2SCFGR_I2SE() const override { return I2SCFGR.Fields.I2SE; }
		I2SModeSelection get_I2SCFGR_I2SMOD() const override { return I2SCFGR.Fields.I2SMOD; }
		void set_I2SCFGR_CHLEN(ChannelLength value) override { I2SCFGR.Fields.CHLEN = value; }
		void set_I2SCFGR_DATLEN(DataLengthToBeTransferred value) override { I2SCFGR.Fields.DATLEN = value; }
		void set_I2SCFGR_CKPOL(SteadyStateClockPolarity value) override { I2SCFGR.Fields.CKPOL = value; }
		void set_I2SCFGR_I2SSTD(I2SStandardSelection value) override { I2SCFGR.Fields.I2SSTD = value; }
		void set_I2SCFGR_PCMSYNC(PcmFrameSynchronization value) override { I2SCFGR.Fields.PCMSYNC = value; }
		void set_I2SCFGR_I2SCFG(I2SConfigurationMode value) override { I2SCFGR.Fields.I2SCFG = value; }
		void set_I2SCFGR_I2SE(I2SEnable value) override { I2SCFGR.Fields.I2SE = value; }
		void set_I2SCFGR_I2SMOD(I2SModeSelection value) override { I2SCFGR.Fields.I2SMOD = value; }

		// I2SPR Fields
		uint8_t get_I2SPR_I2SDIV() const override { return I2SPR.Fields.I2SDIV; }
		OddFactorForThePrescaler get_I2SPR_ODD() const override { return I2SPR.Fields.ODD; }
		MasterClockOutputEnable get_I2SPR_MCKOE() const override { return I2SPR.Fields.MCKOE; }
		void set_I2SPR_I2SDIV(uint8_t value) override { I2SPR.Fields.I2SDIV = value; }
		void set_I2SPR_ODD(OddFactorForThePrescaler value) override { I2SPR.Fields.ODD = value; }
		void set_I2SPR_MCKOE(MasterClockOutputEnable value) override { I2SPR.Fields.MCKOE = value; }

	private:

		ControlRegister1 CR1;
		ControlRegister2 CR2;
		StatusRegister SR;
		DataRegister DR;
		CrcPolynomialRegister CRCPR;
		RxCrcRegister RXCRCR;
		TxCrcRegister TXCRCR;
		I2SConfigurationRegister I2SCFGR;
		I2SPrescalarRegister I2SPR;
	};
}
#endif // SPI_REGISTER_MAP_HPP_