//*****************************************************************************
//
//! \file xuart.c
//! \brief Driver for the UART
//! \version V2.1.1.1
//! \date 08/17/2012
//! \author CooCox
//! \copy
//!
//! Copyright (c)  2012, CooCox
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


#include "xhw_sercom.h"
#include "xuart.h"
#include "xdebug.h"
#include "xhw_memmap.h"
#include "xhw_types.h"




//*****************************************************************************
//
//! \brief Sets the configuration of a UART.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBaud is the desired baud rate.
//! \param ulConfig is the data format for the port (number of data bits,
//! number of stop bits, parity and oversample ratio).
//!
//! This function configures the UART for operation in the specified data
//! format.  The baud rate is provided in the \e ulBaud parameter and the data
//! format in the \e ulConfig parameter.
//!
//! The \e ulBase parameter can be one of the following:
//! - \b xUART0_BASE    = UART 0 Module base address
//! - \b xUART1_BASE    = UART 1 Module base address
//! - \b xUART2_BASE    = UART 2 Module base address
//! - \b xUART3_BASE    = UART 3 Module base address
//! - \b xUART4_BASE    = UART 4 Module base address
//! - \b xUART5_BASE    = UART 5 Module base address
//!
//! The \e ulBaud parameter can be one of the following:
//! The \e ulConfig parameter is the logical OR of four values: the number of
//! data bits, the number of stop bits, the parity and the oversample ratio.
//!
//! - \b xUART_CONFIG_WLEN_5
//! - \b xUART_CONFIG_WLEN_6
//! - \b xUART_CONFIG_WLEN_7
//! - \b xUART_CONFIG_WLEN_8
//! - \b xUART_CONFIG_WLEN_9
//! - \b xUART_CONFIG_PAR_ODD
//! - \b xUART_CONFIG_PAR_EVEN
//! - \b xUART_CONFIG_PAR_DISABLE
//! - \b xUART_CONFIG_PAR_ENABLE
//! - \b xUART_CONFIG_STOP_1
//! - \b xUART_CONFIG_STOP_2
//!
//! \b UART_CONFIG_WLEN_8,\b UART_CONFIG_WLEN_9,\b UART_CONFIG_WLEN_10
//! select from eight to ten data bits per byte (respectively).
//! \b UART_CONFIG_STOP_ONE and \b UART_CONFIG_STOP_TWO select one two stop
//! bits (respectively).
//! \b UART_CONFIG_PAR_NONE, \b UART_CONFIG_PAR_EVEN,\b UART_CONFIG_PAR_ODD
//! select the parity mode (no parity bit, even parity bit, odd parity bit,
//! parity bit always one, and parity bit always zero, respectively).
//! \b UART_CONFIG_SAMPLE_RATE_xx,  \b UART_CONFIG_SAMPLE_RATE_DEFAULT select
//! uart oversample ratio, this parameter is only used for UART0 module.
//!
//!
//! \note Oversample ratio is only used in UART 0 Module.
//! \return None.
//
//*****************************************************************************
void UARTConfigSet(unsigned long ulBase,
                   unsigned long ulBaud,
                   unsigned long ulConfig)
{
    float ulUartClock  = 0, ulTemp = 0;
    unsigned short ulBaudReg    = 0;
    unsigned long ulWlen       = 0;
	unsigned long ulParity     = 0;
    unsigned long ulStop       = 0;

    //
    // Check the parameters.
    //
    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
    xASSERT(0 == (ulConfig & ~(xUART_CONFIG_WLEN_5  | xUART_CONFIG_WLEN_6  |
                               xUART_CONFIG_WLEN_7  | xUART_CONFIG_WLEN_8  |
							   xUART_CONFIG_WLEN_9  | xUART_CONFIG_PAR_ODD  |
                               xUART_CONFIG_PAR_EVEN | xUART_CONFIG_PAR_DISABLE |
							   xUART_CONFIG_PAR_ENABLE | xUART_CONFIG_STOP_1   | 
							   xUART_CONFIG_STOP_2 )));

    //
    // Configure UART Baud Rate.
    //
	
	ulUartClock = 8000000;		//add function to get the peripheral clock value for the selected UART
    ulTemp = 65536.0*(1-((16*ulBaud)/ulUartClock));
	ulBaudReg = ulTemp;
	USARTWaitForSync(ulBase);
	xHWREGH(ulBase+SERCOM_USART_BAUD_OFFSET) = ulBaudReg;
	
    //
    // Configure bytes length
    //
	ulWlen = ulConfig & xUART_CONFIG_WLEN_MASK;
	USARTWaitForSync(ulBase);
	xHWREG(ulBase+SERCOM_USART_CTRLB_OFFSET) |= ulWlen;
	
    //
    // Configure Parity
    //
	
	
	
	switch(ulConfig & xUART_CONFIG_PAR_ENABLE_MASK)
    {
        case  xUART_CONFIG_PAR_DISABLE:
        {
			USARTWaitForSync(ulBase);
            xHWREG(ulBase+SERCOM_USART_CTRLA_OFFSET) |= xUART_CONFIG_PAR_DISABLE;            
            break ;
        }

        case  xUART_CONFIG_PAR_ENABLE:
        {
			USARTWaitForSync(ulBase);
            xHWREG(ulBase+SERCOM_USART_CTRLA_OFFSET) |= xUART_CONFIG_PAR_ENABLE;
			ulParity = ulConfig & xUART_CONFIG_PAR_MASK;
			
			USARTWaitForSync(ulBase);
		    xHWREG(ulBase+SERCOM_USART_CTRLB_OFFSET) |= ulParity;
            break ;
        }
	}

    //
    // Configure Stop Bit
    //
	
	ulStop = ulConfig & xUART_CONFIG_STOP_MASK;
	USARTWaitForSync(ulBase);
	xHWREG(ulBase+SERCOM_USART_CTRLB_OFFSET) |= ulStop;

}

