//*****************************************************************************
//
//! \file xuart.h
//! \brief Prototypes for the UART Driver.
//! \version V2.1.1.0
//! \date 11/14/2011
//! \author CooCox
//! \copy
//!
//! Copyright (c)  2011, CooCox 
//! All rights reserved.
//! 
//! Redistribution and use in source and binary forms, with or without 
//! modification, are permitted provided that the following conditions 
//! are met: 
//! 
//!     * Redistributions of source code must retain the above copyright 
//! notice, this list of conditions and the following disclaimer. 
//!     * Redistributions in binary form must reproduce the above copyright
//! notice, this list of conditions and the following disclaimer in the
//! documentation and/or other materials provided with the distribution. 
//!     * Neither the name of the <ORGANIZATION> nor the names of its 
//! contributors may be used to endorse or promote products derived 
//! from this software without specific prior written permission. 
//! 
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//! AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
//! IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//! ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
//! LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
//! SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//! INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
//! CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
//! ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
//! THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************
#include "xhw_types.h"

#ifndef __xUART_H__
#define __xUART_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup CoX_Peripheral_Lib
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup UART
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_Ints xUART Interrupt
//! \brief Values that show xUART Interrupt
//! \n
//! \section xUART_Ints_Section 1. Where to use this group
//! Values that can be passed to UARTIntEnable, UARTIntDisable, and UARTIntClear
//! as the ulIntFlags parameter, and returned from UARTIntStatus. 
//! \n
//! \section xUART_Ints_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xUART Interrupts        |       CoX      |         SAMDxx         |
//! |------------------------|----------------|------------------------|
//! |xUART_INT_ERROR         |    Mandatory   |                       |
//! |------------------------|----------------|------------------------|
//! |xUART_INT_RT            |    Mandatory   |                       |
//! |------------------------|----------------|------------------------|
//! |xUART_INT_TX            |    Mandatory   |                       |
//! |------------------------|----------------|------------------------|
//! |xUART_INT_RX            |    Mandatory   |                       |
//! |------------------------|----------------|------------------------|
//! |xUART_INT_DSR           |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_INT_DCD           |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_INT_CTS           |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_INT_RI            |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_INT_LMSB          |  Non-Mandatory |            N           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! All Error Interrupt Mask
//
#define xUART_INT_ERROR         0        \\error interrupts not available in SAM d20 devices, reconfirm later

//
//! Receive Timeout Interrupt Mask
//
#define xUART_INT_RT            0       \\not implemented

//
//! Transmit Interrupt Mask
//
#define xUART_INT_TX            SERCOM_USART_INTENSET_TXC       

//
//! Receive Interrupt Mask
//
#define xUART_INT_RX            SERCOM_USART_INTENSET_RXC   

//
//! Receive start interrupt mask
//
#define xUART_INT_RXS			SERCOM_USART_INTENSET_RXS

//
//! Data register empty interrupt mask
//
#define xUART_INT_DRE			SERCOM_USART_INTENSET_DRE

//
//! DSR Modem Interrupt Mask
//
#define xUART_INT_DSR           0       //not implemented

//
//! DCD Modem Interrupt Mask
//
#define xUART_INT_DCD           0       //not implemented

//
//! CTS Modem Interrupt Mask
//
#define xUART_INT_CTS           0 		//not implemented

//
//! RI Modem Interrupt Mask
//
#define xUART_INT_RI            0 		//not implemented

//
//! LIN Mode Sync Break Interrupt Mask
//
#define xUART_INT_LMSB          0		//not implemented


//*****************************************************************************
//
//! @}
//
//*****************************************************************************   

//*****************************************************************************
//
//! \addtogroup xUART_Event_Flag xUART Event Flags
//! \brief Values that show xUART Event Flags
//! \n
//! \section xUART_Event_Flag_Section 1. Where to use this group
//! Uart Event/Error Flag, Used by IntHandle's Event Callback Function as 
//! ulMsgParam parmeter. User Callback function can user this to detect what 
//! event happened.
//! \n
//! \section xUART_Event_Flag_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xUART Events            |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_TX          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_RX          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_OE          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_FE          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_RT          |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_PE          |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_DSR         |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_DCD         |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_CTS         |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_RI          |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_EVENT_LMSB        |  Non-Mandatory |            N           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! Transmit Event Mask
//
#define xUART_EVENT_TX          SERCOM_USART_INTENSET_TXC       

//
//! Receive Event Mask
//
#define xUART_EVENT_RX          SERCOM_USART_INTENSET_RXC   

//
//! Overrun Error Event Mask
//
#define xUART_EVENT_OE          0       \\not applicable

//
//! Parity Error Event Mask
//
#define xUART_EVENT_PE          0       \\not applicable

//
//! Framing Error Event Mask
//
#define xUART_EVENT_FE          0       \\not applicable

//
//! Receive Timeout Event Mask
//
#define xUART_EVENT_RT          0		\\not applicable       

//
//! DSR Modem Event Mask
//
#define xUART_EVENT_DSR         0		\\not applicable       

//
//! DCD Modem Event Mask
//
#define xUART_EVENT_DCD         0		\\not applicable       

//
//! CTS Modem Event Mask
//
#define xUART_EVENT_CTS         0		\\not applicable       

//
//! RI Modem Event Mask
//
#define xUART_EVENT_RI          0		\\not applicable 

