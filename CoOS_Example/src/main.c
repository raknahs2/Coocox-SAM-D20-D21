/**
 * \file
 *
 * \brief Example Application main file
 *
 * Copyright (C) 2012-2014 Atmel Corporation. All rights reserved.
 *
 * \license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \license_stop
 *
 */
#include "CoOS.h"
#include "xgpio.h"
#include "xspi.h"
#include "xuart.h"
#include "xhw_memmap.h"
#include "clock.h"
#include <system.h>
#include "xhw_types.h"
#include "xsercom_interrupt.h"

#define TASK_PRIORITY_LEVEL				10
#define TICK_CNT_INIT_VAL       (CFG_SYSTICK_FREQ / 20)


#define UART3_INST_NUM       3
#define SPI0_INST_NUM		 0
#define SPI5_INST_NUM        5

U32 loc_tick_cnt = TICK_CNT_INIT_VAL;
OS_TID tid_board_live_task;
OS_TID tid_sw0_task;
OS_TID tid_usart3_task;
OS_TID tid_spi0_task;
OS_TID tid_spi5_task;
OS_TID tid_test;

OS_STK stk_board_live_task[100];
OS_STK stk_sw0_task[100];
OS_STK stk_usart3_task[100];
OS_STK stk_spi0_task[100];
OS_STK stk_spi5_task[100];

OS_MutexID usart3_mutex;
OS_FlagID usart_txc_flag, usart_rxc_flag;
OS_FlagID spi5_start_flag, spi0_txc_flag, spi5_rxc_flag;
OS_EventID sw0_semaphore;
OS_EventID mb_id_serial_link;

static volatile uint16_t spi_rxdata = 0;
static volatile uint16_t usart_rxdata = 0;
	
xtEventCallback uart3_callback()
{
	CoEnterISR();
		
	uint8_t status;
	
	status  = (xHWREGB(xUART3_BASE + SERCOM_USART_INTFLAG_OFFSET));
	
	if ((status & SERCOM_USART_INTFLAG_TXC)== 0x02){
		
		/* Clear the TXC flag */
		xHWREGB(xUART3_BASE + SERCOM_USART_INTFLAG_OFFSET) = 0x02;
		
		/* Post a flag to indicate usart transmission complete */
		isr_SetFlag(usart_txc_flag);
		
	} else if ((status & SERCOM_USART_INTFLAG_RXC)== 0x04){
		
		/* Reading the data clears the RXC flag */
		//rxdata = xUARTCharGetNonBlocking(xUART3_BASE);
		usart_rxdata = xHWREG(xUART3_BASE + SERCOM_USART_DATA_OFFSET);
		
		/* Post a flag to indicate receive complete */
		isr_SetFlag(usart_rxc_flag);
	}
	
	CoExitISR();
}

xtEventCallback spi0_callback(){
	
		CoEnterISR();
		
		uint8_t status;
		uint16_t dummy_data;
		
		status  = (xHWREGB(xSPI0_BASE + SERCOM_SPI_INTFLAG_OFFSET));
		
		if ((status & SERCOM_SPI_INTFLAG_TXC)== 0x02){
			
			/* Clear the TXC flag */
			xHWREGB(xSPI0_BASE + SERCOM_SPI_INTFLAG_OFFSET) = 0x02;
			
			dummy_data = xHWREG(xSPI0_BASE + SERCOM_SPI_DATA_OFFSET);
			
			/* Post a flag to indicate usart transmission complete */
			isr_SetFlag(spi0_txc_flag);
			
		}
		
		CoExitISR();
}

xtEventCallback spi5_callback()
{
	
		CoEnterISR();
		uint8_t status;
		
		status  = (xHWREGB(xSPI5_BASE + SERCOM_SPI_INTFLAG_OFFSET));
		
		 if ((status & SERCOM_SPI_INTFLAG_RXC)== 0x04){
			 
			 
			/* Reading the data clears the RXC flag */
			spi_rxdata = xHWREG(xSPI5_BASE + SERCOM_SPI_DATA_OFFSET);
			
			/* Post a flag to indicate receive complete */
			isr_SetFlag(spi5_rxc_flag);
		}
		

		CoExitISR();
}


void sw0_task(void *pdata)
{
	uint16_t read_val = 0;
	const uint8_t *msg1 = "SW0 is pressed\r\n\n";
	int i;

	xGPIODirModeSet(PORTA_BASE, xGPIO_PIN_15, xGPIO_DIR_MODE_IN);
	GPIOPinInputPullConfigSet(PORTA_BASE, xGPIO_PIN_15, GPIO_PIN_PULL_UP);

	while (1) {
		read_val = xGPIOPinRead(PORTA_BASE, xGPIO_PIN_15);
		if (read_val & PORT_PA15) {
			CoPostSem(sw0_semaphore);
		} else {
			if (E_OK == CoEnterMutexSection(usart3_mutex)) {
				i = 0;
				while (*(msg1 + i)) {
					xUARTCharPutNonBlocking(xUART3_BASE, *(msg1 + i));
					i++;
					CoWaitForSingleFlag(usart_txc_flag,0);
					CoClearFlag(usart_txc_flag);
				}
				CoLeaveMutexSection(usart3_mutex);
			}
		}
	}
}

