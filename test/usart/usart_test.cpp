#include "usart.hpp"
#include "usart_register_map_mock.hpp"

TEST_F(UsartPeripheralTest, SetMode)
{
    usart.SetMode(UsartMode::Rx);
    EXPECT_EQ(0x00002004U, registers.CR1.Value);

    usart.SetMode(UsartMode::Tx);
    EXPECT_EQ(0x00002008U, registers.CR1.Value);

    usart.SetMode(UsartMode::RxTx);
    EXPECT_EQ(0x0000200CU, registers.CR1.Value);

    usart.SetMode(UsartMode::Disabled);
    EXPECT_EQ(0x00000000U, registers.CR1.Value);
}

TEST_F(UsartPeripheralTest, SetBaudRate)
{
    usart.SetBaudRate(16000000U, 9600U, OversamplingMode::By16);
    EXPECT_EQ(0x00000683U, registers.BRR.Value);

    usart.SetBaudRate(16000000U, 115200U, OversamplingMode::By8);
    EXPECT_EQ(0x00000113U, registers.BRR.Value);
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
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

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
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

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
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

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
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

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
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

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
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

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
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

    EXPECT_CALL(registerMap, get_CR1_M()).Times(0);
    EXPECT_CALL(registerMap, get_CR1_PCE()).Times(0);
    EXPECT_CALL(registerMap, get_SR_TXE()).Times(0);
    EXPECT_CALL(registerMap, set_DR_DR(_)).Times(0);

    vector<uint8_t> data = { /* No data */ };

    usart.SendData(data);
}

TEST_F(UsartPeripheralTestWithMock, SendDataUsartDisabled)
{
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Disabled));
        
    EXPECT_CALL(registerMap, get_CR1_M()).Times(0);
    EXPECT_CALL(registerMap, get_CR1_PCE()).Times(0);
    EXPECT_CALL(registerMap, get_SR_TXE()).Times(0);
    EXPECT_CALL(registerMap, set_DR_DR(_)).Times(0);

    vector<uint8_t> data = { 0x12U };

    usart.SendData(data);
}

TEST_F(UsartPeripheralTestWithMock, ReceiveData8BitsNoParity)
{
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_8DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Disabled));

    EXPECT_CALL(registerMap, get_SR_RXNE())
        .Times(3)
        .WillRepeatedly(Return(ReadDataRegisterNotEmpty::ReceivedDataReady));

    EXPECT_CALL(registerMap, get_DR_DR())
        .Times(3)
        .WillOnce(Return(0x1ABU))
        .WillOnce(Return(0x1CDU))
        .WillOnce(Return(0x1EFU));

    auto data = usart.ReceiveData(3U);

    EXPECT_THAT(data, ElementsAre(0xABU, 0xCDU, 0xEFU));
}

TEST_F(UsartPeripheralTestWithMock, ReceiveData8BitsWithParity)
{
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_8DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Enabled));

    EXPECT_CALL(registerMap, get_SR_RXNE())
        .Times(3)
        .WillRepeatedly(Return(ReadDataRegisterNotEmpty::ReceivedDataReady));

    EXPECT_CALL(registerMap, get_DR_DR())
        .Times(3)
        .WillOnce(Return(0xABU))
        .WillOnce(Return(0xCDU))
        .WillOnce(Return(0xEFU));

    auto data = usart.ReceiveData(3U);

    EXPECT_THAT(data, ElementsAre(0x2BU, 0x4DU, 0x6FU));
}

TEST_F(UsartPeripheralTestWithMock, ReceiveData9BitsWithParity)
{
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_9DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Enabled));

    EXPECT_CALL(registerMap, get_SR_RXNE())
        .Times(3)
        .WillRepeatedly(Return(ReadDataRegisterNotEmpty::ReceivedDataReady));

    EXPECT_CALL(registerMap, get_DR_DR())
        .Times(3)
        .WillOnce(Return(0x1ABU))   // '1' is the parity bit. Assume even parity.
        .WillOnce(Return(0x1CDU))   // '1' is the parity bit. Assume even parity.
        .WillOnce(Return(0x1EFU));  // '1' is the parity bit. Assume even parity.

    auto data = usart.ReceiveData(3U);

    EXPECT_THAT(data, ElementsAre(0xABU, 0xCDU, 0xEFU));
}

TEST_F(UsartPeripheralTestWithMock, ReceiveData9BitsNoParityEvenLength)
{
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_9DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Disabled));

    EXPECT_CALL(registerMap, get_SR_RXNE())
        .Times(3)
        .WillRepeatedly(Return(ReadDataRegisterNotEmpty::ReceivedDataReady));

    EXPECT_CALL(registerMap, get_DR_DR())
        .Times(3)
        .WillOnce(Return(0x1ABU))   // '1' is part of the data.
        .WillOnce(Return(0x1CDU))   // '1' is part of the data.
        .WillOnce(Return(0x1EFU));  // '1' is part of the data.

    auto data = usart.ReceiveData(6U);

    EXPECT_THAT(data, ElementsAre(0x01U, 0xABU, 0x01U, 0xCDU, 0x01U, 0xEFU));
}

TEST_F(UsartPeripheralTestWithMock, ReceiveData9BitsNoParityOddLength)
{
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

    EXPECT_CALL(registerMap, get_CR1_M())
        .Times(1)
        .WillOnce(Return(WordLength::_9DataBits));

    EXPECT_CALL(registerMap, get_CR1_PCE())
        .Times(1)
        .WillOnce(Return(ParityControlEnable::Disabled));

    EXPECT_CALL(registerMap, get_SR_RXNE())
        .Times(3)
        .WillRepeatedly(Return(ReadDataRegisterNotEmpty::ReceivedDataReady));

    EXPECT_CALL(registerMap, get_DR_DR())
        .Times(3)
        .WillOnce(Return(0x1ABU))   // '1' is part of the data.
        .WillOnce(Return(0x1CDU))   // '1' is part of the data.
        .WillOnce(Return(0x1EFU));  // '1' is part of the data.

    auto data = usart.ReceiveData(5U);

    EXPECT_THAT(data, ElementsAre(0x01U, 0xABU, 0x01U, 0xCDU, 0x01U));
}

TEST_F(UsartPeripheralTestWithMock, ReceiveDataLengthIs0)
{
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Enabled));

    EXPECT_CALL(registerMap, get_CR1_M()).Times(0);
    EXPECT_CALL(registerMap, get_CR1_PCE()).Times(0);
    EXPECT_CALL(registerMap, get_SR_RXNE()).Times(0);
    EXPECT_CALL(registerMap, get_DR_DR()).Times(0);

    auto data = usart.ReceiveData(0U);

    EXPECT_THAT(data, ElementsAre());
}

TEST_F(UsartPeripheralTestWithMock, ReceiveDataUsartDisabled)
{
    EXPECT_CALL(registerMap, get_CR1_UE())
        .Times(1)
        .WillOnce(Return(UsartEnable::Disabled));
        
    EXPECT_CALL(registerMap, get_CR1_M()).Times(0);
    EXPECT_CALL(registerMap, get_CR1_PCE()).Times(0);
    EXPECT_CALL(registerMap, get_SR_RXNE()).Times(0);
    EXPECT_CALL(registerMap, get_DR_DR()).Times(0);

    auto data = usart.ReceiveData(1U);

    EXPECT_THAT(data, ElementsAre());
}