void UARTClockMode(unsigned long ulBase, unsigned long ulConfig)
{
	xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
			
	xASSERT((ulConfig == SERCOM_USART_INT_CLOCK) || (ulConfig == SERCOM_USART_EXT_CLOCK));
	
	USARTWaitForSync(ulBase);
	xHWREG(ulBase + SERCOM_USART_CTRLA_OFFSET) |= ulConfig;

}


//*****************************************************************************
//
//! \brief Configures USART Rx pin in SERCOM peripheral
//!
//! \param ulBase is the base address of the UART port
//! \param ulRxPin is the SERCOM pad number to be configured as Rx pin
//!
//! returns none
//
//****************************************************************************

void UARTRxPinSelect(unsigned long ulBase, unsigned long ulRxPin)
{
	xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
	xASSERT((ulRxPin == SERCOM_USART_RX_PIN_0) || (ulRxPin == SERCOM_USART_RX_PIN_1) ||
			(ulRxPin == SERCOM_USART_RX_PIN_2) || (ulRxPin == SERCOM_USART_RX_PIN_3));
	
	USARTWaitForSync(ulBase);	
	xHWREG(ulBase+SERCOM_USART_CTRLA_OFFSET) |= ulRxPin;
}

//*****************************************************************************
//
//! \brief Configures USART Tx pin in SERCOM peripheral
//!
//! \param ulBase is the base address of the UART port
//! \param ulTxPin is the SERCOM pad number to be configured as Tx pin
//!
//! returns none
//
//*****************************************************************************

void UARTTxPinSelect(unsigned long ulBase, unsigned long ulTxPin)
{
	xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
			
	xASSERT((ulTxPin == SERCOM_USART_TX_PIN_0) || (ulTxPin == SERCOM_USART_TX_PIN_2));
	
	USARTWaitForSync(ulBase);	
	xHWREG(ulBase+SERCOM_USART_CTRLA_OFFSET) |= ulTxPin;
}


//*****************************************************************************
//
//! \brief Enables transmitting or receiving.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBlock is the block to enable. it is the logical OR of
//! these values:  \b UART_TX, \b UART_RX.
//!
//! Sets the TXE or RXE bits.
//!
//! \return None.
//
//*****************************************************************************
void UARTEnable(unsigned long ulBase)
{
    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
	USARTWaitForSync(ulBase);
    xHWREG(ulBase + SERCOM_USART_CTRLA_OFFSET) |= SERCOM_USART_CTRLA_ENABLE;
}