//
//! LIN Mode Sync Break Event Mask
//
#define xUART_EVENT_LMSB        0		\\not applicable

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_Error xUART Error
//! \brief Values that show xUART Error
//! \n
//! \section xUART_Event_Flag_Section 1. Where to use this group
//! Values returned from xUARTRxErrorGet().
//! \n
//! \section xUART_Event_Flag_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xUART Error             |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xUART_RXERROR_OVERRUN   |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_RXERROR_BREAK     |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_RXERROR_PARITY    |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_RXERROR_FRAMING   |    Mandatory   |            Y           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

#define xUART_RXERROR_OVERRUN   SERCOM_USART_STATUS_BUFOVF
#define xUART_RXERROR_BREAK     0							// not available
#define xUART_RXERROR_PARITY    SERCOM_USART_STATUS_PERR
#define xUART_RXERROR_FRAMING   SERCOM_USART_STATUS_FERR

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_Frame_Configs xUART Frame Configuration
//! \brief Values that show xUART Frame Configuration
//! \n
//! \section xUART_Frame_Configs_Section 1. Where to use this group
//! Uart Data Frame Configs. Such as Word Length, Parity, Stop bit.
//! Values that can be passed to xUARTConfig as the ulConfig parameter
//! and returned by UARTConfigGetExpClk in the pulConfig parameter.
//! Additionally, the UART_CONFIG_PAR_* subset can be passed to
//! UARTParityModeSet as the ulParity parameter, and are returned by
//! UARTParityModeGet. 
//! \n
//! \section xUART_Frame_Configs_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xUART Frame Config      |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_WLEN_MASK  |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_WLEN_n     |    Mandatory   |   xUART_CONFIG_WLEN_9  |
//! |                        |                |------------------------|
//! |                        |                |   xUART_CONFIG_WLEN_8  |
//! |                        |                |------------------------|
//! |                        |                |   xUART_CONFIG_WLEN_7  |
//! |                        |                |------------------------|
//! |                        |                |   xUART_CONFIG_WLEN_6  |
//! |                        |                |------------------------|
//! |                        |                |   xUART_CONFIG_WLEN_5  |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_PAR_MASK   |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_PAR_NONE   |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_PAR_EVEN   |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_PAR_ODD    |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_PAR_ONE    |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_PAR_ZERO   |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_STOP_MASK  |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_STOP_1     |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_STOP_2     |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_STOP_0_5   |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_CONFIG_STOP_1_5   |  Non-Mandatory |            N           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************
//
// Mask for extracting word length
//
#define xUART_CONFIG_WLEN_MASK  SERCOM_USART_CTRLB_CHSIZE_Msk  

//
//! 9 bit data
//
#define xUART_CONFIG_WLEN_9     SERCOM_USART_CONFIG_CHSIZE_9  

//
//! 8 bit data
//
#define xUART_CONFIG_WLEN_8     SERCOM_USART_CONFIG_CHSIZE_8 

//
//! 7 bit data
//
#define xUART_CONFIG_WLEN_7     SERCOM_USART_CONFIG_CHSIZE_7

//
//! 6 bit data
//
#define xUART_CONFIG_WLEN_6     SERCOM_USART_CONFIG_CHSIZE_6

//
//! 5 bit data
//
#define xUART_CONFIG_WLEN_5     SERCOM_USART_CONFIG_CHSIZE_5

//
//! Mask for extracting stop bits
//
#define xUART_CONFIG_STOP_MASK  SERCOM_USART_CTRLB_SBMODE

//
//! One stop bit
//
#define xUART_CONFIG_STOP_1     SERCOM_USART_CONFIG_STOP_1  

//
//! Two stop bits
//
#define xUART_CONFIG_STOP_2     SERCOM_USART_CONFIG_STOP_2

#define xUART_CONFIG_STOP_0_5   0  
#define xUART_CONFIG_STOP_1_5   0  

//
//! Mask for enabling parity
//
#define xUART_CONFIG_PAR_ENABLE_MASK  SERCOM_USART_CTRLA_FORM_Msk

//
//! Parity enabled
//
#define xUART_CONFIG_PAR_ENABLE  SERCOM_USART_CTRLA_PAR_ENABLE

//
//! Parity disabled
#define xUART_CONFIG_PAR_DISABLE SERCOM_USART_CTRLA_PAR_DISABLE

//
//! Mask for extracting parity
//
#define xUART_CONFIG_PAR_MASK   SERCOM_USART_CTRLB_PMODE

//
//! Even parity
//
#define xUART_CONFIG_PAR_EVEN   SERCOM_USART_CONFIG_PAR_EVEN  

//
//! Odd parity
//
#define xUART_CONFIG_PAR_ODD    SERCOM_USART_CONFIG_PAR_ODD  

//
//! Parity bit is one / marked
//
#define xUART_CONFIG_PAR_ONE    0 

//
//! Parity bit is zero / space
//
#define xUART_CONFIG_PAR_ZERO   0 

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_IrDA_Mode xUART IrDA Mode 
//! \brief Values that show xUART IrDA Mode
//! \n
//! \section xUART_IrDA_Mode_Section 1. Where to use this group
//! Uart IrDA mode that con be passed to UARTIrDAConfig as the
//! ulMode parameter. 
//! \n
//! \section xUART_IrDA_Mode_CoX 2. CoX Port Details 
//! \verbatim
//! +-------------------------+----------------+------------------------+
//! |xUART IrDA Mode          |       CoX      |         NUC1xx         |
//! |-------------------------|----------------|------------------------|
//! |xUART_IRDA_MODE_NORMAL   |  Non-Mandatory |            N           |
//! |-------------------------|----------------|------------------------|
//! |xUART_IRDA_MODE_LOW_POWER|  Non-Mandatory |            N           |
//! +-------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! IrDA Normal Mode
//
#define xUART_IRDA_MODE_NORMAL  0

