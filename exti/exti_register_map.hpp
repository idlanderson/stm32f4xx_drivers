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
			InterruptMask MR0         : 1; // [0]     rw : Interrupt mask on line 0
			InterruptMask MR1         : 1; // [1]     rw : Interrupt mask on line 1
			InterruptMask MR2         : 1; // [2]     rw : Interrupt mask on line 2
			InterruptMask MR3         : 1; // [3]     rw : Interrupt mask on line 3
			InterruptMask MR4         : 1; // [4]     rw : Interrupt mask on line 4
			InterruptMask MR5         : 1; // [5]     rw : Interrupt mask on line 5
			InterruptMask MR6         : 1; // [6]     rw : Interrupt mask on line 6
			InterruptMask MR7         : 1; // [7]     rw : Interrupt mask on line 7
			InterruptMask MR8         : 1; // [8]     rw : Interrupt mask on line 8
			InterruptMask MR9         : 1; // [9]     rw : Interrupt mask on line 9
			InterruptMask MR10        : 1; // [10]    rw : Interrupt mask on line 10
			InterruptMask MR11        : 1; // [11]    rw : Interrupt mask on line 11
			InterruptMask MR12        : 1; // [12]    rw : Interrupt mask on line 12
			InterruptMask MR13        : 1; // [13]    rw : Interrupt mask on line 13
			InterruptMask MR14        : 1; // [14]    rw : Interrupt mask on line 14
			InterruptMask MR15        : 1; // [15]    rw : Interrupt mask on line 15
			InterruptMask MR16        : 1; // [16]    rw : Interrupt mask on line 16
			InterruptMask MR17        : 1; // [17]    rw : Interrupt mask on line 17
			InterruptMask MR18        : 1; // [18]    rw : Interrupt mask on line 18
			InterruptMask MR19        : 1; // [19]    rw : Interrupt mask on line 19
			InterruptMask MR20        : 1; // [20]    rw : Interrupt mask on line 20
			InterruptMask MR21        : 1; // [21]    rw : Interrupt mask on line 21
			InterruptMask MR22        : 1; // [22]    rw : Interrupt mask on line 22
			Reserved      Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union EMR_t
	{
		volatile struct
		{
			InterruptMask MR0         : 1; // [0]     rw : Event mask on line 0
			InterruptMask MR1         : 1; // [1]     rw : Event mask on line 1
			InterruptMask MR2         : 1; // [2]     rw : Event mask on line 2
			InterruptMask MR3         : 1; // [3]     rw : Event mask on line 3
			InterruptMask MR4         : 1; // [4]     rw : Event mask on line 4
			InterruptMask MR5         : 1; // [5]     rw : Event mask on line 5
			InterruptMask MR6         : 1; // [6]     rw : Event mask on line 6
			InterruptMask MR7         : 1; // [7]     rw : Event mask on line 7
			InterruptMask MR8         : 1; // [8]     rw : Event mask on line 8
			InterruptMask MR9         : 1; // [9]     rw : Event mask on line 9
			InterruptMask MR10        : 1; // [10]    rw : Event mask on line 10
			InterruptMask MR11        : 1; // [11]    rw : Event mask on line 11
			InterruptMask MR12        : 1; // [12]    rw : Event mask on line 12
			InterruptMask MR13        : 1; // [13]    rw : Event mask on line 13
			InterruptMask MR14        : 1; // [14]    rw : Event mask on line 14
			InterruptMask MR15        : 1; // [15]    rw : Event mask on line 15
			InterruptMask MR16        : 1; // [16]    rw : Event mask on line 16
			InterruptMask MR17        : 1; // [17]    rw : Event mask on line 17
			InterruptMask MR18        : 1; // [18]    rw : Event mask on line 18
			InterruptMask MR19        : 1; // [19]    rw : Event mask on line 19
			InterruptMask MR20        : 1; // [20]    rw : Event mask on line 20
			InterruptMask MR21        : 1; // [21]    rw : Event mask on line 21
			InterruptMask MR22        : 1; // [22]    rw : Event mask on line 22
			Reserved      Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union RTSR_t
	{
		volatile struct
		{
			EnableFlag TR0         : 1; // [0]     rw : Rising trigger event configuration bit of line 0
			EnableFlag TR1         : 1; // [1]     rw : Rising trigger event configuration bit of line 1
			EnableFlag TR2         : 1; // [2]     rw : Rising trigger event configuration bit of line 2
			EnableFlag TR3         : 1; // [3]     rw : Rising trigger event configuration bit of line 3
			EnableFlag TR4         : 1; // [4]     rw : Rising trigger event configuration bit of line 4
			EnableFlag TR5         : 1; // [5]     rw : Rising trigger event configuration bit of line 5
			EnableFlag TR6         : 1; // [6]     rw : Rising trigger event configuration bit of line 6
			EnableFlag TR7         : 1; // [7]     rw : Rising trigger event configuration bit of line 7
			EnableFlag TR8         : 1; // [8]     rw : Rising trigger event configuration bit of line 8
			EnableFlag TR9         : 1; // [9]     rw : Rising trigger event configuration bit of line 9
			EnableFlag TR10        : 1; // [10]    rw : Rising trigger event configuration bit of line 10
			EnableFlag TR11        : 1; // [11]    rw : Rising trigger event configuration bit of line 11
			EnableFlag TR12        : 1; // [12]    rw : Rising trigger event configuration bit of line 12
			EnableFlag TR13        : 1; // [13]    rw : Rising trigger event configuration bit of line 13
			EnableFlag TR14        : 1; // [14]    rw : Rising trigger event configuration bit of line 14
			EnableFlag TR15        : 1; // [15]    rw : Rising trigger event configuration bit of line 15
			EnableFlag TR16        : 1; // [16]    rw : Rising trigger event configuration bit of line 16
			EnableFlag TR17        : 1; // [17]    rw : Rising trigger event configuration bit of line 17
			EnableFlag TR18        : 1; // [18]    rw : Rising trigger event configuration bit of line 18
			EnableFlag TR19        : 1; // [19]    rw : Rising trigger event configuration bit of line 19
			EnableFlag TR20        : 1; // [20]    rw : Rising trigger event configuration bit of line 20
			EnableFlag TR21        : 1; // [21]    rw : Rising trigger event configuration bit of line 21
			EnableFlag TR22        : 1; // [22]    rw : Rising trigger event configuration bit of line 22
			Reserved   Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union FTSR_t
	{
		volatile struct
		{
			EnableFlag TR0         : 1; // [0]     rw : Falling trigger event configuration bit of line 0
			EnableFlag TR1         : 1; // [1]     rw : Falling trigger event configuration bit of line 1
			EnableFlag TR2         : 1; // [2]     rw : Falling trigger event configuration bit of line 2
			EnableFlag TR3         : 1; // [3]     rw : Falling trigger event configuration bit of line 3
			EnableFlag TR4         : 1; // [4]     rw : Falling trigger event configuration bit of line 4
			EnableFlag TR5         : 1; // [5]     rw : Falling trigger event configuration bit of line 5
			EnableFlag TR6         : 1; // [6]     rw : Falling trigger event configuration bit of line 6
			EnableFlag TR7         : 1; // [7]     rw : Falling trigger event configuration bit of line 7
			EnableFlag TR8         : 1; // [8]     rw : Falling trigger event configuration bit of line 8
			EnableFlag TR9         : 1; // [9]     rw : Falling trigger event configuration bit of line 9
			EnableFlag TR10        : 1; // [10]    rw : Falling trigger event configuration bit of line 10
			EnableFlag TR11        : 1; // [11]    rw : Falling trigger event configuration bit of line 11
			EnableFlag TR12        : 1; // [12]    rw : Falling trigger event configuration bit of line 12
			EnableFlag TR13        : 1; // [13]    rw : Falling trigger event configuration bit of line 13
			EnableFlag TR14        : 1; // [14]    rw : Falling trigger event configuration bit of line 14
			EnableFlag TR15        : 1; // [15]    rw : Falling trigger event configuration bit of line 15
			EnableFlag TR16        : 1; // [16]    rw : Falling trigger event configuration bit of line 16
			EnableFlag TR17        : 1; // [17]    rw : Falling trigger event configuration bit of line 17
			EnableFlag TR18        : 1; // [18]    rw : Falling trigger event configuration bit of line 18
			EnableFlag TR19        : 1; // [19]    rw : Falling trigger event configuration bit of line 19
			EnableFlag TR20        : 1; // [20]    rw : Falling trigger event configuration bit of line 20
			EnableFlag TR21        : 1; // [21]    rw : Falling trigger event configuration bit of line 21
			EnableFlag TR22        : 1; // [22]    rw : Falling trigger event configuration bit of line 22
			Reserved   Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union SWIER_t
	{
		volatile struct
		{
			SoftwareInterrupt SWIER0      : 1; // [0]     rw : Software interrupt on line 0
			SoftwareInterrupt SWIER1      : 1; // [1]     rw : Software interrupt on line 1
			SoftwareInterrupt SWIER2      : 1; // [2]     rw : Software interrupt on line 2
			SoftwareInterrupt SWIER3      : 1; // [3]     rw : Software interrupt on line 3
			SoftwareInterrupt SWIER4      : 1; // [4]     rw : Software interrupt on line 4
			SoftwareInterrupt SWIER5      : 1; // [5]     rw : Software interrupt on line 5
			SoftwareInterrupt SWIER6      : 1; // [6]     rw : Software interrupt on line 6
			SoftwareInterrupt SWIER7      : 1; // [7]     rw : Software interrupt on line 7
			SoftwareInterrupt SWIER8      : 1; // [8]     rw : Software interrupt on line 8
			SoftwareInterrupt SWIER9      : 1; // [9]     rw : Software interrupt on line 9
			SoftwareInterrupt SWIER10     : 1; // [10]    rw : Software interrupt on line 10
			SoftwareInterrupt SWIER11     : 1; // [11]    rw : Software interrupt on line 11
			SoftwareInterrupt SWIER12     : 1; // [12]    rw : Software interrupt on line 12
			SoftwareInterrupt SWIER13     : 1; // [13]    rw : Software interrupt on line 13
			SoftwareInterrupt SWIER14     : 1; // [14]    rw : Software interrupt on line 14
			SoftwareInterrupt SWIER15     : 1; // [15]    rw : Software interrupt on line 15
			SoftwareInterrupt SWIER16     : 1; // [16]    rw : Software interrupt on line 16
			SoftwareInterrupt SWIER17     : 1; // [17]    rw : Software interrupt on line 17
			SoftwareInterrupt SWIER18     : 1; // [18]    rw : Software interrupt on line 18
			SoftwareInterrupt SWIER19     : 1; // [19]    rw : Software interrupt on line 19
			SoftwareInterrupt SWIER20     : 1; // [20]    rw : Software interrupt on line 20
			SoftwareInterrupt SWIER21     : 1; // [21]    rw : Software interrupt on line 21
			SoftwareInterrupt SWIER22     : 1; // [22]    rw : Software interrupt on line 22
			Reserved          Reserved1   : 9; // [23:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union PR_t
	{
		volatile struct
		{
			PendingBit PR0         : 1; // [0]     rw : Pending bit on line 0
			PendingBit PR1         : 1; // [1]     rw : Pending bit on line 1
			PendingBit PR2         : 1; // [2]     rw : Pending bit on line 2
			PendingBit PR3         : 1; // [3]     rw : Pending bit on line 3
			PendingBit PR4         : 1; // [4]     rw : Pending bit on line 4
			PendingBit PR5         : 1; // [5]     rw : Pending bit on line 5
			PendingBit PR6         : 1; // [6]     rw : Pending bit on line 6
			PendingBit PR7         : 1; // [7]     rw : Pending bit on line 7
			PendingBit PR8         : 1; // [8]     rw : Pending bit on line 8
			PendingBit PR9         : 1; // [9]     rw : Pending bit on line 9
			PendingBit PR10        : 1; // [10]    rw : Pending bit on line 10
			PendingBit PR11        : 1; // [11]    rw : Pending bit on line 11
			PendingBit PR12        : 1; // [12]    rw : Pending bit on line 12
			PendingBit PR13        : 1; // [13]    rw : Pending bit on line 13
			PendingBit PR14        : 1; // [14]    rw : Pending bit on line 14
			PendingBit PR15        : 1; // [15]    rw : Pending bit on line 15
			PendingBit PR16        : 1; // [16]    rw : Pending bit on line 16
			PendingBit PR17        : 1; // [17]    rw : Pending bit on line 17
			PendingBit PR18        : 1; // [18]    rw : Pending bit on line 18
			PendingBit PR19        : 1; // [19]    rw : Pending bit on line 19
			PendingBit PR20        : 1; // [20]    rw : Pending bit on line 20
			PendingBit PR21        : 1; // [21]    rw : Pending bit on line 21
			PendingBit PR22        : 1; // [22]    rw : Pending bit on line 22
			Reserved   Reserved1   : 9; // [23:31]    : RESERVED FIELD.
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
		virtual InterruptMask get_IMR_MR0() const = 0;
		virtual InterruptMask get_IMR_MR1() const = 0;
		virtual InterruptMask get_IMR_MR2() const = 0;
		virtual InterruptMask get_IMR_MR3() const = 0;
		virtual InterruptMask get_IMR_MR4() const = 0;
		virtual InterruptMask get_IMR_MR5() const = 0;
		virtual InterruptMask get_IMR_MR6() const = 0;
		virtual InterruptMask get_IMR_MR7() const = 0;
		virtual InterruptMask get_IMR_MR8() const = 0;
		virtual InterruptMask get_IMR_MR9() const = 0;
		virtual InterruptMask get_IMR_MR10() const = 0;
		virtual InterruptMask get_IMR_MR11() const = 0;
		virtual InterruptMask get_IMR_MR12() const = 0;
		virtual InterruptMask get_IMR_MR13() const = 0;
		virtual InterruptMask get_IMR_MR14() const = 0;
		virtual InterruptMask get_IMR_MR15() const = 0;
		virtual InterruptMask get_IMR_MR16() const = 0;
		virtual InterruptMask get_IMR_MR17() const = 0;
		virtual InterruptMask get_IMR_MR18() const = 0;
		virtual InterruptMask get_IMR_MR19() const = 0;
		virtual InterruptMask get_IMR_MR20() const = 0;
		virtual InterruptMask get_IMR_MR21() const = 0;
		virtual InterruptMask get_IMR_MR22() const = 0;
		virtual void set_IMR_MR0(InterruptMask value) = 0;
		virtual void set_IMR_MR1(InterruptMask value) = 0;
		virtual void set_IMR_MR2(InterruptMask value) = 0;
		virtual void set_IMR_MR3(InterruptMask value) = 0;
		virtual void set_IMR_MR4(InterruptMask value) = 0;
		virtual void set_IMR_MR5(InterruptMask value) = 0;
		virtual void set_IMR_MR6(InterruptMask value) = 0;
		virtual void set_IMR_MR7(InterruptMask value) = 0;
		virtual void set_IMR_MR8(InterruptMask value) = 0;
		virtual void set_IMR_MR9(InterruptMask value) = 0;
		virtual void set_IMR_MR10(InterruptMask value) = 0;
		virtual void set_IMR_MR11(InterruptMask value) = 0;
		virtual void set_IMR_MR12(InterruptMask value) = 0;
		virtual void set_IMR_MR13(InterruptMask value) = 0;
		virtual void set_IMR_MR14(InterruptMask value) = 0;
		virtual void set_IMR_MR15(InterruptMask value) = 0;
		virtual void set_IMR_MR16(InterruptMask value) = 0;
		virtual void set_IMR_MR17(InterruptMask value) = 0;
		virtual void set_IMR_MR18(InterruptMask value) = 0;
		virtual void set_IMR_MR19(InterruptMask value) = 0;
		virtual void set_IMR_MR20(InterruptMask value) = 0;
		virtual void set_IMR_MR21(InterruptMask value) = 0;
		virtual void set_IMR_MR22(InterruptMask value) = 0;

		// EMR Fields
		virtual InterruptMask get_EMR_MR0() const = 0;
		virtual InterruptMask get_EMR_MR1() const = 0;
		virtual InterruptMask get_EMR_MR2() const = 0;
		virtual InterruptMask get_EMR_MR3() const = 0;
		virtual InterruptMask get_EMR_MR4() const = 0;
		virtual InterruptMask get_EMR_MR5() const = 0;
		virtual InterruptMask get_EMR_MR6() const = 0;
		virtual InterruptMask get_EMR_MR7() const = 0;
		virtual InterruptMask get_EMR_MR8() const = 0;
		virtual InterruptMask get_EMR_MR9() const = 0;
		virtual InterruptMask get_EMR_MR10() const = 0;
		virtual InterruptMask get_EMR_MR11() const = 0;
		virtual InterruptMask get_EMR_MR12() const = 0;
		virtual InterruptMask get_EMR_MR13() const = 0;
		virtual InterruptMask get_EMR_MR14() const = 0;
		virtual InterruptMask get_EMR_MR15() const = 0;
		virtual InterruptMask get_EMR_MR16() const = 0;
		virtual InterruptMask get_EMR_MR17() const = 0;
		virtual InterruptMask get_EMR_MR18() const = 0;
		virtual InterruptMask get_EMR_MR19() const = 0;
		virtual InterruptMask get_EMR_MR20() const = 0;
		virtual InterruptMask get_EMR_MR21() const = 0;
		virtual InterruptMask get_EMR_MR22() const = 0;
		virtual void set_EMR_MR0(InterruptMask value) = 0;
		virtual void set_EMR_MR1(InterruptMask value) = 0;
		virtual void set_EMR_MR2(InterruptMask value) = 0;
		virtual void set_EMR_MR3(InterruptMask value) = 0;
		virtual void set_EMR_MR4(InterruptMask value) = 0;
		virtual void set_EMR_MR5(InterruptMask value) = 0;
		virtual void set_EMR_MR6(InterruptMask value) = 0;
		virtual void set_EMR_MR7(InterruptMask value) = 0;
		virtual void set_EMR_MR8(InterruptMask value) = 0;
		virtual void set_EMR_MR9(InterruptMask value) = 0;
		virtual void set_EMR_MR10(InterruptMask value) = 0;
		virtual void set_EMR_MR11(InterruptMask value) = 0;
		virtual void set_EMR_MR12(InterruptMask value) = 0;
		virtual void set_EMR_MR13(InterruptMask value) = 0;
		virtual void set_EMR_MR14(InterruptMask value) = 0;
		virtual void set_EMR_MR15(InterruptMask value) = 0;
		virtual void set_EMR_MR16(InterruptMask value) = 0;
		virtual void set_EMR_MR17(InterruptMask value) = 0;
		virtual void set_EMR_MR18(InterruptMask value) = 0;
		virtual void set_EMR_MR19(InterruptMask value) = 0;
		virtual void set_EMR_MR20(InterruptMask value) = 0;
		virtual void set_EMR_MR21(InterruptMask value) = 0;
		virtual void set_EMR_MR22(InterruptMask value) = 0;

		// RTSR Fields
		virtual EnableFlag get_RTSR_TR0() const = 0;
		virtual EnableFlag get_RTSR_TR1() const = 0;
		virtual EnableFlag get_RTSR_TR2() const = 0;
		virtual EnableFlag get_RTSR_TR3() const = 0;
		virtual EnableFlag get_RTSR_TR4() const = 0;
		virtual EnableFlag get_RTSR_TR5() const = 0;
		virtual EnableFlag get_RTSR_TR6() const = 0;
		virtual EnableFlag get_RTSR_TR7() const = 0;
		virtual EnableFlag get_RTSR_TR8() const = 0;
		virtual EnableFlag get_RTSR_TR9() const = 0;
		virtual EnableFlag get_RTSR_TR10() const = 0;
		virtual EnableFlag get_RTSR_TR11() const = 0;
		virtual EnableFlag get_RTSR_TR12() const = 0;
		virtual EnableFlag get_RTSR_TR13() const = 0;
		virtual EnableFlag get_RTSR_TR14() const = 0;
		virtual EnableFlag get_RTSR_TR15() const = 0;
		virtual EnableFlag get_RTSR_TR16() const = 0;
		virtual EnableFlag get_RTSR_TR17() const = 0;
		virtual EnableFlag get_RTSR_TR18() const = 0;
		virtual EnableFlag get_RTSR_TR19() const = 0;
		virtual EnableFlag get_RTSR_TR20() const = 0;
		virtual EnableFlag get_RTSR_TR21() const = 0;
		virtual EnableFlag get_RTSR_TR22() const = 0;
		virtual void set_RTSR_TR0(EnableFlag value) = 0;
		virtual void set_RTSR_TR1(EnableFlag value) = 0;
		virtual void set_RTSR_TR2(EnableFlag value) = 0;
		virtual void set_RTSR_TR3(EnableFlag value) = 0;
		virtual void set_RTSR_TR4(EnableFlag value) = 0;
		virtual void set_RTSR_TR5(EnableFlag value) = 0;
		virtual void set_RTSR_TR6(EnableFlag value) = 0;
		virtual void set_RTSR_TR7(EnableFlag value) = 0;
		virtual void set_RTSR_TR8(EnableFlag value) = 0;
		virtual void set_RTSR_TR9(EnableFlag value) = 0;
		virtual void set_RTSR_TR10(EnableFlag value) = 0;
		virtual void set_RTSR_TR11(EnableFlag value) = 0;
		virtual void set_RTSR_TR12(EnableFlag value) = 0;
		virtual void set_RTSR_TR13(EnableFlag value) = 0;
		virtual void set_RTSR_TR14(EnableFlag value) = 0;
		virtual void set_RTSR_TR15(EnableFlag value) = 0;
		virtual void set_RTSR_TR16(EnableFlag value) = 0;
		virtual void set_RTSR_TR17(EnableFlag value) = 0;
		virtual void set_RTSR_TR18(EnableFlag value) = 0;
		virtual void set_RTSR_TR19(EnableFlag value) = 0;
		virtual void set_RTSR_TR20(EnableFlag value) = 0;
		virtual void set_RTSR_TR21(EnableFlag value) = 0;
		virtual void set_RTSR_TR22(EnableFlag value) = 0;

		// FTSR Fields
		virtual EnableFlag get_FTSR_TR0() const = 0;
		virtual EnableFlag get_FTSR_TR1() const = 0;
		virtual EnableFlag get_FTSR_TR2() const = 0;
		virtual EnableFlag get_FTSR_TR3() const = 0;
		virtual EnableFlag get_FTSR_TR4() const = 0;
		virtual EnableFlag get_FTSR_TR5() const = 0;
		virtual EnableFlag get_FTSR_TR6() const = 0;
		virtual EnableFlag get_FTSR_TR7() const = 0;
		virtual EnableFlag get_FTSR_TR8() const = 0;
		virtual EnableFlag get_FTSR_TR9() const = 0;
		virtual EnableFlag get_FTSR_TR10() const = 0;
		virtual EnableFlag get_FTSR_TR11() const = 0;
		virtual EnableFlag get_FTSR_TR12() const = 0;
		virtual EnableFlag get_FTSR_TR13() const = 0;
		virtual EnableFlag get_FTSR_TR14() const = 0;
		virtual EnableFlag get_FTSR_TR15() const = 0;
		virtual EnableFlag get_FTSR_TR16() const = 0;
		virtual EnableFlag get_FTSR_TR17() const = 0;
		virtual EnableFlag get_FTSR_TR18() const = 0;
		virtual EnableFlag get_FTSR_TR19() const = 0;
		virtual EnableFlag get_FTSR_TR20() const = 0;
		virtual EnableFlag get_FTSR_TR21() const = 0;
		virtual EnableFlag get_FTSR_TR22() const = 0;
		virtual void set_FTSR_TR0(EnableFlag value) = 0;
		virtual void set_FTSR_TR1(EnableFlag value) = 0;
		virtual void set_FTSR_TR2(EnableFlag value) = 0;
		virtual void set_FTSR_TR3(EnableFlag value) = 0;
		virtual void set_FTSR_TR4(EnableFlag value) = 0;
		virtual void set_FTSR_TR5(EnableFlag value) = 0;
		virtual void set_FTSR_TR6(EnableFlag value) = 0;
		virtual void set_FTSR_TR7(EnableFlag value) = 0;
		virtual void set_FTSR_TR8(EnableFlag value) = 0;
		virtual void set_FTSR_TR9(EnableFlag value) = 0;
		virtual void set_FTSR_TR10(EnableFlag value) = 0;
		virtual void set_FTSR_TR11(EnableFlag value) = 0;
		virtual void set_FTSR_TR12(EnableFlag value) = 0;
		virtual void set_FTSR_TR13(EnableFlag value) = 0;
		virtual void set_FTSR_TR14(EnableFlag value) = 0;
		virtual void set_FTSR_TR15(EnableFlag value) = 0;
		virtual void set_FTSR_TR16(EnableFlag value) = 0;
		virtual void set_FTSR_TR17(EnableFlag value) = 0;
		virtual void set_FTSR_TR18(EnableFlag value) = 0;
		virtual void set_FTSR_TR19(EnableFlag value) = 0;
		virtual void set_FTSR_TR20(EnableFlag value) = 0;
		virtual void set_FTSR_TR21(EnableFlag value) = 0;
		virtual void set_FTSR_TR22(EnableFlag value) = 0;

		// SWIER Fields
		virtual SoftwareInterrupt get_SWIER_SWIER0() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER1() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER2() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER3() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER4() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER5() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER6() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER7() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER8() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER9() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER10() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER11() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER12() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER13() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER14() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER15() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER16() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER17() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER18() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER19() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER20() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER21() const = 0;
		virtual SoftwareInterrupt get_SWIER_SWIER22() const = 0;
		virtual void set_SWIER_SWIER0(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER1(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER2(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER3(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER4(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER5(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER6(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER7(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER8(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER9(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER10(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER11(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER12(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER13(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER14(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER15(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER16(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER17(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER18(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER19(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER20(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER21(SoftwareInterrupt value) = 0;
		virtual void set_SWIER_SWIER22(SoftwareInterrupt value) = 0;

		// PR Fields
		virtual PendingBit get_PR_PR0() const = 0;
		virtual PendingBit get_PR_PR1() const = 0;
		virtual PendingBit get_PR_PR2() const = 0;
		virtual PendingBit get_PR_PR3() const = 0;
		virtual PendingBit get_PR_PR4() const = 0;
		virtual PendingBit get_PR_PR5() const = 0;
		virtual PendingBit get_PR_PR6() const = 0;
		virtual PendingBit get_PR_PR7() const = 0;
		virtual PendingBit get_PR_PR8() const = 0;
		virtual PendingBit get_PR_PR9() const = 0;
		virtual PendingBit get_PR_PR10() const = 0;
		virtual PendingBit get_PR_PR11() const = 0;
		virtual PendingBit get_PR_PR12() const = 0;
		virtual PendingBit get_PR_PR13() const = 0;
		virtual PendingBit get_PR_PR14() const = 0;
		virtual PendingBit get_PR_PR15() const = 0;
		virtual PendingBit get_PR_PR16() const = 0;
		virtual PendingBit get_PR_PR17() const = 0;
		virtual PendingBit get_PR_PR18() const = 0;
		virtual PendingBit get_PR_PR19() const = 0;
		virtual PendingBit get_PR_PR20() const = 0;
		virtual PendingBit get_PR_PR21() const = 0;
		virtual PendingBit get_PR_PR22() const = 0;
		virtual void set_PR_PR0(PendingBit value) = 0;
		virtual void set_PR_PR1(PendingBit value) = 0;
		virtual void set_PR_PR2(PendingBit value) = 0;
		virtual void set_PR_PR3(PendingBit value) = 0;
		virtual void set_PR_PR4(PendingBit value) = 0;
		virtual void set_PR_PR5(PendingBit value) = 0;
		virtual void set_PR_PR6(PendingBit value) = 0;
		virtual void set_PR_PR7(PendingBit value) = 0;
		virtual void set_PR_PR8(PendingBit value) = 0;
		virtual void set_PR_PR9(PendingBit value) = 0;
		virtual void set_PR_PR10(PendingBit value) = 0;
		virtual void set_PR_PR11(PendingBit value) = 0;
		virtual void set_PR_PR12(PendingBit value) = 0;
		virtual void set_PR_PR13(PendingBit value) = 0;
		virtual void set_PR_PR14(PendingBit value) = 0;
		virtual void set_PR_PR15(PendingBit value) = 0;
		virtual void set_PR_PR16(PendingBit value) = 0;
		virtual void set_PR_PR17(PendingBit value) = 0;
		virtual void set_PR_PR18(PendingBit value) = 0;
		virtual void set_PR_PR19(PendingBit value) = 0;
		virtual void set_PR_PR20(PendingBit value) = 0;
		virtual void set_PR_PR21(PendingBit value) = 0;
		virtual void set_PR_PR22(PendingBit value) = 0;
	};

	class ExtiRegisterMap : public IExtiRegisterMap
	{
	public:

		ExtiRegisterMap(ExtiRegisters & registers)
			: registers(registers) { }

		ExtiRegisterMap(uint32_t addr)
			: registers(*reinterpret_cast<ExtiRegisters*>(addr)) { }

		// IMR Fields
		InterruptMask get_IMR_MR0() const { return registers.IMR.Fields.MR0; }
		InterruptMask get_IMR_MR1() const { return registers.IMR.Fields.MR1; }
		InterruptMask get_IMR_MR2() const { return registers.IMR.Fields.MR2; }
		InterruptMask get_IMR_MR3() const { return registers.IMR.Fields.MR3; }
		InterruptMask get_IMR_MR4() const { return registers.IMR.Fields.MR4; }
		InterruptMask get_IMR_MR5() const { return registers.IMR.Fields.MR5; }
		InterruptMask get_IMR_MR6() const { return registers.IMR.Fields.MR6; }
		InterruptMask get_IMR_MR7() const { return registers.IMR.Fields.MR7; }
		InterruptMask get_IMR_MR8() const { return registers.IMR.Fields.MR8; }
		InterruptMask get_IMR_MR9() const { return registers.IMR.Fields.MR9; }
		InterruptMask get_IMR_MR10() const { return registers.IMR.Fields.MR10; }
		InterruptMask get_IMR_MR11() const { return registers.IMR.Fields.MR11; }
		InterruptMask get_IMR_MR12() const { return registers.IMR.Fields.MR12; }
		InterruptMask get_IMR_MR13() const { return registers.IMR.Fields.MR13; }
		InterruptMask get_IMR_MR14() const { return registers.IMR.Fields.MR14; }
		InterruptMask get_IMR_MR15() const { return registers.IMR.Fields.MR15; }
		InterruptMask get_IMR_MR16() const { return registers.IMR.Fields.MR16; }
		InterruptMask get_IMR_MR17() const { return registers.IMR.Fields.MR17; }
		InterruptMask get_IMR_MR18() const { return registers.IMR.Fields.MR18; }
		InterruptMask get_IMR_MR19() const { return registers.IMR.Fields.MR19; }
		InterruptMask get_IMR_MR20() const { return registers.IMR.Fields.MR20; }
		InterruptMask get_IMR_MR21() const { return registers.IMR.Fields.MR21; }
		InterruptMask get_IMR_MR22() const { return registers.IMR.Fields.MR22; }
		void set_IMR_MR0(InterruptMask value) { registers.IMR.Fields.MR0 = value; }
		void set_IMR_MR1(InterruptMask value) { registers.IMR.Fields.MR1 = value; }
		void set_IMR_MR2(InterruptMask value) { registers.IMR.Fields.MR2 = value; }
		void set_IMR_MR3(InterruptMask value) { registers.IMR.Fields.MR3 = value; }
		void set_IMR_MR4(InterruptMask value) { registers.IMR.Fields.MR4 = value; }
		void set_IMR_MR5(InterruptMask value) { registers.IMR.Fields.MR5 = value; }
		void set_IMR_MR6(InterruptMask value) { registers.IMR.Fields.MR6 = value; }
		void set_IMR_MR7(InterruptMask value) { registers.IMR.Fields.MR7 = value; }
		void set_IMR_MR8(InterruptMask value) { registers.IMR.Fields.MR8 = value; }
		void set_IMR_MR9(InterruptMask value) { registers.IMR.Fields.MR9 = value; }
		void set_IMR_MR10(InterruptMask value) { registers.IMR.Fields.MR10 = value; }
		void set_IMR_MR11(InterruptMask value) { registers.IMR.Fields.MR11 = value; }
		void set_IMR_MR12(InterruptMask value) { registers.IMR.Fields.MR12 = value; }
		void set_IMR_MR13(InterruptMask value) { registers.IMR.Fields.MR13 = value; }
		void set_IMR_MR14(InterruptMask value) { registers.IMR.Fields.MR14 = value; }
		void set_IMR_MR15(InterruptMask value) { registers.IMR.Fields.MR15 = value; }
		void set_IMR_MR16(InterruptMask value) { registers.IMR.Fields.MR16 = value; }
		void set_IMR_MR17(InterruptMask value) { registers.IMR.Fields.MR17 = value; }
		void set_IMR_MR18(InterruptMask value) { registers.IMR.Fields.MR18 = value; }
		void set_IMR_MR19(InterruptMask value) { registers.IMR.Fields.MR19 = value; }
		void set_IMR_MR20(InterruptMask value) { registers.IMR.Fields.MR20 = value; }
		void set_IMR_MR21(InterruptMask value) { registers.IMR.Fields.MR21 = value; }
		void set_IMR_MR22(InterruptMask value) { registers.IMR.Fields.MR22 = value; }

		// EMR Fields
		InterruptMask get_EMR_MR0() const { return registers.EMR.Fields.MR0; }
		InterruptMask get_EMR_MR1() const { return registers.EMR.Fields.MR1; }
		InterruptMask get_EMR_MR2() const { return registers.EMR.Fields.MR2; }
		InterruptMask get_EMR_MR3() const { return registers.EMR.Fields.MR3; }
		InterruptMask get_EMR_MR4() const { return registers.EMR.Fields.MR4; }
		InterruptMask get_EMR_MR5() const { return registers.EMR.Fields.MR5; }
		InterruptMask get_EMR_MR6() const { return registers.EMR.Fields.MR6; }
		InterruptMask get_EMR_MR7() const { return registers.EMR.Fields.MR7; }
		InterruptMask get_EMR_MR8() const { return registers.EMR.Fields.MR8; }
		InterruptMask get_EMR_MR9() const { return registers.EMR.Fields.MR9; }
		InterruptMask get_EMR_MR10() const { return registers.EMR.Fields.MR10; }
		InterruptMask get_EMR_MR11() const { return registers.EMR.Fields.MR11; }
		InterruptMask get_EMR_MR12() const { return registers.EMR.Fields.MR12; }
		InterruptMask get_EMR_MR13() const { return registers.EMR.Fields.MR13; }
		InterruptMask get_EMR_MR14() const { return registers.EMR.Fields.MR14; }
		InterruptMask get_EMR_MR15() const { return registers.EMR.Fields.MR15; }
		InterruptMask get_EMR_MR16() const { return registers.EMR.Fields.MR16; }
		InterruptMask get_EMR_MR17() const { return registers.EMR.Fields.MR17; }
		InterruptMask get_EMR_MR18() const { return registers.EMR.Fields.MR18; }
		InterruptMask get_EMR_MR19() const { return registers.EMR.Fields.MR19; }
		InterruptMask get_EMR_MR20() const { return registers.EMR.Fields.MR20; }
		InterruptMask get_EMR_MR21() const { return registers.EMR.Fields.MR21; }
		InterruptMask get_EMR_MR22() const { return registers.EMR.Fields.MR22; }
		void set_EMR_MR0(InterruptMask value) { registers.EMR.Fields.MR0 = value; }
		void set_EMR_MR1(InterruptMask value) { registers.EMR.Fields.MR1 = value; }
		void set_EMR_MR2(InterruptMask value) { registers.EMR.Fields.MR2 = value; }
		void set_EMR_MR3(InterruptMask value) { registers.EMR.Fields.MR3 = value; }
		void set_EMR_MR4(InterruptMask value) { registers.EMR.Fields.MR4 = value; }
		void set_EMR_MR5(InterruptMask value) { registers.EMR.Fields.MR5 = value; }
		void set_EMR_MR6(InterruptMask value) { registers.EMR.Fields.MR6 = value; }
		void set_EMR_MR7(InterruptMask value) { registers.EMR.Fields.MR7 = value; }
		void set_EMR_MR8(InterruptMask value) { registers.EMR.Fields.MR8 = value; }
		void set_EMR_MR9(InterruptMask value) { registers.EMR.Fields.MR9 = value; }
		void set_EMR_MR10(InterruptMask value) { registers.EMR.Fields.MR10 = value; }
		void set_EMR_MR11(InterruptMask value) { registers.EMR.Fields.MR11 = value; }
		void set_EMR_MR12(InterruptMask value) { registers.EMR.Fields.MR12 = value; }
		void set_EMR_MR13(InterruptMask value) { registers.EMR.Fields.MR13 = value; }
		void set_EMR_MR14(InterruptMask value) { registers.EMR.Fields.MR14 = value; }
		void set_EMR_MR15(InterruptMask value) { registers.EMR.Fields.MR15 = value; }
		void set_EMR_MR16(InterruptMask value) { registers.EMR.Fields.MR16 = value; }
		void set_EMR_MR17(InterruptMask value) { registers.EMR.Fields.MR17 = value; }
		void set_EMR_MR18(InterruptMask value) { registers.EMR.Fields.MR18 = value; }
		void set_EMR_MR19(InterruptMask value) { registers.EMR.Fields.MR19 = value; }
		void set_EMR_MR20(InterruptMask value) { registers.EMR.Fields.MR20 = value; }
		void set_EMR_MR21(InterruptMask value) { registers.EMR.Fields.MR21 = value; }
		void set_EMR_MR22(InterruptMask value) { registers.EMR.Fields.MR22 = value; }

		// RTSR Fields
		EnableFlag get_RTSR_TR0() const { return registers.RTSR.Fields.TR0; }
		EnableFlag get_RTSR_TR1() const { return registers.RTSR.Fields.TR1; }
		EnableFlag get_RTSR_TR2() const { return registers.RTSR.Fields.TR2; }
		EnableFlag get_RTSR_TR3() const { return registers.RTSR.Fields.TR3; }
		EnableFlag get_RTSR_TR4() const { return registers.RTSR.Fields.TR4; }
		EnableFlag get_RTSR_TR5() const { return registers.RTSR.Fields.TR5; }
		EnableFlag get_RTSR_TR6() const { return registers.RTSR.Fields.TR6; }
		EnableFlag get_RTSR_TR7() const { return registers.RTSR.Fields.TR7; }
		EnableFlag get_RTSR_TR8() const { return registers.RTSR.Fields.TR8; }
		EnableFlag get_RTSR_TR9() const { return registers.RTSR.Fields.TR9; }
		EnableFlag get_RTSR_TR10() const { return registers.RTSR.Fields.TR10; }
		EnableFlag get_RTSR_TR11() const { return registers.RTSR.Fields.TR11; }
		EnableFlag get_RTSR_TR12() const { return registers.RTSR.Fields.TR12; }
		EnableFlag get_RTSR_TR13() const { return registers.RTSR.Fields.TR13; }
		EnableFlag get_RTSR_TR14() const { return registers.RTSR.Fields.TR14; }
		EnableFlag get_RTSR_TR15() const { return registers.RTSR.Fields.TR15; }
		EnableFlag get_RTSR_TR16() const { return registers.RTSR.Fields.TR16; }
		EnableFlag get_RTSR_TR17() const { return registers.RTSR.Fields.TR17; }
		EnableFlag get_RTSR_TR18() const { return registers.RTSR.Fields.TR18; }
		EnableFlag get_RTSR_TR19() const { return registers.RTSR.Fields.TR19; }
		EnableFlag get_RTSR_TR20() const { return registers.RTSR.Fields.TR20; }
		EnableFlag get_RTSR_TR21() const { return registers.RTSR.Fields.TR21; }
		EnableFlag get_RTSR_TR22() const { return registers.RTSR.Fields.TR22; }
		void set_RTSR_TR0(EnableFlag value) { registers.RTSR.Fields.TR0 = value; }
		void set_RTSR_TR1(EnableFlag value) { registers.RTSR.Fields.TR1 = value; }
		void set_RTSR_TR2(EnableFlag value) { registers.RTSR.Fields.TR2 = value; }
		void set_RTSR_TR3(EnableFlag value) { registers.RTSR.Fields.TR3 = value; }
		void set_RTSR_TR4(EnableFlag value) { registers.RTSR.Fields.TR4 = value; }
		void set_RTSR_TR5(EnableFlag value) { registers.RTSR.Fields.TR5 = value; }
		void set_RTSR_TR6(EnableFlag value) { registers.RTSR.Fields.TR6 = value; }
		void set_RTSR_TR7(EnableFlag value) { registers.RTSR.Fields.TR7 = value; }
		void set_RTSR_TR8(EnableFlag value) { registers.RTSR.Fields.TR8 = value; }
		void set_RTSR_TR9(EnableFlag value) { registers.RTSR.Fields.TR9 = value; }
		void set_RTSR_TR10(EnableFlag value) { registers.RTSR.Fields.TR10 = value; }
		void set_RTSR_TR11(EnableFlag value) { registers.RTSR.Fields.TR11 = value; }
		void set_RTSR_TR12(EnableFlag value) { registers.RTSR.Fields.TR12 = value; }
		void set_RTSR_TR13(EnableFlag value) { registers.RTSR.Fields.TR13 = value; }
		void set_RTSR_TR14(EnableFlag value) { registers.RTSR.Fields.TR14 = value; }
		void set_RTSR_TR15(EnableFlag value) { registers.RTSR.Fields.TR15 = value; }
		void set_RTSR_TR16(EnableFlag value) { registers.RTSR.Fields.TR16 = value; }
		void set_RTSR_TR17(EnableFlag value) { registers.RTSR.Fields.TR17 = value; }
		void set_RTSR_TR18(EnableFlag value) { registers.RTSR.Fields.TR18 = value; }
		void set_RTSR_TR19(EnableFlag value) { registers.RTSR.Fields.TR19 = value; }
		void set_RTSR_TR20(EnableFlag value) { registers.RTSR.Fields.TR20 = value; }
		void set_RTSR_TR21(EnableFlag value) { registers.RTSR.Fields.TR21 = value; }
		void set_RTSR_TR22(EnableFlag value) { registers.RTSR.Fields.TR22 = value; }

		// FTSR Fields
		EnableFlag get_FTSR_TR0() const { return registers.FTSR.Fields.TR0; }
		EnableFlag get_FTSR_TR1() const { return registers.FTSR.Fields.TR1; }
		EnableFlag get_FTSR_TR2() const { return registers.FTSR.Fields.TR2; }
		EnableFlag get_FTSR_TR3() const { return registers.FTSR.Fields.TR3; }
		EnableFlag get_FTSR_TR4() const { return registers.FTSR.Fields.TR4; }
		EnableFlag get_FTSR_TR5() const { return registers.FTSR.Fields.TR5; }
		EnableFlag get_FTSR_TR6() const { return registers.FTSR.Fields.TR6; }
		EnableFlag get_FTSR_TR7() const { return registers.FTSR.Fields.TR7; }
		EnableFlag get_FTSR_TR8() const { return registers.FTSR.Fields.TR8; }
		EnableFlag get_FTSR_TR9() const { return registers.FTSR.Fields.TR9; }
		EnableFlag get_FTSR_TR10() const { return registers.FTSR.Fields.TR10; }
		EnableFlag get_FTSR_TR11() const { return registers.FTSR.Fields.TR11; }
		EnableFlag get_FTSR_TR12() const { return registers.FTSR.Fields.TR12; }
		EnableFlag get_FTSR_TR13() const { return registers.FTSR.Fields.TR13; }
		EnableFlag get_FTSR_TR14() const { return registers.FTSR.Fields.TR14; }
		EnableFlag get_FTSR_TR15() const { return registers.FTSR.Fields.TR15; }
		EnableFlag get_FTSR_TR16() const { return registers.FTSR.Fields.TR16; }
		EnableFlag get_FTSR_TR17() const { return registers.FTSR.Fields.TR17; }
		EnableFlag get_FTSR_TR18() const { return registers.FTSR.Fields.TR18; }
		EnableFlag get_FTSR_TR19() const { return registers.FTSR.Fields.TR19; }
		EnableFlag get_FTSR_TR20() const { return registers.FTSR.Fields.TR20; }
		EnableFlag get_FTSR_TR21() const { return registers.FTSR.Fields.TR21; }
		EnableFlag get_FTSR_TR22() const { return registers.FTSR.Fields.TR22; }
		void set_FTSR_TR0(EnableFlag value) { registers.FTSR.Fields.TR0 = value; }
		void set_FTSR_TR1(EnableFlag value) { registers.FTSR.Fields.TR1 = value; }
		void set_FTSR_TR2(EnableFlag value) { registers.FTSR.Fields.TR2 = value; }
		void set_FTSR_TR3(EnableFlag value) { registers.FTSR.Fields.TR3 = value; }
		void set_FTSR_TR4(EnableFlag value) { registers.FTSR.Fields.TR4 = value; }
		void set_FTSR_TR5(EnableFlag value) { registers.FTSR.Fields.TR5 = value; }
		void set_FTSR_TR6(EnableFlag value) { registers.FTSR.Fields.TR6 = value; }
		void set_FTSR_TR7(EnableFlag value) { registers.FTSR.Fields.TR7 = value; }
		void set_FTSR_TR8(EnableFlag value) { registers.FTSR.Fields.TR8 = value; }
		void set_FTSR_TR9(EnableFlag value) { registers.FTSR.Fields.TR9 = value; }
		void set_FTSR_TR10(EnableFlag value) { registers.FTSR.Fields.TR10 = value; }
		void set_FTSR_TR11(EnableFlag value) { registers.FTSR.Fields.TR11 = value; }
		void set_FTSR_TR12(EnableFlag value) { registers.FTSR.Fields.TR12 = value; }
		void set_FTSR_TR13(EnableFlag value) { registers.FTSR.Fields.TR13 = value; }
		void set_FTSR_TR14(EnableFlag value) { registers.FTSR.Fields.TR14 = value; }
		void set_FTSR_TR15(EnableFlag value) { registers.FTSR.Fields.TR15 = value; }
		void set_FTSR_TR16(EnableFlag value) { registers.FTSR.Fields.TR16 = value; }
		void set_FTSR_TR17(EnableFlag value) { registers.FTSR.Fields.TR17 = value; }
		void set_FTSR_TR18(EnableFlag value) { registers.FTSR.Fields.TR18 = value; }
		void set_FTSR_TR19(EnableFlag value) { registers.FTSR.Fields.TR19 = value; }
		void set_FTSR_TR20(EnableFlag value) { registers.FTSR.Fields.TR20 = value; }
		void set_FTSR_TR21(EnableFlag value) { registers.FTSR.Fields.TR21 = value; }
		void set_FTSR_TR22(EnableFlag value) { registers.FTSR.Fields.TR22 = value; }

		// SWIER Fields
		SoftwareInterrupt get_SWIER_SWIER0() const { return registers.SWIER.Fields.SWIER0; }
		SoftwareInterrupt get_SWIER_SWIER1() const { return registers.SWIER.Fields.SWIER1; }
		SoftwareInterrupt get_SWIER_SWIER2() const { return registers.SWIER.Fields.SWIER2; }
		SoftwareInterrupt get_SWIER_SWIER3() const { return registers.SWIER.Fields.SWIER3; }
		SoftwareInterrupt get_SWIER_SWIER4() const { return registers.SWIER.Fields.SWIER4; }
		SoftwareInterrupt get_SWIER_SWIER5() const { return registers.SWIER.Fields.SWIER5; }
		SoftwareInterrupt get_SWIER_SWIER6() const { return registers.SWIER.Fields.SWIER6; }
		SoftwareInterrupt get_SWIER_SWIER7() const { return registers.SWIER.Fields.SWIER7; }
		SoftwareInterrupt get_SWIER_SWIER8() const { return registers.SWIER.Fields.SWIER8; }
		SoftwareInterrupt get_SWIER_SWIER9() const { return registers.SWIER.Fields.SWIER9; }
		SoftwareInterrupt get_SWIER_SWIER10() const { return registers.SWIER.Fields.SWIER10; }
		SoftwareInterrupt get_SWIER_SWIER11() const { return registers.SWIER.Fields.SWIER11; }
		SoftwareInterrupt get_SWIER_SWIER12() const { return registers.SWIER.Fields.SWIER12; }
		SoftwareInterrupt get_SWIER_SWIER13() const { return registers.SWIER.Fields.SWIER13; }
		SoftwareInterrupt get_SWIER_SWIER14() const { return registers.SWIER.Fields.SWIER14; }
		SoftwareInterrupt get_SWIER_SWIER15() const { return registers.SWIER.Fields.SWIER15; }
		SoftwareInterrupt get_SWIER_SWIER16() const { return registers.SWIER.Fields.SWIER16; }
		SoftwareInterrupt get_SWIER_SWIER17() const { return registers.SWIER.Fields.SWIER17; }
		SoftwareInterrupt get_SWIER_SWIER18() const { return registers.SWIER.Fields.SWIER18; }
		SoftwareInterrupt get_SWIER_SWIER19() const { return registers.SWIER.Fields.SWIER19; }
		SoftwareInterrupt get_SWIER_SWIER20() const { return registers.SWIER.Fields.SWIER20; }
		SoftwareInterrupt get_SWIER_SWIER21() const { return registers.SWIER.Fields.SWIER21; }
		SoftwareInterrupt get_SWIER_SWIER22() const { return registers.SWIER.Fields.SWIER22; }
		void set_SWIER_SWIER0(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER0 = value; }
		void set_SWIER_SWIER1(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER1 = value; }
		void set_SWIER_SWIER2(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER2 = value; }
		void set_SWIER_SWIER3(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER3 = value; }
		void set_SWIER_SWIER4(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER4 = value; }
		void set_SWIER_SWIER5(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER5 = value; }
		void set_SWIER_SWIER6(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER6 = value; }
		void set_SWIER_SWIER7(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER7 = value; }
		void set_SWIER_SWIER8(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER8 = value; }
		void set_SWIER_SWIER9(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER9 = value; }
		void set_SWIER_SWIER10(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER10 = value; }
		void set_SWIER_SWIER11(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER11 = value; }
		void set_SWIER_SWIER12(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER12 = value; }
		void set_SWIER_SWIER13(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER13 = value; }
		void set_SWIER_SWIER14(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER14 = value; }
		void set_SWIER_SWIER15(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER15 = value; }
		void set_SWIER_SWIER16(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER16 = value; }
		void set_SWIER_SWIER17(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER17 = value; }
		void set_SWIER_SWIER18(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER18 = value; }
		void set_SWIER_SWIER19(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER19 = value; }
		void set_SWIER_SWIER20(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER20 = value; }
		void set_SWIER_SWIER21(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER21 = value; }
		void set_SWIER_SWIER22(SoftwareInterrupt value) { registers.SWIER.Fields.SWIER22 = value; }

		// PR Fields
		PendingBit get_PR_PR0() const { return registers.PR.Fields.PR0; }
		PendingBit get_PR_PR1() const { return registers.PR.Fields.PR1; }
		PendingBit get_PR_PR2() const { return registers.PR.Fields.PR2; }
		PendingBit get_PR_PR3() const { return registers.PR.Fields.PR3; }
		PendingBit get_PR_PR4() const { return registers.PR.Fields.PR4; }
		PendingBit get_PR_PR5() const { return registers.PR.Fields.PR5; }
		PendingBit get_PR_PR6() const { return registers.PR.Fields.PR6; }
		PendingBit get_PR_PR7() const { return registers.PR.Fields.PR7; }
		PendingBit get_PR_PR8() const { return registers.PR.Fields.PR8; }
		PendingBit get_PR_PR9() const { return registers.PR.Fields.PR9; }
		PendingBit get_PR_PR10() const { return registers.PR.Fields.PR10; }
		PendingBit get_PR_PR11() const { return registers.PR.Fields.PR11; }
		PendingBit get_PR_PR12() const { return registers.PR.Fields.PR12; }
		PendingBit get_PR_PR13() const { return registers.PR.Fields.PR13; }
		PendingBit get_PR_PR14() const { return registers.PR.Fields.PR14; }
		PendingBit get_PR_PR15() const { return registers.PR.Fields.PR15; }
		PendingBit get_PR_PR16() const { return registers.PR.Fields.PR16; }
		PendingBit get_PR_PR17() const { return registers.PR.Fields.PR17; }
		PendingBit get_PR_PR18() const { return registers.PR.Fields.PR18; }
		PendingBit get_PR_PR19() const { return registers.PR.Fields.PR19; }
		PendingBit get_PR_PR20() const { return registers.PR.Fields.PR20; }
		PendingBit get_PR_PR21() const { return registers.PR.Fields.PR21; }
		PendingBit get_PR_PR22() const { return registers.PR.Fields.PR22; }
		void set_PR_PR0(PendingBit value) { registers.PR.Fields.PR0 = value; }
		void set_PR_PR1(PendingBit value) { registers.PR.Fields.PR1 = value; }
		void set_PR_PR2(PendingBit value) { registers.PR.Fields.PR2 = value; }
		void set_PR_PR3(PendingBit value) { registers.PR.Fields.PR3 = value; }
		void set_PR_PR4(PendingBit value) { registers.PR.Fields.PR4 = value; }
		void set_PR_PR5(PendingBit value) { registers.PR.Fields.PR5 = value; }
		void set_PR_PR6(PendingBit value) { registers.PR.Fields.PR6 = value; }
		void set_PR_PR7(PendingBit value) { registers.PR.Fields.PR7 = value; }
		void set_PR_PR8(PendingBit value) { registers.PR.Fields.PR8 = value; }
		void set_PR_PR9(PendingBit value) { registers.PR.Fields.PR9 = value; }
		void set_PR_PR10(PendingBit value) { registers.PR.Fields.PR10 = value; }
		void set_PR_PR11(PendingBit value) { registers.PR.Fields.PR11 = value; }
		void set_PR_PR12(PendingBit value) { registers.PR.Fields.PR12 = value; }
		void set_PR_PR13(PendingBit value) { registers.PR.Fields.PR13 = value; }
		void set_PR_PR14(PendingBit value) { registers.PR.Fields.PR14 = value; }
		void set_PR_PR15(PendingBit value) { registers.PR.Fields.PR15 = value; }
		void set_PR_PR16(PendingBit value) { registers.PR.Fields.PR16 = value; }
		void set_PR_PR17(PendingBit value) { registers.PR.Fields.PR17 = value; }
		void set_PR_PR18(PendingBit value) { registers.PR.Fields.PR18 = value; }
		void set_PR_PR19(PendingBit value) { registers.PR.Fields.PR19 = value; }
		void set_PR_PR20(PendingBit value) { registers.PR.Fields.PR20 = value; }
		void set_PR_PR21(PendingBit value) { registers.PR.Fields.PR21 = value; }
		void set_PR_PR22(PendingBit value) { registers.PR.Fields.PR22 = value; }

	private:

		ExtiRegisters & registers;
	};
}
#endif // EXTI_REGISTER_MAP_HPP_