//*****************************************************************************
//
//! \brief Enables transmitting or receiving.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBlock is the block to enable. it is the logical OR of
//! these values:  \b UART_TX, \b UART_RX.
//!
//! Sets the TXE or RXE bits.
//!
//! \return None.
//
//*****************************************************************************
void UARTBlockEnable(unsigned long ulBase, unsigned long ulBlock)
{
	xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
    xASSERT(0 == (ulBlock & ~(xUART_BLOCK_TX | xUART_BLOCK_RX)));

	switch(ulBlock)
	{
		case xUART_BLOCK_TX:
		{
			USARTWaitForSync(ulBase);
			xHWREG(ulBase+SERCOM_USART_CTRLB_OFFSET) |= SERCOM_USART_CTRLB_TXEN;
			break;
		}
		
		case xUART_BLOCK_RX:
		{
			USARTWaitForSync(ulBase);
			xHWREG(ulBase+SERCOM_USART_CTRLB_OFFSET) |= SERCOM_USART_CTRLB_RXEN;
			break;
		}
	}
	
}

//*****************************************************************************
//
//! \brief Disables transmitting or receiving.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBlock is the block to disable. it is the logical OR of
//! these values:  \b UART_TX, \b UART_RX.
//!
//! Sets the TXE or RXE bits.
//!
//! \return None.
//
//*****************************************************************************
void UARTDisable(unsigned long ulBase)
{
    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
	USARTWaitForSync(ulBase);
	xHWREG(ulBase + SERCOM_USART_CTRLA_OFFSET) &= (unsigned long)(~(SERCOM_USART_ENABLE));
}

//*****************************************************************************
//
//! \brief disables transmitting or receiving.
//!
//! \param ulBase is the base address of the UART port.
//! \param ulBlock is the block to disable. it is the logical OR of
//! these values:  \b UART_TX, \b UART_RX.
//!
//! Sets the TXE or RXE bits.
//!
//! \return None.
//
//*****************************************************************************
void UARTBlockDisable(unsigned long ulBase, unsigned long ulBlock)
{
	xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
    xASSERT(0 == (ulBlock & ~(xUART_BLOCK_TX | xUART_BLOCK_RX)));

	switch(ulBlock)
	{
		case xUART_BLOCK_TX:
		{
			USARTWaitForSync(ulBase);
			xHWREG(ulBase+SERCOM_USART_CTRLB_OFFSET) &= (unsigned long)(~(SERCOM_USART_CTRLB_TXEN));
			break;
		}
		
		case xUART_BLOCK_RX:
		{
			USARTWaitForSync(ulBase);
			xHWREG(ulBase+SERCOM_USART_CTRLB_OFFSET) |= (unsigned long)(~(SERCOM_USART_CTRLB_RXEN));
			break;
		}
	}
	
}

void UARTClockEnable(unsigned long ulBase)
{
	xASSERT((ulBase == xUART0_BASE) ||
	(ulBase == xUART1_BASE) ||
	(ulBase == xUART2_BASE) ||
	(ulBase == xUART3_BASE) ||
	(ulBase == xUART4_BASE) ||
	(ulBase == xUART5_BASE));
	
	switch(ulBase)
	{
		case xUART0_BASE:
		{
			
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= UART0_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) |= UART0_CORE_CLOCK;
			break;
		}
			
		case xUART1_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= UART1_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) |= UART1_CORE_CLOCK;
			break;
		}
		
		
		case xUART2_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= UART2_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) = UART2_CORE_CLOCK;
			break;
		}
		
		case xUART3_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= UART3_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) = UART3_CORE_CLOCK;
			break;
		}
		
		case xUART4_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= UART4_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) = UART4_CORE_CLOCK;
			break;
		}
		
		case xUART5_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= UART5_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) = UART5_CORE_CLOCK;
			break;
		}
	}
	
}

//*****************************************************************************
//
//! \brief Determines if there are any characters in receiver register.
//!
//! \param ulBase is the base address of the UART port.
//!
//! This function returns a flag indicating whether or not there is data
//! available in the receive register.
//!
//! \return Returns \b true if there is data in the receive register or \b false
//! if there is no data in the receive register.
//
//*****************************************************************************
xtBoolean UARTCharsAvail(unsigned long ulBase)
{
    xtBoolean ulStatus = xfalse;

    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
	
	
    ulStatus = (xtBoolean)(xHWREGB(ulBase + SERCOM_USART_INTFLAG_OFFSET) &
                          ((unsigned char) SERCOM_USART_INTFLAG_DRE));

    return (ulStatus);
}


