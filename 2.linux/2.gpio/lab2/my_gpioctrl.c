#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/gpio.h>

#define LED_PIN	17

static int dummy_init(void)
{
	pr_info("Module init\n");

	int ret;
	ret = gpio_request_one(LED_PIN, GPIOF_OUT_INIT_LOW, NULL);
	if (ret < 0) {
		printk(KERN_ALERT "Error requesting GPIO\n");
		return -ENODEV;
	}
	pr_info("echo  1 > gpio17\n");
	gpio_direction_output(LED_PIN, 0);
	gpio_set_value(LED_PIN, 1);
	
	return 0;
}

static void dummy_exit(void)
{
	pr_info("Module exit\n");
	pr_info("echo  0 > gpio17\n");
	gpio_set_value(LED_PIN, 0);
	gpio_free(LED_PIN);

}

module_init(dummy_init);
module_exit(dummy_exit);

MODULE_DESCRIPTION("My gpio ctrl module");
MODULE_AUTHOR("BINH HOANG");
MODULE_LICENSE("GPL");
