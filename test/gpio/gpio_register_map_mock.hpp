#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gpio_register_map.hpp"

using namespace stm32::gpio;
using namespace testing;

class MockGpioRegisterMap : public IGpioRegisterMap
{
public:

	// MODER Fields
	MOCK_CONST_METHOD0(get_MODER_MODER0, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER1, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER2, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER3, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER4, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER5, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER6, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER7, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER8, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER9, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER10, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER11, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER12, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER13, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER14, PortMode());
	MOCK_CONST_METHOD0(get_MODER_MODER15, PortMode());
	MOCK_METHOD1(set_MODER_MODER0, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER1, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER2, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER3, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER4, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER5, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER6, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER7, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER8, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER9, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER10, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER11, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER12, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER13, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER14, void(PortMode value));
	MOCK_METHOD1(set_MODER_MODER15, void(PortMode value));

	// OTYPER Fields
	MOCK_CONST_METHOD0(get_OTYPER_OT0, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT1, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT2, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT3, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT4, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT5, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT6, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT7, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT8, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT9, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT10, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT11, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT12, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT13, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT14, OutputType());
	MOCK_CONST_METHOD0(get_OTYPER_OT15, OutputType());
	MOCK_METHOD1(set_OTYPER_OT0, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT1, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT2, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT3, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT4, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT5, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT6, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT7, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT8, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT9, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT10, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT11, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT12, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT13, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT14, void(OutputType value));
	MOCK_METHOD1(set_OTYPER_OT15, void(OutputType value));

	// OSPEEDR Fields
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR0, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR1, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR2, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR3, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR4, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR5, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR6, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR7, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR8, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR9, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR10, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR11, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR12, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR13, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR14, OutputSpeed());
	MOCK_CONST_METHOD0(get_OSPEEDR_OSPEEDR15, OutputSpeed());
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR0, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR1, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR2, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR3, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR4, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR5, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR6, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR7, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR8, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR9, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR10, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR11, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR12, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR13, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR14, void(OutputSpeed value));
	MOCK_METHOD1(set_OSPEEDR_OSPEEDR15, void(OutputSpeed value));

	// PUPDR Fields
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR0, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR1, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR2, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR3, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR4, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR5, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR6, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR7, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR8, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR9, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR10, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR11, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR12, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR13, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR14, PullUpPullDown());
	MOCK_CONST_METHOD0(get_PUPDR_PUPDR15, PullUpPullDown());
	MOCK_METHOD1(set_PUPDR_PUPDR0, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR1, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR2, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR3, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR4, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR5, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR6, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR7, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR8, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR9, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR10, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR11, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR12, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR13, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR14, void(PullUpPullDown value));
	MOCK_METHOD1(set_PUPDR_PUPDR15, void(PullUpPullDown value));

	// IDR Fields
	MOCK_CONST_METHOD0(get_IDR_IDR0, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR1, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR2, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR3, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR4, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR5, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR6, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR7, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR8, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR9, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR10, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR11, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR12, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR13, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR14, uint8_t());
	MOCK_CONST_METHOD0(get_IDR_IDR15, uint8_t());

	// ODR Fields
	MOCK_CONST_METHOD0(get_ODR_ODR0, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR1, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR2, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR3, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR4, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR5, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR6, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR7, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR8, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR9, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR10, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR11, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR12, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR13, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR14, uint8_t());
	MOCK_CONST_METHOD0(get_ODR_ODR15, uint8_t());
	MOCK_METHOD1(set_ODR_ODR0, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR1, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR2, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR3, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR4, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR5, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR6, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR7, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR8, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR9, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR10, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR11, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR12, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR13, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR14, void(uint8_t value));
	MOCK_METHOD1(set_ODR_ODR15, void(uint8_t value));

	// BSRR Fields
	MOCK_METHOD1(set_BSRR_BS0, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS1, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS2, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS3, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS4, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS5, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS6, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS7, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS8, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS9, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS10, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS11, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS12, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS13, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS14, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BS15, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR0, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR1, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR2, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR3, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR4, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR5, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR6, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR7, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR8, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR9, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR10, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR11, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR12, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR13, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR14, void(uint8_t value));
	MOCK_METHOD1(set_BSRR_BR15, void(uint8_t value));

	// LCKR Fields
	MOCK_CONST_METHOD0(get_LCKR_LCK0, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK1, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK2, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK3, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK4, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK5, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK6, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK7, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK8, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK9, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK10, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK11, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK12, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK13, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK14, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCK15, PortConfigurationLock());
	MOCK_CONST_METHOD0(get_LCKR_LCKK, PortConfigurationLockKey());
	MOCK_METHOD1(set_LCKR_LCK0, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK1, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK2, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK3, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK4, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK5, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK6, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK7, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK8, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK9, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK10, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK11, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK12, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK13, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK14, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCK15, void(PortConfigurationLock value));
	MOCK_METHOD1(set_LCKR_LCKK, void(PortConfigurationLockKey value));

	// AFRL Fields
	MOCK_CONST_METHOD0(get_AFRL_AFRL0, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRL_AFRL1, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRL_AFRL2, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRL_AFRL3, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRL_AFRL4, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRL_AFRL5, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRL_AFRL6, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRL_AFRL7, AlternateFunction());
	MOCK_METHOD1(set_AFRL_AFRL0, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRL_AFRL1, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRL_AFRL2, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRL_AFRL3, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRL_AFRL4, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRL_AFRL5, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRL_AFRL6, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRL_AFRL7, void(AlternateFunction value));

	// AFRH Fields
	MOCK_CONST_METHOD0(get_AFRH_AFRH8, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRH_AFRH9, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRH_AFRH10, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRH_AFRH11, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRH_AFRH12, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRH_AFRH13, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRH_AFRH14, AlternateFunction());
	MOCK_CONST_METHOD0(get_AFRH_AFRH15, AlternateFunction());
	MOCK_METHOD1(set_AFRH_AFRH8, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRH_AFRH9, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRH_AFRH10, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRH_AFRH11, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRH_AFRH12, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRH_AFRH13, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRH_AFRH14, void(AlternateFunction value));
	MOCK_METHOD1(set_AFRH_AFRH15, void(AlternateFunction value));
};
