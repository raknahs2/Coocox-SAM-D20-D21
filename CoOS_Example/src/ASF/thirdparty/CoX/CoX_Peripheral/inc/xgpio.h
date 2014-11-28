//*****************************************************************************
//
//! \file xgpio.h
//! \brief Prototypes for the GPIO Driver.
//! \brief Prototypes for the AFIO Driver.
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

#ifndef __xGPIO_H__
#define __xGPIO_H__

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
//! \addtogroup GPIO
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_Config xGPIO intrerrupt number config
//! 
//! \section xGPIO_Config_section 1. Where to use this group
//! This is use to config xGPIO intrerrupt number.
//! 
//! \section xGPIO_Config_CoX 2.CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xGPIO General Pin ID    |       CoX      |         SAMD20         |
//! |------------------------|----------------|------------------------|
//! |xGPIO_INT_NUMBER        |    Mandatory   |   xGPIO_INT_NUMBER     |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//SAMD20Jx
#define PA0                     PA0
#define PA1                     PA1
#define PA2                     PA2
#define PA3                     PA3
#define PA4                     PA4
#define PA5                     PA5
#define PA6                     PA6
#define PA7                     PA7
#define PA8                     PA8
#define PA9                     PA9
#define PA10                    PA10
#define PA11                    PA11
#define PA12                    PA12
#define PA13                    PA13
#define PA14                    PA14
#define PA15                    PA15
#define PA16                    PA16
#define PA17                    PA17
#define PA18                    PA18
#define PA19                    PA19
#define PA20                    PA20
#define PA21                    PA21
#define PA22                    PA22
#define PA23                    PA23
#define PA24                    PA24
#define PA25                    PA25
#define PA26                    0
#define PA27                    PA27
#define PA28                    PA28
#define PA29                    0
#define PA30                    PA30
#define PA31                    PA31

#define PB0                     PB0
#define PB1                     PB1
#define PB2                     PB2
#define PB3                     PB3
#define PB4                     PB4
#define PB5                     PB5
#define PB6                     PB6
#define PB7                     PB7
#define PB8                     PB8
#define PB9                     PB9
#define PB10                    PB10
#define PB11                    PB11
#define PB12                    PB12
#define PB13                    PB13
#define PB14                    PB14
#define PB15                    PB15
#define PB16					PB16
#define PB17					PB17
#define PB18					0
#define PB19					0
#define PB20					0
#define PB21					0
#define PB22					PB22
#define PB23					PB23
#define PB24					0
#define PB25					0
#define PB26					0
#define PB27					0
#define PB28					0
#define PB29					0
#define PB30					PB30
#define PB31					PB31

//
//! xGPIO intrerrupt nimber config
//
#define xGPIO_INT_NUMBER        0 // 0 for now, need to check this along with EIC module which is where ext interrupts are configured. PORT doesn't have interrupts config.  

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_General_Pin_IDs xGPIO General Pin ID
//! 
//! \section xGPIO_General_Pin_SIDs 1. Where to use this group
//! The following values define the bit field for the ulPins argument to several
//! of the APIs. So all the API which have a ulPins argument must use this group.
//! 
//! \section xGPIO_General_Pin_IDs_CoX 2.CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xGPIO General Pin ID    |       CoX      |         SAMD2x         |
//! |------------------------|----------------|------------------------|
//! |xGPIO_PIN_n             |    Mandatory   |       xGPIO_PIN_0      |
//! |                        |                |------------------------|
//! |                        |                |       xGPIO_PIN_1      |
//! |                        |                |------------------------|
//! |                        |                |       xGPIO_PIN_2      |
//! |                        |                |------------------------|
//! |                        |                |           ...          |
//! |                        |                |------------------------|
//! |                        |                |       xGPIO_PIN_15     |
//! |                        |                |------------------------|
//! |                        |                |           ...          |
//! |                        |                |------------------------|
//! |                        |                |      xGPIO_PIN_30      |
//! |                        |                |------------------------|
//! |                        |                |      xGPIO_PIN_31      |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! GPIO pin 0
//
#define xGPIO_PIN_0             GPIO_PIN_0

//
//! GPIO pin 1
//
#define xGPIO_PIN_1             GPIO_PIN_1

//
//! GPIO pin 2
//
#define xGPIO_PIN_2             GPIO_PIN_2

//
//! GPIO pin 3
//
#define xGPIO_PIN_3             GPIO_PIN_3

//
//! GPIO pin 4
//
#define xGPIO_PIN_4             GPIO_PIN_4

//
//! GPIO pin 5
//
#define xGPIO_PIN_5             GPIO_PIN_5

//
//! GPIO pin 6
//
#define xGPIO_PIN_6             GPIO_PIN_6

//
//! GPIO pin 7
//
#define xGPIO_PIN_7             GPIO_PIN_7

//
//! GPIO pin 8
//
#define xGPIO_PIN_8             GPIO_PIN_8

//
//! GPIO pin 9
//
#define xGPIO_PIN_9             GPIO_PIN_9

//
//! GPIO pin 10
//
#define xGPIO_PIN_10            GPIO_PIN_10

//
//! GPIO pin 11
//
#define xGPIO_PIN_11            GPIO_PIN_11

//
//! GPIO pin 12
//
#define xGPIO_PIN_12            GPIO_PIN_12

//
//! GPIO pin 13
//
#define xGPIO_PIN_13            GPIO_PIN_13

//
//! GPIO pin 14
//
#define xGPIO_PIN_14            GPIO_PIN_14

//
//! GPIO pin 15
//
#define xGPIO_PIN_15            GPIO_PIN_15

//
//! GPIO pin 16
//
#define xGPIO_PIN_16            GPIO_PIN_16

//
//! GPIO pin 17
//
#define xGPIO_PIN_17            GPIO_PIN_17

//
//! GPIO pin 18
//
#define xGPIO_PIN_18            GPIO_PIN_18

//
//! GPIO pin 19
//
#define xGPIO_PIN_19            GPIO_PIN_19

//
//! GPIO pin 20
//
#define xGPIO_PIN_20            GPIO_PIN_20

//
//! GPIO pin 21
//
#define xGPIO_PIN_21            GPIO_PIN_21

//
//! GPIO pin 22
//
#define xGPIO_PIN_22            GPIO_PIN_22

//
//! GPIO pin 23
//
#define xGPIO_PIN_23            GPIO_PIN_23

//
//! GPIO pin 24
//
#define xGPIO_PIN_24            GPIO_PIN_24

//
//! GPIO pin 25
//
#define xGPIO_PIN_25            GPIO_PIN_25

//
//! GPIO pin 26
//
#define xGPIO_PIN_26            GPIO_PIN_26

//
//! GPIO pin 23
//
#define xGPIO_PIN_27            GPIO_PIN_27

//
//! GPIO pin 28
//
#define xGPIO_PIN_28            GPIO_PIN_28

//
//! GPIO pin 29
//
#define xGPIO_PIN_29            GPIO_PIN_29

//
//! GPIO pin 30
//
#define xGPIO_PIN_30            GPIO_PIN_30

//
//! GPIO pin 31
//
#define xGPIO_PIN_31            GPIO_PIN_31  

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_Dir_Mode xGPIO Dir Mode
//! 
//! \section xGPIO_Dir_Mode_S1 1. Where to use this group
//! Values that can be passed to xGPIODirModeSet as the ulPinIO parameter, and
//! returned from xGPIODirModeGet.
//! 
//! \section xGPIO_Dir_Mode_CoX 2.CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xGPIO Dir Mode          |       CoX      |         SAMD2x         |
//! |------------------------|----------------|------------------------|
//! |xGPIO_DIR_MODE_IN       |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xGPIO_DIR_MODE_OUT      |    Mandatory   |            Y           |
//! |------------------------|----------------|------------------------|
//! |xGPIO_DIR_MODE_HW       |    Mandatory   |            N           |
//! |------------------------|----------------|------------------------|
//! |xGPIO_DIR_MODE_QB       |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xGPIO_DIR_MODE_OD       |  Non-Mandatory |            N           |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
// Pin is a GPIO input
//
#define xGPIO_DIR_MODE_IN       GPIO_DIR_MODE_IN  

//
// Pin is a GPIO output
//
#define xGPIO_DIR_MODE_OUT      GPIO_DIR_MODE_OUT 

//
// Pin is a peripheral function
//
#define xGPIO_DIR_MODE_HW       GPIO_DIR_MODE_HW  

//
// Pin is in Quasi-bidirectional mode
//
#define xGPIO_DIR_MODE_QB       0  

//
// Pin is in Open-Drain mode.
//
#define xGPIO_DIR_MODE_OD       0  

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_Int_Type xGPIO Int Type
//! 
//! \section xGPIO_Int_Type_S1 1. Where to use this group
//! Values that can be passed to xGPIOIntTypeSet as the ulIntType parameter, and
//! returned from xGPIOIntTypeGet.
//! 
//! \section xGPIO_Int_Type_CoX 2.CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xGPIO Int Type          |       CoX      |         SAMD2x         |
//! |------------------------|----------------|------------------------|
//! |xGPIO_FALLING_EDGE      |    Mandatory   |            N           |
//! |------------------------|----------------|------------------------|
//! |xGPIO_RISING_EDGE       |    Mandatory   |            N           |
//! |------------------------|----------------|------------------------|
//! |xGPIO_LOW_LEVEL         |    Mandatory   |            N           |
//! |------------------------|----------------|------------------------|
//! |xGPIO_HIGH_LEVEL        |    Mandatory   |            N           |
//! |------------------------|----------------|------------------------|
//! |xGPIO_BOTH_LEVEL        |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! |xGPIO_BOTH_EDGES        |  Non-Mandatory |            N           |
//! |------------------------|----------------|------------------------|
//! \endverbatim
//! @{
//
//*****************************************************************************

//
// Interrupt on falling edge
//
#define xGPIO_FALLING_EDGE      0 

//
// Interrupt on rising edge
//
#define xGPIO_RISING_EDGE       0 

//
// Interrupt on both edges
//
#define xGPIO_BOTH_EDGES        0 

//
// Interrupt on both levels
//
#define xGPIO_BOTH_LEVEL        0

//
// Interrupt on low level
//
#define xGPIO_LOW_LEVEL         0  

//
// Interrupt on high level
//
#define xGPIO_HIGH_LEVEL        0 

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_Pad_Config_Strength xGPIO Pad Config Strength
//! 
//! \section xGPIO_Pad_Config_Strength_S1 1. Where to use this group
//! Values that can be passed to xGPIOPadConfigSet as the ulStrength parameter,
//! and returned by xGPIOPadConfigGet in the *pulStrength parameter.
//! 
//! \section xGPIO_Pad_Config_Strength_CoX 2.CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xGPIO Pad Strength      |       CoX      |         SAMD2x         |
//! |------------------------|----------------|------------------------|
//! |xGPIO_STRENGTH_nMA      | Non-Mandatory  |						   |
//! |                        |                |------------------------|
//! |                        |                |						   |
//! |                        |                |------------------------|
//! |                        |                |						   |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_Pad_Config_Type xGPIO Pad Config Type
//! <br />
//! \section xGPIO_Pad_Config_Type_S1 1. Where to use this group
//! Values that can be passed to xGPIOPadConfigSet as the ulPadType parameter,
//! and returned by xGPIOPadConfigGet in the *pulPadType parameter.
//! <br />
//! \section xGPIO_Pad_Config_Type_CoX 2.CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xGPIO Pad Type          |       CoX      |         SAMD2x         |
//! |------------------------|----------------|------------------------|
//! |xGPIO_PIN_TYPE_STD      |  Non-Mandatory |                       |
//! |------------------------|----------------|------------------------|
//! |xGPIO_PIN_TYPE_STD_WPU  |  Non-Mandatory |                       |
//! |------------------------|----------------|------------------------|
//! |xGPIO_PIN_TYPE_OD       |  Non-Mandatory |                       |
//! |------------------------|----------------|------------------------|
//! |xGPIO_PIN_TYPE_OD_WPU   |  Non-Mandatory |                       |
//! |------------------------|----------------|------------------------|
//! |xGPIO_PIN_TYPE_OD_WPD   |  Non-Mandatory |                       |
//! |------------------------|----------------|------------------------|
//! |xGPIO_PIN_TYPE_ANALOG   |  Non-Mandatory |                       |
//! |------------------------|----------------|------------------------|
//! |xGPIO_PIN_TYPE_STD_WPD  |  Non-Mandatory |                       |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//
//! GPIO pin type standard
//
#define	xGPIO_PIN_TYPE_STD      0