//
//! IrDA Low-Power Mode
//
#define xUART_IRDA_MODE_LOW_POWER                                             \
                                0

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_Enable_Blocks xUART Enable Blocks
//! \brief Values that show xUART Enable Blocks
//! \n
//! \section xUART_Enable_Blocks_Section 1. Where to use this group
//! Uart logic blocks  that can be passed to UARTEnable() or UARTDisable() as 
//! the ulBlock parameter.
//! \n
//! \section xUART_Enable_Blocks_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xUART Enable Block      |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xUART_BLOCK_UART        |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_BLOCK_RX          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xUART_BLOCK_TX          |    Mandatory   |            Y           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! Uart logic block
//
#define xUART_BLOCK_UART        SERCOM_USART_CTRLA_ENABLE

//
//! Uart transmit logic block
//
#define xUART_BLOCK_TX          SERCOM_USART_CTRLB_TXEN

//
//! uart receive logic block
//
#define xUART_BLOCK_RX          SERCOM_USART_CTRLB_RXEN

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_FIFO_Rx_Tiggle_Level xUART FIFO Rx Tiggle Level
//! \brief Values that show xUART FIFO Rx Tiggle Level
//! \n
//! \section xUART_FIFO_Rx_Tiggle_Level_Section 1. Where to use this group
//! Values that can be passed to UARTFIFORxLevelSet as the ulRxLevel parameter.
//! \n
//! \section xUART_FIFO_Rx_Tiggle_Level_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |FIFO Rx Tiggle Level    |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xUART_FIFO_RX_n         |    Mandatory   |           N
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! (1 character)
//
#define xUART_FIFO_RX_1         0  

//
//! (4 character)
//
#define xUART_FIFO_RX_4         0  

//
//! (8 character)
//
#define xUART_FIFO_RX_8         0  

//
//! (14 character)
//
#define xUART_FIFO_RX_14        0  

//
//! (30 character)
//
#define xUART_FIFO_RX_30        0 

//
//! (46 character)
//
#define xUART_FIFO_RX_46        0 

//
//! (62 character)
//
#define xUART_FIFO_RX_62        0 

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_Modem_Output xUART Modem Output
//! \brief Values that show xUART Modem Output
//! \n
//! \section xUART_Modem_Output_Section 1. Where to use this group
//! Values that can be passed to UARTModemControlSet(), UARTModemControlClear() 
//! or returned from UARTModemControlGet().
//! \n
//! \section xUART_Modem_Output_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xUART Modem Output      |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xUART_OUTPUT_RTS        |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_OUTPUT_DTR        |  Non-Mandatory |            N           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

#define xUART_OUTPUT_RTS        0

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_Modem_Intput xUART Modem Input
//! \brief Values that show xUART Modem Input
//! \n
//! \section xUART_Modem_Intput_Section 1. Where to use this group
//! Values that can be returned from UARTModemStatusGet().
//! \n
//! \section xUART_Modem_Intput_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xUART Modem Input       |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xUART_INPUT_CTS         |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_INPUT_RI          |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_INPUT_DCD         |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_INPUT_DSR         |  Non-Mandatory |            N           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

#define xUART_INPUT_CTS         0

//*****************************************************************************
//
//! @}
//
//*****************************************************************************


//*****************************************************************************
//
//! \addtogroup xUART_Flow_Control xUART Flow Control
//! \brief Values that show xUART Flow Control
//! \n
//! \section xUART_Flow_Control_Section 1. Where to use this group
//! Values that can be passed to UARTFlowControlSet() or returned from
//! UARTFlowControlGet().
//! \n
//! \section xUART_Flow_Control_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xUART Flow Control      |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xUART_FLOWCONTROL_TX    |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_FLOWCONTROL_RX    |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xUART_FLOWCONTROL_NONE  |  Non-Mandatory |            N           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

#define xUART_FLOWCONTROL_TX    0
#define xUART_FLOWCONTROL_RX    0
#define xUART_FLOWCONTROL_NONE  0

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_LIN_Config xUART LIN Configuration
//! \brief Values that show xUART LIN Configuration
//! \n
//! \section xUART_LIN_Config_Section 1. Where to use this group
//! Values that can be passed to xUARTLINConfig().
//! \n
//! \section xUART_LIN_Config_CoX 2. CoX Port Details 
//! \verbatim
//! +-----------------------------+----------------+-------------------+
//! |xUART LIN Configuration      |       CoX      |      NUC1xx       |
//! |-----------------------------|----------------|-------------------|
//! |xUART_LIN_MODE_MASK          |  Non-Mandatory |         N         |
//! |-----------------------------|----------------|-------------------|
//! |xUART_LIN_MODE_MASTER        |  Non-Mandatory |         N         |
//! |-----------------------------|----------------|-------------------|
//! |xUART_LIN_MODE_SLAVE         |  Non-Mandatory |         N         |
//! |-----------------------------|----------------|-------------------|
//! |xUART_LIN_SYNC_BREAK_LEN_MASK|  Non-Mandatory |         N         |
//! |-----------------------------|----------------|-------------------|
//! |xUART_LIN_SYNC_BREAK_LEN_13  |  Non-Mandatory |         N         |
//! |-----------------------------|----------------|-------------------|
//! |xUART_LIN_SYNC_BREAK_LEN_14  |  Non-Mandatory |         N         |
//! |-----------------------------|----------------|-------------------|
//! |xUART_LIN_SYNC_BREAK_LEN_15  |  Non-Mandatory |         N         |
//! |-----------------------------|----------------|-------------------|
//! |xUART_LIN_SYNC_BREAK_LEN_16  |  Non-Mandatory |         N         |
//! +-----------------------------+----------------+-------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

