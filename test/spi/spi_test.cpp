#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "spi.hpp"
#include "spi_register_map_mock.hpp"

using namespace stm32::spi;
using namespace testing;
using ::testing::Return;

class SpiPeripheralTest : public ::testing::Test
{
public:
    SpiPeripheralTest() : spi(spiRegisters) {}
protected:
    MockSpiRegisterMap spiRegisters;
    SpiPeripheral spi;
};

TEST_F(SpiPeripheralTest, SetDeviceModeMaster)
{
    EXPECT_CALL(spiRegisters, set_CR1_MSTR(MasterSelection::Value1)).Times(1);

    spi.SetDeviceMode(MasterSelection::Value1);
}

TEST_F(SpiPeripheralTest, SetDeviceModeSlave)
{
    EXPECT_CALL(spiRegisters, set_CR1_MSTR(MasterSelection::Value0)).Times(1);

    spi.SetDeviceMode(MasterSelection::Value0);
}

TEST_F(SpiPeripheralTest, SendDataEightBit)
{
    EXPECT_CALL(spiRegisters, get_CR1_DFF)
        .Times(1)
        .WillOnce(Return(DataFrameFormat::Value0));

    EXPECT_CALL(spiRegisters, get_SR_TXE).Times(4).WillRepeatedly(Return(TransmitBufferEmpty::Value1));

    EXPECT_CALL(spiRegisters, set_DR_DR(0x00000001U)).Times(1);
    EXPECT_CALL(spiRegisters, set_DR_DR(0x00000002U)).Times(1);
    EXPECT_CALL(spiRegisters, set_DR_DR(0x00000003U)).Times(1);
    EXPECT_CALL(spiRegisters, set_DR_DR(0x00000004U)).Times(1);

    std::vector<uint8_t> data = { 1U, 2U, 3U, 4U };
    spi.SendData(data);
}

TEST_F(SpiPeripheralTest, SendDataSixteenBit)
{
    EXPECT_CALL(spiRegisters, get_CR1_DFF)
        .Times(1)
        .WillOnce(Return(DataFrameFormat::Value1));

    EXPECT_CALL(spiRegisters, get_SR_TXE).Times(2).WillRepeatedly(Return(TransmitBufferEmpty::Value1));

    EXPECT_CALL(spiRegisters, set_DR_DR(0x00000102U)).Times(1);
    EXPECT_CALL(spiRegisters, set_DR_DR(0x00000304U)).Times(1);

    std::vector<uint8_t> data = { 1U, 2U, 3U, 4U };
    spi.SendData(data);
}

TEST_F(SpiPeripheralTest, ReceiveDataEightBit)
{
    EXPECT_CALL(spiRegisters, get_CR1_DFF)
        .Times(1)
        .WillOnce(Return(DataFrameFormat::Value0));
    
    EXPECT_CALL(spiRegisters, get_SR_RXNE).Times(4).WillRepeatedly(Return(ReceiveBufferNotEmpty::Value1));

    EXPECT_CALL(spiRegisters, get_DR_DR)
        .Times(4)
        .WillOnce(Return(1U))
        .WillOnce(Return(2U))
        .WillOnce(Return(3U))
        .WillOnce(Return(4U));

    std::vector<uint8_t> data = spi.ReceiveData(4U);

    EXPECT_THAT(data, Contains(4));
    EXPECT_THAT(data, ElementsAre(1U, 2U, 3U, 4U));
}

TEST_F(SpiPeripheralTest, ReceiveDataSixteenBit)
{
    EXPECT_CALL(spiRegisters, get_CR1_DFF)
        .Times(1)
        .WillOnce(Return(DataFrameFormat::Value1));
    
    EXPECT_CALL(spiRegisters, get_SR_RXNE).Times(2).WillRepeatedly(Return(ReceiveBufferNotEmpty::Value1));

    EXPECT_CALL(spiRegisters, get_DR_DR)
        .Times(2)
        .WillOnce(Return(0x00000102U))
        .WillOnce(Return(0x00000304U));

    std::vector<uint8_t> data = spi.ReceiveData(4U);

    EXPECT_THAT(data, Contains(4));
    EXPECT_THAT(data, ElementsAre(1U, 2U, 3U, 4U));
}