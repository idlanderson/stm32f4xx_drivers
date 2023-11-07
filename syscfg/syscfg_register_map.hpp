#ifndef SYSCFG_REGISTER_MAP_HPP_
#define SYSCFG_REGISTER_MAP_HPP_

#include <cstdint>
#include "syscfg_types.hpp"

using namespace std;

namespace stm32::syscfg
{
	union MEMRMP_t
	{
		volatile struct
		{
			MemoryMapping MEM_MODE    : 2; // [0:1]   rw : Memory mapping selection
			Reserved      Reserved1   : 30; // [2:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union PMC_t
	{
		volatile struct
		{
			Reserved             Reserved1   : 23; // [0:22]     : RESERVED FIELD.
			EthernetPhyInterface MII_RMII_SEL : 1; // [23]    rw : Ethernet PHY interface selection
			Reserved             Reserved2   : 8; // [24:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union EXTICR1_t
	{
		volatile struct
		{
			ExtiConfiguration EXTI0       : 4; // [0:3]   rw : EXTI x configuration
			ExtiConfiguration EXTI1       : 4; // [4:7]   rw : EXTI x configuration
			ExtiConfiguration EXTI2       : 4; // [8:11]  rw : EXTI x configuration
			ExtiConfiguration EXTI3       : 4; // [12:15] rw : EXTI x configuration
			Reserved          Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union EXTICR2_t
	{
		volatile struct
		{
			ExtiConfiguration EXTI4       : 4; // [0:3]   rw : EXTI x configuration
			ExtiConfiguration EXTI5       : 4; // [4:7]   rw : EXTI x configuration
			ExtiConfiguration EXTI6       : 4; // [8:11]  rw : EXTI x configuration
			ExtiConfiguration EXTI7       : 4; // [12:15] rw : EXTI x configuration
			Reserved          Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union EXTICR3_t
	{
		volatile struct
		{
			ExtiConfiguration EXTI8       : 4; // [0:3]   rw : EXTI x configuration
			ExtiConfiguration EXTI9       : 4; // [4:7]   rw : EXTI x configuration
			ExtiConfiguration EXTI10      : 4; // [8:11]  rw : EXTI x configuration
			ExtiConfiguration EXTI11      : 4; // [12:15] rw : EXTI x configuration
			Reserved          Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union EXTICR4_t
	{
		volatile struct
		{
			ExtiConfiguration EXTI12      : 4; // [0:3]   rw : EXTI x configuration
			ExtiConfiguration EXTI13      : 4; // [4:7]   rw : EXTI x configuration
			ExtiConfiguration EXTI14      : 4; // [8:11]  rw : EXTI x configuration
			ExtiConfiguration EXTI15      : 4; // [12:15] rw : EXTI x configuration
			Reserved          Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union CMPCR_t
	{
		volatile struct
		{
			CompensationCellPowerDown CMP_PD      : 1; // [0]     rw : Compensation cell power-down
			Reserved                  Reserved1   : 7; // [1:7]      : RESERVED FIELD.
			CompensationCellReadyFlag READY       : 1; // [8]     r  : Compensation cell ready flag
			Reserved                  Reserved2   : 23; // [9:31]     : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	struct SyscfgRegisters
	{
		MEMRMP_t MEMRMP; // Address Offset 0x0
		PMC_t PMC; // Address Offset 0x4
		EXTICR1_t EXTICR1; // Address Offset 0x8
		EXTICR2_t EXTICR2; // Address Offset 0xC
		EXTICR3_t EXTICR3; // Address Offset 0x10
		EXTICR4_t EXTICR4; // Address Offset 0x14
		Reserved Reserved1; // Address Offset 0x18
		Reserved Reserved2; // Address Offset 0x1C
		CMPCR_t CMPCR; // Address Offset 0x20
	};

	class ISyscfgRegisterMap
	{
	public:

		// MEMRMP Fields
		virtual MemoryMapping get_MEMRMP_MEM_MODE() const = 0;
		virtual void set_MEMRMP_MEM_MODE(MemoryMapping value) = 0;

		// PMC Fields
		virtual EthernetPhyInterface get_PMC_MII_RMII_SEL() const = 0;
		virtual void set_PMC_MII_RMII_SEL(EthernetPhyInterface value) = 0;

		// EXTICR1 Fields
		virtual ExtiConfiguration get_EXTICR1_EXTI0() const = 0;
		virtual ExtiConfiguration get_EXTICR1_EXTI1() const = 0;
		virtual ExtiConfiguration get_EXTICR1_EXTI2() const = 0;
		virtual ExtiConfiguration get_EXTICR1_EXTI3() const = 0;
		virtual void set_EXTICR1_EXTI0(ExtiConfiguration value) = 0;
		virtual void set_EXTICR1_EXTI1(ExtiConfiguration value) = 0;
		virtual void set_EXTICR1_EXTI2(ExtiConfiguration value) = 0;
		virtual void set_EXTICR1_EXTI3(ExtiConfiguration value) = 0;

		// EXTICR2 Fields
		virtual ExtiConfiguration get_EXTICR2_EXTI4() const = 0;
		virtual ExtiConfiguration get_EXTICR2_EXTI5() const = 0;
		virtual ExtiConfiguration get_EXTICR2_EXTI6() const = 0;
		virtual ExtiConfiguration get_EXTICR2_EXTI7() const = 0;
		virtual void set_EXTICR2_EXTI4(ExtiConfiguration value) = 0;
		virtual void set_EXTICR2_EXTI5(ExtiConfiguration value) = 0;
		virtual void set_EXTICR2_EXTI6(ExtiConfiguration value) = 0;
		virtual void set_EXTICR2_EXTI7(ExtiConfiguration value) = 0;

		// EXTICR3 Fields
		virtual ExtiConfiguration get_EXTICR3_EXTI8() const = 0;
		virtual ExtiConfiguration get_EXTICR3_EXTI9() const = 0;
		virtual ExtiConfiguration get_EXTICR3_EXTI10() const = 0;
		virtual ExtiConfiguration get_EXTICR3_EXTI11() const = 0;
		virtual void set_EXTICR3_EXTI8(ExtiConfiguration value) = 0;
		virtual void set_EXTICR3_EXTI9(ExtiConfiguration value) = 0;
		virtual void set_EXTICR3_EXTI10(ExtiConfiguration value) = 0;
		virtual void set_EXTICR3_EXTI11(ExtiConfiguration value) = 0;

		// EXTICR4 Fields
		virtual ExtiConfiguration get_EXTICR4_EXTI12() const = 0;
		virtual ExtiConfiguration get_EXTICR4_EXTI13() const = 0;
		virtual ExtiConfiguration get_EXTICR4_EXTI14() const = 0;
		virtual ExtiConfiguration get_EXTICR4_EXTI15() const = 0;
		virtual void set_EXTICR4_EXTI12(ExtiConfiguration value) = 0;
		virtual void set_EXTICR4_EXTI13(ExtiConfiguration value) = 0;
		virtual void set_EXTICR4_EXTI14(ExtiConfiguration value) = 0;
		virtual void set_EXTICR4_EXTI15(ExtiConfiguration value) = 0;

		// CMPCR Fields
		virtual CompensationCellPowerDown get_CMPCR_CMP_PD() const = 0;
		virtual CompensationCellReadyFlag get_CMPCR_READY() const = 0;
		virtual void set_CMPCR_CMP_PD(CompensationCellPowerDown value) = 0;
	};

	class SyscfgRegisterMap : public ISyscfgRegisterMap
	{
	public:

		SyscfgRegisterMap(SyscfgRegisters & registers)
			: registers(registers) { }

		SyscfgRegisterMap(uint32_t addr)
			: registers(*reinterpret_cast<SyscfgRegisters*>(addr)) { }

		// MEMRMP Fields
		MemoryMapping get_MEMRMP_MEM_MODE() const { return registers.MEMRMP.Fields.MEM_MODE; }
		void set_MEMRMP_MEM_MODE(MemoryMapping value) { registers.MEMRMP.Fields.MEM_MODE = value; }

		// PMC Fields
		EthernetPhyInterface get_PMC_MII_RMII_SEL() const { return registers.PMC.Fields.MII_RMII_SEL; }
		void set_PMC_MII_RMII_SEL(EthernetPhyInterface value) { registers.PMC.Fields.MII_RMII_SEL = value; }

		// EXTICR1 Fields
		ExtiConfiguration get_EXTICR1_EXTI0() const { return registers.EXTICR1.Fields.EXTI0; }
		ExtiConfiguration get_EXTICR1_EXTI1() const { return registers.EXTICR1.Fields.EXTI1; }
		ExtiConfiguration get_EXTICR1_EXTI2() const { return registers.EXTICR1.Fields.EXTI2; }
		ExtiConfiguration get_EXTICR1_EXTI3() const { return registers.EXTICR1.Fields.EXTI3; }
		void set_EXTICR1_EXTI0(ExtiConfiguration value) { registers.EXTICR1.Fields.EXTI0 = value; }
		void set_EXTICR1_EXTI1(ExtiConfiguration value) { registers.EXTICR1.Fields.EXTI1 = value; }
		void set_EXTICR1_EXTI2(ExtiConfiguration value) { registers.EXTICR1.Fields.EXTI2 = value; }
		void set_EXTICR1_EXTI3(ExtiConfiguration value) { registers.EXTICR1.Fields.EXTI3 = value; }

		// EXTICR2 Fields
		ExtiConfiguration get_EXTICR2_EXTI4() const { return registers.EXTICR2.Fields.EXTI4; }
		ExtiConfiguration get_EXTICR2_EXTI5() const { return registers.EXTICR2.Fields.EXTI5; }
		ExtiConfiguration get_EXTICR2_EXTI6() const { return registers.EXTICR2.Fields.EXTI6; }
		ExtiConfiguration get_EXTICR2_EXTI7() const { return registers.EXTICR2.Fields.EXTI7; }
		void set_EXTICR2_EXTI4(ExtiConfiguration value) { registers.EXTICR2.Fields.EXTI4 = value; }
		void set_EXTICR2_EXTI5(ExtiConfiguration value) { registers.EXTICR2.Fields.EXTI5 = value; }
		void set_EXTICR2_EXTI6(ExtiConfiguration value) { registers.EXTICR2.Fields.EXTI6 = value; }
		void set_EXTICR2_EXTI7(ExtiConfiguration value) { registers.EXTICR2.Fields.EXTI7 = value; }

		// EXTICR3 Fields
		ExtiConfiguration get_EXTICR3_EXTI8() const { return registers.EXTICR3.Fields.EXTI8; }
		ExtiConfiguration get_EXTICR3_EXTI9() const { return registers.EXTICR3.Fields.EXTI9; }
		ExtiConfiguration get_EXTICR3_EXTI10() const { return registers.EXTICR3.Fields.EXTI10; }
		ExtiConfiguration get_EXTICR3_EXTI11() const { return registers.EXTICR3.Fields.EXTI11; }
		void set_EXTICR3_EXTI8(ExtiConfiguration value) { registers.EXTICR3.Fields.EXTI8 = value; }
		void set_EXTICR3_EXTI9(ExtiConfiguration value) { registers.EXTICR3.Fields.EXTI9 = value; }
		void set_EXTICR3_EXTI10(ExtiConfiguration value) { registers.EXTICR3.Fields.EXTI10 = value; }
		void set_EXTICR3_EXTI11(ExtiConfiguration value) { registers.EXTICR3.Fields.EXTI11 = value; }

		// EXTICR4 Fields
		ExtiConfiguration get_EXTICR4_EXTI12() const { return registers.EXTICR4.Fields.EXTI12; }
		ExtiConfiguration get_EXTICR4_EXTI13() const { return registers.EXTICR4.Fields.EXTI13; }
		ExtiConfiguration get_EXTICR4_EXTI14() const { return registers.EXTICR4.Fields.EXTI14; }
		ExtiConfiguration get_EXTICR4_EXTI15() const { return registers.EXTICR4.Fields.EXTI15; }
		void set_EXTICR4_EXTI12(ExtiConfiguration value) { registers.EXTICR4.Fields.EXTI12 = value; }
		void set_EXTICR4_EXTI13(ExtiConfiguration value) { registers.EXTICR4.Fields.EXTI13 = value; }
		void set_EXTICR4_EXTI14(ExtiConfiguration value) { registers.EXTICR4.Fields.EXTI14 = value; }
		void set_EXTICR4_EXTI15(ExtiConfiguration value) { registers.EXTICR4.Fields.EXTI15 = value; }

		// CMPCR Fields
		CompensationCellPowerDown get_CMPCR_CMP_PD() const { return registers.CMPCR.Fields.CMP_PD; }
		CompensationCellReadyFlag get_CMPCR_READY() const { return registers.CMPCR.Fields.READY; }
		void set_CMPCR_CMP_PD(CompensationCellPowerDown value) { registers.CMPCR.Fields.CMP_PD = value; }

	private:

		SyscfgRegisters & registers;
	};
}
#endif // SYSCFG_REGISTER_MAP_HPP_