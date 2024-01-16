#include <stdio.h>
#include <stdint.h>

uint32_t volatile *const RCC_AHB1ENR		= (uint32_t*)(0x40023800 + 0x30);
uint32_t volatile *const GPIOA_MODER 		= (uint32_t*)(0x40020000 + 0x00);
uint32_t volatile *const GPIOC_MODER 		= (uint32_t*)(0x40020800 + 0x00);
uint32_t volatile *const GPIOA_ODR 			= (uint32_t*)(0x40020000 + 0x14);
uint32_t const volatile *const GPIOC_IDR 	= (uint32_t*)(0x40020800 + 0x10);

int main(void) {
	*RCC_AHB1ENR |= 5;
	*GPIOA_MODER |= (1 << 10);
	*GPIOC_MODER &= ~(3 << 26);

	while(1) {
		if(!((*GPIOC_IDR >> 13) & 1)) *GPIOA_ODR |= (1 << 5);
		else *GPIOA_ODR &= ~(1 << 5);
	}
}
