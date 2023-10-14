#ifndef SPI_HPP_H_
#define SPI_HPP_H_

#include "stm32f4xx.hpp"
#include <cstdint>
#include <vector>

namespace stm32::spi
{
    enum class DataFrameFormat : bool
    {
        EightBit   = 0U,
        SixteenBit = 1U
    };

    union ControlRegister1
    {
        volatile struct
        {
            uint8_t CPHA : 1;
            uint8_t CPOL : 1;
            uint8_t MSTR : 1;
            uint8_t BR   : 3;
            uint8_t SPE  : 1;
            uint8_t LSBFIRST : 1;
            uint8_t SSI : 1;
            uint8_t SSM : 1;
            uint8_t RXONLY : 1;
            uint8_t DFF : 1;
            uint8_t CRCNEXT : 1;
            uint8_t CRCEN : 1;
            uint8_t BIDIOE : 1;
            uint8_t BIDIMODE : 1;
            uint16_t Reserved : 16;
        } Fields;
        volatile uint32_t Value;
    };

    class ISpiRegisterMap : public RegisterMap
    {
    public:
        // CR1 Fields.
        virtual uint8_t getBIDIMODE() const = 0;
        virtual uint8_t getBIDIOE() const = 0;
        virtual uint8_t getCRCEN() const = 0;
        virtual uint8_t getCRCNEXT() const = 0;
        virtual uint8_t getDFF() const = 0;
        virtual uint8_t getRXONLY() const = 0;
        virtual uint8_t getSSM() const = 0;
        virtual uint8_t getSSI() const = 0;
        virtual uint8_t getLSBFIRST() const = 0;
        virtual uint8_t getSPE() const = 0;
        virtual uint8_t getBR() const = 0;
        virtual uint8_t getMSTR() const = 0;
        virtual uint8_t getCPOL() const = 0;
        virtual uint8_t getCPHA() const = 0;

        virtual void setBIDIMODE(uint8_t value) = 0;
        virtual void setBIDIOE(uint8_t value) = 0;
        virtual void setCRCEN(uint8_t value) = 0;
        virtual void setCRCNEXT(uint8_t value) = 0;
        virtual void setDFF(uint8_t value) = 0;
        virtual void setRXONLY(uint8_t value) = 0;
        virtual void setSSM(uint8_t value) = 0;
        virtual void setSSI(uint8_t value) = 0;
        virtual void setLSBFIRST(uint8_t value) = 0;
        virtual void setSPE(uint8_t value) = 0;
        virtual void setBR(uint8_t value) = 0;
        virtual void setMSTR(uint8_t value) = 0;
        virtual void setCPOL(uint8_t value) = 0;
        virtual void setCPHA(uint8_t value) = 0;

        // CR2 Fields.
        virtual uint8_t getRXNEIE() const = 0;
        virtual uint8_t getERRIE() const = 0;
        virtual uint8_t getFRF() const = 0;
        virtual uint8_t getSSOE() const = 0;
        virtual uint8_t getTXDMAEN() const = 0;
        virtual uint8_t getRXDMAEN() const = 0;
        virtual void setRXNEIE(uint8_t value) = 0;
        virtual void setERRIE(uint8_t value) = 0;
        virtual void setFRF(uint8_t value) = 0;
        virtual void setSSOE(uint8_t value) = 0;
        virtual void setTXDMAEN(uint8_t value) = 0;
        virtual void setRXDMAEN(uint8_t value) = 0;

        // SR Fields.
        virtual uint8_t getFRE() const = 0;
        virtual uint8_t getBSY() const = 0;
        virtual uint8_t getOVR() const = 0;
        virtual uint8_t getMODF() const = 0;
        virtual uint8_t getCRCERR() const = 0;
        virtual uint8_t getUDR() const = 0;
        virtual uint8_t getCHSIDE() const = 0;
        virtual uint8_t getTXE() const = 0;
        virtual uint8_t getRXNE() const = 0;
        virtual void setCRCERR(uint8_t value) = 0;

