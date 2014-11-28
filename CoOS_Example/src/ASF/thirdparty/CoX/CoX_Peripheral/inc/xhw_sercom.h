//*****************************************************************************
//
//! \file xhw_spi.h
//! \brief Macros used when accessing the SPI hardware.
//! \version V2.2.1.0
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

#ifndef __xHW_SPI_H__
#define __xHW_SPI_H__

/* -------- SERCOM_I2CM_CTRLA : (SERCOM Offset: 0x00) (R/W 32) I2CM I2CM Control A -------- */
#define SERCOM_I2CM_CTRLA_OFFSET    0x00         /**< \brief (SERCOM_I2CM_CTRLA offset) I2CM Control A */
#define SERCOM_I2CM_CTRLA_RESETVALUE 0x00000000   /**< \brief (SERCOM_I2CM_CTRLA reset_value) I2CM Control A */

#define SERCOM_I2CM_CTRLA_SWRST_Pos 0            /**< \brief (SERCOM_I2CM_CTRLA) Software Reset */
#define SERCOM_I2CM_CTRLA_SWRST     (0x1u << SERCOM_I2CM_CTRLA_SWRST_Pos)
#define SERCOM_I2CM_CTRLA_ENABLE_Pos 1            /**< \brief (SERCOM_I2CM_CTRLA) Enable */
#define SERCOM_I2CM_CTRLA_ENABLE    (0x1u << SERCOM_I2CM_CTRLA_ENABLE_Pos)
#define SERCOM_I2CM_CTRLA_MODE_Pos  2            /**< \brief (SERCOM_I2CM_CTRLA) Operating Mode */
#define SERCOM_I2CM_CTRLA_MODE_Msk  (0x7u << SERCOM_I2CM_CTRLA_MODE_Pos)
#define SERCOM_I2CM_CTRLA_MODE(value) ((SERCOM_I2CM_CTRLA_MODE_Msk & ((value) << SERCOM_I2CM_CTRLA_MODE_Pos)))
#define   SERCOM_I2CM_CTRLA_MODE_USART_EXT_CLK_Val 0x0u   /**< \brief (SERCOM_I2CM_CTRLA) USART mode with external clock */
#define   SERCOM_I2CM_CTRLA_MODE_USART_INT_CLK_Val 0x1u   /**< \brief (SERCOM_I2CM_CTRLA) USART mode with internal clock */
#define   SERCOM_I2CM_CTRLA_MODE_SPI_SLAVE_Val 0x2u   /**< \brief (SERCOM_I2CM_CTRLA) SPI mode with external clock */
#define   SERCOM_I2CM_CTRLA_MODE_SPI_MASTER_Val 0x3u   /**< \brief (SERCOM_I2CM_CTRLA) SPI mode with internal clock */
#define   SERCOM_I2CM_CTRLA_MODE_I2C_SLAVE_Val 0x4u   /**< \brief (SERCOM_I2CM_CTRLA) I2C mode with external clock */
#define   SERCOM_I2CM_CTRLA_MODE_I2C_MASTER_Val 0x5u   /**< \brief (SERCOM_I2CM_CTRLA) I2C mode with internal clock */
#define SERCOM_I2CM_CTRLA_MODE_USART_EXT_CLK (SERCOM_I2CM_CTRLA_MODE_USART_EXT_CLK_Val << SERCOM_I2CM_CTRLA_MODE_Pos)
#define SERCOM_I2CM_CTRLA_MODE_USART_INT_CLK (SERCOM_I2CM_CTRLA_MODE_USART_INT_CLK_Val << SERCOM_I2CM_CTRLA_MODE_Pos)
#define SERCOM_I2CM_CTRLA_MODE_SPI_SLAVE (SERCOM_I2CM_CTRLA_MODE_SPI_SLAVE_Val << SERCOM_I2CM_CTRLA_MODE_Pos)
#define SERCOM_I2CM_CTRLA_MODE_SPI_MASTER (SERCOM_I2CM_CTRLA_MODE_SPI_MASTER_Val << SERCOM_I2CM_CTRLA_MODE_Pos)
#define SERCOM_I2CM_CTRLA_MODE_I2C_SLAVE (SERCOM_I2CM_CTRLA_MODE_I2C_SLAVE_Val << SERCOM_I2CM_CTRLA_MODE_Pos)
#define SERCOM_I2CM_CTRLA_MODE_I2C_MASTER (SERCOM_I2CM_CTRLA_MODE_I2C_MASTER_Val << SERCOM_I2CM_CTRLA_MODE_Pos)
#define SERCOM_I2CM_CTRLA_RUNSTDBY_Pos 7            /**< \brief (SERCOM_I2CM_CTRLA) Run during Standby */
#define SERCOM_I2CM_CTRLA_RUNSTDBY  (0x1u << SERCOM_I2CM_CTRLA_RUNSTDBY_Pos)
#define SERCOM_I2CM_CTRLA_PINOUT_Pos 16           /**< \brief (SERCOM_I2CM_CTRLA) Pin Usage */
#define SERCOM_I2CM_CTRLA_PINOUT    (0x1u << SERCOM_I2CM_CTRLA_PINOUT_Pos)
#define SERCOM_I2CM_CTRLA_SDAHOLD_Pos 20           /**< \brief (SERCOM_I2CM_CTRLA) SDA Hold Time */
#define SERCOM_I2CM_CTRLA_SDAHOLD_Msk (0x3u << SERCOM_I2CM_CTRLA_SDAHOLD_Pos)
#define SERCOM_I2CM_CTRLA_SDAHOLD(value) ((SERCOM_I2CM_CTRLA_SDAHOLD_Msk & ((value) << SERCOM_I2CM_CTRLA_SDAHOLD_Pos)))
#define SERCOM_I2CM_CTRLA_INACTOUT_Pos 28           /**< \brief (SERCOM_I2CM_CTRLA) Inactive Bus Timeout */
#define SERCOM_I2CM_CTRLA_INACTOUT_Msk (0x3u << SERCOM_I2CM_CTRLA_INACTOUT_Pos)
#define SERCOM_I2CM_CTRLA_INACTOUT(value) ((SERCOM_I2CM_CTRLA_INACTOUT_Msk & ((value) << SERCOM_I2CM_CTRLA_INACTOUT_Pos)))
#define SERCOM_I2CM_CTRLA_LOWTOUT_Pos 30           /**< \brief (SERCOM_I2CM_CTRLA) SCL Low Timeout */
#define SERCOM_I2CM_CTRLA_LOWTOUT   (0x1u << SERCOM_I2CM_CTRLA_LOWTOUT_Pos)
#define SERCOM_I2CM_CTRLA_MASK      0x7031009Fu  /**< \brief (SERCOM_I2CM_CTRLA) MASK Register */

/* -------- SERCOM_I2CS_CTRLA : (SERCOM Offset: 0x00) (R/W 32) I2CS I2CS Control A -------- */

#define SERCOM_I2CS_CTRLA_OFFSET    0x00         /**< \brief (SERCOM_I2CS_CTRLA offset) I2CS Control A */
#define SERCOM_I2CS_CTRLA_RESETVALUE 0x00000000   /**< \brief (SERCOM_I2CS_CTRLA reset_value) I2CS Control A */

