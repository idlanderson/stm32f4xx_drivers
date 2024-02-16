#include "usart.hpp"

namespace stm32::usart
{
    /// @brief Sets the mode of the USART peripheral.
    /// @param mode Mode to set (Rx, Tx or Rx/Tx).
    void UsartPeripheral::SetMode(UsartMode mode)
    {
        TransmitterEnable txEnable = mode == UsartMode::Tx || mode == UsartMode::RxTx ? TransmitterEnable::Enabled : TransmitterEnable::Disabled;
        ReceiverEnable rxEnable    = mode == UsartMode::Rx || mode == UsartMode::RxTx ? ReceiverEnable::Enabled    : ReceiverEnable::Disabled;
        UsartEnable usartEnable    = mode != UsartMode::Disabled ? UsartEnable::Enabled : UsartEnable::Disabled;

        device.set_CR1_TE(txEnable);
        device.set_CR1_RE(rxEnable);
        device.set_CR1_UE(usartEnable);
    }

    /// @brief Sets the baud rate of the USART peripheral.
    /// @param peripheralClockInHz The frequency of the peripheral clock, in Hz (e.g. 16000000).
    /// @param baudRate The desired baud rate, expressed in bps (e.g. 9600)
    /// @param oversamplingMode The oversampling mode to use (8 or 16).
    void UsartPeripheral::SetBaudRate(uint32_t peripheralClockInHz, uint32_t baudRate, OversamplingMode oversamplingMode)
    {
        device.set_CR1_OVER8(oversamplingMode);

        uint8_t oversamplingFactor = oversamplingMode == OversamplingMode::By8 ? 8U : 16U;

        uint32_t usartdiv = (100U * peripheralClockInHz) / (oversamplingFactor * baudRate);
        uint32_t mantissa = usartdiv / 100U;
        uint32_t fraction = (usartdiv - mantissa * 100U) * oversamplingFactor;

        // Round the fraction up to the nearest hundred. Credit for the rounding solution: https://cplusplus.com/forum/general/198033/
        uint32_t remainder = fraction % 100U;
        fraction = ((fraction - remainder) + 100U) / 100U;

        device.set_BRR_DIV_Mantissa(mantissa);
        device.set_BRR_DIV_Fraction(fraction);
    }

    /// @brief Sets the parity bit mode selection.
    /// @param parity The parity mode (None, Even or Odd).
    void UsartPeripheral::SetParity(Parity parity)
    {
        ParityControlEnable enable = parity == Parity::Even || parity == Parity::Odd ? ParityControlEnable::Enabled : ParityControlEnable::Disabled;
        ParitySelection selection  = parity == Parity::Odd ? ParitySelection::Odd : ParitySelection::Even;

        device.set_CR1_PCE(enable);
        device.set_CR1_PS(selection);
    }

    /// @brief Sets the word length.
    /// @param wordLength The word length (8-bit or 9-bit).
    void UsartPeripheral::SetWordLength(WordLength wordLength)
    {
        device.set_CR1_M(wordLength);
    }

    /// @brief Sets the stop bit mode selection.
    /// @param stopBits The stop bit mode (0.5, 1, 1.5 or 2 stop bits).
    void UsartPeripheral::SetStopBits(StopBits stopBits)
    {
        device.set_CR2_STOP(stopBits);
    }

    /// @brief Enables or disables the hardware flow control lines (RTS and CTS).
    /// @param rtsEnable Enable or disable RTS.
    /// @param ctsEnable Enable or disable CTS.
    void UsartPeripheral::SetHardwareFlowControl(bool rtsEnable, bool ctsEnable)
    {
        RtsEnable rts = rtsEnable ? RtsEnable::Enabled : RtsEnable::Disabled;
        CtsEnable cts = ctsEnable ? CtsEnable::Enabled : CtsEnable::Disabled;

        device.set_CR3_RTSE(rts);
        device.set_CR3_CTSE(cts);
    }

    /// @brief Sends an std::string to a receiving device. This function will block
    /// until all of the data is sent. Note that the exact format of the data sent to the
    /// receiving device will depend on the configured word length and parity bit.
    /// If a 8-bit word length is used with parity, then the MSB of each byte sent will
    /// be replaced by the parity bit.
    /// @param data A reference to the string.
    void UsartPeripheral::SendData(const string & data)
    {
        vector<uint8_t> dataVector(data.begin(), data.end());
        SendData(dataVector);
    }

    /// @brief Sends a C-style string to a receiving device. This function will block
    /// until all of the data is sent. Note that the exact format of the data sent to the
    /// receiving device will depend on the configured word length and parity bit.
    /// If a 8-bit word length is used with parity, then the MSB of each byte sent will
    /// be replaced by the parity bit.
    /// @param data A pointer to the string.
    void UsartPeripheral::SendData(const char * data)
    {
        string s(data);
        SendData(s);
    }

