#ifndef USART_REGISTER_MAP_HPP_
#define USART_REGISTER_MAP_HPP_

#include <cstdint>
#include "usart_types.hpp"

using namespace std;

namespace stm32::usart
{
	union SR_t
	{
		volatile struct
		{
			ParityError               PE          : 1; // [0]     r  : Parity error
			FramingError              FE          : 1; // [1]     r  : Framing error
			NoiceDetectedFlag         NF          : 1; // [2]     r  : Noise detected flag
			OverrunError              ORE         : 1; // [3]     r  : Overrun error
			IdleLineDetected          IDLE        : 1; // [4]     r  : IDLE line detected
			ReadDataRegisterNotEmpty  RXNE        : 1; // [5]     rw : Read data register not empty
			TransmissionComplete      TC          : 1; // [6]     rw : Transmission complete
			TransmitDataRegisterEmpty TXE         : 1; // [7]     r  : Transmit data register empty
			LinBreakDetectionFlag     LBD         : 1; // [8]     rw : LIN break detection flag
			CtsFlag                   CTS         : 1; // [9]     rw : CTS flag
			Reserved                  Reserved1   : 22; // [10:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union DR_t
	{
		volatile struct
		{
			uint32_t DR          : 9; // [0:8]   rw : Data value
			Reserved Reserved1   : 23; // [9:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union BRR_t
	{
		volatile struct
		{
			uint32_t DIV_Fraction : 4; // [0:3]   rw : Fraction of USARTDIV
			uint32_t DIV_Mantissa : 12; // [4:15]  rw : Mantissa of USARTDIV
			Reserved Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CR1_t
	{
		volatile struct
		{
			SendBreak           SBK         : 1; // [0]     rw : Send break
			ReceiverWakeup      RWU         : 1; // [1]     rw : Receiver wakeup
			ReceiverEnable      RE          : 1; // [2]     rw : Receiver enable
			TransmitterEnable   TE          : 1; // [3]     rw : Transmitter enable
			IdleInterruptEnable IDLEIE      : 1; // [4]     rw : IDLE interrupt enable
			RxneInterruptEnable RXNEIE      : 1; // [5]     rw : RXNE interrupt enable
			TcInterruptEnable   TCIE        : 1; // [6]     rw : Transmission complete interrupt enable
			TxeInterruptEnable  TXEIE       : 1; // [7]     rw : TXE interrupt enable
			PeInterruptEnable   PEIE        : 1; // [8]     rw : PE interrupt enable
			ParitySelection     PS          : 1; // [9]     rw : Parity selection
			ParityControlEnable PCE         : 1; // [10]    rw : Parity control enable
			WakeupMethod        WAKE        : 1; // [11]    rw : Wakeup method
			WordLength          M           : 1; // [12]    rw : Word length
			UsartEnable         UE          : 1; // [13]    rw : USART enable
			Reserved            Reserved1   : 1; // [14]       : RESERVED FIELD.
			OversamplingMode    OVER8       : 1; // [15]    rw : Oversampling mode
			Reserved            Reserved2   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CR2_t
	{
		volatile struct
		{
			uint32_t                         ADD         : 4; // [0:3]   rw : Address of USART node
			Reserved                         Reserved1   : 1; // [4]        : RESERVED FIELD.
			LinBreakDetectionLength          LBDL        : 1; // [5]     rw : LIN break detection length
			LinBreakDetectionInterruptEnable LBDIE       : 1; // [6]     rw : LIN break detection interrupt enable
			Reserved                         Reserved2   : 1; // [7]        : RESERVED FIELD.
			LastBitClockPulse                LBCL        : 1; // [8]     rw : Last bit clock pulse
			ClockPhase                       CPHA        : 1; // [9]     rw : Clock phase
			ClockPolarity                    CPOL        : 1; // [10]    rw : Clock polarity
			ClockEnable                      CLKEN       : 1; // [11]    rw : Clock enable
			StopBits                         STOP        : 2; // [12:13] rw : Stop bits
			LinModeEnable                    LINEN       : 1; // [14]    rw : LIN mode enable
			Reserved                         Reserved3   : 17; // [15:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CR3_t
	{
		volatile struct
		{
			ErrorInterruptEnable     EIE         : 1; // [0]     rw : Error interrupt enable
			IrdaModeEnable           IREN        : 1; // [1]     rw : IrDA mode enable
			IrdaLowPower             IRLP        : 1; // [2]     rw : IrDA low-power
			HalfDuplexSelection      HDSEL       : 1; // [3]     rw : Half-duplex selection
			SmartcardNackEnable      NACK        : 1; // [4]     rw : Smartcard NACK enable
			SmartcardModeEnable      SCEN        : 1; // [5]     rw : Smartcard mode enable
			DmaEnableReciever        DMAR        : 1; // [6]     rw : DMA enable reciever
			DmaEnableTransmitter     DMAT        : 1; // [7]     rw : DMA enable transmitter
			RtsEnable                RTSE        : 1; // [8]     rw : RTS enable
			CtsEnable                CTSE        : 1; // [9]     rw : CTS enable
			CtsInterruptEnable       CTSIE       : 1; // [10]    rw : CTS interrupt enable
			OneSampleBitMethodEnable ONEBIT      : 1; // [11]    rw : One sample bit method enable
			Reserved                 Reserved1   : 20; // [12:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union GTPR_t
	{
		volatile struct
		{
			uint32_t PSC         : 8; // [0:7]   rw : Prescalar value
			uint32_t GT          : 8; // [8:15]  rw : Guard time value
			Reserved Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	struct UsartRegisters
	{
		SR_t SR; // Address Offset 0x0
		DR_t DR; // Address Offset 0x4
		BRR_t BRR; // Address Offset 0x8
		CR1_t CR1; // Address Offset 0xC
		CR2_t CR2; // Address Offset 0x10
		CR3_t CR3; // Address Offset 0x14
		GTPR_t GTPR; // Address Offset 0x18
	};

	class IUsartRegisterMap
	{
	public:

		// SR Fields
		virtual ParityError get_SR_PE() const = 0;
		virtual FramingError get_SR_FE() const = 0;
		virtual NoiceDetectedFlag get_SR_NF() const = 0;
		virtual OverrunError get_SR_ORE() const = 0;
		virtual IdleLineDetected get_SR_IDLE() const = 0;
		virtual ReadDataRegisterNotEmpty get_SR_RXNE() const = 0;
		virtual TransmissionComplete get_SR_TC() const = 0;
		virtual TransmitDataRegisterEmpty get_SR_TXE() const = 0;
		virtual LinBreakDetectionFlag get_SR_LBD() const = 0;
		virtual CtsFlag get_SR_CTS() const = 0;
		virtual void set_SR_RXNE(ReadDataRegisterNotEmpty value) = 0;
		virtual void set_SR_TC(TransmissionComplete value) = 0;
		virtual void set_SR_LBD(LinBreakDetectionFlag value) = 0;
		virtual void set_SR_CTS(CtsFlag value) = 0;

		// DR Fields
		virtual uint32_t get_DR_DR() const = 0;
		virtual void set_DR_DR(uint32_t value) = 0;

		// BRR Fields
		virtual uint32_t get_BRR_DIV_Fraction() const = 0;
		virtual uint32_t get_BRR_DIV_Mantissa() const = 0;
		virtual void set_BRR_DIV_Fraction(uint32_t value) = 0;
		virtual void set_BRR_DIV_Mantissa(uint32_t value) = 0;

		// CR1 Fields
		virtual SendBreak get_CR1_SBK() const = 0;
		virtual ReceiverWakeup get_CR1_RWU() const = 0;
		virtual ReceiverEnable get_CR1_RE() const = 0;
		virtual TransmitterEnable get_CR1_TE() const = 0;
		virtual IdleInterruptEnable get_CR1_IDLEIE() const = 0;
		virtual RxneInterruptEnable get_CR1_RXNEIE() const = 0;
		virtual TcInterruptEnable get_CR1_TCIE() const = 0;
		virtual TxeInterruptEnable get_CR1_TXEIE() const = 0;
		virtual PeInterruptEnable get_CR1_PEIE() const = 0;
		virtual ParitySelection get_CR1_PS() const = 0;
		virtual ParityControlEnable get_CR1_PCE() const = 0;
		virtual WakeupMethod get_CR1_WAKE() const = 0;
		virtual WordLength get_CR1_M() const = 0;
		virtual UsartEnable get_CR1_UE() const = 0;
		virtual OversamplingMode get_CR1_OVER8() const = 0;
		virtual void set_CR1_SBK(SendBreak value) = 0;
		virtual void set_CR1_RWU(ReceiverWakeup value) = 0;
		virtual void set_CR1_RE(ReceiverEnable value) = 0;
		virtual void set_CR1_TE(TransmitterEnable value) = 0;
		virtual void set_CR1_IDLEIE(IdleInterruptEnable value) = 0;
		virtual void set_CR1_RXNEIE(RxneInterruptEnable value) = 0;
		virtual void set_CR1_TCIE(TcInterruptEnable value) = 0;
		virtual void set_CR1_TXEIE(TxeInterruptEnable value) = 0;
		virtual void set_CR1_PEIE(PeInterruptEnable value) = 0;
		virtual void set_CR1_PS(ParitySelection value) = 0;
		virtual void set_CR1_PCE(ParityControlEnable value) = 0;
		virtual void set_CR1_WAKE(WakeupMethod value) = 0;
		virtual void set_CR1_M(WordLength value) = 0;
		virtual void set_CR1_UE(UsartEnable value) = 0;
		virtual void set_CR1_OVER8(OversamplingMode value) = 0;

		// CR2 Fields
		virtual uint32_t get_CR2_ADD() const = 0;
		virtual LinBreakDetectionLength get_CR2_LBDL() const = 0;
		virtual LinBreakDetectionInterruptEnable get_CR2_LBDIE() const = 0;
		virtual LastBitClockPulse get_CR2_LBCL() const = 0;
		virtual ClockPhase get_CR2_CPHA() const = 0;
		virtual ClockPolarity get_CR2_CPOL() const = 0;
		virtual ClockEnable get_CR2_CLKEN() const = 0;
		virtual StopBits get_CR2_STOP() const = 0;
		virtual LinModeEnable get_CR2_LINEN() const = 0;
		virtual void set_CR2_ADD(uint32_t value) = 0;
		virtual void set_CR2_LBDL(LinBreakDetectionLength value) = 0;
		virtual void set_CR2_LBDIE(LinBreakDetectionInterruptEnable value) = 0;
		virtual void set_CR2_LBCL(LastBitClockPulse value) = 0;
		virtual void set_CR2_CPHA(ClockPhase value) = 0;
		virtual void set_CR2_CPOL(ClockPolarity value) = 0;
		virtual void set_CR2_CLKEN(ClockEnable value) = 0;
		virtual void set_CR2_STOP(StopBits value) = 0;
		virtual void set_CR2_LINEN(LinModeEnable value) = 0;

		// CR3 Fields
		virtual ErrorInterruptEnable get_CR3_EIE() const = 0;
		virtual IrdaModeEnable get_CR3_IREN() const = 0;
		virtual IrdaLowPower get_CR3_IRLP() const = 0;
		virtual HalfDuplexSelection get_CR3_HDSEL() const = 0;
		virtual SmartcardNackEnable get_CR3_NACK() const = 0;
		virtual SmartcardModeEnable get_CR3_SCEN() const = 0;
		virtual DmaEnableReciever get_CR3_DMAR() const = 0;
		virtual DmaEnableTransmitter get_CR3_DMAT() const = 0;
		virtual RtsEnable get_CR3_RTSE() const = 0;
		virtual CtsEnable get_CR3_CTSE() const = 0;
		virtual CtsInterruptEnable get_CR3_CTSIE() const = 0;
		virtual OneSampleBitMethodEnable get_CR3_ONEBIT() const = 0;
		virtual void set_CR3_EIE(ErrorInterruptEnable value) = 0;
		virtual void set_CR3_IREN(IrdaModeEnable value) = 0;
		virtual void set_CR3_IRLP(IrdaLowPower value) = 0;
		virtual void set_CR3_HDSEL(HalfDuplexSelection value) = 0;
		virtual void set_CR3_NACK(SmartcardNackEnable value) = 0;
		virtual void set_CR3_SCEN(SmartcardModeEnable value) = 0;
		virtual void set_CR3_DMAR(DmaEnableReciever value) = 0;
		virtual void set_CR3_DMAT(DmaEnableTransmitter value) = 0;
		virtual void set_CR3_RTSE(RtsEnable value) = 0;
		virtual void set_CR3_CTSE(CtsEnable value) = 0;
		virtual void set_CR3_CTSIE(CtsInterruptEnable value) = 0;
		virtual void set_CR3_ONEBIT(OneSampleBitMethodEnable value) = 0;

		// GTPR Fields
		virtual uint32_t get_GTPR_PSC() const = 0;
		virtual uint32_t get_GTPR_GT() const = 0;
		virtual void set_GTPR_PSC(uint32_t value) = 0;
		virtual void set_GTPR_GT(uint32_t value) = 0;
	};

	class UsartRegisterMap : public IUsartRegisterMap
	{
	public:

		UsartRegisterMap(UsartRegisters & registers)
			: registers(registers) { }

		UsartRegisterMap(uint32_t addr)
			: registers(*reinterpret_cast<UsartRegisters*>(addr)) { }

		// SR Fields
		ParityError get_SR_PE() const { return registers.SR.Fields.PE; }
		FramingError get_SR_FE() const { return registers.SR.Fields.FE; }
		NoiceDetectedFlag get_SR_NF() const { return registers.SR.Fields.NF; }
		OverrunError get_SR_ORE() const { return registers.SR.Fields.ORE; }
		IdleLineDetected get_SR_IDLE() const { return registers.SR.Fields.IDLE; }
		ReadDataRegisterNotEmpty get_SR_RXNE() const { return registers.SR.Fields.RXNE; }
		TransmissionComplete get_SR_TC() const { return registers.SR.Fields.TC; }
		TransmitDataRegisterEmpty get_SR_TXE() const { return registers.SR.Fields.TXE; }
		LinBreakDetectionFlag get_SR_LBD() const { return registers.SR.Fields.LBD; }
		CtsFlag get_SR_CTS() const { return registers.SR.Fields.CTS; }
		void set_SR_RXNE(ReadDataRegisterNotEmpty value) { registers.SR.Fields.RXNE = value; }
		void set_SR_TC(TransmissionComplete value) { registers.SR.Fields.TC = value; }
		void set_SR_LBD(LinBreakDetectionFlag value) { registers.SR.Fields.LBD = value; }
		void set_SR_CTS(CtsFlag value) { registers.SR.Fields.CTS = value; }

		// DR Fields
		uint32_t get_DR_DR() const { return registers.DR.Fields.DR; }
		void set_DR_DR(uint32_t value) { registers.DR.Fields.DR = value; }

		// BRR Fields
		uint32_t get_BRR_DIV_Fraction() const { return registers.BRR.Fields.DIV_Fraction; }
		uint32_t get_BRR_DIV_Mantissa() const { return registers.BRR.Fields.DIV_Mantissa; }
		void set_BRR_DIV_Fraction(uint32_t value) { registers.BRR.Fields.DIV_Fraction = value; }
		void set_BRR_DIV_Mantissa(uint32_t value) { registers.BRR.Fields.DIV_Mantissa = value; }

		// CR1 Fields
		SendBreak get_CR1_SBK() const { return registers.CR1.Fields.SBK; }
		ReceiverWakeup get_CR1_RWU() const { return registers.CR1.Fields.RWU; }
		ReceiverEnable get_CR1_RE() const { return registers.CR1.Fields.RE; }
		TransmitterEnable get_CR1_TE() const { return registers.CR1.Fields.TE; }
		IdleInterruptEnable get_CR1_IDLEIE() const { return registers.CR1.Fields.IDLEIE; }
		RxneInterruptEnable get_CR1_RXNEIE() const { return registers.CR1.Fields.RXNEIE; }
		TcInterruptEnable get_CR1_TCIE() const { return registers.CR1.Fields.TCIE; }
		TxeInterruptEnable get_CR1_TXEIE() const { return registers.CR1.Fields.TXEIE; }
		PeInterruptEnable get_CR1_PEIE() const { return registers.CR1.Fields.PEIE; }
		ParitySelection get_CR1_PS() const { return registers.CR1.Fields.PS; }
		ParityControlEnable get_CR1_PCE() const { return registers.CR1.Fields.PCE; }
		WakeupMethod get_CR1_WAKE() const { return registers.CR1.Fields.WAKE; }
		WordLength get_CR1_M() const { return registers.CR1.Fields.M; }
		UsartEnable get_CR1_UE() const { return registers.CR1.Fields.UE; }
		OversamplingMode get_CR1_OVER8() const { return registers.CR1.Fields.OVER8; }
		void set_CR1_SBK(SendBreak value) { registers.CR1.Fields.SBK = value; }
		void set_CR1_RWU(ReceiverWakeup value) { registers.CR1.Fields.RWU = value; }
		void set_CR1_RE(ReceiverEnable value) { registers.CR1.Fields.RE = value; }
		void set_CR1_TE(TransmitterEnable value) { registers.CR1.Fields.TE = value; }
		void set_CR1_IDLEIE(IdleInterruptEnable value) { registers.CR1.Fields.IDLEIE = value; }
		void set_CR1_RXNEIE(RxneInterruptEnable value) { registers.CR1.Fields.RXNEIE = value; }
		void set_CR1_TCIE(TcInterruptEnable value) { registers.CR1.Fields.TCIE = value; }
		void set_CR1_TXEIE(TxeInterruptEnable value) { registers.CR1.Fields.TXEIE = value; }
		void set_CR1_PEIE(PeInterruptEnable value) { registers.CR1.Fields.PEIE = value; }
		void set_CR1_PS(ParitySelection value) { registers.CR1.Fields.PS = value; }
		void set_CR1_PCE(ParityControlEnable value) { registers.CR1.Fields.PCE = value; }
		void set_CR1_WAKE(WakeupMethod value) { registers.CR1.Fields.WAKE = value; }
		void set_CR1_M(WordLength value) { registers.CR1.Fields.M = value; }
		void set_CR1_UE(UsartEnable value) { registers.CR1.Fields.UE = value; }
		void set_CR1_OVER8(OversamplingMode value) { registers.CR1.Fields.OVER8 = value; }

		// CR2 Fields
		uint32_t get_CR2_ADD() const { return registers.CR2.Fields.ADD; }
		LinBreakDetectionLength get_CR2_LBDL() const { return registers.CR2.Fields.LBDL; }
		LinBreakDetectionInterruptEnable get_CR2_LBDIE() const { return registers.CR2.Fields.LBDIE; }
		LastBitClockPulse get_CR2_LBCL() const { return registers.CR2.Fields.LBCL; }
		ClockPhase get_CR2_CPHA() const { return registers.CR2.Fields.CPHA; }
		ClockPolarity get_CR2_CPOL() const { return registers.CR2.Fields.CPOL; }
		ClockEnable get_CR2_CLKEN() const { return registers.CR2.Fields.CLKEN; }
		StopBits get_CR2_STOP() const { return registers.CR2.Fields.STOP; }
		LinModeEnable get_CR2_LINEN() const { return registers.CR2.Fields.LINEN; }
		void set_CR2_ADD(uint32_t value) { registers.CR2.Fields.ADD = value; }
		void set_CR2_LBDL(LinBreakDetectionLength value) { registers.CR2.Fields.LBDL = value; }
		void set_CR2_LBDIE(LinBreakDetectionInterruptEnable value) { registers.CR2.Fields.LBDIE = value; }
		void set_CR2_LBCL(LastBitClockPulse value) { registers.CR2.Fields.LBCL = value; }
		void set_CR2_CPHA(ClockPhase value) { registers.CR2.Fields.CPHA = value; }
		void set_CR2_CPOL(ClockPolarity value) { registers.CR2.Fields.CPOL = value; }
		void set_CR2_CLKEN(ClockEnable value) { registers.CR2.Fields.CLKEN = value; }
		void set_CR2_STOP(StopBits value) { registers.CR2.Fields.STOP = value; }
		void set_CR2_LINEN(LinModeEnable value) { registers.CR2.Fields.LINEN = value; }

		// CR3 Fields
		ErrorInterruptEnable get_CR3_EIE() const { return registers.CR3.Fields.EIE; }
		IrdaModeEnable get_CR3_IREN() const { return registers.CR3.Fields.IREN; }
		IrdaLowPower get_CR3_IRLP() const { return registers.CR3.Fields.IRLP; }
		HalfDuplexSelection get_CR3_HDSEL() const { return registers.CR3.Fields.HDSEL; }
		SmartcardNackEnable get_CR3_NACK() const { return registers.CR3.Fields.NACK; }
		SmartcardModeEnable get_CR3_SCEN() const { return registers.CR3.Fields.SCEN; }
		DmaEnableReciever get_CR3_DMAR() const { return registers.CR3.Fields.DMAR; }
		DmaEnableTransmitter get_CR3_DMAT() const { return registers.CR3.Fields.DMAT; }
		RtsEnable get_CR3_RTSE() const { return registers.CR3.Fields.RTSE; }
		CtsEnable get_CR3_CTSE() const { return registers.CR3.Fields.CTSE; }
		CtsInterruptEnable get_CR3_CTSIE() const { return registers.CR3.Fields.CTSIE; }
		OneSampleBitMethodEnable get_CR3_ONEBIT() const { return registers.CR3.Fields.ONEBIT; }
		void set_CR3_EIE(ErrorInterruptEnable value) { registers.CR3.Fields.EIE = value; }
		void set_CR3_IREN(IrdaModeEnable value) { registers.CR3.Fields.IREN = value; }
		void set_CR3_IRLP(IrdaLowPower value) { registers.CR3.Fields.IRLP = value; }
		void set_CR3_HDSEL(HalfDuplexSelection value) { registers.CR3.Fields.HDSEL = value; }
		void set_CR3_NACK(SmartcardNackEnable value) { registers.CR3.Fields.NACK = value; }
		void set_CR3_SCEN(SmartcardModeEnable value) { registers.CR3.Fields.SCEN = value; }
		void set_CR3_DMAR(DmaEnableReciever value) { registers.CR3.Fields.DMAR = value; }
		void set_CR3_DMAT(DmaEnableTransmitter value) { registers.CR3.Fields.DMAT = value; }
		void set_CR3_RTSE(RtsEnable value) { registers.CR3.Fields.RTSE = value; }
		void set_CR3_CTSE(CtsEnable value) { registers.CR3.Fields.CTSE = value; }
		void set_CR3_CTSIE(CtsInterruptEnable value) { registers.CR3.Fields.CTSIE = value; }
		void set_CR3_ONEBIT(OneSampleBitMethodEnable value) { registers.CR3.Fields.ONEBIT = value; }

		// GTPR Fields
		uint32_t get_GTPR_PSC() const { return registers.GTPR.Fields.PSC; }
		uint32_t get_GTPR_GT() const { return registers.GTPR.Fields.GT; }
		void set_GTPR_PSC(uint32_t value) { registers.GTPR.Fields.PSC = value; }
		void set_GTPR_GT(uint32_t value) { registers.GTPR.Fields.GT = value; }

	private:

		UsartRegisters & registers;
	};
}
#endif // USART_REGISTER_MAP_HPP_