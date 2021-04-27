#include "utils.h"

#define GPIO_BASE_ADDR  (0x3F200000)
#define GPFSEL1         *((unsigned int *)(GPIO_BASE_ADDR+0x04))
#define GPSET0          *((unsigned int *)(GPIO_BASE_ADDR+0x1C))
#define GPCLR0          *((unsigned int *)(GPIO_BASE_ADDR+0x28))

void kernel_main(void)
{
	//set gpio17 is output
	GPFSEL1=(GPFSEL1&(~(7<<21)))|(1<<21);
	while (1) {
		GPSET0=GPSET0|(1<<17);
		delay(1000000);
		GPCLR0=GPCLR0|(1<<17);
		delay(1000000);
	}
}
