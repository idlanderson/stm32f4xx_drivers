#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "usart_register_map.hpp"
#include <cstring>

using namespace stm32::usart;
using namespace testing;

class MockUsartRegisterMap : public IUsartRegisterMap
{
public:

	// SR Fields
	MOCK_METHOD(ParityError, get_SR_PE, (), (const, override));
	MOCK_METHOD(FramingError, get_SR_FE, (), (const, override));
	MOCK_METHOD(NoiceDetectedFlag, get_SR_NF, (), (const, override));
	MOCK_METHOD(OverrunError, get_SR_ORE, (), (const, override));
	MOCK_METHOD(IdleLineDetected, get_SR_IDLE, (), (const, override));
	MOCK_METHOD(ReadDataRegisterNotEmpty, get_SR_RXNE, (), (const, override));
	MOCK_METHOD(TransmissionComplete, get_SR_TC, (), (const, override));
	MOCK_METHOD(TransmitDataRegisterEmpty, get_SR_TXE, (), (const, override));
	MOCK_METHOD(LinBreakDetectionFlag, get_SR_LBD, (), (const, override));
	MOCK_METHOD(CtsFlag, get_SR_CTS, (), (const, override));
	MOCK_METHOD(void, set_SR_RXNE, (ReadDataRegisterNotEmpty), (override));
	MOCK_METHOD(void, set_SR_TC, (TransmissionComplete), (override));
	MOCK_METHOD(void, set_SR_LBD, (LinBreakDetectionFlag), (override));
	MOCK_METHOD(void, set_SR_CTS, (CtsFlag), (override));

	// DR Fields
	MOCK_METHOD(uint32_t, get_DR_DR, (), (const, override));
	MOCK_METHOD(void, set_DR_DR, (uint32_t), (override));

	// BRR Fields
	MOCK_METHOD(uint32_t, get_BRR_DIV_Fraction, (), (const, override));
	MOCK_METHOD(uint32_t, get_BRR_DIV_Mantissa, (), (const, override));
	MOCK_METHOD(void, set_BRR_DIV_Fraction, (uint32_t), (override));
	MOCK_METHOD(void, set_BRR_DIV_Mantissa, (uint32_t), (override));

	// CR1 Fields
	MOCK_METHOD(SendBreak, get_CR1_SBK, (), (const, override));
	MOCK_METHOD(ReceiverWakeup, get_CR1_RWU, (), (const, override));
	MOCK_METHOD(ReceiverEnable, get_CR1_RE, (), (const, override));
	MOCK_METHOD(TransmitterEnable, get_CR1_TE, (), (const, override));
	MOCK_METHOD(IdleInterruptEnable, get_CR1_IDLEIE, (), (const, override));
	MOCK_METHOD(RxneInterruptEnable, get_CR1_RXNEIE, (), (const, override));
	MOCK_METHOD(TcInterruptEnable, get_CR1_TCIE, (), (const, override));
	MOCK_METHOD(TxeInterruptEnable, get_CR1_TXEIE, (), (const, override));
	MOCK_METHOD(PeInterruptEnable, get_CR1_PEIE, (), (const, override));
	MOCK_METHOD(ParitySelection, get_CR1_PS, (), (const, override));
	MOCK_METHOD(ParityControlEnable, get_CR1_PCE, (), (const, override));
	MOCK_METHOD(WakeupMethod, get_CR1_WAKE, (), (const, override));
	MOCK_METHOD(WordLength, get_CR1_M, (), (const, override));
	MOCK_METHOD(UsartEnable, get_CR1_UE, (), (const, override));
	MOCK_METHOD(OversamplingMode, get_CR1_OVER8, (), (const, override));
	MOCK_METHOD(void, set_CR1_SBK, (SendBreak), (override));
	MOCK_METHOD(void, set_CR1_RWU, (ReceiverWakeup), (override));
	MOCK_METHOD(void, set_CR1_RE, (ReceiverEnable), (override));
	MOCK_METHOD(void, set_CR1_TE, (TransmitterEnable), (override));
	MOCK_METHOD(void, set_CR1_IDLEIE, (IdleInterruptEnable), (override));
	MOCK_METHOD(void, set_CR1_RXNEIE, (RxneInterruptEnable), (override));
	MOCK_METHOD(void, set_CR1_TCIE, (TcInterruptEnable), (override));
	MOCK_METHOD(void, set_CR1_TXEIE, (TxeInterruptEnable), (override));
	MOCK_METHOD(void, set_CR1_PEIE, (PeInterruptEnable), (override));
	MOCK_METHOD(void, set_CR1_PS, (ParitySelection), (override));
	MOCK_METHOD(void, set_CR1_PCE, (ParityControlEnable), (override));
	MOCK_METHOD(void, set_CR1_WAKE, (WakeupMethod), (override));
	MOCK_METHOD(void, set_CR1_M, (WordLength), (override));
	MOCK_METHOD(void, set_CR1_UE, (UsartEnable), (override));
	MOCK_METHOD(void, set_CR1_OVER8, (OversamplingMode), (override));