        // DR.
        virtual uint16_t getDR() const = 0;
        virtual void     setDR(uint16_t value) = 0;

        // CRCPR.
        virtual uint16_t getCRCPR() const = 0;
        virtual void     setCRCPR(uint16_t value) = 0;

        // RXCRCR and TXCRCR.
        virtual uint16_t getRXCRCR() const = 0;
        virtual uint16_t getTXCRCR() const = 0;

        // I2SCFGR.
        virtual uint8_t getI2SMOD() const = 0;
        virtual uint8_t getI2SE() const = 0;
        virtual uint8_t getI2SCFG() const = 0;
        virtual uint8_t getPCMSYNC() const = 0;
        virtual uint8_t getI2SSTD() const = 0;
        virtual uint8_t getCKPOL() const = 0;
        virtual uint8_t getDATLEN() const = 0;
        virtual uint8_t getCHLEN() const = 0;
        virtual void setI2SMOD(uint8_t value) = 0;
        virtual void setI2SE(uint8_t value) = 0;
        virtual void setI2SCFG(uint8_t value) = 0;
        virtual void setPCMSYNC(uint8_t value) = 0;
        virtual void setI2SSTD(uint8_t value) = 0;
        virtual void setCKPOL(uint8_t value) = 0;
        virtual void setDATLEN(uint8_t value) = 0;
        virtual void setCHLEN(uint8_t value) = 0;

        // I2SPR
        virtual uint8_t getMCKOE() const = 0;
        virtual uint8_t getODD() const = 0;
        virtual uint8_t getI2SDIV() const = 0;
        virtual void setMCKOE(uint8_t value) = 0;
        virtual void setODD(uint8_t value) = 0;
        virtual void setI2SDIV(uint8_t value) = 0;
    };

    class SpiRegisterMap : public ISpiRegisterMap 
    {
    public:
        // CR1 Fields
        uint8_t getBIDIMODE() const override { return CR1.Fields.BIDIMODE; }
        uint8_t getBIDIOE() const override { return CR1.Fields.BIDIOE; }
        uint8_t getCRCEN() const override { return CR1.Fields.CRCEN; }
        uint8_t getCRCNEXT() const override { return CR1.Fields.CRCNEXT; }
        uint8_t getDFF() const override { return CR1.Fields.DFF; }
        uint8_t getRXONLY() const override { return CR1.Fields.RXONLY; }
        uint8_t getSSM() const override { return CR1.Fields.SSM; }
        uint8_t getSSI() const override { return CR1.Fields.SSI; }
        uint8_t getLSBFIRST() const override { return CR1.Fields.LSBFIRST; }
        uint8_t getSPE() const override { return CR1.Fields.SPE; }
        uint8_t getBR() const override { return CR1.Fields.BR; }
        uint8_t getMSTR() const override { return CR1.Fields.MSTR; }
        uint8_t getCPOL() const override { return CR1.Fields.CPOL; }
        uint8_t getCPHA() const override { return CR1.Fields.CPHA; }
        void setBIDIMODE(uint8_t value) override { CR1.Fields.BIDIMODE = value; }
        void setBIDIOE(uint8_t value) override { CR1.Fields.BIDIOE = value; }
        void setCRCEN(uint8_t value) override { CR1.Fields.CRCEN = value; }
        void setCRCNEXT(uint8_t value) override { CR1.Fields.CRCNEXT = value; }
        void setDFF(uint8_t value) override { CR1.Fields.DFF = value; }
        void setRXONLY(uint8_t value) override { CR1.Fields.RXONLY = value; }
        void setSSM(uint8_t value) override { CR1.Fields.SSM = value; }
        void setSSI(uint8_t value) override { CR1.Fields.SSI = value; }
        void setLSBFIRST(uint8_t value) override { CR1.Fields.LSBFIRST = value; }
        void setSPE(uint8_t value) override { CR1.Fields.SPE = value; }
        void setBR(uint8_t value) override { CR1.Fields.BR = value; }
        void setMSTR(uint8_t value) override { CR1.Fields.MSTR = value; }
        void setCPOL(uint8_t value) override { CR1.Fields.CPOL = value; }
        void setCPHA(uint8_t value) override { CR1.Fields.CPHA = value; }

