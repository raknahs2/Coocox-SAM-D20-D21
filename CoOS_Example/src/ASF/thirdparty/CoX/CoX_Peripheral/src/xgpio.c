//*****************************************************************************
//
//! \file xgpio.c
//! \brief Driver for the GPIO AFIO and EXTI controller
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
#include "xhw_gpio.h"
#include "xgpio.h"
#include "xdebug.h"
#include "xhw_memmap.h"
#include "xhw_types.h"


//*****************************************************************************
//
// An array that maps Port base.
//
//*****************************************************************************
static const unsigned long g_pulPortBase[] =
{
    PORTA_BASE,
    PORTB_BASE
};

//*****************************************************************************
//
//! \brief Sets the direction and mode of the specified pin.
//!
//! \param ulPort is the base address of the GPIO port
//! \param ulBit is the bit number of a port.
//! \param ulPinIO is the pin direction and/or mode.
//!
//! This function will set the specified pin(Only 1 pin) on the selected GPIO
//! port as either an input or output under software control, or it will set
//! the pin to be under hardware control.
//!
//! The parameter \e ulPinIO is an enumerated data type that can be one of
//! the following values:
//!
//! - \b GPIO_DIR_MODE_IN
//! - \b GPIO_DIR_MODE_OUT
//!
//! where \b GPIO_DIR_MODE_IN specifies that the pin will be programmed as
//! a software controlled input, \b GPIO_DIR_MODE_OUT specifies that the pin
//! will be programmed as a software controlled output.
//!
//! \return None.
//
//*****************************************************************************
void GPIODirModeSet(
		unsigned long ulPort,
		unsigned long ulBit,
		unsigned long ulPinIO)
{
	//Assert(ulPort);
	//Assert(config);
	xASSERT((ulPinIO == GPIO_DIR_MODE_OUT) || (ulPinIO == GPIO_DIR_MODE_IN));

	/* Track the configuration bits into a temporary variable before writing */
	unsigned long pin_cfg = 0;
	unsigned long lower_pin_mask = 0;
	unsigned long upper_pin_mask = 0;

	/* Check if the user has requested that the input buffer be enabled */
	if (ulPinIO == GPIO_DIR_MODE_IN){
		/* Enable input buffer flag */
		pin_cfg |= PORT_WRCONFIG_INEN;
		/* Clear the port DIR bits to disable the output buffer */
		xHWREG(ulPort + PORT_DIRCLR_OFFSET) = ulBit;	
	}

	/* Check if the user has requested that the output buffer be enabled */
	if (ulPinIO == GPIO_DIR_MODE_OUT)
	{
		/* Disable input buffer flag */
		pin_cfg &= ~PORT_WRCONFIG_INEN;
		/* Set the port DIR bits to enable the output buffer */
		xHWREG(ulPort + PORT_DIRSET_OFFSET) = ulBit;
	}
	
	/* The Write Configuration register (WRCONFIG) requires the
	 * pins to to grouped into two 16-bit half-words - split them out here */
	lower_pin_mask = (ulBit & 0xFFFF);	
	upper_pin_mask = (ulBit >> 16);

	/* Configure the lower 16-bits of the port to the desired configuration,
	 * including the pin peripheral multiplexer just in case it is enabled */
	xHWREG(ulPort + PORT_WRCONFIG_OFFSET)
		= (lower_pin_mask << PORT_WRCONFIG_PINMASK_Pos) |
			pin_cfg | PORT_WRCONFIG_WRPINCFG;

	/* Configure the upper 16-bits of the port to the desired configuration,
	 * including the pin peripheral multiplexer just in case it is enabled */
	xHWREG(ulPort + PORT_WRCONFIG_OFFSET)
		= (upper_pin_mask << PORT_WRCONFIG_PINMASK_Pos) |
			pin_cfg | PORT_WRCONFIG_WRPINCFG |
			PORT_WRCONFIG_HWSEL;
			
}