//*****************************************************************************
//
//! \brief Receives a character from the specified port.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Gets a character from the receive register for the specified port.
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
unsigned long UARTCharGetNonBlocking(unsigned long ulBase)
{
    xtBoolean     ulStatus = xfalse;
    unsigned long ulChar   = 0;

    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));

    //
    // Char available?
    //
	
	ulStatus = (xtBoolean) (xHWREGB(ulBase + SERCOM_USART_INTFLAG_OFFSET) & 
									(unsigned char)SERCOM_USART_INTFLAG_RXC);
    
    if(xtrue == ulStatus)                        // Char available
    {
        ulChar = (unsigned long) xHWREGH(ulBase + SERCOM_USART_DATA_OFFSET);
    }
    else                                         // Char Not available
    {
        ulChar = (unsigned long) (-1);
    }

    return (ulChar);
}

//*****************************************************************************
//
//! \brief Waits for a character from the specified port.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Gets a character from the receive register for the specified port.  If there
//! are no characters available, this function waits until a character is
//! received before returning.
//!
//! \return Returns the character read from the specified port, cast as a
//! \e long.
//
//*****************************************************************************
unsigned char UARTCharGet(unsigned long ulBase)
{
    unsigned long          ulChar   = 0;
    volatile unsigned char ulStatus = 0;

    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));


    //
    // Wait until Receive a char
    //
    while(0 == ulStatus)
    {
		ulStatus = xHWREGB(ulBase + SERCOM_USART_INTFLAG_OFFSET) & (unsigned char)SERCOM_USART_INTFLAG_RXC;

    }

    //
    // Get the char
    //
	ulChar = (unsigned long) xHWREGH(ulBase + SERCOM_USART_DATA_OFFSET);
    return (ulChar);
}

//*****************************************************************************
//
//! \brief Sends a character to the specified port.
//!
//! \param ulBase is the base address of the UART port.
//! \param ucData is the character to be transmitted.
//!
//! Writes the character \e ucData to the transmit register for the specified port.
//! This function does not block, so if there is no space available, then a
//! \b false is returned, and the application must retry the function later.
//!
//! This function replaces the original UARTCharNonBlockingPut() API and
//! performs the same actions.  A macro is provided in <tt>uart.h</tt> to map
//! the original API to this API.
//!
//! \return Returns \b true if the character was successfully placed in the
//! transmit register or \b false if there was no space available in the transmit
//! register.
//
//*****************************************************************************
xtBoolean UARTCharPutNonBlocking(unsigned long ulBase, unsigned char ulData)
{
    xtBoolean     ulStatus = 0;
    xtBoolean     ulResult = 0;

    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));

    //
    // Transmit register is available ?
    //
    ulStatus = (xtBoolean) (xHWREGB(ulBase + SERCOM_USART_INTFLAG_OFFSET) & SERCOM_USART_INTFLAG_DRE);

    if(xtrue == ulStatus)                      // Transmit Register available
    {
        xHWREGH(ulBase + SERCOM_USART_DATA_OFFSET) = ulData;
        ulResult = xtrue;
    }
    else                                       // Transmit Register NOT available
    {
        ulResult = xfalse;
    }

    return (ulResult);
}

//*****************************************************************************
//
//! \brief Waits to send a character from the specified port.
//!
//! \param ulBase is the base address of the UART port.
//! \param ucData is the character to be transmitted.
//!
//! Sends the character \e ucData to the transmit register for the specified port.
//! If there is no space available in the transmit register, this function waits
//! until there is space available before returning.
//!
//! \return None.
//
//*****************************************************************************
void UARTCharPut(unsigned long ulBase, unsigned char ulData)
{
    volatile unsigned char ulStatus = 0;

    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));


    //
    // Wait until transmit register available
    //

	while(0 == ulStatus)
    {
        ulStatus = xHWREGB(ulBase + SERCOM_USART_INTFLAG_OFFSET) & ((unsigned char)SERCOM_USART_INTFLAG_DRE);
    }

    //
    // Send the char
    //
    xHWREGH(ulBase + SERCOM_USART_DATA_OFFSET) = ulData;
	
	while(!(xHWREGB(ulBase + SERCOM_USART_INTFLAG_OFFSET) & ((unsigned char)SERCOM_USART_INTFLAG_TXC)));

}

