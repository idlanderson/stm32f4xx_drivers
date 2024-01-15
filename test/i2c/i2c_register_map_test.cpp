#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "i2c_register_map.hpp"

using namespace stm32::i2c;

TEST(CR1, PE)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.PE = (PeripheralEnable)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(CR1, NOSTRETCH)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.NOSTRETCH = (ClockStretchingDisable)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(CR1, START)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.START = (StartGeneration)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(CR1, STOP)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.STOP = (StopGeneration)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(CR1, ACK)
{
	CR1_t reg;
	reg.Value = 0U;
	reg.Fields.ACK = (AcknowledgeEnable)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(CR2, FREQ)
{
	CR2_t reg;
	reg.Value = 0U;
	reg.Fields.FREQ = (uint32_t)63U;
	EXPECT_EQ(0x0000003FU, reg.Value);
}

TEST(OAR1, ADD)
{
	OAR1_t reg;
	reg.Value = 0U;
	reg.Fields.ADD = (uint32_t)1023U;
	EXPECT_EQ(0x000003FFU, reg.Value);
}

TEST(OAR1, RESERVEDBIT14)
{
	OAR1_t reg;
	reg.Value = 0U;
	reg.Fields.RESERVEDBIT14 = (uint32_t)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(OAR1, ADDMODE)
{
	OAR1_t reg;
	reg.Value = 0U;
	reg.Fields.ADDMODE = (AddressingMode)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(OAR2, ENDUAL)
{
	OAR2_t reg;
	reg.Value = 0U;
	reg.Fields.ENDUAL = (DualAddressingModeEnable)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(OAR2, ADD2)
{
	OAR2_t reg;
	reg.Value = 0U;
	reg.Fields.ADD2 = (uint32_t)127U;
	EXPECT_EQ(0x000000FEU, reg.Value);
}

TEST(DR, DR)
{
	DR_t reg;
	reg.Value = 0U;
	reg.Fields.DR = (uint32_t)255U;
	EXPECT_EQ(0x000000FFU, reg.Value);
}

TEST(SR1, SB)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.SB = (StartBit)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(SR1, ADDR)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.ADDR = (AddressSentMatched)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(SR1, BTF)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.BTF = (ByteTransferFinished)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(SR1, STOPF)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.STOPF = (StopDetection)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(SR1, RxNE)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.RxNE = (DataRegisterNotEmpty)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(SR1, TxE)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.TxE = (DataRegisterEmpty)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(SR1, BERR)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.BERR = (BusError)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(SR1, ARLO)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.ARLO = (ArbitrationLost)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(SR1, AF)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.AF = (AcknowledgeFailure)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(SR1, OVR)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.OVR = (OverrunUnderrun)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(SR1, TIMEOUT)
{
	SR1_t reg;
	reg.Value = 0U;
	reg.Fields.TIMEOUT = (TimeoutError)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(SR2, MSL)
{
	SR2_t reg;
	reg.Value = 0U;
	reg.Fields.MSL = (MasterSlave)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(SR2, BUSY)
{
	SR2_t reg;
	reg.Value = 0U;
	reg.Fields.BUSY = (BusBusy)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(SR2, TRA)
{
	SR2_t reg;
	reg.Value = 0U;
	reg.Fields.TRA = (TransmitterReceiver)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(CCR, CCR)
{
	CCR_t reg;
	reg.Value = 0U;
	reg.Fields.CCR = (uint32_t)4095U;
	EXPECT_EQ(0x00000FFFU, reg.Value);
}

TEST(CCR, DUTY)
{
	CCR_t reg;
	reg.Value = 0U;
	reg.Fields.DUTY = (FmModeDutyCycle)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(CCR, FS)
{
	CCR_t reg;
	reg.Value = 0U;
	reg.Fields.FS = (MasterModeSelection)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(TRISE, TRISE)
{
	TRISE_t reg;
	reg.Value = 0U;
	reg.Fields.TRISE = (uint32_t)63U;
	EXPECT_EQ(0x0000003FU, reg.Value);
}

