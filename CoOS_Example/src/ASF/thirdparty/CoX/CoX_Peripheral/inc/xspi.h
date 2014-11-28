//*****************************************************************************
//
//! \file xspi.h
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
//! THE POSPIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#ifndef __xSPI_H__
#define __xSPI_H__

#include "xhw_types.h"
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
//! \addtogroup SPI
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xSPI
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xSPI_Ints xSPI Interrupts
//! \brief Values that show xSPI interrupts
//! \n
//! \section xSPI_Ints_Section 1. Where to use this group
//! Values that can be passed to SPIIntEnable, SPIIntDisable, and SPIIntClear
//! as the ulIntFlags parameter, and returned from SPIIntStatus. 
//! \n
//! \section xSPI_Ints_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xSPI Interrupts         |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xSPI_INT_EOT            |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_INT_TX             |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xSPI_INT_RX             |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xSPI_INT_ERROR          |  Non-Mandatory |            N           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! End of transfer
//
#define xSPI_INT_EOT            SERCOM_SPI_INTENSET_TXC

#define xSPI_INT_RXC			SERCOM_SPI_INTENSET_RXC

#define xSPI_INT_DRE			SERCOM_SPI_INTENSET_DRE

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xSPI_Ints_Event xSPI Interrupt Event
//! \brief Values that show xSPI interrupt events.
//! \n
//! \section xSPI_Ints_Event_Section 1. Where to use this group
//! Values that can be passed to SPIIntEnable, SPIIntDisable, and SPIIntClear
//! as the ulIntFlags parameter, and returned from SPIIntStatus. 
//! \n
//! \section xSPI_Ints_Event_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xSPI Interrupts         |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xSPI_EVENT_EOT          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_EVENT_TX           |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xSPI_EVENT_RX           |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xSPI_EVENT_ERROR        |  Non-Mandatory |            N           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! End of transfer
//
#define xSPI_EVENT_EOT          0

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xSPI_Config xSPI Configure
//! \brief Values that show xSPI Configure
//! \n
//! \section xSPI_Config_Section 1. Where to use this group
//! Values that can be passed to xSPIConfig()
//! as the ulConfig parameter. 
//! \n
//! \section xSPI_Config_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xSPI Configs            |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xSPI_MOTO_FORMAT_MODE_0 |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_MOTO_FORMAT_MODE_1 |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_MOTO_FORMAT_MODE_2 |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_MOTO_FORMAT_MODE_3 |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_TI_FORMAT_MODE     |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xSPI_NMW_FORMAT_MODE    |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |                        |                |                        |
//! |------------------------|----------------|------------------------|
//! |xSPI_MODE_MASTER        |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_MODE_SLAVE         |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |                        |                |                        |
//! |------------------------|----------------|------------------------|
//! |xSPI_MSB_FIRST          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_LSB_FIRST          |  Non-Mandatory |            Y           |
//! |------------------------|----------------|------------------------|
//! |                        |                |                        |
//! |------------------------|----------------|------------------------|
//! |xSPI_DATA_WIDTHn        |  Non-Mandatory |    xSPI_DATA_WIDTH1    |
//! |                        |                |------------------------|
//! |                        |                |    xSPI_DATA_WIDTH2    |
//! |                        |                |------------------------|
//! |                        |                |    xSPI_DATA_WIDTH3    |
//! |                        |                |------------------------|
//! |                        |                |           ...          |
//! |                        |                |------------------------|
//! |                        |                |    xSPI_DATA_WIDTH32   |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! Moto Format, polarity 0, phase 0
//
#define xSPI_MOTO_FORMAT_MODE_0 SERCOM_SPI_MODE_0

//
//! Moto Format, polarity 0, phase 1
//  
#define xSPI_MOTO_FORMAT_MODE_1 SERCOM_SPI_MODE_1  
                                             
//
//! Moto Format, polarity 1, phase 0
//  
#define xSPI_MOTO_FORMAT_MODE_2 SERCOM_SPI_MODE_2  
                                           
//
//! Moto Format, polarity 1, phase 1
//
#define xSPI_MOTO_FORMAT_MODE_3 SERCOM_SPI_MODE_3
                                            
//
//!  TI frame format
//                                            
#define xSPI_TI_FORMAT_MODE     0		//not defined
  
//
//! National MicroWire frame format
//
#define xSPI_NMW_FORMAT_MODE    0		//not defined

