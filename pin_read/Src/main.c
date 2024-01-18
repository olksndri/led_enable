#include <stdint.h>
#include <stdio.h>
#include "main.h"

RCC_AHB1ENR_t volatile *const RCC_AHB1ENR 	= (RCC_AHB1ENR_t*)(0x40023800 + 0x30);
GPIOx_MODER_t volatile *const GPIOA_MODER 	= (GPIOx_MODER_t*)(0x40020000 + 0x00);
GPIOx_IDR_t volatile *const GPIOA_IDR 		= (GPIOx_IDR_t*)(0x40020000 + 0x10);
GPIOx_ODR_t volatile *const GPIOA_ODR 		= (GPIOx_ODR_t*)(0x40020000 + 0x14);

int main(void) {
	RCC_AHB1ENR->GPIOA_EN 	|= 1; // enable clock on AHB1 BUS (for GPIOA)
	GPIOA_MODER->MODER0 	&= 0; 	// set PA0 mode as input
	GPIOA_MODER->MODER5 	|= 1; 	// set PA5 mode as output

	while(1) {
		if (GPIOA_IDR->IDR0 & 1) GPIOA_ODR->ODR5 |= 1;
		else GPIOA_ODR->ODR5 &= 0;
	}
}