//
//! GPIO pin type standard with pull up
//
#define xGPIO_PIN_TYPE_STD_WPU  PORT_PIN_PULL_UP

//
//! GPIO pin type open drain
//
#define xGPIO_PIN_TYPE_OD       PORT_PIN_PULL_NONE

//
//! GPIO pin type open drain with pull up
//
#define xGPIO_PIN_TYPE_OD_WPU   0

//
//! GPIO pin type open drain with pull down
//
#define xGPIO_PIN_TYPE_OD_WPD   0

//
//! GPIO pin type analog
//
#define xGPIO_PIN_TYPE_ANALOG   0

//
//! GPIO pin type with pull down
//
#define xGPIO_PIN_TYPE_STD_WPD  PORT_PIN_PULL_DOWN

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_GP_Short_Pin xGPIO General Purpose Short Pin
//! @{
//
//*****************************************************************************
#define GPA0                     PORTA_BASE, GPIO_PIN_0
#define GPA1                     PORTA_BASE, GPIO_PIN_1
#define GPA2                     PORTA_BASE, GPIO_PIN_2
#define GPA3                     PORTA_BASE, GPIO_PIN_3
#define GPA4                     PORTA_BASE, GPIO_PIN_4
#define GPA5                     PORTA_BASE, GPIO_PIN_5
#define GPA6                     PORTA_BASE, GPIO_PIN_6
#define GPA7                     PORTA_BASE, GPIO_PIN_7
#define GPA8                     PORTA_BASE, GPIO_PIN_8
#define GPA9                     PORTA_BASE, GPIO_PIN_9
#define GPA10                    PORTA_BASE, GPIO_PIN_10
#define GPA11                    PORTA_BASE, GPIO_PIN_11
#define GPA12                    PORTA_BASE, GPIO_PIN_12
#define GPA13                    PORTA_BASE, GPIO_PIN_13
#define GPA14                    PORTA_BASE, GPIO_PIN_14
#define GPA15                    PORTA_BASE, GPIO_PIN_15
#define GPA16                    PORTA_BASE, GPIO_PIN_16
#define GPA17                    PORTA_BASE, GPIO_PIN_17
#define GPA18                    PORTA_BASE, GPIO_PIN_18
#define GPA19                    PORTA_BASE, GPIO_PIN_19
#define GPA20                    PORTA_BASE, GPIO_PIN_20
#define GPA21                    PORTA_BASE, GPIO_PIN_21
#define GPA22                    PORTA_BASE, GPIO_PIN_22
#define GPA23                    PORTA_BASE, GPIO_PIN_23
#define GPA24                    PORTA_BASE, GPIO_PIN_24
#define GPA25                    PORTA_BASE, GPIO_PIN_25
#define GPA26                    0
#define GPA27                    PORTA_BASE, GPIO_PIN_27
#define GPA28                    PORTA_BASE, GPIO_PIN_28
#define GPA29                    0
#define GPA30                    PORTA_BASE, GPIO_PIN_30
#define GPA31                    PORTA_BASE, GPIO_PIN_31

#define GPB0                     PORTB_BASE, GPIO_PIN_0
#define GPB1                     PORTB_BASE, GPIO_PIN_1
#define GPB2                     PORTB_BASE, GPIO_PIN_2
#define GPB3                     PORTB_BASE, GPIO_PIN_3
#define GPB4                     PORTB_BASE, GPIO_PIN_4
#define GPB5                     PORTB_BASE, GPIO_PIN_5
#define GPB6                     PORTB_BASE, GPIO_PIN_6
#define GPB7                     PORTB_BASE, GPIO_PIN_7
#define GPB8                     PORTB_BASE, GPIO_PIN_8
#define GPB9                     PORTB_BASE, GPIO_PIN_9
#define GPB10                    PORTB_BASE, GPIO_PIN_10
#define GPB11                    PORTB_BASE, GPIO_PIN_11
#define GPB12                    PORTB_BASE, GPIO_PIN_12
#define GPB13                    PORTB_BASE, GPIO_PIN_13
#define GPB14                    PORTB_BASE, GPIO_PIN_14
#define GPB15                    PORTB_BASE, GPIO_PIN_15
#define GPB16					 PORTB_BASE, GPIO_PIN_16
#define GPB17					 PORTB_BASE, GPIO_PIN_17
#define GPB18					 0
#define GPB19					 0
#define GPB20					 0
#define GPB21					 0
#define GPB22					 PORTB_BASE, GPIO_PIN_22
#define GPB23					 PORTB_BASE, GPIO_PIN_23
#define GPB24					 0
#define GPB25					 0
#define GPB26					 0
#define GPB27					 0
#define GPB28					 0
#define GPB29					 0
#define GPB30					 PORTB_BASE, GPIO_PIN_30
#define GPB31					 PORTB_BASE, GPIO_PIN_31

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_Short_Pin xGPIO Short Pin ID
//! 
//! \section xGPIO_Short_Pin_S1 1. Where to use this group
//! The following values define the short pin argument(dShortPin) to several
//! of the \b XPinTypexxx APIs and all the API which have a eShortPin argument.
//! Such as \ref xGPIOSPinRead(),\ref xGPIOSPinWrite().
//! 
//! \section xGPIO_Short_Pin_CoX 2.CoX Port Details 
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |xGPIO Short Pin ID      |       CoX      |         SAMD2x         |
//! |------------------------|----------------|------------------------|
//! |PXn                     |    Mandatory   |    PA0 PA1 ... PA31    |
//! |                        |                |------------------------|
//! |X is A, B, C ...        |                |    PB0 PB1 ... PB31    |
//! |                        |                |------------------------|
//! |                        |                |                        |
//! |                        |                |------------------------|
//! |                        |                |                        |
//! |                        |                |------------------------|
//! |                        |                |						   |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************


//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_Peripheral_Pin xGPIO General Peripheral Pin
//! \brief General Peripheral Pin Name.
//!
//! \section xGPIO_Peripheral_Pin_define xGPIO Peripheral Pin define?
//! The macros of General Peripheral Pin Name always like:
//! <b> ModuleName + n + PinName </b>, such as CAN0RX, SPI1CLK.
//!
//! \section xGPIO_Peripheral_Pin_Port CoX Port Details
//! \verbatim
//! +------------------------+----------------+------------------------+
//! |General Peripheral Pin  |       CoX      |         SAMD2x         |
//! |------------------------|----------------|------------------------|
//! |ADCn                    |    Mandatory   |						   |
//! |                        |                |------------------------|
//! |                        |                |                        |
//! |                        |                |------------------------|
//! |                        |                |                        |
//! |------------------------|----------------|------------------------|
//! |I2CnSCK                 |    Mandatory   |         |
//! |------------------------|----------------|------------------------|
//! |I2CnSDA                 |    Mandatory   |         |
//! |------------------------|----------------|------------------------|
//! |SPInCLK                 |    Mandatory   |         |
//! |------------------------|----------------|------------------------|
//! |SPInMOSI                |    Mandatory   |       |
//! |------------------------|----------------|------------------------|
//! |SPInMISO                |    Mandatory   |       |
//! |------------------------|----------------|------------------------|
//! |SPInCS                  |    Mandatory   |           |
//! |------------------------|----------------|------------------------|
//! |UARTnRX                 |    Mandatory   |         |
//! |                        |                |------------------------|
//! |                        |                |                 |
//! |------------------------|----------------|------------------------|
//! |UARTnTX                 |    Mandatory   |         |
//! |                        |                |------------------------|
//! |                        |                |                 |
//! |------------------------|----------------|------------------------|
//! |CMPnN                   |    Mandatory   |             |
//! |------------------------|----------------|------------------------|
//! |CMPnP                   |    Mandatory   |             |
//! |------------------------|----------------|------------------------|
//! |CMPnO                   |    Mandatory   |             |
//! |------------------------|----------------|------------------------|
//! |PWMn                    |    Mandatory   |           |
//! |------------------------|----------------|------------------------|
//! |TIMCCPn                 |    Mandatory   |     |
//! +------------------------+----------------+------------------------+
//! \endverbatim
//!
//!  
//! @{
//
//*****************************************************************************

#define ADC0                    0
#define ADC1                    0
#define ADC2                    0
#define ADC3                    0
#define ADC4                    0
#define ADC5                    0
#define ADC6                    0
#define ADC7                    0
#define ADC8                    0
#define ADC9                    0
#define ADC10                   0
#define ADC11                   0
#define ADC12                   0
#define ADC13                   0
#define ADC14                   0
#define ADC15                   0

#define CAN0RX                  0
#define CAN0TX                  0
#define CAN1RX                  0
#define CAN1TX                  0

#define I2C0SCK                 0
#define I2C0SDA                 0
#define I2C1SCK                 0
#define I2C1SDA                 0
#define I2C2SCK                 0
#define I2C2SDA                 0

#define I2S0RXSCK               0
#define I2S0RXMCLK              0
#define I2S0RXSD                0
#define I2S0RXWS                0
#define I2S0TXSCK               0
#define I2S0TXMCLK              0
#define I2S0TXSD                0
#define I2S0TXWS                0

#define SPI0CLK                 0
#define SPI0MOSI                0
#define SPI0MISO                0
#define SPI0CS                  0
#define SPI1CLK                 0
#define SPI1MOSI                0
#define SPI1MISO                0
#define SPI1CS                  0
#define SPI2CLK                 0
#define SPI2MOSI                0
#define SPI2MISO                0
#define SPI2CS                  0
#define SPI3CLK                 0
#define SPI3MOSI                0
#define SPI3MISO                0
#define SPI3CS                  0

#define UART0RX                 0
#define UART0TX                 0
#define UART0CTS                0
#define UART0DCD                0
#define UART0DSR                0
#define UART0DTR                0
#define UART1RX                 0
#define UART1TX                 0
#define UART1CTS                0
#define UART1DCD                0
#define UART1DSR                0
#define UART1DTR                0
#define UART2RX                 0
#define UART2TX                 0
#define UART2CTS                0
#define UART2DCD                0
#define UART2DSR                0
#define UART2DTR                0

#define CMP0N                   0
#define CMP0P                   0
#define CMP0O                   0
#define CMP1N                   0
#define CMP1P                   0
#define CMP1O                   0

#define PWM0                    0
#define PWM1                    0
#define PWM2                    0
#define PWM3                    0
#define PWM4                    0
#define PWM5                    0
#define PWM6                    0
#define PWM7                    0

#define TIMCCP0                 0
#define TIMCCP1                 0
#define TIMCCP2                 0
#define TIMCCP3                 0
#define TIMCCP4                 0
#define TIMCCP5                 0
#define TIMCCP6                 0
#define TIMCCP7                 0

//SAMD20Jx
#define AC_AIN0				 AC_AIN0
#define AC_AIN1				 AC_AIN1
#define AC_AIN2				 AC_AIN2
#define AC_AIN3				 AC_AIN3

#define AC_CMP0				 AC_CMP0
#define AC_CMP1				 AC_CMP1