#define xUART_LIN_SYNC_BREAK_LEN_MASK                                         \
                                0
                                
#define xUART_LIN_SYNC_BREAK_LEN_13                                           \
                                0

#define xUART_LIN_SYNC_BREAK_LEN_14                                           \
                                0

#define xUART_LIN_SYNC_BREAK_LEN_15                                           \
                                0

#define xUART_LIN_SYNC_BREAK_LEN_16                                           \
                                0

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xUART_Exported_APIs xUART API
//! \brief UART API Reference.
//! \section xUART_Exported_APIs_Port CoX Port Details
//! \verbatim
//! +------------------------+----------------+--------+
//! |xUART API               |       CoX      | NUC1xx |
//! |------------------------|----------------|--------|
//! |xUARTConfigSet          |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTEnable             |    Mandatory   |    N   |
//! |------------------------|----------------|--------|
//! |xUARTDisable            |    Mandatory   |    N   |
//! |------------------------|----------------|--------|
//! |xUARTFIFOEnable         |  Non-Mandatory |    N   |
//! |------------------------|----------------|--------|
//! |xUARTFIFODisable        |  Non-Mandatory |    N   |
//! |------------------------|----------------|--------|
//! |xUARTFIFORxLevelSet     |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTCharsAvail         |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTSpaceAvail         |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTCharGetNonBlocking |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTCharGet            |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTCharPutNonBlocking |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTCharPut            |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTBusy               |  Non-Mandatory |    N   |
//! |------------------------|----------------|--------|
//! |xUARTIntEnable          |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTIntCallbackInit    |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTIntDisable         |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTRxErrorGet         |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTRxErrorClear       |    Mandatory   |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTModemControlSet    |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTModemControlClear  |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTModemControlGet    |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTModemStatusGet     |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTFlowControlSet     |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTFlowControlGet     |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTIrDAConfig         |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTIrDAEnable         |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTIrDADisable        |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTLINConfig          |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTLINEnable          |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! |xUARTLINDisable         |  Non-Mandatory |    Y   |
//! |------------------------|----------------|--------|
//! \endverbatim
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Sets the configuration of a UART.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBaud is the desired baud rate.
//! \param ulConfig is the data format for the port (number of data bits,
//! number of stop bits, and parity).
//!
//! This function configures the UART for operation in the specified data
//! format.  The baud rate is provided in the \e ulBaud parameter and the data
//! format in the \e ulConfig parameter.
//!
//! The \e ulConfig parameter is the logical OR of three values: the number of
//! data bits, the number of stop bits, and the parity.  \b UART_CONFIG_WLEN_8,
//! \b xUART_CONFIG_WLEN_7, \b xUART_CONFIG_WLEN_6, and \b xUART_CONFIG_WLEN_5
//! select from eight to five data bits per byte (respectively).
//! \b xUART_CONFIG_STOP_1 and \b xUART_CONFIG_STOP_2 select one or two stop
//! bits (respectively).  \b xUART_CONFIG_PAR_NONE, \b xUART_CONFIG_PAR_EVEN,
//! \b xUART_CONFIG_PAR_ODD, \b xUART_CONFIG_PAR_ONE, and 
//! \b xUART_CONFIG_PAR_ZERO select the parity mode (no parity bit, 
//! even parity bit, odd parity bit, parity bit always one, and parity bit 
//! always zero, respectively).
//!
//!
//! \return None.
//
//*****************************************************************************

#define xUARTConfigSet(ulBase, ulBaud, ulConfig)						\
		UARTConfigSet(ulBase, ulBaud, ulConfig)

//*****************************************************************************
//
//! \brief selects which SERCOM pad is to be configured as receive pin
//!
//! \param ulBase is the base address of the UART port.
//! \param ulRxPin is the SERCOM PAD number 
//!
//! \return None.
//
//*****************************************************************************      
#define xUARTRxPinSelect(ulBase, ulRxPin)                                           \
		UARTRxPinSelect(ulBase, ulRxPin)
		
		
//*****************************************************************************
//
//! \brief selects clock for the UART, whether it's internal or external
//!
//! \param ulBase is the base address of the UART port.
//! \param ulRxPin is the SERCOM PAD number 
//!
//! \return None.
//
//*****************************************************************************      
#define xUARTClockMode(ulBase, ulConfig)                                           \
		UARTClockMode(ulBase, ulConfig)
		
//*****************************************************************************
//
//! \brief selects which SERCOM pad is to be configured as transmit pin
//!
//! \param ulBase is the base address of the UART port.
//! \param ulRxPin is the SERCOM PAD number 
//!
//! \return None.
//
//*****************************************************************************      
#define xUARTTxPinSelect(ulBase, ulTxPin)                                           \
		UARTTxPinSelect(ulBase, ulTxPin)
		
