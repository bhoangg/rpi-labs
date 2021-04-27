#ifndef	_IRQ_H
#define	_IRQ_H

void irq_vector_init( void );
void enable_irq( void );
void disable_irq( void );

void handle_timer_irq(void) ;

#endif  /*_IRQ_H */
