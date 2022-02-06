#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>

const int button = 17;
volatile int my_data = 0;
int irq_number = 0;

static irqreturn_t handler(int irq, void *dev)
{
	pr_info("Handler: %d",my_data);
	my_data++;

	return IRQ_HANDLED;
}

static int dummy_init(void)
{
	pr_info("Module init\n");
	gpio_request(button, "sysfs");
	gpio_direction_input(button);
	gpio_set_debounce(button, 100);
	gpio_export(button, false);
	irq_number = gpio_to_irq(button);

	// init interrupt 
	int ret = request_irq(irq_number, handler, IRQF_TRIGGER_RISING, "my_irq", NULL);
	if(ret<0){
		pr_err("Init interrupt error %d",ret);
		return -1;
	}

	return 0;
}

static void dummy_exit(void)
{
	pr_info("Module exit\n");
	free_irq(irq_number, NULL);
}

module_init(dummy_init);
module_exit(dummy_exit);

MODULE_DESCRIPTION("My interrupt");
MODULE_AUTHOR("BINH HOANG");
MODULE_LICENSE("GPL");
