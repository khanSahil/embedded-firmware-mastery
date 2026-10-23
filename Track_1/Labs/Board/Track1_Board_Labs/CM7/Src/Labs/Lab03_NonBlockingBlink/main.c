/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Sahil Khan
 * @brief          : Non-blocking LED7 blink using a SysTick interrupt time base.
 * 					 LED starts OFF and changes state approximately every 1000 ms.
 ******************************************************************************
 */

#include <stdbool.h>
#include "stm32h7xx.h"
#include "led7.h"
#include "systick.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define LED_BLINK_INTERVAL_MS 1000U

int main(void)
{
	led7_init();
	systick_init_1ms_interrupt();
	uint32_t last_change_time = systick_get_ms();

	/* Loop forever */
	bool led_is_on = false;
	while(1)
	{
		uint32_t current_time = systick_get_ms();
		if((current_time - last_change_time) >= LED_BLINK_INTERVAL_MS)
		{
			last_change_time = current_time;
			led_is_on = !led_is_on;

			led_is_on ? led7_on() : led7_off();
		}
	}
}
