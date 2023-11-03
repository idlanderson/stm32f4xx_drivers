#ifndef EXTI_REGISTER_MAP_HPP_
#define EXTI_REGISTER_MAP_HPP_

#include <cstdint>
#include "exti_types.hpp"

using namespace std;

namespace stm32::exti
{
	union IMR_t
	{
		volatile struct
		{
			uint32_t MR          : 23; // [0:22]  rw : Interrupt mask on lines 0-22
			Reserved Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union EMR_t
	{
		volatile struct
		{
			uint32_t MR          : 23; // [0:22]  rw : Event mask on lines 0-22
			Reserved Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union RTSR_t
	{
		volatile struct
		{
			uint32_t TR          : 23; // [0:22]  rw : Rising trigger event configuration bit of lines 0-22
			Reserved Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union FTSR_t
	{
		volatile struct
		{
			uint32_t TR          : 23; // [0:22]  rw : Falling trigger event configuration bit of lines 0-22
			Reserved Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union SWIER_t
	{
		volatile struct
		{
			uint32_t SWIER       : 23; // [0:22]  rw : Software interrupt on lines 0-22
			Reserved Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union PR_t
	{
		volatile struct
		{
			uint32_t PR          : 23; // [0:22]  rw : Pending bit on lines 0-22
			Reserved Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	struct ExtiRegisters
	{
		IMR_t IMR; // Address Offset 0x0
		EMR_t EMR; // Address Offset 0x4
		RTSR_t RTSR; // Address Offset 0x8
		FTSR_t FTSR; // Address Offset 0xC
		SWIER_t SWIER; // Address Offset 0x10
		PR_t PR; // Address Offset 0x14
	};

	class IExtiRegisterMap
	{
	public:

		// IMR Fields
		virtual uint32_t get_IMR_MR() const = 0;
		virtual void set_IMR_MR(uint32_t value) = 0;

		// EMR Fields
		virtual uint32_t get_EMR_MR() const = 0;
		virtual void set_EMR_MR(uint32_t value) = 0;

		// RTSR Fields
		virtual uint32_t get_RTSR_TR() const = 0;
		virtual void set_RTSR_TR(uint32_t value) = 0;

		// FTSR Fields
		virtual uint32_t get_FTSR_TR() const = 0;
		virtual void set_FTSR_TR(uint32_t value) = 0;

		// SWIER Fields
		virtual uint32_t get_SWIER_SWIER() const = 0;
		virtual void set_SWIER_SWIER(uint32_t value) = 0;

		// PR Fields
		virtual uint32_t get_PR_PR() const = 0;
		virtual void set_PR_PR(uint32_t value) = 0;
	};

	class ExtiRegisterMap : public IExtiRegisterMap
	{
	public:

		ExtiRegisterMap(ExtiRegisters & registers)
			: registers(registers) { }

		ExtiRegisterMap(uint32_t addr)
			: registers(*reinterpret_cast<ExtiRegisters*>(addr)) { }

		// IMR Fields
		uint32_t get_IMR_MR() const { return registers.IMR.Fields.MR; }
		void set_IMR_MR(uint32_t value) { registers.IMR.Fields.MR = value; }

		// EMR Fields
		uint32_t get_EMR_MR() const { return registers.EMR.Fields.MR; }
		void set_EMR_MR(uint32_t value) { registers.EMR.Fields.MR = value; }

		// RTSR Fields
		uint32_t get_RTSR_TR() const { return registers.RTSR.Fields.TR; }
		void set_RTSR_TR(uint32_t value) { registers.RTSR.Fields.TR = value; }

		// FTSR Fields
		uint32_t get_FTSR_TR() const { return registers.FTSR.Fields.TR; }
		void set_FTSR_TR(uint32_t value) { registers.FTSR.Fields.TR = value; }

		// SWIER Fields
		uint32_t get_SWIER_SWIER() const { return registers.SWIER.Fields.SWIER; }
		void set_SWIER_SWIER(uint32_t value) { registers.SWIER.Fields.SWIER = value; }

		// PR Fields
		uint32_t get_PR_PR() const { return registers.PR.Fields.PR; }
		void set_PR_PR(uint32_t value) { registers.PR.Fields.PR = value; }

	private:

		ExtiRegisters & registers;
	};
}
#endif // EXTI_REGISTER_MAP_HPP_