#define xSPI_MODE_MASTER        SERCOM_SPI_MASTER  		
#define xSPI_MODE_SLAVE         SERCOM_SPI_SLAVE  

#define xSPI_MSB_FIRST          SERCOM_SPI_DORD_0 
#define xSPI_LSB_FIRST          SERCOM_SPI_DORD_1  



//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xSPI_DMA xSPI DMA
//! \brief Values that show xSPI DMA
//! \n
//! \section xSPI_DMA_Section 1. Where to use this group
//! Values that can be passed to xSPIDMAEnable() and xSPIDMADisable()
//! as the ulDmaMode parameter. 
//! \n
//! \section xSPI_DMA_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xSPI DMA                |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xSPI_DMA_TX             |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |SPI_DMA_RX              |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |SPI_DMA_BOTH            |  Non-Mandatory |            Y           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! Enable DMA for transmit
//
#define xSPI_DMA_TX             0
  
//
//! Enable DMA for receive
//
#define xSPI_DMA_RX             0
  
//
//! Enable DMA for transfer and receive
//
#define xSPI_DMA_BOTH           0  

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xSPI_SlaveSelMode xSPI Slave Select Mode
//! \brief Values show xSPI Slave Select Mode
//! \n
//! \section xSPI_SlaveSelMode_Section 1. Where to use this group
//! Values that can be passed to xSPISSSet()
//! as the ulSSMode parameter. 
//! \n
//! \section xSPI_SlaveSelMode_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xSPI Slave Select Mode  |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xSPI_SS_HARDWARE        |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_SS_SOFTWARE        |    Mandatory   |            Y           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

#define xSPI_SS_HARDWARE        0  
#define xSPI_SS_SOFTWARE        0  

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xSPI_SlaveSel xSPI Slave Select
//! \brief Values that show xSPI Slave Select
//! \n
//! \section xSPI_SlaveSel_Section 1. Where to use this group
//! Values that can be passed to xSPISSSet()
//! as the ulSlaveSel parameter. 
//! \n
//! \section xSPI_SlaveSel_CoX 2. CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xSPI Slave Select       |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xSPI_SS_NONE            |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPI_SSn                |    Mandatory   |        xSPI_SS0        |
//! |                        |                |------------------------|
//! |                        |                |        xSPI_SS1        |
//! |                        |                |------------------------|
//! |                        |                |        xSPI_SS01       |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

#define xSPI_SS_NONE            0   
#define xSPI_SS0                0  
#define xSPI_SS1                0 
#define xSPI_SS01               0

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xSPI_Exported_APIs xSPI API
//! \brief xSPI API Reference.
//!
//! \section xSPI_Exported_APIs_Port CoX Port Details
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xSPI API                |       CoX      |         NUC1xx         |
//! |------------------------|----------------|------------------------|
//! |xSPIConfigSet           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPISingleDataReadWrite |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIBitLengthGet        |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIDataRead            |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIDataWrite           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIIntEnable           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIIntCallbackInit     |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIIntDisable          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIStatusGet           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIIsBusy              |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIIsRxEmpty           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIIsTxEmpty           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIIsRxFull            |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIIsTxFull            |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIDMAEnable           |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIDMADisable          |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIEnable              |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPIDisable             |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xSPISSSet               |    Mandatory   |            Y           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************


//*****************************************************************************
//
//! \brief Configures the synchronous serial interface.
//!
//! \param ulBase specifies the SPI module base address.
//! \param ulBitRate specifies the clock rate.
//! \param ulConfig is the required configuration of the SPI.
//! Details please refer to \ref xSPI_Config.
//!
//! This function configures the synchronous serial interface.  It sets
//! the SPI protocol, mode of operation, bit rate, and data width and the first
//! bit.
//!
//! The \e ulConfig parameter is the logical OR of several different values,
//! many of which are grouped into sets where only one can be chosen.
//!
//! The Protocol of SPI can be one of the following values:
//! \b xSPI_MOTO_FORMAT_MODE_0, \b xSPI_MOTO_FORMAT_MODE_1,
//! \b xSPI_MOTO_FORMAT_MODE_2, \b xSPI_MOTO_FORMAT_MODE_3. 
//! The Motorola frame formats imply the following polarity and phase 
//! configurations:
//!
//! <pre>
//! Polarity Phase       Mode
//!   0       0   xSPI_MOTO_FORMAT_MODE_0
//!   0       1   xSPI_MOTO_FORMAT_MODE_1
//!   1       0   xSPI_MOTO_FORMAT_MODE_2
//!   1       1   xSPI_MOTO_FORMAT_MODE_3
//! </pre>
//!  
//! The SPI module can operate as a master or slave;  The Mode of SPI
//! can be one of the following values: \b xSPI_MODE_MASTER, or
//! \b xSPI_MODE_SLAVE.
//!
//! The \e ulBitRate parameter defines the bit rate for the SPI.  This bit rate
//! must satisfy the following clock ratio criteria:
//!
//! - 0 !=  bit rate (master mode)
//!
//! The first bit of the data transfers, can be one of the following values:
//! \b xSPI_MSB_FIRST, or \b xSPI_LSB_FIRST.
//! Details please refer to \ref xSPI_Config_CoX.
//!
//! \return None.
//
//*****************************************************************************