        // CR2 Fields
        uint8_t getRXNEIE() const override { return GetField_1Bit(CR2, CR2_RXNEIE); }
        uint8_t getERRIE() const override { return GetField_1Bit(CR2, CR2_ERRIE); }
        uint8_t getFRF() const override { return GetField_1Bit(CR2, CR2_FRF); }
        uint8_t getSSOE() const override { return GetField_1Bit(CR2, CR2_SSOE); }
        uint8_t getTXDMAEN() const override { return GetField_1Bit(CR2, CR2_TXDMAEN); }
        uint8_t getRXDMAEN() const override { return GetField_1Bit(CR2, CR2_RXDMAEN); }
        void setRXNEIE(uint8_t value) override { return SetField_1Bit(CR2, CR2_RXNEIE, value); }
        void setERRIE(uint8_t value) override { return SetField_1Bit(CR2, CR2_ERRIE, value); }
        void setFRF(uint8_t value) override { return SetField_1Bit(CR2, CR2_FRF, value); }
        void setSSOE(uint8_t value) override { return SetField_1Bit(CR2, CR2_SSOE, value); }
        void setTXDMAEN(uint8_t value) override { return SetField_1Bit(CR2, CR2_TXDMAEN, value); }
        void setRXDMAEN(uint8_t value) override { return SetField_1Bit(CR2, CR2_RXDMAEN, value); }

        // SR Fields
        uint8_t getFRE() const override { return GetField_1Bit(SR, SR_FRE); }
        uint8_t getBSY() const override { return GetField_1Bit(SR, SR_BSY); }
        uint8_t getOVR() const override { return GetField_1Bit(SR, SR_OVR); }
        uint8_t getMODF() const override { return GetField_1Bit(SR, SR_MODF); }
        uint8_t getCRCERR() const override { return GetField_1Bit(SR, SR_CRCERR); }
        uint8_t getUDR() const override { return GetField_1Bit(SR, SR_UDR); }
        uint8_t getCHSIDE() const override { return GetField_1Bit(SR, SR_CHSIDE); }
        uint8_t getTXE() const override { return GetField_1Bit(SR, SR_TXE); }
        uint8_t getRXNE() const override { return GetField_1Bit(SR, SR_RXNE); }
        void setCRCERR(uint8_t value) override { return SetField_1Bit(SR, SR_CRCERR, value); }

        // DR
        uint16_t getDR() const override { return (uint16_t)(DR & 0x0000FFFFU); }
        void setDR(uint16_t value) override { DR = (uint32_t)value; }

        // CRCPR
        uint16_t getCRCPR() const override { return (uint16_t)(CRCPR & 0x0000FFFFU); }
        void setCRCPR(uint16_t value) override { CRCPR = (uint32_t)value; }

        // RXCRCR and TXCRCR
        uint16_t getRXCRCR() const override { return (uint16_t)(RXCRCR & 0x0000FFFFU); }
        uint16_t getTXCRCR() const override { return (uint16_t)(TXCRCR & 0x0000FFFFU); }

