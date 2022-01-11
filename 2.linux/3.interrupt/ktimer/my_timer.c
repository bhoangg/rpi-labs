#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/timer.h>

volatile int my_data = 0;
struct timer_list my_timer;

void handler_timer(struct timer_list * data)
{
	pr_info("Timer handler: %d",my_data);
	my_data++;

	mod_timer(&my_timer, jiffies + msecs_to_jiffies(2000));
}

static int dummy_init(void)
{
	pr_info("Module init\n");

	// init timer
	timer_setup(&my_timer, handler_timer, 0);
	mod_timer(&my_timer, jiffies + msecs_to_jiffies(2000));
	return 0;
}

static void dummy_exit(void)
{
	pr_info("Module exit\n");
	del_timer(&my_timer);
}

module_init(dummy_init);
module_exit(dummy_exit);

MODULE_DESCRIPTION("My ktimer");
MODULE_AUTHOR("BINH HOANG");
MODULE_LICENSE("GPL");
