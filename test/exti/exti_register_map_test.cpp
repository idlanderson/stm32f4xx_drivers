#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "exti_register_map.hpp"

using namespace stm32::exti;

TEST(IMR, MR0)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR0 = (InterruptMask)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(IMR, MR1)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR1 = (InterruptMask)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(IMR, MR2)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR2 = (InterruptMask)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(IMR, MR3)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR3 = (InterruptMask)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(IMR, MR4)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR4 = (InterruptMask)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(IMR, MR5)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR5 = (InterruptMask)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(IMR, MR6)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR6 = (InterruptMask)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(IMR, MR7)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR7 = (InterruptMask)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(IMR, MR8)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR8 = (InterruptMask)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(IMR, MR9)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR9 = (InterruptMask)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(IMR, MR10)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR10 = (InterruptMask)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(IMR, MR11)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR11 = (InterruptMask)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(IMR, MR12)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR12 = (InterruptMask)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(IMR, MR13)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR13 = (InterruptMask)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(IMR, MR14)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR14 = (InterruptMask)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(IMR, MR15)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR15 = (InterruptMask)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(IMR, MR16)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR16 = (InterruptMask)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(IMR, MR17)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR17 = (InterruptMask)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(IMR, MR18)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR18 = (InterruptMask)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(IMR, MR19)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR19 = (InterruptMask)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(IMR, MR20)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR20 = (InterruptMask)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(IMR, MR21)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR21 = (InterruptMask)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(IMR, MR22)
{
	IMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR22 = (InterruptMask)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(EMR, MR0)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR0 = (InterruptMask)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(EMR, MR1)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR1 = (InterruptMask)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(EMR, MR2)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR2 = (InterruptMask)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(EMR, MR3)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR3 = (InterruptMask)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(EMR, MR4)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR4 = (InterruptMask)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(EMR, MR5)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR5 = (InterruptMask)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(EMR, MR6)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR6 = (InterruptMask)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(EMR, MR7)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR7 = (InterruptMask)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(EMR, MR8)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR8 = (InterruptMask)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(EMR, MR9)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR9 = (InterruptMask)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(EMR, MR10)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR10 = (InterruptMask)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(EMR, MR11)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR11 = (InterruptMask)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(EMR, MR12)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR12 = (InterruptMask)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(EMR, MR13)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR13 = (InterruptMask)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(EMR, MR14)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR14 = (InterruptMask)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(EMR, MR15)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR15 = (InterruptMask)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(EMR, MR16)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR16 = (InterruptMask)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(EMR, MR17)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR17 = (InterruptMask)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(EMR, MR18)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR18 = (InterruptMask)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(EMR, MR19)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR19 = (InterruptMask)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(EMR, MR20)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR20 = (InterruptMask)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(EMR, MR21)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR21 = (InterruptMask)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(EMR, MR22)
{
	EMR_t reg;
	reg.Value = 0U;
	reg.Fields.MR22 = (InterruptMask)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(RTSR, TR0)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR0 = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(RTSR, TR1)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR1 = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(RTSR, TR2)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR2 = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(RTSR, TR3)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR3 = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(RTSR, TR4)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR4 = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(RTSR, TR5)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR5 = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(RTSR, TR6)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR6 = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(RTSR, TR7)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR7 = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(RTSR, TR8)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR8 = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(RTSR, TR9)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR9 = (EnableFlag)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(RTSR, TR10)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR10 = (EnableFlag)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(RTSR, TR11)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR11 = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(RTSR, TR12)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR12 = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(RTSR, TR13)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR13 = (EnableFlag)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(RTSR, TR14)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR14 = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(RTSR, TR15)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR15 = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(RTSR, TR16)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR16 = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(RTSR, TR17)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR17 = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(RTSR, TR18)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR18 = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(RTSR, TR19)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR19 = (EnableFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(RTSR, TR20)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR20 = (EnableFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(RTSR, TR21)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR21 = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(RTSR, TR22)
{
	RTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR22 = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(FTSR, TR0)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR0 = (EnableFlag)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(FTSR, TR1)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR1 = (EnableFlag)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(FTSR, TR2)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR2 = (EnableFlag)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(FTSR, TR3)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR3 = (EnableFlag)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(FTSR, TR4)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR4 = (EnableFlag)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(FTSR, TR5)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR5 = (EnableFlag)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(FTSR, TR6)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR6 = (EnableFlag)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(FTSR, TR7)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR7 = (EnableFlag)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(FTSR, TR8)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR8 = (EnableFlag)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(FTSR, TR9)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR9 = (EnableFlag)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(FTSR, TR10)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR10 = (EnableFlag)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(FTSR, TR11)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR11 = (EnableFlag)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(FTSR, TR12)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR12 = (EnableFlag)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(FTSR, TR13)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR13 = (EnableFlag)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(FTSR, TR14)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR14 = (EnableFlag)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(FTSR, TR15)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR15 = (EnableFlag)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(FTSR, TR16)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR16 = (EnableFlag)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(FTSR, TR17)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR17 = (EnableFlag)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(FTSR, TR18)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR18 = (EnableFlag)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(FTSR, TR19)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR19 = (EnableFlag)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(FTSR, TR20)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR20 = (EnableFlag)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(FTSR, TR21)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR21 = (EnableFlag)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(FTSR, TR22)
{
	FTSR_t reg;
	reg.Value = 0U;
	reg.Fields.TR22 = (EnableFlag)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(SWIER, SWIER0)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER0 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(SWIER, SWIER1)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER1 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(SWIER, SWIER2)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER2 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(SWIER, SWIER3)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER3 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(SWIER, SWIER4)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER4 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(SWIER, SWIER5)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER5 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(SWIER, SWIER6)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER6 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(SWIER, SWIER7)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER7 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(SWIER, SWIER8)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER8 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(SWIER, SWIER9)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER9 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(SWIER, SWIER10)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER10 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(SWIER, SWIER11)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER11 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(SWIER, SWIER12)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER12 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(SWIER, SWIER13)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER13 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(SWIER, SWIER14)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER14 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(SWIER, SWIER15)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER15 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(SWIER, SWIER16)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER16 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(SWIER, SWIER17)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER17 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(SWIER, SWIER18)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER18 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(SWIER, SWIER19)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER19 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(SWIER, SWIER20)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER20 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(SWIER, SWIER21)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER21 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(SWIER, SWIER22)
{
	SWIER_t reg;
	reg.Value = 0U;
	reg.Fields.SWIER22 = (SoftwareInterrupt)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

TEST(PR, PR0)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR0 = (PendingBit)1U;
	EXPECT_EQ(0x00000001U, reg.Value);
}

TEST(PR, PR1)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR1 = (PendingBit)1U;
	EXPECT_EQ(0x00000002U, reg.Value);
}

TEST(PR, PR2)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR2 = (PendingBit)1U;
	EXPECT_EQ(0x00000004U, reg.Value);
}

TEST(PR, PR3)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR3 = (PendingBit)1U;
	EXPECT_EQ(0x00000008U, reg.Value);
}

TEST(PR, PR4)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR4 = (PendingBit)1U;
	EXPECT_EQ(0x00000010U, reg.Value);
}

TEST(PR, PR5)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR5 = (PendingBit)1U;
	EXPECT_EQ(0x00000020U, reg.Value);
}

TEST(PR, PR6)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR6 = (PendingBit)1U;
	EXPECT_EQ(0x00000040U, reg.Value);
}