//*****************************************************************************
//
//! \brief Enables transmitting or receiving.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBlock is the block to enable. it is the logical OR of 
//! these values:  \b xUART_BLOCK_TX, \b xUART_BLOCK_RX.
//!
//! Sets the UARTEN, or TXE or RXE bits.
//!
//! \note Do nothing in UART,In IrDA and LIN mode will set the Tx or Rx enable
//!
//! \return None.
//
//*****************************************************************************      
#define xUARTEnable(ulBase)                                           \
        UARTEnable(ulBase)                             

//*****************************************************************************
//
//! \brief enables transmitting or receiving.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBlock is the block to disable. it is the logical OR of 
//! these values: \b xUART_BLOCK_UART, \b xUART_BLOCK_TX, \b xUART_BLOCK_RX.
//!
//!
//! \note Do nothing in NUVOTON
//!
//! \return None.
//
//*****************************************************************************
#define xUARTBlockEnable(ulBase, ulBlock)                                          \
         UARTBlockEnable(ulBase, ulBlock)
		
//*****************************************************************************
//
//! \brief Disables the USART module
//!
//! \param ulBase is the base address of the UART port.
//!
//! Clears the UARTEN or TXE or RXE bits.
//!
//! \note Do nothing in NUVOTON
//!
//! \return None.
//
//*****************************************************************************
#define xUARTDisable(ulBase)                                          \
         UARTDisable(ulBase)
		 
//*****************************************************************************
//
//! \brief Disables transmitting or receiving.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBlock is the block to disable. it is the logical OR of 
//! these values: \b xUART_BLOCK_UART, \b xUART_BLOCK_TX, \b xUART_BLOCK_RX.
//!
//!
//! \note Do nothing in NUVOTON
//!
//! \return None.
//
//*****************************************************************************
#define xUARTBlockDisable(ulBase, ulBlock)                                          \
         UARTBlockDisable(ulBase, ulBlock)
		 
//*****************************************************************************
//
//! \brief Enables the transmit and receive FIFOs.
//!
//! \param ulBase is the base address of the UART port.
//!
//! This functions enables the transmit and receive FIFOs in the UART.
//!
//! \note Do nothing in NUVOTON
//!
//! \return None.
//
//*****************************************************************************
#define xUARTFIFOEnable(ulBase)

//*****************************************************************************
//
//! \brief Disables the transmit and receive FIFOs.
//!
//! \param ulBase is the base address of the UART port.
//!
//! This functions disables the transmit and receive FIFOs in the UART.
//!
//! \note Do nothing in NUVOTON
//!
//! \return None.
//
//*****************************************************************************
#define xUARTFIFODisable(ulBase)

//*****************************************************************************
//
//! \brief Sets the Rx FIFO level at which interrupts are generated.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulRxLevel is the receive FIFO interrupt level, specified as one of
//! \b xUART_FIFO_RX_1, \b xUART_FIFO_RX_4, \b xUART_FIFO_RX_8,
//! \b xUART_FIFO_RX_14, \b xUART_FIFO_RX_30, \b xUART_FIFO_RX_46,
//! or \b xUART_FIFO_RX_62.
//!
//! This function sets the FIFO level at which receive interrupts
//! are generated.
//!
//! \return None.
//
//*****************************************************************************
#define xUARTFIFORxLevelSet(ulBase, ulRxLevel)

//*****************************************************************************
//
//! \brief Determines if there are any characters in the receive FIFO.
//!
//! \param ulBase is the base address of the UART port.
//!
//! This function returns a flag indicating whether or not there is data
//! available in the receive FIFO.
//!
//! \return Returns \b true if there is data in the receive FIFO or \b false
//! if there is no data in the receive FIFO.
//
//*****************************************************************************
#define xUARTCharsAvail(ulBase)                                               \
         UARTCharsAvail(ulBase)
//*****************************************************************************
//
//! \brief Determines if there is any space in the transmit FIFO.
//!
//! \param ulBase is the base address of the UART port.
//!
//! This function returns a flag indicating whether or not there is space
//! available in the transmit FIFO.
//!
//! \return Returns \b true if there is space available in the transmit FIFO
//! or \b false if there is no space available in the transmit FIFO.
//
//*****************************************************************************
#define xUARTSpaceAvail(ulBase)                                               \

//*****************************************************************************
//
//! \brief Receives a character from the specified port.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Gets a character from the receive FIFO for the specified port.
//!
//! This function replaces the original UARTCharNonBlockingGet() API and
//! performs the same actions.  A macro is provided in <tt>uart.h</tt> to map
//! the original API to this API.
//!
//! \return Returns the character read from the specified port, cast as a
//! \e long.  A \b -1 is returned if there are no characters present in the
//! receive FIFO.  The UARTCharsAvail() function should be called before
//! attempting to call this function.
//
//*****************************************************************************
#define xUARTCharGetNonBlocking(ulBase)                                       \
        UARTCharGetNonBlocking(ulBase)
		
//*****************************************************************************
//
//! \brief Waits for a character from the specified port.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Gets a character from the receive FIFO for the specified port.  If there
//! are no characters available, this function waits until a character is
//! received before returning.
//!
//! \return Returns the character read from the specified port, cast as a
//! \e long.
//
//*****************************************************************************
#define xUARTCharGet(ulBase)                                                  \
        UARTCharGet(ulBase)