//*****************************************************************************
//
//! Gets the direction and mode of a pin.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ulBit is the pin number.
//!
//! This function gets the direction and control mode for a specified pin on
//! the selected GPIO port.  The pin can be configured as either an input or
//! output under software control, or it can be under hardware control.  The
//! type of control and direction are returned as an enumerated data type.
//!
//! \return Returns one of the enumerated data types described for
//! GPIODirModeSet().
//
//*****************************************************************************
unsigned long
GPIODirModeGet(unsigned long ulPort, unsigned long ulBit)
{
    //
    // Check the arguments.
    //
    //Assert(ulPort);
    xASSERT(ulBit < 32);
    
    //
    // Return the pin direction and mode.
    //
    return ((xHWREG(ulPort + PORT_DIR_OFFSET) >> ulBit) & 0x00000001);
}



//*****************************************************************************
//
//! \brief Sets the direction and mode of the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port
//! \param ulPins is the bit-packed representation of the pin(s).
//! \param ulPinIO is the pin direction and/or mode.
//!
//! This function will set the specified pin(s) on the selected GPIO port
//! as either an input or output under software control, or it will set the
//! pin to be under hardware control.
//!
//! The parameter \e ulPinIO is an enumerated data type that can be one of
//! the following values:
//!
//! - \b xGPIO_DIR_MODE_IN
//! - \b xGPIO_DIR_MODE_OUT
//! - \b xGPIO_DIR_MODE_HW
//!
//! where \b GPIO_DIR_MODE_IN specifies that the pin will be programmed as
//! a software controlled input, \b GPIO_DIR_MODE_OUT specifies that the pin
//! will be programmed as a software controlled output, and
//! \b GPIO_DIR_MODE_HW specifies that the pin will be placed under
//! hardware control.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
xGPIODirModeSet(unsigned long ulPort, unsigned long ulPins,
               unsigned long ulPinIO)
{
    //
    // Check the arguments.
    //
    //xASSERT(GPIOBaseValid(ulPort));
    xASSERT((ulPinIO == xGPIO_DIR_MODE_IN) || (ulPinIO == xGPIO_DIR_MODE_OUT) ||
            (ulPinIO == xGPIO_DIR_MODE_HW));

    //
    // Set the pin direction and mode.
    //
	for (int i = 0; i < 32; i++) {
		if (ulPins & (1UL << i)) {
			GPIODirModeSet(ulPort, (1UL << i), ulPinIO);
		}
	}
}

//*****************************************************************************
//
//! \brief Gets the direction and mode of a pin.
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ulPin is the bit-packed representation of the pin.
//!
//! This function gets the direction and control mode for a specified pin on
//! the selected GPIO port.  The pin can be configured as either an input or
//! output under software control, or it can be under hardware control.  The
//! type of control and direction are returned as an enumerated data type.
//!
//! \return Returns one of the enumerated data types described for
//! GPIODirModeSet().
//
//*****************************************************************************
unsigned long
xGPIODirModeGet(unsigned long ulPort, unsigned long ulPin)
{
    unsigned long ulBits;
    //
    // Check the arguments.
    //
    //xASSERT(GPIOBaseValid(ulPort));

    for(ulBits=0; ulBits<32; ulBits++)
    {
        if(ulPin & (1 << ulBits))
        {
            break;
        }
    } 
    
    //
    // Return the pin direction and mode.
    //
    return GPIODirModeGet(ulPort, ulBits);
}

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
 unsigned long
 GPIOPinToPort(unsigned long ulPort, unsigned long ulPin)
 {
	 //
	 // Check the arguments.
	 //
	 //xASSERT(GPIOBaseValid(ulPort));

	 return ulPort;
 }
 
//*****************************************************************************
//
//! \brief Get the GPIO pin number from a short Pin.
//!
//! \param ulPort is the base address of the GPIO port
//!
//! \note None.
//! 
//! \return GPIO pin number which is used by GPIO API.
//
//*****************************************************************************
unsigned long 
GPIOPinToPin(unsigned long ulPort, unsigned long ulPin)
{        
    //
    // Check the arguments.
    //
    //xASSERT(GPIOBaseValid(ulPort));

    return ulPin;
}

