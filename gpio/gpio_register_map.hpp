#ifndef GPIO_REGISTER_MAP_HPP_
#define GPIO_REGISTER_MAP_HPP_

#include <cstdint>
#include "gpio_types.hpp"

using namespace std;

namespace stm32::gpio
{
	union PortModeRegister
	{
		volatile struct
		{
			PortMode MODER0    : 2; // [1:0]  rw : Port Mode for Pin 0
			PortMode MODER1    : 2; // [3:2]  rw : Port Mode for Pin 1
			PortMode MODER2    : 2; // [5:4]  rw : Port Mode for Pin 2
			PortMode MODER3    : 2; // [7:6]  rw : Port Mode for Pin 3
			PortMode MODER4    : 2; // [9:8]  rw : Port Mode for Pin 4
			PortMode MODER5    : 2; // [11:10] rw : Port Mode for Pin 5
			PortMode MODER6    : 2; // [13:12] rw : Port Mode for Pin 6
			PortMode MODER7    : 2; // [15:14] rw : Port Mode for Pin 7
			PortMode MODER8    : 2; // [17:16] rw : Port Mode for Pin 8
			PortMode MODER9    : 2; // [19:18] rw : Port Mode for Pin 9
			PortMode MODER10   : 2; // [21:20] rw : Port Mode for Pin 10
			PortMode MODER11   : 2; // [23:22] rw : Port Mode for Pin 11
			PortMode MODER12   : 2; // [25:24] rw : Port Mode for Pin 12
			PortMode MODER13   : 2; // [27:26] rw : Port Mode for Pin 13
			PortMode MODER14   : 2; // [29:28] rw : Port Mode for Pin 14
			PortMode MODER15   : 2; // [31:30] rw : Port Mode for Pin 15
		} Fields;
		volatile uint32_t Value;
	};

	union PortOutputTypeRegister
	{
		volatile struct
		{
			OutputType OT0       : 1; // [0]    rw : Output Type for Pin 0
			OutputType OT1       : 1; // [1]    rw : Output Type for Pin 1
			OutputType OT2       : 1; // [2]    rw : Output Type for Pin 2
			OutputType OT3       : 1; // [3]    rw : Output Type for Pin 3
			OutputType OT4       : 1; // [4]    rw : Output Type for Pin 4
			OutputType OT5       : 1; // [5]    rw : Output Type for Pin 5
			OutputType OT6       : 1; // [6]    rw : Output Type for Pin 6
			OutputType OT7       : 1; // [7]    rw : Output Type for Pin 7
			OutputType OT8       : 1; // [8]    rw : Output Type for Pin 8
			OutputType OT9       : 1; // [9]    rw : Output Type for Pin 9
			OutputType OT10      : 1; // [10]   rw : Output Type for Pin 10
			OutputType OT11      : 1; // [11]   rw : Output Type for Pin 11
			OutputType OT12      : 1; // [12]   rw : Output Type for Pin 12
			OutputType OT13      : 1; // [13]   rw : Output Type for Pin 13
			OutputType OT14      : 1; // [14]   rw : Output Type for Pin 14
			OutputType OT15      : 1; // [15]   rw : Output Type for Pin 15
			uint32_t   RESERVED1 : 16;
		} Fields;
		volatile uint32_t Value;
	};

	union PortOutputSpeedRegister
	{
		volatile struct
		{
			OutputSpeed OSPEEDR0  : 2; // [1:0]  rw : Output Speed for Pin 0
			OutputSpeed OSPEEDR1  : 2; // [3:2]  rw : Output Speed for Pin 1
			OutputSpeed OSPEEDR2  : 2; // [5:4]  rw : Output Speed for Pin 2
			OutputSpeed OSPEEDR3  : 2; // [7:6]  rw : Output Speed for Pin 3
			OutputSpeed OSPEEDR4  : 2; // [9:8]  rw : Output Speed for Pin 4
			OutputSpeed OSPEEDR5  : 2; // [11:10] rw : Output Speed for Pin 5
			OutputSpeed OSPEEDR6  : 2; // [13:12] rw : Output Speed for Pin 6
			OutputSpeed OSPEEDR7  : 2; // [15:14] rw : Output Speed for Pin 7
			OutputSpeed OSPEEDR8  : 2; // [17:16] rw : Output Speed for Pin 8
			OutputSpeed OSPEEDR9  : 2; // [19:18] rw : Output Speed for Pin 9
			OutputSpeed OSPEEDR10 : 2; // [21:20] rw : Output Speed for Pin 10
			OutputSpeed OSPEEDR11 : 2; // [23:22] rw : Output Speed for Pin 11
			OutputSpeed OSPEEDR12 : 2; // [25:24] rw : Output Speed for Pin 12
			OutputSpeed OSPEEDR13 : 2; // [27:26] rw : Output Speed for Pin 13
			OutputSpeed OSPEEDR14 : 2; // [29:28] rw : Output Speed for Pin 14
			OutputSpeed OSPEEDR15 : 2; // [31:30] rw : Output Speed for Pin 15
		} Fields;
		volatile uint32_t Value;
	};

	union PortPullUpPullDownRegister
	{
		volatile struct
		{
			PullUpPullDown PUPDR0    : 2; // [1:0]  rw : Pull-Up/Pull Down for Pin 0
			PullUpPullDown PUPDR1    : 2; // [3:2]  rw : Pull-Up/Pull Down for Pin 1
			PullUpPullDown PUPDR2    : 2; // [5:4]  rw : Pull-Up/Pull Down for Pin 2
			PullUpPullDown PUPDR3    : 2; // [7:6]  rw : Pull-Up/Pull Down for Pin 3
			PullUpPullDown PUPDR4    : 2; // [9:8]  rw : Pull-Up/Pull Down for Pin 4
			PullUpPullDown PUPDR5    : 2; // [11:10] rw : Pull-Up/Pull Down for Pin 5
			PullUpPullDown PUPDR6    : 2; // [13:12] rw : Pull-Up/Pull Down for Pin 6
			PullUpPullDown PUPDR7    : 2; // [15:14] rw : Pull-Up/Pull Down for Pin 7
			PullUpPullDown PUPDR8    : 2; // [17:16] rw : Pull-Up/Pull Down for Pin 8
			PullUpPullDown PUPDR9    : 2; // [19:18] rw : Pull-Up/Pull Down for Pin 9
			PullUpPullDown PUPDR10   : 2; // [21:20] rw : Pull-Up/Pull Down for Pin 10
			PullUpPullDown PUPDR11   : 2; // [23:22] rw : Pull-Up/Pull Down for Pin 11
			PullUpPullDown PUPDR12   : 2; // [25:24] rw : Pull-Up/Pull Down for Pin 12
			PullUpPullDown PUPDR13   : 2; // [27:26] rw : Pull-Up/Pull Down for Pin 13
			PullUpPullDown PUPDR14   : 2; // [29:28] rw : Pull-Up/Pull Down for Pin 14
			PullUpPullDown PUPDR15   : 2; // [31:30] rw : Pull-Up/Pull Down for Pin 15
		} Fields;
		volatile uint32_t Value;
	};