#define ADC_AIN0			 ADC_AIN0
#define ADC_AIN1			 ADC_AIN1
#define ADC_AIN2			 ADC_AIN2
#define ADC_AIN3			 ADC_AIN3
#define ADC_AIN4			 ADC_AIN4
#define ADC_AIN5			 ADC_AIN5
#define ADC_AIN6			 ADC_AIN6
#define ADC_AIN7			 ADC_AIN7
#define ADC_AIN8			 ADC_AIN8
#define ADC_AIN9			 ADC_AIN9
#define ADC_AIN10			 ADC_AIN10
#define ADC_AIN11			 ADC_AIN11
#define ADC_AIN12			 ADC_AIN12
#define ADC_AIN13			 ADC_AIN13
#define ADC_AIN14			 ADC_AIN14
#define ADC_AIN15			 ADC_AIN15
#define ADC_AIN16			 ADC_AIN16
#define ADC_AIN17			 ADC_AIN17
#define ADC_AIN18			 ADC_AIN18
#define ADC_AIN19			 ADC_AIN19
#define ADC_VREFP			 ADC_VREFP

#define CORE_SWCLK			 CORE_SWCLK

#define DAC_VOUT			 DAC_VOUT
#define DAC_VREFP			 DAC_VREFP

#define EIC_EXTINT0			 EIC_EXTINT0
#define EIC_EXTINT1			 EIC_EXTINT1
#define EIC_EXTINT2			 EIC_EXTINT2
#define EIC_EXTINT3			 EIC_EXTINT3
#define EIC_EXTINT4			 EIC_EXTINT4
#define EIC_EXTINT5			 EIC_EXTINT5
#define EIC_EXTINT6			 EIC_EXTINT6
#define EIC_EXTINT7			 EIC_EXTINT7
#define EIC_EXTINT8			 EIC_EXTINT8
#define EIC_EXTINT9			 EIC_EXTINT9
#define EIC_EXTINT10		 EIC_EXTINT10
#define EIC_EXTINT11		 EIC_EXTINT11
#define EIC_EXTINT12		 EIC_EXTINT12
#define EIC_EXTINT13		 EIC_EXTINT13
#define EIC_EXTINT14		 EIC_EXTINT14
#define EIC_EXTINT15		 EIC_EXTINT15

#define EIC_NMI				 EIC_NMI

#define GCLK_IO0			 GCLK_IO0
#define GCLK_IO1			 GCLK_IO1
#define GCLK_IO2			 GCLK_IO2
#define GCLK_IO3			 GCLK_IO3
#define GCLK_IO4			 GCLK_IO4
#define GCLK_IO5			 GCLK_IO5
#define GCLK_IO6			 GCLK_IO6
#define GCLK_IO7			 GCLK_IO7

#define SERCOM0_PAD0		 SERCOM0_PAD0
#define SERCOM0_PAD1		 SERCOM0_PAD1
#define SERCOM0_PAD2		 SERCOM0_PAD2
#define SERCOM0_PAD3		 SERCOM0_PAD3

#define SERCOM1_PAD0		 SERCOM1_PAD0
#define SERCOM1_PAD1		 SERCOM1_PAD1
#define SERCOM1_PAD2		 SERCOM1_PAD2
#define SERCOM1_PAD3		 SERCOM1_PAD3

#define SERCOM2_PAD0		 SERCOM2_PAD0
#define SERCOM2_PAD1		 SERCOM2_PAD1
#define SERCOM2_PAD2		 SERCOM2_PAD2
#define SERCOM2_PAD3		 SERCOM2_PAD3

#define SERCOM3_PAD0		 SERCOM3_PAD0
#define SERCOM3_PAD1		 SERCOM3_PAD1
#define SERCOM3_PAD2		 SERCOM3_PAD2
#define SERCOM3_PAD3		 SERCOM3_PAD3

#define SERCOM4_PAD0		 SERCOM4_PAD0
#define SERCOM4_PAD1		 SERCOM4_PAD1
#define SERCOM4_PAD2		 SERCOM4_PAD2
#define SERCOM4_PAD3		 SERCOM4_PAD3

#define SERCOM5_PAD0		 SERCOM5_PAD0
#define SERCOM5_PAD1		 SERCOM5_PAD1
#define SERCOM5_PAD2		 SERCOM5_PAD2
#define SERCOM5_PAD3		 SERCOM5_PAD3

#define TC0_WO0				 TC0_WO0
#define TC0_WO1				 TC0_WO1

#define TC1_WO0				 TC1_WO0
#define TC1_WO1				 TC1_WO1

#define TC2_WO0				 TC2_WO0
#define TC2_WO1				 TC2_WO1

#define TC3_WO0				 TC3_WO0
#define TC3_WO1				 TC3_WO1

#define TC4_WO0				 TC4_WO0
#define TC4_WO1				 TC4_WO1

#define TC5_WO0				 TC5_WO0
#define TC5_WO1				 TC5_WO1

#define TC6_WO0				 TC6_WO0
#define TC6_WO1				 TC6_WO1

#define TC7_WO0				 TC7_WO0
#define TC7_WO1				 TC7_WO1


//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_Pin_Config xGPIO Pin Config
//! \brief Values that can be passed to xGPIOPinConfigure as the ulPinConfig 
//! parameter.
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup xGPIO_Exported_APIs xGPIO API
//! \brief xGPIO API Reference.
//!
//! \section xGPIO_Exported_APIs_Port CoX Port Details
//!
//! \verbatim
//! +--------------------------+----------------+------------------------+
//! |xGPIO API                 |       CoX      |         SAMD2x         |
//! |--------------------------|----------------|------------------------|
//! |xGPIODirModeSet           |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinToPeripheralId   |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinToPort           |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinToPin            |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinDirModeSet       |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIODirModeGet           |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOPinIntCallbackInit   |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOPinIntEnable         |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinIntEnable        |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOPinIntDisable        |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinIntDisable       |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOPinIntStatus         |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOPinIntClear          |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinIntClear         |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOPinRead              |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinRead             |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOPinWrite             |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinWrite            |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOPinConfigure         |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinTypeGPIOInput    |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinTypeGPIOOutput   |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinTypeGPIOOutputOD |  Non-Mandatory |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xGPIOSPinTypeGPIOOutputQB |  Non-Mandatory |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeADC              |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeCAN              |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeI2C              |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeI2S              |  Non-Mandatory |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypePWM              |  Non-Mandatory |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeSPI              |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeTimer            |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeUART             |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeACMP             |    Mandatory   |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeCLKO             |  Non-Mandatory |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeEXTINT           |        N       |            Y           |
//! |--------------------------|----------------|------------------------|
//! |xSPinTypeEBI              |  Non-Mandatory |            Y           |
//! +--------------------------+----------------+------------------------+
//! \endverbatim
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Set the direction and mode of the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port
//! Details please refer to \ref xLowLayer_Peripheral_Memmap.
//! \param ulPins is the bit-packed representation of the pin(s).
//! Details please refer to \ref xGPIO_General_Pin_IDs.
//! \param ulPinIO is the pin direction and/or mode.
//! Details please refer to \ref xGPIO_Dir_Mode.
//!
//! This function will set the specified pin(s) on the selected GPIO port
//! as either an input or output under software control, or it will set the
//! pin to be under hardware control.
//!
//! The parameter \e ulPinIO is an enumerated data type that can be one of
//! the following values:
//! 
//! Details please refer to \ref xGPIO_Dir_Mode_CoX.
//!
//! Where \b xGPIO_DIR_MODE_IN specifies that the pin will be programmed as
//! a software controlled input, \b xGPIO_DIR_MODE_OUT specifies that the pin
//! will be programmed as a software controlled output, and
//! \b xGPIO_DIR_MODE_HW specifies that the pin will be placed under
//! hardware control.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//! 
//! Details please refer to \ref xGPIO_General_Pin_IDs_CoX.
//!
//! \note xGPIOPadConfigSet() must also be used to configure the corresponding
//! pad(s) in order for them to propagate the signal to/from the GPIO.
//!
//! \return None.
//
//*****************************************************************************
extern void xGPIODirModeSet(unsigned long ulPort, unsigned long ulPins,
                            unsigned long ulPinIO);   

//*****************************************************************************
//
//! \brief Get the GPIO port from a Pin.
//!
//! \param eShortPin is the base address of the GPIO port
//! 
//! \return GPIO port code which is used by \ref xSysCtlPeripheralEnable,
//! \ref xSysCtlPeripheralDisable, \ref xSysCtlPeripheralReset.
//! Details please refer to \ref xSysCtl_Peripheral_ID.
//
//*****************************************************************************
#define xGPIOSPinToPeripheralId(eShortPin)   // Nothing now..Functionality seems to be same as xGPIOSPinToPort()

//*****************************************************************************
//
//! \brief Get the GPIO port from a short Pin.
//!
//! \param eShortPin is the base address of the GPIO port
//!
//! \note None.
//! 
//! \return GPIO port address which is used by GPIO API.
//
//*****************************************************************************
#define xGPIOSPinToPort(eShortPin)		GPIOSPinToPort(eShortPin)


//*****************************************************************************
//
//! \brief Get the GPIO port and Pin number from a short Pin.
//!
//! \param eShortPin is the base address of the GPIO port
//!
//! \note None.
//! 
//! \return GPIO port address which is used by GPIO API.
//
//*****************************************************************************
#define xGPIOSPinToPortPin(eShortPin)	GPIOSPinToPortPin(eShortPin)
        
//*****************************************************************************
//
//! \brief Get the GPIO pin number from a short Pin.
//!
//! \param eShortPin is the base address of the GPIO port
//!
//! \note None.
//! 
//! \return GPIO pin number which is used by GPIO API.
//
//*****************************************************************************
#define xGPIOSPinToPin(eShortPin)		GPIOSPinToPin(eShortPin)

//*****************************************************************************
//
//! \brief Set the direction and mode of the specified pin(s).
//!
//! \param eShortPin Specified port and pin.
//! Details please refer to \ref xGPIO_Short_Pin.
//! \param ulPinIO is the pin direction and/or mode.
//! Details please refer to \ref xGPIO_Dir_Mode.
//!
//! This function will set the specified pin(s) on the selected GPIO port
//! as either an input or output under software control, or it will set the
//! pin to be under hardware control.
//!
//! The parameter \e ulPinIO is an enumerated data type that can be one of
//! the following values:
//!
//! Details please refer to \ref xGPIO_Dir_Mode_CoX.
//!
//! where \b xGPIO_DIR_MODE_IN specifies that the pin will be programmed as
//! a software controlled input, \b xGPIO_DIR_MODE_OUT specifies that the pin
//! will be programmed as a software controlled output, and
//! \b xGPIO_DIR_MODE_HW specifies that the pin will be placed under
//! hardware control.
//!
//! The pin is specified by eShortPin, which can only be one pin.
//! Details please refer to \ref xGPIO_Short_Pin_CoX.
//!
//! \note xGPIOPadConfigSet() must also be used to configure the corresponding
//! pad(s) in order for them to propagate the signal to/from the GPIO.
//!
//! \return None.
//
//*****************************************************************************
#define xGPIOSPinDirModeSet(eShortPin, ulPinIO)		xGPIOSDirModeSet(eShortPin, ulPinIO)

//*****************************************************************************
//
//! \brief Get the direction and mode of a pin.
//!
//! \param ulPort is the base address of the GPIO port
//! Details please refer to \ref xLowLayer_Peripheral_Memmap.
//! \param ulPin is the bit-packed representation of the pin.
//! Details please refer to \ref xGPIO_General_Pin_IDs.
//!
//! This function gets the direction and control mode for a specified pin on
//! the selected GPIO port.  The pin can be configured as either an input or
//! output under software control, or it can be under hardware control.  The
//! type of control and direction are returned as an enumerated data type.
//!
//! The pin are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//! 
//! Details please refer to \ref xGPIO_General_Pin_IDs_CoX.
//!
//! \return Returns one of the enumerated data types described for
//! \ref xGPIODirModeSet().Details please refer to \ref xGPIO_Dir_Mode_CoX.
//
//*****************************************************************************        
extern unsigned long xGPIODirModeGet(unsigned long ulPort, 
                                     unsigned long ulPin);

