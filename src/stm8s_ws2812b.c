/**
  *******************************************************************************
  * @file    stm8s_ws2812b.c
  * @author  Kapil Verma
  * @version V0.1.0
  * @date    11-November-2022
  * @brief   This file contains all functions prototype and macros for the STM8s Serial library.
  *******************************************************************************
  * @attention
  *
	********************** Copyright (c) 2022 Kapil Verma *************************
	* 
	* 	Licensed under MIT License
	*
	*	Permission is hereby granted, free of charge, to any person obtaining a copy
	*	of this software and associated documentation files (the "Software"), to deal
	*	in the Software without restriction, including without limitation the rights
	*	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	*	copies of the Software, and to permit persons to whom the Software is
	*	furnished to do so, subject to the following conditions:
	*	
	*	The above copyright notice and this permission notice shall be included in all
	*	copies or substantial portions of the Software.
	*
	*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	*	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	*	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	*	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	*	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	*	SOFTWARE.
	*
	*	Note - Parts of code are copyrighted by STMicroelectronics, licensed under 
	*	MCD-ST Liberty SW License Agreement V2. You may obtain a copy that at:  
	*
	*        http://www.st.com/software_license_agreement_liberty_v2
  * 
  *******************************************************************************
	*/

/* Includes -------------------------------------------------------------------*/
#include "stm8s_ws2812b.h"


uint8_t led_port;
uint8_t led_pin;

uint8_t led_bit_itr;
uint8_t ws2812b_byte;

uint32_t prev_strip_change = 0;

bool isInitialised = FALSE;

void sendChannel(uint8_t byte) {
	led_bit_itr = 8;
	ws2812b_byte = byte;
	
/*	_asm("BSET $" #_led_port ", #" #_led_pin);
	
	#asm
				
		LOOP:																
		BSET					$_led_port,						#led_pin	
		NOP
		NOP
		NOP
		NOP
		BTJT					_led_byte,						#7,							SEND_BIT_1
		BRES					$_led_port,						#led_pin	
		SEND_BIT_1:
		NOP
		NOP
		NOP
		NOP
		NOP
		BRES					$_led_port,						#led_pin
		NOP
		NOP
		NOP
		NOP
		SLL						_led_byte
		DEC						_led_bit_itr
		JRNE					LOOP

	#endasm */
}

void sendPixel( uint8_t r , uint8_t g , uint8_t b )
{	
	disableInterrupts();
	
	//while(micros() - prev_led_change < 251);
	
	sendChannel(g);
	sendChannel(r);
	sendChannel(b);
	
	enableInterrupts();
	
	//prev_led_change = micros();
}


/* Exposed Methods Prototypes -------------------------------------------------*/


void WS2812B_init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
{
	led_port = GPIOx->ODR;
	led_pin = (uint8_t) GPIO_Pin;
	
	isInitialised = TRUE;
}


void WS2812B_deInit(void)
{
	isInitialised = FALSE;
}


void WS2812B_sendPixel(uint8_t r, uint8_t g, uint8_t b)
{
	if (!isInitialised) return;
	
	sendPixel(r, g, b);
}

/************************ Copyright (c) 2022 Kapil Verma ******END OF FILE******/