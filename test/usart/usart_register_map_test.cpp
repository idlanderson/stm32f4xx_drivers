#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "usart_register_map.hpp"

using namespace stm32::usart;

TEST(SR, PE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.PE = (ParityError)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(SR, FE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.FE = (FramingError)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(SR, NF)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.NF = (NoiceDetectedFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(SR, ORE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.ORE = (OverrunError)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(SR, IDLE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.IDLE = (IdleLineDetected)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(SR, RXNE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.RXNE = (ReadDataRegisterNotEmpty)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(SR, TC)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.TC = (TransmissionComplete)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(SR, TXE)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.TXE = (TransmitDataRegisterEmpty)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(SR, LBD)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.LBD = (LinBreakDetectionFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(SR, CTS)
{
	SR_t reg;
	reg.Value = 0U;
	reg.Fields.CTS = (CtsFlag)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(DR, DR)
{
	DR_t reg;
	reg.Value = 0U;
	reg.Fields.DR = (uint32_t)511U;
	EXPECT_EQ(0x000001FFU, reg.Value);
}

TEST(BRR, DIV_Fraction)
{
	BRR_t reg;
	reg.Value = 0U;
	reg.Fields.DIV_Fraction = (uint32_t)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(BRR, DIV_Mantissa)
{
	BRR_t reg;
	reg.Value = 0U;
	reg.Fields.DIV_Mantissa = (uint32_t)4095U;
	EXPECT_EQ(0x0000FFF0U, reg.Value);
}

TEST(CR1, SBK)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.SBK = (SendBreak)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(CR1, RWU)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.RWU = (ReceiverWakeup)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(CR1, RE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.RE = (ReceiverEnable)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(CR1, TE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.TE = (TransmitterEnable)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(CR1, IDLEIE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.IDLEIE = (IdleInterruptEnable)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(CR1, RXNEIE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.RXNEIE = (RxneInterruptEnable)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(CR1, TCIE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.TCIE = (TcInterruptEnable)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(CR1, TXEIE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.TXEIE = (TxeInterruptEnable)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(CR1, PEIE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.PEIE = (PeInterruptEnable)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(CR1, PS)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.PS = (ParitySelection)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(CR1, PCE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.PCE = (ParityControlEnable)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(CR1, WAKE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.WAKE = (WakeupMethod)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(CR1, M)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.M = (WordLength)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(CR1, UE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.UE = (UsartEnable)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(CR1, OVER8)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.OVER8 = (OversamplingMode)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(CR2, ADD)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.ADD = (uint32_t)15U;
	EXPECT_EQ(0x0000000FU, reg.Value);
}

TEST(CR2, LBDL)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.LBDL = (LinBreakDetectionLength)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(CR2, LBDIE)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.LBDIE = (LinBreakDetectionInterruptEnable)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(CR2, LBCL)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.LBCL = (LastBitClockPulse)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(CR2, CPHA)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.CPHA = (ClockPhase)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(CR2, CPOL)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.CPOL = (ClockPolarity)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(CR2, CLKEN)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.CLKEN = (ClockEnable)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(CR2, STOP)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.STOP = (StopBits)3U;
	EXPECT_EQ(0x00003000U, reg.Value);
}

TEST(CR2, LINEN)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.LINEN = (LinModeEnable)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(CR3, EIE)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.EIE = (ErrorInterruptEnable)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(CR3, IREN)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.IREN = (IrdaModeEnable)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(CR3, IRLP)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.IRLP = (IrdaLowPower)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(CR3, HDSEL)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.HDSEL = (HalfDuplexSelection)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(CR3, NACK)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.NACK = (SmartcardNackEnable)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(CR3, SCEN)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.SCEN = (SmartcardModeEnable)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(CR3, DMAR)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.DMAR = (DmaEnableReciever)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(CR3, DMAT)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.DMAT = (DmaEnableTransmitter)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(CR3, RTSE)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.RTSE = (RtsEnable)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(CR3, CTSE)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.CTSE = (CtsEnable)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(CR3, CTSIE)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.CTSIE = (CtsInterruptEnable)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(CR3, ONEBIT)
{
	CR3_t reg;
	reg.Value = 0U;
	reg.Fields.ONEBIT = (OneSampleBitMethodEnable)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(GTPR, PSC)
{
	GTPR_t reg;
	reg.Value = 0U;
	reg.Fields.PSC = (uint32_t)255U;
	EXPECT_EQ(0x000000FFU, reg.Value);
}

TEST(GTPR, GT)
{
	GTPR_t reg;
	reg.Value = 0U;
	reg.Fields.GT = (uint32_t)255U;
	EXPECT_EQ(0x0000FF00U, reg.Value);
}