void board_live_task(void *pdata)
{
	static bool val = true;

	xGPIODirModeSet(PORTA_BASE, xGPIO_PIN_14, xGPIO_DIR_MODE_OUT);
	xGPIOPinWrite(PORTA_BASE, xGPIO_PIN_14, 0);
	while (1) {
		if (E_OK == CoPendSem(sw0_semaphore, 1)) {
			CoTickDelay(loc_tick_cnt);
			xGPIOPinWrite(PORTA_BASE, xGPIO_PIN_14, val);
			val = !val;
			loc_tick_cnt -= 1;
			if (loc_tick_cnt < 1) {
			loc_tick_cnt = TICK_CNT_INIT_VAL;
			}
		}
	}
}

void usart3_task(void *pdata)
{
	const uint8_t *msg1 = "Press 1 to start data transfer\r\n";
	StatusType err;
	void *pmail;
	

 	xGPIOPinConfigure(PA24, SERCOM3_PAD2);  /* PA24 - TxD */
 	xGPIOPinConfigure(PA25, SERCOM3_PAD3);  /* PA25 - RxD */
	UARTClockEnable(xUART3_BASE);
	UARTTxPinSelect(xUART3_BASE, SERCOM_USART_TX_PIN_2);
	UARTRxPinSelect(xUART3_BASE, SERCOM_USART_RX_PIN_3);
	xUARTConfigSet(xUART3_BASE, 9600,
			xUART_CONFIG_WLEN_8 | xUART_CONFIG_PAR_DISABLE);
	UARTClockMode(xUART3_BASE, SERCOM_USART_INT_CLOCK);
	UARTLsbFirst(xUART3_BASE);
	xUARTBlockEnable(xUART3_BASE, xUART_BLOCK_TX);
	xUARTBlockEnable(xUART3_BASE, xUART_BLOCK_RX);
	xUARTEnable(xUART3_BASE);
	
	UsartInitDefaultCallback();
	UARTIntCallbackInit(UART3_INST_NUM, uart3_callback);
	SercomUSARTIntEnable(xUART3_BASE, xUART_INT_TX);
	SercomUSARTIntEnable(xUART3_BASE, xUART_INT_RX);
	NVIC_EnableIRQ(SERCOM3_IRQn);
	
	
	/* Send the message through USART3 */
	while (*msg1) {
		xUARTCharPutNonBlocking(xUART3_BASE, *msg1++);
		CoWaitForSingleFlag(usart_txc_flag,0);
		CoClearFlag(usart_txc_flag);
	}
	

	CoWaitForSingleFlag(usart_rxc_flag,0);
	CoClearFlag(usart_rxc_flag);
	/* Wait until getting the command through USART3 */
	while (usart_rxdata != '1');
	
	/* Post a flag to start SPI0 master task */
	CoSetFlag(spi5_start_flag);

	while(1) {
		if (E_OK == CoEnterMutexSection(usart3_mutex)) {
			
			pmail = CoPendMail(mb_id_serial_link, 0, &err);
			
			if (E_OK == err) {
				uint8_t i = 0;
				
				while (*((unsigned char *)(pmail + i))) {
					
					xUARTCharPutNonBlocking(xUART3_BASE,
					*((unsigned char *)(pmail + i)));
					i++;	
					
					CoWaitForSingleFlag(usart_txc_flag,0);
					CoClearFlag(usart_txc_flag);
					
				}
			}
			
			CoLeaveMutexSection(usart3_mutex);
		}
	}
}

