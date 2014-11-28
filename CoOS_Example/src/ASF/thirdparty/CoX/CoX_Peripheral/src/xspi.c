//*****************************************************************************
//
//! \file xspi.c
//! \brief Driver for the SPI
//! \version V2.1.1.0
//! \date 12/27/2011
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
#include "xspi.h"
#include "xdebug.h"
#include "xhw_memmap.h"


//*****************************************************************************
//
//! \brief Configures the synchronous serial interface.
//!
//! \param ulBase specifies the SPI module base address.
//! \param ulBitRate specifies the clock rate.
//! \param ulConfig specifies direction of SPI mode, master/slave, and data order.
//!
//! This function configures the synchronous serial interface.  It sets
//! the SPI protocol, mode of operation, bit rate, and data shift direction.
//!
//! \return None.
//! Self note: parameters to be in ulConfig - mode - 0,1,2,3, master/slave, LSB/msb first,
//
//*****************************************************************************
void SPIConfigSet(unsigned long ulBase, unsigned long ulBitRate, unsigned long ulConfig)
{
    unsigned long ulMode;
    unsigned long ulDataOrder;
	unsigned short ulBaudReg = 0;
	float ulSPIClock  = 0, ulTemp = 0;    

	
    //
    // Check the arguments.
    //
	xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));    
			
	xASSERT(0 == (ulConfig & ~(xSPI_MOTO_FORMAT_MODE_0  | xSPI_MOTO_FORMAT_MODE_1  |
                               xSPI_MOTO_FORMAT_MODE_2  | xSPI_MOTO_FORMAT_MODE_3  |
							   xSPI_MODE_MASTER | xSPI_MODE_SLAVE |
							   xSPI_MSB_FIRST | xSPI_LSB_FIRST)));
							   
    //
    // Set the clock predivider.
    //
    ulSPIClock = 8000000;		//add function to get the peripheral clock value for the selected UART
    ulTemp = (ulSPIClock/(2*ulBitRate))-1;
	ulBaudReg = ulTemp;
	SPIWaitForSync(ulBase);
	xHWREGH(ulBase+SERCOM_SPI_BAUD_OFFSET) = ulBaudReg;
	
    //
    // configure SPI mode	
    //
    //SERCOM_OP_MODE_MASK //SERCOM_SPI_MODE_MASK
	ulMode = ulConfig & (SERCOM_OP_MODE_MASK | SERCOM_SPI_MODE_MASK);
	SPIWaitForSync(ulBase);
	xHWREG(ulBase + SERCOM_SPI_CTRLA_OFFSET) |= ulMode;
	
	//configure data order
	ulDataOrder = ulConfig & SERCOM_SPI_DORD_MASK;
	SPIWaitForSync(ulBase);
	xHWREG(ulBase + SERCOM_SPI_CTRLA_OFFSET) |= ulDataOrder;
}
//*****************************************************************************
//
//! \brief writes and reads a single byte of data
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function enables operation of the synchronous peripheral interface.The
//! synchronous peripheral interface must be configured before it is enabled.
//!
//! \return None.
//
//*****************************************************************************
	
	
void SPIRxEnable(unsigned long ulBase)
{
	xASSERT((ulBase == xSPI0_BASE) ||
			(ulBase == xSPI1_BASE) ||
			(ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));
	
	SPIWaitForSync(ulBase);
	xHWREG(ulBase + SERCOM_SPI_CTRLB_OFFSET) |= SERCOM_SPI_CTRLB_RXEN;
		
}


xtBoolean SPISingleDataWriteNonblocking (unsigned long ulBase, unsigned char ulWData)
{
    xtBoolean     ulStatus = 0;
    xtBoolean     ulResult = 0;
	
	xASSERT((ulBase == xSPI0_BASE) ||
	(ulBase == xSPI1_BASE) ||
	(ulBase == xSPI2_BASE) ||
	(ulBase == xSPI3_BASE) ||
	(ulBase == xSPI4_BASE) ||
	(ulBase == xSPI5_BASE));

    //
    // Transmit register is available ?
    //
    ulStatus = xHWREGB(ulBase + SERCOM_SPI_INTFLAG_OFFSET) & SERCOM_SPI_INTFLAG_DRE;

    if(xtrue == ulStatus)                      // Transmit Register available
    {
        xHWREGH(ulBase + SERCOM_SPI_DATA_OFFSET) = ulWData;
        ulResult = xtrue;
    }
    else                                       // Transmit Register NOT available
    {
        ulResult = xfalse;
    }

    return (ulResult);
}


	
unsigned long SPISingleDataReadWrite (unsigned long ulBase, unsigned char ulWData)	
{
	unsigned char ulRdata = 0;
	unsigned long ulStatus = 0;
	
	xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));


    //
    // Wait until transmit register available
    //

	while(0 == ulStatus)
    {
        ulStatus = xHWREGB(ulBase + SERCOM_SPI_INTFLAG_OFFSET) & ((unsigned char)SERCOM_SPI_INTFLAG_DRE);
    }

    //
    // Send the char
    //
    xHWREGH(ulBase + SERCOM_SPI_DATA_OFFSET) = ulWData;
	
	while(!(xHWREGB(ulBase + SERCOM_SPI_INTFLAG_OFFSET) & ((unsigned char)SERCOM_SPI_INTFLAG_TXC)));

	//
	// wait for char to be received
	//