	union PortInputDataRegister
	{
		volatile struct
		{
			uint8_t IDR0      : 1; // [0]    r  : Input Data for Pin 0
			uint8_t IDR1      : 1; // [1]    r  : Input Data for Pin 1
			uint8_t IDR2      : 1; // [2]    r  : Input Data for Pin 2
			uint8_t IDR3      : 1; // [3]    r  : Input Data for Pin 3
			uint8_t IDR4      : 1; // [4]    r  : Input Data for Pin 4
			uint8_t IDR5      : 1; // [5]    r  : Input Data for Pin 5
			uint8_t IDR6      : 1; // [6]    r  : Input Data for Pin 6
			uint8_t IDR7      : 1; // [7]    r  : Input Data for Pin 7
			uint8_t IDR8      : 1; // [8]    r  : Input Data for Pin 8
			uint8_t IDR9      : 1; // [9]    r  : Input Data for Pin 9
			uint8_t IDR10     : 1; // [10]   r  : Input Data for Pin 10
			uint8_t IDR11     : 1; // [11]   r  : Input Data for Pin 11
			uint8_t IDR12     : 1; // [12]   r  : Input Data for Pin 12
			uint8_t IDR13     : 1; // [13]   r  : Input Data for Pin 13
			uint8_t IDR14     : 1; // [14]   r  : Input Data for Pin 14
			uint8_t IDR15     : 1; // [15]   r  : Input Data for Pin 15
			uint32_t RESERVED1 : 16;
		} Fields;
		volatile uint32_t Value;
	};

	union PortOutputDataRegister
	{
		volatile struct
		{
			uint8_t ODR0      : 1; // [0]    rw : Output Data for Pin 0
			uint8_t ODR1      : 1; // [1]    rw : Output Data for Pin 1
			uint8_t ODR2      : 1; // [2]    rw : Output Data for Pin 2
			uint8_t ODR3      : 1; // [3]    rw : Output Data for Pin 3
			uint8_t ODR4      : 1; // [4]    rw : Output Data for Pin 4
			uint8_t ODR5      : 1; // [5]    rw : Output Data for Pin 5
			uint8_t ODR6      : 1; // [6]    rw : Output Data for Pin 6
			uint8_t ODR7      : 1; // [7]    rw : Output Data for Pin 7
			uint8_t ODR8      : 1; // [8]    rw : Output Data for Pin 8
			uint8_t ODR9      : 1; // [9]    rw : Output Data for Pin 9
			uint8_t ODR10     : 1; // [10]   rw : Output Data for Pin 10
			uint8_t ODR11     : 1; // [11]   rw : Output Data for Pin 11
			uint8_t ODR12     : 1; // [12]   rw : Output Data for Pin 12
			uint8_t ODR13     : 1; // [13]   rw : Output Data for Pin 13
			uint8_t ODR14     : 1; // [14]   rw : Output Data for Pin 14
			uint8_t ODR15     : 1; // [15]   rw : Output Data for Pin 15
			uint32_t RESERVED1 : 16;
		} Fields;
		volatile uint32_t Value;
	};

	union PortBitSetResetRegister
	{
		volatile struct
		{
			uint8_t BS0       : 1; // [0]    w  : Port Set Bit 0
			uint8_t BS1       : 1; // [1]    w  : Port Set Bit 1
			uint8_t BS2       : 1; // [2]    w  : Port Set Bit 2
			uint8_t BS3       : 1; // [3]    w  : Port Set Bit 3
			uint8_t BS4       : 1; // [4]    w  : Port Set Bit 4
			uint8_t BS5       : 1; // [5]    w  : Port Set Bit 5
			uint8_t BS6       : 1; // [6]    w  : Port Set Bit 6
			uint8_t BS7       : 1; // [7]    w  : Port Set Bit 7
			uint8_t BS8       : 1; // [8]    w  : Port Set Bit 8
			uint8_t BS9       : 1; // [9]    w  : Port Set Bit 9
			uint8_t BS10      : 1; // [10]   w  : Port Set Bit 10
			uint8_t BS11      : 1; // [11]   w  : Port Set Bit 11
			uint8_t BS12      : 1; // [12]   w  : Port Set Bit 12
			uint8_t BS13      : 1; // [13]   w  : Port Set Bit 13
			uint8_t BS14      : 1; // [14]   w  : Port Set Bit 14
			uint8_t BS15      : 1; // [15]   w  : Port Set Bit 15
			uint8_t BR0       : 1; // [16]   w  : Port Reset Bit 0
			uint8_t BR1       : 1; // [17]   w  : Port Reset Bit 1
			uint8_t BR2       : 1; // [18]   w  : Port Reset Bit 2
			uint8_t BR3       : 1; // [19]   w  : Port Reset Bit 3
			uint8_t BR4       : 1; // [20]   w  : Port Reset Bit 4
			uint8_t BR5       : 1; // [21]   w  : Port Reset Bit 5
			uint8_t BR6       : 1; // [22]   w  : Port Reset Bit 6
			uint8_t BR7       : 1; // [23]   w  : Port Reset Bit 7
			uint8_t BR8       : 1; // [24]   w  : Port Reset Bit 8
			uint8_t BR9       : 1; // [25]   w  : Port Reset Bit 9
			uint8_t BR10      : 1; // [26]   w  : Port Reset Bit 10
			uint8_t BR11      : 1; // [27]   w  : Port Reset Bit 11
			uint8_t BR12      : 1; // [28]   w  : Port Reset Bit 12
			uint8_t BR13      : 1; // [29]   w  : Port Reset Bit 13
			uint8_t BR14      : 1; // [30]   w  : Port Reset Bit 14
			uint8_t BR15      : 1; // [31]   w  : Port Reset Bit 15
		} Fields;
		volatile uint32_t Value;
	};

	union PortConfigurationLockRegister
	{
		volatile struct
		{
			PortConfigurationLock    LCK0      : 1; // [0]    rw : Port Configuration Lock for Bit 0
			PortConfigurationLock    LCK1      : 1; // [1]    rw : Port Configuration Lock for Bit 1
			PortConfigurationLock    LCK2      : 1; // [2]    rw : Port Configuration Lock for Bit 2
			PortConfigurationLock    LCK3      : 1; // [3]    rw : Port Configuration Lock for Bit 3
			PortConfigurationLock    LCK4      : 1; // [4]    rw : Port Configuration Lock for Bit 4
			PortConfigurationLock    LCK5      : 1; // [5]    rw : Port Configuration Lock for Bit 5
			PortConfigurationLock    LCK6      : 1; // [6]    rw : Port Configuration Lock for Bit 6
			PortConfigurationLock    LCK7      : 1; // [7]    rw : Port Configuration Lock for Bit 7
			PortConfigurationLock    LCK8      : 1; // [8]    rw : Port Configuration Lock for Bit 8
			PortConfigurationLock    LCK9      : 1; // [9]    rw : Port Configuration Lock for Bit 9
			PortConfigurationLock    LCK10     : 1; // [10]   rw : Port Configuration Lock for Bit 10
			PortConfigurationLock    LCK11     : 1; // [11]   rw : Port Configuration Lock for Bit 11
			PortConfigurationLock    LCK12     : 1; // [12]   rw : Port Configuration Lock for Bit 12
			PortConfigurationLock    LCK13     : 1; // [13]   rw : Port Configuration Lock for Bit 13
			PortConfigurationLock    LCK14     : 1; // [14]   rw : Port Configuration Lock for Bit 14
			PortConfigurationLock    LCK15     : 1; // [15]   rw : Port Configuration Lock for Bit 15
			PortConfigurationLockKey LCKK      : 1; // [16]   rw : Port Configuration Lock Key
			uint32_t                 RESERVED1 : 15;
		} Fields;
		volatile uint32_t Value;
	};