        // I2SCFGR
        uint8_t getI2SMOD() const override { return GetField_1Bit(I2SCFGR, I2SCFGR_I2SMOD); }
        uint8_t getI2SE() const override { return GetField_1Bit(I2SCFGR, I2SCFGR_I2SE); }
        uint8_t getI2SCFG() const override { return GetField_2Bit(I2SCFGR, I2SCFGR_I2SCFG); }
        uint8_t getPCMSYNC() const override { return GetField_1Bit(I2SCFGR, I2SCFGR_PCMSYNC); }
        uint8_t getI2SSTD() const override { return GetField_2Bit(I2SCFGR, I2SCFGR_I2SSTD); }
        uint8_t getCKPOL() const override { return GetField_1Bit(I2SCFGR, I2SCFGR_CKPOL); }
        uint8_t getDATLEN() const override { return GetField_2Bit(I2SCFGR, I2SCFGR_DATLEN); }
        uint8_t getCHLEN() const override { return GetField_1Bit(I2SCFGR, I2SCFGR_CHLEN); }
        void setI2SMOD(uint8_t value) override { return SetField_1Bit(I2SCFGR, I2SCFGR_I2SMOD, value); }
        void setI2SE(uint8_t value) override { return SetField_1Bit(I2SCFGR, I2SCFGR_I2SE, value); }
        void setI2SCFG(uint8_t value) override { return SetField_2Bit(I2SCFGR, I2SCFGR_I2SCFG, value); }
        void setPCMSYNC(uint8_t value) override { return SetField_1Bit(I2SCFGR, I2SCFGR_PCMSYNC, value); }
        void setI2SSTD(uint8_t value) override { return SetField_2Bit(I2SCFGR, I2SCFGR_I2SSTD, value); }
        void setCKPOL(uint8_t value) override { return SetField_1Bit(I2SCFGR, I2SCFGR_CKPOL, value); }
        void setDATLEN(uint8_t value) override { return SetField_2Bit(I2SCFGR, I2SCFGR_DATLEN, value); }
        void setCHLEN(uint8_t value) override { return SetField_1Bit(I2SCFGR, I2SCFGR_CHLEN, value); }

        // I2SPR
        uint8_t getMCKOE() const override { return GetField_1Bit(I2SPR, I2SPR_MCKOE); }
        uint8_t getODD() const override { return GetField_1Bit(I2SPR, I2SPR_ODD); }
        uint8_t getI2SDIV() const override { return GetField_8Bit(I2SPR, I2SPR_I2SDIV); }
        void setMCKOE(uint8_t value) override { return SetField_1Bit(I2SPR, I2SPR_MCKOE, value); }
        void setODD(uint8_t value) override { return SetField_1Bit(I2SPR, I2SPR_ODD, value); }
        void setI2SDIV(uint8_t value) override { return SetField_8Bit(I2SPR, I2SPR_I2SDIV, value); }

    private:

        ControlRegister1 CR1;
        DeviceRegister CR2;
        DeviceRegister SR;
        DeviceRegister DR;
        DeviceRegister CRCPR;
        DeviceRegister RXCRCR;
        DeviceRegister TXCRCR;
        DeviceRegister I2SCFGR;
        DeviceRegister I2SPR;

        const uint8_t CR1_BIDIMODE = 15U;
        const uint8_t CR1_BIDIOE = 14U;
        const uint8_t CR1_CRCEN = 13U;
        const uint8_t CR1_CRCNEXT = 12U;
        const uint8_t CR1_DFF = 11U;
        const uint8_t CR1_RXONLY = 10U;
        const uint8_t CR1_SSM = 9U;
        const uint8_t CR1_SSI = 8U;
        const uint8_t CR1_LSBFIRST = 7U;
        const uint8_t CR1_SPE = 6U;
        const uint8_t CR1_BR = 3U;
        const uint8_t CR1_MSTR = 2U;
        const uint8_t CR1_CPOL = 1U;
        const uint8_t CR1_CPHA = 0U;

        const uint8_t CR2_TXEIE = 7U;
        const uint8_t CR2_RXNEIE = 6U;
        const uint8_t CR2_ERRIE = 5U;
        const uint8_t CR2_FRF = 4U;
        const uint8_t CR2_SSOE = 2U;
        const uint8_t CR2_TXDMAEN = 1U;
        const uint8_t CR2_RXDMAEN = 0U;

