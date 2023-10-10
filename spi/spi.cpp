#include "spi.hpp"

#define BIDIMODE_BIT_POSITION_IN_CR1  15U
#define BIDIOE_BIT_POSITION_IN_CR1    14U
#define DFF_BIT_POSITION_IN_CR1       11U
#define RXONLY_BIT_POSITION_IN_CR1    10U
#define SPI_CR1_SSI                   8U
#define SPI_CR1_SPE                   6U
#define MSTR_BIT_POSITION_IN_CR1      2U
#define CPOL_BIT_POSITION_IN_CR1      1U
#define CPHA_BIT_POSITION_IN_CR1      0U
#define BR_3_BIT_POSITION_IN_CR1      1U

#define SPI_CR1_SSM                   9U
#define SPI_CR2_SSOE                  2U

#define SPI_SR_BSY                    7U
#define SPI_SR_OVR                    6U
#define SPI_SR_MODF                   5U
#define SPI_SR_CRCERR                 4U
#define SPI_SR_UDR                    3U
#define SPI_SR_CHSIDE                 2U
#define SPI_SR_TXE                    1U
#define SPI_SR_RXNE                   0U

void SPI::SetRegField_1Bit(DeviceRegister & reg, uint8_t position, uint8_t value)
{
    if (position <= MaxPositionFor1BitField &&
        value    <= MaxValueFor1BitField)
    {
        reg &= ~(0x1U << position);
        reg |= value << position;
    }
}

void SPI::SetRegField_2Bits(DeviceRegister & reg, uint8_t position, uint8_t value)
{
    if (position <= MaxPositionFor2BitField &&
        value    <= MaxValueFor2BitField)
    {
        reg &= ~(0x3U << (2U * position)); /* Clear the bits */
        reg |= value << (2U * position);   /* Populate the new value */
    }
}

void SPI::SetRegField_3Bits(DeviceRegister & reg, uint8_t position, uint8_t value)
{
    if (position <= MaxPositionFor3BitField &&
        value    <= MaxValueFor3BitField)
    {
        reg &= ~(0x7U << (3U * position)); /* Clear the bits */
        reg |= value << (3U * position);   /* Populate the new value */
    }
}

void SPI::SetDeviceMode(DeviceMode deviceMode)
{
    SetRegField_1Bit(this->CR1, MSTR_BIT_POSITION_IN_CR1, (uint8_t)deviceMode);
}

void SPI::SetBidirectionalMode(BidirectionalMode mode)
{
    SetRegField_1Bit(this->CR1, BIDIMODE_BIT_POSITION_IN_CR1, (uint8_t)mode);
}

void SPI::SetRxOnly(RxOnly rxOnly)
{
    SetRegField_1Bit(this->CR1, RXONLY_BIT_POSITION_IN_CR1, (uint8_t)rxOnly);
}

void SPI::SetBusConfig(BusConfig busConfig)
{
    if (busConfig == BusConfig::FullDuplex)
    {
        SetBidirectionalMode(BidirectionalMode::Unidirectional);
        SetRxOnly(RxOnly::FullDuplex_TxAndRx);
    }
    else if (busConfig == BusConfig::HalfDuplex)
    {
        SetBidirectionalMode(BidirectionalMode::Bidirectional);
        SetRxOnly(RxOnly::FullDuplex_TxAndRx);
    }
    else if (busConfig == BusConfig::SimplexRxOnly)
    {
        SetBidirectionalMode(BidirectionalMode::Unidirectional);
        SetRxOnly(RxOnly::OutputDisabled_RxOnly);
    }
}

void SPI::SetOutputEnableInBidirectionalMode(OutputEnableInBidirectionalMode isEnabled)
{
    SetRegField_1Bit(this->CR1, BIDIOE_BIT_POSITION_IN_CR1, (uint8_t)isEnabled);
}

SPI::DataFrameFormat SPI::GetDataFrameFormat() const
{
    return (DataFrameFormat)((this->CR1 >> DFF_BIT_POSITION_IN_CR1) & 0x0001U);
}

void SPI::SetDataFrameFormat(DataFrameFormat format)
{
    SetRegField_1Bit(this->CR1, DFF_BIT_POSITION_IN_CR1, (uint8_t)format);
}