// 	ulStatus = 0;
// 	
//     while(0 == ulStatus)
//     {
// 		ulStatus = xHWREGB(ulBase + SERCOM_SPI_INTFLAG_OFFSET) & (unsigned char)SERCOM_SPI_INTFLAG_RXC;
// 
//     }
// 	
//SERCOM_SPI_STATUS_BUFOVF
//	ulStatus = 0;
//	if (xHWREGB(ulBase + SERCOM_SPI_STATUS_OFFSET) & (unsigned char)SERCOM_SPI_STATUS_BUFOVF)
//	{
//		xHWREGB(ulBase + SERCOM_SPI_STATUS_OFFSET) |= (unsigned char)SERCOM_SPI_STATUS_BUFOVF;
//		return (-1);
//	}

	ulStatus = 0;
	
    while(0 == ulStatus)
    {
		ulStatus = xHWREGB(ulBase + SERCOM_SPI_INTFLAG_OFFSET) & (unsigned char)SERCOM_SPI_INTFLAG_RXC;

    }

    //
    // Get the char
    //
	ulRdata = (unsigned long) xHWREGH(ulBase + SERCOM_SPI_DATA_OFFSET);
    return (ulRdata);
	
	
}

//*****************************************************************************
//
//! \brief Enables the synchronous peripheral interface.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function enables operation of the synchronous peripheral interface.The
//! synchronous peripheral interface must be configured before it is enabled.
//!
//! \return None.
//
//*****************************************************************************
void SPIEnable(unsigned long ulBase)
{
    xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));
	SPIWaitForSync(ulBase);
    xHWREG(ulBase + SERCOM_SPI_CTRLA_OFFSET) |= SERCOM_SPI_CTRLA_ENABLE;
}

//*****************************************************************************
//
//! \brief Disables the synchronous peripheral interface.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function disables operation of the synchronous peripheral interface.
//!
//! \return None.
//
//*****************************************************************************
void
SPIDisable(unsigned long ulBase)
{
    xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));
	SPIWaitForSync(ulBase);
	xHWREG(ulBase + SERCOM_SPI_CTRLA_OFFSET) &= (unsigned long)(~(SERCOM_SPI_CTRLA_ENABLE));
}

//*****************************************************************************
//
//! \brief Enables individual SPI interrupt sources.
//!
//! \param ulBase specifies the SPI module base address.
//! \param ulIntFlags is a bit mask of the interrupt sources to be enabled.
//!
//! Enables the indicated SPI interrupt sources.  Only the sources that are
//! enabled can be reflected to the processor interrupt; disabled sources have
//! no effect on the processor.  The \e ulIntFlags parameter can be any of the
//! \b SPI_SPRF, \b SPI_MODF, \b SPI_SPTEF, \b SPI_SPMF or \b SPI_SPLPF values.
//!
//! \return None.
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Gets the current interrupt status.
//!
//! \param ulBase specifies the SPI module base address.
//! \param bMasked is \b xfalse if the raw interrupt status is required or
//! \b xtrue if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the SPI module.  Either the
//! raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned.
//!
//! \return The current interrupt status, enumerated as a bit field of
//! \b SPI_SPRF, \b SPI_MODF, \b SPI_SPTEF, and \b SPI_SPMF.
//
//*****************************************************************************
unsigned long SPIIntStatus(unsigned long ulBase, xtBoolean bMasked)
{
    //
    // Check the arguments.
    //
    xASSERT((ulBase == xSPI0_BASE) ||
    (ulBase == xSPI1_BASE) ||
    (ulBase == xSPI2_BASE) ||
    (ulBase == xSPI3_BASE) ||
    (ulBase == xSPI4_BASE) ||
    (ulBase == xSPI5_BASE));
    xASSERT(bMasked == xfalse);
	
    //
    // Return  the interrupt status as requested.
    // 
    return (xHWREGB(ulBase + SERCOM_SPI_INTFLAG_OFFSET)) ;
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
xtBoolean SPIBusy(unsigned long ulBase)
{
    xtBoolean ulStatus = xfalse;

    xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));

    ulStatus = (xtBoolean) xHWREGB(ulBase + SERCOM_SPI_INTFLAG_OFFSET) &
                           ((unsigned char)SERCOM_SPI_INTFLAG_DRE);

    //
    // Transmit full mean busy and vice versa
    //
    ulStatus = !ulStatus;

    return (ulStatus);
}