#define SERCOM_I2CS_CTRLA_SWRST_Pos 0            /**< \brief (SERCOM_I2CS_CTRLA) Software Reset */
#define SERCOM_I2CS_CTRLA_SWRST     (0x1u << SERCOM_I2CS_CTRLA_SWRST_Pos)
#define SERCOM_I2CS_CTRLA_ENABLE_Pos 1            /**< \brief (SERCOM_I2CS_CTRLA) Enable */
#define SERCOM_I2CS_CTRLA_ENABLE    (0x1u << SERCOM_I2CS_CTRLA_ENABLE_Pos)
#define SERCOM_I2CS_CTRLA_MODE_Pos  2            /**< \brief (SERCOM_I2CS_CTRLA) Operating Mode */
#define SERCOM_I2CS_CTRLA_MODE_Msk  (0x7u << SERCOM_I2CS_CTRLA_MODE_Pos)
#define SERCOM_I2CS_CTRLA_MODE(value) ((SERCOM_I2CS_CTRLA_MODE_Msk & ((value) << SERCOM_I2CS_CTRLA_MODE_Pos)))
#define   SERCOM_I2CS_CTRLA_MODE_USART_EXT_CLK_Val 0x0u   /**< \brief (SERCOM_I2CS_CTRLA) USART mode with external clock */
#define   SERCOM_I2CS_CTRLA_MODE_USART_INT_CLK_Val 0x1u   /**< \brief (SERCOM_I2CS_CTRLA) USART mode with internal clock */
#define   SERCOM_I2CS_CTRLA_MODE_SPI_SLAVE_Val 0x2u   /**< \brief (SERCOM_I2CS_CTRLA) SPI mode with external clock */
#define   SERCOM_I2CS_CTRLA_MODE_SPI_MASTER_Val 0x3u   /**< \brief (SERCOM_I2CS_CTRLA) SPI mode with internal clock */
#define   SERCOM_I2CS_CTRLA_MODE_I2C_SLAVE_Val 0x4u   /**< \brief (SERCOM_I2CS_CTRLA) I2C mode with external clock */
#define   SERCOM_I2CS_CTRLA_MODE_I2C_MASTER_Val 0x5u   /**< \brief (SERCOM_I2CS_CTRLA) I2C mode with internal clock */
#define SERCOM_I2CS_CTRLA_MODE_USART_EXT_CLK (SERCOM_I2CS_CTRLA_MODE_USART_EXT_CLK_Val << SERCOM_I2CS_CTRLA_MODE_Pos)
#define SERCOM_I2CS_CTRLA_MODE_USART_INT_CLK (SERCOM_I2CS_CTRLA_MODE_USART_INT_CLK_Val << SERCOM_I2CS_CTRLA_MODE_Pos)
#define SERCOM_I2CS_CTRLA_MODE_SPI_SLAVE (SERCOM_I2CS_CTRLA_MODE_SPI_SLAVE_Val << SERCOM_I2CS_CTRLA_MODE_Pos)
#define SERCOM_I2CS_CTRLA_MODE_SPI_MASTER (SERCOM_I2CS_CTRLA_MODE_SPI_MASTER_Val << SERCOM_I2CS_CTRLA_MODE_Pos)
#define SERCOM_I2CS_CTRLA_MODE_I2C_SLAVE (SERCOM_I2CS_CTRLA_MODE_I2C_SLAVE_Val << SERCOM_I2CS_CTRLA_MODE_Pos)
#define SERCOM_I2CS_CTRLA_MODE_I2C_MASTER (SERCOM_I2CS_CTRLA_MODE_I2C_MASTER_Val << SERCOM_I2CS_CTRLA_MODE_Pos)
#define SERCOM_I2CS_CTRLA_RUNSTDBY_Pos 7            /**< \brief (SERCOM_I2CS_CTRLA) Run during Standby */
#define SERCOM_I2CS_CTRLA_RUNSTDBY  (0x1u << SERCOM_I2CS_CTRLA_RUNSTDBY_Pos)
#define SERCOM_I2CS_CTRLA_PINOUT_Pos 16           /**< \brief (SERCOM_I2CS_CTRLA) Pin Usage */
#define SERCOM_I2CS_CTRLA_PINOUT    (0x1u << SERCOM_I2CS_CTRLA_PINOUT_Pos)
#define SERCOM_I2CS_CTRLA_SDAHOLD_Pos 20           /**< \brief (SERCOM_I2CS_CTRLA) SDA Hold Time */
#define SERCOM_I2CS_CTRLA_SDAHOLD_Msk (0x3u << SERCOM_I2CS_CTRLA_SDAHOLD_Pos)
#define SERCOM_I2CS_CTRLA_SDAHOLD(value) ((SERCOM_I2CS_CTRLA_SDAHOLD_Msk & ((value) << SERCOM_I2CS_CTRLA_SDAHOLD_Pos)))
#define SERCOM_I2CS_CTRLA_LOWTOUT_Pos 30           /**< \brief (SERCOM_I2CS_CTRLA) SCL Low Timeout */
#define SERCOM_I2CS_CTRLA_LOWTOUT   (0x1u << SERCOM_I2CS_CTRLA_LOWTOUT_Pos)
#define SERCOM_I2CS_CTRLA_MASK      0x4031009Fu  /**< \brief (SERCOM_I2CS_CTRLA) MASK Register */

/* -------- SERCOM_SPI_CTRLA : (SERCOM Offset: 0x00) (R/W 32) SPI SPI Control A -------- */

#define SERCOM_SPI_CTRLA_OFFSET     0x00         /**< \brief (SERCOM_SPI_CTRLA offset) SPI Control A */
#define SERCOM_SPI_CTRLA_RESETVALUE 0x00000000   /**< \brief (SERCOM_SPI_CTRLA reset_value) SPI Control A */

#define SERCOM_SPI_CTRLA_SWRST_Pos  0            /**< \brief (SERCOM_SPI_CTRLA) Software Reset */
#define SERCOM_SPI_CTRLA_SWRST      (0x1u << SERCOM_SPI_CTRLA_SWRST_Pos)
#define SERCOM_SPI_CTRLA_ENABLE_Pos 1            /**< \brief (SERCOM_SPI_CTRLA) Enable */
#define SERCOM_SPI_CTRLA_ENABLE     (0x1u << SERCOM_SPI_CTRLA_ENABLE_Pos)
#define SERCOM_SPI_CTRLA_MODE_Pos   2            /**< \brief (SERCOM_SPI_CTRLA) Operating Mode */
#define SERCOM_SPI_CTRLA_MODE_Msk   (0x7u << SERCOM_SPI_CTRLA_MODE_Pos)
#define SERCOM_SPI_CTRLA_MODE(value) ((SERCOM_SPI_CTRLA_MODE_Msk & ((value) << SERCOM_SPI_CTRLA_MODE_Pos)))
#define   SERCOM_SPI_CTRLA_MODE_USART_EXT_CLK_Val 0x0u   /**< \brief (SERCOM_SPI_CTRLA) USART mode with external clock */
#define   SERCOM_SPI_CTRLA_MODE_USART_INT_CLK_Val 0x1u   /**< \brief (SERCOM_SPI_CTRLA) USART mode with internal clock */
#define   SERCOM_SPI_CTRLA_MODE_SPI_SLAVE_Val 0x2u   /**< \brief (SERCOM_SPI_CTRLA) SPI mode with external clock */
#define   SERCOM_SPI_CTRLA_MODE_SPI_MASTER_Val 0x3u   /**< \brief (SERCOM_SPI_CTRLA) SPI mode with internal clock */
#define   SERCOM_SPI_CTRLA_MODE_I2C_SLAVE_Val 0x4u   /**< \brief (SERCOM_SPI_CTRLA) I2C mode with external clock */
#define   SERCOM_SPI_CTRLA_MODE_I2C_MASTER_Val 0x5u   /**< \brief (SERCOM_SPI_CTRLA) I2C mode with internal clock */
#define SERCOM_SPI_CTRLA_MODE_USART_EXT_CLK (SERCOM_SPI_CTRLA_MODE_USART_EXT_CLK_Val << SERCOM_SPI_CTRLA_MODE_Pos)
#define SERCOM_SPI_CTRLA_MODE_USART_INT_CLK (SERCOM_SPI_CTRLA_MODE_USART_INT_CLK_Val << SERCOM_SPI_CTRLA_MODE_Pos)
#define SERCOM_SPI_CTRLA_MODE_SPI_SLAVE (SERCOM_SPI_CTRLA_MODE_SPI_SLAVE_Val << SERCOM_SPI_CTRLA_MODE_Pos)
#define SERCOM_SPI_CTRLA_MODE_SPI_MASTER (SERCOM_SPI_CTRLA_MODE_SPI_MASTER_Val << SERCOM_SPI_CTRLA_MODE_Pos)
#define SERCOM_SPI_CTRLA_MODE_I2C_SLAVE (SERCOM_SPI_CTRLA_MODE_I2C_SLAVE_Val << SERCOM_SPI_CTRLA_MODE_Pos)
#define SERCOM_SPI_CTRLA_MODE_I2C_MASTER (SERCOM_SPI_CTRLA_MODE_I2C_MASTER_Val << SERCOM_SPI_CTRLA_MODE_Pos)
#define SERCOM_SPI_CTRLA_RUNSTDBY_Pos 7            /**< \brief (SERCOM_SPI_CTRLA) Run during Standby */
#define SERCOM_SPI_CTRLA_RUNSTDBY   (0x1u << SERCOM_SPI_CTRLA_RUNSTDBY_Pos)
#define SERCOM_SPI_CTRLA_DOPO_Pos   16           /**< \brief (SERCOM_SPI_CTRLA) Data Out Pinout */
#define SERCOM_SPI_CTRLA_DOPO       (0x1u << SERCOM_SPI_CTRLA_DOPO_Pos)
#define SERCOM_SPI_CTRLA_DIPO_Pos   20           /**< \brief (SERCOM_SPI_CTRLA) Data In Pinout */
#define SERCOM_SPI_CTRLA_DIPO_Msk   (0x3u << SERCOM_SPI_CTRLA_DIPO_Pos)
#define SERCOM_SPI_CTRLA_DIPO(value) ((SERCOM_SPI_CTRLA_DIPO_Msk & ((value) << SERCOM_SPI_CTRLA_DIPO_Pos)))
#define SERCOM_SPI_CTRLA_FORM_Pos   24           /**< \brief (SERCOM_SPI_CTRLA) Frame Format */
#define SERCOM_SPI_CTRLA_FORM_Msk   (0xFu << SERCOM_SPI_CTRLA_FORM_Pos)
#define SERCOM_SPI_CTRLA_FORM(value) ((SERCOM_SPI_CTRLA_FORM_Msk & ((value) << SERCOM_SPI_CTRLA_FORM_Pos)))
#define SERCOM_SPI_CTRLA_CPHA_Pos   28           /**< \brief (SERCOM_SPI_CTRLA) Clock Phase */
#define SERCOM_SPI_CTRLA_CPHA       (0x1u << SERCOM_SPI_CTRLA_CPHA_Pos)
#define SERCOM_SPI_CTRLA_CPOL_Pos   29           /**< \brief (SERCOM_SPI_CTRLA) Clock Polarity */
#define SERCOM_SPI_CTRLA_CPOL       (0x1u << SERCOM_SPI_CTRLA_CPOL_Pos)
#define SERCOM_SPI_CTRLA_DORD_Pos   30           /**< \brief (SERCOM_SPI_CTRLA) Data Order */
#define SERCOM_SPI_CTRLA_DORD       (0x1u << SERCOM_SPI_CTRLA_DORD_Pos)
#define SERCOM_SPI_CTRLA_MASK       0x7F31009Fu  /**< \brief (SERCOM_SPI_CTRLA) MASK Register */

/* -------- SERCOM_USART_CTRLA : (SERCOM Offset: 0x00) (R/W 32) USART USART Control A -------- */

#define SERCOM_USART_CTRLA_OFFSET   0x00         /**< \brief (SERCOM_USART_CTRLA offset) USART Control A */
#define SERCOM_USART_CTRLA_RESETVALUE 0x00000000   /**< \brief (SERCOM_USART_CTRLA reset_value) USART Control A */