	union AlternateFunctionLowRegister
	{
		volatile struct
		{
			AlternateFunction AFRL0     : 4; // [3:0]  rw : Alternate Function for Pin 0
			AlternateFunction AFRL1     : 4; // [7:4]  rw : Alternate Function for Pin 1
			AlternateFunction AFRL2     : 4; // [11:8] rw : Alternate Function for Pin 2
			AlternateFunction AFRL3     : 4; // [15:12] rw : Alternate Function for Pin 3
			AlternateFunction AFRL4     : 4; // [19:16] rw : Alternate Function for Pin 4
			AlternateFunction AFRL5     : 4; // [23:20] rw : Alternate Function for Pin 5
			AlternateFunction AFRL6     : 4; // [27:24] rw : Alternate Function for Pin 6
			AlternateFunction AFRL7     : 4; // [31:28] rw : Alternate Function for Pin 7
		} Fields;
		volatile uint32_t Value;
	};

	union AlternateFunctionHighRegister
	{
		volatile struct
		{
			AlternateFunction AFRH8     : 4; // [3:0]  rw : Alternate Function for Pin 8
			AlternateFunction AFRH9     : 4; // [7:4]  rw : Alternate Function for Pin 9
			AlternateFunction AFRH10    : 4; // [11:8] rw : Alternate Function for Pin 10
			AlternateFunction AFRH11    : 4; // [15:12] rw : Alternate Function for Pin 11
			AlternateFunction AFRH12    : 4; // [19:16] rw : Alternate Function for Pin 12
			AlternateFunction AFRH13    : 4; // [23:20] rw : Alternate Function for Pin 13
			AlternateFunction AFRH14    : 4; // [27:24] rw : Alternate Function for Pin 14
			AlternateFunction AFRH15    : 4; // [31:28] rw : Alternate Function for Pin 15
		} Fields;
		volatile uint32_t Value;
	};

	class IGpioRegisterMap
	{
	public:

		// MODER Fields
		virtual PortMode get_MODER_MODER0() const = 0;
		virtual PortMode get_MODER_MODER1() const = 0;
		virtual PortMode get_MODER_MODER2() const = 0;
		virtual PortMode get_MODER_MODER3() const = 0;
		virtual PortMode get_MODER_MODER4() const = 0;
		virtual PortMode get_MODER_MODER5() const = 0;
		virtual PortMode get_MODER_MODER6() const = 0;
		virtual PortMode get_MODER_MODER7() const = 0;
		virtual PortMode get_MODER_MODER8() const = 0;
		virtual PortMode get_MODER_MODER9() const = 0;
		virtual PortMode get_MODER_MODER10() const = 0;
		virtual PortMode get_MODER_MODER11() const = 0;
		virtual PortMode get_MODER_MODER12() const = 0;
		virtual PortMode get_MODER_MODER13() const = 0;
		virtual PortMode get_MODER_MODER14() const = 0;
		virtual PortMode get_MODER_MODER15() const = 0;
		virtual void set_MODER_MODER0(PortMode value) = 0;
		virtual void set_MODER_MODER1(PortMode value) = 0;
		virtual void set_MODER_MODER2(PortMode value) = 0;
		virtual void set_MODER_MODER3(PortMode value) = 0;
		virtual void set_MODER_MODER4(PortMode value) = 0;
		virtual void set_MODER_MODER5(PortMode value) = 0;
		virtual void set_MODER_MODER6(PortMode value) = 0;
		virtual void set_MODER_MODER7(PortMode value) = 0;
		virtual void set_MODER_MODER8(PortMode value) = 0;
		virtual void set_MODER_MODER9(PortMode value) = 0;
		virtual void set_MODER_MODER10(PortMode value) = 0;
		virtual void set_MODER_MODER11(PortMode value) = 0;
		virtual void set_MODER_MODER12(PortMode value) = 0;
		virtual void set_MODER_MODER13(PortMode value) = 0;
		virtual void set_MODER_MODER14(PortMode value) = 0;
		virtual void set_MODER_MODER15(PortMode value) = 0;

		// OTYPER Fields
		virtual OutputType get_OTYPER_OT0() const = 0;
		virtual OutputType get_OTYPER_OT1() const = 0;
		virtual OutputType get_OTYPER_OT2() const = 0;
		virtual OutputType get_OTYPER_OT3() const = 0;
		virtual OutputType get_OTYPER_OT4() const = 0;
		virtual OutputType get_OTYPER_OT5() const = 0;
		virtual OutputType get_OTYPER_OT6() const = 0;
		virtual OutputType get_OTYPER_OT7() const = 0;
		virtual OutputType get_OTYPER_OT8() const = 0;
		virtual OutputType get_OTYPER_OT9() const = 0;
		virtual OutputType get_OTYPER_OT10() const = 0;
		virtual OutputType get_OTYPER_OT11() const = 0;
		virtual OutputType get_OTYPER_OT12() const = 0;
		virtual OutputType get_OTYPER_OT13() const = 0;
		virtual OutputType get_OTYPER_OT14() const = 0;
		virtual OutputType get_OTYPER_OT15() const = 0;
		virtual void set_OTYPER_OT0(OutputType value) = 0;
		virtual void set_OTYPER_OT1(OutputType value) = 0;
		virtual void set_OTYPER_OT2(OutputType value) = 0;
		virtual void set_OTYPER_OT3(OutputType value) = 0;
		virtual void set_OTYPER_OT4(OutputType value) = 0;
		virtual void set_OTYPER_OT5(OutputType value) = 0;
		virtual void set_OTYPER_OT6(OutputType value) = 0;
		virtual void set_OTYPER_OT7(OutputType value) = 0;
		virtual void set_OTYPER_OT8(OutputType value) = 0;
		virtual void set_OTYPER_OT9(OutputType value) = 0;
		virtual void set_OTYPER_OT10(OutputType value) = 0;
		virtual void set_OTYPER_OT11(OutputType value) = 0;
		virtual void set_OTYPER_OT12(OutputType value) = 0;
		virtual void set_OTYPER_OT13(OutputType value) = 0;
		virtual void set_OTYPER_OT14(OutputType value) = 0;
		virtual void set_OTYPER_OT15(OutputType value) = 0;

