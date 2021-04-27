#include "peripherals/BCM2837.h"
#include "irq.h"

void invalid_entry_irq(int type, unsigned long esr, unsigned long address)
{
	//TODO
}

void handle_irq(void)
{
	unsigned int irq = IRQ_PENDING_1;
	switch (irq) {
		case (SYSTEM_TIMER_IRQ_1):
			handle_timer_irq();
			break;
		default:
			//TODO
			break;
	}
}
