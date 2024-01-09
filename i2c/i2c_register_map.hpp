#ifndef I2C_REGISTER_MAP_HPP_
#define I2C_REGISTER_MAP_HPP_

#include <cstdint>
#include "i2c_types.hpp"

using namespace std;

namespace stm32::i2c
{
	union CR1_t
	{
		volatile struct
		{
			PeripheralEnable  PE          : 1; // [0]     rw : Peripheral enable
			Reserved          Reserved1   : 9; // [1:9]      : RESERVED FIELD.
			AcknowledgeEnable ACK         : 1; // [10]    rw : Acknowledge enable
			Reserved          Reserved2   : 21; // [11:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CR2_t
	{
		volatile struct
		{
			uint32_t FREQ        : 6; // [0:5]   rw : Peripheral clock frequency
			Reserved Reserved1   : 26; // [6:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union OAR1_t
	{
		volatile struct
		{
			uint32_t       ADD         : 10; // [0:9]   rw : Interface address
			Reserved       Reserved1   : 4; // [10:13]    : RESERVED FIELD.
			uint32_t       RESERVEDBIT14 : 1; // [14]    w  : Reserved bit. Should always be kept at 1 by software.
			AddressingMode ADDMODE     : 1; // [15]    rw : Addressing mode (slave mode)
			Reserved       Reserved2   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union OAR2_t
	{
		volatile struct
		{
			DualAddressingModeEnable ENDUAL      : 1; // [0]     rw : Dual addressing mode enable
			uint32_t                 ADD2        : 7; // [1:7]   rw : Interface address
			Reserved                 Reserved1   : 24; // [8:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union DR_t
	{
		volatile struct
		{
			uint32_t DR          : 8; // [0:7]   rw : 8-bit data register
			Reserved Reserved1   : 24; // [8:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union SR1_t
	{
		volatile struct
		{
			StartBit           SB          : 1; // [0]     r  : Start bit (Master mode)
			AddressSentMatched ADDR        : 1; // [1]     r  : Address sent (master mode)/matched (slave mode)
			Reserved           Reserved1   : 30; // [2:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union SR2_t
	{
		volatile struct
		{
			MasterSlave         MSL         : 1; // [0]     r  : Master/slave
			BusBusy             BUSY        : 1; // [1]     r  : Bus busy
			TransmitterReceiver TRA         : 1; // [2]     r  : Transmitter/receiver
			Reserved            Reserved1   : 29; // [3:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CCR_t
	{
		volatile struct
		{
			uint32_t            CCR         : 12; // [0:11]  rw : Clock control register in Fm/Sm mode (Master mode) 
			Reserved            Reserved1   : 2; // [12:13]    : RESERVED FIELD.
			FmModeDutyCycle     DUTY        : 1; // [14]    rw : Fm mode duty cycle
			MasterModeSelection FS          : 1; // [15]    rw : I2C master mode selection
			Reserved            Reserved2   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	struct I2CRegisters
	{
		CR1_t CR1; // Address Offset 0x0
		CR2_t CR2; // Address Offset 0x4
		OAR1_t OAR1; // Address Offset 0x8
		OAR2_t OAR2; // Address Offset 0xC
		DR_t DR; // Address Offset 0x10
		SR1_t SR1; // Address Offset 0x14
		SR2_t SR2; // Address Offset 0x18
		CCR_t CCR; // Address Offset 0x1C
	};

	class II2CRegisterMap
	{
	public:

		// CR1 Fields
		virtual PeripheralEnable get_CR1_PE() const = 0;
		virtual AcknowledgeEnable get_CR1_ACK() const = 0;
		virtual void set_CR1_PE(PeripheralEnable value) = 0;
		virtual void set_CR1_ACK(AcknowledgeEnable value) = 0;

		// CR2 Fields
		virtual uint32_t get_CR2_FREQ() const = 0;
		virtual void set_CR2_FREQ(uint32_t value) = 0;

		// OAR1 Fields
		virtual uint32_t get_OAR1_ADD() const = 0;
		virtual AddressingMode get_OAR1_ADDMODE() const = 0;
		virtual void set_OAR1_ADD(uint32_t value) = 0;
		virtual void set_OAR1_RESERVEDBIT14(uint32_t value) = 0;
		virtual void set_OAR1_ADDMODE(AddressingMode value) = 0;

		// OAR2 Fields
		virtual DualAddressingModeEnable get_OAR2_ENDUAL() const = 0;
		virtual uint32_t get_OAR2_ADD2() const = 0;
		virtual void set_OAR2_ENDUAL(DualAddressingModeEnable value) = 0;
		virtual void set_OAR2_ADD2(uint32_t value) = 0;

		// DR Fields
		virtual uint32_t get_DR_DR() const = 0;
		virtual void set_DR_DR(uint32_t value) = 0;

		// SR1 Fields
		virtual StartBit get_SR1_SB() const = 0;
		virtual AddressSentMatched get_SR1_ADDR() const = 0;

		// SR2 Fields
		virtual MasterSlave get_SR2_MSL() const = 0;
		virtual BusBusy get_SR2_BUSY() const = 0;
		virtual TransmitterReceiver get_SR2_TRA() const = 0;

		// CCR Fields
		virtual uint32_t get_CCR_CCR() const = 0;
		virtual FmModeDutyCycle get_CCR_DUTY() const = 0;
		virtual MasterModeSelection get_CCR_FS() const = 0;
		virtual void set_CCR_CCR(uint32_t value) = 0;
		virtual void set_CCR_DUTY(FmModeDutyCycle value) = 0;
		virtual void set_CCR_FS(MasterModeSelection value) = 0;
	};

	class I2CRegisterMap : public II2CRegisterMap
	{
	public:

		I2CRegisterMap(I2CRegisters & registers)
			: registers(registers) { }

		I2CRegisterMap(uint32_t addr)
			: registers(*reinterpret_cast<I2CRegisters*>(addr)) { }

		// CR1 Fields
		PeripheralEnable get_CR1_PE() const { return registers.CR1.Fields.PE; }
		AcknowledgeEnable get_CR1_ACK() const { return registers.CR1.Fields.ACK; }
		void set_CR1_PE(PeripheralEnable value) { registers.CR1.Fields.PE = value; }
		void set_CR1_ACK(AcknowledgeEnable value) { registers.CR1.Fields.ACK = value; }

		// CR2 Fields
		uint32_t get_CR2_FREQ() const { return registers.CR2.Fields.FREQ; }
		void set_CR2_FREQ(uint32_t value) { registers.CR2.Fields.FREQ = value; }

		// OAR1 Fields
		uint32_t get_OAR1_ADD() const { return registers.OAR1.Fields.ADD; }
		AddressingMode get_OAR1_ADDMODE() const { return registers.OAR1.Fields.ADDMODE; }
		void set_OAR1_ADD(uint32_t value) { registers.OAR1.Fields.ADD = value; }
		void set_OAR1_RESERVEDBIT14(uint32_t value) { registers.OAR1.Fields.RESERVEDBIT14 = value; }
		void set_OAR1_ADDMODE(AddressingMode value) { registers.OAR1.Fields.ADDMODE = value; }

		// OAR2 Fields
		DualAddressingModeEnable get_OAR2_ENDUAL() const { return registers.OAR2.Fields.ENDUAL; }
		uint32_t get_OAR2_ADD2() const { return registers.OAR2.Fields.ADD2; }
		void set_OAR2_ENDUAL(DualAddressingModeEnable value) { registers.OAR2.Fields.ENDUAL = value; }
		void set_OAR2_ADD2(uint32_t value) { registers.OAR2.Fields.ADD2 = value; }

		// DR Fields
		uint32_t get_DR_DR() const { return registers.DR.Fields.DR; }
		void set_DR_DR(uint32_t value) { registers.DR.Fields.DR = value; }

		// SR1 Fields
		StartBit get_SR1_SB() const { return registers.SR1.Fields.SB; }
		AddressSentMatched get_SR1_ADDR() const { return registers.SR1.Fields.ADDR; }

		// SR2 Fields
		MasterSlave get_SR2_MSL() const { return registers.SR2.Fields.MSL; }
		BusBusy get_SR2_BUSY() const { return registers.SR2.Fields.BUSY; }
		TransmitterReceiver get_SR2_TRA() const { return registers.SR2.Fields.TRA; }

		// CCR Fields
		uint32_t get_CCR_CCR() const { return registers.CCR.Fields.CCR; }
		FmModeDutyCycle get_CCR_DUTY() const { return registers.CCR.Fields.DUTY; }
		MasterModeSelection get_CCR_FS() const { return registers.CCR.Fields.FS; }
		void set_CCR_CCR(uint32_t value) { registers.CCR.Fields.CCR = value; }
		void set_CCR_DUTY(FmModeDutyCycle value) { registers.CCR.Fields.DUTY = value; }
		void set_CCR_FS(MasterModeSelection value) { registers.CCR.Fields.FS = value; }

	private:

		I2CRegisters & registers;
	};
}
#endif // I2C_REGISTER_MAP_HPP_