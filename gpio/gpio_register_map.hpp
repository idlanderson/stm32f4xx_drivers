#ifndef GPIO_REGISTER_MAP_HPP_
#define GPIO_REGISTER_MAP_HPP_

#include <cstdint>
#include "gpio_types.hpp"

using namespace std;

namespace stm32::gpio
{
	union MODER_t
	{
		volatile struct
		{
			Mode MODER0      : 2; // [0:1]   rw : Port Mode for Pin 0
			Mode MODER1      : 2; // [2:3]   rw : Port Mode for Pin 1
			Mode MODER2      : 2; // [4:5]   rw : Port Mode for Pin 2
			Mode MODER3      : 2; // [6:7]   rw : Port Mode for Pin 3
			Mode MODER4      : 2; // [8:9]   rw : Port Mode for Pin 4
			Mode MODER5      : 2; // [10:11] rw : Port Mode for Pin 5
			Mode MODER6      : 2; // [12:13] rw : Port Mode for Pin 6
			Mode MODER7      : 2; // [14:15] rw : Port Mode for Pin 7
			Mode MODER8      : 2; // [16:17] rw : Port Mode for Pin 8
			Mode MODER9      : 2; // [18:19] rw : Port Mode for Pin 9
			Mode MODER10     : 2; // [20:21] rw : Port Mode for Pin 10
			Mode MODER11     : 2; // [22:23] rw : Port Mode for Pin 11
			Mode MODER12     : 2; // [24:25] rw : Port Mode for Pin 12
			Mode MODER13     : 2; // [26:27] rw : Port Mode for Pin 13
			Mode MODER14     : 2; // [28:29] rw : Port Mode for Pin 14
			Mode MODER15     : 2; // [30:31] rw : Port Mode for Pin 15
		} Fields;
		volatile uint32_t Value;
	};