//*****************************************************************************
//
//! \brief Init the GPIO Port X Interrupt Callback function.
//!
//! \param ulPort is the base address of the GPIO port.
//! Details please refer to \ref xLowLayer_Peripheral_Memmap.
//! \param ulPin is the bit-packed representation of the pin.
//! Details please refer to \ref xGPIO_General_Pin_IDs.
//! \param pfnCallback is the callback function.
//! Details please refer to \ref xLowLayer_Exported_Types.
//!
//! When there is any pins interrupt occrus, Interrupt Handler will 
//! call the callback function. 
//! 
//! param of pfnCallback
//! - pvCBData not used, always 0.
//! - ulEvent not used, always 0.
//! - ulMsgParam is pins which have an event.
//! Details please refer to \ref xGPIO_General_Pin_IDs_CoX.
//! - pvMsgData not used, always 0.
//!
//! \return None.
//
//*****************************************************************************
//extern void xGPIOPinIntCallbackInit(unsigned long ulPort, unsigned long ulPin, xtEventCallback pfnCallback); //Enable when EIC is implemented
        
//*****************************************************************************
//
//! \brief Set the interrupt type and Enable interrupt for the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port
//! Details please refer to \ref xLowLayer_Peripheral_Memmap.
//! \param ulPins is the bit-packed representation of the pin(s).
//! Details please refer to \ref xGPIO_General_Pin_IDs.
//! \param ulIntType specifies the type of interrupt trigger mechanism.
//! Details please refer to \ref xGPIO_Int_Type.
//!
//! This function sets up the various interrupt trigger mechanisms for the
//! specified pin(s) on the selected GPIO port.
//!
//! The parameter \e ulIntType is an enumerated data type that can be one of
//! the following values:
//!
//! Details please refer to \ref xGPIO_Int_Type_CoX.
//!
//! Where the different values describe the interrupt detection mechanism
//! (edge or level) and the particular triggering event (falling, rising,
//! or both edges for edge detect, low or high for level detect).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//! 
//! Details please refer to \ref xGPIO_General_Pin_IDs_CoX.
//!
//! \note In order to avoid any spurious interrupts, the user must
//! ensure that the GPIO inputs remain stable for the duration of
//! this function.
//!
//! \return None.
//
//*****************************************************************************
extern void xGPIOPinIntEnable(unsigned long ulPort, unsigned long ulPins, 
                              unsigned long ulIntType);
         
//*****************************************************************************
//
//! \brief Set the interrupt type and Enable interrupt for the specified pin(s).
//!
//! \param eShortPin Specified port and pin.
//! Details please refer to \ref xGPIO_Short_Pin.
//! \param ulIntType specifies the type of interrupt trigger mechanism.
//! Details please refer to \ref xGPIO_Int_Type.
//!
//! This function sets up the various interrupt trigger mechanisms for the
//! specified pin(s) on the selected GPIO port.
//!
//! The parameter \e ulIntType is an enumerated data type that can be one of
//! the following values:
//!
//! Details please refer to \ref xGPIO_Int_Type_CoX.
//!
//! Where the different values describe the interrupt detection mechanism
//! (edge or level) and the particular triggering event (falling, rising,
//! or both edges for edge detect, low or high for level detect).
//!
//! The pin is specified by eShortPin, which can only be one pin.
//! Details please refer to \ref xGPIO_Short_Pin_CoX.
//!
//! \note In order to avoid any spurious interrupts, the user must
//! ensure that the GPIO inputs remain stable for the duration of
//! this function.
//!
//! \return None.
//
//*****************************************************************************
#define xGPIOSPinIntEnable(eShortPin, ulIntType)

//*****************************************************************************
//
//! \brief Disables interrupts for the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port
//! Details please refer to \ref xLowLayer_Peripheral_Memmap.
//! \param ulPins is the bit-packed representation of the pin(s).
//! Details please refer to \ref xGPIO_General_Pin_IDs.
//!
//! Mask the interrupt for the specified pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! Details please refer to \ref xGPIO_General_Pin_IDs_CoX.
//!
//! \return None.
//
//*****************************************************************************       
extern void xGPIOPinIntDisable(unsigned long ulPort, unsigned long ulPins);

//*****************************************************************************
//
//! \brief Disables interrupts for the specified pin.
//!
//! \param eShortPin Specified port and pin.
//! Details please refer to \ref xGPIO_Short_Pin.
//!
//! Mask the interrupt for the specified pin(s).
//!
//! The pin is specified by eShortPin, which can only be one pin.
//! Details please refer to \ref xGPIO_Short_Pin_CoX.
//!
//! \return None.
//
//*****************************************************************************       
#define xGPIOSPinIntDisable(eShortPin)

//*****************************************************************************
//
//! \brief Get interrupt status for the specified GPIO port.
//!
//! \param ulPort is the base address of the GPIO port.
//! Details please refer to \ref xLowLayer_Peripheral_Memmap.
//! 
//! \return Returns a bit-packed byte, where each bit that is set identifies
//! an active masked or raw interrupt, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//! Bits 31:16 should be ignored.
//
//*****************************************************************************
extern void xGPIOPinIntStatus(unsigned long ulPort);  

//*****************************************************************************
//
//! \brief Clear the interrupt for the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port
//! Details please refer to \ref xLowLayer_Peripheral_Memmap.
//! \param ulPins is the bit-packed representation of the pin(s).
//! Details please refer to \ref xGPIO_General_Pin_IDs.
//!
//! Clear the interrupt for the specified pin(s).
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! Details please refer to \ref xGPIO_General_Pin_IDs_CoX.
//!
//! \note Because there is a write buffer in the Cortex-M0 processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared.  Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \return None.
//
//*****************************************************************************
extern void xGPIOPinIntClear(unsigned long ulPort, unsigned long ulPins);

//*****************************************************************************
//
//! \brief Clear the interrupt for the specified pin.
//!
//! \param eShortPin Specified port and pin.
//! Details please refer to \ref xGPIO_Short_Pin.
//!
//! Clear the interrupt for the specified pin.
//!
//! The pin is specified by eShortPin, which can only be one pin.
//! Details please refer to \ref xGPIO_Short_Pin_CoX.
//!
//! \note Because there is a write buffer in the Cortex-M0 processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared.  Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \return None.
//
//*****************************************************************************
#define xGPIOSPinIntClear(eShortPin)

//*****************************************************************************
//
//! \brief Reads the values present of the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port
//! Details please refer to \ref xLowLayer_Peripheral_Memmap.
//! \param ulPins is the bit-packed representation of the pin(s).
//! Details please refer to \ref xGPIO_General_Pin_IDs.
//!
//! The values at the specified pin(s) are read, as specified by \e ucPins.
//! Values are returned for both input and output pin(s), and the value
//! for pin(s) that are not specified by \e ucPins are set to 0.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! Details please refer to \ref xGPIO_General_Pin_IDs_CoX.
//!
//! \return Returns a bit-packed byte providing the state of the specified
//! pin, where bit 0 of the byte represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, and so on.  Any bit that is not specified by \e ucPins
//! is returned as a 0.  Bits 31:8 should be ignored.
//
//*****************************************************************************
extern long xGPIOPinRead(unsigned long ulPort, unsigned long ulPins);


//*****************************************************************************
//
//! \brief Reads the values present of the specified pin.
//!
//! \param eShortPin Specified port and pin.
//! Details please refer to \ref xGPIO_Short_Pin.
//!
//! The values at the specified pin are read, as specified by \e eShortPin.
//! Values are returned for both input and output pin(s), and the value
//! for pin(s) that are not specified by \e eShortPin are set to 0.
//!
//! The pin is specified by eShortPin, which can only be one pin.
//! Details please refer to \ref xGPIO_Short_Pin_CoX.
//!
//! \return Returns the value of specified port and pin.
//
//*****************************************************************************
#define xGPIOSPinRead(eShortPin)	GPIOSPinRead(eShortPin)

//*****************************************************************************
//
//! \brief Write a value to the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port
//! Details please refer to \ref xLowLayer_Peripheral_Memmap.
//! \param ulPins is the bit-packed representation of the pin(s).
//! Details please refer to \ref xGPIO_General_Pin_IDs.
//! \param ucVal is the value to write to the pin(s), 0 or 1.
//!
//! Write the corresponding bit values to the output pin(s) specified by
//! \e ucPins.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! Details please refer to \ref xGPIO_General_Pin_IDs_CoX.
//!
//! \return None.
//
//*****************************************************************************
extern void xGPIOPinWrite(unsigned long ulPort, unsigned long ulPins, 
                          unsigned char ucVal);

//*****************************************************************************
//
//! \brief Write a value to the specified pin.
//!
//! \param eShortPin Specified port and pin.
//! Details please refer to \ref xGPIO_Short_Pin.
//! \param ucVal is the value to write to the pin(s), 0 or 1.
//!
//! Write the corresponding bit values to the output pin specified by
//! \e eShortPin.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin is specified by eShortPin, which can only be one pin.
//! Details please refer to \ref xGPIO_Short_Pin_CoX.
//!
//! \return None.
//
//*****************************************************************************
#define xGPIOSPinWrite(eShortPin, ucVal)  GPIOSPinWrite(eShortPin, ucVal)

//*****************************************************************************
//
//! \brief Configure the alternate function of a GPIO pin.
//!
//! \param ulPinConfig is the pin configuration value, specified as only one of
//! the \b GPIO_P??_??? values.
//!
//! This function configures the pin mux that selects the peripheral function
//! associated with a particular GPIO pin.  Only one peripheral function at a
//! time can be associated with a GPIO pin, and each peripheral function should
//! only be associated with a single GPIO pin at a time (despite the fact that
//! many of them can be associated with more than one GPIO pin).
//!
//! \note This function is only valid on Tempest-class devices.
//!
//! \return None.
//
//*****************************************************************************        
#define xGPIOPinConfigure(eShortPin, ulPinConfig)	GPIOSPinConfigure(eShortPin, ulPinConfig)



//*****************************************************************************
//
//! \brief Turn a pin to a GPIO Input pin.
//!
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin.
//!
//! This function configures a pin for use as an GPIO Input pin device and turns 
//! the pin into a GPIO input pin.
//!
//! \return None.
//
//*****************************************************************************
#define xGPIOSPinTypeGPIOInput(eShortPin) xGPIODirModeSet(G##eShortPin, xGPIO_DIR_MODE_IN)

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO Output(push-pull) pin.
//!
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin.
//!
//! This function configures a pin for use as an GPIO Output pin device and  
//! turns the pin into a GPIO Output pin.
//!
//! \return None.
//
//*****************************************************************************
#define xGPIOSPinTypeGPIOOutput(eShortPin) xGPIODirModeSet(G##eShortPin, xGPIO_DIR_MODE_OUT)
            
