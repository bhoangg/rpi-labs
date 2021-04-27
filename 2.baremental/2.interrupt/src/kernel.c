#include "peripherals/BCM2837.h"
#include "irq.h"

const unsigned int interval = 200000;
unsigned int curVal = 0;
unsigned int blinked = 0;

void blink_led(void);
void timer_init(void);
void gpio_init(void);
void enable_interrupt_controller(void);

void kernel_main(void)
{
	irq_vector_init();
	timer_init();
	gpio_init();
	enable_interrupt_controller();
	enable_irq();

	while (1) {
		//TODO
	}
}

void gpio_init(void)
{
	//set gpio17 is output
	GPFSEL1=(GPFSEL1&(~(7<<21)))|(1<<21);
}

void timer_init(void)
{
	curVal = TIMER_CLO;
	curVal += interval;
	TIMER_C1 = curVal;
}

void blink_led(void)
{
	if(!blinked){
		GPSET0=GPSET0|(1<<17);
		blinked = 1;
	}
	else
	{
		GPCLR0=GPCLR0|(1<<17);
		blinked = 0;
	}
}

void enable_interrupt_controller(void)
{
	ENABLE_IRQS_1= SYSTEM_TIMER_IRQ_1;
}

void handle_timer_irq(void) 
{
	blink_led();
	curVal += interval;
	TIMER_C1 = curVal;
	TIMER_CS = TIMER_CS_M1;
}
