//*****************************************************************************
//
//! \file xhw_gpio.h
//! \brief Macros used when accessing the GPIO control hardware.
//! \version V2.2.1.0
//! \date 7/31/2012
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


#ifndef __XHW_GPIO_H__
#define __XHW_GPIO_H__

/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR PORT */
/* ========================================================================== */
/** \addtogroup SAMD20_PORT Port Module */
/*@{*/

#define REV_PORT                    0x100

/* -------- PORT_DIR : (PORT Offset: 0x00) (R/W 32) GROUP Data Direction -------- */
#define PORT_DIR_OFFSET             0x00         /**< \brief (PORT_DIR offset) Data Direction */
#define PORT_DIR_RESETVALUE         0x00000000   /**< \brief (PORT_DIR reset_value) Data Direction */

#define PORT_DIR_DIR_Pos            0            /**< \brief (PORT_DIR) Port Data Direction */
#define PORT_DIR_DIR_Msk            (0xFFFFFFFFu << PORT_DIR_DIR_Pos)
#define PORT_DIR_DIR(value)         ((PORT_DIR_DIR_Msk & ((value) << PORT_DIR_DIR_Pos)))
#define PORT_DIR_MASK               0xFFFFFFFFu  /**< \brief (PORT_DIR) MASK Register */

/* -------- PORT_DIRCLR : (PORT Offset: 0x04) (R/W 32) GROUP Data Direction Clear -------- */
#define PORT_DIRCLR_OFFSET          0x04         /**< \brief (PORT_DIRCLR offset) Data Direction Clear */
#define PORT_DIRCLR_RESETVALUE      0x00000000   /**< \brief (PORT_DIRCLR reset_value) Data Direction Clear */

#define PORT_DIRCLR_DIRCLR_Pos      0            /**< \brief (PORT_DIRCLR) Port Data Direction Clear */
#define PORT_DIRCLR_DIRCLR_Msk      (0xFFFFFFFFu << PORT_DIRCLR_DIRCLR_Pos)
#define PORT_DIRCLR_DIRCLR(value)   ((PORT_DIRCLR_DIRCLR_Msk & ((value) << PORT_DIRCLR_DIRCLR_Pos)))
#define PORT_DIRCLR_MASK            0xFFFFFFFFu  /**< \brief (PORT_DIRCLR) MASK Register */

/* -------- PORT_DIRSET : (PORT Offset: 0x08) (R/W 32) GROUP Data Direction Set -------- */
#define PORT_DIRSET_OFFSET          0x08         /**< \brief (PORT_DIRSET offset) Data Direction Set */
#define PORT_DIRSET_RESETVALUE      0x00000000   /**< \brief (PORT_DIRSET reset_value) Data Direction Set */

#define PORT_DIRSET_DIRSET_Pos      0            /**< \brief (PORT_DIRSET) Port Data Direction Set */
#define PORT_DIRSET_DIRSET_Msk      (0xFFFFFFFFu << PORT_DIRSET_DIRSET_Pos)
#define PORT_DIRSET_DIRSET(value)   ((PORT_DIRSET_DIRSET_Msk & ((value) << PORT_DIRSET_DIRSET_Pos)))
#define PORT_DIRSET_MASK            0xFFFFFFFFu  /**< \brief (PORT_DIRSET) MASK Register */

/* -------- PORT_DIRTGL : (PORT Offset: 0x0C) (R/W 32) GROUP Data Direction Toggle -------- */
#define PORT_DIRTGL_OFFSET          0x0C         /**< \brief (PORT_DIRTGL offset) Data Direction Toggle */
#define PORT_DIRTGL_RESETVALUE      0x00000000   /**< \brief (PORT_DIRTGL reset_value) Data Direction Toggle */

#define PORT_DIRTGL_DIRTGL_Pos      0            /**< \brief (PORT_DIRTGL) Port Data Direction Toggle */
#define PORT_DIRTGL_DIRTGL_Msk      (0xFFFFFFFFu << PORT_DIRTGL_DIRTGL_Pos)
#define PORT_DIRTGL_DIRTGL(value)   ((PORT_DIRTGL_DIRTGL_Msk & ((value) << PORT_DIRTGL_DIRTGL_Pos)))
#define PORT_DIRTGL_MASK            0xFFFFFFFFu  /**< \brief (PORT_DIRTGL) MASK Register */

/* -------- PORT_OUT : (PORT Offset: 0x10) (R/W 32) GROUP Data Output Value -------- */