#define xSPIConfigSet(ulBase, ulBitRate, ulConfig)	SPIConfigSet(ulBase, ulBitRate, ulConfig)

//extern void xSPIConfigSet(unsigned long ulBase, unsigned long ulBitRate, unsigned long ulConfig);

//*****************************************************************************
//
//! \brief Read  and write a data element from and to the SPI interface.
//!
//! \param ulBase specifies the SPI module base address.
//! \param ulWData is the data that was transmitted over the SPI interface.
//!
//! This function send transmitted data to the SPI interface of the specified
//! SPI module and gets received data from the SPI interface of the specified
//! SPI module and return that data.
//!
//! \note Only the lower N bits of the value written to \e pulData contain
//! valid data, where N is the data width as configured by
//! SPIConfig().  For example, if the interface is configured for
//! 8-bit data width, only the lower 8 bits of the value written to \e pulData
//! contain valid data.
//!
//! \return the data that was received over the SPI interface.
//
//*****************************************************************************

#define xSPISingleDataReadWrite(ulBase, ulWData)	SPISingleDataReadWrite(ulBase,ulWData)

//extern unsigned long xSPISingleDataReadWrite(unsigned long ulBase, unsigned long ulWData);

//*****************************************************************************
//
//! \brief Gets the number of bits transferred per frame.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function gets the number of bits transferred per frame.
//!
//! \note if return 0 that means number of bits is 32.
//!
//! \return the number of bits transferred per frame.
//
//*****************************************************************************
#define xSPIBitLengthGet(ulBase)	0
//extern unsigned long xSPIBitLengthGet(unsigned long ulBase);

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
//! \note Only the lower N bits of the value written to \e pulData contain
//! valid data, where N is the data width as configured by
//! SPIConfigSetExpClk().  For example, if the interface is configured for
//! 8-bit data width, only the lower 8 bits of the value written to \e pulData
//! contain valid data.
//!
//! \return None.
//
//*****************************************************************************        
#define xSPIDataRead(ulBase, pulRData, ulLen)	SPIDataRead(ulBase, pulRData, ulLen)

//*****************************************************************************
//
//! \brief Write  datas element to the SPI interface.
//!
//! \param ulBase specifies the SPI module base address.
//! \param pulWData is a pointer to a storage location for data that was
//! transmitted over the SPI interface.
//! \param ulLen specifies the length of data will be write.
//!
//! This function transmitted data to the interface of the specified
//! SPI module .
//!
//! \note Only the lower N bits of the value written to \e pulData contain
//! valid data, where N is the data width as configured by
//! SPIConfigSetExpClk().  For example, if the interface is configured for
//! 8-bit data width, only the lower 8 bits of the value written to \e pulData
//! contain valid data.
//!
//! \return None.
//
//*****************************************************************************        
#define xSPIDataWrite(ulBase, pulWData, ulLen)  SPIDataWrite(ulBase, pulWData, ulLen)
//*****************************************************************************
//
//! \brief Enable the SPI interrupt of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//! \param ulIntFlags specifies the type of SPI interrupt.
//! Details please refer to \ref xSPI_Ints.
//!
//! This function is to enable the SPI interrupt of the specified SPI port.
//!
//! \return None.
//
//*****************************************************************************        
#define xSPIIntEnable(ulBase, ulIntFlags)
//*****************************************************************************
//
//! \brief Init interrupts callback for the specified SPI Port.
//!
//! \param ulPort is the base address of the SPI port.
//! \param xtI2CCallback is callback for the specified SPI Port.
//!
//! Init interrupts callback for the specified SPI Port.
//!
//! \return None.
//
//*****************************************************************************
#define xSPIIntCallbackInit(ulBase, pfnCallback)

