//*****************************************************************************
//
//! \file xsercom_interrupt.h
//! \brief Prototypes for the SERCOM interrupts.
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
#include "xhw_sercom.h"
#include "xhw_memmap.h"
#include "xdebug.h"
#include "samd20j18.h"


#include "xsercom_interrupt.h"


//*****************************************************************************
//
// An array is UART callback function point
//
//*****************************************************************************
xtEventCallback g_pfnUARTHandlerCallbacks[SERCOM_INST_NUM];

xtEventCallback g_pfnSPIHandlerCallbacks[SERCOM_INST_NUM];

//*******************************************************************************
//NOTE 1: For clearing the interrupt flags, the following actions need to be done depending upon the flag
//
//USART
//RXS: Receive Start:  cleared by writing a one to it.
//RXC: Receive complete:  cleared by reading the Data register (DATA) or by disabling the receiver.
//TXC: Transmit complete:  writing a one to it or by writing new data to DATA.
//DRE: Data Register Empty:  cleared by writing new data to DATA.
//
//SPI
//RXC: Receive Complete:  cleared by reading the Data (DATA) register or by disabling the receiver.
//TXC: Transmit Complete:  cleared by writing a one to it or by writing new data to DATA.
//DRE: Data Register Empty:  cleared by writing new data to DATA.
//********************************************************************************

//*****************************************************************************
//
//! \internal
//! \brief The function is the UART0 interrupt service.
//!
//! \param None.
//!
//! This function is a interrupt service routine of UART0.
//!
//! \return None.
//
//*****************************************************************************
void SERCOM0_Handler(void)
 {
    volatile unsigned long ulTemp = 0, ulSercomMode = 0;
	
	ulTemp = xHWREG(xUART0_BASE + SERCOM_USART_CTRLA_OFFSET);
	ulSercomMode = (ulTemp & SERCOM_MODE_MASK)>>2;
	
	if((ulSercomMode == 0) || (ulSercomMode == 1))
	{
		(*g_pfnUARTHandlerCallbacks[0])();

	}
	else if((ulSercomMode == 2) || (ulSercomMode == 3))
	{
		(*g_pfnSPIHandlerCallbacks[0])();
	}
 }
 

//*****************************************************************************
//
//! \internal
//! \brief The function is the UART1 interrupt service.
//!
//! \param None.
//!
//! This function is a interrupt service routine of UART1.
//!
//! \return None.
//
//*****************************************************************************
void SERCOM1_Handler(void)
 {
    volatile unsigned long ulTemp = 0, ulSercomMode = 0;
	
	//note: for note on clearing interrupt flags, please refer the INTFLAGS register description in the SAM D20 datasheet
	
	ulTemp = xHWREG(xUART1_BASE + SERCOM_USART_CTRLA_OFFSET);
	ulSercomMode = (ulTemp & SERCOM_MODE_MASK)>>2;
	
	if((ulSercomMode == 0) || (ulSercomMode == 1))
	{
		(*g_pfnUARTHandlerCallbacks[1])();

	}
	else if((ulSercomMode == 2) || (ulSercomMode == 3))
	{
		(*g_pfnSPIHandlerCallbacks[1])();
	}
 }
 

//*****************************************************************************
//
//! \internal
//! \brief The function is the UART2 interrupt service.
//!
//! \param None.
//!
//! This function is a interrupt service routine of UART2.
//!
//! \return None.
//
//*****************************************************************************
void SERCOM2_Handler(void)
 {
    volatile unsigned long ulTemp = 0, ulSercomMode = 0;
	
	//note: for note on clearing interrupt flags, please refer the INTFLAGS register description in the SAM D20 datasheet
	
	ulTemp = xHWREG(xUART2_BASE + SERCOM_USART_CTRLA_OFFSET);
	ulSercomMode = (ulTemp & SERCOM_MODE_MASK)>>2;
	
	if((ulSercomMode == 0) || (ulSercomMode == 1))
	{
		(*g_pfnUARTHandlerCallbacks[2])();

	}
	else if((ulSercomMode == 2) || (ulSercomMode == 3))
	{
		(*g_pfnSPIHandlerCallbacks[2])();
	}
 }
 