//*****************************************************************************
//
//! \brief Reads the values present of the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ulPins is the bit-packed representation of the pin(s).
//!
//! The values at the specified pin(s) are read, as specified by \e ucPins.
//! Values are returned for both input and output pin(s), and the value
//! for pin(s) that are not specified by \e ucPins are set to 0.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return Returns a bit-packed byte providing the state of the specified
//! pin, where bit 0 of the byte represents GPIO port pin 0, bit 1 represents
//! GPIO port pin 1, and so on.  Any bit that is not specified by \e ucPins
//! is returned as a 0.  Bits 31:16 should be ignored.
//
//*****************************************************************************
long
xGPIOPinRead(unsigned long ulPort, unsigned long ulPins)
{
    //
    // Check the arguments.
    //
    //xASSERT(GPIOBaseValid(ulPort));

    //
    // Return the pin value(s).
    //
    return(xHWREG(ulPort + PORT_IN_OFFSET) & (ulPins));
}
//*****************************************************************************
//
//! \brief Writes a value to the specified pin(s).
//!
//! \param ulPort is the base address of the GPIO port.
//! \param ulPins is the bit-packed representation of the pin(s).
//! \param ucVal is the value to write to the pin(s).
//!
//! Writes the corresponding bit values to the output pin(s) specified by
//! \e ucPins.  Writing to a pin configured as an input pin has no effect.
//!
//! The pin(s) are specified using a bit-packed byte, where each bit that is
//! set identifies the pin to be accessed, and where bit 0 of the byte
//! represents GPIO port pin 0, bit 1 represents GPIO port pin 1, and so on.
//!
//! \return None.
//
//*****************************************************************************
void
xGPIOPinWrite(unsigned long ulPort, unsigned long ulPins, unsigned char ucVal)
{
    //
    // Check the arguments.
    //
    //xASSERT(GPIOBaseValid(ulPort));
    //
    // Write the pins.
    //
	/* Set the pin to high or low atomically based on the requested level */
	if (ucVal) {
		xHWREG(ulPort + PORT_OUTSET_OFFSET) = ulPins;
	} else {
		xHWREG(ulPort + PORT_OUTCLR_OFFSET) = ulPins;
	}
}

//*****************************************************************************
//
//! \brief Configures the alternate function of a GPIO pin.
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
//! \note None.
//!
//! \return None.
//
//*****************************************************************************
void
GPIOPinConfigure(unsigned long ulPinConfig)
{
    unsigned long ulPortBase, ulPinBase, ulMux;
    unsigned long ulShift;
	unsigned long ulpin_mask;
	
	/* Track the configuration bits into a temporary variable before writing */
	unsigned long pin_cfg = 0;
	unsigned long lower_pin_mask = 0;
	unsigned long upper_pin_mask = 0;
    //
    // Extract the Port Base shift.
    //
    ulShift = (ulPinConfig >> 12) & 0xF;
    ulPortBase = g_pulPortBase[ulShift]; 

    //
    // Extract the pin shift number.
    // 
    ulShift = (ulPinConfig >> 4) & 0xFF; 
    ulPinBase = ulShift;
	ulpin_mask = (1UL << (ulPinBase % 32));
    //
    // Extract the pin mux.
    // 
    ulMux = ulPinConfig & 0xF; 
	pin_cfg |= PORT_WRCONFIG_PMUXEN;
	pin_cfg |= (ulMux << PORT_WRCONFIG_PMUX_Pos);	

	/* The Write Configuration register (WRCONFIG) requires the
	 * pins to to grouped into two 16-bit half-words - split them out here */
	lower_pin_mask = (ulpin_mask & 0xFFFF);
	upper_pin_mask = (ulpin_mask >> 16);	

	/* Configure the lower 16-bits of the port to the desired configuration,
	 * including the pin peripheral multiplexer just in case it is enabled */
	xHWREG(ulPortBase + PORT_WRCONFIG_OFFSET)
		= (lower_pin_mask << PORT_WRCONFIG_PINMASK_Pos) |
			pin_cfg | PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_WRPMUX;

	/* Configure the upper 16-bits of the port to the desired configuration,
	 * including the pin peripheral multiplexer just in case it is enabled */
	xHWREG(ulPortBase + PORT_WRCONFIG_OFFSET)
		= (upper_pin_mask << PORT_WRCONFIG_PINMASK_Pos) |
			pin_cfg | PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_WRPMUX |
			PORT_WRCONFIG_HWSEL;
}