//*****************************************************************************
//
//! \brief Determines whether the UART transmitter is busy or not.
//!
//! \param ulBase is the base address of the UART port.
//!
//! Allows the caller to determine whether all transmitted bytes have cleared
//! the transmitter hardware.  If \b false is returned, the transmit register is
//! empty and all bits of the last transmitted character, including all stop
//! bits, have left the hardware shift register.
//!
//! \return Returns \b true if the UART is transmitting or \b false if all
//! transmissions are complete.
//
//*****************************************************************************
xtBoolean UARTBusy(unsigned long ulBase)
{
    xtBoolean ulStatus = xfalse;

    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));

    ulStatus = (xtBoolean) xHWREGB(ulBase + SERCOM_USART_INTFLAG_OFFSET) &
                           ((unsigned char)SERCOM_USART_INTFLAG_DRE);

    //
    // Transmit full mean busy and vice versa
    //
    ulStatus = !ulStatus;

    return (ulStatus);
}






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
//! \b xUART_RXERROR_FRAMING, \b xUART_RXERROR_PARITY, \b 
//! and \b xUART_RXERROR_OVERRUN.
//
//*****************************************************************************
unsigned long UARTRxErrorGet(unsigned long ulBase)
{
    unsigned long ulErrorFlag = 0;

    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
			
	ulErrorFlag = ((unsigned long)xHWREG(ulBase + SERCOM_USART_STATUS_OFFSET)) & SERCOM_USART_ERROR_MASK;



    return ulErrorFlag;
}


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
void UARTRxErrorClear(unsigned long ulBase)
{
    xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
			
	xHWREG(ulBase + SERCOM_USART_STATUS_OFFSET) = SERCOM_USART_ERROR_MASK;
}

//*****************************************************************************
//
//! \brief Configure MSB of chars to be sent first.
//!
//! \param ulPort is the base address of the UART port.
//!
//! Setting this bit reverses the order of the bits that are transmitted and
//! received on the wire. this bit does not affect the polarity of the bits,
//! the location of the parity bit or the location of the start or stop bits.
//! This bit should only be changed when the transmitter and receiver are both
//! disabled.
//!
//! \return None.
//
//*****************************************************************************
void UARTLsbFirst(unsigned long ulBase)
{
	xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
			
	USARTWaitForSync(ulBase);
	xHWREG(ulBase + SERCOM_USART_CTRLA_OFFSET) |= (unsigned long)SERCOM_USART_LSB_FIRST;
}

//*****************************************************************************
//
//! \brief Configure LSB of chars to be sent first.
//!
//! \param ulPort is the base address of the UART port.
//!
//! Setting this bit reverses the order of the bits that are transmitted and
//! received on the wire. this bit does not affect the polarity of the bits,
//! the location of the parity bit or the location of the start or stop bits.
//! This bit should only be changed when the transmitter and receiver are both
//! disabled.
//!
//! \return None.
//
//*****************************************************************************
void UARTMsbFirst(unsigned long ulBase)
{
	xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
			
	USARTWaitForSync(ulBase);
    xHWREGB(ulBase + SERCOM_USART_CTRLA_OFFSET) &= (unsigned char)(~SERCOM_USART_LSB_FIRST);
}

void USARTWaitForSync(unsigned long ulBase)
{
	unsigned char ulStatus = 0;
	xASSERT((ulBase == xUART0_BASE) ||
            (ulBase == xUART1_BASE) ||
            (ulBase == xUART2_BASE) ||
			(ulBase == xUART3_BASE) ||
			(ulBase == xUART4_BASE) ||
			(ulBase == xUART5_BASE));
	do
	{
		ulStatus = xHWREG(ulBase+ SERCOM_USART_STATUS_OFFSET) & ((unsigned char)SERCOM_USART_STATUS_SYNCBUSY);
	} while(1==ulStatus);
}
