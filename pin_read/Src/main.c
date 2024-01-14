
#include <stdint.h>
#include <stdio.h>

int main(void) {

	uint32_t *const GPIOA_AHB1_RCC = (uint32_t*)(0x40023800 + 0x30);
	uint32_t *const GPIOA_PORT_MODE = (uint32_t*)(0x40020000 + 0x00);
	uint32_t *const GPIOA_PORT_INPUT = (uint32_t*)(0x40020000 + 0x10);
	uint32_t *const GPIOA_PORT_OUTPUT = (uint32_t*)(0x40020000 + 0x14);

	*GPIOA_AHB1_RCC |= 1; // enable clock on AHB1 BUS (for GPIOA)
	*GPIOA_PORT_MODE &= ~(3); // enable PA0 as input
	*GPIOA_PORT_MODE |= (1 << 10); // enable PA5 as output

	while(1) {
		uint32_t input = *GPIOA_PORT_INPUT & 1;
		if(input) {
			*GPIOA_PORT_OUTPUT |= (1 << 5);
		} else {
			*GPIOA_PORT_OUTPUT &= ~(1 << 5);
		}
	}
}