#define PORT_OUT_OFFSET             0x10         /**< \brief (PORT_OUT offset) Data Output Value */
#define PORT_OUT_RESETVALUE         0x00000000   /**< \brief (PORT_OUT reset_value) Data Output Value */

#define PORT_OUT_OUT_Pos            0            /**< \brief (PORT_OUT) Port Data Output Value */
#define PORT_OUT_OUT_Msk            (0xFFFFFFFFu << PORT_OUT_OUT_Pos)
#define PORT_OUT_OUT(value)         ((PORT_OUT_OUT_Msk & ((value) << PORT_OUT_OUT_Pos)))
#define PORT_OUT_MASK               0xFFFFFFFFu  /**< \brief (PORT_OUT) MASK Register */

/* -------- PORT_OUTCLR : (PORT Offset: 0x14) (R/W 32) GROUP Data Output Value Clear -------- */


#define PORT_OUTCLR_OFFSET          0x14         /**< \brief (PORT_OUTCLR offset) Data Output Value Clear */
#define PORT_OUTCLR_RESETVALUE      0x00000000   /**< \brief (PORT_OUTCLR reset_value) Data Output Value Clear */

#define PORT_OUTCLR_OUTCLR_Pos      0            /**< \brief (PORT_OUTCLR) Port Data Output Value Clear */
#define PORT_OUTCLR_OUTCLR_Msk      (0xFFFFFFFFu << PORT_OUTCLR_OUTCLR_Pos)
#define PORT_OUTCLR_OUTCLR(value)   ((PORT_OUTCLR_OUTCLR_Msk & ((value) << PORT_OUTCLR_OUTCLR_Pos)))
#define PORT_OUTCLR_MASK            0xFFFFFFFFu  /**< \brief (PORT_OUTCLR) MASK Register */

/* -------- PORT_OUTSET : (PORT Offset: 0x18) (R/W 32) GROUP Data Output Value Set -------- */


#define PORT_OUTSET_OFFSET          0x18         /**< \brief (PORT_OUTSET offset) Data Output Value Set */
#define PORT_OUTSET_RESETVALUE      0x00000000   /**< \brief (PORT_OUTSET reset_value) Data Output Value Set */

#define PORT_OUTSET_OUTSET_Pos      0            /**< \brief (PORT_OUTSET) Port Data Output Value Set */
#define PORT_OUTSET_OUTSET_Msk      (0xFFFFFFFFu << PORT_OUTSET_OUTSET_Pos)
#define PORT_OUTSET_OUTSET(value)   ((PORT_OUTSET_OUTSET_Msk & ((value) << PORT_OUTSET_OUTSET_Pos)))
#define PORT_OUTSET_MASK            0xFFFFFFFFu  /**< \brief (PORT_OUTSET) MASK Register */

/* -------- PORT_OUTTGL : (PORT Offset: 0x1C) (R/W 32) GROUP Data Output Value Toggle -------- */


#define PORT_OUTTGL_OFFSET          0x1C         /**< \brief (PORT_OUTTGL offset) Data Output Value Toggle */
#define PORT_OUTTGL_RESETVALUE      0x00000000   /**< \brief (PORT_OUTTGL reset_value) Data Output Value Toggle */

#define PORT_OUTTGL_OUTTGL_Pos      0            /**< \brief (PORT_OUTTGL) Port Data Output Value Toggle */
#define PORT_OUTTGL_OUTTGL_Msk      (0xFFFFFFFFu << PORT_OUTTGL_OUTTGL_Pos)
#define PORT_OUTTGL_OUTTGL(value)   ((PORT_OUTTGL_OUTTGL_Msk & ((value) << PORT_OUTTGL_OUTTGL_Pos)))
#define PORT_OUTTGL_MASK            0xFFFFFFFFu  /**< \brief (PORT_OUTTGL) MASK Register */

/* -------- PORT_IN : (PORT Offset: 0x20) (R/  32) GROUP Data Input Value -------- */


#define PORT_IN_OFFSET              0x20         /**< \brief (PORT_IN offset) Data Input Value */
#define PORT_IN_RESETVALUE          0x00000000   /**< \brief (PORT_IN reset_value) Data Input Value */

