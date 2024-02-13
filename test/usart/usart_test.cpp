#include "usart.hpp"
#include "usart_register_map_mock.hpp"

TEST_F(UsartPeripheralTest, SetMode)
{
    usart.SetMode(UsartMode::Rx);
    EXPECT_EQ(0x00000004U, registers.CR1.Value);

    usart.SetMode(UsartMode::Tx);
    EXPECT_EQ(0x00000008U, registers.CR1.Value);

    usart.SetMode(UsartMode::RxTx);
    EXPECT_EQ(0x0000000CU, registers.CR1.Value);

    usart.SetMode(UsartMode::Disabled);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
}

TEST_F(UsartPeripheralTest, SetParity)
{
    usart.SetParity(Parity::Even);
    EXPECT_EQ(0x00000400U, registers.CR1.Value);

    usart.SetParity(Parity::Odd);
    EXPECT_EQ(0x00000600U, registers.CR1.Value);

    usart.SetParity(Parity::None);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
}

TEST_F(UsartPeripheralTest, SetWordLength)
{
    usart.SetWordLength(WordLength::_9DataBits);
    EXPECT_EQ(0x00001000U, registers.CR1.Value);

    usart.SetWordLength(WordLength::_8DataBits);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
}

TEST_F(UsartPeripheralTest, SetStopBits)
{
    usart.SetStopBits(StopBits::_05StopBit);
    EXPECT_EQ(0x00001000U, registers.CR2.Value);

    usart.SetStopBits(StopBits::_2StopBits);
    EXPECT_EQ(0x00002000U, registers.CR2.Value);

    usart.SetStopBits(StopBits::_15StopBits);
    EXPECT_EQ(0x00003000U, registers.CR2.Value);

    usart.SetStopBits(StopBits::_1StopBit);
    EXPECT_EQ(0x00000000U, registers.CR2.Value);
}

TEST_F(UsartPeripheralTest, SetHardwareFlowControl)
{
    usart.SetHardwareFlowControl(true, false);
    EXPECT_EQ(0x00000100U, registers.CR3.Value);

    usart.SetHardwareFlowControl(false, true);
    EXPECT_EQ(0x00000200U, registers.CR3.Value);

    usart.SetHardwareFlowControl(true, true);
    EXPECT_EQ(0x00000300U, registers.CR3.Value);

    usart.SetHardwareFlowControl(false, false);
    EXPECT_EQ(0x00000000U, registers.CR3.Value);
}

TEST_F(UsartPeripheralTestWithMock, SendData8BitNoParity)
{
    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_8DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Disabled));

    EXPECT_CALL(registerMap, get_SR_TXE())
        .Times(3)
        .WillRepeatedly(Return(TransmitDataRegisterEmpty::TransferredToShiftRegister));

    EXPECT_CALL(registerMap, set_DR_DR(0x000000ABU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x000000CDU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x000000EFU)).Times(1);

    vector<uint8_t> data = { 0xABU, 0xCDU, 0xEFU };

    usart.SendData(data);
}

TEST_F(UsartPeripheralTestWithMock, SendData8BitWithParity)
{
    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_8DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Enabled));

    EXPECT_CALL(registerMap, get_SR_TXE())
        .Times(3)
        .WillRepeatedly(Return(TransmitDataRegisterEmpty::TransferredToShiftRegister));

    EXPECT_CALL(registerMap, set_DR_DR(0x0000002BU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x0000004DU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x0000006FU)).Times(1);

    vector<uint8_t> data = { 0xABU, 0xCDU, 0xEFU };

    usart.SendData(data);
}

TEST_F(UsartPeripheralTestWithMock, SendData9BitWithParity)
{
    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_9DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Enabled));

    EXPECT_CALL(registerMap, get_SR_TXE())
        .Times(3)
        .WillRepeatedly(Return(TransmitDataRegisterEmpty::TransferredToShiftRegister));

    EXPECT_CALL(registerMap, set_DR_DR(0x000000ABU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x000000CDU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x000000EFU)).Times(1);

    vector<uint8_t> data = { 0xABU, 0xCDU, 0xEFU };

    usart.SendData(data);
}

TEST_F(UsartPeripheralTestWithMock, SendData9BitNoParityMultiByteEvenNumber)
{
    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_9DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Disabled));

    EXPECT_CALL(registerMap, get_SR_TXE())
        .Times(3)
        .WillRepeatedly(Return(TransmitDataRegisterEmpty::TransferredToShiftRegister));

    EXPECT_CALL(registerMap, set_DR_DR(0x000001ABU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x000000CDU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x000000EFU)).Times(1);

    vector<uint8_t> data = 
    { 
        0x01U,  // The next byte is an address
        0xABU,  // Address
        0x00U,  // The next byte is data
        0xCDU,  // Data
        0x00U,  // The next byte is data
        0xEFU   // Data
    };

    usart.SendData(data);
}

TEST_F(UsartPeripheralTestWithMock, SendData9BitNoParitySingleByte)
{
    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_9DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Disabled));

    EXPECT_CALL(registerMap, get_SR_TXE())
        .Times(1)
        .WillRepeatedly(Return(TransmitDataRegisterEmpty::TransferredToShiftRegister));

    EXPECT_CALL(registerMap, set_DR_DR(0x000000ABU)).Times(1);

    // The address/data byte is missing. In this case, the data will be sent as is.
    vector<uint8_t> data = { 0xABU };

    usart.SendData(data);
}

TEST_F(UsartPeripheralTestWithMock, SendData9BitNoParityMultiByteOddNumber)
{
    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_9DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Disabled));

    EXPECT_CALL(registerMap, get_SR_TXE())
        .Times(3)
        .WillRepeatedly(Return(TransmitDataRegisterEmpty::TransferredToShiftRegister));

    EXPECT_CALL(registerMap, set_DR_DR(0x000001ABU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x000000CDU)).Times(1);
    EXPECT_CALL(registerMap, set_DR_DR(0x000000EFU)).Times(1);

    vector<uint8_t> data = 
    { 
        0x01U,  // The next byte is an address
        0xABU,  // Address
        0x00U,  // The next byte is data
        0xCDU,  // Data
        // MISSING - the data/address byte
        0xEFU   // Data. Note that the data/address byte is missing. This will be sent as is.
    };

    usart.SendData(data);
}

TEST_F(UsartPeripheralTestWithMock, SendData0Bytes)
{
    EXPECT_CALL(registerMap, get_CR1_M()).Times(0);
    EXPECT_CALL(registerMap, get_CR1_PCE()).Times(0);
    EXPECT_CALL(registerMap, get_SR_TXE()).Times(0);
    EXPECT_CALL(registerMap, set_DR_DR(_)).Times(0);

    vector<uint8_t> data = { /* No data */ };

    usart.SendData(data);
}