/**
 *  \brief Toggles the state of a port pin that is configured as an output.
 *
 *  Toggles the current output level of a port pin.
 *
 * \param ulPort is the base address of the GPIO port.
 * \param ulPin is the bit-packed representation of the pin.
 */
void GPIOPinToggleOutputLevel(unsigned long ulPort, unsigned long ulPin)
{
	xHWREG(ulPort + PORT_OUTTGL_OFFSET) = ulPin;
}

/**
 *  \brief Set the Pull configuration for input port pin
 *
 *  Set the internal PULL_UP, PULL_DOWN or PULL_NONE.
 * This function will set the specified pin(Only 1 pin) 
 *
 * \param ulPort is the base address of the GPIO port.
 * \param ulPin is the bit-packed representation of the pin.
 * \param ulPull is the pull configuration of the pin. 
 */
void GPIOPinInputPullConfigSet(unsigned long ulPort, unsigned long ulBit, unsigned long ulPull)
{
	xASSERT((ulPull == GPIO_PIN_PULL_NONE) || 
	        (ulPull == GPIO_PIN_PULL_UP) || 
			(ulPull == GPIO_PIN_PULL_DOWN));

	/* Track the configuration bits into a temporary variable before writing */
	unsigned long pin_cfg = 0;
	unsigned long lower_pin_mask = 0;
	unsigned long upper_pin_mask = 0;

	/* Check if the user has requeste dpull-up/pull-down control flag*/
	if(ulPull != GPIO_PIN_PULL_NONE){
		/* Enable input buffer flag */
		pin_cfg |= PORT_WRCONFIG_PULLEN;
	}
	pin_cfg |= PORT_WRCONFIG_INEN;
	
    /* The Write Configuration register (WRCONFIG) requires the
	 * pins to to grouped into two 16-bit half-words - split them out here */
	lower_pin_mask = (ulBit & 0xFFFF);	
	upper_pin_mask = (ulBit >> 16);

	/* Configure the lower 16-bits of the port to the desired configuration,
	 * including the pin peripheral multiplexer just in case it is enabled */
	xHWREG(ulPort + PORT_WRCONFIG_OFFSET)
		= (lower_pin_mask << PORT_WRCONFIG_PINMASK_Pos) |
			pin_cfg | PORT_WRCONFIG_WRPINCFG;

	/* Configure the upper 16-bits of the port to the desired configuration,
	 * including the pin peripheral multiplexer just in case it is enabled */
	xHWREG(ulPort + PORT_WRCONFIG_OFFSET)
		= (upper_pin_mask << PORT_WRCONFIG_PINMASK_Pos) |
			pin_cfg | PORT_WRCONFIG_WRPINCFG |
			PORT_WRCONFIG_HWSEL;
			
		/* Set the pull-up state once the port pins are configured if one was
		 * requested and it does not violate the valid set of port
		 * configurations */			
	if (pin_cfg & PORT_WRCONFIG_PULLEN) {
		/* Set the OUT register bits to enable the pullup if requested,clear to enable pull-down */
		if (ulPull == GPIO_PIN_PULL_UP) {
			xHWREG(ulPort + PORT_OUTSET_OFFSET) = ulBit;
			} else {
			xHWREG(ulPort + PORT_OUTCLR_OFFSET) = ulBit;
		}
	}
			
}