		// OSPEEDR Fields
		virtual OutputSpeed get_OSPEEDR_OSPEEDR0() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR1() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR2() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR3() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR4() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR5() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR6() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR7() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR8() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR9() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR10() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR11() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR12() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR13() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR14() const = 0;
		virtual OutputSpeed get_OSPEEDR_OSPEEDR15() const = 0;
		virtual void set_OSPEEDR_OSPEEDR0(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR1(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR2(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR3(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR4(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR5(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR6(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR7(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR8(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR9(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR10(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR11(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR12(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR13(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR14(OutputSpeed value) = 0;
		virtual void set_OSPEEDR_OSPEEDR15(OutputSpeed value) = 0;

		// PUPDR Fields
		virtual PullUpPullDown get_PUPDR_PUPDR0() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR1() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR2() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR3() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR4() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR5() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR6() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR7() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR8() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR9() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR10() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR11() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR12() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR13() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR14() const = 0;
		virtual PullUpPullDown get_PUPDR_PUPDR15() const = 0;
		virtual void set_PUPDR_PUPDR0(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR1(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR2(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR3(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR4(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR5(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR6(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR7(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR8(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR9(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR10(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR11(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR12(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR13(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR14(PullUpPullDown value) = 0;
		virtual void set_PUPDR_PUPDR15(PullUpPullDown value) = 0;

		// IDR Fields
		virtual uint8_t get_IDR_IDR0() const = 0;
		virtual uint8_t get_IDR_IDR1() const = 0;
		virtual uint8_t get_IDR_IDR2() const = 0;
		virtual uint8_t get_IDR_IDR3() const = 0;
		virtual uint8_t get_IDR_IDR4() const = 0;
		virtual uint8_t get_IDR_IDR5() const = 0;
		virtual uint8_t get_IDR_IDR6() const = 0;
		virtual uint8_t get_IDR_IDR7() const = 0;
		virtual uint8_t get_IDR_IDR8() const = 0;
		virtual uint8_t get_IDR_IDR9() const = 0;
		virtual uint8_t get_IDR_IDR10() const = 0;
		virtual uint8_t get_IDR_IDR11() const = 0;
		virtual uint8_t get_IDR_IDR12() const = 0;
		virtual uint8_t get_IDR_IDR13() const = 0;
		virtual uint8_t get_IDR_IDR14() const = 0;
		virtual uint8_t get_IDR_IDR15() const = 0;

		// ODR Fields
		virtual uint8_t get_ODR_ODR0() const = 0;
		virtual uint8_t get_ODR_ODR1() const = 0;
		virtual uint8_t get_ODR_ODR2() const = 0;
		virtual uint8_t get_ODR_ODR3() const = 0;
		virtual uint8_t get_ODR_ODR4() const = 0;
		virtual uint8_t get_ODR_ODR5() const = 0;
		virtual uint8_t get_ODR_ODR6() const = 0;
		virtual uint8_t get_ODR_ODR7() const = 0;
		virtual uint8_t get_ODR_ODR8() const = 0;
		virtual uint8_t get_ODR_ODR9() const = 0;
		virtual uint8_t get_ODR_ODR10() const = 0;
		virtual uint8_t get_ODR_ODR11() const = 0;
		virtual uint8_t get_ODR_ODR12() const = 0;
		virtual uint8_t get_ODR_ODR13() const = 0;
		virtual uint8_t get_ODR_ODR14() const = 0;
		virtual uint8_t get_ODR_ODR15() const = 0;
		virtual void set_ODR_ODR0(uint8_t value) = 0;
		virtual void set_ODR_ODR1(uint8_t value) = 0;
		virtual void set_ODR_ODR2(uint8_t value) = 0;
		virtual void set_ODR_ODR3(uint8_t value) = 0;
		virtual void set_ODR_ODR4(uint8_t value) = 0;
		virtual void set_ODR_ODR5(uint8_t value) = 0;
		virtual void set_ODR_ODR6(uint8_t value) = 0;
		virtual void set_ODR_ODR7(uint8_t value) = 0;
		virtual void set_ODR_ODR8(uint8_t value) = 0;
		virtual void set_ODR_ODR9(uint8_t value) = 0;
		virtual void set_ODR_ODR10(uint8_t value) = 0;
		virtual void set_ODR_ODR11(uint8_t value) = 0;
		virtual void set_ODR_ODR12(uint8_t value) = 0;
		virtual void set_ODR_ODR13(uint8_t value) = 0;
		virtual void set_ODR_ODR14(uint8_t value) = 0;
		virtual void set_ODR_ODR15(uint8_t value) = 0;

		// BSRR Fields
		virtual void set_BSRR_BS0(uint8_t value) = 0;
		virtual void set_BSRR_BS1(uint8_t value) = 0;
		virtual void set_BSRR_BS2(uint8_t value) = 0;
		virtual void set_BSRR_BS3(uint8_t value) = 0;
		virtual void set_BSRR_BS4(uint8_t value) = 0;
		virtual void set_BSRR_BS5(uint8_t value) = 0;
		virtual void set_BSRR_BS6(uint8_t value) = 0;
		virtual void set_BSRR_BS7(uint8_t value) = 0;
		virtual void set_BSRR_BS8(uint8_t value) = 0;
		virtual void set_BSRR_BS9(uint8_t value) = 0;
		virtual void set_BSRR_BS10(uint8_t value) = 0;
		virtual void set_BSRR_BS11(uint8_t value) = 0;
		virtual void set_BSRR_BS12(uint8_t value) = 0;
		virtual void set_BSRR_BS13(uint8_t value) = 0;
		virtual void set_BSRR_BS14(uint8_t value) = 0;
		virtual void set_BSRR_BS15(uint8_t value) = 0;
		virtual void set_BSRR_BR0(uint8_t value) = 0;
		virtual void set_BSRR_BR1(uint8_t value) = 0;
		virtual void set_BSRR_BR2(uint8_t value) = 0;
		virtual void set_BSRR_BR3(uint8_t value) = 0;
		virtual void set_BSRR_BR4(uint8_t value) = 0;
		virtual void set_BSRR_BR5(uint8_t value) = 0;
		virtual void set_BSRR_BR6(uint8_t value) = 0;
		virtual void set_BSRR_BR7(uint8_t value) = 0;
		virtual void set_BSRR_BR8(uint8_t value) = 0;
		virtual void set_BSRR_BR9(uint8_t value) = 0;
		virtual void set_BSRR_BR10(uint8_t value) = 0;
		virtual void set_BSRR_BR11(uint8_t value) = 0;
		virtual void set_BSRR_BR12(uint8_t value) = 0;
		virtual void set_BSRR_BR13(uint8_t value) = 0;
		virtual void set_BSRR_BR14(uint8_t value) = 0;
		virtual void set_BSRR_BR15(uint8_t value) = 0;

		// LCKR Fields
		virtual PortConfigurationLock get_LCKR_LCK0() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK1() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK2() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK3() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK4() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK5() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK6() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK7() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK8() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK9() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK10() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK11() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK12() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK13() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK14() const = 0;
		virtual PortConfigurationLock get_LCKR_LCK15() const = 0;
		virtual PortConfigurationLockKey get_LCKR_LCKK() const = 0;
		virtual void set_LCKR_LCK0(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK1(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK2(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK3(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK4(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK5(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK6(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK7(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK8(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK9(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK10(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK11(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK12(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK13(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK14(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCK15(PortConfigurationLock value) = 0;
		virtual void set_LCKR_LCKK(PortConfigurationLockKey value) = 0;

		// AFRL Fields
		virtual AlternateFunction get_AFRL_AFRL0() const = 0;
		virtual AlternateFunction get_AFRL_AFRL1() const = 0;
		virtual AlternateFunction get_AFRL_AFRL2() const = 0;
		virtual AlternateFunction get_AFRL_AFRL3() const = 0;
		virtual AlternateFunction get_AFRL_AFRL4() const = 0;
		virtual AlternateFunction get_AFRL_AFRL5() const = 0;
		virtual AlternateFunction get_AFRL_AFRL6() const = 0;
		virtual AlternateFunction get_AFRL_AFRL7() const = 0;
		virtual void set_AFRL_AFRL0(AlternateFunction value) = 0;
		virtual void set_AFRL_AFRL1(AlternateFunction value) = 0;
		virtual void set_AFRL_AFRL2(AlternateFunction value) = 0;
		virtual void set_AFRL_AFRL3(AlternateFunction value) = 0;
		virtual void set_AFRL_AFRL4(AlternateFunction value) = 0;
		virtual void set_AFRL_AFRL5(AlternateFunction value) = 0;
		virtual void set_AFRL_AFRL6(AlternateFunction value) = 0;
		virtual void set_AFRL_AFRL7(AlternateFunction value) = 0;

		// AFRH Fields
		virtual AlternateFunction get_AFRH_AFRH8() const = 0;
		virtual AlternateFunction get_AFRH_AFRH9() const = 0;
		virtual AlternateFunction get_AFRH_AFRH10() const = 0;
		virtual AlternateFunction get_AFRH_AFRH11() const = 0;
		virtual AlternateFunction get_AFRH_AFRH12() const = 0;
		virtual AlternateFunction get_AFRH_AFRH13() const = 0;
		virtual AlternateFunction get_AFRH_AFRH14() const = 0;
		virtual AlternateFunction get_AFRH_AFRH15() const = 0;
		virtual void set_AFRH_AFRH8(AlternateFunction value) = 0;
		virtual void set_AFRH_AFRH9(AlternateFunction value) = 0;
		virtual void set_AFRH_AFRH10(AlternateFunction value) = 0;
		virtual void set_AFRH_AFRH11(AlternateFunction value) = 0;
		virtual void set_AFRH_AFRH12(AlternateFunction value) = 0;
		virtual void set_AFRH_AFRH13(AlternateFunction value) = 0;
		virtual void set_AFRH_AFRH14(AlternateFunction value) = 0;
		virtual void set_AFRH_AFRH15(AlternateFunction value) = 0;
	};

	class GpioRegisterMap : public IGpioRegisterMap
	{
	public:

		// MODER Fields
		PortMode get_MODER_MODER0() const override { return MODER.Fields.MODER0; }
		PortMode get_MODER_MODER1() const override { return MODER.Fields.MODER1; }
		PortMode get_MODER_MODER2() const override { return MODER.Fields.MODER2; }
		PortMode get_MODER_MODER3() const override { return MODER.Fields.MODER3; }
		PortMode get_MODER_MODER4() const override { return MODER.Fields.MODER4; }
		PortMode get_MODER_MODER5() const override { return MODER.Fields.MODER5; }
		PortMode get_MODER_MODER6() const override { return MODER.Fields.MODER6; }
		PortMode get_MODER_MODER7() const override { return MODER.Fields.MODER7; }
		PortMode get_MODER_MODER8() const override { return MODER.Fields.MODER8; }
		PortMode get_MODER_MODER9() const override { return MODER.Fields.MODER9; }
		PortMode get_MODER_MODER10() const override { return MODER.Fields.MODER10; }
		PortMode get_MODER_MODER11() const override { return MODER.Fields.MODER11; }
		PortMode get_MODER_MODER12() const override { return MODER.Fields.MODER12; }
		PortMode get_MODER_MODER13() const override { return MODER.Fields.MODER13; }
		PortMode get_MODER_MODER14() const override { return MODER.Fields.MODER14; }
		PortMode get_MODER_MODER15() const override { return MODER.Fields.MODER15; }
		void set_MODER_MODER0(PortMode value) override { MODER.Fields.MODER0 = value; }
		void set_MODER_MODER1(PortMode value) override { MODER.Fields.MODER1 = value; }
		void set_MODER_MODER2(PortMode value) override { MODER.Fields.MODER2 = value; }
		void set_MODER_MODER3(PortMode value) override { MODER.Fields.MODER3 = value; }
		void set_MODER_MODER4(PortMode value) override { MODER.Fields.MODER4 = value; }
		void set_MODER_MODER5(PortMode value) override { MODER.Fields.MODER5 = value; }
		void set_MODER_MODER6(PortMode value) override { MODER.Fields.MODER6 = value; }
		void set_MODER_MODER7(PortMode value) override { MODER.Fields.MODER7 = value; }
		void set_MODER_MODER8(PortMode value) override { MODER.Fields.MODER8 = value; }
		void set_MODER_MODER9(PortMode value) override { MODER.Fields.MODER9 = value; }
		void set_MODER_MODER10(PortMode value) override { MODER.Fields.MODER10 = value; }
		void set_MODER_MODER11(PortMode value) override { MODER.Fields.MODER11 = value; }
		void set_MODER_MODER12(PortMode value) override { MODER.Fields.MODER12 = value; }
		void set_MODER_MODER13(PortMode value) override { MODER.Fields.MODER13 = value; }
		void set_MODER_MODER14(PortMode value) override { MODER.Fields.MODER14 = value; }
		void set_MODER_MODER15(PortMode value) override { MODER.Fields.MODER15 = value; }

		// OTYPER Fields
		OutputType get_OTYPER_OT0() const override { return OTYPER.Fields.OT0; }
		OutputType get_OTYPER_OT1() const override { return OTYPER.Fields.OT1; }
		OutputType get_OTYPER_OT2() const override { return OTYPER.Fields.OT2; }
		OutputType get_OTYPER_OT3() const override { return OTYPER.Fields.OT3; }
		OutputType get_OTYPER_OT4() const override { return OTYPER.Fields.OT4; }
		OutputType get_OTYPER_OT5() const override { return OTYPER.Fields.OT5; }
		OutputType get_OTYPER_OT6() const override { return OTYPER.Fields.OT6; }
		OutputType get_OTYPER_OT7() const override { return OTYPER.Fields.OT7; }
		OutputType get_OTYPER_OT8() const override { return OTYPER.Fields.OT8; }
		OutputType get_OTYPER_OT9() const override { return OTYPER.Fields.OT9; }
		OutputType get_OTYPER_OT10() const override { return OTYPER.Fields.OT10; }
		OutputType get_OTYPER_OT11() const override { return OTYPER.Fields.OT11; }
		OutputType get_OTYPER_OT12() const override { return OTYPER.Fields.OT12; }
		OutputType get_OTYPER_OT13() const override { return OTYPER.Fields.OT13; }
		OutputType get_OTYPER_OT14() const override { return OTYPER.Fields.OT14; }
		OutputType get_OTYPER_OT15() const override { return OTYPER.Fields.OT15; }
		void set_OTYPER_OT0(OutputType value) override { OTYPER.Fields.OT0 = value; }
		void set_OTYPER_OT1(OutputType value) override { OTYPER.Fields.OT1 = value; }
		void set_OTYPER_OT2(OutputType value) override { OTYPER.Fields.OT2 = value; }
		void set_OTYPER_OT3(OutputType value) override { OTYPER.Fields.OT3 = value; }
		void set_OTYPER_OT4(OutputType value) override { OTYPER.Fields.OT4 = value; }
		void set_OTYPER_OT5(OutputType value) override { OTYPER.Fields.OT5 = value; }
		void set_OTYPER_OT6(OutputType value) override { OTYPER.Fields.OT6 = value; }
		void set_OTYPER_OT7(OutputType value) override { OTYPER.Fields.OT7 = value; }
		void set_OTYPER_OT8(OutputType value) override { OTYPER.Fields.OT8 = value; }
		void set_OTYPER_OT9(OutputType value) override { OTYPER.Fields.OT9 = value; }
		void set_OTYPER_OT10(OutputType value) override { OTYPER.Fields.OT10 = value; }
		void set_OTYPER_OT11(OutputType value) override { OTYPER.Fields.OT11 = value; }
		void set_OTYPER_OT12(OutputType value) override { OTYPER.Fields.OT12 = value; }
		void set_OTYPER_OT13(OutputType value) override { OTYPER.Fields.OT13 = value; }
		void set_OTYPER_OT14(OutputType value) override { OTYPER.Fields.OT14 = value; }
		void set_OTYPER_OT15(OutputType value) override { OTYPER.Fields.OT15 = value; }

		// OSPEEDR Fields
		OutputSpeed get_OSPEEDR_OSPEEDR0() const override { return OSPEEDR.Fields.OSPEEDR0; }
		OutputSpeed get_OSPEEDR_OSPEEDR1() const override { return OSPEEDR.Fields.OSPEEDR1; }
		OutputSpeed get_OSPEEDR_OSPEEDR2() const override { return OSPEEDR.Fields.OSPEEDR2; }
		OutputSpeed get_OSPEEDR_OSPEEDR3() const override { return OSPEEDR.Fields.OSPEEDR3; }
		OutputSpeed get_OSPEEDR_OSPEEDR4() const override { return OSPEEDR.Fields.OSPEEDR4; }
		OutputSpeed get_OSPEEDR_OSPEEDR5() const override { return OSPEEDR.Fields.OSPEEDR5; }
		OutputSpeed get_OSPEEDR_OSPEEDR6() const override { return OSPEEDR.Fields.OSPEEDR6; }
		OutputSpeed get_OSPEEDR_OSPEEDR7() const override { return OSPEEDR.Fields.OSPEEDR7; }
		OutputSpeed get_OSPEEDR_OSPEEDR8() const override { return OSPEEDR.Fields.OSPEEDR8; }
		OutputSpeed get_OSPEEDR_OSPEEDR9() const override { return OSPEEDR.Fields.OSPEEDR9; }
		OutputSpeed get_OSPEEDR_OSPEEDR10() const override { return OSPEEDR.Fields.OSPEEDR10; }
		OutputSpeed get_OSPEEDR_OSPEEDR11() const override { return OSPEEDR.Fields.OSPEEDR11; }
		OutputSpeed get_OSPEEDR_OSPEEDR12() const override { return OSPEEDR.Fields.OSPEEDR12; }
		OutputSpeed get_OSPEEDR_OSPEEDR13() const override { return OSPEEDR.Fields.OSPEEDR13; }
		OutputSpeed get_OSPEEDR_OSPEEDR14() const override { return OSPEEDR.Fields.OSPEEDR14; }
		OutputSpeed get_OSPEEDR_OSPEEDR15() const override { return OSPEEDR.Fields.OSPEEDR15; }
		void set_OSPEEDR_OSPEEDR0(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR0 = value; }
		void set_OSPEEDR_OSPEEDR1(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR1 = value; }
		void set_OSPEEDR_OSPEEDR2(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR2 = value; }
		void set_OSPEEDR_OSPEEDR3(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR3 = value; }
		void set_OSPEEDR_OSPEEDR4(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR4 = value; }
		void set_OSPEEDR_OSPEEDR5(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR5 = value; }
		void set_OSPEEDR_OSPEEDR6(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR6 = value; }
		void set_OSPEEDR_OSPEEDR7(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR7 = value; }
		void set_OSPEEDR_OSPEEDR8(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR8 = value; }
		void set_OSPEEDR_OSPEEDR9(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR9 = value; }
		void set_OSPEEDR_OSPEEDR10(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR10 = value; }
		void set_OSPEEDR_OSPEEDR11(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR11 = value; }
		void set_OSPEEDR_OSPEEDR12(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR12 = value; }
		void set_OSPEEDR_OSPEEDR13(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR13 = value; }
		void set_OSPEEDR_OSPEEDR14(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR14 = value; }
		void set_OSPEEDR_OSPEEDR15(OutputSpeed value) override { OSPEEDR.Fields.OSPEEDR15 = value; }

		// PUPDR Fields
		PullUpPullDown get_PUPDR_PUPDR0() const override { return PUPDR.Fields.PUPDR0; }
		PullUpPullDown get_PUPDR_PUPDR1() const override { return PUPDR.Fields.PUPDR1; }
		PullUpPullDown get_PUPDR_PUPDR2() const override { return PUPDR.Fields.PUPDR2; }
		PullUpPullDown get_PUPDR_PUPDR3() const override { return PUPDR.Fields.PUPDR3; }
		PullUpPullDown get_PUPDR_PUPDR4() const override { return PUPDR.Fields.PUPDR4; }
		PullUpPullDown get_PUPDR_PUPDR5() const override { return PUPDR.Fields.PUPDR5; }
		PullUpPullDown get_PUPDR_PUPDR6() const override { return PUPDR.Fields.PUPDR6; }
		PullUpPullDown get_PUPDR_PUPDR7() const override { return PUPDR.Fields.PUPDR7; }
		PullUpPullDown get_PUPDR_PUPDR8() const override { return PUPDR.Fields.PUPDR8; }
		PullUpPullDown get_PUPDR_PUPDR9() const override { return PUPDR.Fields.PUPDR9; }
		PullUpPullDown get_PUPDR_PUPDR10() const override { return PUPDR.Fields.PUPDR10; }
		PullUpPullDown get_PUPDR_PUPDR11() const override { return PUPDR.Fields.PUPDR11; }
		PullUpPullDown get_PUPDR_PUPDR12() const override { return PUPDR.Fields.PUPDR12; }
		PullUpPullDown get_PUPDR_PUPDR13() const override { return PUPDR.Fields.PUPDR13; }
		PullUpPullDown get_PUPDR_PUPDR14() const override { return PUPDR.Fields.PUPDR14; }
		PullUpPullDown get_PUPDR_PUPDR15() const override { return PUPDR.Fields.PUPDR15; }
		void set_PUPDR_PUPDR0(PullUpPullDown value) override { PUPDR.Fields.PUPDR0 = value; }
		void set_PUPDR_PUPDR1(PullUpPullDown value) override { PUPDR.Fields.PUPDR1 = value; }
		void set_PUPDR_PUPDR2(PullUpPullDown value) override { PUPDR.Fields.PUPDR2 = value; }
		void set_PUPDR_PUPDR3(PullUpPullDown value) override { PUPDR.Fields.PUPDR3 = value; }
		void set_PUPDR_PUPDR4(PullUpPullDown value) override { PUPDR.Fields.PUPDR4 = value; }
		void set_PUPDR_PUPDR5(PullUpPullDown value) override { PUPDR.Fields.PUPDR5 = value; }
		void set_PUPDR_PUPDR6(PullUpPullDown value) override { PUPDR.Fields.PUPDR6 = value; }
		void set_PUPDR_PUPDR7(PullUpPullDown value) override { PUPDR.Fields.PUPDR7 = value; }
		void set_PUPDR_PUPDR8(PullUpPullDown value) override { PUPDR.Fields.PUPDR8 = value; }
		void set_PUPDR_PUPDR9(PullUpPullDown value) override { PUPDR.Fields.PUPDR9 = value; }
		void set_PUPDR_PUPDR10(PullUpPullDown value) override { PUPDR.Fields.PUPDR10 = value; }
		void set_PUPDR_PUPDR11(PullUpPullDown value) override { PUPDR.Fields.PUPDR11 = value; }
		void set_PUPDR_PUPDR12(PullUpPullDown value) override { PUPDR.Fields.PUPDR12 = value; }
		void set_PUPDR_PUPDR13(PullUpPullDown value) override { PUPDR.Fields.PUPDR13 = value; }
		void set_PUPDR_PUPDR14(PullUpPullDown value) override { PUPDR.Fields.PUPDR14 = value; }
		void set_PUPDR_PUPDR15(PullUpPullDown value) override { PUPDR.Fields.PUPDR15 = value; }

		// IDR Fields
		uint8_t get_IDR_IDR0() const override { return IDR.Fields.IDR0; }
		uint8_t get_IDR_IDR1() const override { return IDR.Fields.IDR1; }
		uint8_t get_IDR_IDR2() const override { return IDR.Fields.IDR2; }
		uint8_t get_IDR_IDR3() const override { return IDR.Fields.IDR3; }
		uint8_t get_IDR_IDR4() const override { return IDR.Fields.IDR4; }
		uint8_t get_IDR_IDR5() const override { return IDR.Fields.IDR5; }
		uint8_t get_IDR_IDR6() const override { return IDR.Fields.IDR6; }
		uint8_t get_IDR_IDR7() const override { return IDR.Fields.IDR7; }
		uint8_t get_IDR_IDR8() const override { return IDR.Fields.IDR8; }
		uint8_t get_IDR_IDR9() const override { return IDR.Fields.IDR9; }
		uint8_t get_IDR_IDR10() const override { return IDR.Fields.IDR10; }
		uint8_t get_IDR_IDR11() const override { return IDR.Fields.IDR11; }
		uint8_t get_IDR_IDR12() const override { return IDR.Fields.IDR12; }
		uint8_t get_IDR_IDR13() const override { return IDR.Fields.IDR13; }
		uint8_t get_IDR_IDR14() const override { return IDR.Fields.IDR14; }
		uint8_t get_IDR_IDR15() const override { return IDR.Fields.IDR15; }

		// ODR Fields
		uint8_t get_ODR_ODR0() const override { return ODR.Fields.ODR0; }
		uint8_t get_ODR_ODR1() const override { return ODR.Fields.ODR1; }
		uint8_t get_ODR_ODR2() const override { return ODR.Fields.ODR2; }
		uint8_t get_ODR_ODR3() const override { return ODR.Fields.ODR3; }
		uint8_t get_ODR_ODR4() const override { return ODR.Fields.ODR4; }
		uint8_t get_ODR_ODR5() const override { return ODR.Fields.ODR5; }
		uint8_t get_ODR_ODR6() const override { return ODR.Fields.ODR6; }
		uint8_t get_ODR_ODR7() const override { return ODR.Fields.ODR7; }
		uint8_t get_ODR_ODR8() const override { return ODR.Fields.ODR8; }
		uint8_t get_ODR_ODR9() const override { return ODR.Fields.ODR9; }
		uint8_t get_ODR_ODR10() const override { return ODR.Fields.ODR10; }
		uint8_t get_ODR_ODR11() const override { return ODR.Fields.ODR11; }
		uint8_t get_ODR_ODR12() const override { return ODR.Fields.ODR12; }
		uint8_t get_ODR_ODR13() const override { return ODR.Fields.ODR13; }
		uint8_t get_ODR_ODR14() const override { return ODR.Fields.ODR14; }
		uint8_t get_ODR_ODR15() const override { return ODR.Fields.ODR15; }
		void set_ODR_ODR0(uint8_t value) override { ODR.Fields.ODR0 = value; }
		void set_ODR_ODR1(uint8_t value) override { ODR.Fields.ODR1 = value; }
		void set_ODR_ODR2(uint8_t value) override { ODR.Fields.ODR2 = value; }
		void set_ODR_ODR3(uint8_t value) override { ODR.Fields.ODR3 = value; }
		void set_ODR_ODR4(uint8_t value) override { ODR.Fields.ODR4 = value; }
		void set_ODR_ODR5(uint8_t value) override { ODR.Fields.ODR5 = value; }
		void set_ODR_ODR6(uint8_t value) override { ODR.Fields.ODR6 = value; }
		void set_ODR_ODR7(uint8_t value) override { ODR.Fields.ODR7 = value; }
		void set_ODR_ODR8(uint8_t value) override { ODR.Fields.ODR8 = value; }
		void set_ODR_ODR9(uint8_t value) override { ODR.Fields.ODR9 = value; }
		void set_ODR_ODR10(uint8_t value) override { ODR.Fields.ODR10 = value; }
		void set_ODR_ODR11(uint8_t value) override { ODR.Fields.ODR11 = value; }
		void set_ODR_ODR12(uint8_t value) override { ODR.Fields.ODR12 = value; }
		void set_ODR_ODR13(uint8_t value) override { ODR.Fields.ODR13 = value; }
		void set_ODR_ODR14(uint8_t value) override { ODR.Fields.ODR14 = value; }
		void set_ODR_ODR15(uint8_t value) override { ODR.Fields.ODR15 = value; }

		// BSRR Fields
		void set_BSRR_BS0(uint8_t value) override { BSRR.Fields.BS0 = value; }
		void set_BSRR_BS1(uint8_t value) override { BSRR.Fields.BS1 = value; }
		void set_BSRR_BS2(uint8_t value) override { BSRR.Fields.BS2 = value; }
		void set_BSRR_BS3(uint8_t value) override { BSRR.Fields.BS3 = value; }
		void set_BSRR_BS4(uint8_t value) override { BSRR.Fields.BS4 = value; }
		void set_BSRR_BS5(uint8_t value) override { BSRR.Fields.BS5 = value; }
		void set_BSRR_BS6(uint8_t value) override { BSRR.Fields.BS6 = value; }
		void set_BSRR_BS7(uint8_t value) override { BSRR.Fields.BS7 = value; }
		void set_BSRR_BS8(uint8_t value) override { BSRR.Fields.BS8 = value; }
		void set_BSRR_BS9(uint8_t value) override { BSRR.Fields.BS9 = value; }
		void set_BSRR_BS10(uint8_t value) override { BSRR.Fields.BS10 = value; }
		void set_BSRR_BS11(uint8_t value) override { BSRR.Fields.BS11 = value; }
		void set_BSRR_BS12(uint8_t value) override { BSRR.Fields.BS12 = value; }
		void set_BSRR_BS13(uint8_t value) override { BSRR.Fields.BS13 = value; }
		void set_BSRR_BS14(uint8_t value) override { BSRR.Fields.BS14 = value; }
		void set_BSRR_BS15(uint8_t value) override { BSRR.Fields.BS15 = value; }
		void set_BSRR_BR0(uint8_t value) override { BSRR.Fields.BR0 = value; }
		void set_BSRR_BR1(uint8_t value) override { BSRR.Fields.BR1 = value; }
		void set_BSRR_BR2(uint8_t value) override { BSRR.Fields.BR2 = value; }
		void set_BSRR_BR3(uint8_t value) override { BSRR.Fields.BR3 = value; }
		void set_BSRR_BR4(uint8_t value) override { BSRR.Fields.BR4 = value; }
		void set_BSRR_BR5(uint8_t value) override { BSRR.Fields.BR5 = value; }
		void set_BSRR_BR6(uint8_t value) override { BSRR.Fields.BR6 = value; }
		void set_BSRR_BR7(uint8_t value) override { BSRR.Fields.BR7 = value; }
		void set_BSRR_BR8(uint8_t value) override { BSRR.Fields.BR8 = value; }
		void set_BSRR_BR9(uint8_t value) override { BSRR.Fields.BR9 = value; }
		void set_BSRR_BR10(uint8_t value) override { BSRR.Fields.BR10 = value; }
		void set_BSRR_BR11(uint8_t value) override { BSRR.Fields.BR11 = value; }
		void set_BSRR_BR12(uint8_t value) override { BSRR.Fields.BR12 = value; }
		void set_BSRR_BR13(uint8_t value) override { BSRR.Fields.BR13 = value; }
		void set_BSRR_BR14(uint8_t value) override { BSRR.Fields.BR14 = value; }
		void set_BSRR_BR15(uint8_t value) override { BSRR.Fields.BR15 = value; }

		// LCKR Fields
		PortConfigurationLock get_LCKR_LCK0() const override { return LCKR.Fields.LCK0; }
		PortConfigurationLock get_LCKR_LCK1() const override { return LCKR.Fields.LCK1; }
		PortConfigurationLock get_LCKR_LCK2() const override { return LCKR.Fields.LCK2; }
		PortConfigurationLock get_LCKR_LCK3() const override { return LCKR.Fields.LCK3; }
		PortConfigurationLock get_LCKR_LCK4() const override { return LCKR.Fields.LCK4; }
		PortConfigurationLock get_LCKR_LCK5() const override { return LCKR.Fields.LCK5; }
		PortConfigurationLock get_LCKR_LCK6() const override { return LCKR.Fields.LCK6; }
		PortConfigurationLock get_LCKR_LCK7() const override { return LCKR.Fields.LCK7; }
		PortConfigurationLock get_LCKR_LCK8() const override { return LCKR.Fields.LCK8; }
		PortConfigurationLock get_LCKR_LCK9() const override { return LCKR.Fields.LCK9; }
		PortConfigurationLock get_LCKR_LCK10() const override { return LCKR.Fields.LCK10; }
		PortConfigurationLock get_LCKR_LCK11() const override { return LCKR.Fields.LCK11; }
		PortConfigurationLock get_LCKR_LCK12() const override { return LCKR.Fields.LCK12; }
		PortConfigurationLock get_LCKR_LCK13() const override { return LCKR.Fields.LCK13; }
		PortConfigurationLock get_LCKR_LCK14() const override { return LCKR.Fields.LCK14; }
		PortConfigurationLock get_LCKR_LCK15() const override { return LCKR.Fields.LCK15; }
		PortConfigurationLockKey get_LCKR_LCKK() const override { return LCKR.Fields.LCKK; }
		void set_LCKR_LCK0(PortConfigurationLock value) override { LCKR.Fields.LCK0 = value; }
		void set_LCKR_LCK1(PortConfigurationLock value) override { LCKR.Fields.LCK1 = value; }
		void set_LCKR_LCK2(PortConfigurationLock value) override { LCKR.Fields.LCK2 = value; }
		void set_LCKR_LCK3(PortConfigurationLock value) override { LCKR.Fields.LCK3 = value; }
		void set_LCKR_LCK4(PortConfigurationLock value) override { LCKR.Fields.LCK4 = value; }
		void set_LCKR_LCK5(PortConfigurationLock value) override { LCKR.Fields.LCK5 = value; }
		void set_LCKR_LCK6(PortConfigurationLock value) override { LCKR.Fields.LCK6 = value; }
		void set_LCKR_LCK7(PortConfigurationLock value) override { LCKR.Fields.LCK7 = value; }
		void set_LCKR_LCK8(PortConfigurationLock value) override { LCKR.Fields.LCK8 = value; }
		void set_LCKR_LCK9(PortConfigurationLock value) override { LCKR.Fields.LCK9 = value; }
		void set_LCKR_LCK10(PortConfigurationLock value) override { LCKR.Fields.LCK10 = value; }
		void set_LCKR_LCK11(PortConfigurationLock value) override { LCKR.Fields.LCK11 = value; }
		void set_LCKR_LCK12(PortConfigurationLock value) override { LCKR.Fields.LCK12 = value; }
		void set_LCKR_LCK13(PortConfigurationLock value) override { LCKR.Fields.LCK13 = value; }
		void set_LCKR_LCK14(PortConfigurationLock value) override { LCKR.Fields.LCK14 = value; }
		void set_LCKR_LCK15(PortConfigurationLock value) override { LCKR.Fields.LCK15 = value; }
		void set_LCKR_LCKK(PortConfigurationLockKey value) override { LCKR.Fields.LCKK = value; }

		// AFRL Fields
		AlternateFunction get_AFRL_AFRL0() const override { return AFRL.Fields.AFRL0; }
		AlternateFunction get_AFRL_AFRL1() const override { return AFRL.Fields.AFRL1; }
		AlternateFunction get_AFRL_AFRL2() const override { return AFRL.Fields.AFRL2; }
		AlternateFunction get_AFRL_AFRL3() const override { return AFRL.Fields.AFRL3; }
		AlternateFunction get_AFRL_AFRL4() const override { return AFRL.Fields.AFRL4; }
		AlternateFunction get_AFRL_AFRL5() const override { return AFRL.Fields.AFRL5; }
		AlternateFunction get_AFRL_AFRL6() const override { return AFRL.Fields.AFRL6; }
		AlternateFunction get_AFRL_AFRL7() const override { return AFRL.Fields.AFRL7; }
		void set_AFRL_AFRL0(AlternateFunction value) override { AFRL.Fields.AFRL0 = value; }
		void set_AFRL_AFRL1(AlternateFunction value) override { AFRL.Fields.AFRL1 = value; }
		void set_AFRL_AFRL2(AlternateFunction value) override { AFRL.Fields.AFRL2 = value; }
		void set_AFRL_AFRL3(AlternateFunction value) override { AFRL.Fields.AFRL3 = value; }
		void set_AFRL_AFRL4(AlternateFunction value) override { AFRL.Fields.AFRL4 = value; }
		void set_AFRL_AFRL5(AlternateFunction value) override { AFRL.Fields.AFRL5 = value; }
		void set_AFRL_AFRL6(AlternateFunction value) override { AFRL.Fields.AFRL6 = value; }
		void set_AFRL_AFRL7(AlternateFunction value) override { AFRL.Fields.AFRL7 = value; }

		// AFRH Fields
		AlternateFunction get_AFRH_AFRH8() const override { return AFRH.Fields.AFRH8; }
		AlternateFunction get_AFRH_AFRH9() const override { return AFRH.Fields.AFRH9; }
		AlternateFunction get_AFRH_AFRH10() const override { return AFRH.Fields.AFRH10; }
		AlternateFunction get_AFRH_AFRH11() const override { return AFRH.Fields.AFRH11; }
		AlternateFunction get_AFRH_AFRH12() const override { return AFRH.Fields.AFRH12; }
		AlternateFunction get_AFRH_AFRH13() const override { return AFRH.Fields.AFRH13; }
		AlternateFunction get_AFRH_AFRH14() const override { return AFRH.Fields.AFRH14; }
		AlternateFunction get_AFRH_AFRH15() const override { return AFRH.Fields.AFRH15; }
		void set_AFRH_AFRH8(AlternateFunction value) override { AFRH.Fields.AFRH8 = value; }
		void set_AFRH_AFRH9(AlternateFunction value) override { AFRH.Fields.AFRH9 = value; }
		void set_AFRH_AFRH10(AlternateFunction value) override { AFRH.Fields.AFRH10 = value; }
		void set_AFRH_AFRH11(AlternateFunction value) override { AFRH.Fields.AFRH11 = value; }
		void set_AFRH_AFRH12(AlternateFunction value) override { AFRH.Fields.AFRH12 = value; }
		void set_AFRH_AFRH13(AlternateFunction value) override { AFRH.Fields.AFRH13 = value; }
		void set_AFRH_AFRH14(AlternateFunction value) override { AFRH.Fields.AFRH14 = value; }
		void set_AFRH_AFRH15(AlternateFunction value) override { AFRH.Fields.AFRH15 = value; }

	private:

		PortModeRegister MODER;
		PortOutputTypeRegister OTYPER;
		PortOutputSpeedRegister OSPEEDR;
		PortPullUpPullDownRegister PUPDR;
		PortInputDataRegister IDR;
		PortOutputDataRegister ODR;
		PortBitSetResetRegister BSRR;
		PortConfigurationLockRegister LCKR;
		AlternateFunctionLowRegister AFRL;
		AlternateFunctionHighRegister AFRH;
	};
}
#endif // GPIO_REGISTER_MAP_HPP_