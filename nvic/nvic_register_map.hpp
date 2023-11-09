#ifndef NVIC_REGISTER_MAP_HPP_
#define NVIC_REGISTER_MAP_HPP_

#include <cstdint>
#include "nvic_types.hpp"

using namespace std;

namespace stm32::nvic
{
	union ISER_t
	{
		volatile struct
		{
			uint32_t SETENA      : 32; // [0:31]  rw : Interrupt set-enable bits
		} Fields;
		volatile uint32_t Value;
	};

	union ICER_t
	{
		volatile struct
		{
			uint32_t CLRENA      : 32; // [0:31]  rw : Interrupt clear-enable bits
		} Fields;
		volatile uint32_t Value;
	};

	union ISPR_t
	{
		volatile struct
		{
			uint32_t SETPEND     : 32; // [0:31]  rw : Interrupt set-pending bits
		} Fields;
		volatile uint32_t Value;
	};

	union ICPR_t
	{
		volatile struct
		{
			uint32_t CLRPEND     : 32; // [0:31]  rw : Interrupt clear-pending bits
		} Fields;
		volatile uint32_t Value;
	};

	union IABR_t
	{
		volatile struct
		{
			uint32_t ACTIVE      : 32; // [0:31]  rw : Interrupt active flags
		} Fields;
		volatile uint32_t Value;
	};

	union IPR_t
	{
		volatile struct
		{
			uint32_t PRI         : 32; // [0:31]  rw : Interrupt priority
		} Fields;
		volatile uint32_t Value;
	};

	union STIR_t
	{
		volatile struct
		{
			uint32_t INTID       : 8; // [0:7]   rw : Interrupt ID of the interrupt to trigger
			Reserved Reserved1   : 24; // [8:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	struct NvicRegisters
	{
		ISER_t ISER[8]; // Address Offset 0x0
		Reserved Reserved1[24];
		ICER_t ICER[8]; // Address Offset 0x80
		Reserved Reserved2[24];
		ISPR_t ISPR[8]; // Address Offset 0x100
		Reserved Reserved3[24];
		ICPR_t ICPR[8]; // Address Offset 0x180
		Reserved Reserved4[24];
		IABR_t IABR[8]; // Address Offset 0x200
		Reserved Reserved5[56];
		IPR_t IPR[60]; // Address Offset 0x300
		Reserved Reserved6[644];
		STIR_t STIR; // Address Offset 0xE00
	};

	class INvicRegisterMap
	{
	public:

		// ISER Fields
		virtual uint32_t get_ISER_SETENA(uint16_t index) const = 0;
		virtual void set_ISER_SETENA(uint16_t index, uint32_t value) = 0;

		// ICER Fields
		virtual uint32_t get_ICER_CLRENA(uint16_t index) const = 0;
		virtual void set_ICER_CLRENA(uint16_t index, uint32_t value) = 0;

		// ISPR Fields
		virtual uint32_t get_ISPR_SETPEND(uint16_t index) const = 0;
		virtual void set_ISPR_SETPEND(uint16_t index, uint32_t value) = 0;

		// ICPR Fields
		virtual uint32_t get_ICPR_CLRPEND(uint16_t index) const = 0;
		virtual void set_ICPR_CLRPEND(uint16_t index, uint32_t value) = 0;

		// IABR Fields
		virtual uint32_t get_IABR_ACTIVE(uint16_t index) const = 0;
		virtual void set_IABR_ACTIVE(uint16_t index, uint32_t value) = 0;

		// IPR Fields
		virtual uint32_t get_IPR_PRI(uint16_t index) const = 0;
		virtual void set_IPR_PRI(uint16_t index, uint32_t value) = 0;

		// STIR Fields
		virtual uint32_t get_STIR_INTID() const = 0;
		virtual void set_STIR_INTID(uint32_t value) = 0;
	};

	class NvicRegisterMap : public INvicRegisterMap
	{
	public:

		NvicRegisterMap(NvicRegisters & registers)
			: registers(registers) { }

		NvicRegisterMap(uint32_t addr)
			: registers(*reinterpret_cast<NvicRegisters*>(addr)) { }

		// ISER Fields
		uint32_t get_ISER_SETENA(uint16_t index) const { return registers.ISER[index].Fields.SETENA; }
		void set_ISER_SETENA(uint16_t index, uint32_t value) { registers.ISER[index].Fields.SETENA = value; }

		// ICER Fields
		uint32_t get_ICER_CLRENA(uint16_t index) const { return registers.ICER[index].Fields.CLRENA; }
		void set_ICER_CLRENA(uint16_t index, uint32_t value) { registers.ICER[index].Fields.CLRENA = value; }

		// ISPR Fields
		uint32_t get_ISPR_SETPEND(uint16_t index) const { return registers.ISPR[index].Fields.SETPEND; }
		void set_ISPR_SETPEND(uint16_t index, uint32_t value) { registers.ISPR[index].Fields.SETPEND = value; }

		// ICPR Fields
		uint32_t get_ICPR_CLRPEND(uint16_t index) const { return registers.ICPR[index].Fields.CLRPEND; }
		void set_ICPR_CLRPEND(uint16_t index, uint32_t value) { registers.ICPR[index].Fields.CLRPEND = value; }

		// IABR Fields
		uint32_t get_IABR_ACTIVE(uint16_t index) const { return registers.IABR[index].Fields.ACTIVE; }
		void set_IABR_ACTIVE(uint16_t index, uint32_t value) { registers.IABR[index].Fields.ACTIVE = value; }

		// IPR Fields
		uint32_t get_IPR_PRI(uint16_t index) const { return registers.IPR[index].Fields.PRI; }
		void set_IPR_PRI(uint16_t index, uint32_t value) { registers.IPR[index].Fields.PRI = value; }

		// STIR Fields
		uint32_t get_STIR_INTID() const { return registers.STIR.Fields.INTID; }
		void set_STIR_INTID(uint32_t value) { registers.STIR.Fields.INTID = value; }

	private:

		NvicRegisters & registers;
	};
}
#endif // NVIC_REGISTER_MAP_HPP_