//*****************************************************************************
//
//! \brief Turn a pin to a GPIO Output(open drain) pin.
//!
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin.
//!
//! This function configures a pin for use as an GPIO Output pin device and turns 
//! the pin into a GPIO Output(open drain) pin.
//!
//! \return None.
//
//*****************************************************************************
#define xGPIOSPinTypeGPIOOutputOD(eShortPin)

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO Output(oQuasi-bidirectional) pin.
//!
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin.
//!
//! This function configures a pin for use as an GPIO Output pin device and turns 
//!  the pin into a GPIO Output(Quasi-bidirectional) pin.
//!
//! \return None.
//
//*****************************************************************************
#define xGPIOSPinTypeGPIOOutputQB(eShortPin) 

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO ADC input pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as ADC0. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin.
//!
//! This function configures a pin for use as an ADC function device and turns 
//! the pin into a GPIO ADC input pin.
//!
//! Table shows what the ePeripheralPin and eShortPin should be, only the 
//! argument which are in the same line can be combined. For eaxmple(TI):<br/>
//! xSPinTypeADC(ADC0, PE7) or xSPinTypeADC(ADC1, PE6) is correct;<br/>
//! But xSPinTypeADC(ADC0, PE6) or xSPinTypeADC(ADC0, PE5) is error.
//! \verbatim
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: ADCn         |should be: PXn          |
//! |                    |n indicate the pin      |XX indicate the GPIO    |
//! |                    |number such as          |PORT,Such as            |
//! |                    |0 1 2 3 ....            |A B C D E ...           |
//! |                    |                        |n indicate the pin      |
//! |                    |                        |number such as          |
//! |                    |                        |0 1 2 3 ....            |
//! |--------------------|------------------------|------------------------|
//! |       SAMD2x       |                    |                     |
//! |                    |                    |                     |
//! |                    |                    |                     |
//! |                    |                    |                     |
//! |                    |                    |                     |
//! |                    |                    |                     |
//! |                    |                    |                     |
//! |                    |                    |                     |
//! |--------------------|------------------------|------------------------|
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************            
#define xSPinTypeADC(ePeripheralPin, eShortPin)	GPIOSPinConfigure(ePeripheralPin, eShortPin) 

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO CAN input or output pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as CAN0RX. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin. 
//!
//! This function configures a pin for use as a CAN function and turns 
//! the pin into a GPIO CAN input or output pin.
//!
//! Table shows what the ePeripheralPin and eShortPin should be,only the 
//! argument which are in the same line can be combined.For eaxmple(TI):<br/>
//! xSPinTypeCAN(CAN0RX, PA4) or xSPinTypeCAN(CAN0RX, PB4) is correct;<br/>
//! But xSPinTypeCAN(CAN0RX, PA5) or xSPinTypeCAN(CAN0RX, PF0) is error.
//! \verbatim
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: CANnRX       |should be: PXn          |
//! |                    |or CANnTX               |XX indicate the GPIO    |
//! |                    |n indicate the pin      |PORT,Such as            |
//! |                    |number such as          |A B C D E ...           |
//! |                    |0 1 2 3 ....            |n indicate the pin      |
//! |                    |                        |number such as          |
//! |                    |                        |0 1 2 3 ....            |
//! |--------------------|------------------------|------------------------|
//! |       SAMD2x       |                  |                     |
//! |                    |                  |                     |
//! |--------------------|------------------------|------------------------|
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************             
#define xSPinTypeCAN(ePeripheralPin, eShortPin) 

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO I2C input or output pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin.  
//!
//! This function configures a pin for use as an I2C function device and turns 
//! the pin into a GPIO I2C input or output pin.
//!
//! Table shows what the ePeripheralPin and eShortPin should be,only the 
//! argument which are in the same line can be combined.For eaxmple(TI):<br/>
//! xSPinTypeI2C(CAN0RX, PA4) or xSPinTypeI2C(CAN0RX, PB4) is correct;<br/>
//! But xSPinTypeI2C(CAN0RX, PA5) or xSPinTypeI2C(CAN0RX, PF0) is error.
//! \verbatim
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: I2CnSCK      |should be: PXn          |
//! |                    |or I2CnSDA              |XX indicate the GPIO    |
//! |                    |n indicate the pin      |PORT,Such as            |
//! |                    |number such as          |A B C D E ...           |
//! |                    |0 1 2 3 ....            |n indicate the pin      |
//! |                    |                        |number such as          |
//! |                    |                        |0 1 2 3 ....            |
//! |--------------------|------------------------|------------------------|
//! |       SAMD2x       |    I2C0SCK             |                     |
//! |                    |    I2C0SDA             |                     |
//! |                    |    I2C1SCK             |                    |
//! |                    |    I2C1SDA             |                    |
//! |--------------------|------------------------|------------------------|
//! \endverbatim
//!
//! \return None.
//
//***************************************************************************** 
 #define xSPinTypeI2C(ePeripheralPin, eShortPin) GPIOSPinConfigure(ePeripheralPin, eShortPin)

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO I2S input or output pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin. 
//!
//! This function configures a pin for use as an I2S function device and turns 
//!  the pin into a GPIO I2S input or output pin.
//!
//! Table shows what the ePeripheralPin and eShortPin should be,only the 
//! argument which are in the same line can be combined.For eaxmple(TI):<br/>
//! xSPinTypeI2S(I2S0RXSD, PA2) or xSPinTypeI2S(I2S0RXSD, PD4) is correct;<br/>
//! But xSPinTypeI2S(I2S0RXSD, PD1) or xSPinTypeI2S(I2S0RXWS, PA2) is error.
//! \verbatim
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: I2SnRXSCK,   |should be: PXn          |
//! |                    |I2SnRXMCLK,I2S0RXSD,    |XX indicate the GPIO    |
//! |                    |I2S0RXWS,I2S0TXSCK,     |PORT,Such as            |
//! |                    |I2S0TXMCLK,I2S0TXSD,    |A B C D E ...           |
//! |                    |or I2S0TXWS.            |n indicate the pin      |
//! |                    |n indicate the pin      |number such as          |
//! |                    |number such as          |0 1 2 3 ....            |
//! |                    |0 1 2 3 ....            |                        |
//! |--------------------|------------------------|------------------------|
//! |       SAMD2x       |              |                    |
//! |                    |              |                     |
//! |                    |                |                     |
//! |                    |                |                     |
//! |                    |             |                    |
//! |                    |               |                     |
//! |                    |                |                     |
//! |                    |                |                     |
//! |--------------------|------------------------|------------------------|
//! \endverbatim
//!
//! \return None.
//
//***************************************************************************** 
#define xSPinTypeI2S(ePeripheralPin, eShortPin) 

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO PWM input or output pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin. 
//!
//! This function configures a pin for use as a PWM function and turns 
//!  the pin into a GPIO PWM input or output pin.
//!
//! Table shows what the ePeripheralPin and eShortPin should be,only the 
//! argument which are in the same line can be combined.For eaxmple(TI):<br/>
//! xSPinTypePWM(PWM0, PD0) or xSPinTypePWM(PWM0, PJ0) is correct;<br/>
//! But xSPinTypePWM(PWM0, PD1) or xSPinTypePWM(PWM0, PD2) is error.
//! \verbatim
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: PWMn,        |should be: PXn          |
//! |                    |n indicate the pin      |XX indicate the GPIO    |
//! |                    |number such as          |PORT,Such as            |
//! |                    |0 1 2 3 ....            |A B C D E ...           |
//! |                    |                        |n indicate the pin      |
//! |                    |                        |number such as          |
//! |                    |                        |0 1 2 3 ....            |
//! |--------------------|------------------------|------------------------|
//! |       SAMD2x       |                    |                    |
//! |                    |                    |                    |
//! |                    |                    |                    |
//! |                    |                    |                    |
//! |                    |                    |                    |
//! |                    |                    |                    |
//! |                    |                    |                    |
//! |                    |                    |                    |
//! |--------------------|------------------------|------------------------|
//! \endverbatim
//!
//! \return None.
//
//***************************************************************************** 
#define xSPinTypePWM(ePeripheralPin, eShortPin)

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO SPI input or output pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin.
//!
//! This function configures a pin for use as a SPI function and turns 
//!  the pin into a GPIO SPI input or output pin.
//!
//! Table shows what the ePeripheralPin and eShortPin should be,only the 
//! argument which are in the same line can be combined.For eaxmple(TI):<br/>
//! xSPinTypeSPI(SPI0CLK, PA2) or xSPinTypeSPI(SPI0MOSI, PA5) is correct;<br/>
//! But xSPinTypeSPI(SPI0CLK, PA5) or xSPinTypeSPI(SPI0CLK, PA4) is error.
//! \verbatim
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: SPInCLK,     |should be: PXn          |
//! |                    |SPInMISO, SPInMOSI,     |XX indicate the GPIO    |
//! |                    |or SPInCS,              |PORT,Such as            |
//! |                    |n indicate the pin      |A B C D E ...           |
//! |                    |number such as          |n indicate the pin      |
//! |                    |0 1 2 3 ....            |number such as          |
//! |                    |                        |0 1 2 3 ....            |
//! |--------------------|------------------------|------------------------|
//! |       SAMD2x       |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |                    |                |               |
//! |--------------------|------------------------|------------------------|
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************
#define xSPinTypeSPI(ePeripheralPin, eShortPin) GPIOSPinConfigure(ePeripheralPin, eShortPin)

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO Timer input or output pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin. 
//!
//! This function configures a pin for use as a Timer function and turns 
//!  the pin into a GPIO Timer input or output pin.
//!
//! Table shows what the ePeripheralPin and eShortPin should be,only the 
//! argument which are in the same line can be combined.For eaxmple(TI):<br/>
//! xSPinTypeTimer(TIMCCP0, PD3) or xSPinTypeTimer(TIMCCP0, PJ7) is correct;<br/>
//! But xSPinTypeTimer(TIMCCP0, PC5) or xSPinTypeTimer(TIMCCP0, PB6) is error.
//! \verbatim
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: TIMCCPn,     |should be: PXn          |
//! |                    |n indicate the pin      |XX indicate the GPIO    |
//! |                    |number such as          |PORT,Such as            |
//! |                    |0 1 2 3 ....            |A B C D E ...           |
//! |                    |                        |n indicate the pin      |
//! |                    |                        |number such as          |
//! |                    |                        |0 1 2 3 ....            |
//! |--------------------|------------------------|------------------------|
//! |       SAMD2x       |                 |                     |
//! |                    |                 |                     |
//! |                    |                 |                    |
//! |                    |                 |                    |
//! |--------------------|------------------------|------------------------|
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************            
#define xSPinTypeTimer(ePeripheralPin, eShortPin) 

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO UART input or output pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin. 
//!
//! This function configures a pin for use as a UART function and turns 
//!  the pin into a GPIO UART input or output pin.
//!
//! Table shows what the ePeripheralPin and eShortPin should be,only the 
//! argument which are in the same line can be combined.For eaxmple(TI):<br/>
//! xSPinTypeUART(UART0RX, PA0) or xSPinTypeUART(UART0TX, PA1) is correct;<br/>
//! But xSPinTypeUART(UART0RX, PA1) or xSPinTypeUART(UART0RX, PE6) is error.
//! \verbatim
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: UARTnRX,     |should be: PXn          |
//! |                    |UARTnTX, UARTnCTS,      |XX indicate the GPIO    |
//! |                    |......,                 |PORT,Such as            |
//! |                    |n indicate the pin      |A B C D E ...           |
//! |                    |number such as          |n indicate the pin      |
//! |                    |0 1 2 3 ....            |number such as          |
//! |                    |                        |0 1 2 3 ....            |
//! |--------------------|------------------------|------------------------|
//! |		SAMD2x		 |                |                    |
//! |                    |                |                    |
//! |                    |                |                    |
//! |                    |                |                    |
//! |                    |                |                    |
//! |                    |                |                    |
//! |                    |                |                    |
//! |                    |                |                    |
//! |                    |                |                    |
//! |                    |                |                    |
//! |--------------------|------------------------|------------------------|
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************
#define xSPinTypeUART(ePeripheralPin, eShortPin)	GPIOSPinConfigure(ePeripheralPin, eShortPin)

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO ACMP input or output pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin. 
//!
//! This function configures a pin for use as an ACMP function and turns 
//!  the pin into a GPIO ACMP input or output pin.
//!
//! \verbatim
//! +--------------------+------------------------+------------------------+
//! |    manufacturer    |ePeripheralPin          |eShortPin               |
//! |--------------------|------------------------|------------------------|
//! |    CoX             |This parameter is a     |This parameter is a     |
//! |                    |mandatory.The mandatory |mandatory. the mandatory|
//! |                    |is the format of        |is the format of        |
//! |                    |Variable naming.So it   |Variable naming.So it   |
//! |                    |should be: CMPnN,       |should be: PXn          |
//! |                    |CMPnO or CMPnP          |XX indicate the GPIO    |
//! |                    |n indicate the pin      |PORT,Such as            |
//! |                    |number such as          |A B C D E ...           |
//! |                    |0 1 2 3 ....            |n indicate the pin      |
//! |                    |                        |number such as          |
//! |                    |                        |0 1 2 3 ....            |
//! |--------------------|------------------------|------------------------|
//! |       SAMD2x       |                   |                    |
//! |                    |                   |                    |
//! |                    |                   |                    |
//! |                    |                   |                    |
//! |                    |                   |                    |
//! |                    |                   |                    |
//! |--------------------|------------------------|------------------------|
//! \endverbatim
//!
//! \return None.
//
//*****************************************************************************            
#define xSPinTypeACMP(ePeripheralPin, eShortPin) 