//*****************************************************************************
//
//! \brief Sends a character to the specified port.
//!
//! \param ulBase is the base address of the UART port.
//! \param ucData is the character to be transmitted.
//!
//! Writes the character \e ucData to the transmit FIFO for the specified port.
//! This function does not block, so if there is no space available, then a
//! \b false is returned, and the application must retry the function later.
//!
//! This function replaces the original UARTCharNonBlockingPut() API and
//! performs the same actions.  A macro is provided in <tt>uart.h</tt> to map
//! the original API to this API.
//!
//! \return Returns \b true if the character was successfully placed in the
//! transmit FIFO or \b false if there was no space available in the transmit
//! FIFO.
//
//*****************************************************************************
#define xUARTCharPutNonBlocking(ulBase, ucData)                               \
        UARTCharPutNonBlocking(ulBase, ucData)
//*****************************************************************************
//
//! \brief Waits to send a character from the specified port.
//!
//! \param ulBase is the base address of the UART port.
//! \param ucData is the character to be transmitted.
//!
//! Sends the character \e ucData to the transmit FIFO for the specified port.
//! If there is no space available in the transmit FIFO, this function waits
//! until there is space available before returning.
//!
//! \return None.
//
//*****************************************************************************
#define xUARTCharPut(ulBase, ucData)                                          \
        UARTCharPut(ulBase, ucData)
//*****************************************************************************
//
//! \brief Determines whether the UART transmitter is busy or not.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Allows the caller to determine whether all transmitted bytes have cleared
//! the transmitter hardware.  If \b false is returned, the transmit FIFO is
//! empty and all bits of the last transmitted character, including all stop
//! bits, have left the hardware shift register.
//!
//! \return Returns \b true if the UART is transmitting or \b false if all
//! transmissions are complete.
//
//*****************************************************************************
#define xUARTBusy(ulBase)                                                     \
    UARTBusy(ulBase)
//*****************************************************************************
//
//! \brief Enables individual UART interrupt sources.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! Enables the indicated UART interrupt sources.  Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.
//!
//! The \e ulIntFlags parameter is the logical OR of any of the following:
//!
//! - \b xUART_INT_ERROR - All Error interrupt
//! - \b xUART_INT_RT - Receive Timeout interrupt
//! - \b xUART_INT_TX - Transmit interrupt
//! - \b xUART_INT_RX - Receive interrupt
//!
//! \return None.
//
//*****************************************************************************
#define xUARTIntEnable(ulBase, ulIntFlags) 

//*****************************************************************************
//
//! \brief Init interrupts callback for the specified UART Port.
//!
//! \param ulPort is the base address of the UART port.
//! \param xtI2CCallback is callback for the specified UART Port.
//!
//! Init interrupts callback for the specified UART Port.
//!
//! \return None.
//
//*****************************************************************************
#define xUARTIntCallbackInit(ulBase, xtUARTCallback)                          

        
//*****************************************************************************
//
//! \brief Disables individual UART interrupt sources.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! Disables the indicated UART interrupt sources.  Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to UARTIntEnable().
//!
//! - \b xUART_INT_ERROR - All Error interrupt
//! - \b xUART_INT_RT - Receive Timeout interrupt
//! - \b xUART_INT_TX - Transmit interrupt
//! - \b xUART_INT_RX - Receive interrupt
//!
//! \return None.
//
//*****************************************************************************
#define xUARTIntDisable(ulBase, ulIntFlags)

//*****************************************************************************
//
//! \brief Gets current receiver errors.
//!
//! \param ulBase is the base address of the UART port.
//!
//! This function returns the current state of each of the 4 receiver error
//! sources.  The returned errors are equivalent to the four error bits
//! returned via the previous call to UARTCharGet() or UARTCharGetNonBlocking()
//! with the exception that the overrun error is set immediately the overrun
//! occurs rather than when a character is next read.
//!
//! \return Returns a logical OR combination of the receiver error flags,
//! \b xUART_RXERROR_FRAMING, \b xUART_RXERROR_PARITY, \b xUART_RXERROR_BREAK
//! and \b xUART_RXERROR_OVERRUN.
//
//*****************************************************************************
#define xUARTRxErrorGet(ulBase)                                               \
        UARTRxErrorGet(ulBase)
//*****************************************************************************
//
//! \brief Clears all reported receiver errors.
//!
//! \param ulBase is the base address of the UART port.
//!
//! This function is used to clear all receiver error conditions reported via
//! UARTRxErrorGet().  If using the overrun, framing error, parity error or
//! break interrupts, this function must be called after clearing the interrupt
//! to ensure that later errors of the same type trigger another interrupt.
//!
//! \return None.
//
//*****************************************************************************
#define xUARTRxErrorClear(ulBase)                                             \
        UARTRxErrorClear(ulBase)
//*****************************************************************************
//
//! \brief Sets the states of the DTR and/or RTS modem control signals.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulControl is a bit-mapped flag indicating which modem control bits
//! should be set.
//!
//! Sets the states of the DTR or RTS modem handshake outputs from the UART.
//!
//! The \e ulControl parameter is the logical OR of any of the following:
//!
//! - \b xUART_OUTPUT_RTS - The Modem Control RTS signal
//!
//! \note It is not available on UART2.
//!
//! \return None.
//
//*****************************************************************************
#define xUARTModemControlSet(ulBase, ulControl)