#define SERCOM_USART_CTRLA_SWRST_Pos 0            /**< \brief (SERCOM_USART_CTRLA) Software Reset */
#define SERCOM_USART_CTRLA_SWRST    (0x1u << SERCOM_USART_CTRLA_SWRST_Pos)
#define SERCOM_USART_CTRLA_ENABLE_Pos 1            /**< \brief (SERCOM_USART_CTRLA) Enable */
#define SERCOM_USART_CTRLA_ENABLE   (0x1u << SERCOM_USART_CTRLA_ENABLE_Pos)
#define SERCOM_USART_CTRLA_MODE_Pos 2            /**< \brief (SERCOM_USART_CTRLA) Operating Mode */
#define SERCOM_USART_CTRLA_MODE_Msk (0x7u << SERCOM_USART_CTRLA_MODE_Pos)
#define SERCOM_USART_CTRLA_MODE(value) ((SERCOM_USART_CTRLA_MODE_Msk & ((value) << SERCOM_USART_CTRLA_MODE_Pos)))
#define   SERCOM_USART_CTRLA_MODE_USART_EXT_CLK_Val 0x0u   /**< \brief (SERCOM_USART_CTRLA) USART mode with external clock */
#define   SERCOM_USART_CTRLA_MODE_USART_INT_CLK_Val 0x1u   /**< \brief (SERCOM_USART_CTRLA) USART mode with internal clock */
#define   SERCOM_USART_CTRLA_MODE_SPI_SLAVE_Val 0x2u   /**< \brief (SERCOM_USART_CTRLA) SPI mode with external clock */
#define   SERCOM_USART_CTRLA_MODE_SPI_MASTER_Val 0x3u   /**< \brief (SERCOM_USART_CTRLA) SPI mode with internal clock */
#define   SERCOM_USART_CTRLA_MODE_I2C_SLAVE_Val 0x4u   /**< \brief (SERCOM_USART_CTRLA) I2C mode with external clock */
#define   SERCOM_USART_CTRLA_MODE_I2C_MASTER_Val 0x5u   /**< \brief (SERCOM_USART_CTRLA) I2C mode with internal clock */
#define SERCOM_USART_CTRLA_MODE_USART_EXT_CLK (SERCOM_USART_CTRLA_MODE_USART_EXT_CLK_Val << SERCOM_USART_CTRLA_MODE_Pos)
#define SERCOM_USART_CTRLA_MODE_USART_INT_CLK (SERCOM_USART_CTRLA_MODE_USART_INT_CLK_Val << SERCOM_USART_CTRLA_MODE_Pos)
#define SERCOM_USART_CTRLA_MODE_SPI_SLAVE (SERCOM_USART_CTRLA_MODE_SPI_SLAVE_Val << SERCOM_USART_CTRLA_MODE_Pos)
#define SERCOM_USART_CTRLA_MODE_SPI_MASTER (SERCOM_USART_CTRLA_MODE_SPI_MASTER_Val << SERCOM_USART_CTRLA_MODE_Pos)
#define SERCOM_USART_CTRLA_MODE_I2C_SLAVE (SERCOM_USART_CTRLA_MODE_I2C_SLAVE_Val << SERCOM_USART_CTRLA_MODE_Pos)
#define SERCOM_USART_CTRLA_MODE_I2C_MASTER (SERCOM_USART_CTRLA_MODE_I2C_MASTER_Val << SERCOM_USART_CTRLA_MODE_Pos)
#define SERCOM_USART_CTRLA_RUNSTDBY_Pos 7            /**< \brief (SERCOM_USART_CTRLA) Run during Standby */
#define SERCOM_USART_CTRLA_RUNSTDBY (0x1u << SERCOM_USART_CTRLA_RUNSTDBY_Pos)
#define SERCOM_USART_CTRLA_TXPO_Pos 16           /**< \brief (SERCOM_USART_CTRLA) Transmit Data Pinout */
#define SERCOM_USART_CTRLA_TXPO     (0x1u << SERCOM_USART_CTRLA_TXPO_Pos)
#define SERCOM_USART_CTRLA_RXPO_Pos 20           /**< \brief (SERCOM_USART_CTRLA) Receive Data Pinout */
#define SERCOM_USART_CTRLA_RXPO_Msk (0x3u << SERCOM_USART_CTRLA_RXPO_Pos)
#define SERCOM_USART_CTRLA_RXPO(value) ((SERCOM_USART_CTRLA_RXPO_Msk & ((value) << SERCOM_USART_CTRLA_RXPO_Pos)))
#define SERCOM_USART_CTRLA_FORM_Pos 24           /**< \brief (SERCOM_USART_CTRLA) Frame Format */
#define SERCOM_USART_CTRLA_FORM_Msk (0xFu << SERCOM_USART_CTRLA_FORM_Pos)
#define SERCOM_USART_CTRLA_FORM(value) ((SERCOM_USART_CTRLA_FORM_Msk & ((value) << SERCOM_USART_CTRLA_FORM_Pos)))
#define SERCOM_USART_CTRLA_CMODE_Pos 28           /**< \brief (SERCOM_USART_CTRLA) Communication Mode */
#define SERCOM_USART_CTRLA_CMODE    (0x1u << SERCOM_USART_CTRLA_CMODE_Pos)
#define SERCOM_USART_CTRLA_CPOL_Pos 29           /**< \brief (SERCOM_USART_CTRLA) Clock Polarity */
#define SERCOM_USART_CTRLA_CPOL     (0x1u << SERCOM_USART_CTRLA_CPOL_Pos)
#define SERCOM_USART_CTRLA_DORD_Pos 30           /**< \brief (SERCOM_USART_CTRLA) Data Order */
#define SERCOM_USART_CTRLA_DORD     (0x1u << SERCOM_USART_CTRLA_DORD_Pos)
#define SERCOM_USART_CTRLA_MASK     0x7F31009Fu  /**< \brief (SERCOM_USART_CTRLA) MASK Register */

/* -------- SERCOM_I2CM_CTRLB : (SERCOM Offset: 0x04) (R/W 32) I2CM I2CM Control B -------- */
#define SERCOM_I2CM_CTRLB_OFFSET    0x04         /**< \brief (SERCOM_I2CM_CTRLB offset) I2CM Control B */
#define SERCOM_I2CM_CTRLB_RESETVALUE 0x00000000   /**< \brief (SERCOM_I2CM_CTRLB reset_value) I2CM Control B */

#define SERCOM_I2CM_CTRLB_SMEN_Pos  8            /**< \brief (SERCOM_I2CM_CTRLB) Smart Mode Enable */
#define SERCOM_I2CM_CTRLB_SMEN      (0x1u << SERCOM_I2CM_CTRLB_SMEN_Pos)
#define SERCOM_I2CM_CTRLB_QCEN_Pos  9            /**< \brief (SERCOM_I2CM_CTRLB) Quick Command Enable */
#define SERCOM_I2CM_CTRLB_QCEN      (0x1u << SERCOM_I2CM_CTRLB_QCEN_Pos)
#define SERCOM_I2CM_CTRLB_CMD_Pos   16           /**< \brief (SERCOM_I2CM_CTRLB) Command */
#define SERCOM_I2CM_CTRLB_CMD_Msk   (0x3u << SERCOM_I2CM_CTRLB_CMD_Pos)
#define SERCOM_I2CM_CTRLB_CMD(value) ((SERCOM_I2CM_CTRLB_CMD_Msk & ((value) << SERCOM_I2CM_CTRLB_CMD_Pos)))
#define SERCOM_I2CM_CTRLB_ACKACT_Pos 18           /**< \brief (SERCOM_I2CM_CTRLB) Acknowledge Action */
#define SERCOM_I2CM_CTRLB_ACKACT    (0x1u << SERCOM_I2CM_CTRLB_ACKACT_Pos)
#define SERCOM_I2CM_CTRLB_MASK      0x00070300u  /**< \brief (SERCOM_I2CM_CTRLB) MASK Register */

/* -------- SERCOM_I2CS_CTRLB : (SERCOM Offset: 0x04) (R/W 32) I2CS I2CS Control B -------- */

#define SERCOM_I2CS_CTRLB_OFFSET    0x04         /**< \brief (SERCOM_I2CS_CTRLB offset) I2CS Control B */
#define SERCOM_I2CS_CTRLB_RESETVALUE 0x00000000   /**< \brief (SERCOM_I2CS_CTRLB reset_value) I2CS Control B */

#define SERCOM_I2CS_CTRLB_SMEN_Pos  8            /**< \brief (SERCOM_I2CS_CTRLB) Smart Mode Enable */
#define SERCOM_I2CS_CTRLB_SMEN      (0x1u << SERCOM_I2CS_CTRLB_SMEN_Pos)
#define SERCOM_I2CS_CTRLB_AMODE_Pos 14           /**< \brief (SERCOM_I2CS_CTRLB) Address Mode */
#define SERCOM_I2CS_CTRLB_AMODE_Msk (0x3u << SERCOM_I2CS_CTRLB_AMODE_Pos)
#define SERCOM_I2CS_CTRLB_AMODE(value) ((SERCOM_I2CS_CTRLB_AMODE_Msk & ((value) << SERCOM_I2CS_CTRLB_AMODE_Pos)))
#define SERCOM_I2CS_CTRLB_CMD_Pos   16           /**< \brief (SERCOM_I2CS_CTRLB) Command */
#define SERCOM_I2CS_CTRLB_CMD_Msk   (0x3u << SERCOM_I2CS_CTRLB_CMD_Pos)
#define SERCOM_I2CS_CTRLB_CMD(value) ((SERCOM_I2CS_CTRLB_CMD_Msk & ((value) << SERCOM_I2CS_CTRLB_CMD_Pos)))
#define SERCOM_I2CS_CTRLB_ACKACT_Pos 18           /**< \brief (SERCOM_I2CS_CTRLB) Acknowledge Action */
#define SERCOM_I2CS_CTRLB_ACKACT    (0x1u << SERCOM_I2CS_CTRLB_ACKACT_Pos)
#define SERCOM_I2CS_CTRLB_MASK      0x0007C100u  /**< \brief (SERCOM_I2CS_CTRLB) MASK Register */