TEST(PR, PR7)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR7 = (PendingBit)1U;
	EXPECT_EQ(0x00000080U, reg.Value);
}

TEST(PR, PR8)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR8 = (PendingBit)1U;
	EXPECT_EQ(0x00000100U, reg.Value);
}

TEST(PR, PR9)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR9 = (PendingBit)1U;
	EXPECT_EQ(0x00000200U, reg.Value);
}

TEST(PR, PR10)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR10 = (PendingBit)1U;
	EXPECT_EQ(0x00000400U, reg.Value);
}

TEST(PR, PR11)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR11 = (PendingBit)1U;
	EXPECT_EQ(0x00000800U, reg.Value);
}

TEST(PR, PR12)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR12 = (PendingBit)1U;
	EXPECT_EQ(0x00001000U, reg.Value);
}

TEST(PR, PR13)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR13 = (PendingBit)1U;
	EXPECT_EQ(0x00002000U, reg.Value);
}

TEST(PR, PR14)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR14 = (PendingBit)1U;
	EXPECT_EQ(0x00004000U, reg.Value);
}

TEST(PR, PR15)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR15 = (PendingBit)1U;
	EXPECT_EQ(0x00008000U, reg.Value);
}

TEST(PR, PR16)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR16 = (PendingBit)1U;
	EXPECT_EQ(0x00010000U, reg.Value);
}

TEST(PR, PR17)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR17 = (PendingBit)1U;
	EXPECT_EQ(0x00020000U, reg.Value);
}

TEST(PR, PR18)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR18 = (PendingBit)1U;
	EXPECT_EQ(0x00040000U, reg.Value);
}

TEST(PR, PR19)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR19 = (PendingBit)1U;
	EXPECT_EQ(0x00080000U, reg.Value);
}

TEST(PR, PR20)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR20 = (PendingBit)1U;
	EXPECT_EQ(0x00100000U, reg.Value);
}

TEST(PR, PR21)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR21 = (PendingBit)1U;
	EXPECT_EQ(0x00200000U, reg.Value);
}

TEST(PR, PR22)
{
	PR_t reg;
	reg.Value = 0U;
	reg.Fields.PR22 = (PendingBit)1U;
	EXPECT_EQ(0x00400000U, reg.Value);
}