//*****************************************************************************
//
//! \brief Turn a pin to a GPIO CLKO output pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin. 
//!
//! This function configures a pin for use as a CLKO function and turns 
//!  the pin into a GPIO CLKO output pin.
//!
//! \return None.
//
//*****************************************************************************
#define xSPinTypeCLKO(ePeripheralPin, eShortPin)
            
//*****************************************************************************
//
//! \brief Turn a pin to a GPIO external interrupt pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin. 
//!
//! This function configures a pin for use as an GPIO interrupt function and  
//! turns the pin into a GPIO external interrupt pin.
//!
//! \return None.
//
//*****************************************************************************
#define xSPinTypeEXTINT(ePeripheralPin, eShortPin) GPIOSPinConfigure(ePeripheralPin, eShortPin)
            
//*****************************************************************************
//
//! \brief Turn a pin to a GPIO EBI pin.
//!
//! \param ePeripheralPin is the GPIO Peripheral name such as I2C0SDA. 
//! Details please refer to \ref xGPIO_Pin_Config.
//! \param eShortPin is the GPIO short pin name such as PA0. 
//! Details please refer to \ref xGPIO_Short_Pin. 
//!
//! This function configures a pin for use as an GPIO EBI function and  
//! turns the pin into a GPIO EBI pin.
//!
//! \return None.
//
//*****************************************************************************
#define xSPinTypeEBI(ePeripheralPin, eShortPin)


//*****************************************************************************
//
//! \addtogroup SAMD2x_GPIO_General_Pin_IDs SAMD2x GPIO General Pin ID
//! \brief The following values define the bit field for the ucPins argument
//! to several of the APIs.
//! @{
//
//*****************************************************************************

//
//! GPIO pin 0
//
#define GPIO_PIN_0              0x00000001

//
//! GPIO pin 1
//
#define GPIO_PIN_1              0x00000002

//
//! GPIO pin 2
//
#define GPIO_PIN_2              0x00000004

//
//! GPIO pin 3
//
#define GPIO_PIN_3              0x00000008

//
//! GPIO pin 4
//
#define GPIO_PIN_4              0x00000010

//
//! GPIO pin 5
//
#define GPIO_PIN_5              0x00000020

//
//! GPIO pin 6
//
#define GPIO_PIN_6              0x00000040

//
//! GPIO pin 7
//
#define GPIO_PIN_7              0x00000080

//
//! GPIO pin 8
//
#define GPIO_PIN_8              0x00000100

//
//! GPIO pin 9
//
#define GPIO_PIN_9              0x00000200

//
//! GPIO pin 10
//
#define GPIO_PIN_10             0x00000400

//
//! GPIO pin 11
//
#define GPIO_PIN_11             0x00000800

//
//! GPIO pin 12
//
#define GPIO_PIN_12             0x00001000

//
//! GPIO pin 13
//
#define GPIO_PIN_13             0x00002000

//
//! GPIO pin 14
//
#define GPIO_PIN_14             0x00004000

//
//! GPIO pin 15
//
#define GPIO_PIN_15             0x00008000

//
//! GPIO pin 16
//
#define GPIO_PIN_16             0x00010000

//
//! GPIO pin 17
//
#define GPIO_PIN_17             0x00020000

//
//! GPIO pin 18
//
#define GPIO_PIN_18             0x00040000

//
//! GPIO pin 19
//
#define GPIO_PIN_19             0x00080000

//
//! GPIO pin 20
//
#define GPIO_PIN_20             0x00100000

//
//! GPIO pin 21
//
#define GPIO_PIN_21             0x00200000

//
//! GPIO pin 22
//
#define GPIO_PIN_22             0x00400000

//
//! GPIO pin 23
//
#define GPIO_PIN_23             0x00800000

//
//! GPIO pin 24
//
#define GPIO_PIN_24             0x01000000

//
//! GPIO pin 25
//
#define GPIO_PIN_25             0x02000000

//
//! GPIO pin 26
//
#define GPIO_PIN_26             0x04000000

//
//! GPIO pin 27
//
#define GPIO_PIN_27             0x08000000

//
//! GPIO pin 28
//
#define GPIO_PIN_28             0x10000000

//
//! GPIO pin 29
//
#define GPIO_PIN_29             0x20000000

//
//! GPIO pin 30
//
#define GPIO_PIN_30             0x40000000

//
//! GPIO pin 31
//
#define GPIO_PIN_31             0x80000000

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup SAMD2x_GPIO_General_Pin_Bits SAMD2x GPIO General Pin Bits
//! \brief The following values define the bit field for the ucBit argument to
//! GPIODirModeSet() API.
//! @{
//
//*****************************************************************************

//
//! GPIO BIT 0
//
#define GPIO_BIT_0              0x00000000

//
//! GPIO BIT 1
//
#define GPIO_BIT_1              0x00000001

//
//! GPIO BIT 2
//
#define GPIO_BIT_2              0x00000002

//
//! GPIO BIT 3
//
#define GPIO_BIT_3              0x00000003

//
//! GPIO BIT 4
//
#define GPIO_BIT_4              0x00000004

//
//! GPIO BIT 5
//
#define GPIO_BIT_5              0x00000005

//
//! GPIO BIT 6
//
#define GPIO_BIT_6              0x00000006

//
//! GPIO BIT 7
//
#define GPIO_BIT_7              0x00000007

//
//! GPIO BIT 8
//
#define GPIO_BIT_8              0x00000008

//
//! GPIO BIT 9
//
#define GPIO_BIT_9              0x00000009

//
//! GPIO BIT 10
//
#define GPIO_BIT_10             0x0000000A

//
//! GPIO BIT 11
//
#define GPIO_BIT_11             0x0000000B

//
//! GPIO BIT 12
//
#define GPIO_BIT_12             0x0000000C

//
//! GPIO BIT 13
//
#define GPIO_BIT_13             0x0000000D

//
//! GPIO BIT 14
//
#define GPIO_BIT_14             0x0000000E

//
//! GPIO BIT 15
//
#define GPIO_BIT_15             0x0000000F

//
//! GPIO BIT 16
//
#define GPIO_BIT_16             0x00000010

//
//! GPIO BIT 17
//
#define GPIO_BIT_17             0x00000011

//
//! GPIO BIT 18
//
#define GPIO_BIT_18             0x00000012

//
//! GPIO BIT 19
//
#define GPIO_BIT_19             0x00000013

//
//! GPIO BIT 20
//
#define GPIO_BIT_20             0x00000014

//
//! GPIO BIT 21
//
#define GPIO_BIT_21             0x00000015

//
//! GPIO BIT 22
//
#define GPIO_BIT_22             0x00000016

//
//! GPIO BIT 23
//
#define GPIO_BIT_23             0x00000017

//
//! GPIO BIT 24
//
#define GPIO_BIT_24             0x00000018

//
//! GPIO BIT 25
//
#define GPIO_BIT_25             0x00000019

//
//! GPIO BIT 26
//
#define GPIO_BIT_26             0x0000001A

//
//! GPIO BIT 27
//
#define GPIO_BIT_27             0x0000001B

//
//! GPIO BIT 28
//
#define GPIO_BIT_28             0x0000001C

//
//! GPIO BIT 29
//
#define GPIO_BIT_29             0x0000001D

//
//! GPIO BIT 30
//
#define GPIO_BIT_30             0x0000001E

//
//! GPIO BIT 31
//
#define GPIO_BIT_31             0x0000001F

//*****************************************************************************
//
//! @} Brief GPIO API Reference
//
//*****************************************************************************

#define GPIOSPinToPort(eShortPin)						GPIOPinToPort(G##eShortPin)
#define GPIOSPinToPortPin(eShortPin)					G##eShortPin
#define GPIOSPinToPin(eShortPin)						GPIOPinToPin(G##eShortPin)
#define xGPIOSDirModeSet(eShortPin, ulPinIO)			xGPIODirModeSet(G##eShortPin, ulPinIO)
#define GPIOSPinRead(eShortPin)							(xGPIOPinRead(G##eShortPin) ? 1: 0)
#define GPIOSPinWrite(eShortPin, ucVal)					xGPIOPinWrite(G##eShortPin, ucVal)
#define GPIOSPinConfigure(eShortPin,ePeripheralPin)	GPIOPinConfigure(GPIO_##eShortPin##_##ePeripheralPin) //Eg:-xGPIOPinConfigure(PA0, EIC_EXTINT0) ->GPIOPinConfigure(GPIO_PA0_EIC_EXTINT0)



extern void GPIODirModeSet(unsigned long ulPort, unsigned long ulBit, unsigned long ulPinIO);
extern unsigned long GPIODirModeGet(unsigned long ulPort, unsigned long ulBit);

extern unsigned long  GPIOPinToPort(unsigned long ulPort, unsigned long ulPin);
extern unsigned long  GPIOPinToPin(unsigned long ulPort, unsigned long ulPin);
extern void	GPIOPinConfigure(unsigned long ulPinConfig);


