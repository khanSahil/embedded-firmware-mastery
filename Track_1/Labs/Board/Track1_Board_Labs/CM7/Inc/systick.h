/*
 * systick.h
 *
 *  Created on: Oct 11, 2026
 *      Author: sahkhan
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

/**
 * Configures SysTick for a 1 ms period.
 * Requires a 64 MHz processor clock.
 * SysTick interrupts remain disabled; timing uses polling.
 */
void systick_init_1ms(void);

/**
 * Blocks the caller for approximately the requested number of milliseconds.
 * Call systick_init_1ms() before using this function.
 * Requires exclusive use of SysTick; each call resets its current counter.
 */
void systick_delay_ms(uint32_t milliseconds);

/*
 * Configure a 1 ms SysTick interrupt, assuming a 64 MHz processor clock.
 * Use once during startup. Requires exclusive ownership of SysTick.
 */
void systick_init_1ms_interrupt(void);

/*
 * Return the software millisecond count maintained by SysTick_Handler.
 * The uint32_t count wraps naturally.
 */
uint32_t systick_get_ms(void);

#endif /* SYSTICK_H_ */
