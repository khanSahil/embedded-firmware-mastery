/*
 * led7.c
 *
 *  Created on: Oct 4, 2026
 *      Author: sahkhan
 */
#include <stdint.h>
#include "led7.h"

#define RCC_AHB4ENR_OFFSET 		0x0E0
#define RCC_BASE_ADDRESS 		0x58024400
#define RCC_AHB4ENR_ADDRESS 	(RCC_BASE_ADDRESS + RCC_AHB4ENR_OFFSET)
#define GPIOJ_EN_BIT			9U

#define GPIOJ_BASE_ADDRESS		0x58022400

#define GPIO_BSRR_OFFSET 		0x18
#define GPIOJ_BSRR_ADDRESS		(GPIOJ_BASE_ADDRESS + GPIO_BSRR_OFFSET)
#define GPIOJ_PIN_BIT			2U

#define GPIO_OTYPER_OFFSET 		0x04
#define GPIOJ_OTYPER_ADDRESS	(GPIOJ_BASE_ADDRESS + GPIO_OTYPER_OFFSET)

#define GPIO_OSPEEDR_OFFSET		0x08
#define GPIOJ_OSPEEDR_ADDRESS	(GPIOJ_BASE_ADDRESS + GPIO_OSPEEDR_OFFSET)
#define GPIOJ_OSPEEDR_MASK		((1U << 4) | (1U << 5))

#define GPIO_PUPDR_OFFSET		0x0C
#define GPIOJ_PUPDR_ADDRESS		(GPIOJ_BASE_ADDRESS + GPIO_PUPDR_OFFSET)
#define GPIOJ_PUPDR_MASK		((1U << 4) | (1U << 5))

#define GPIO_MODER_OFFSET		0x00
#define GPIOJ_MODER_ADDRESS		(GPIOJ_BASE_ADDRESS + GPIO_MODER_OFFSET)

void led7_init(void)
{
	// enabling CLK for PortJ
	volatile uint32_t *pRCC_AHB4ENR = (volatile uint32_t*)RCC_AHB4ENR_ADDRESS;
	*pRCC_AHB4ENR |= (1U << GPIOJ_EN_BIT);
	(void)*pRCC_AHB4ENR;

	// setting initial Output Value using BSRR for PJ2
	volatile uint32_t *pBSRR_GPIOJ = (volatile uint32_t*)GPIOJ_BSRR_ADDRESS;
	*pBSRR_GPIOJ = (1U << GPIOJ_PIN_BIT);

	// setting push-pull configuration for PJ2
	volatile uint32_t *pOTYPER_GPIOJ = (volatile uint32_t*)GPIOJ_OTYPER_ADDRESS;
	*pOTYPER_GPIOJ &= ~(1U << GPIOJ_PIN_BIT);

	// setting low speed for PJ2
	volatile uint32_t *pOSPEEDR_GPIOJ = (volatile uint32_t*)GPIOJ_OSPEEDR_ADDRESS;
	*pOSPEEDR_GPIOJ &= ~(GPIOJ_OSPEEDR_MASK);

	// disabling pull-down/pull-up for PJ2
	volatile uint32_t *pPUPDR_GPIOJ = (volatile uint32_t*)GPIOJ_PUPDR_ADDRESS;
	*pPUPDR_GPIOJ &= ~(GPIOJ_PUPDR_MASK);

	// Setting PJ2 as General Purpose Output
	volatile uint32_t *pMODER_GPIOJ = (volatile uint32_t*)GPIOJ_MODER_ADDRESS;
	*pMODER_GPIOJ = (*pMODER_GPIOJ & ~(3U << 4)) | (1U << 4);

}

void led7_on(void)
{
	volatile uint32_t *pBSRR_GPIOJ = (volatile uint32_t*)GPIOJ_BSRR_ADDRESS;
	*pBSRR_GPIOJ = (1U << 18);
}

void led7_off(void)
{
	volatile uint32_t *pBSRR_GPIOJ = (volatile uint32_t*)GPIOJ_BSRR_ADDRESS;
	*pBSRR_GPIOJ = (1U << 2);
}
