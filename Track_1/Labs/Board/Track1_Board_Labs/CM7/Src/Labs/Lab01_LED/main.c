/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Sahil Khan
 * @brief          : This program turns ON LED7
 * 				   : on STM32H745I-DISCO Board
 ******************************************************************************\
 */

#include "led7.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	led7_init();
	led7_on();
	led7_off();
	/* Loop forever */
	for(;;);
}