/* -------- SERCOM_SPI_CTRLB : (SERCOM Offset: 0x04) (R/W 32) SPI SPI Control B -------- */

#define SERCOM_SPI_CTRLB_OFFSET     0x04         /**< \brief (SERCOM_SPI_CTRLB offset) SPI Control B */
#define SERCOM_SPI_CTRLB_RESETVALUE 0x00000000   /**< \brief (SERCOM_SPI_CTRLB reset_value) SPI Control B */

#define SERCOM_SPI_CTRLB_CHSIZE_Pos 0            /**< \brief (SERCOM_SPI_CTRLB) Character Size */
#define SERCOM_SPI_CTRLB_CHSIZE_Msk (0x7u << SERCOM_SPI_CTRLB_CHSIZE_Pos)
#define SERCOM_SPI_CTRLB_CHSIZE(value) ((SERCOM_SPI_CTRLB_CHSIZE_Msk & ((value) << SERCOM_SPI_CTRLB_CHSIZE_Pos)))
#define SERCOM_SPI_CTRLB_PLOADEN_Pos 6            /**< \brief (SERCOM_SPI_CTRLB) Data Preload Enable */
#define SERCOM_SPI_CTRLB_PLOADEN    (0x1u << SERCOM_SPI_CTRLB_PLOADEN_Pos)
#define SERCOM_SPI_CTRLB_AMODE_Pos  14           /**< \brief (SERCOM_SPI_CTRLB) Address Mode */
#define SERCOM_SPI_CTRLB_AMODE_Msk  (0x3u << SERCOM_SPI_CTRLB_AMODE_Pos)
#define SERCOM_SPI_CTRLB_AMODE(value) ((SERCOM_SPI_CTRLB_AMODE_Msk & ((value) << SERCOM_SPI_CTRLB_AMODE_Pos)))
#define SERCOM_SPI_CTRLB_RXEN_Pos   17           /**< \brief (SERCOM_SPI_CTRLB) Receiver Enable */
#define SERCOM_SPI_CTRLB_RXEN       (0x1u << SERCOM_SPI_CTRLB_RXEN_Pos)
#define SERCOM_SPI_CTRLB_MASK       0x0002C047u  /**< \brief (SERCOM_SPI_CTRLB) MASK Register */

/* -------- SERCOM_USART_CTRLB : (SERCOM Offset: 0x04) (R/W 32) USART USART Control B -------- */

#define SERCOM_USART_CTRLB_OFFSET   0x04         /**< \brief (SERCOM_USART_CTRLB offset) USART Control B */
#define SERCOM_USART_CTRLB_RESETVALUE 0x00000000   /**< \brief (SERCOM_USART_CTRLB reset_value) USART Control B */

#define SERCOM_USART_CTRLB_CHSIZE_Pos 0            /**< \brief (SERCOM_USART_CTRLB) Character Size */
#define SERCOM_USART_CTRLB_CHSIZE_Msk (0x7u << SERCOM_USART_CTRLB_CHSIZE_Pos)
#define SERCOM_USART_CTRLB_CHSIZE(value) ((SERCOM_USART_CTRLB_CHSIZE_Msk & ((value) << SERCOM_USART_CTRLB_CHSIZE_Pos)))
#define SERCOM_USART_CTRLB_SBMODE_Pos 6            /**< \brief (SERCOM_USART_CTRLB) Stop Bit Mode */
#define SERCOM_USART_CTRLB_SBMODE   (0x1u << SERCOM_USART_CTRLB_SBMODE_Pos)
#define SERCOM_USART_CTRLB_SFDE_Pos 9            /**< \brief (SERCOM_USART_CTRLB) Start of Frame Detection Enable */
#define SERCOM_USART_CTRLB_SFDE     (0x1u << SERCOM_USART_CTRLB_SFDE_Pos)
#define SERCOM_USART_CTRLB_PMODE_Pos 13           /**< \brief (SERCOM_USART_CTRLB) Parity Mode */
#define SERCOM_USART_CTRLB_PMODE    (0x1u << SERCOM_USART_CTRLB_PMODE_Pos)
#define SERCOM_USART_CTRLB_TXEN_Pos 16           /**< \brief (SERCOM_USART_CTRLB) Transmitter Enable */
#define SERCOM_USART_CTRLB_TXEN     (0x1u << SERCOM_USART_CTRLB_TXEN_Pos)
#define SERCOM_USART_CTRLB_RXEN_Pos 17           /**< \brief (SERCOM_USART_CTRLB) Receiver Enable */
#define SERCOM_USART_CTRLB_RXEN     (0x1u << SERCOM_USART_CTRLB_RXEN_Pos)
#define SERCOM_USART_CTRLB_MASK     0x00032247u  /**< \brief (SERCOM_USART_CTRLB) MASK Register */

/* -------- SERCOM_I2CM_DBGCTRL : (SERCOM Offset: 0x08) (R/W  8) I2CM I2CM Debug Control -------- */


#define SERCOM_I2CM_DBGCTRL_OFFSET  0x08         /**< \brief (SERCOM_I2CM_DBGCTRL offset) I2CM Debug Control */
#define SERCOM_I2CM_DBGCTRL_RESETVALUE 0x00         /**< \brief (SERCOM_I2CM_DBGCTRL reset_value) I2CM Debug Control */

#define SERCOM_I2CM_DBGCTRL_DBGSTOP_Pos 0            /**< \brief (SERCOM_I2CM_DBGCTRL) Debug Mode */
#define SERCOM_I2CM_DBGCTRL_DBGSTOP (0x1u << SERCOM_I2CM_DBGCTRL_DBGSTOP_Pos)
#define SERCOM_I2CM_DBGCTRL_MASK    0x01u        /**< \brief (SERCOM_I2CM_DBGCTRL) MASK Register */

/* -------- SERCOM_SPI_DBGCTRL : (SERCOM Offset: 0x08) (R/W  8) SPI SPI Debug Control -------- */

#define SERCOM_SPI_DBGCTRL_OFFSET   0x08         /**< \brief (SERCOM_SPI_DBGCTRL offset) SPI Debug Control */
#define SERCOM_SPI_DBGCTRL_RESETVALUE 0x00         /**< \brief (SERCOM_SPI_DBGCTRL reset_value) SPI Debug Control */

#define SERCOM_SPI_DBGCTRL_DBGSTOP_Pos 0            /**< \brief (SERCOM_SPI_DBGCTRL) Debug Mode */
#define SERCOM_SPI_DBGCTRL_DBGSTOP  (0x1u << SERCOM_SPI_DBGCTRL_DBGSTOP_Pos)
#define SERCOM_SPI_DBGCTRL_MASK     0x01u        /**< \brief (SERCOM_SPI_DBGCTRL) MASK Register */

/* -------- SERCOM_USART_DBGCTRL : (SERCOM Offset: 0x08) (R/W  8) USART USART Debug Control -------- */

#define SERCOM_USART_DBGCTRL_OFFSET 0x08         /**< \brief (SERCOM_USART_DBGCTRL offset) USART Debug Control */
#define SERCOM_USART_DBGCTRL_RESETVALUE 0x00         /**< \brief (SERCOM_USART_DBGCTRL reset_value) USART Debug Control */

#define SERCOM_USART_DBGCTRL_DBGSTOP_Pos 0            /**< \brief (SERCOM_USART_DBGCTRL) Debug Mode */
#define SERCOM_USART_DBGCTRL_DBGSTOP (0x1u << SERCOM_USART_DBGCTRL_DBGSTOP_Pos)
#define SERCOM_USART_DBGCTRL_MASK   0x01u        /**< \brief (SERCOM_USART_DBGCTRL) MASK Register */

/* -------- SERCOM_I2CM_BAUD : (SERCOM Offset: 0x0A) (R/W 16) I2CM I2CM Baud Rate -------- */


#define SERCOM_I2CM_BAUD_OFFSET     0x0A         /**< \brief (SERCOM_I2CM_BAUD offset) I2CM Baud Rate */
#define SERCOM_I2CM_BAUD_RESETVALUE 0x0000       /**< \brief (SERCOM_I2CM_BAUD reset_value) I2CM Baud Rate */

#define SERCOM_I2CM_BAUD_BAUD_Pos   0            /**< \brief (SERCOM_I2CM_BAUD) Baud Rate Value */
#define SERCOM_I2CM_BAUD_BAUD_Msk   (0xFFu << SERCOM_I2CM_BAUD_BAUD_Pos)
#define SERCOM_I2CM_BAUD_BAUD(value) ((SERCOM_I2CM_BAUD_BAUD_Msk & ((value) << SERCOM_I2CM_BAUD_BAUD_Pos)))
#define SERCOM_I2CM_BAUD_BAUDLOW_Pos 8            /**< \brief (SERCOM_I2CM_BAUD) Baud Rate Value Low */
#define SERCOM_I2CM_BAUD_BAUDLOW_Msk (0xFFu << SERCOM_I2CM_BAUD_BAUDLOW_Pos)
#define SERCOM_I2CM_BAUD_BAUDLOW(value) ((SERCOM_I2CM_BAUD_BAUDLOW_Msk & ((value) << SERCOM_I2CM_BAUD_BAUDLOW_Pos)))
#define SERCOM_I2CM_BAUD_MASK       0xFFFFu      /**< \brief (SERCOM_I2CM_BAUD) MASK Register */

