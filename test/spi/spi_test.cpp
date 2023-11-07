#include "spi_register_map_mock.hpp"
#include "spi.hpp"
#include <cstring>
#include <iostream>

using namespace stm32::spi;
using namespace testing;
using ::testing::Return;

class SpiPeripheralTest : public ::testing::Test
{
public:
    SpiPeripheralTest() : registerMap(registers), spi(registerMap) { }
protected:

    void SetUp() override 
    {
        std::memset(&registers, 0, sizeof(registers));
    }

    void TearDown() override 
    {
        SetUp();
    }

    SpiRegisters registers = {};
    SpiRegisterMap registerMap;
    SpiPeripheral spi;
};

class SpiPeripheralTestWithMock : public ::testing::Test
{
public:
    SpiPeripheralTestWithMock() : spi(registerMap) { }
protected:
    MockSpiRegisterMap registerMap;
    SpiPeripheral spi;
};

TEST_F(SpiPeripheralTest, SetDeviceModeAllValues)
{
    spi.SetDeviceMode(MasterSelection::Slave);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetDeviceMode(MasterSelection::Master);
    EXPECT_EQ(0x00000004U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetBidirectionalModeAllValues)
{
    spi.SetBidirectionalMode(BidirectionalDataModeEnable::_2LineUnidirectional);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetBidirectionalMode(BidirectionalDataModeEnable::_1LineBidirectional);
    EXPECT_EQ(0x00008000U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetOutputEnableInBidirectionalModeAllValues)
{
    spi.SetOutputEnableInBidirectionalMode(OutputEnableInBidirectionalMode::Disabled);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetOutputEnableInBidirectionalMode(OutputEnableInBidirectionalMode::Enabled);
    EXPECT_EQ(0x00004000U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetRxOnlyAllValues)
{
    spi.SetRxOnly(ReceiveOnly::FullDuplex);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetRxOnly(ReceiveOnly::OutputDisabled);
    EXPECT_EQ(0x00000400U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetBusConfigAllValues)
{
    registers.CR1.Value = 0x00000000U;
    spi.SetBusConfig(BusConfig::FullDuplex);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);

    registers.CR1.Value = 0x00000000U;
    spi.SetBusConfig(BusConfig::HalfDuplex);
    EXPECT_EQ(0x00008000U, registers.CR1.Value);

    registers.CR1.Value = 0x00000000U;
    spi.SetBusConfig(BusConfig::SimplexRxOnly);
    EXPECT_EQ(0x00000400U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, GetDataFrameFormat)
{
    registers.CR1.Value = 0x00000000U;
    auto dff1 = spi.GetDataFrameFormat();
    EXPECT_EQ(DataFrameFormat::_8Bit, dff1);

    registers.CR1.Value = 0x00000800U;
    auto dff2 = spi.GetDataFrameFormat();
    EXPECT_EQ(DataFrameFormat::_16Bit, dff2);
}

TEST_F(SpiPeripheralTest, SetDataFrameFormat)
{
    spi.SetDataFrameFormat(DataFrameFormat::_8Bit);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetDataFrameFormat(DataFrameFormat::_16Bit);
    EXPECT_EQ(0x00000800U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetClockPolarity)
{
    spi.SetClockPolarity(ClockPolarity::CkTo0WhenIdle);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetClockPolarity(ClockPolarity::CkTo1WhenIdle);
    EXPECT_EQ(0x00000002U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetClockPhase)
{
    spi.SetClockPhase(ClockPhase::FirstClockTransition);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetClockPhase(ClockPhase::SecondClockTransition);
    EXPECT_EQ(0x00000001U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetBaudRate)
{
    spi.SetBaudRate(BaudRateControl::FpclkDiv2);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetBaudRate(BaudRateControl::FpclkDiv4);
    EXPECT_EQ(0x00000008U, registers.CR1.Value);
    spi.SetBaudRate(BaudRateControl::FpclkDiv8);
    EXPECT_EQ(0x00000010U, registers.CR1.Value);
    spi.SetBaudRate(BaudRateControl::FpclkDiv16);
    EXPECT_EQ(0x00000018U, registers.CR1.Value);
    spi.SetBaudRate(BaudRateControl::FpclkDiv32);
    EXPECT_EQ(0x00000020U, registers.CR1.Value);
    spi.SetBaudRate(BaudRateControl::FpclkDiv64);
    EXPECT_EQ(0x00000028U, registers.CR1.Value);
    spi.SetBaudRate(BaudRateControl::FpclkDiv128);
    EXPECT_EQ(0x00000030U, registers.CR1.Value);
    spi.SetBaudRate(BaudRateControl::FpclkDiv256);
    EXPECT_EQ(0x00000038U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetSlaveManagement)
{
    spi.SetSlaveManagement(SoftwareSlaveManagement::Disabled);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetSlaveManagement(SoftwareSlaveManagement::Enabled);
    EXPECT_EQ(0x00000200U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetInternalSlaveSelect)
{
    spi.SetInternalSlaveSelect(InternalSlaveSelect::DriveNssLow);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetInternalSlaveSelect(InternalSlaveSelect::DriveNssHigh);
    EXPECT_EQ(0x00000100U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, SetSlaveSelectOutputEnabled)
{
    spi.SetSlaveSelectOutputEnabled(SsOutputEnable::Disabled);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
    spi.SetSlaveSelectOutputEnabled(SsOutputEnable::Enabled);
    EXPECT_EQ(0x00000004U, registers.CR2.Value);
}

TEST_F(SpiPeripheralTest, SetEnabled)
{
    spi.SetEnabled(SpiEnable::Disabled);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
    spi.SetEnabled(SpiEnable::Enabled);
    EXPECT_EQ(0x00000040U, registers.CR1.Value);
}

TEST_F(SpiPeripheralTest, IsReceiveBufferNotEmpty)
{
    registers.SR.Value = 0x00000000U;
    EXPECT_FALSE(spi.IsReceiveBufferNotEmpty());
    registers.SR.Value = 0x00000001U;
    EXPECT_TRUE(spi.IsReceiveBufferNotEmpty());
}

TEST_F(SpiPeripheralTest, IsTransmitBufferEmpty)
{
    registers.SR.Value = 0x00000000U;
    EXPECT_FALSE(spi.IsTransmitBufferEmpty());
    registers.SR.Value = 0x00000002U;
    EXPECT_TRUE(spi.IsTransmitBufferEmpty());
}

TEST_F(SpiPeripheralTest, HasCrcErrorOccurred)
{
    registers.SR.Value = 0x00000000U;
    EXPECT_FALSE(spi.HasCrcErrorOccurred());
    registers.SR.Value = 0x00000010U;
    EXPECT_TRUE(spi.HasCrcErrorOccurred());
}

TEST_F(SpiPeripheralTest, HasModeFaultOccurred)
{
    registers.SR.Value = 0x00000000U;
    EXPECT_FALSE(spi.HasModeFaultOccurred());
    registers.SR.Value = 0x00000020U;
    EXPECT_TRUE(spi.HasModeFaultOccurred());
}

TEST_F(SpiPeripheralTest, HasOverrunOccurred)
{
    registers.SR.Value = 0x00000000U;
    EXPECT_FALSE(spi.HasOverrunOccurred());
    registers.SR.Value = 0x00000040U;
    EXPECT_TRUE(spi.HasOverrunOccurred());
}

TEST_F(SpiPeripheralTest, IsBusy)
{
    registers.SR.Value = 0x00000000U;
    EXPECT_FALSE(spi.IsBusy());
    registers.SR.Value = 0x00000080U;
    EXPECT_TRUE(spi.IsBusy());
}

TEST_F(SpiPeripheralTest, SendData8Bit)
{
    registers.CR1.Fields.DFF = DataFrameFormat::_8Bit;
    registers.SR.Fields.TXE = TransmitBufferEmpty::Empty;

    spi.SendData({0xABU, 0xCDU});

    EXPECT_EQ(0x000000CDU, registers.DR.Value);
}

TEST_F(SpiPeripheralTest, SendData16Bit)
{
    registers.CR1.Fields.DFF = DataFrameFormat::_16Bit;
    registers.SR.Fields.TXE = TransmitBufferEmpty::Empty;

    spi.SendData({0xABU, 0xCDU});

    EXPECT_EQ(0x0000ABCDU, registers.DR.Value);
}

TEST_F(SpiPeripheralTest, ReceiveData8Bit)
{
    registers.CR1.Fields.DFF = DataFrameFormat::_8Bit;
    registers.SR.Fields.RXNE = ReceiveBufferNotEmpty::NotEmpty;
    registers.DR.Fields.DR = 0xABCDU;

    auto data = spi.ReceiveData(1U);

    EXPECT_THAT(data, ElementsAre(0xCDU));
}

TEST_F(SpiPeripheralTest, ReceiveData16Bit)
{
    registers.CR1.Fields.DFF = DataFrameFormat::_16Bit;
    registers.SR.Fields.RXNE = ReceiveBufferNotEmpty::NotEmpty;
    registers.DR.Fields.DR = 0xABCDU;

    auto data = spi.ReceiveData(2U);

    EXPECT_THAT(data, ElementsAre(0xABU, 0xCDU));
}

TEST_F(SpiPeripheralTestWithMock, SendData8Bit)
{
    EXPECT_CALL(registerMap, get_CR1_DFF)
        .Times(1)
        .WillOnce(Return(DataFrameFormat::_8Bit));

    EXPECT_CALL(registerMap, get_SR_TXE).Times(4).WillRepeatedly(Return(TransmitBufferEmpty::Empty));

    EXPECT_CALL(registerMap, set_DR_DR(0x00000001U)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x00000002U)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x00000003U)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x00000004U)).Times(1);

    std::vector<uint8_t> data = { 1U, 2U, 3U, 4U };
    spi.SendData(data);
}

TEST_F(SpiPeripheralTestWithMock, SendDataSixteenBit)
{
    EXPECT_CALL(registerMap, get_CR1_DFF)
        .Times(1)
        .WillOnce(Return(DataFrameFormat::_16Bit));

    EXPECT_CALL(registerMap, get_SR_TXE).Times(2).WillRepeatedly(Return(TransmitBufferEmpty::Empty));

    EXPECT_CALL(registerMap, set_DR_DR(0x00000102U)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x00000304U)).Times(1);

    std::vector<uint8_t> data = { 1U, 2U, 3U, 4U };
    spi.SendData(data);
}

TEST_F(SpiPeripheralTestWithMock, ReceiveDataEightBit)
{
    EXPECT_CALL(registerMap, get_CR1_DFF)
        .Times(1)
        .WillOnce(Return(DataFrameFormat::_8Bit));
    
    EXPECT_CALL(registerMap, get_SR_RXNE).Times(4).WillRepeatedly(Return(ReceiveBufferNotEmpty::NotEmpty));

    EXPECT_CALL(registerMap, get_DR_DR)
        .Times(4)
        .WillOnce(Return(1U))
        .WillOnce(Return(2U))
        .WillOnce(Return(3U))
        .WillOnce(Return(4U));

    std::vector<uint8_t> data = spi.ReceiveData(4U);

    EXPECT_THAT(data, ElementsAre(1U, 2U, 3U, 4U));
}

TEST_F(SpiPeripheralTestWithMock, ReceiveDataSixteenBit)
{
    EXPECT_CALL(registerMap, get_CR1_DFF)
        .Times(1)
        .WillOnce(Return(DataFrameFormat::_16Bit));
    
    EXPECT_CALL(registerMap, get_SR_RXNE).Times(2).WillRepeatedly(Return(ReceiveBufferNotEmpty::NotEmpty));

    EXPECT_CALL(registerMap, get_DR_DR)
        .Times(2)
        .WillOnce(Return(0x00000102U))
        .WillOnce(Return(0x00000304U));

    std::vector<uint8_t> data = spi.ReceiveData(4U);

    EXPECT_THAT(data, ElementsAre(1U, 2U, 3U, 4U));
}