//*****************************************************************************
//
//! \brief Clears the states of the DTR and/or RTS modem control signals.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulControl is a bit-mapped flag indicating which modem control bits
//! should be set.
//!
//! Clears the states of the DTR or RTS modem handshake outputs from the UART.
//!
//! The \e ulControl parameter is the logical OR of any of the following:
//!
//! - \b xUART_OUTPUT_RTS - The Modem Control RTS signal
//!
//! \note It is not available on UART2
//!
//! \return None.
//
//*****************************************************************************
#define xUARTModemControlClear(ulBase, ulControl)


//*****************************************************************************
//
//! \brief Gets the states of the DTR and RTS modem control signals.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Returns the current states of each of the two UART modem control signals,
//! DTR and RTS.
//!
//! \note It is not available on UART2
//!
//! \return Returns the states of the handshake output signals.  This will be a
//! logical logical OR combination of values \b xUART_OUTPUT_RTS 
//! where the presence of each flag indicates that the
//! associated signal is asserted.
//
//*****************************************************************************
#define xUARTModemControlGet(ulBase, ulControl)

//*****************************************************************************
//
//! \brief Gets the states of the RI, DCD, DSR and CTS modem status signals.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Returns the current states of each of the four UART modem status signals,
//! RI, DCD, DSR and CTS.
//!
//! \note It is not available on UART2
//!
//! \return Returns the states of the handshake output signals.  This will be a
//! logical logical OR combination of values \b xUART_INPUT_CTS,  where the
//! presence of each flag indicates that the associated signal is asserted.
//
//*****************************************************************************
#define xUARTModemStatusGet(ulBase)

//*****************************************************************************
//
//! \brief Sets the UART hardware flow control mode to be used.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulMode indicates the flow control modes to be used.  This is a
//! logical OR combination of values \b xUART_FLOWCONTROL_TX and \b
//! xUART_FLOWCONTROL_RX to enable hardware transmit (CTS) and receive (RTS)
//! flow control or \b xUART_FLOWCONTROL_NONE to disable hardware flow control.
//!
//! Sets the required hardware flow control modes.  If \e ulMode contains
//! flag \b xUART_FLOWCONTROL_TX, data is only transmitted if the incoming CTS
//! signal is asserted. If \e ulMode contains flag \b xUART_FLOWCONTROL_RX,
//! the RTS output is controlled by the hardware and is asserted only when
//! there is space available in the receive FIFO.  If no hardware flow control
//! is required, xUART_FLOWCONTROL_NONE should be passed.
//!
//! \note The availability of hardware flow control varies with the Stellaris
//! part and UART in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
#define xUARTFlowControlSet(ulBase, ulMode)

//*****************************************************************************
//
//! \brief Returns the UART hardware flow control mode currently in use.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Returns the current hardware flow control mode.
//!
//! \note The availability of hardware flow control varies with the Stellaris
//! part and UART in use.  Please consult the datasheet for the part you are
//! using to determine whether this support is available.
//!
//! \return Returns the current flow control mode in use.  This is a
//! logical OR combination of values \b xUART_FLOWCONTROL_TX if transmit
//! (CTS) flow control is enabled and \b xUART_FLOWCONTROL_RX if receive (RTS)
//! flow control is in use.  If hardware flow control is disabled, \b
//! xUART_FLOWCONTROL_NONE will be returned.
//
//*****************************************************************************
#define xUARTFlowControlGet(ulBase)
        
//*****************************************************************************
//
//! \brief Enables SIR (IrDA) mode on the specified UART.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBaud is the desired baud rate.
//! \param ulConfig is the data format for the port (number of data bits,
//! number of stop bits, and parity).
//! \param ulMode is the IrDA mode. 
//!
//! This function configures the UART IrDA for operation in the specified data
//! format.  The baud rate is provided in the \e ulBaud parameter,  the data
//! format in the \e ulConfig parameter, and the ulMode is provided in the
//! \e ulMode parameter.
//!
//! The \e ulConfig parameter is the logical OR of three values: the number of
//! data bits, the number of stop bits, and the parity.  \b xUART_CONFIG_WLEN_8,
//! \b xUART_CONFIG_WLEN_7, \b xUART_CONFIG_WLEN_6, and \b xUART_CONFIG_WLEN_5
//! select from eight to five data bits per byte (respectively).
//! \bX UART_CONFIG_STOP_1 and \b xUART_CONFIG_STOP_2 select one or two stop
//! bits (respectively).  \b xUART_CONFIG_PAR_NONE, \b xUART_CONFIG_PAR_EVEN,
//! \b xUART_CONFIG_PAR_ODD, \b xUART_CONFIG_PAR_ONE,  and
//! \b xUART_CONFIG_PAR_ZERO select the parity mode (no parity bit, 
//! even parity bit, odd parity bit, parity bit always one, and 
//! parity bit always zero, respectively).
//!
//! The \e ulMode parameter can be values:
//! - \b xUART_IRDA_MODE_NORMAL - IrDA normal mode
//!
//! \note SIR (IrDA) operation is not supported on Sandstorm-class devices.
//!
//! \return None.
//
//*****************************************************************************
#define xUARTIrDAConfig(ulBase, ulBaud, ulConfig, ulMode);
                  

//*****************************************************************************
//
//! \brief Enables SIR (IrDA) mode on the specified UART.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Enables the SIREN control bit for IrDA mode on the UART. 
//!
//! \return None.
//
//*****************************************************************************
#define xUARTIrDAEnable(ulBase)

//*****************************************************************************
//
//! \brief Disables SIR (IrDA) mode on the specified UART.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Clears the SIREN (IrDA) bits.
//!
//! \return None.
//
//*****************************************************************************
#define xUARTIrDADisable(ulBase)

