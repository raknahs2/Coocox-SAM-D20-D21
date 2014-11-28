=======================================================
				SAMD20 XPRO CoOS Demo
=======================================================
		
Purpose
-------
The CoOS example will help users how to use CoOS in SAM D20 XPRO boards. This basic application shows how to create task and up to some extent how the inter task communication is performed using CoOS. This example contains the COX peripheral layer implemented for GPIO, USART and SPI of ATSAMD20J18A. 

Requirements
------------
	Hardware
		This package can be used with SAM D20 XPRO boards.
	Software
		This example runs on,
			Atmel Studio 6.2.1153
			Atmel ARM GNU Toolchain - 4.8.3.1426
			ARM_Toolchain_Version:4.8.3.275 GCC_VERSION:4.8.3
			ASF 3.18.0 or above
			CoOS 1.1.5

Description
-----------
The example uses the COX peripheral drivers for GPIO, SPI and USART to demonstrate the SPI Master/Slave, USART Tx/Rx and GPIO input read and Output write functionalities in a single integrated application. Apart from the COX peripheral drivers, the example also shows the user how to create tasks, how to share information in the form of variables between tasks using CoOS features.

//SPI Master
	 * PA4 - MOSI
	 * PA5 - SCK
	 * PA6 - SS
	 * PA7 - MISO
//SPI Slave
	 * PB23 - MOSI
	 * PB17 - SCK
	 * PB22 - SS
	 * PB16 - MISO
//USART	 	 
	* PA24 - TxD
 	* PA25 - RxD	 
//Input GPIO (push button)
	 * PA15
//Output GPIO (LED)
	 * PA14

Required Hardware Setup
-----------------------
//External wired connections required for SPI on SAMD20 XPRO to test the example application
	connect PA4 to PB23 (MOSI)
	connect PA5 to PB17 (SCK)
	connect PA6 to PB22 (SS)
	connect PA7 to PB16 (MISO)

//On the computer, open and configure a terminal application (e.g. HyperTerminal on Microsoft Windows) with these settings:
	9600 bauds
	8 bits of data
	No parity
	1 stop bit
	No flow control

Example Application Brief
-------------------------
There are 5 task running in parallel. The ‘sw0_task’ keeps reading SW0 on the SAM D21 Xplained Pro. As long as the switch is not pressed, it releases a semaphore. The ‘board_live_task’ waits
for the above semaphore to be released by the ‘sw0_task’. So, if SW0 is pressed, the LED will stop toggling. Pressing SW0 will also sends a message through SERCOM3. 
As SERCOM3 (configured as USART) is a shared resource, a Mutex (usart3_mutex) is used by ‘sw0_task’ and ‘usart3_task’ for mutual exclusion.
There are 3 other tasks which handles the serial communication. The ‘usart3_task’ configures SERCOM3 as USART (9600 baud, 8 Data Bits, and no parity bit). 
It prints a  message at starting to inform the user to press ‘1’ to start data transfer. Once this task receives ‘1’ (ASCII 0x31), it sets a flag named ‘spi5_start_flag’. The SPI master task ‘spi0_task’ waits till this flag is set. Once it is set, the SPI master keep on sending predefined characters. External connections have to be made from SPI0 to SPI5. The SERCOM5 is configured as SPI slave who receives SPI data. The task ‘spi5_slave_task’ will send the received characters to the ‘usart3_task’ using a mail box. The ‘usart3_task’ then sends them out to SERCOM3, which is configured as USART.

Running the Example Application
-------------------------------
Using Atmel Studio, build the program and download it inside the SAMD20 XPRO board using EDBG debugging interface (available on-bard SAMD20 XPRO) and follow the instructions provided in the hyperterminal.

Memory Utilization
------------------
Compiler Optimization level	:	-O1
Program Memory Usage 		:	14140 bytes   5.4 % Full
Data Memory Usage 			:	12728 bytes   38.8 % Full


==============================================================================
Package Revision History
==============================================================================
Ver: 1.0 (initial release)
Release Date: Aug-11 2014

	Known issues and limitations:-
	1) USART and SPI uses polling method. Interrupts are not supported
	2) USART: Using SERCOM0 and SERCOM1 simultaneously has some issues in SAMD20XPRO.
	   This seems to be an issue with the board.   
==============================================================================
Ver: 2.0
Release Date: Nov-28 2014

	Enhancements in Ver 2.0:-
	Interrupt driven mechanism for USART and SPI.

	Known issues and limitations:-
	USART: Using SERCOM0 and SERCOM1 simultaneously has some issues in SAMD20XPRO.
	   This seems to be an issue with the board.
	   
Memory Utilization
------------------
Compiler Optimization level	:	-O1
Program Memory Usage 	:	15496 bytes   5.9 % Full
Data Memory Usage 		:	12784 bytes   39.0 % Full
   
==============================================================================
//Template
Ver: 
Release Date: 

	Known issues and limitations:-
==============================================================================
==============================================================================
==============================================================================