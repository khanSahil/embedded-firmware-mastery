/*
 * systick.h
 *
 *  Created on: Oct 11, 2026
 *      Author: sahkhan
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

void systick_init_1ms(void);
void systick_delay_ms(uint32_t milliseconds);

#endif /* SYSTICK_H_ */
