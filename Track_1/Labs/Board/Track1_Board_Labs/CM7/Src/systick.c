/*
 * systick.c
 *
 *  Created on: Oct 11, 2026
 *      Author: sahkhan
 */


#include "systick.h"
#include "stm32h7xx.h"

#define SYSTICK_CYCLES_PER_MS 0xFA00U
#define SYSTICK_CLEAR_VALUE 0x0U

static volatile uint32_t elapsed_ms = 0U;

void systick_init_1ms(void)
{
/*
 	Disables SysTick.
	Sets RELOAD to 63,999. Assuming 64MHz clock
	Clears the current counter by writing 0 to SYST_CVR.
	Enables SysTick with CLKSOURCE = 1 and TICKINT = 0.
	64MHz Clock Assumption
*/
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	SysTick->LOAD = SYSTICK_CYCLES_PER_MS - 1U;
	SysTick->VAL = SYSTICK_CLEAR_VALUE;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
}

/*
 * Do not use with the interrupt-based timebase.
*/
void systick_delay_ms(uint32_t milliseconds)
{
	SysTick->VAL = SYSTICK_CLEAR_VALUE;
	for(uint32_t counter = 0U; counter < milliseconds; counter++)
	{
		while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0U)
		{
			// waiting for next millisecond interval
		}
	}
}


void systick_init_1ms_interrupt(void)
{
/*
 	Disables SysTick.
	Sets RELOAD to 63,999. Assuming 64MHz clock
	Clears the current counter by writing 0 to SYST_CVR.
	Enables SysTick with CLKSOURCE = 1 and TICKINT = 1.
	64MHz Clock Assumption
*/
	SysTick->CTRL = 0U;
	SysTick->LOAD = SYSTICK_CYCLES_PER_MS - 1U;
	SysTick->VAL = SYSTICK_CLEAR_VALUE;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk
					| SysTick_CTRL_ENABLE_Msk
					| SysTick_CTRL_TICKINT_Msk;

}


void SysTick_Handler(void)
{
	elapsed_ms++;
}


uint32_t systick_get_ms(void)
{
	return elapsed_ms;
}
