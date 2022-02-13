#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/of.h>

static unsigned int gpio_led;
static int irq;

static const struct of_device_id blink_led_of_match[] = {
	{ .compatible = "my-led-2", .data = (void *)"my data" },
	{ },
};

static int blink_led_probe(struct platform_device *pdev)
{
	pr_info("Module init\n");
	int ret;
	struct device_node *np = pdev->dev.of_node;

	if(!np)
		return ERR_PTR(-ENOENT);

	gpio_led = of_get_named_gpio(np, "led-gpios", 0);

	pr_info("binhht: gpio:%d",gpio_led);

	gpio_request(gpio_led, "my-led");
	gpio_direction_output(gpio_led, 0);
	pr_info("echo  1 > gpio17\n");
	gpio_set_value(gpio_led, 1);
	
	return 0;
}

static int blink_led_remove(struct platform_device *pdev)
{
	pr_info("Module exit\n");
	pr_info("echo  0 > gpio17\n");
	gpio_set_value(gpio_led, 0);
	return 0;
}

static struct platform_driver blink_led_driver = {
	.probe		= blink_led_probe,
	.remove		= blink_led_remove,
	.driver		= {
		.name	= "blink_led",
		.of_match_table = blink_led_of_match,
	},
};

module_platform_driver(blink_led_driver);

MODULE_DESCRIPTION("My device tree module");
MODULE_AUTHOR("BINH HOANG");
MODULE_LICENSE("GPL");
