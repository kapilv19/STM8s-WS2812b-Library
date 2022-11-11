/**
  *******************************************************************************
  * @file    stm8s_ws2812b.h
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

/* Define to prevent recursive inclusion --------------------------------------*/
#ifndef __STM8S_WS2812B_H
#define __STM8S_WS2812B_H


/* Includes -------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_utils.h"


/* Exposed Methods Prototypes -------------------------------------------------*/
void WS2812B_init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin);
void WS2812B_deInit(void);
void WS2812B_sendPixel(uint8_t r, uint8_t g, uint8_t b);


#endif /* __STM8S_WS2812B_H */

/************************ Copyright (c) 2022 Kapil Verma ******END OF FILE******/