        const uint8_t SR_FRE = 8U;
        const uint8_t SR_BSY = 7U;
        const uint8_t SR_OVR = 6U;
        const uint8_t SR_MODF = 5U;
        const uint8_t SR_CRCERR = 4U;
        const uint8_t SR_UDR = 3U;
        const uint8_t SR_CHSIDE = 2U;
        const uint8_t SR_TXE = 1U;
        const uint8_t SR_RXNE = 0U;

        const uint8_t I2SCFGR_I2SMOD = 11U;
        const uint8_t I2SCFGR_I2SE = 10U;
        const uint8_t I2SCFGR_I2SCFG = 8U;
        const uint8_t I2SCFGR_PCMSYNC = 7U;
        const uint8_t I2SCFGR_I2SSTD = 4U;
        const uint8_t I2SCFGR_CKPOL = 3U;
        const uint8_t I2SCFGR_DATLEN = 1U;
        const uint8_t I2SCFGR_CHLEN = 0U;

        const uint8_t I2SPR_MCKOE = 9U;
        const uint8_t I2SPR_ODD = 8U;
        const uint8_t I2SPR_I2SDIV = 0U;
    };

    enum class DeviceMode
    {
        Slave  = 0U,
        Master = 1U
    };

    enum class BusConfig
    {
        FullDuplex    = 0U,
        HalfDuplex    = 1U,
        SimplexRxOnly = 2U
    };

    enum class RxOnly
    {
        FullDuplex_TxAndRx    = 0U,
        OutputDisabled_RxOnly = 1U
    };

    enum class BaudRate
    {
        Div2   = 0U,
        Div4   = 1U,
        Div8   = 2U,
        Div16  = 3U,
        Div32  = 4U,
        Div64  = 5U,
        Div128 = 6U,
        Div256 = 7U
    };

    enum class ClockPolarity
    {
        Low  = 0U,  
        High = 1U
    };

    enum class ClockPhase
    {
        FirstEdge  = 0U,
        SecondEdge = 1U
    };

    enum class SlaveManagement
    {
        Hardware = 0U,
        Software = 1U
    };

    enum class BidirectionalMode
    {
        Unidirectional = 0U,
        Bidirectional  = 1U
    };

    enum class OutputEnableInBidirectionalMode
    {
        Disabled_RxOnly = 0U,
        Enabled_TxOnly  = 1U
    };

    class SpiPeripheral
    {
    public:

        SpiPeripheral(ISpiRegisterMap & device) : device(device) { }

        DataFrameFormat GetDataFrameFormat() const;

        void SetDeviceMode(DeviceMode deviceMode);
        void SetBidirectionalMode(BidirectionalMode mode);
        void SetRxOnly(RxOnly rxOnly);
        void SetBusConfig(BusConfig busConfig);
        void SetOutputEnableInBidirectionalMode(OutputEnableInBidirectionalMode isEnabled);
        void SetDataFrameFormat(DataFrameFormat format);
        void SetClockPolarity(ClockPolarity polarity);
        void SetClockPhase(ClockPhase phase);
        void SetBaudRate(BaudRate baudRate);
        void SetSlaveManagement(SlaveManagement slaveManagement);
        void SetInternalSlaveSelect(bool isEnabled);
        void SetSlaveSelectOutputEnabled(bool isEnabled);
        void SetEnabled(bool isEnabled);

        bool IsReceiveBufferNotEmpty() const;
        bool IsTransmitBufferEmpty() const;
        bool HasCrcErrorOccurred() const;
        bool HasModeFaultOccurred() const;
        bool HasOverrunOccurred() const;
        bool IsBusy() const;

        void SendData(std::vector<uint8_t> data);
        std::vector<uint8_t> ReceiveData(uint32_t length);

    private:

        ISpiRegisterMap & device;
    };
}

#endif // SPI_HPP_H_