/* -------- SERCOM_SPI_BAUD : (SERCOM Offset: 0x0A) (R/W  8) SPI SPI Baud Rate -------- */
#define SERCOM_SPI_BAUD_OFFSET      0x0A         /**< \brief (SERCOM_SPI_BAUD offset) SPI Baud Rate */
#define SERCOM_SPI_BAUD_RESETVALUE  0x00         /**< \brief (SERCOM_SPI_BAUD reset_value) SPI Baud Rate */

#define SERCOM_SPI_BAUD_BAUD_Pos    0            /**< \brief (SERCOM_SPI_BAUD) Baud Rate Value */
#define SERCOM_SPI_BAUD_BAUD_Msk    (0xFFu << SERCOM_SPI_BAUD_BAUD_Pos)
#define SERCOM_SPI_BAUD_BAUD(value) ((SERCOM_SPI_BAUD_BAUD_Msk & ((value) << SERCOM_SPI_BAUD_BAUD_Pos)))
#define SERCOM_SPI_BAUD_MASK        0xFFu        /**< \brief (SERCOM_SPI_BAUD) MASK Register */

/* -------- SERCOM_USART_BAUD : (SERCOM Offset: 0x0A) (R/W 16) USART USART Baud Rate -------- */

#define SERCOM_USART_BAUD_OFFSET    0x0A         /**< \brief (SERCOM_USART_BAUD offset) USART Baud Rate */
#define SERCOM_USART_BAUD_RESETVALUE 0x0000       /**< \brief (SERCOM_USART_BAUD reset_value) USART Baud Rate */

#define SERCOM_USART_BAUD_BAUD_Pos  0            /**< \brief (SERCOM_USART_BAUD) Baud Rate Value */
#define SERCOM_USART_BAUD_BAUD_Msk  (0xFFFFu << SERCOM_USART_BAUD_BAUD_Pos)
#define SERCOM_USART_BAUD_BAUD(value) ((SERCOM_USART_BAUD_BAUD_Msk & ((value) << SERCOM_USART_BAUD_BAUD_Pos)))
#define SERCOM_USART_BAUD_MASK      0xFFFFu      /**< \brief (SERCOM_USART_BAUD) MASK Register */

/* -------- SERCOM_I2CM_INTENCLR : (SERCOM Offset: 0x0C) (R/W  8) I2CM I2CM Interrupt Enable Clear -------- */
#define SERCOM_I2CM_INTENCLR_OFFSET 0x0C         /**< \brief (SERCOM_I2CM_INTENCLR offset) I2CM Interrupt Enable Clear */
#define SERCOM_I2CM_INTENCLR_RESETVALUE 0x00         /**< \brief (SERCOM_I2CM_INTENCLR reset_value) I2CM Interrupt Enable Clear */

#define SERCOM_I2CM_INTENCLR_MB_Pos 0            /**< \brief (SERCOM_I2CM_INTENCLR) Write Interrupt Disable */
#define SERCOM_I2CM_INTENCLR_MB     (0x1u << SERCOM_I2CM_INTENCLR_MB_Pos)
#define SERCOM_I2CM_INTENCLR_SB_Pos 1            /**< \brief (SERCOM_I2CM_INTENCLR) Read Interrupt Disable */
#define SERCOM_I2CM_INTENCLR_SB     (0x1u << SERCOM_I2CM_INTENCLR_SB_Pos)
#define SERCOM_I2CM_INTENCLR_MASK   0x03u        /**< \brief (SERCOM_I2CM_INTENCLR) MASK Register */

/* -------- SERCOM_I2CS_INTENCLR : (SERCOM Offset: 0x0C) (R/W  8) I2CS I2CS Interrupt Enable Clear -------- */

#define SERCOM_I2CS_INTENCLR_OFFSET 0x0C         /**< \brief (SERCOM_I2CS_INTENCLR offset) I2CS Interrupt Enable Clear */
#define SERCOM_I2CS_INTENCLR_RESETVALUE 0x00         /**< \brief (SERCOM_I2CS_INTENCLR reset_value) I2CS Interrupt Enable Clear */

#define SERCOM_I2CS_INTENCLR_PREC_Pos 0            /**< \brief (SERCOM_I2CS_INTENCLR) Stop Interrupt Disable */
#define SERCOM_I2CS_INTENCLR_PREC   (0x1u << SERCOM_I2CS_INTENCLR_PREC_Pos)
#define SERCOM_I2CS_INTENCLR_AMATCH_Pos 1            /**< \brief (SERCOM_I2CS_INTENCLR) Address Interrupt Disable */
#define SERCOM_I2CS_INTENCLR_AMATCH (0x1u << SERCOM_I2CS_INTENCLR_AMATCH_Pos)
#define SERCOM_I2CS_INTENCLR_DRDY_Pos 2            /**< \brief (SERCOM_I2CS_INTENCLR) Data Interrupt Disable */
#define SERCOM_I2CS_INTENCLR_DRDY   (0x1u << SERCOM_I2CS_INTENCLR_DRDY_Pos)
#define SERCOM_I2CS_INTENCLR_MASK   0x07u        /**< \brief (SERCOM_I2CS_INTENCLR) MASK Register */

/* -------- SERCOM_SPI_INTENCLR : (SERCOM Offset: 0x0C) (R/W  8) SPI SPI Interrupt Enable Clear -------- */

#define SERCOM_SPI_INTENCLR_OFFSET  0x0C         /**< \brief (SERCOM_SPI_INTENCLR offset) SPI Interrupt Enable Clear */
#define SERCOM_SPI_INTENCLR_RESETVALUE 0x00         /**< \brief (SERCOM_SPI_INTENCLR reset_value) SPI Interrupt Enable Clear */

#define SERCOM_SPI_INTENCLR_DRE_Pos 0            /**< \brief (SERCOM_SPI_INTENCLR) Data Register Empty Interrupt Disable */
#define SERCOM_SPI_INTENCLR_DRE     (0x1u << SERCOM_SPI_INTENCLR_DRE_Pos)
#define SERCOM_SPI_INTENCLR_TXC_Pos 1            /**< \brief (SERCOM_SPI_INTENCLR) Transmit Complete Interrupt Disable */
#define SERCOM_SPI_INTENCLR_TXC     (0x1u << SERCOM_SPI_INTENCLR_TXC_Pos)
#define SERCOM_SPI_INTENCLR_RXC_Pos 2            /**< \brief (SERCOM_SPI_INTENCLR) Receive Complete Interrupt Disable */
#define SERCOM_SPI_INTENCLR_RXC     (0x1u << SERCOM_SPI_INTENCLR_RXC_Pos)
#define SERCOM_SPI_INTENCLR_MASK    0x07u        /**< \brief (SERCOM_SPI_INTENCLR) MASK Register */

/* -------- SERCOM_USART_INTENCLR : (SERCOM Offset: 0x0C) (R/W  8) USART USART Interrupt Enable Clear -------- */


#define SERCOM_USART_INTENCLR_OFFSET 0x0C         /**< \brief (SERCOM_USART_INTENCLR offset) USART Interrupt Enable Clear */
#define SERCOM_USART_INTENCLR_RESETVALUE 0x00         /**< \brief (SERCOM_USART_INTENCLR reset_value) USART Interrupt Enable Clear */

#define SERCOM_USART_INTENCLR_DRE_Pos 0            /**< \brief (SERCOM_USART_INTENCLR) Data Register Empty Interrupt Disable */
#define SERCOM_USART_INTENCLR_DRE   (0x1u << SERCOM_USART_INTENCLR_DRE_Pos)
#define SERCOM_USART_INTENCLR_TXC_Pos 1            /**< \brief (SERCOM_USART_INTENCLR) Transmit Complete Interrupt Disable */
#define SERCOM_USART_INTENCLR_TXC   (0x1u << SERCOM_USART_INTENCLR_TXC_Pos)
#define SERCOM_USART_INTENCLR_RXC_Pos 2            /**< \brief (SERCOM_USART_INTENCLR) Receive Complete Interrupt Disable */
#define SERCOM_USART_INTENCLR_RXC   (0x1u << SERCOM_USART_INTENCLR_RXC_Pos)
#define SERCOM_USART_INTENCLR_RXS_Pos 3            /**< \brief (SERCOM_USART_INTENCLR) Receive Start Interrupt Disable */
#define SERCOM_USART_INTENCLR_RXS   (0x1u << SERCOM_USART_INTENCLR_RXS_Pos)
#define SERCOM_USART_INTENCLR_MASK  0x0Fu        /**< \brief (SERCOM_USART_INTENCLR) MASK Register */

/* -------- SERCOM_I2CM_INTENSET : (SERCOM Offset: 0x0D) (R/W  8) I2CM I2CM Interrupt Enable Set -------- */

#define SERCOM_I2CM_INTENSET_OFFSET 0x0D         /**< \brief (SERCOM_I2CM_INTENSET offset) I2CM Interrupt Enable Set */
#define SERCOM_I2CM_INTENSET_RESETVALUE 0x00         /**< \brief (SERCOM_I2CM_INTENSET reset_value) I2CM Interrupt Enable Set */

#define SERCOM_I2CM_INTENSET_MB_Pos 0            /**< \brief (SERCOM_I2CM_INTENSET) Write Interrupt Enable */
#define SERCOM_I2CM_INTENSET_MB     (0x1u << SERCOM_I2CM_INTENSET_MB_Pos)
#define SERCOM_I2CM_INTENSET_SB_Pos 1            /**< \brief (SERCOM_I2CM_INTENSET) Read Interrupt Enable */
#define SERCOM_I2CM_INTENSET_SB     (0x1u << SERCOM_I2CM_INTENSET_SB_Pos)
#define SERCOM_I2CM_INTENSET_MASK   0x03u        /**< \brief (SERCOM_I2CM_INTENSET) MASK Register */