#define PORT_IN_IN_Pos              0            /**< \brief (PORT_IN) Port Data Input Value */
#define PORT_IN_IN_Msk              (0xFFFFFFFFu << PORT_IN_IN_Pos)
#define PORT_IN_IN(value)           ((PORT_IN_IN_Msk & ((value) << PORT_IN_IN_Pos)))
#define PORT_IN_MASK                0xFFFFFFFFu  /**< \brief (PORT_IN) MASK Register */

/* -------- PORT_CTRL : (PORT Offset: 0x24) (R/W 32) GROUP Control -------- */


#define PORT_CTRL_OFFSET            0x24         /**< \brief (PORT_CTRL offset) Control */
#define PORT_CTRL_RESETVALUE        0x00000000   /**< \brief (PORT_CTRL reset_value) Control */

#define PORT_CTRL_SAMPLING_Pos      0            /**< \brief (PORT_CTRL) Input Sampling Mode */
#define PORT_CTRL_SAMPLING_Msk      (0xFFFFFFFFu << PORT_CTRL_SAMPLING_Pos)
#define PORT_CTRL_SAMPLING(value)   ((PORT_CTRL_SAMPLING_Msk & ((value) << PORT_CTRL_SAMPLING_Pos)))
#define PORT_CTRL_MASK              0xFFFFFFFFu  /**< \brief (PORT_CTRL) MASK Register */

/* -------- PORT_WRCONFIG : (PORT Offset: 0x28) ( /W 32) GROUP Write Configuration -------- */

#define PORT_WRCONFIG_OFFSET        0x28         /**< \brief (PORT_WRCONFIG offset) Write Configuration */
#define PORT_WRCONFIG_RESETVALUE    0x00000000   /**< \brief (PORT_WRCONFIG reset_value) Write Configuration */

#define PORT_WRCONFIG_PINMASK_Pos   0            /**< \brief (PORT_WRCONFIG) Pin Mask for Multiple Pin Configuration */
#define PORT_WRCONFIG_PINMASK_Msk   (0xFFFFu << PORT_WRCONFIG_PINMASK_Pos)
#define PORT_WRCONFIG_PINMASK(value) ((PORT_WRCONFIG_PINMASK_Msk & ((value) << PORT_WRCONFIG_PINMASK_Pos)))
#define PORT_WRCONFIG_PMUXEN_Pos    16           /**< \brief (PORT_WRCONFIG) Select Peripheral Multiplexer */
#define PORT_WRCONFIG_PMUXEN        (0x1u << PORT_WRCONFIG_PMUXEN_Pos)
#define PORT_WRCONFIG_INEN_Pos      17           /**< \brief (PORT_WRCONFIG) Input Enable */
#define PORT_WRCONFIG_INEN          (0x1u << PORT_WRCONFIG_INEN_Pos)
#define PORT_WRCONFIG_PULLEN_Pos    18           /**< \brief (PORT_WRCONFIG) Pull Enable */
#define PORT_WRCONFIG_PULLEN        (0x1u << PORT_WRCONFIG_PULLEN_Pos)
#define PORT_WRCONFIG_ODRAIN_Pos    19           /**< \brief (PORT_WRCONFIG) Open Drain Output */
#define PORT_WRCONFIG_ODRAIN        (0x1u << PORT_WRCONFIG_ODRAIN_Pos)
#define PORT_WRCONFIG_SLEWLIM_Pos   20           /**< \brief (PORT_WRCONFIG) Output Driver Slew Rate Limit Enable */
#define PORT_WRCONFIG_SLEWLIM       (0x1u << PORT_WRCONFIG_SLEWLIM_Pos)
#define PORT_WRCONFIG_DRVSTR_Pos    22           /**< \brief (PORT_WRCONFIG) Output Driver Strength Selection */
#define PORT_WRCONFIG_DRVSTR        (0x1u << PORT_WRCONFIG_DRVSTR_Pos)
#define PORT_WRCONFIG_PMUX_Pos      24           /**< \brief (PORT_WRCONFIG) Peripheral Multiplexing Template */
#define PORT_WRCONFIG_PMUX_Msk      (0xFu << PORT_WRCONFIG_PMUX_Pos)
#define PORT_WRCONFIG_PMUX(value)   ((PORT_WRCONFIG_PMUX_Msk & ((value) << PORT_WRCONFIG_PMUX_Pos)))
#define PORT_WRCONFIG_WRPMUX_Pos    28           /**< \brief (PORT_WRCONFIG) Write PMUX Registers */
#define PORT_WRCONFIG_WRPMUX        (0x1u << PORT_WRCONFIG_WRPMUX_Pos)
#define PORT_WRCONFIG_WRPINCFG_Pos  30           /**< \brief (PORT_WRCONFIG) Write PINCFG Registers */
#define PORT_WRCONFIG_WRPINCFG      (0x1u << PORT_WRCONFIG_WRPINCFG_Pos)
#define PORT_WRCONFIG_HWSEL_Pos     31           /**< \brief (PORT_WRCONFIG) Half-Word Select */
#define PORT_WRCONFIG_HWSEL         (0x1u << PORT_WRCONFIG_HWSEL_Pos)
#define PORT_WRCONFIG_MASK          0xDF5FFFFFu  /**< \brief (PORT_WRCONFIG) MASK Register */

