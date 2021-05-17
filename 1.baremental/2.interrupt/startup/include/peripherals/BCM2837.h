#ifndef __BCM2837__
#define __BCM2837__

#define GPIO_BASE_ADDR  (0x3F000000)

/*************GPIO*************/
#define GPFSEL1         *((unsigned int *)(GPIO_BASE_ADDR+0x200004))
#define GPSET0          *((unsigned int *)(GPIO_BASE_ADDR+0x20001C))
#define GPCLR0          *((unsigned int *)(GPIO_BASE_ADDR+0x200028))

/*************TIMER*************/
#define TIMER_CS        *((unsigned int *)(GPIO_BASE_ADDR+0x00003000))
#define TIMER_CLO       *((unsigned int *)(GPIO_BASE_ADDR+0x00003004))
#define TIMER_CHI       *((unsigned int *)(GPIO_BASE_ADDR+0x00003008))
#define TIMER_C0        *((unsigned int *)(GPIO_BASE_ADDR+0x0000300C))
#define TIMER_C1        *((unsigned int *)(GPIO_BASE_ADDR+0x00003010))
#define TIMER_C2        *((unsigned int *)(GPIO_BASE_ADDR+0x00003014))
#define TIMER_C3        *((unsigned int *)(GPIO_BASE_ADDR+0x00003018))

#define TIMER_CS_M0	(1 << 0)
#define TIMER_CS_M1	(1 << 1)
#define TIMER_CS_M2	(1 << 2)
#define TIMER_CS_M3	(1 << 3)

/**************IRQ**************/
#define IRQ_BASIC_PENDING	*((unsigned int *)(GPIO_BASE_ADDR+0x0000B200))
#define IRQ_PENDING_1		*((unsigned int *)(GPIO_BASE_ADDR+0x0000B204))
#define IRQ_PENDING_2		*((unsigned int *)(GPIO_BASE_ADDR+0x0000B208))
#define FIQ_CONTROL         *((unsigned int *)(GPIO_BASE_ADDR+0x0000B20C))
#define ENABLE_IRQS_1		*((unsigned int *)(GPIO_BASE_ADDR+0x0000B210))
#define ENABLE_IRQS_2		*((unsigned int *)(GPIO_BASE_ADDR+0x0000B214))
#define ENABLE_BASIC_IRQS	*((unsigned int *)(GPIO_BASE_ADDR+0x0000B218))
#define DISABLE_IRQS_1		*((unsigned int *)(GPIO_BASE_ADDR+0x0000B21C))
#define DISABLE_IRQS_2		*((unsigned int *)(GPIO_BASE_ADDR+0x0000B220))
#define DISABLE_BASIC_IRQS	*((unsigned int *)(GPIO_BASE_ADDR+0x0000B224))

#define SYSTEM_TIMER_IRQ_0	(1 << 0)
#define SYSTEM_TIMER_IRQ_1	(1 << 1)
#define SYSTEM_TIMER_IRQ_2	(1 << 2)
#define SYSTEM_TIMER_IRQ_3	(1 << 3)

#endif  /*__BCM2837__*/
