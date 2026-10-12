/*
 * systick.h
 *
 *  Created on: Oct 11, 2026
 *      Author: sahkhan
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#define SYSTICK_CYCLES_PER_MS 0xFA00U
#define SYSTICK_CLEAR_VALUE 0x0U

#include <stdint.h>

void systick_init_1ms(void);
void systick_delay_ms(uint32_t milliseconds);

#endif /* SYSTICK_H_ */