//*****************************************************************************
//
//! \brief Open LIN mode on the specified UART.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulConfig is the Config of the UART port in LIN mode.
//!
//! Open the LIN mode for the UART. 
//!
//! The \e ulConfig parameter is the logical OR of three values: the LIN Tx or Rx
//! Mode, the LIN Break Field Length.
//!
//! \return None.
//
//*****************************************************************************
#define xUARTLINConfig(ulBase, ulBaud, ulConfig);
        
//*****************************************************************************
//
//! \brief Enables LIN Function mode on the specified UART.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Enables the SIREN control bit for LIN Function on the UART. 
//!
//! \return None.
//
//*****************************************************************************    
#define xUARTLINEnable(ulBase);

//*****************************************************************************
//
//! \brief Disables LIN Function mode on the specified UART.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Clears the LIN Function bits.
//!
//! \return None.
//
//*****************************************************************************    
#define xUARTLINDisable(ulBase);
    

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

#define SERCOM_USART_CONFIG_CHSIZE_9		0x00000001UL

#define SERCOM_USART_CONFIG_CHSIZE_8		0x00000000UL

#define SERCOM_USART_CONFIG_CHSIZE_7		0x00000007UL

#define SERCOM_USART_CONFIG_CHSIZE_6		0x00000006UL

#define SERCOM_USART_CONFIG_CHSIZE_5		0x00000005UL

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

#define SERCOM_USART_CONFIG_STOP_1			0x00000000UL

#define SERCOM_USART_CONFIG_STOP_2			0x00000040UL

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

#define SERCOM_USART_CONFIG_PAR_NONE		0x00000000UL

#define SERCOM_USART_CONFIG_PAR_EVEN		0x00000000UL

#define SERCOM_USART_CONFIG_PAR_ODD			0x00002000UL

#define SERCOM_USART_CTRLA_PAR_ENABLE		0x01000000UL

#define SERCOM_USART_CTRLA_PAR_DISABLE		0x00000000UL

//*****************************************************************************
//
//!
//
//*****************************************************************************

#define SERCOM_USART_RX_PIN_0				0x00000000UL

#define SERCOM_USART_RX_PIN_1				0x00100000UL

#define SERCOM_USART_RX_PIN_2				0x00200000UL

#define SERCOM_USART_RX_PIN_3				0x00300000UL

#define SERCOM_USART_TX_PIN_0				0x00000000UL

#define SERCOM_USART_TX_PIN_2				0x00010000UL

//*****************************************************************************
//
//! 
//
//*****************************************************************************

#define SERCOM_USART_ENABLE					0x00000002UL

#define SERCOM_USART_DISABLE				0x00000000UL

#define SERCOM_USART_ERROR_MASK				0x00000007UL

#define SERCOM_USART_LSB_FIRST				0x40000000UL

#define SERCOM_USART_INT_CLOCK				SERCOM_USART_CTRLA_MODE_USART_INT_CLK

#define SERCOM_USART_EXT_CLOCK				SERCOM_USART_CTRLA_MODE_USART_EXT_CLK

#define SERCOM_USART_GCLK_ID				0x00000000UL

#define GCLK_BASE							0x40000C00UL

#define UART0_CORE_CLOCK					0x400DUL

#define UART1_CORE_CLOCK					0x400EUL

#define UART2_CORE_CLOCK					0x400FUL

#define UART3_CORE_CLOCK					0x4010UL

#define UART4_CORE_CLOCK					0x4011UL

#define UART5_CORE_CLOCK					0x4012UL

#define PM_BASE								0x40000400UL

#define UART0_BUS_CLOCK						0x00000004UL

#define UART1_BUS_CLOCK						0x00000008UL

#define UART2_BUS_CLOCK						0x00000010UL

#define UART3_BUS_CLOCK						0x00000020UL

#define UART4_BUS_CLOCK						0x00000040UL

#define UART5_BUS_CLOCK						0x00000080UL

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

void UARTConfigSet(unsigned long ulBase, unsigned long ulBaud,
                   unsigned long ulConfig);

void UARTEnable(unsigned long ulBase);

void UARTBlockEnable(unsigned long ulBase, unsigned long ulConfig);

void UARTDisable(unsigned long ulBase);

void UARTBlockDisable(unsigned long ulBase, unsigned long ulConfig);

xtBoolean UARTCharsAvail(unsigned long ulBase);

unsigned long UARTCharGetNonBlocking(unsigned long ulBase);

unsigned char UARTCharGet(unsigned long ulBase);

xtBoolean UARTCharPutNonBlocking(unsigned long ulBase, unsigned char ulData);

void UARTCharPut(unsigned long ulBase, unsigned char ulData);

xtBoolean UARTBusy(unsigned long ulBase);

unsigned long UARTRxErrorGet(unsigned long ulBase);

void UARTRxErrorClear(unsigned long ulBase);

//SAM D20 specific API's

void UARTRxPinSelect(unsigned long ulBase, unsigned long ulRxPin);

void UARTTxPinSelect(unsigned long ulBase, unsigned long ulTxPin);

void UARTClockMode(unsigned long ulBase, unsigned long ulConfig);

void UARTClockEnable(unsigned long ulBase);

void UARTMsbFirst(unsigned long ulBase);

void UARTLsbFirst(unsigned long ulBase);

void USARTWaitForSync(unsigned long ulBase);
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __xUART_H__