/* -------- PORT_PMUX : (PORT Offset: 0x30) (R/W  8) GROUP Peripheral Multiplexing -------- */


#define PORT_PMUX_OFFSET            0x30         /**< \brief (PORT_PMUX offset) Peripheral Multiplexing */
#define PORT_PMUX_RESETVALUE        0x00         /**< \brief (PORT_PMUX reset_value) Peripheral Multiplexing */

#define PORT_PMUX_PMUXE_Pos         0            /**< \brief (PORT_PMUX) Peripheral Multiplexing for Even-Numbered Pin */
#define PORT_PMUX_PMUXE_Msk         (0xFu << PORT_PMUX_PMUXE_Pos)
#define PORT_PMUX_PMUXE(value)      ((PORT_PMUX_PMUXE_Msk & ((value) << PORT_PMUX_PMUXE_Pos)))
#define PORT_PMUX_PMUXO_Pos         4            /**< \brief (PORT_PMUX) Peripheral Multiplexing for Odd-Numbered Pin */
#define PORT_PMUX_PMUXO_Msk         (0xFu << PORT_PMUX_PMUXO_Pos)
#define PORT_PMUX_PMUXO(value)      ((PORT_PMUX_PMUXO_Msk & ((value) << PORT_PMUX_PMUXO_Pos)))
#define PORT_PMUX_MASK              0xFFu        /**< \brief (PORT_PMUX) MASK Register */

/* -------- PORT_PINCFG : (PORT Offset: 0x40) (R/W  8) GROUP Pin Configuration -------- */

#define PORT_PINCFG_OFFSET          0x40         /**< \brief (PORT_PINCFG offset) Pin Configuration */
#define PORT_PINCFG_RESETVALUE      0x00         /**< \brief (PORT_PINCFG reset_value) Pin Configuration */

#define PORT_PINCFG_PMUXEN_Pos      0            /**< \brief (PORT_PINCFG) Select Peripheral Multiplexer */
#define PORT_PINCFG_PMUXEN          (0x1u << PORT_PINCFG_PMUXEN_Pos)
#define PORT_PINCFG_INEN_Pos        1            /**< \brief (PORT_PINCFG) Input Enable */
#define PORT_PINCFG_INEN            (0x1u << PORT_PINCFG_INEN_Pos)
#define PORT_PINCFG_PULLEN_Pos      2            /**< \brief (PORT_PINCFG) Pull Enable */
#define PORT_PINCFG_PULLEN          (0x1u << PORT_PINCFG_PULLEN_Pos)
#define PORT_PINCFG_ODRAIN_Pos      3            /**< \brief (PORT_PINCFG) Open Drain Output */
#define PORT_PINCFG_ODRAIN          (0x1u << PORT_PINCFG_ODRAIN_Pos)
#define PORT_PINCFG_SLEWLIM_Pos     4            /**< \brief (PORT_PINCFG) Output Driver Slew Rate Limit Enable */
#define PORT_PINCFG_SLEWLIM         (0x1u << PORT_PINCFG_SLEWLIM_Pos)
#define PORT_PINCFG_DRVSTR_Pos      6            /**< \brief (PORT_PINCFG) Output Driver Strength Selection */
#define PORT_PINCFG_DRVSTR          (0x1u << PORT_PINCFG_DRVSTR_Pos)
#define PORT_PINCFG_MASK            0x5Fu        /**< \brief (PORT_PINCFG) MASK Register */

/** \brief PortGroup hardware registers */


/*@}*/


//*****************************************************************************
//
//! \addtogroup CoX_Peripheral_Lib
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup GPIO
//! @{
//
//*****************************************************************************



#endif // __XHW_GPIO_H__