/* -------- SERCOM_I2CS_INTENSET : (SERCOM Offset: 0x0D) (R/W  8) I2CS I2CS Interrupt Enable Set -------- */

#define SERCOM_I2CS_INTENSET_OFFSET 0x0D         /**< \brief (SERCOM_I2CS_INTENSET offset) I2CS Interrupt Enable Set */
#define SERCOM_I2CS_INTENSET_RESETVALUE 0x00         /**< \brief (SERCOM_I2CS_INTENSET reset_value) I2CS Interrupt Enable Set */

#define SERCOM_I2CS_INTENSET_PREC_Pos 0            /**< \brief (SERCOM_I2CS_INTENSET) Stop Interrupt Enable */
#define SERCOM_I2CS_INTENSET_PREC   (0x1u << SERCOM_I2CS_INTENSET_PREC_Pos)
#define SERCOM_I2CS_INTENSET_AMATCH_Pos 1            /**< \brief (SERCOM_I2CS_INTENSET) Address Interrupt Enable */
#define SERCOM_I2CS_INTENSET_AMATCH (0x1u << SERCOM_I2CS_INTENSET_AMATCH_Pos)
#define SERCOM_I2CS_INTENSET_DRDY_Pos 2            /**< \brief (SERCOM_I2CS_INTENSET) Data Interrupt Enable */
#define SERCOM_I2CS_INTENSET_DRDY   (0x1u << SERCOM_I2CS_INTENSET_DRDY_Pos)
#define SERCOM_I2CS_INTENSET_MASK   0x07u        /**< \brief (SERCOM_I2CS_INTENSET) MASK Register */

/* -------- SERCOM_SPI_INTENSET : (SERCOM Offset: 0x0D) (R/W  8) SPI SPI Interrupt Enable Set -------- */

#define SERCOM_SPI_INTENSET_OFFSET  0x0D         /**< \brief (SERCOM_SPI_INTENSET offset) SPI Interrupt Enable Set */
#define SERCOM_SPI_INTENSET_RESETVALUE 0x00         /**< \brief (SERCOM_SPI_INTENSET reset_value) SPI Interrupt Enable Set */

#define SERCOM_SPI_INTENSET_DRE_Pos 0            /**< \brief (SERCOM_SPI_INTENSET) Data Register Empty Interrupt Enable */
#define SERCOM_SPI_INTENSET_DRE     (0x1u << SERCOM_SPI_INTENSET_DRE_Pos)
#define SERCOM_SPI_INTENSET_TXC_Pos 1            /**< \brief (SERCOM_SPI_INTENSET) Transmit Complete Interrupt Enable */
#define SERCOM_SPI_INTENSET_TXC     (0x1u << SERCOM_SPI_INTENSET_TXC_Pos)
#define SERCOM_SPI_INTENSET_RXC_Pos 2            /**< \brief (SERCOM_SPI_INTENSET) Receive Complete Interrupt Enable */
#define SERCOM_SPI_INTENSET_RXC     (0x1u << SERCOM_SPI_INTENSET_RXC_Pos)
#define SERCOM_SPI_INTENSET_MASK    0x07u        /**< \brief (SERCOM_SPI_INTENSET) MASK Register */

/* -------- SERCOM_USART_INTENSET : (SERCOM Offset: 0x0D) (R/W  8) USART USART Interrupt Enable Set -------- */

#define SERCOM_USART_INTENSET_OFFSET 0x0D         /**< \brief (SERCOM_USART_INTENSET offset) USART Interrupt Enable Set */
#define SERCOM_USART_INTENSET_RESETVALUE 0x00         /**< \brief (SERCOM_USART_INTENSET reset_value) USART Interrupt Enable Set */

#define SERCOM_USART_INTENSET_DRE_Pos 0            /**< \brief (SERCOM_USART_INTENSET) Data Register Empty Interrupt Enable */
#define SERCOM_USART_INTENSET_DRE   (0x1u << SERCOM_USART_INTENSET_DRE_Pos)
#define SERCOM_USART_INTENSET_TXC_Pos 1            /**< \brief (SERCOM_USART_INTENSET) Transmit Complete Interrupt Enable */
#define SERCOM_USART_INTENSET_TXC   (0x1u << SERCOM_USART_INTENSET_TXC_Pos)
#define SERCOM_USART_INTENSET_RXC_Pos 2            /**< \brief (SERCOM_USART_INTENSET) Receive Complete Interrupt Enable */
#define SERCOM_USART_INTENSET_RXC   (0x1u << SERCOM_USART_INTENSET_RXC_Pos)
#define SERCOM_USART_INTENSET_RXS_Pos 3            /**< \brief (SERCOM_USART_INTENSET) Receive Start Interrupt Enable */
#define SERCOM_USART_INTENSET_RXS   (0x1u << SERCOM_USART_INTENSET_RXS_Pos)
#define SERCOM_USART_INTENSET_MASK  0x0Fu        /**< \brief (SERCOM_USART_INTENSET) MASK Register */

/* -------- SERCOM_I2CM_INTFLAG : (SERCOM Offset: 0x0E) (R/W  8) I2CM I2CM Interrupt Flag Status and Clear -------- */

#define SERCOM_I2CM_INTFLAG_OFFSET  0x0E         /**< \brief (SERCOM_I2CM_INTFLAG offset) I2CM Interrupt Flag Status and Clear */
#define SERCOM_I2CM_INTFLAG_RESETVALUE 0x00         /**< \brief (SERCOM_I2CM_INTFLAG reset_value) I2CM Interrupt Flag Status and Clear */

#define SERCOM_I2CM_INTFLAG_MB_Pos  0            /**< \brief (SERCOM_I2CM_INTFLAG) Write Interrupt */
#define SERCOM_I2CM_INTFLAG_MB      (0x1u << SERCOM_I2CM_INTFLAG_MB_Pos)
#define SERCOM_I2CM_INTFLAG_SB_Pos  1            /**< \brief (SERCOM_I2CM_INTFLAG) Read Interrupt */
#define SERCOM_I2CM_INTFLAG_SB      (0x1u << SERCOM_I2CM_INTFLAG_SB_Pos)
#define SERCOM_I2CM_INTFLAG_MASK    0x03u        /**< \brief (SERCOM_I2CM_INTFLAG) MASK Register */

/* -------- SERCOM_I2CS_INTFLAG : (SERCOM Offset: 0x0E) (R/W  8) I2CS I2CS Interrupt Flag Status and Clear -------- */

#define SERCOM_I2CS_INTFLAG_OFFSET  0x0E         /**< \brief (SERCOM_I2CS_INTFLAG offset) I2CS Interrupt Flag Status and Clear */
#define SERCOM_I2CS_INTFLAG_RESETVALUE 0x00         /**< \brief (SERCOM_I2CS_INTFLAG reset_value) I2CS Interrupt Flag Status and Clear */

#define SERCOM_I2CS_INTFLAG_PREC_Pos 0            /**< \brief (SERCOM_I2CS_INTFLAG) Stop Interrupt */
#define SERCOM_I2CS_INTFLAG_PREC    (0x1u << SERCOM_I2CS_INTFLAG_PREC_Pos)
#define SERCOM_I2CS_INTFLAG_AMATCH_Pos 1            /**< \brief (SERCOM_I2CS_INTFLAG) Address Interrupt */
#define SERCOM_I2CS_INTFLAG_AMATCH  (0x1u << SERCOM_I2CS_INTFLAG_AMATCH_Pos)
#define SERCOM_I2CS_INTFLAG_DRDY_Pos 2            /**< \brief (SERCOM_I2CS_INTFLAG) Data Interrupt */
#define SERCOM_I2CS_INTFLAG_DRDY    (0x1u << SERCOM_I2CS_INTFLAG_DRDY_Pos)
#define SERCOM_I2CS_INTFLAG_MASK    0x07u        /**< \brief (SERCOM_I2CS_INTFLAG) MASK Register */

/* -------- SERCOM_SPI_INTFLAG : (SERCOM Offset: 0x0E) (R/W  8) SPI SPI Interrupt Flag Status and Clear -------- */

#define SERCOM_SPI_INTFLAG_OFFSET   0x0E         /**< \brief (SERCOM_SPI_INTFLAG offset) SPI Interrupt Flag Status and Clear */
#define SERCOM_SPI_INTFLAG_RESETVALUE 0x00         /**< \brief (SERCOM_SPI_INTFLAG reset_value) SPI Interrupt Flag Status and Clear */

#define SERCOM_SPI_INTFLAG_DRE_Pos  0            /**< \brief (SERCOM_SPI_INTFLAG) Data Register Empty Interrupt */
#define SERCOM_SPI_INTFLAG_DRE      (0x1u << SERCOM_SPI_INTFLAG_DRE_Pos)
#define SERCOM_SPI_INTFLAG_TXC_Pos  1            /**< \brief (SERCOM_SPI_INTFLAG) Transmit Complete Interrupt */
#define SERCOM_SPI_INTFLAG_TXC      (0x1u << SERCOM_SPI_INTFLAG_TXC_Pos)
#define SERCOM_SPI_INTFLAG_RXC_Pos  2            /**< \brief (SERCOM_SPI_INTFLAG) Receive Complete Interrupt */
#define SERCOM_SPI_INTFLAG_RXC      (0x1u << SERCOM_SPI_INTFLAG_RXC_Pos)
#define SERCOM_SPI_INTFLAG_MASK     0x07u        /**< \brief (SERCOM_SPI_INTFLAG) MASK Register */

/* -------- SERCOM_USART_INTFLAG : (SERCOM Offset: 0x0E) (R/W  8) USART USART Interrupt Flag Status and Clear -------- */

#define SERCOM_USART_INTFLAG_OFFSET 0x0E         /**< \brief (SERCOM_USART_INTFLAG offset) USART Interrupt Flag Status and Clear */
#define SERCOM_USART_INTFLAG_RESETVALUE 0x00         /**< \brief (SERCOM_USART_INTFLAG reset_value) USART Interrupt Flag Status and Clear */