    /// @brief Sends a collection of data to a receiving device. This function will block
    /// until all of the data is sent. Note that the exact format of the data sent to the
    /// receiving device will depend on the configured word length and parity bit.
    /// If a 8-bit word length is used with parity, then the MSB of each byte sent will
    /// be replaced by the parity bit.
    /// @param data A reference to the vector containing data to send.
    void UsartPeripheral::SendData(const vector<uint8_t> & data)
    {
        if (device.get_CR1_UE() == UsartEnable::Disabled || data.size() == 0U) 
        {
            return;
        }

        WordLength wordLength = device.get_CR1_M();
        ParityControlEnable parityEnabled = device.get_CR1_PCE();

        // There are four different possible frame formats given the values of M and PCE:
        // M = 0, PCE = 0       SB | 8-bits data | STB          (8-bit word, no parity)
        // M = 0, PCE = 1       SB | 7-bits data | PB | STB     (8-bit word, parity)
        // M = 1, PCE = 0       SB | 9-bits data | STB          (9-bit word, no parity)
        // M = 1, PCE = 1       SB | 8-bits data | PB | STB     (9-bit word, parity)

        uint16_t i = 0U;

        while (i < data.size())
        {
            uint32_t dr = 0U;

            // Wait until the hardware is ready to transmit.
            // "Transferred to Shift Register" means that the main data register
            // (TDR) is empty and ready for the next byte.
            while (device.get_SR_TXE() != TransmitDataRegisterEmpty::TransferredToShiftRegister);

            if (wordLength    == WordLength::_8DataBits && 
                parityEnabled == ParityControlEnable::Enabled)
            {
                // M = 0, PCE = 1: 7 data bits + parity bit
                // Bit 7 of DR will have no effect since it will be replaced by the parity bit.
                dr = data[i] & 0x7FU;
            }
            else if (
                wordLength    == WordLength::_9DataBits && 
                parityEnabled == ParityControlEnable::Disabled && 
                i < (data.size() - 1U))
            {
                // M = 1, PCE = 0: 9 data bits (no parity bit), with an even number of bytes in 'data'.
                // This mode is often used to distinguish between an address byte and
                // a data byte when multiple slave devices are present on the UART bus.
                // In this case, the data should be provided as follows:
                // [ 1, AA, 0, DD, 0, DD, ... ]
                // Where AA is a slave address byte and DD is a data byte.
                //  1 indicates: "the next byte is an address"
                //  0 indicates: "the next byte is data"
                dr = ((static_cast<uint32_t>(data[i] & 0x01U) << 8U)) | data[i + 1];
                i++; // Advance an extra byte since we're using two bytes instead of one.
            }
            else
            {
                // Covers three cases:
                // M = 0, PCE = 0: 8 data bits (no parity bit)
                // M = 1, PCE = 1: 8 data bits (with parity bit)
                // M = 1, PCE = 0: 9 data bits (no parity bit), but with odd number of bytes in 'data'
                dr = data[i];
            }

            i++;

            device.set_DR_DR(dr);
        }
    }

    /// @brief Receives data from a transmitting device. This function will block until all data
    /// is received.
    /// @param length The number of bytes to receive.
    /// @return A vector containing the data bytes received.
    vector<uint8_t> UsartPeripheral::ReceiveData(uint32_t length)
    {
        vector<uint8_t> data = { };

        if (device.get_CR1_UE() == UsartEnable::Disabled || length == 0U) return data;

        WordLength wordLength = device.get_CR1_M();
        ParityControlEnable parityEnabled = device.get_CR1_PCE();

        uint32_t numberOfBytesReceived = 0U;

        while (numberOfBytesReceived < length)
        {
            // Wait until a byte of data is received...
            while (device.get_SR_RXNE() != ReadDataRegisterNotEmpty::ReceivedDataReady);

            if (wordLength == WordLength::_8DataBits)
            {
                if (parityEnabled == ParityControlEnable::Enabled)
                {
                    // M = 0, PCE = 1: 7 data bits + parity bit
                    data.push_back(device.get_DR_DR() & 0x7FU); // Mask the MSB since it's the parity bit.
                }
                else
                {
                    // M = 0, PCE = 0: 8 data bits (no parity bit)
                    data.push_back(device.get_DR_DR() & 0xFFU); // All 8 bits can be used.
                }

                numberOfBytesReceived++;
            }
            else if (wordLength == WordLength::_9DataBits)
            {
                uint32_t dr = device.get_DR_DR();

                if (parityEnabled == ParityControlEnable::Disabled)
                {
                    uint8_t bit8 = static_cast<uint8_t>((dr >> 8U) & 0x01U);
                    data.push_back(bit8);
                    numberOfBytesReceived++;
                }

                if (numberOfBytesReceived < length)
                {
                    data.push_back(dr & 0xFFU);
                    numberOfBytesReceived++;
                }
            }
        }

        return data;
    }
}