//*****************************************************************************
//
//! \brief Gets a data element from the SPI interface.
//!
//! \param ulBase specifies the SPI module base address.
//! \param pulData is a pointer to a storage location for data that was
//! received over the SPI interface.
//! \param ulLen specifies the length of data will be read.
//!
//! This function gets received data from the interface of the specified
//! SPI module and places that data into the location specified by the
//! \e pulData parameter.
//!
//! \note The data width is always 8-bit.
//!
//! \return None.
//
//*****************************************************************************        
void SPIDataRead(unsigned long ulBase, unsigned long *pulRData, unsigned long ulLen)
{
    unsigned long i;
    
    //
    // Check the arguments.
    //
	xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));   

	xASSERT(pulRData);
    
    for(i = 0; i < ulLen; i++)
    {
        pulRData[i] = SPISingleDataReadWrite(ulBase, 0xFFFF);
    }
}

//*****************************************************************************
//
//! \brief Write datas element to the SPI interface.
//!
//! \param ulBase specifies the SPI module base address.
//! \param pulWData is a pointer to a storage location for data that was
//! transmitted over the SPI interface.
//! \param ulLen specifies the length of data will be write.
//!
//! This function transmitted data to the interface of the specified
//! SPI module .
//!
//! \note The data width is always 8-bit.
//!
//! \return None.
//
//*****************************************************************************        
void SPIDataWrite(unsigned long ulBase, const unsigned long *pulWData, 
             unsigned long ulLen)
{
    unsigned long i;
    volatile unsigned long ulRDataDump;
    
    //
    // Check the arguments.
    //
	xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));    
	xASSERT(pulWData);
    
    for(i = 0; i < ulLen; i++)
    {
        ulRDataDump = SPISingleDataReadWrite(ulBase, pulWData[i]);
    }    
}


void SPIClockEnable(unsigned long ulBase)
{
	xASSERT((ulBase == xSPI0_BASE) ||
	(ulBase == xSPI1_BASE) ||
	(ulBase == xSPI2_BASE) ||
	(ulBase == xSPI3_BASE) ||
	(ulBase == xSPI4_BASE) ||
	(ulBase == xSPI5_BASE));
	
	switch(ulBase)
	{
		case xSPI0_BASE:
		{
			
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= SPI0_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) |= SPI0_CORE_CLOCK;
			break;
		}
			
		case xSPI1_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= SPI1_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) |= SPI1_CORE_CLOCK;
			break;
		}
		
		
		case xSPI2_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= SPI2_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) = SPI2_CORE_CLOCK;
			break;
		}
		
		case xSPI3_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= SPI3_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) = SPI3_CORE_CLOCK;
			break;
		}
		
		case xSPI4_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= SPI4_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) = SPI4_CORE_CLOCK;
			break;
		}
		
		case xSPI5_BASE:
		{
			xHWREG(PM_BASE + PM_APBCMASK_OFFSET) |= SPI5_BUS_CLOCK;
			xHWREGH(GCLK_BASE + GCLK_CLKCTRL_OFFSET) = SPI5_CORE_CLOCK;
			break;
		}
	}
	
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

void SPIInputPinSel(unsigned long ulBase, unsigned long ulInputPin)
{
	xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));
	xASSERT((ulInputPin == SERCOM_SPI_DI_PIN_0) || (ulInputPin == SERCOM_SPI_DI_PIN_1) ||
			(ulInputPin == SERCOM_SPI_DI_PIN_2) || (ulInputPin == SERCOM_SPI_DI_PIN_3));
	
	SPIWaitForSync(ulBase);	
	xHWREG(ulBase+SERCOM_SPI_CTRLA_OFFSET) |= ulInputPin;
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

void SPIOutputPinSel(unsigned long ulBase, unsigned long ulOutputPin)
{
	xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));
	
	xASSERT((ulOutputPin == SERCOM_SPI_DO_PINCFG_0) || (ulOutputPin == SERCOM_SPI_DO_PINCFG_1) ||
			(ulOutputPin == SERCOM_SPI_DO_PINCFG_2) || (ulOutputPin == SERCOM_SPI_DO_PINCFG_3));
		
	
	SPIWaitForSync(ulBase);	
	xHWREG(ulBase+SERCOM_SPI_CTRLA_OFFSET) |= ulOutputPin;
}



//*****************************************************************************
//
//! \brief set the SPI clock status when the MCU enters wait mode.
//!
//! \param ulBase specifies the SPI module base address.
//! \param ulMode specifies the SPI clock status in wait mode.
//!
//! This function is to set the SPI clock continue when the MCU enters wait mode.
//!
//! The \e ulMode can be one of the following values:
//! \b SPI_CLK_STOP or \b SPI_CLK_CONTINUE.
//!
//! \note This bit is used for power conservation while the device is in 
//!       wait mode.
//!
//! \return None.
//
//*****************************************************************************
void SPIWaitForSync(unsigned long ulBase)
{
	unsigned char ulStatus = 0;
	xASSERT((ulBase == xSPI0_BASE) ||
            (ulBase == xSPI1_BASE) ||
            (ulBase == xSPI2_BASE) ||
			(ulBase == xSPI3_BASE) ||
			(ulBase == xSPI4_BASE) ||
			(ulBase == xSPI5_BASE));
	while(ulStatus == 1)
	{
		ulStatus = xHWREG(ulBase+ SERCOM_SPI_STATUS_OFFSET) & ((unsigned char)SERCOM_SPI_STATUS_SYNCBUSY);
	} 
}
