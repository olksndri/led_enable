#include <stdint.h>
#include <stdio.h>

int main(void) {
	uint32_t volatile *const pGPIOA_AHB1_RCC_REG 		= (uint32_t*)(0x40023800 + 0x30);
	uint32_t volatile *const pGPIOA_PORT_MODE_REG 		= (uint32_t*)(0x40020000 + 0x00);
	uint32_t const volatile *const pGPIOA_PORT_IN_REG 	= (uint32_t*)(0x40020000 + 0x10);
	uint32_t volatile *const pGPIOA_PORT_OUT_REG 		= (uint32_t*)(0x40020000 + 0x14);

	*pGPIOA_AHB1_RCC_REG 	|= 1; // enable clock on AHB1 BUS (for GPIOA)
	*pGPIOA_PORT_MODE_REG	&= ~(3); // set PA0 mode as input
	*pGPIOA_PORT_MODE_REG 	|= (1 << 10); // set PA5 mode as output

	while(1) {
		if (*pGPIOA_PORT_IN_REG & 1) *pGPIOA_PORT_OUT_REG |= (1 << 5);
		else *pGPIOA_PORT_OUT_REG &= ~(1 << 5);
	}
}