void SPI::SetClockPolarity(ClockPolarity polarity)
{
    SetRegField_1Bit(this->CR1, CPOL_BIT_POSITION_IN_CR1, (uint8_t)polarity);
}

void SPI::SetClockPhase(ClockPhase phase)
{
    SetRegField_1Bit(this->CR1, CPHA_BIT_POSITION_IN_CR1, (uint8_t)phase);
}

void SPI::SetBaudRate(BaudRate baudRate)
{
    SetRegField_3Bits(this->CR1, BR_3_BIT_POSITION_IN_CR1, (uint8_t)baudRate);
}

void SPI::SetSlaveManagement(SlaveManagement slaveManagement)
{
    SetRegField_1Bit(this->CR1, SPI_CR1_SSM, (uint8_t)slaveManagement);
}

void SPI::SetInternalSlaveSelect(bool isEnabled)
{
    SetRegField_1Bit(this->CR1, SPI_CR1_SSI, (uint8_t)isEnabled);
}

void SPI::SetSlaveSelectOutputEnabled(bool isEnabled)
{
    SetRegField_1Bit(this->CR2, SPI_CR2_SSOE, (uint8_t)isEnabled);
}

void SPI::SetEnabled(bool isEnabled)
{
    SetRegField_1Bit(this->CR1, SPI_CR1_SPE, (uint8_t)isEnabled);
}

bool SPI::IsBusy() const
{
    return (bool)((this->SR >> SPI_SR_BSY) & 0x1U);
}

bool SPI::IsReceiveBufferNotEmpty() const
{
    return (bool)((this->SR >> SPI_SR_RXNE) & 0x1U);
}

bool SPI::IsTransmitBufferEmpty() const
{
    return (bool)((this->SR >> SPI_SR_TXE) & 0x1U);
}

bool SPI::HasCrcErrorOccurred() const
{
    return (bool)((this->SR >> SPI_SR_CRCERR) & 0x1U);
}

bool SPI::HasModeFaultOccurred() const
{
    return (bool)((this->SR >> SPI_SR_MODF) & 0x1U);
}

bool SPI::HasOverrunOccurred() const
{
    return (bool)((this->SR >> SPI_SR_OVR) & 0x1U);
}

void SPI::SendData(std::vector<uint8_t> data)
{
    uint32_t remainingLengthToSend = data.size();
    uint32_t currentIndex = 0U;
    DataFrameFormat dataFrameFormat = GetDataFrameFormat();

    while (remainingLengthToSend > 0U)
    {
        while (!IsTransmitBufferEmpty());

        if (dataFrameFormat == DataFrameFormat::EightBit)
        {
            this->DR = (0x0000U | data[currentIndex]);
            remainingLengthToSend--;
            currentIndex++;
        }
        else if (dataFrameFormat == DataFrameFormat::SixteenBit)
        {
            this->DR = ((data[currentIndex] << 8U) | data[currentIndex + 1U]);
            remainingLengthToSend -= 2U;
            currentIndex += 2U;
        }
        else
        {
            remainingLengthToSend = 0U;
        }
    }
}

std::vector<uint8_t> SPI::ReceiveData(uint32_t length)
{
    uint32_t remainingLengthToReceive = length;
    DataFrameFormat dataFrameFormat = GetDataFrameFormat();
    std::vector<uint8_t> dataReceived;

    while (remainingLengthToReceive > 0U)
    {
        while (!IsReceiveBufferNotEmpty()); // While the RxBuffer is NOT NOT empty (i.e. while it's empty).

        if (dataFrameFormat == DataFrameFormat::EightBit)
        {
            uint8_t data = (uint8_t)this->DR;
            dataReceived.push_back(data);
            remainingLengthToReceive--;
        }
        else if (dataFrameFormat == DataFrameFormat::SixteenBit)
        {
            uint16_t data = (uint16_t)this->DR;
            dataReceived.push_back(data);
            remainingLengthToReceive -= 2U;
        }
        else
        {
            remainingLengthToReceive = 0U;
        }
    }

    return dataReceived;
}