//*****************************************************************************
//
//! \brief Disable the SPI interrupt of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function is to disable the SPI interrupt of the specified SPI port 
//!
//! \return None.
//
//*****************************************************************************        
#define xSPIIntDisable(ulBase, ulIntFlags)
//*****************************************************************************
//
//! \brief Get the SPI interrupt flag of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//! \param xbMasked is \b false if the raw interrupt status is required or
//! \b true if the masked interrupt status is required.
//!
//! This function returns the interrupt status for the SPI module.  Either the
//! raw interrupt status or the status of interrupts that are allowed to
//! reflect to the processor can be returned. 
//!
//! \return the SPI interrupt flag.It can be the following values:
//! \b .
//
//*****************************************************************************        
#define xSPIStatusGet(ulBase, xbMasked)   SPIIntStatus(ulBase, xbMasked) 
//*****************************************************************************
//
//! \brief Check the busy status of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function Check the busy status of the specified SPI module.
//!
//! \return Returns the busy status of the specified SPI port.
//! \b xtrue The SPI port is in busy,or \b xfalse The SPI port is not in busy.
//
//*****************************************************************************        
#define xSPIIsBusy(ulBase)   0
//*****************************************************************************
//
//! \brief Check the status of the Rx buffer of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function Check the Rx buffer status of the specified SPI module.
//!
//! \note Only the chips with the part number NUC1x0xxxCx, ex: NUC140VE3CN, 
//! can support this function..
//!
//! \return Returns the Rx buffer status of the specified SPI port.
//! \b xtrue The Rx buffer is empty,or \b xfalse The Rx buffer is not empty.
//
//*****************************************************************************        

#define xSPIIsDataEmpty(ulBase)	SPIIsDataEmpty(ulBase)
//extern xtBoolean xSPIIsDataEmpty(unsigned long ulBase); 

//*****************************************************************************
//
//! \brief Check the status of the Tx buffer of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function Check the Tx buffer status of the specified SPI module.
//!
//! \note Only the chips with the part number NUC1x0xxxCx, ex: NUC140VE3CN, 
//! can support this function..
//!
//! \return Returns the Tx buffer status of the specified SPI port.
//! \b xtrue The Tx buffer is in empty,or \b xfalse The Tx buffer is not empty.
//
//*****************************************************************************        
//extern xtBoolean xSPIIsTxEmpty(unsigned long ulBase);

//*****************************************************************************
//
//! \brief Check the status of the Rx buffer of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function Check the Rx buffer status of the specified SPI module.
//!
//! \note Only the chips with the part number NUC1x0xxxCx, ex: NUC140VE3CN, 
//! can support this function..
//!
//! \return Returns the Rx buffer status of the specified SPI port.
//! \b xtrue The Rx buffer is full,or \b xfalse The Rx buffer is not full.
//
//*****************************************************************************        
#define xSPIIsRxFull(ulBase)	0

//*****************************************************************************
//
//! \brief Check the status of the Tx buffer of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function Check the Tx buffer status of the specified SPI module.
//!
//! \note Only the chips with the part number NUC1x0xxxCx, ex: NUC140VE3CN, 
//! can support this function..
//!
//! \return Returns the Tx buffer status of the specified SPI port.
//! \b xtrue The Tx buffer is in full,or \b xfalse The Tx buffer is not full.
//
//*****************************************************************************        
#define xSPIIsTxFull(ulBase)	0   

//*****************************************************************************
//
//! \brief Enable the DMA of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//! \param ulDmaMode specifies the SPI module base address.
//! Details please refer to \ref xSPI_DMA.
//!
//! This function enable the DMA of the specified SPI port.
//!
//! The \e ulDmaMode parameter can be one of the following values:
//! \b xSPI_DMA_RX, \b xSPI_DMA_TX ,or \b xSPI_DMA_BOTH.
//! Details please refer to \ref xSPI_DMA_CoX.
//!
//! \return None.
//
//*****************************************************************************        
#define xSPIDMAEnable(ulBase, ulDmaMode)	0