void spi0_task(void *pdata)
{
	unsigned long master_rx_data = 0;
	uint8_t i = 0;
	
	/* Configure PA6 as general purpose output, to use it as SS */
	xGPIODirModeSet(PORTA_BASE,xGPIO_PIN_6, xGPIO_DIR_MODE_OUT);
	xGPIOPinWrite(PORTA_BASE, xGPIO_PIN_6, 0);
	
	/*
	 * PA4 - MOSI
	 * PA5 - SCK
	 * PA6 - SS
	 * PA7 - MISO
	 */
	/* Configure the pins to be used for SPI */
	xGPIOPinConfigure(PA4, SERCOM0_PAD0);
	xGPIOPinConfigure(PA5, SERCOM0_PAD1);
	xGPIOPinConfigure(PA7, SERCOM0_PAD3);
	SPIClockEnable(xSPI0_BASE);
	SPIInputPinSel(xSPI0_BASE, SERCOM_SPI_DI_PIN_3);
	SPIOutputPinSel(xSPI0_BASE, SERCOM_SPI_DO_PINCFG_0);
	xSPIConfigSet(xSPI0_BASE, 2000000, SERCOM_SPI_MODE_0|SERCOM_SPI_MASTER|xSPI_MSB_FIRST);
	SPIRxEnable(xSPI0_BASE);
	SPIEnable(xSPI0_BASE);
	
	SpiInitDefaultCallback();
	SPIIntCallbackInit(SPI0_INST_NUM, spi0_callback);
	SercomSPIIntEnable(xSPI0_BASE, xSPI_INT_EOT);
	NVIC_EnableIRQ(SERCOM0_IRQn);
		
	
	if (E_OK == CoWaitForSingleFlag(spi5_start_flag,0)) {
		
		while (1) {
			CoTickDelay(500);
			/* Manually control SS */
			xGPIOPinWrite(PORTA_BASE, xGPIO_PIN_6, 0);
			
			/* Keep sending 0 to 9 */
			SPISingleDataWriteNonblocking(xSPI0_BASE, 0x30 + (i++ % 10));
			CoWaitForSingleFlag(spi0_txc_flag,0);
			CoClearFlag(spi0_txc_flag);
			
			xGPIOPinWrite(PORTA_BASE, xGPIO_PIN_6, 1);
		}
	}
}

void spi5_slave_task(void *pdata)
{

	unsigned char message1[4] = {0};
	
	/*
	 * PB16 - MISO
	 * PB17 - SCK
	 * PB22 - SS
	 * PB23 - MOSI
	 */
	xGPIOPinConfigure(PB16, SERCOM5_PAD0);
	xGPIOPinConfigure(PB17, SERCOM5_PAD1);
	xGPIOPinConfigure(PB22, SERCOM5_PAD2);
	xGPIOPinConfigure(PB23, SERCOM5_PAD3);
	
	SPIClockEnable(xSPI5_BASE);
	SPIInputPinSel(xSPI5_BASE, SERCOM_SPI_DI_PIN_3);
	SPIOutputPinSel(xSPI5_BASE, SERCOM_SPI_DO_PINCFG_0);
	
	xSPIConfigSet(xSPI5_BASE, 100000, SERCOM_SPI_MODE_0|SERCOM_SPI_SLAVE|xSPI_MSB_FIRST);
	SPIRxEnable(xSPI5_BASE);
	SPIEnable(xSPI5_BASE);
	
	SPIIntCallbackInit(SPI5_INST_NUM, spi5_callback);
	SercomSPIIntEnable(xSPI5_BASE, xSPI_INT_RXC);
	NVIC_EnableIRQ(SERCOM5_IRQn);
	
	/* Create a message box to send the received byte to usart3_task */
	mb_id_serial_link = CoCreateMbox(EVENT_SORT_TYPE_FIFO);
	
	while (1) {
		
 		CoWaitForSingleFlag(spi5_rxc_flag,0);
 		CoClearFlag(spi5_rxc_flag);
		
		/* Prepare the message to be sent */
		message1[0] = (uint8_t) spi_rxdata;
		message1[1] = '\r';
		message1[2] = '\n';

		CoPostMail(mb_id_serial_link, message1);
	}
}

int main(void)
{
	system_init();
	CoInitOS();

	spi5_start_flag = CoCreateFlag(true,false);
	spi5_rxc_flag   = CoCreateFlag(false, false);
	spi0_txc_flag   = CoCreateFlag(false,false);
	usart_txc_flag  = CoCreateFlag(false,false);
	usart_rxc_flag  = CoCreateFlag(false,false);

	sw0_semaphore = CoCreateSem(0, 1, EVENT_SORT_TYPE_FIFO);
	usart3_mutex = CoCreateMutex();

	tid_sw0_task =
			CoCreateTask(sw0_task, NULL, TASK_PRIORITY_LEVEL,
			&stk_sw0_task[99], 100);
	tid_board_live_task =
			CoCreateTask(board_live_task, NULL, TASK_PRIORITY_LEVEL,
			&stk_board_live_task[99], 100);
	tid_spi0_task  =
			CoCreateTask(spi0_task, NULL, TASK_PRIORITY_LEVEL,
			&stk_spi0_task[99], 100);
	tid_usart3_task	=
			CoCreateTask(usart3_task, NULL, TASK_PRIORITY_LEVEL,
			&stk_usart3_task[99], 100);
	tid_spi5_task =
			CoCreateTask(spi5_slave_task, NULL, TASK_PRIORITY_LEVEL,
			&stk_spi5_task[99], 100);
	
	CoStartOS();
	
	while (1) {
	};
}