//*****************************************************************************
//
//! \internal
//! \brief The function is the UART3 interrupt service.
//!
//! \param None.
//!
//! This function is a interrupt service routine of UART3.
//!
//! \return None.
//
//*****************************************************************************
void SERCOM3_Handler(void)
 {
    volatile unsigned long ulTemp = 0, ulSercomMode = 0;
	
	//note: for note on clearing interrupt flags, please refer the INTFLAGS register description in the SAM D20 datasheet
	
	ulTemp = xHWREG(xUART3_BASE + SERCOM_USART_CTRLA_OFFSET);
	ulSercomMode = (ulTemp & SERCOM_MODE_MASK)>>2;
	
	if((ulSercomMode == 0) || (ulSercomMode == 1))
	{
		(*g_pfnUARTHandlerCallbacks[3])();

	}
	else if((ulSercomMode == 2) || (ulSercomMode == 3))
	{
		(*g_pfnSPIHandlerCallbacks[3])();
	}
 }
 
 //*****************************************************************************
 //
 //! \internal
 //! \brief The function is the UART4 interrupt service.
 //!
 //! \param None.
 //!
 //! This function is a interrupt service routine of UART4.
 //!
 //! \return None.
 //
 //*****************************************************************************
 void SERCOM4_Handler(void)
 {
    volatile unsigned long ulTemp = 0, ulSercomMode = 0;
	
	//note: for note on clearing interrupt flags, please refer the INTFLAGS register description in the SAM D20 datasheet
	
	ulTemp = xHWREG(xUART4_BASE + SERCOM_USART_CTRLA_OFFSET);
	ulSercomMode = (ulTemp & SERCOM_MODE_MASK)>>2;
	
	if((ulSercomMode == 0) || (ulSercomMode == 1))
	{
		(*g_pfnUARTHandlerCallbacks[4])();

	}
	else if((ulSercomMode == 2) || (ulSercomMode == 3))
	{
		(*g_pfnSPIHandlerCallbacks[4])();
	}
 }
 
 
 
 //*****************************************************************************
 //
 //! \internal
 //! \brief The function is the UART5 interrupt service.
 //!
 //! \param None.
 //!
 //! This function is a interrupt service routine of UART5.
 //!
 //! \return None.
 //
 //*****************************************************************************
 void SERCOM5_Handler(void)
 {
    volatile unsigned long ulTemp = 0, ulSercomMode = 0;
	
	//note: for note on clearing interrupt flags, please refer the INTFLAGS register description in the SAM D20 datasheet
	
	ulTemp = xHWREG(xUART5_BASE + SERCOM_USART_CTRLA_OFFSET);
	ulSercomMode = (ulTemp & SERCOM_MODE_MASK)>>2;
	
	if((ulSercomMode == 0) || (ulSercomMode == 1))
	{
		(*g_pfnUARTHandlerCallbacks[5])();

	}
	else if((ulSercomMode == 2) || (ulSercomMode == 3))
	{
		(*g_pfnSPIHandlerCallbacks[5])();
	}
 }
 
 
 xtEventCallback DefaultInterruptCallback(void)
 {
	 while(1);
 }

 void SpiInitDefaultCallback(void)
 {
	 uint8_t i;
	 for (i=0; i<SERCOM_INST_NUM; i++){
		 g_pfnSPIHandlerCallbacks[i] = DefaultInterruptCallback;
	 }
	 
 }
 
 void UsartInitDefaultCallback(void)
  {
	  uint8_t i;
	  for (i=0; i<SERCOM_INST_NUM; i++){
		  g_pfnUARTHandlerCallbacks[i] = DefaultInterruptCallback;
	  }
	  
  }
 
//*****************************************************************************
//
//! \brief Init interrupts callback for the specified UART Port.
//!
//! \param ulPort is the base address of the UART port.
//! \param xtUARTCallback is callback for the specified UART Port.
//!
//! Init interrupts callback for the specified UART Port.
//!
//! The \e ulBase parameter can be one of the following:
//! - \b UART0_BASE    = UART 0 Module base address
//! - \b UART1_BASE    = UART 1 Module base address
//! - \b UART2_BASE    = UART 2 Module base address
//!
//! \return None.
//
//*****************************************************************************
void UARTIntCallbackInit(uint8_t ucSercomInstanceNum, xtEventCallback pfnCallback)
{
	xASSERT(ucSercomInstanceNum < SERCOM_INST_NUM);
	
	g_pfnUARTHandlerCallbacks[ucSercomInstanceNum] = pfnCallback;
}

//*****************************************************************************
//
//! \brief Init interrupts callback for the specified UART Port.
//!
//! \param ulPort is the base address of the UART port.
//! \param xtUARTCallback is callback for the specified UART Port.
//!
//! Init interrupts callback for the specified UART Port.
//!
//! The \e ulBase parameter can be one of the following:
//! - \b UART0_BASE    = UART 0 Module base address
//! - \b UART1_BASE    = UART 1 Module base address
//! - \b UART2_BASE    = UART 2 Module base address
//!
//! \return None.
//
//*****************************************************************************
void SPIIntCallbackInit(uint8_t ucSercomInstanceNum, xtEventCallback pfnCallback)
{
		xASSERT(ucSercomInstanceNum < SERCOM_INST_NUM);
		
        g_pfnSPIHandlerCallbacks[ucSercomInstanceNum] = pfnCallback;
}