	// CR2 Fields
	MOCK_METHOD(uint32_t, get_CR2_ADD, (), (const, override));
	MOCK_METHOD(LinBreakDetectionLength, get_CR2_LBDL, (), (const, override));
	MOCK_METHOD(LinBreakDetectionInterruptEnable, get_CR2_LBDIE, (), (const, override));
	MOCK_METHOD(LastBitClockPulse, get_CR2_LBCL, (), (const, override));
	MOCK_METHOD(ClockPhase, get_CR2_CPHA, (), (const, override));
	MOCK_METHOD(ClockPolarity, get_CR2_CPOL, (), (const, override));
	MOCK_METHOD(ClockEnable, get_CR2_CLKEN, (), (const, override));
	MOCK_METHOD(StopBits, get_CR2_STOP, (), (const, override));
	MOCK_METHOD(LinModeEnable, get_CR2_LINEN, (), (const, override));
	MOCK_METHOD(void, set_CR2_ADD, (uint32_t), (override));
	MOCK_METHOD(void, set_CR2_LBDL, (LinBreakDetectionLength), (override));
	MOCK_METHOD(void, set_CR2_LBDIE, (LinBreakDetectionInterruptEnable), (override));
	MOCK_METHOD(void, set_CR2_LBCL, (LastBitClockPulse), (override));
	MOCK_METHOD(void, set_CR2_CPHA, (ClockPhase), (override));
	MOCK_METHOD(void, set_CR2_CPOL, (ClockPolarity), (override));
	MOCK_METHOD(void, set_CR2_CLKEN, (ClockEnable), (override));
	MOCK_METHOD(void, set_CR2_STOP, (StopBits), (override));
	MOCK_METHOD(void, set_CR2_LINEN, (LinModeEnable), (override));

	// CR3 Fields
	MOCK_METHOD(ErrorInterruptEnable, get_CR3_EIE, (), (const, override));
	MOCK_METHOD(IrdaModeEnable, get_CR3_IREN, (), (const, override));
	MOCK_METHOD(IrdaLowPower, get_CR3_IRLP, (), (const, override));
	MOCK_METHOD(HalfDuplexSelection, get_CR3_HDSEL, (), (const, override));
	MOCK_METHOD(SmartcardNackEnable, get_CR3_NACK, (), (const, override));
	MOCK_METHOD(SmartcardModeEnable, get_CR3_SCEN, (), (const, override));
	MOCK_METHOD(DmaEnableReciever, get_CR3_DMAR, (), (const, override));
	MOCK_METHOD(DmaEnableTransmitter, get_CR3_DMAT, (), (const, override));
	MOCK_METHOD(RtsEnable, get_CR3_RTSE, (), (const, override));
	MOCK_METHOD(CtsEnable, get_CR3_CTSE, (), (const, override));
	MOCK_METHOD(CtsInterruptEnable, get_CR3_CTSIE, (), (const, override));
	MOCK_METHOD(OneSampleBitMethodEnable, get_CR3_ONEBIT, (), (const, override));
	MOCK_METHOD(void, set_CR3_EIE, (ErrorInterruptEnable), (override));
	MOCK_METHOD(void, set_CR3_IREN, (IrdaModeEnable), (override));
	MOCK_METHOD(void, set_CR3_IRLP, (IrdaLowPower), (override));
	MOCK_METHOD(void, set_CR3_HDSEL, (HalfDuplexSelection), (override));
	MOCK_METHOD(void, set_CR3_NACK, (SmartcardNackEnable), (override));
	MOCK_METHOD(void, set_CR3_SCEN, (SmartcardModeEnable), (override));
	MOCK_METHOD(void, set_CR3_DMAR, (DmaEnableReciever), (override));
	MOCK_METHOD(void, set_CR3_DMAT, (DmaEnableTransmitter), (override));
	MOCK_METHOD(void, set_CR3_RTSE, (RtsEnable), (override));
	MOCK_METHOD(void, set_CR3_CTSE, (CtsEnable), (override));
	MOCK_METHOD(void, set_CR3_CTSIE, (CtsInterruptEnable), (override));
	MOCK_METHOD(void, set_CR3_ONEBIT, (OneSampleBitMethodEnable), (override));

	// GTPR Fields
	MOCK_METHOD(uint32_t, get_GTPR_PSC, (), (const, override));
	MOCK_METHOD(uint32_t, get_GTPR_GT, (), (const, override));
	MOCK_METHOD(void, set_GTPR_PSC, (uint32_t), (override));
	MOCK_METHOD(void, set_GTPR_GT, (uint32_t), (override));
};

class UsartPeripheralTest : public ::testing::Test
{
public:
	UsartPeripheralTest() : registerMap(registers), usart(registerMap) { }
protected:
	void SetUp() override { std::memset(&registers, 0, sizeof(registers)); } 
	void TearDown() override { SetUp(); }
	UsartRegisters registers = { };
	UsartRegisterMap registerMap;
	UsartPeripheral usart;
};

class UsartPeripheralTestWithMock : public ::testing::Test
{
public:
	UsartPeripheralTestWithMock() : usart(registerMap) { }
protected:
	MockUsartRegisterMap registerMap;
	UsartPeripheral usart;
};