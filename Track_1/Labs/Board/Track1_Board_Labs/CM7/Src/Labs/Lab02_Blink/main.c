/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Sahil Khan
 * @brief          : This program blinks LED7 with 1 sec ON and 1 sec OFF
 * 				   : on STM32H745I-DISCO Board
 ******************************************************************************\
 */

#include "stm32h7xx.h"
#include "led7.h"
#include "systick.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	led7_init();
	systick_init_1ms();

	/* Loop forever */
	while(1)
	{
		led7_on();
		systick_delay_ms(1000U);
		led7_off();
		systick_delay_ms(1000U);
	}
}
