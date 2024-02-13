#include "usart.hpp"
#include <stdio.h>

namespace stm32::usart
{
    void UsartPeripheral::SetMode(UsartMode mode)
    {
        TransmitterEnable txEnable = mode == UsartMode::Tx || mode == UsartMode::RxTx ? TransmitterEnable::Enabled : TransmitterEnable::Disabled;
        ReceiverEnable    rxEnable = mode == UsartMode::Rx || mode == UsartMode::RxTx ? ReceiverEnable::Enabled    : ReceiverEnable::Disabled;

        device.set_CR1_TE(txEnable);
        device.set_CR1_RE(rxEnable);
    }

    void UsartPeripheral::SetParity(Parity parity)
    {
        ParityControlEnable enable = parity == Parity::Even || parity == Parity::Odd ? ParityControlEnable::Enabled : ParityControlEnable::Disabled;
        ParitySelection selection  = parity == Parity::Odd ? ParitySelection::Odd : ParitySelection::Even;

        device.set_CR1_PCE(enable);
        device.set_CR1_PS(selection);
    }

    void UsartPeripheral::SetWordLength(WordLength wordLength)
    {
        device.set_CR1_M(wordLength);
    }

    void UsartPeripheral::SetStopBits(StopBits stopBits)
    {
        device.set_CR2_STOP(stopBits);
    }

    void UsartPeripheral::SetHardwareFlowControl(bool rtsEnable, bool ctsEnable)
    {
        RtsEnable rts = rtsEnable ? RtsEnable::Enabled : RtsEnable::Disabled;
        CtsEnable cts = ctsEnable ? CtsEnable::Enabled : CtsEnable::Disabled;

        device.set_CR3_RTSE(rts);
        device.set_CR3_CTSE(cts);
    }

    void UsartPeripheral::SendData(const vector<uint8_t> & data)
    {
        if (data.size() == 0U) return;

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
}