//*****************************************************************************
//
//! \brief Disable the DMA of the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//! \param ulDmaMode specifies the SPI module base address.
//! Details please refer to \ref xSPI_DMA.
//!
//! This function disable the DMA of the specified SPI port.
//!
//! The \e ulDmaMode parameter can be one of the following values:
//! \b SPI_DMA_RX, \b SPI_DMA_TX ,or \b SPI_DMA_BOTH.
//! Details please refer to \ref xSPI_DMA_CoX.
//!
//! \return None.
//
//*****************************************************************************        
#define xSPIDMADisable(ulBase, ulDmaMode)	0
//*****************************************************************************
//
//! \brief Enable the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function enable the specified SPI port.
//!
//! \note do nothing for NUC1xx.
//!
//! \return None.
//
//*****************************************************************************         
#define xSPIEnable(ulBase)   SPIEnable(ulBase)

//*****************************************************************************
//
//! \brief Disable the specified SPI port.
//!
//! \param ulBase specifies the SPI module base address.
//!
//! This function disable the specified SPI port.
//!
//! \note do nothing for NUC1xx.
//!
//! \return None.
//
//*****************************************************************************
#define xSPIDisable(ulBase)   SPIDisable(ulBase)


//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

#define SERCOM_SPI_MODE_MASK	0x30000000UL

#define SERCOM_SPI_MODE_0		0x00000000UL

#define SERCOM_SPI_MODE_1		0x10000000UL

#define SERCOM_SPI_MODE_2		0x20000000UL

#define SERCOM_SPI_MODE_3		0x30000000UL

#define SERCOM_OP_MODE_MASK		0x0000001CUL

#define SERCOM_SPI_MASTER		0x0000000CUL

#define SERCOM_SPI_SLAVE		0x00000008UL

#define SERCOM_SPI_DORD_MASK	0x40000000UL

#define SERCOM_SPI_DORD_0		0x00000000UL

#define SERCOM_SPI_DORD_1		0x40000000UL

#define SERCOM_SPI_DI_PIN_0		0x00000000UL

#define SERCOM_SPI_DI_PIN_1		0x00100000UL

#define SERCOM_SPI_DI_PIN_2		0x00200000UL

#define SERCOM_SPI_DI_PIN_3		0x00300000UL

#define SERCOM_SPI_DO_PINCFG_0		0x00000000UL

#define SERCOM_SPI_DO_PINCFG_1		0x00010000UL

#define SERCOM_SPI_DO_PINCFG_2		0x00020000UL

#define SERCOM_SPI_DO_PINCFG_3		0x00030000UL

#define GCLK_BASE						0x40000C00UL

#define SPI0_CORE_CLOCK					0x400DUL

#define SPI1_CORE_CLOCK					0x400EUL

#define SPI2_CORE_CLOCK					0x400FUL

#define SPI3_CORE_CLOCK					0x4010UL

#define SPI4_CORE_CLOCK					0x4011UL

#define SPI5_CORE_CLOCK					0x4012UL

#define PM_BASE								0x40000400UL

#define SPI0_BUS_CLOCK						0x00000004UL

#define SPI1_BUS_CLOCK						0x00000008UL

#define SPI2_BUS_CLOCK						0x00000010UL

#define SPI3_BUS_CLOCK						0x00000020UL

#define SPI4_BUS_CLOCK						0x00000040UL

#define SPI5_BUS_CLOCK						0x00000080UL


void SPIConfigSet(unsigned long ulBase, unsigned long ulBitRate, unsigned long ulConfig);

unsigned long SPISingleDataReadWrite (unsigned long ulBase, unsigned char ulWData);	

xtBoolean SPISingleDataWriteNonblocking (unsigned long ulBase, unsigned char ulWData);

void SPIDisable(unsigned long ulBase);

void SPIEnable(unsigned long ulBase);

unsigned long SPIIntStatus(unsigned long ulBase, xtBoolean bMasked);

xtBoolean SPIBusy(unsigned long ulBase);

void SPIDataRead(unsigned long ulBase, unsigned long *pulRData, unsigned long ulLen);

void SPIDataWrite(unsigned long ulBase, const unsigned long *pulWData, unsigned long ulLen);

//SAM D20 specific API's

void SPIOutputPinSel(unsigned long ulBase, unsigned long ulOutputPin);

void SPIInputPinSel(unsigned long ulBase, unsigned long ulInputPin);

void SPIClockEnable(unsigned long ulBase);

void SPIRxEnable(unsigned long ulBase);

void SPIWaitForSync(unsigned long ulBase);


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __xSPI_H__