#define SERCOM_USART_INTFLAG_DRE_Pos 0            /**< \brief (SERCOM_USART_INTFLAG) Data Register Empty Interrupt */
#define SERCOM_USART_INTFLAG_DRE    (0x1u << SERCOM_USART_INTFLAG_DRE_Pos)
#define SERCOM_USART_INTFLAG_TXC_Pos 1            /**< \brief (SERCOM_USART_INTFLAG) Transmit Complete Interrupt */
#define SERCOM_USART_INTFLAG_TXC    (0x1u << SERCOM_USART_INTFLAG_TXC_Pos)
#define SERCOM_USART_INTFLAG_RXC_Pos 2            /**< \brief (SERCOM_USART_INTFLAG) Receive Complete Interrupt */
#define SERCOM_USART_INTFLAG_RXC    (0x1u << SERCOM_USART_INTFLAG_RXC_Pos)
#define SERCOM_USART_INTFLAG_RXS_Pos 3            /**< \brief (SERCOM_USART_INTFLAG) Receive Start Interrupt */
#define SERCOM_USART_INTFLAG_RXS    (0x1u << SERCOM_USART_INTFLAG_RXS_Pos)
#define SERCOM_USART_INTFLAG_MASK   0x0Fu        /**< \brief (SERCOM_USART_INTFLAG) MASK Register */

/* -------- SERCOM_I2CM_STATUS : (SERCOM Offset: 0x10) (R/W 16) I2CM I2CM Status -------- */

#define SERCOM_I2CM_STATUS_OFFSET   0x10         /**< \brief (SERCOM_I2CM_STATUS offset) I2CM Status */
#define SERCOM_I2CM_STATUS_RESETVALUE 0x0000       /**< \brief (SERCOM_I2CM_STATUS reset_value) I2CM Status */

#define SERCOM_I2CM_STATUS_BUSERR_Pos 0            /**< \brief (SERCOM_I2CM_STATUS) Bus Error */
#define SERCOM_I2CM_STATUS_BUSERR   (0x1u << SERCOM_I2CM_STATUS_BUSERR_Pos)
#define SERCOM_I2CM_STATUS_ARBLOST_Pos 1            /**< \brief (SERCOM_I2CM_STATUS) Arbitration Lost */
#define SERCOM_I2CM_STATUS_ARBLOST  (0x1u << SERCOM_I2CM_STATUS_ARBLOST_Pos)
#define SERCOM_I2CM_STATUS_RXNACK_Pos 2            /**< \brief (SERCOM_I2CM_STATUS) Received Not Acknowledge */
#define SERCOM_I2CM_STATUS_RXNACK   (0x1u << SERCOM_I2CM_STATUS_RXNACK_Pos)
#define SERCOM_I2CM_STATUS_BUSSTATE_Pos 4            /**< \brief (SERCOM_I2CM_STATUS) Bus State */
#define SERCOM_I2CM_STATUS_BUSSTATE_Msk (0x3u << SERCOM_I2CM_STATUS_BUSSTATE_Pos)
#define SERCOM_I2CM_STATUS_BUSSTATE(value) ((SERCOM_I2CM_STATUS_BUSSTATE_Msk & ((value) << SERCOM_I2CM_STATUS_BUSSTATE_Pos)))
#define SERCOM_I2CM_STATUS_LOWTOUT_Pos 6            /**< \brief (SERCOM_I2CM_STATUS) SCL Low Timeout */
#define SERCOM_I2CM_STATUS_LOWTOUT  (0x1u << SERCOM_I2CM_STATUS_LOWTOUT_Pos)
#define SERCOM_I2CM_STATUS_CLKHOLD_Pos 7            /**< \brief (SERCOM_I2CM_STATUS) Clock Hold */
#define SERCOM_I2CM_STATUS_CLKHOLD  (0x1u << SERCOM_I2CM_STATUS_CLKHOLD_Pos)
#define SERCOM_I2CM_STATUS_SYNCBUSY_Pos 15           /**< \brief (SERCOM_I2CM_STATUS) Synchronization Busy */
#define SERCOM_I2CM_STATUS_SYNCBUSY (0x1u << SERCOM_I2CM_STATUS_SYNCBUSY_Pos)
#define SERCOM_I2CM_STATUS_MASK     0x80F7u      /**< \brief (SERCOM_I2CM_STATUS) MASK Register */

/* -------- SERCOM_I2CS_STATUS : (SERCOM Offset: 0x10) (R/W 16) I2CS I2CS Status -------- */

#define SERCOM_I2CS_STATUS_OFFSET   0x10         /**< \brief (SERCOM_I2CS_STATUS offset) I2CS Status */
#define SERCOM_I2CS_STATUS_RESETVALUE 0x0000       /**< \brief (SERCOM_I2CS_STATUS reset_value) I2CS Status */

#define SERCOM_I2CS_STATUS_BUSERR_Pos 0            /**< \brief (SERCOM_I2CS_STATUS) Bus Error */
#define SERCOM_I2CS_STATUS_BUSERR   (0x1u << SERCOM_I2CS_STATUS_BUSERR_Pos)
#define SERCOM_I2CS_STATUS_COLL_Pos 1            /**< \brief (SERCOM_I2CS_STATUS) Transmit Collision */
#define SERCOM_I2CS_STATUS_COLL     (0x1u << SERCOM_I2CS_STATUS_COLL_Pos)
#define SERCOM_I2CS_STATUS_RXNACK_Pos 2            /**< \brief (SERCOM_I2CS_STATUS) Received Not Acknowledge */
#define SERCOM_I2CS_STATUS_RXNACK   (0x1u << SERCOM_I2CS_STATUS_RXNACK_Pos)
#define SERCOM_I2CS_STATUS_DIR_Pos  3            /**< \brief (SERCOM_I2CS_STATUS) Read/Write Direction */
#define SERCOM_I2CS_STATUS_DIR      (0x1u << SERCOM_I2CS_STATUS_DIR_Pos)
#define SERCOM_I2CS_STATUS_SR_Pos   4            /**< \brief (SERCOM_I2CS_STATUS) Repeated Start */
#define SERCOM_I2CS_STATUS_SR       (0x1u << SERCOM_I2CS_STATUS_SR_Pos)
#define SERCOM_I2CS_STATUS_LOWTOUT_Pos 6            /**< \brief (SERCOM_I2CS_STATUS) SCL Low Timeout */
#define SERCOM_I2CS_STATUS_LOWTOUT  (0x1u << SERCOM_I2CS_STATUS_LOWTOUT_Pos)
#define SERCOM_I2CS_STATUS_CLKHOLD_Pos 7            /**< \brief (SERCOM_I2CS_STATUS) Clock Hold */
#define SERCOM_I2CS_STATUS_CLKHOLD  (0x1u << SERCOM_I2CS_STATUS_CLKHOLD_Pos)
#define SERCOM_I2CS_STATUS_SYNCBUSY_Pos 15           /**< \brief (SERCOM_I2CS_STATUS) Synchronization Busy */
#define SERCOM_I2CS_STATUS_SYNCBUSY (0x1u << SERCOM_I2CS_STATUS_SYNCBUSY_Pos)
#define SERCOM_I2CS_STATUS_MASK     0x80DFu      /**< \brief (SERCOM_I2CS_STATUS) MASK Register */

/* -------- SERCOM_SPI_STATUS : (SERCOM Offset: 0x10) (R/W 16) SPI SPI Status -------- */

#define SERCOM_SPI_STATUS_OFFSET    0x10         /**< \brief (SERCOM_SPI_STATUS offset) SPI Status */
#define SERCOM_SPI_STATUS_RESETVALUE 0x0000       /**< \brief (SERCOM_SPI_STATUS reset_value) SPI Status */

#define SERCOM_SPI_STATUS_BUFOVF_Pos 2            /**< \brief (SERCOM_SPI_STATUS) Buffer Overflow */
#define SERCOM_SPI_STATUS_BUFOVF    (0x1u << SERCOM_SPI_STATUS_BUFOVF_Pos)
#define SERCOM_SPI_STATUS_SYNCBUSY_Pos 15           /**< \brief (SERCOM_SPI_STATUS) Synchronization Busy */
#define SERCOM_SPI_STATUS_SYNCBUSY  (0x1u << SERCOM_SPI_STATUS_SYNCBUSY_Pos)
#define SERCOM_SPI_STATUS_MASK      0x8004u      /**< \brief (SERCOM_SPI_STATUS) MASK Register */

/* -------- SERCOM_USART_STATUS : (SERCOM Offset: 0x10) (R/W 16) USART USART Status -------- */

#define SERCOM_USART_STATUS_OFFSET  0x10         /**< \brief (SERCOM_USART_STATUS offset) USART Status */
#define SERCOM_USART_STATUS_RESETVALUE 0x0000       /**< \brief (SERCOM_USART_STATUS reset_value) USART Status */

#define SERCOM_USART_STATUS_PERR_Pos 0            /**< \brief (SERCOM_USART_STATUS) Parity Error */
#define SERCOM_USART_STATUS_PERR    (0x1u << SERCOM_USART_STATUS_PERR_Pos)
#define SERCOM_USART_STATUS_FERR_Pos 1            /**< \brief (SERCOM_USART_STATUS) Frame Error */
#define SERCOM_USART_STATUS_FERR    (0x1u << SERCOM_USART_STATUS_FERR_Pos)
#define SERCOM_USART_STATUS_BUFOVF_Pos 2            /**< \brief (SERCOM_USART_STATUS) Buffer Overflow */
#define SERCOM_USART_STATUS_BUFOVF  (0x1u << SERCOM_USART_STATUS_BUFOVF_Pos)
#define SERCOM_USART_STATUS_SYNCBUSY_Pos 15           /**< \brief (SERCOM_USART_STATUS) Synchronization Busy */
#define SERCOM_USART_STATUS_SYNCBUSY (0x1u << SERCOM_USART_STATUS_SYNCBUSY_Pos)
#define SERCOM_USART_STATUS_MASK    0x8007u      /**< \brief (SERCOM_USART_STATUS) MASK Register */