void SercomSPIIntEnable(unsigned long ulBase, unsigned long ulIntflag)
{
	//
	// Check the parameters.
	//
	xASSERT((ulBase == xSPI0_BASE) ||
	(ulBase == xSPI1_BASE) ||
	(ulBase == xSPI2_BASE) ||
	(ulBase == xSPI3_BASE) ||
	(ulBase == xSPI4_BASE) ||
	(ulBase == xSPI5_BASE));
	
	switch(ulIntflag)
	{
		case xSPI_INT_DRE:
		{
			xHWREGB(ulBase + SERCOM_SPI_INTENSET_OFFSET) |= xSPI_INT_DRE;
			break;
		}
		case xSPI_INT_EOT:
		{
			xHWREGB(ulBase + SERCOM_SPI_INTENSET_OFFSET) |= xSPI_INT_EOT;
			break;
		}
		case xSPI_INT_RXC:
		{
			xHWREGB(ulBase + SERCOM_SPI_INTENSET_OFFSET) |= xSPI_INT_RXC;
			break;
		}
	}
}
void SercomUSARTIntEnable(unsigned long ulBase, unsigned long ulIntflag)
{
	//
	// Check the parameters.
	//
	xASSERT((ulBase == xUART0_BASE) ||
	(ulBase == xUART1_BASE) ||
	(ulBase == xUART2_BASE) ||
	(ulBase == xUART3_BASE) ||
	(ulBase == xUART4_BASE) ||
	(ulBase == xUART5_BASE));
	
	switch(ulIntflag)
	{
		case xUART_INT_RX:
		{
			xHWREGB(ulBase + SERCOM_USART_INTENSET_OFFSET) |= xUART_INT_RX;
			break;
		}
		case xUART_INT_RXS:
		{
			xHWREGB(ulBase + SERCOM_USART_INTENSET_OFFSET) |= xUART_INT_RXS;
			break;
		}
		case xUART_INT_TX:
		{
			xHWREGB(ulBase + SERCOM_USART_INTENSET_OFFSET) |= xUART_INT_TX;
			break;
		}
	}
}

void SercomUSARTIntDisable(unsigned long ulBase, unsigned long ulIntflag)
{
	//
	// Check the parameters.
	//
	xASSERT((ulBase == xUART0_BASE) ||
	(ulBase == xUART1_BASE) ||
	(ulBase == xUART2_BASE) ||
	(ulBase == xUART3_BASE) ||
	(ulBase == xUART4_BASE) ||
	(ulBase == xUART5_BASE));
	
	switch(ulIntflag)
	{
		case xUART_INT_RX:
		{
			xHWREGB(ulBase + SERCOM_USART_INTENCLR_OFFSET) |= xUART_INT_RX;
			break;
		}
		case xUART_INT_RXS:
		{
			xHWREGB(ulBase + SERCOM_USART_INTENCLR_OFFSET) |= xUART_INT_RXS;
			break;
		}
		case xUART_INT_TX:
		{
			xHWREGB(ulBase + SERCOM_USART_INTENCLR_OFFSET) |= xUART_INT_TX;
			break;
		}
	}
}

void SercomSPIIntDisable(unsigned long ulBase, unsigned long ulIntflag)
{
	//
	// Check the parameters.
	//
	xASSERT((ulBase == xSPI0_BASE) ||
	(ulBase == xSPI1_BASE) ||
	(ulBase == xSPI2_BASE) ||
	(ulBase == xSPI3_BASE) ||
	(ulBase == xSPI4_BASE) ||
	(ulBase == xSPI5_BASE));
	
	switch(ulIntflag)
	{
		case xSPI_INT_DRE:
		{
			xHWREGB(ulBase + SERCOM_SPI_INTENCLR_OFFSET) |= xSPI_INT_DRE;
			break;
		}
		case xSPI_INT_EOT:
		{
			xHWREGB(ulBase + SERCOM_SPI_INTENCLR_OFFSET) |= xSPI_INT_EOT;
			break;
		}
		case xSPI_INT_RXC:
		{
			xHWREGB(ulBase + SERCOM_SPI_INTENCLR_OFFSET) |= xSPI_INT_RXC;
			break;
		}
	}
}