	union OTYPER_t
	{
		volatile struct
		{
			OutputType OT0         : 1; // [0]     rw : Output Type for Pin 0
			OutputType OT1         : 1; // [1]     rw : Output Type for Pin 1
			OutputType OT2         : 1; // [2]     rw : Output Type for Pin 2
			OutputType OT3         : 1; // [3]     rw : Output Type for Pin 3
			OutputType OT4         : 1; // [4]     rw : Output Type for Pin 4
			OutputType OT5         : 1; // [5]     rw : Output Type for Pin 5
			OutputType OT6         : 1; // [6]     rw : Output Type for Pin 6
			OutputType OT7         : 1; // [7]     rw : Output Type for Pin 7
			OutputType OT8         : 1; // [8]     rw : Output Type for Pin 8
			OutputType OT9         : 1; // [9]     rw : Output Type for Pin 9
			OutputType OT10        : 1; // [10]    rw : Output Type for Pin 10
			OutputType OT11        : 1; // [11]    rw : Output Type for Pin 11
			OutputType OT12        : 1; // [12]    rw : Output Type for Pin 12
			OutputType OT13        : 1; // [13]    rw : Output Type for Pin 13
			OutputType OT14        : 1; // [14]    rw : Output Type for Pin 14
			OutputType OT15        : 1; // [15]    rw : Output Type for Pin 15
			Reserved   Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union OSPEEDR_t
	{
		volatile struct
		{
			Speed OSPEEDR0    : 2; // [0:1]   rw : Output Speed for Pin 0
			Speed OSPEEDR1    : 2; // [2:3]   rw : Output Speed for Pin 1
			Speed OSPEEDR2    : 2; // [4:5]   rw : Output Speed for Pin 2
			Speed OSPEEDR3    : 2; // [6:7]   rw : Output Speed for Pin 3
			Speed OSPEEDR4    : 2; // [8:9]   rw : Output Speed for Pin 4
			Speed OSPEEDR5    : 2; // [10:11] rw : Output Speed for Pin 5
			Speed OSPEEDR6    : 2; // [12:13] rw : Output Speed for Pin 6
			Speed OSPEEDR7    : 2; // [14:15] rw : Output Speed for Pin 7
			Speed OSPEEDR8    : 2; // [16:17] rw : Output Speed for Pin 8
			Speed OSPEEDR9    : 2; // [18:19] rw : Output Speed for Pin 9
			Speed OSPEEDR10   : 2; // [20:21] rw : Output Speed for Pin 10
			Speed OSPEEDR11   : 2; // [22:23] rw : Output Speed for Pin 11
			Speed OSPEEDR12   : 2; // [24:25] rw : Output Speed for Pin 12
			Speed OSPEEDR13   : 2; // [26:27] rw : Output Speed for Pin 13
			Speed OSPEEDR14   : 2; // [28:29] rw : Output Speed for Pin 14
			Speed OSPEEDR15   : 2; // [30:31] rw : Output Speed for Pin 15
		} Fields;
		volatile uint32_t Value;
	};

	union PUPDR_t
	{
		volatile struct
		{
			PullUpPullDown PUPDR0      : 2; // [0:1]   rw : Pull-Up/Pull Down for Pin 0
			PullUpPullDown PUPDR1      : 2; // [2:3]   rw : Pull-Up/Pull Down for Pin 1
			PullUpPullDown PUPDR2      : 2; // [4:5]   rw : Pull-Up/Pull Down for Pin 2
			PullUpPullDown PUPDR3      : 2; // [6:7]   rw : Pull-Up/Pull Down for Pin 3
			PullUpPullDown PUPDR4      : 2; // [8:9]   rw : Pull-Up/Pull Down for Pin 4
			PullUpPullDown PUPDR5      : 2; // [10:11] rw : Pull-Up/Pull Down for Pin 5
			PullUpPullDown PUPDR6      : 2; // [12:13] rw : Pull-Up/Pull Down for Pin 6
			PullUpPullDown PUPDR7      : 2; // [14:15] rw : Pull-Up/Pull Down for Pin 7
			PullUpPullDown PUPDR8      : 2; // [16:17] rw : Pull-Up/Pull Down for Pin 8
			PullUpPullDown PUPDR9      : 2; // [18:19] rw : Pull-Up/Pull Down for Pin 9
			PullUpPullDown PUPDR10     : 2; // [20:21] rw : Pull-Up/Pull Down for Pin 10
			PullUpPullDown PUPDR11     : 2; // [22:23] rw : Pull-Up/Pull Down for Pin 11
			PullUpPullDown PUPDR12     : 2; // [24:25] rw : Pull-Up/Pull Down for Pin 12
			PullUpPullDown PUPDR13     : 2; // [26:27] rw : Pull-Up/Pull Down for Pin 13
			PullUpPullDown PUPDR14     : 2; // [28:29] rw : Pull-Up/Pull Down for Pin 14
			PullUpPullDown PUPDR15     : 2; // [30:31] rw : Pull-Up/Pull Down for Pin 15
		} Fields;
		volatile uint32_t Value;
	};

	union IDR_t
	{
		volatile struct
		{
			uint32_t IDR0        : 1; // [0]     r  : Input Data for Pin 0
			uint32_t IDR1        : 1; // [1]     r  : Input Data for Pin 1
			uint32_t IDR2        : 1; // [2]     r  : Input Data for Pin 2
			uint32_t IDR3        : 1; // [3]     r  : Input Data for Pin 3
			uint32_t IDR4        : 1; // [4]     r  : Input Data for Pin 4
			uint32_t IDR5        : 1; // [5]     r  : Input Data for Pin 5
			uint32_t IDR6        : 1; // [6]     r  : Input Data for Pin 6
			uint32_t IDR7        : 1; // [7]     r  : Input Data for Pin 7
			uint32_t IDR8        : 1; // [8]     r  : Input Data for Pin 8
			uint32_t IDR9        : 1; // [9]     r  : Input Data for Pin 9
			uint32_t IDR10       : 1; // [10]    r  : Input Data for Pin 10
			uint32_t IDR11       : 1; // [11]    r  : Input Data for Pin 11
			uint32_t IDR12       : 1; // [12]    r  : Input Data for Pin 12
			uint32_t IDR13       : 1; // [13]    r  : Input Data for Pin 13
			uint32_t IDR14       : 1; // [14]    r  : Input Data for Pin 14
			uint32_t IDR15       : 1; // [15]    r  : Input Data for Pin 15
			Reserved Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union ODR_t
	{
		volatile struct
		{
			uint32_t ODR0        : 1; // [0]     rw : Output Data for Pin 0
			uint32_t ODR1        : 1; // [1]     rw : Output Data for Pin 1
			uint32_t ODR2        : 1; // [2]     rw : Output Data for Pin 2
			uint32_t ODR3        : 1; // [3]     rw : Output Data for Pin 3
			uint32_t ODR4        : 1; // [4]     rw : Output Data for Pin 4
			uint32_t ODR5        : 1; // [5]     rw : Output Data for Pin 5
			uint32_t ODR6        : 1; // [6]     rw : Output Data for Pin 6
			uint32_t ODR7        : 1; // [7]     rw : Output Data for Pin 7
			uint32_t ODR8        : 1; // [8]     rw : Output Data for Pin 8
			uint32_t ODR9        : 1; // [9]     rw : Output Data for Pin 9
			uint32_t ODR10       : 1; // [10]    rw : Output Data for Pin 10
			uint32_t ODR11       : 1; // [11]    rw : Output Data for Pin 11
			uint32_t ODR12       : 1; // [12]    rw : Output Data for Pin 12
			uint32_t ODR13       : 1; // [13]    rw : Output Data for Pin 13
			uint32_t ODR14       : 1; // [14]    rw : Output Data for Pin 14
			uint32_t ODR15       : 1; // [15]    rw : Output Data for Pin 15
			Reserved Reserved1   : 16; // [16:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union BSRR_t
	{
		volatile struct
		{
			uint32_t BS0         : 1; // [0]     w  : Port Set Bit 0
			uint32_t BS1         : 1; // [1]     w  : Port Set Bit 1
			uint32_t BS2         : 1; // [2]     w  : Port Set Bit 2
			uint32_t BS3         : 1; // [3]     w  : Port Set Bit 3
			uint32_t BS4         : 1; // [4]     w  : Port Set Bit 4
			uint32_t BS5         : 1; // [5]     w  : Port Set Bit 5
			uint32_t BS6         : 1; // [6]     w  : Port Set Bit 6
			uint32_t BS7         : 1; // [7]     w  : Port Set Bit 7
			uint32_t BS8         : 1; // [8]     w  : Port Set Bit 8
			uint32_t BS9         : 1; // [9]     w  : Port Set Bit 9
			uint32_t BS10        : 1; // [10]    w  : Port Set Bit 10
			uint32_t BS11        : 1; // [11]    w  : Port Set Bit 11
			uint32_t BS12        : 1; // [12]    w  : Port Set Bit 12
			uint32_t BS13        : 1; // [13]    w  : Port Set Bit 13
			uint32_t BS14        : 1; // [14]    w  : Port Set Bit 14
			uint32_t BS15        : 1; // [15]    w  : Port Set Bit 15
			uint32_t BR0         : 1; // [16]    w  : Port Reset Bit 0
			uint32_t BR1         : 1; // [17]    w  : Port Reset Bit 1
			uint32_t BR2         : 1; // [18]    w  : Port Reset Bit 2
			uint32_t BR3         : 1; // [19]    w  : Port Reset Bit 3
			uint32_t BR4         : 1; // [20]    w  : Port Reset Bit 4
			uint32_t BR5         : 1; // [21]    w  : Port Reset Bit 5
			uint32_t BR6         : 1; // [22]    w  : Port Reset Bit 6
			uint32_t BR7         : 1; // [23]    w  : Port Reset Bit 7
			uint32_t BR8         : 1; // [24]    w  : Port Reset Bit 8
			uint32_t BR9         : 1; // [25]    w  : Port Reset Bit 9
			uint32_t BR10        : 1; // [26]    w  : Port Reset Bit 10
			uint32_t BR11        : 1; // [27]    w  : Port Reset Bit 11
			uint32_t BR12        : 1; // [28]    w  : Port Reset Bit 12
			uint32_t BR13        : 1; // [29]    w  : Port Reset Bit 13
			uint32_t BR14        : 1; // [30]    w  : Port Reset Bit 14
			uint32_t BR15        : 1; // [31]    w  : Port Reset Bit 15
		} Fields;
		volatile uint32_t Value;
	};

	union LCKR_t
	{
		volatile struct
		{
			PortConfigurationLock    LCK0        : 1; // [0]     rw : Port Configuration Lock for Bit 0
			PortConfigurationLock    LCK1        : 1; // [1]     rw : Port Configuration Lock for Bit 1
			PortConfigurationLock    LCK2        : 1; // [2]     rw : Port Configuration Lock for Bit 2
			PortConfigurationLock    LCK3        : 1; // [3]     rw : Port Configuration Lock for Bit 3
			PortConfigurationLock    LCK4        : 1; // [4]     rw : Port Configuration Lock for Bit 4
			PortConfigurationLock    LCK5        : 1; // [5]     rw : Port Configuration Lock for Bit 5
			PortConfigurationLock    LCK6        : 1; // [6]     rw : Port Configuration Lock for Bit 6
			PortConfigurationLock    LCK7        : 1; // [7]     rw : Port Configuration Lock for Bit 7
			PortConfigurationLock    LCK8        : 1; // [8]     rw : Port Configuration Lock for Bit 8
			PortConfigurationLock    LCK9        : 1; // [9]     rw : Port Configuration Lock for Bit 9
			PortConfigurationLock    LCK10       : 1; // [10]    rw : Port Configuration Lock for Bit 10
			PortConfigurationLock    LCK11       : 1; // [11]    rw : Port Configuration Lock for Bit 11
			PortConfigurationLock    LCK12       : 1; // [12]    rw : Port Configuration Lock for Bit 12
			PortConfigurationLock    LCK13       : 1; // [13]    rw : Port Configuration Lock for Bit 13
			PortConfigurationLock    LCK14       : 1; // [14]    rw : Port Configuration Lock for Bit 14
			PortConfigurationLock    LCK15       : 1; // [15]    rw : Port Configuration Lock for Bit 15
			PortConfigurationLockKey LCKK        : 1; // [16]    rw : Port Configuration Lock Key
			Reserved                 Reserved1   : 15; // [17:31]    : RESERVED FIELD.
		} Fields;
		volatile uint32_t Value;
	};

	union AFRL_t
	{
		volatile struct
		{
			AlternateFunction AFRL0       : 4; // [0:3]   rw : Alternate Function for Pin 0
			AlternateFunction AFRL1       : 4; // [4:7]   rw : Alternate Function for Pin 1
			AlternateFunction AFRL2       : 4; // [8:11]  rw : Alternate Function for Pin 2
			AlternateFunction AFRL3       : 4; // [12:15] rw : Alternate Function for Pin 3
			AlternateFunction AFRL4       : 4; // [16:19] rw : Alternate Function for Pin 4
			AlternateFunction AFRL5       : 4; // [20:23] rw : Alternate Function for Pin 5
			AlternateFunction AFRL6       : 4; // [24:27] rw : Alternate Function for Pin 6
			AlternateFunction AFRL7       : 4; // [28:31] rw : Alternate Function for Pin 7
		} Fields;
		volatile uint32_t Value;
	};

	union AFRH_t
	{
		volatile struct
		{
			AlternateFunction AFRH8       : 4; // [0:3]   rw : Alternate Function for Pin 8
			AlternateFunction AFRH9       : 4; // [4:7]   rw : Alternate Function for Pin 9
			AlternateFunction AFRH10      : 4; // [8:11]  rw : Alternate Function for Pin 10
			AlternateFunction AFRH11      : 4; // [12:15] rw : Alternate Function for Pin 11
			AlternateFunction AFRH12      : 4; // [16:19] rw : Alternate Function for Pin 12
			AlternateFunction AFRH13      : 4; // [20:23] rw : Alternate Function for Pin 13
			AlternateFunction AFRH14      : 4; // [24:27] rw : Alternate Function for Pin 14
			AlternateFunction AFRH15      : 4; // [28:31] rw : Alternate Function for Pin 15
		} Fields;
		volatile uint32_t Value;
	};

	class GpioRegisterMap
	{
	public:

		// MODER Fields
		Mode get_MODER_MODER0() const { return MODER.Fields.MODER0; }
		Mode get_MODER_MODER1() const { return MODER.Fields.MODER1; }
		Mode get_MODER_MODER2() const { return MODER.Fields.MODER2; }
		Mode get_MODER_MODER3() const { return MODER.Fields.MODER3; }
		Mode get_MODER_MODER4() const { return MODER.Fields.MODER4; }
		Mode get_MODER_MODER5() const { return MODER.Fields.MODER5; }
		Mode get_MODER_MODER6() const { return MODER.Fields.MODER6; }
		Mode get_MODER_MODER7() const { return MODER.Fields.MODER7; }
		Mode get_MODER_MODER8() const { return MODER.Fields.MODER8; }
		Mode get_MODER_MODER9() const { return MODER.Fields.MODER9; }
		Mode get_MODER_MODER10() const { return MODER.Fields.MODER10; }
		Mode get_MODER_MODER11() const { return MODER.Fields.MODER11; }
		Mode get_MODER_MODER12() const { return MODER.Fields.MODER12; }
		Mode get_MODER_MODER13() const { return MODER.Fields.MODER13; }
		Mode get_MODER_MODER14() const { return MODER.Fields.MODER14; }
		Mode get_MODER_MODER15() const { return MODER.Fields.MODER15; }
		void set_MODER_MODER0(Mode value) { MODER.Fields.MODER0 = value; }
		void set_MODER_MODER1(Mode value) { MODER.Fields.MODER1 = value; }
		void set_MODER_MODER2(Mode value) { MODER.Fields.MODER2 = value; }
		void set_MODER_MODER3(Mode value) { MODER.Fields.MODER3 = value; }
		void set_MODER_MODER4(Mode value) { MODER.Fields.MODER4 = value; }
		void set_MODER_MODER5(Mode value) { MODER.Fields.MODER5 = value; }
		void set_MODER_MODER6(Mode value) { MODER.Fields.MODER6 = value; }
		void set_MODER_MODER7(Mode value) { MODER.Fields.MODER7 = value; }
		void set_MODER_MODER8(Mode value) { MODER.Fields.MODER8 = value; }
		void set_MODER_MODER9(Mode value) { MODER.Fields.MODER9 = value; }
		void set_MODER_MODER10(Mode value) { MODER.Fields.MODER10 = value; }
		void set_MODER_MODER11(Mode value) { MODER.Fields.MODER11 = value; }
		void set_MODER_MODER12(Mode value) { MODER.Fields.MODER12 = value; }
		void set_MODER_MODER13(Mode value) { MODER.Fields.MODER13 = value; }
		void set_MODER_MODER14(Mode value) { MODER.Fields.MODER14 = value; }
		void set_MODER_MODER15(Mode value) { MODER.Fields.MODER15 = value; }

		// OTYPER Fields
		OutputType get_OTYPER_OT0() const { return OTYPER.Fields.OT0; }
		OutputType get_OTYPER_OT1() const { return OTYPER.Fields.OT1; }
		OutputType get_OTYPER_OT2() const { return OTYPER.Fields.OT2; }
		OutputType get_OTYPER_OT3() const { return OTYPER.Fields.OT3; }
		OutputType get_OTYPER_OT4() const { return OTYPER.Fields.OT4; }
		OutputType get_OTYPER_OT5() const { return OTYPER.Fields.OT5; }
		OutputType get_OTYPER_OT6() const { return OTYPER.Fields.OT6; }
		OutputType get_OTYPER_OT7() const { return OTYPER.Fields.OT7; }
		OutputType get_OTYPER_OT8() const { return OTYPER.Fields.OT8; }
		OutputType get_OTYPER_OT9() const { return OTYPER.Fields.OT9; }
		OutputType get_OTYPER_OT10() const { return OTYPER.Fields.OT10; }
		OutputType get_OTYPER_OT11() const { return OTYPER.Fields.OT11; }
		OutputType get_OTYPER_OT12() const { return OTYPER.Fields.OT12; }
		OutputType get_OTYPER_OT13() const { return OTYPER.Fields.OT13; }
		OutputType get_OTYPER_OT14() const { return OTYPER.Fields.OT14; }
		OutputType get_OTYPER_OT15() const { return OTYPER.Fields.OT15; }
		void set_OTYPER_OT0(OutputType value) { OTYPER.Fields.OT0 = value; }
		void set_OTYPER_OT1(OutputType value) { OTYPER.Fields.OT1 = value; }
		void set_OTYPER_OT2(OutputType value) { OTYPER.Fields.OT2 = value; }
		void set_OTYPER_OT3(OutputType value) { OTYPER.Fields.OT3 = value; }
		void set_OTYPER_OT4(OutputType value) { OTYPER.Fields.OT4 = value; }
		void set_OTYPER_OT5(OutputType value) { OTYPER.Fields.OT5 = value; }
		void set_OTYPER_OT6(OutputType value) { OTYPER.Fields.OT6 = value; }
		void set_OTYPER_OT7(OutputType value) { OTYPER.Fields.OT7 = value; }
		void set_OTYPER_OT8(OutputType value) { OTYPER.Fields.OT8 = value; }
		void set_OTYPER_OT9(OutputType value) { OTYPER.Fields.OT9 = value; }
		void set_OTYPER_OT10(OutputType value) { OTYPER.Fields.OT10 = value; }
		void set_OTYPER_OT11(OutputType value) { OTYPER.Fields.OT11 = value; }
		void set_OTYPER_OT12(OutputType value) { OTYPER.Fields.OT12 = value; }
		void set_OTYPER_OT13(OutputType value) { OTYPER.Fields.OT13 = value; }
		void set_OTYPER_OT14(OutputType value) { OTYPER.Fields.OT14 = value; }
		void set_OTYPER_OT15(OutputType value) { OTYPER.Fields.OT15 = value; }

		// OSPEEDR Fields
		Speed get_OSPEEDR_OSPEEDR0() const { return OSPEEDR.Fields.OSPEEDR0; }
		Speed get_OSPEEDR_OSPEEDR1() const { return OSPEEDR.Fields.OSPEEDR1; }
		Speed get_OSPEEDR_OSPEEDR2() const { return OSPEEDR.Fields.OSPEEDR2; }
		Speed get_OSPEEDR_OSPEEDR3() const { return OSPEEDR.Fields.OSPEEDR3; }
		Speed get_OSPEEDR_OSPEEDR4() const { return OSPEEDR.Fields.OSPEEDR4; }
		Speed get_OSPEEDR_OSPEEDR5() const { return OSPEEDR.Fields.OSPEEDR5; }
		Speed get_OSPEEDR_OSPEEDR6() const { return OSPEEDR.Fields.OSPEEDR6; }
		Speed get_OSPEEDR_OSPEEDR7() const { return OSPEEDR.Fields.OSPEEDR7; }
		Speed get_OSPEEDR_OSPEEDR8() const { return OSPEEDR.Fields.OSPEEDR8; }
		Speed get_OSPEEDR_OSPEEDR9() const { return OSPEEDR.Fields.OSPEEDR9; }
		Speed get_OSPEEDR_OSPEEDR10() const { return OSPEEDR.Fields.OSPEEDR10; }
		Speed get_OSPEEDR_OSPEEDR11() const { return OSPEEDR.Fields.OSPEEDR11; }
		Speed get_OSPEEDR_OSPEEDR12() const { return OSPEEDR.Fields.OSPEEDR12; }
		Speed get_OSPEEDR_OSPEEDR13() const { return OSPEEDR.Fields.OSPEEDR13; }
		Speed get_OSPEEDR_OSPEEDR14() const { return OSPEEDR.Fields.OSPEEDR14; }
		Speed get_OSPEEDR_OSPEEDR15() const { return OSPEEDR.Fields.OSPEEDR15; }
		void set_OSPEEDR_OSPEEDR0(Speed value) { OSPEEDR.Fields.OSPEEDR0 = value; }
		void set_OSPEEDR_OSPEEDR1(Speed value) { OSPEEDR.Fields.OSPEEDR1 = value; }
		void set_OSPEEDR_OSPEEDR2(Speed value) { OSPEEDR.Fields.OSPEEDR2 = value; }
		void set_OSPEEDR_OSPEEDR3(Speed value) { OSPEEDR.Fields.OSPEEDR3 = value; }
		void set_OSPEEDR_OSPEEDR4(Speed value) { OSPEEDR.Fields.OSPEEDR4 = value; }
		void set_OSPEEDR_OSPEEDR5(Speed value) { OSPEEDR.Fields.OSPEEDR5 = value; }
		void set_OSPEEDR_OSPEEDR6(Speed value) { OSPEEDR.Fields.OSPEEDR6 = value; }
		void set_OSPEEDR_OSPEEDR7(Speed value) { OSPEEDR.Fields.OSPEEDR7 = value; }
		void set_OSPEEDR_OSPEEDR8(Speed value) { OSPEEDR.Fields.OSPEEDR8 = value; }
		void set_OSPEEDR_OSPEEDR9(Speed value) { OSPEEDR.Fields.OSPEEDR9 = value; }
		void set_OSPEEDR_OSPEEDR10(Speed value) { OSPEEDR.Fields.OSPEEDR10 = value; }
		void set_OSPEEDR_OSPEEDR11(Speed value) { OSPEEDR.Fields.OSPEEDR11 = value; }
		void set_OSPEEDR_OSPEEDR12(Speed value) { OSPEEDR.Fields.OSPEEDR12 = value; }
		void set_OSPEEDR_OSPEEDR13(Speed value) { OSPEEDR.Fields.OSPEEDR13 = value; }
		void set_OSPEEDR_OSPEEDR14(Speed value) { OSPEEDR.Fields.OSPEEDR14 = value; }
		void set_OSPEEDR_OSPEEDR15(Speed value) { OSPEEDR.Fields.OSPEEDR15 = value; }

		// PUPDR Fields
		PullUpPullDown get_PUPDR_PUPDR0() const { return PUPDR.Fields.PUPDR0; }
		PullUpPullDown get_PUPDR_PUPDR1() const { return PUPDR.Fields.PUPDR1; }
		PullUpPullDown get_PUPDR_PUPDR2() const { return PUPDR.Fields.PUPDR2; }
		PullUpPullDown get_PUPDR_PUPDR3() const { return PUPDR.Fields.PUPDR3; }
		PullUpPullDown get_PUPDR_PUPDR4() const { return PUPDR.Fields.PUPDR4; }
		PullUpPullDown get_PUPDR_PUPDR5() const { return PUPDR.Fields.PUPDR5; }
		PullUpPullDown get_PUPDR_PUPDR6() const { return PUPDR.Fields.PUPDR6; }
		PullUpPullDown get_PUPDR_PUPDR7() const { return PUPDR.Fields.PUPDR7; }
		PullUpPullDown get_PUPDR_PUPDR8() const { return PUPDR.Fields.PUPDR8; }
		PullUpPullDown get_PUPDR_PUPDR9() const { return PUPDR.Fields.PUPDR9; }
		PullUpPullDown get_PUPDR_PUPDR10() const { return PUPDR.Fields.PUPDR10; }
		PullUpPullDown get_PUPDR_PUPDR11() const { return PUPDR.Fields.PUPDR11; }
		PullUpPullDown get_PUPDR_PUPDR12() const { return PUPDR.Fields.PUPDR12; }
		PullUpPullDown get_PUPDR_PUPDR13() const { return PUPDR.Fields.PUPDR13; }
		PullUpPullDown get_PUPDR_PUPDR14() const { return PUPDR.Fields.PUPDR14; }
		PullUpPullDown get_PUPDR_PUPDR15() const { return PUPDR.Fields.PUPDR15; }
		void set_PUPDR_PUPDR0(PullUpPullDown value) { PUPDR.Fields.PUPDR0 = value; }
		void set_PUPDR_PUPDR1(PullUpPullDown value) { PUPDR.Fields.PUPDR1 = value; }
		void set_PUPDR_PUPDR2(PullUpPullDown value) { PUPDR.Fields.PUPDR2 = value; }
		void set_PUPDR_PUPDR3(PullUpPullDown value) { PUPDR.Fields.PUPDR3 = value; }
		void set_PUPDR_PUPDR4(PullUpPullDown value) { PUPDR.Fields.PUPDR4 = value; }
		void set_PUPDR_PUPDR5(PullUpPullDown value) { PUPDR.Fields.PUPDR5 = value; }
		void set_PUPDR_PUPDR6(PullUpPullDown value) { PUPDR.Fields.PUPDR6 = value; }
		void set_PUPDR_PUPDR7(PullUpPullDown value) { PUPDR.Fields.PUPDR7 = value; }
		void set_PUPDR_PUPDR8(PullUpPullDown value) { PUPDR.Fields.PUPDR8 = value; }
		void set_PUPDR_PUPDR9(PullUpPullDown value) { PUPDR.Fields.PUPDR9 = value; }
		void set_PUPDR_PUPDR10(PullUpPullDown value) { PUPDR.Fields.PUPDR10 = value; }
		void set_PUPDR_PUPDR11(PullUpPullDown value) { PUPDR.Fields.PUPDR11 = value; }
		void set_PUPDR_PUPDR12(PullUpPullDown value) { PUPDR.Fields.PUPDR12 = value; }
		void set_PUPDR_PUPDR13(PullUpPullDown value) { PUPDR.Fields.PUPDR13 = value; }
		void set_PUPDR_PUPDR14(PullUpPullDown value) { PUPDR.Fields.PUPDR14 = value; }
		void set_PUPDR_PUPDR15(PullUpPullDown value) { PUPDR.Fields.PUPDR15 = value; }

		// IDR Fields
		uint32_t get_IDR_IDR0() const { return IDR.Fields.IDR0; }
		uint32_t get_IDR_IDR1() const { return IDR.Fields.IDR1; }
		uint32_t get_IDR_IDR2() const { return IDR.Fields.IDR2; }
		uint32_t get_IDR_IDR3() const { return IDR.Fields.IDR3; }
		uint32_t get_IDR_IDR4() const { return IDR.Fields.IDR4; }
		uint32_t get_IDR_IDR5() const { return IDR.Fields.IDR5; }
		uint32_t get_IDR_IDR6() const { return IDR.Fields.IDR6; }
		uint32_t get_IDR_IDR7() const { return IDR.Fields.IDR7; }
		uint32_t get_IDR_IDR8() const { return IDR.Fields.IDR8; }
		uint32_t get_IDR_IDR9() const { return IDR.Fields.IDR9; }
		uint32_t get_IDR_IDR10() const { return IDR.Fields.IDR10; }
		uint32_t get_IDR_IDR11() const { return IDR.Fields.IDR11; }
		uint32_t get_IDR_IDR12() const { return IDR.Fields.IDR12; }
		uint32_t get_IDR_IDR13() const { return IDR.Fields.IDR13; }
		uint32_t get_IDR_IDR14() const { return IDR.Fields.IDR14; }
		uint32_t get_IDR_IDR15() const { return IDR.Fields.IDR15; }

		// ODR Fields
		uint32_t get_ODR_ODR0() const { return ODR.Fields.ODR0; }
		uint32_t get_ODR_ODR1() const { return ODR.Fields.ODR1; }
		uint32_t get_ODR_ODR2() const { return ODR.Fields.ODR2; }
		uint32_t get_ODR_ODR3() const { return ODR.Fields.ODR3; }
		uint32_t get_ODR_ODR4() const { return ODR.Fields.ODR4; }
		uint32_t get_ODR_ODR5() const { return ODR.Fields.ODR5; }
		uint32_t get_ODR_ODR6() const { return ODR.Fields.ODR6; }
		uint32_t get_ODR_ODR7() const { return ODR.Fields.ODR7; }
		uint32_t get_ODR_ODR8() const { return ODR.Fields.ODR8; }
		uint32_t get_ODR_ODR9() const { return ODR.Fields.ODR9; }
		uint32_t get_ODR_ODR10() const { return ODR.Fields.ODR10; }
		uint32_t get_ODR_ODR11() const { return ODR.Fields.ODR11; }
		uint32_t get_ODR_ODR12() const { return ODR.Fields.ODR12; }
		uint32_t get_ODR_ODR13() const { return ODR.Fields.ODR13; }
		uint32_t get_ODR_ODR14() const { return ODR.Fields.ODR14; }
		uint32_t get_ODR_ODR15() const { return ODR.Fields.ODR15; }
		void set_ODR_ODR0(uint32_t value) { ODR.Fields.ODR0 = value; }
		void set_ODR_ODR1(uint32_t value) { ODR.Fields.ODR1 = value; }
		void set_ODR_ODR2(uint32_t value) { ODR.Fields.ODR2 = value; }
		void set_ODR_ODR3(uint32_t value) { ODR.Fields.ODR3 = value; }
		void set_ODR_ODR4(uint32_t value) { ODR.Fields.ODR4 = value; }
		void set_ODR_ODR5(uint32_t value) { ODR.Fields.ODR5 = value; }
		void set_ODR_ODR6(uint32_t value) { ODR.Fields.ODR6 = value; }
		void set_ODR_ODR7(uint32_t value) { ODR.Fields.ODR7 = value; }
		void set_ODR_ODR8(uint32_t value) { ODR.Fields.ODR8 = value; }
		void set_ODR_ODR9(uint32_t value) { ODR.Fields.ODR9 = value; }
		void set_ODR_ODR10(uint32_t value) { ODR.Fields.ODR10 = value; }
		void set_ODR_ODR11(uint32_t value) { ODR.Fields.ODR11 = value; }
		void set_ODR_ODR12(uint32_t value) { ODR.Fields.ODR12 = value; }
		void set_ODR_ODR13(uint32_t value) { ODR.Fields.ODR13 = value; }
		void set_ODR_ODR14(uint32_t value) { ODR.Fields.ODR14 = value; }
		void set_ODR_ODR15(uint32_t value) { ODR.Fields.ODR15 = value; }

		// BSRR Fields
		void set_BSRR_BS0(uint32_t value) { BSRR.Fields.BS0 = value; }
		void set_BSRR_BS1(uint32_t value) { BSRR.Fields.BS1 = value; }
		void set_BSRR_BS2(uint32_t value) { BSRR.Fields.BS2 = value; }
		void set_BSRR_BS3(uint32_t value) { BSRR.Fields.BS3 = value; }
		void set_BSRR_BS4(uint32_t value) { BSRR.Fields.BS4 = value; }
		void set_BSRR_BS5(uint32_t value) { BSRR.Fields.BS5 = value; }
		void set_BSRR_BS6(uint32_t value) { BSRR.Fields.BS6 = value; }
		void set_BSRR_BS7(uint32_t value) { BSRR.Fields.BS7 = value; }
		void set_BSRR_BS8(uint32_t value) { BSRR.Fields.BS8 = value; }
		void set_BSRR_BS9(uint32_t value) { BSRR.Fields.BS9 = value; }
		void set_BSRR_BS10(uint32_t value) { BSRR.Fields.BS10 = value; }
		void set_BSRR_BS11(uint32_t value) { BSRR.Fields.BS11 = value; }
		void set_BSRR_BS12(uint32_t value) { BSRR.Fields.BS12 = value; }
		void set_BSRR_BS13(uint32_t value) { BSRR.Fields.BS13 = value; }
		void set_BSRR_BS14(uint32_t value) { BSRR.Fields.BS14 = value; }
		void set_BSRR_BS15(uint32_t value) { BSRR.Fields.BS15 = value; }
		void set_BSRR_BR0(uint32_t value) { BSRR.Fields.BR0 = value; }
		void set_BSRR_BR1(uint32_t value) { BSRR.Fields.BR1 = value; }
		void set_BSRR_BR2(uint32_t value) { BSRR.Fields.BR2 = value; }
		void set_BSRR_BR3(uint32_t value) { BSRR.Fields.BR3 = value; }
		void set_BSRR_BR4(uint32_t value) { BSRR.Fields.BR4 = value; }
		void set_BSRR_BR5(uint32_t value) { BSRR.Fields.BR5 = value; }
		void set_BSRR_BR6(uint32_t value) { BSRR.Fields.BR6 = value; }
		void set_BSRR_BR7(uint32_t value) { BSRR.Fields.BR7 = value; }
		void set_BSRR_BR8(uint32_t value) { BSRR.Fields.BR8 = value; }
		void set_BSRR_BR9(uint32_t value) { BSRR.Fields.BR9 = value; }
		void set_BSRR_BR10(uint32_t value) { BSRR.Fields.BR10 = value; }
		void set_BSRR_BR11(uint32_t value) { BSRR.Fields.BR11 = value; }
		void set_BSRR_BR12(uint32_t value) { BSRR.Fields.BR12 = value; }
		void set_BSRR_BR13(uint32_t value) { BSRR.Fields.BR13 = value; }
		void set_BSRR_BR14(uint32_t value) { BSRR.Fields.BR14 = value; }
		void set_BSRR_BR15(uint32_t value) { BSRR.Fields.BR15 = value; }

		// LCKR Fields
		PortConfigurationLock get_LCKR_LCK0() const { return LCKR.Fields.LCK0; }
		PortConfigurationLock get_LCKR_LCK1() const { return LCKR.Fields.LCK1; }
		PortConfigurationLock get_LCKR_LCK2() const { return LCKR.Fields.LCK2; }
		PortConfigurationLock get_LCKR_LCK3() const { return LCKR.Fields.LCK3; }
		PortConfigurationLock get_LCKR_LCK4() const { return LCKR.Fields.LCK4; }
		PortConfigurationLock get_LCKR_LCK5() const { return LCKR.Fields.LCK5; }
		PortConfigurationLock get_LCKR_LCK6() const { return LCKR.Fields.LCK6; }
		PortConfigurationLock get_LCKR_LCK7() const { return LCKR.Fields.LCK7; }
		PortConfigurationLock get_LCKR_LCK8() const { return LCKR.Fields.LCK8; }
		PortConfigurationLock get_LCKR_LCK9() const { return LCKR.Fields.LCK9; }
		PortConfigurationLock get_LCKR_LCK10() const { return LCKR.Fields.LCK10; }
		PortConfigurationLock get_LCKR_LCK11() const { return LCKR.Fields.LCK11; }
		PortConfigurationLock get_LCKR_LCK12() const { return LCKR.Fields.LCK12; }
		PortConfigurationLock get_LCKR_LCK13() const { return LCKR.Fields.LCK13; }
		PortConfigurationLock get_LCKR_LCK14() const { return LCKR.Fields.LCK14; }
		PortConfigurationLock get_LCKR_LCK15() const { return LCKR.Fields.LCK15; }
		PortConfigurationLockKey get_LCKR_LCKK() const { return LCKR.Fields.LCKK; }
		void set_LCKR_LCK0(PortConfigurationLock value) { LCKR.Fields.LCK0 = value; }
		void set_LCKR_LCK1(PortConfigurationLock value) { LCKR.Fields.LCK1 = value; }
		void set_LCKR_LCK2(PortConfigurationLock value) { LCKR.Fields.LCK2 = value; }
		void set_LCKR_LCK3(PortConfigurationLock value) { LCKR.Fields.LCK3 = value; }
		void set_LCKR_LCK4(PortConfigurationLock value) { LCKR.Fields.LCK4 = value; }
		void set_LCKR_LCK5(PortConfigurationLock value) { LCKR.Fields.LCK5 = value; }
		void set_LCKR_LCK6(PortConfigurationLock value) { LCKR.Fields.LCK6 = value; }
		void set_LCKR_LCK7(PortConfigurationLock value) { LCKR.Fields.LCK7 = value; }
		void set_LCKR_LCK8(PortConfigurationLock value) { LCKR.Fields.LCK8 = value; }
		void set_LCKR_LCK9(PortConfigurationLock value) { LCKR.Fields.LCK9 = value; }
		void set_LCKR_LCK10(PortConfigurationLock value) { LCKR.Fields.LCK10 = value; }
		void set_LCKR_LCK11(PortConfigurationLock value) { LCKR.Fields.LCK11 = value; }
		void set_LCKR_LCK12(PortConfigurationLock value) { LCKR.Fields.LCK12 = value; }
		void set_LCKR_LCK13(PortConfigurationLock value) { LCKR.Fields.LCK13 = value; }
		void set_LCKR_LCK14(PortConfigurationLock value) { LCKR.Fields.LCK14 = value; }
		void set_LCKR_LCK15(PortConfigurationLock value) { LCKR.Fields.LCK15 = value; }
		void set_LCKR_LCKK(PortConfigurationLockKey value) { LCKR.Fields.LCKK = value; }

		// AFRL Fields
		AlternateFunction get_AFRL_AFRL0() const { return AFRL.Fields.AFRL0; }
		AlternateFunction get_AFRL_AFRL1() const { return AFRL.Fields.AFRL1; }
		AlternateFunction get_AFRL_AFRL2() const { return AFRL.Fields.AFRL2; }
		AlternateFunction get_AFRL_AFRL3() const { return AFRL.Fields.AFRL3; }
		AlternateFunction get_AFRL_AFRL4() const { return AFRL.Fields.AFRL4; }
		AlternateFunction get_AFRL_AFRL5() const { return AFRL.Fields.AFRL5; }
		AlternateFunction get_AFRL_AFRL6() const { return AFRL.Fields.AFRL6; }
		AlternateFunction get_AFRL_AFRL7() const { return AFRL.Fields.AFRL7; }
		void set_AFRL_AFRL0(AlternateFunction value) { AFRL.Fields.AFRL0 = value; }
		void set_AFRL_AFRL1(AlternateFunction value) { AFRL.Fields.AFRL1 = value; }
		void set_AFRL_AFRL2(AlternateFunction value) { AFRL.Fields.AFRL2 = value; }
		void set_AFRL_AFRL3(AlternateFunction value) { AFRL.Fields.AFRL3 = value; }
		void set_AFRL_AFRL4(AlternateFunction value) { AFRL.Fields.AFRL4 = value; }
		void set_AFRL_AFRL5(AlternateFunction value) { AFRL.Fields.AFRL5 = value; }
		void set_AFRL_AFRL6(AlternateFunction value) { AFRL.Fields.AFRL6 = value; }
		void set_AFRL_AFRL7(AlternateFunction value) { AFRL.Fields.AFRL7 = value; }

		// AFRH Fields
		AlternateFunction get_AFRH_AFRH8() const { return AFRH.Fields.AFRH8; }
		AlternateFunction get_AFRH_AFRH9() const { return AFRH.Fields.AFRH9; }
		AlternateFunction get_AFRH_AFRH10() const { return AFRH.Fields.AFRH10; }
		AlternateFunction get_AFRH_AFRH11() const { return AFRH.Fields.AFRH11; }
		AlternateFunction get_AFRH_AFRH12() const { return AFRH.Fields.AFRH12; }
		AlternateFunction get_AFRH_AFRH13() const { return AFRH.Fields.AFRH13; }
		AlternateFunction get_AFRH_AFRH14() const { return AFRH.Fields.AFRH14; }
		AlternateFunction get_AFRH_AFRH15() const { return AFRH.Fields.AFRH15; }
		void set_AFRH_AFRH8(AlternateFunction value) { AFRH.Fields.AFRH8 = value; }
		void set_AFRH_AFRH9(AlternateFunction value) { AFRH.Fields.AFRH9 = value; }
		void set_AFRH_AFRH10(AlternateFunction value) { AFRH.Fields.AFRH10 = value; }
		void set_AFRH_AFRH11(AlternateFunction value) { AFRH.Fields.AFRH11 = value; }
		void set_AFRH_AFRH12(AlternateFunction value) { AFRH.Fields.AFRH12 = value; }
		void set_AFRH_AFRH13(AlternateFunction value) { AFRH.Fields.AFRH13 = value; }
		void set_AFRH_AFRH14(AlternateFunction value) { AFRH.Fields.AFRH14 = value; }
		void set_AFRH_AFRH15(AlternateFunction value) { AFRH.Fields.AFRH15 = value; }

	private:

		MODER_t MODER; // Address Offset 0x0
		OTYPER_t OTYPER; // Address Offset 0x4
		OSPEEDR_t OSPEEDR; // Address Offset 0x8
		PUPDR_t PUPDR; // Address Offset 0xC
		IDR_t IDR; // Address Offset 0x10
		ODR_t ODR; // Address Offset 0x14
		BSRR_t BSRR; // Address Offset 0x18
		LCKR_t LCKR; // Address Offset 0x1C
		AFRL_t AFRL; // Address Offset 0x20
		AFRH_t AFRH; // Address Offset 0x24
	};
}
#endif // GPIO_REGISTER_MAP_HPP_