/*Device specific APIs...*/
#define GPIOSPinToggleOutputLevel(eShortPin)					GPIOPinToggleOutputLevel(G##eShortPin)
void GPIOPinToggleOutputLevel(unsigned long ulPort, unsigned long ulPin);
void GPIOPinInputPullConfigSet(unsigned long ulPort, unsigned long ulBit, unsigned long ulPull);
//*****************************************************************************
//
//! @\brief Values that can be passed to xGPIOPinConfigure as the ulPinConfig
//! parameter. Eg:-GPIOPinConfigure(GPIO_##eShortPin##_##ePeripheralPin) ->
//  GPIOPinConfigure(GPIO_##PA00##_##EIC_EXTINT0)
//  Below calculation takes these parameters:-(port group << 12|pin << 4|mux function) 
//*****************************************************************************
#define GPIO_PA0_EIC_EXTINT0		   ((0	<<	12)	|(0	<<	4)	|0)
#define GPIO_PA0_SERCOM1_PAD0		   ((0	<<	12)	|(0	<<	4)	|3)
#define GPIO_PA0_TC2_WO0			   ((0	<<	12)	|(0	<<	4)	|5)
#define GPIO_PA1_EIC_EXTINT1		   ((0	<<	12)	|(1	<<	4)	|0)
#define GPIO_PA1_SERCOM1_PAD1		   ((0	<<	12)	|(1	<<	4)	|3)
#define GPIO_PA1_TC2_WO1			   ((0	<<	12)	|(1	<<	4)	|5)
#define GPIO_PA2_EIC_EXTINT2		   ((0	<<	12)	|(2	<<	4)	|0)
#define GPIO_PA2_ADC_AIN0			   ((0	<<	12)	|(2	<<	4)	|1)
#define GPIO_PA2_DAC_VOUT			   ((0	<<	12)	|(2	<<	4)	|1)
#define GPIO_PA3_EIC_EXTINT3		   ((0	<<	12)	|(3	<<	4)	|0)
#define GPIO_PA3_ADC_AIN1			   ((0	<<	12)	|(3	<<	4)	|1)
#define GPIO_PA3_DAC_VREFP			   ((0	<<	12)	|(3	<<	4)	|1)
#define GPIO_PA4_EIC_EXTINT4		   ((0	<<	12)	|(4	<<	4)	|0)
#define GPIO_PA4_AC_AIN0			   ((0	<<	12)	|(4	<<	4)	|1)
#define GPIO_PA4_ADC_AIN4			   ((0	<<	12)	|(4	<<	4)	|1)
#define GPIO_PA4_ADC_VREFP			   ((0	<<	12)	|(4	<<	4)	|1)
#define GPIO_PA4_SERCOM0_PAD0		   ((0	<<	12)	|(4	<<	4)	|3)
#define GPIO_PA4_TC0_WO0			   ((0	<<	12)	|(4	<<	4)	|5)
#define GPIO_PA5_EIC_EXTINT5		   ((0	<<	12)	|(5	<<	4)	|0)
#define GPIO_PA5_AC_AIN1			   ((0	<<	12)	|(5	<<	4)	|1)
#define GPIO_PA5_ADC_AIN5			   ((0	<<	12)	|(5	<<	4)	|1)
#define GPIO_PA5_SERCOM0_PAD1		   ((0	<<	12)	|(5	<<	4)	|3)
#define GPIO_PA5_TC0_WO1			   ((0	<<	12)	|(5	<<	4)	|5)
#define GPIO_PA6_EIC_EXTINT6		   ((0	<<	12)	|(6	<<	4)	|0)
#define GPIO_PA6_AC_AIN2			   ((0	<<	12)	|(6	<<	4)	|1)
#define GPIO_PA6_ADC_AIN6			   ((0	<<	12)	|(6	<<	4)	|1)
#define GPIO_PA6_SERCOM0_PAD2		   ((0	<<	12)	|(6	<<	4)	|3)
#define GPIO_PA6_TC1_WO0			   ((0	<<	12)	|(6	<<	4)	|5)
#define GPIO_PA7_EIC_EXTINT7		   ((0	<<	12)	|(7	<<	4)	|0)
#define GPIO_PA7_AC_AIN3			   ((0	<<	12)	|(7	<<	4)	|1)
#define GPIO_PA7_ADC_AIN7			   ((0	<<	12)	|(7	<<	4)	|1)
#define GPIO_PA7_SERCOM0_PAD3		   ((0	<<	12)	|(7	<<	4)	|3)
#define GPIO_PA7_TC1_WO1			   ((0	<<	12)	|(7	<<	4)	|5)
#define GPIO_PA8_EIC_NMI			   ((0	<<	12)	|(8	<<	4)	|0)
#define GPIO_PA8_ADC_AIN16			   ((0	<<	12)	|(8	<<	4)	|1)
#define GPIO_PA8_SERCOM0_PAD0		   ((0	<<	12)	|(8	<<	4)	|2)
#define GPIO_PA8_SERCOM2_PAD0		   ((0	<<	12)	|(8	<<	4)	|3)
#define GPIO_PA8_TC0_WO0			   ((0	<<	12)	|(8	<<	4)	|4)
#define GPIO_PA9_EIC_EXTINT9		   ((0	<<	12)	|(9	<<	4)	|0)
#define GPIO_PA9_ADC_AIN17			   ((0	<<	12)	|(9	<<	4)	|1)
#define GPIO_PA9_SERCOM0_PAD1		   ((0	<<	12)	|(9	<<	4)	|2)
#define GPIO_PA9_SERCOM2_PAD1		   ((0	<<	12)	|(9	<<	4)	|3)
#define GPIO_PA9_TC0_WO1			   ((0	<<	12)	|(9	<<	4)	|4)
#define GPIO_PA10_EIC_EXTINT10		   ((0	<<	12)	|(10 <<	4)	|0)
#define GPIO_PA10_ADC_AIN18			   ((0	<<	12)	|(10 <<	4)	|1)
#define GPIO_PA10_SERCOM0_PAD2		   ((0	<<	12)	|(10 <<	4)	|2)
#define GPIO_PA10_SERCOM2_PAD2		   ((0	<<	12)	|(10 <<	4)	|3)
#define GPIO_PA10_TC1_WO0			   ((0	<<	12)	|(10 <<	4)	|4)
#define GPIO_PA10_GCLK_IO4			   ((0	<<	12)	|(10 <<	4)	|7)
#define GPIO_PA11_EIC_EXTINT11		   ((0	<<	12)	|(11 <<	4)	|0)
#define GPIO_PA11_ADC_AIN19			   ((0	<<	12)	|(11 <<	4)	|1)
#define GPIO_PA11_SERCOM0_PAD3		   ((0	<<	12)	|(11 <<	4)	|2)
#define GPIO_PA11_SERCOM2_PAD3		   ((0	<<	12)	|(11 <<	4)	|3)
#define GPIO_PA11_TC1_WO1			   ((0	<<	12)	|(11 <<	4)	|4)
#define GPIO_PA11_GCLK_IO5			   ((0	<<	12)	|(11 <<	4)	|7)
#define GPIO_PA12_EIC_EXTINT12		   ((0	<<	12)	|(12 <<	4)	|0)
#define GPIO_PA12_SERCOM2_PAD0		   ((0	<<	12)	|(12 <<	4)	|2)
#define GPIO_PA12_SERCOM4_PAD0		   ((0	<<	12)	|(12 <<	4)	|3)
#define GPIO_PA12_TC2_WO0			   ((0	<<	12)	|(12 <<	4)	|4)
#define GPIO_PA12_AC_CMP0			   ((0	<<	12)	|(12 <<	4)	|7)
#define GPIO_PA13_EIC_EXTINT13		   ((0	<<	12)	|(13 <<	4)	|0)
#define GPIO_PA13_SERCOM2_PAD1		   ((0	<<	12)	|(13 <<	4)	|2)
#define GPIO_PA13_SERCOM4_PAD1		   ((0	<<	12)	|(13 <<	4)	|3)
#define GPIO_PA13_TC2_WO1			   ((0	<<	12)	|(13 <<	4)	|4)
#define GPIO_PA13_AC_CMP1			   ((0	<<	12)	|(13 <<	4)	|7)
#define GPIO_PA14_EIC_EXTINT14		   ((0	<<	12)	|(14 <<	4)	|0)
#define GPIO_PA14_SERCOM2_PAD2		   ((0	<<	12)	|(14 <<	4)	|2)
#define GPIO_PA14_SERCOM4_PAD2		   ((0	<<	12)	|(14 <<	4)	|3)
#define GPIO_PA14_TC3_WO0			   ((0	<<	12)	|(14 <<	4)	|4)
#define GPIO_PA14_GCLK_IO0			   ((0	<<	12)	|(14 <<	4)	|7)
#define GPIO_PA15_EIC_EXTINT15		   ((0	<<	12)	|(15 <<	4)	|0)
#define GPIO_PA15_SERCOM2_PAD3		   ((0	<<	12)	|(15 <<	4)	|2)
#define GPIO_PA15_SERCOM4_PAD3		   ((0	<<	12)	|(15 <<	4)	|3)
#define GPIO_PA15_TC3_WO1			   ((0	<<	12)	|(15 <<	4)	|4)
#define GPIO_PA15_GCLK_IO1			   ((0	<<	12)	|(15 <<	4)	|7)
#define GPIO_PA16_EIC_EXTINT0		   ((0	<<	12)	|(16 <<	4)	|0)
#define GPIO_PA16_SERCOM1_PAD0		   ((0	<<	12)	|(16 <<	4)	|2)
#define GPIO_PA16_SERCOM3_PAD0		   ((0	<<	12)	|(16 <<	4)	|3)
#define GPIO_PA16_TC2_WO0			   ((0	<<	12)	|(16 <<	4)	|5)
#define GPIO_PA16_GCLK_IO2			   ((0	<<	12)	|(16 <<	4)	|7)
#define GPIO_PA17_EIC_EXTINT1		   ((0	<<	12)	|(17 <<	4)	|0)
#define GPIO_PA17_SERCOM1_PAD1		   ((0	<<	12)	|(17 <<	4)	|2)
#define GPIO_PA17_SERCOM3_PAD1		   ((0	<<	12)	|(17 <<	4)	|3)
#define GPIO_PA17_TC2_WO1			   ((0	<<	12)	|(17 <<	4)	|5)
#define GPIO_PA17_GCLK_IO3			   ((0	<<	12)	|(17 <<	4)	|7)
#define GPIO_PA18_EIC_EXTINT2		   ((0	<<	12)	|(18 <<	4)	|0)
#define GPIO_PA18_SERCOM1_PAD2		   ((0	<<	12)	|(18 <<	4)	|2)
#define GPIO_PA18_SERCOM3_PAD2		   ((0	<<	12)	|(18 <<	4)	|3)
#define GPIO_PA18_TC3_WO0			   ((0	<<	12)	|(18 <<	4)	|5)
#define GPIO_PA18_AC_CMP0			   ((0	<<	12)	|(18 <<	4)	|7)
#define GPIO_PA19_EIC_EXTINT3		   ((0	<<	12)	|(19 <<	4)	|0)
#define GPIO_PA19_SERCOM1_PAD3		   ((0	<<	12)	|(19 <<	4)	|2)
#define GPIO_PA19_SERCOM3_PAD3		   ((0	<<	12)	|(19 <<	4)	|3)
#define GPIO_PA19_TC3_WO1			   ((0	<<	12)	|(19 <<	4)	|5)
#define GPIO_PA19_AC_CMP1			   ((0	<<	12)	|(19 <<	4)	|7)
#define GPIO_PA20_EIC_EXTINT4		   ((0	<<	12)	|(20 <<	4)	|0)
#define GPIO_PA20_SERCOM5_PAD2		   ((0	<<	12)	|(20 <<	4)	|2)
#define GPIO_PA20_SERCOM3_PAD2		   ((0	<<	12)	|(20 <<	4)	|3)
#define GPIO_PA20_TC7_WO0			   ((0	<<	12)	|(20 <<	4)	|4)
#define GPIO_PA20_GCLK_IO4			   ((0	<<	12)	|(20 <<	4)	|7)
#define GPIO_PA21_EIC_EXTINT5		   ((0	<<	12)	|(21 <<	4)	|0)
#define GPIO_PA21_SERCOM5_PAD3		   ((0	<<	12)	|(21 <<	4)	|2)
#define GPIO_PA21_SERCOM3_PAD3		   ((0	<<	12)	|(21 <<	4)	|3)
#define GPIO_PA21_TC7_WO1			   ((0	<<	12)	|(21 <<	4)	|4)
#define GPIO_PA21_GCLK_IO5			   ((0	<<	12)	|(21 <<	4)	|7)
#define GPIO_PA22_EIC_EXTINT6		   ((0	<<	12)	|(22 <<	4)	|0)
#define GPIO_PA22_SERCOM3_PAD0		   ((0	<<	12)	|(22 <<	4)	|2)
#define GPIO_PA22_SERCOM5_PAD0		   ((0	<<	12)	|(22 <<	4)	|3)
#define GPIO_PA22_TC4_WO0			   ((0	<<	12)	|(22 <<	4)	|5)
#define GPIO_PA22_GCLK_IO6			   ((0	<<	12)	|(22 <<	4)	|7)
#define GPIO_PA23_EIC_EXTINT7		   ((0	<<	12)	|(23 <<	4)	|0)
#define GPIO_PA23_SERCOM3_PAD1		   ((0	<<	12)	|(23 <<	4)	|2)
#define GPIO_PA23_SERCOM5_PAD1		   ((0	<<	12)	|(23 <<	4)	|3)
#define GPIO_PA23_TC4_WO1			   ((0	<<	12)	|(23 <<	4)	|5)
#define GPIO_PA23_GCLK_IO7			   ((0	<<	12)	|(23 <<	4)	|7)
#define GPIO_PA24_EIC_EXTINT12		   ((0	<<	12)	|(24 <<	4)	|0)
#define GPIO_PA24_SERCOM3_PAD2		   ((0	<<	12)	|(24 <<	4)	|2)
#define GPIO_PA24_SERCOM5_PAD2		   ((0	<<	12)	|(24 <<	4)	|3)
#define GPIO_PA24_TC5_WO0			   ((0	<<	12)	|(24 <<	4)	|5)
#define GPIO_PA25_EIC_EXTINT13		   ((0	<<	12)	|(25 <<	4)	|0)
#define GPIO_PA25_SERCOM3_PAD3		   ((0	<<	12)	|(25 <<	4)	|2)
#define GPIO_PA25_SERCOM5_PAD3		   ((0	<<	12)	|(25 <<	4)	|3)
#define GPIO_PA25_TC5_WO1			   ((0	<<	12)	|(25 <<	4)	|5)
#define GPIO_PA27_EIC_EXTINT15		   ((0	<<	12)	|(27 <<	4)	|0)
#define GPIO_PA27_GCLK_IO0			   ((0	<<	12)	|(27 <<	4)	|7)
#define GPIO_PA28_EIC_EXTINT8		   ((0	<<	12)	|(28 <<	4)	|0)
#define GPIO_PA28_GCLK_IO0			   ((0	<<	12)	|(28 <<	4)	|7)
#define GPIO_PA30_EIC_EXTINT10		   ((0	<<	12)	|(30 <<	4)	|0)
#define GPIO_PA30_SERCOM1_PAD2		   ((0	<<	12)	|(30 <<	4)	|3)
#define GPIO_PA30_TC1_WO0			   ((0	<<	12)	|(30 <<	4)	|5)
#define GPIO_PA30_CORE_SWCLK		   ((0	<<	12)	|(30 <<	4)	|6)
#define GPIO_PA30_GCLK_IO0			   ((0	<<	12)	|(30 <<	4)	|7)
#define GPIO_PA31_EIC_EXTINT11		   ((0	<<	12)	|(31 <<	4)	|0)
#define GPIO_PA31_SERCOM1_PAD3		   ((0	<<	12)	|(31 <<	4)	|3)
#define GPIO_PA31_TC1_WO1			   ((0	<<	12)	|(31 <<	4)	|5)
#define GPIO_PB0_EIC_EXTINT0		   ((1	<<	12)	|(32 <<	4)	|0)
#define GPIO_PB0_ADC_AIN8			   ((1	<<	12)	|(32 <<	4)	|1)
#define GPIO_PB0_SERCOM5_PAD2		   ((1	<<	12)	|(32 <<	4)	|3)
#define GPIO_PB0_TC7_WO0			   ((1	<<	12)	|(32 <<	4)	|5)
#define GPIO_PB1_EIC_EXTINT1		   ((1	<<	12)	|(33 <<	4)	|0)
#define GPIO_PB1_ADC_AIN9			   ((1	<<	12)	|(33 <<	4)	|1)
#define GPIO_PB1_SERCOM5_PAD3		   ((1	<<	12)	|(33 <<	4)	|3)
#define GPIO_PB1_TC7_WO1			   ((1	<<	12)	|(33 <<	4)	|5)
#define GPIO_PB2_EIC_EXTINT2		   ((1	<<	12)	|(34 <<	4)	|0)
#define GPIO_PB2_ADC_AIN10			   ((1	<<	12)	|(34 <<	4)	|1)
#define GPIO_PB2_SERCOM5_PAD0		   ((1	<<	12)	|(34 <<	4)	|3)
#define GPIO_PB2_TC6_WO0			   ((1	<<	12)	|(34 <<	4)	|5)
#define GPIO_PB3_EIC_EXTINT3		   ((1	<<	12)	|(35 <<	4)	|0)
#define GPIO_PB3_ADC_AIN11			   ((1	<<	12)	|(35 <<	4)	|1)
#define GPIO_PB3_SERCOM5_PAD1		   ((1	<<	12)	|(35 <<	4)	|3)
#define GPIO_PB3_TC6_WO1			   ((1	<<	12)	|(35 <<	4)	|5)
#define GPIO_PB4_EIC_EXTINT4		   ((1	<<	12)	|(36 <<	4)	|0)
#define GPIO_PB4_ADC_AIN12			   ((1	<<	12)	|(36 <<	4)	|1)
#define GPIO_PB5_EIC_EXTINT5		   ((1	<<	12)	|(37 <<	4)	|0)
#define GPIO_PB5_ADC_AIN13			   ((1	<<	12)	|(37 <<	4)	|1)
#define GPIO_PB6_EIC_EXTINT6		   ((1	<<	12)	|(38 <<	4)	|0)
#define GPIO_PB6_ADC_AIN14			   ((1	<<	12)	|(38 <<	4)	|1)
#define GPIO_PB7_EIC_EXTINT7		   ((1	<<	12)	|(39 <<	4)	|0)
#define GPIO_PB7_ADC_AIN15			   ((1	<<	12)	|(39 <<	4)	|1)
#define GPIO_PB8_EIC_EXTINT8		   ((1	<<	12)	|(40 <<	4)	|0)
#define GPIO_PB8_ADC_AIN2			   ((1	<<	12)	|(40 <<	4)	|1)
#define GPIO_PB8_SERCOM4_PAD0		   ((1	<<	12)	|(40 <<	4)	|3)
#define GPIO_PB8_TC4_WO0			   ((1	<<	12)	|(40 <<	4)	|5)
#define GPIO_PB9_EIC_EXTINT9		   ((1	<<	12)	|(41 <<	4)	|0)
#define GPIO_PB9_ADC_AIN3			   ((1	<<	12)	|(41 <<	4)	|1)
#define GPIO_PB9_SERCOM4_PAD1		   ((1	<<	12)	|(41 <<	4)	|3)
#define GPIO_PB9_TC4_WO1			   ((1	<<	12)	|(41 <<	4)	|5)
#define GPIO_PB10_EIC_EXTINT10		   ((1	<<	12)	|(42 <<	4)	|0)
#define GPIO_PB10_SERCOM4_PAD2		   ((1	<<	12)	|(42 <<	4)	|3)
#define GPIO_PB10_TC5_WO0			   ((1	<<	12)	|(42 <<	4)	|5)
#define GPIO_PB10_GCLK_IO4			   ((1	<<	12)	|(42 <<	4)	|7)
#define GPIO_PB11_EIC_EXTINT11		   ((1	<<	12)	|(43 <<	4)	|0)
#define GPIO_PB11_SERCOM4_PAD3		   ((1	<<	12)	|(43 <<	4)	|3)
#define GPIO_PB11_TC5_WO1			   ((1	<<	12)	|(43 <<	4)	|5)
#define GPIO_PB11_GCLK_IO5			   ((1	<<	12)	|(43 <<	4)	|7)
#define GPIO_PB12_EIC_EXTINT12		   ((1	<<	12)	|(44 <<	4)	|0)
#define GPIO_PB12_SERCOM4_PAD0		   ((1	<<	12)	|(44 <<	4)	|2)
#define GPIO_PB12_TC4_WO0			   ((1	<<	12)	|(44 <<	4)	|4)
#define GPIO_PB12_GCLK_IO6			   ((1	<<	12)	|(44 <<	4)	|7)
#define GPIO_PB13_EIC_EXTINT13		   ((1	<<	12)	|(45 <<	4)	|0)
#define GPIO_PB13_SERCOM4_PAD1		   ((1	<<	12)	|(45 <<	4)	|2)
#define GPIO_PB13_TC4_WO1			   ((1	<<	12)	|(45 <<	4)	|4)
#define GPIO_PB13_GCLK_IO7			   ((1	<<	12)	|(45 <<	4)	|7)
#define GPIO_PB14_EIC_EXTINT14		   ((1	<<	12)	|(46 <<	4)	|0)
#define GPIO_PB14_SERCOM4_PAD2		   ((1	<<	12)	|(46 <<	4)	|2)
#define GPIO_PB14_TC5_WO0			   ((1	<<	12)	|(46 <<	4)	|4)
#define GPIO_PB14_GCLK_IO0			   ((1	<<	12)	|(46 <<	4)	|7)
#define GPIO_PB15_EIC_EXTINT15		   ((1	<<	12)	|(47 <<	4)	|0)
#define GPIO_PB15_SERCOM4_PAD3		   ((1	<<	12)	|(47 <<	4)	|2)
#define GPIO_PB15_TC5_WO1			   ((1	<<	12)	|(47 <<	4)	|4)
#define GPIO_PB15_GCLK_IO1			   ((1	<<	12)	|(47 <<	4)	|7)
#define GPIO_PB16_EIC_EXTINT0		   ((1	<<	12)	|(48 <<	4)	|0)
#define GPIO_PB16_SERCOM5_PAD0		   ((1	<<	12)	|(48 <<	4)	|2)
#define GPIO_PB16_TC6_WO0			   ((1	<<	12)	|(48 <<	4)	|4)
#define GPIO_PB16_GCLK_IO2			   ((1	<<	12)	|(48 <<	4)	|7)
#define GPIO_PB17_EIC_EXTINT1		   ((1	<<	12)	|(49 <<	4)	|0)
#define GPIO_PB17_SERCOM5_PAD1		   ((1	<<	12)	|(49 <<	4)	|2)
#define GPIO_PB17_TC6_WO1			   ((1	<<	12)	|(49 <<	4)	|4)
#define GPIO_PB17_GCLK_IO3			   ((1	<<	12)	|(49 <<	4)	|7)
#define GPIO_PB22_EIC_EXTINT6		   ((1	<<	12)	|(54 <<	4)	|0)
#define GPIO_PB22_SERCOM5_PAD2		   ((1	<<	12)	|(54 <<	4)	|3)
#define GPIO_PB22_TC7_WO0			   ((1	<<	12)	|(54 <<	4)	|5)
#define GPIO_PB22_GCLK_IO0			   ((1	<<	12)	|(54 <<	4)	|7)
#define GPIO_PB23_EIC_EXTINT7		   ((1	<<	12)	|(55 <<	4)	|0)
#define GPIO_PB23_SERCOM5_PAD3		   ((1	<<	12)	|(55 <<	4)	|3)
#define GPIO_PB23_TC7_WO1			   ((1	<<	12)	|(55 <<	4)	|5)
#define GPIO_PB23_GCLK_IO1			   ((1	<<	12)	|(55 <<	4)	|7)
#define GPIO_PB30_EIC_EXTINT14		   ((1	<<	12)	|(62 <<	4)	|0)
#define GPIO_PB30_SERCOM5_PAD0		   ((1	<<	12)	|(62 <<	4)	|3)
#define GPIO_PB30_TC0_WO0			   ((1	<<	12)	|(62 <<	4)	|5)
#define GPIO_PB31_EIC_EXTINT15		   ((1	<<	12)	|(63 <<	4)	|0)
#define GPIO_PB31_SERCOM5_PAD1		   ((1	<<	12)	|(63 <<	4)	|3)
#define GPIO_PB31_TC0_WO1			   ((1	<<	12)	|(63 <<	4)	|5)


//*****************************************************************************
//
//! @}
//
//*****************************************************************************
//*****************************************************************************
//
//! \addtogroup GPIO_Dir_Mode GPIO Dir Mode
//! \brief Values that can be passed to GPIODirModeSet as the ulPinIO parameter,
//! and returned from GPIODirModeGet.
//! @{
//
//*****************************************************************************

//
//! Pin is a GPIO input
//
#define GPIO_DIR_MODE_IN        0x00000000

//
//! Pin is a GPIO output
//
#define GPIO_DIR_MODE_OUT       0x00000001

#define GPIO_DIR_MODE_HW		0x00000002

//*****************************************************************************
//
//! \addtogroup GPIO Internal Pull Configuration
//! \brief 
//! //! @{
//
//*****************************************************************************

//
//! No Pull required
//
#define GPIO_PIN_PULL_NONE			0x00000000
//
//! Pin is internally pull up
//
#define GPIO_PIN_PULL_UP			0x00000001
//
//! Pin is internally pull down
//
#define GPIO_PIN_PULL_DOWN			0x00000002

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __xGPIO_H__