/* -------- SERCOM_I2CM_ADDR : (SERCOM Offset: 0x14) (R/W  8) I2CM I2CM Address -------- */

#define SERCOM_I2CM_ADDR_OFFSET     0x14         /**< \brief (SERCOM_I2CM_ADDR offset) I2CM Address */
#define SERCOM_I2CM_ADDR_RESETVALUE 0x00         /**< \brief (SERCOM_I2CM_ADDR reset_value) I2CM Address */

#define SERCOM_I2CM_ADDR_ADDR_Pos   0            /**< \brief (SERCOM_I2CM_ADDR) Address Value */
#define SERCOM_I2CM_ADDR_ADDR_Msk   (0xFFu << SERCOM_I2CM_ADDR_ADDR_Pos)
#define SERCOM_I2CM_ADDR_ADDR(value) ((SERCOM_I2CM_ADDR_ADDR_Msk & ((value) << SERCOM_I2CM_ADDR_ADDR_Pos)))
#define SERCOM_I2CM_ADDR_MASK       0xFFu        /**< \brief (SERCOM_I2CM_ADDR) MASK Register */

/* -------- SERCOM_I2CS_ADDR : (SERCOM Offset: 0x14) (R/W 32) I2CS I2CS Address -------- */

#define SERCOM_I2CS_ADDR_OFFSET     0x14         /**< \brief (SERCOM_I2CS_ADDR offset) I2CS Address */
#define SERCOM_I2CS_ADDR_RESETVALUE 0x00000000   /**< \brief (SERCOM_I2CS_ADDR reset_value) I2CS Address */

#define SERCOM_I2CS_ADDR_GENCEN_Pos 0            /**< \brief (SERCOM_I2CS_ADDR) General Call Address Enable */
#define SERCOM_I2CS_ADDR_GENCEN     (0x1u << SERCOM_I2CS_ADDR_GENCEN_Pos)
#define SERCOM_I2CS_ADDR_ADDR_Pos   1            /**< \brief (SERCOM_I2CS_ADDR) Address Value */
#define SERCOM_I2CS_ADDR_ADDR_Msk   (0x7Fu << SERCOM_I2CS_ADDR_ADDR_Pos)
#define SERCOM_I2CS_ADDR_ADDR(value) ((SERCOM_I2CS_ADDR_ADDR_Msk & ((value) << SERCOM_I2CS_ADDR_ADDR_Pos)))
#define SERCOM_I2CS_ADDR_ADDRMASK_Pos 17           /**< \brief (SERCOM_I2CS_ADDR) Address Mask */
#define SERCOM_I2CS_ADDR_ADDRMASK_Msk (0x7Fu << SERCOM_I2CS_ADDR_ADDRMASK_Pos)
#define SERCOM_I2CS_ADDR_ADDRMASK(value) ((SERCOM_I2CS_ADDR_ADDRMASK_Msk & ((value) << SERCOM_I2CS_ADDR_ADDRMASK_Pos)))
#define SERCOM_I2CS_ADDR_MASK       0x00FE00FFu  /**< \brief (SERCOM_I2CS_ADDR) MASK Register */

/* -------- SERCOM_SPI_ADDR : (SERCOM Offset: 0x14) (R/W 32) SPI SPI Address -------- */

#define SERCOM_SPI_ADDR_OFFSET      0x14         /**< \brief (SERCOM_SPI_ADDR offset) SPI Address */
#define SERCOM_SPI_ADDR_RESETVALUE  0x00000000   /**< \brief (SERCOM_SPI_ADDR reset_value) SPI Address */

#define SERCOM_SPI_ADDR_ADDR_Pos    0            /**< \brief (SERCOM_SPI_ADDR) Address Value */
#define SERCOM_SPI_ADDR_ADDR_Msk    (0xFFu << SERCOM_SPI_ADDR_ADDR_Pos)
#define SERCOM_SPI_ADDR_ADDR(value) ((SERCOM_SPI_ADDR_ADDR_Msk & ((value) << SERCOM_SPI_ADDR_ADDR_Pos)))
#define SERCOM_SPI_ADDR_ADDRMASK_Pos 16           /**< \brief (SERCOM_SPI_ADDR) Address Mask */
#define SERCOM_SPI_ADDR_ADDRMASK_Msk (0xFFu << SERCOM_SPI_ADDR_ADDRMASK_Pos)
#define SERCOM_SPI_ADDR_ADDRMASK(value) ((SERCOM_SPI_ADDR_ADDRMASK_Msk & ((value) << SERCOM_SPI_ADDR_ADDRMASK_Pos)))
#define SERCOM_SPI_ADDR_MASK        0x00FF00FFu  /**< \brief (SERCOM_SPI_ADDR) MASK Register */

/* -------- SERCOM_I2CM_DATA : (SERCOM Offset: 0x18) (R/W  8) I2CM I2CM Data -------- */

#define SERCOM_I2CM_DATA_OFFSET     0x18         /**< \brief (SERCOM_I2CM_DATA offset) I2CM Data */
#define SERCOM_I2CM_DATA_RESETVALUE 0x00         /**< \brief (SERCOM_I2CM_DATA reset_value) I2CM Data */

#define SERCOM_I2CM_DATA_DATA_Pos   0            /**< \brief (SERCOM_I2CM_DATA) Data Value */
#define SERCOM_I2CM_DATA_DATA_Msk   (0xFFu << SERCOM_I2CM_DATA_DATA_Pos)
#define SERCOM_I2CM_DATA_DATA(value) ((SERCOM_I2CM_DATA_DATA_Msk & ((value) << SERCOM_I2CM_DATA_DATA_Pos)))
#define SERCOM_I2CM_DATA_MASK       0xFFu        /**< \brief (SERCOM_I2CM_DATA) MASK Register */

/* -------- SERCOM_I2CS_DATA : (SERCOM Offset: 0x18) (R/W  8) I2CS I2CS Data -------- */
#define SERCOM_I2CS_DATA_OFFSET     0x18         /**< \brief (SERCOM_I2CS_DATA offset) I2CS Data */
#define SERCOM_I2CS_DATA_RESETVALUE 0x00         /**< \brief (SERCOM_I2CS_DATA reset_value) I2CS Data */

#define SERCOM_I2CS_DATA_DATA_Pos   0            /**< \brief (SERCOM_I2CS_DATA) Data Value */
#define SERCOM_I2CS_DATA_DATA_Msk   (0xFFu << SERCOM_I2CS_DATA_DATA_Pos)
#define SERCOM_I2CS_DATA_DATA(value) ((SERCOM_I2CS_DATA_DATA_Msk & ((value) << SERCOM_I2CS_DATA_DATA_Pos)))
#define SERCOM_I2CS_DATA_MASK       0xFFu        /**< \brief (SERCOM_I2CS_DATA) MASK Register */

/* -------- SERCOM_SPI_DATA : (SERCOM Offset: 0x18) (R/W 16) SPI SPI Data -------- */


#define SERCOM_SPI_DATA_OFFSET      0x18         /**< \brief (SERCOM_SPI_DATA offset) SPI Data */
#define SERCOM_SPI_DATA_RESETVALUE  0x0000       /**< \brief (SERCOM_SPI_DATA reset_value) SPI Data */

#define SERCOM_SPI_DATA_DATA_Pos    0            /**< \brief (SERCOM_SPI_DATA) Data Value */
#define SERCOM_SPI_DATA_DATA_Msk    (0x1FFu << SERCOM_SPI_DATA_DATA_Pos)
#define SERCOM_SPI_DATA_DATA(value) ((SERCOM_SPI_DATA_DATA_Msk & ((value) << SERCOM_SPI_DATA_DATA_Pos)))
#define SERCOM_SPI_DATA_MASK        0x01FFu      /**< \brief (SERCOM_SPI_DATA) MASK Register */

/* -------- SERCOM_USART_DATA : (SERCOM Offset: 0x18) (R/W 16) USART USART Data -------- */

#define SERCOM_USART_DATA_OFFSET    0x18         /**< \brief (SERCOM_USART_DATA offset) USART Data */
#define SERCOM_USART_DATA_RESETVALUE 0x0000       /**< \brief (SERCOM_USART_DATA reset_value) USART Data */

#define SERCOM_USART_DATA_DATA_Pos  0            /**< \brief (SERCOM_USART_DATA) Data Value */
#define SERCOM_USART_DATA_DATA_Msk  (0x1FFu << SERCOM_USART_DATA_DATA_Pos)
#define SERCOM_USART_DATA_DATA(value) ((SERCOM_USART_DATA_DATA_Msk & ((value) << SERCOM_USART_DATA_DATA_Pos)))
#define SERCOM_USART_DATA_MASK      0x01FFu      /**< \brief (SERCOM_USART_DATA) MASK Register */

// 
// PM register OFF set definitions
//
#define PM_APBCMASK_OFFSET          0x20         /**< \brief (PM_APBCMASK offset) APBC Mask */
//
// GCLK register OFF set definitions
//
#define GCLK_CLKCTRL_OFFSET         0x2          /**< \brief (GCLK_CLKCTRL offset) Generic Clock Control */

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
//! \addtogroup KLx_SPI_Register
//! @{
//
//*****************************************************************************


//*****************************************************************************
//
//! @}
//
//*****************************************************************************
#endif // __HW_SPI_H__
