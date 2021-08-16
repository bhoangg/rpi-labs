#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>

#define LED	17
#define GPFSEL1_OFFSET  0x04
#define GPSET0_OFFSET   0x1C
#define GPCLR0_OFFSET   0x28

void __iomem *gpio_base;

static const struct of_device_id blink_led_of_match[] = {
	{ .compatible = "my-led", .data = (void *)LED },
	{ },
};

static int blink_led_probe(struct platform_device *pdev)
{
	pr_info("Module init\n");

	struct resource *res = NULL;
	const struct of_device_id *of_id = NULL;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	gpio_base = ioremap(res->start, res->end - res->start);
	if(gpio_base == NULL)
	{
		pr_err("Can not map to virtual address\n");
		return -ENOMEM;
	}
	pr_info("gpio_base address: 0x%x\n",gpio_base);

	of_id = of_match_device(blink_led_of_match, &pdev->dev);
	
	pr_info("set gpio%d is output\n", of_id->data);
	unsigned int GPFSEL1 = ioread32(gpio_base+GPFSEL1_OFFSET);
	iowrite32((GPFSEL1&(~(7 << 21)))|(1 <<21), gpio_base+GPFSEL1_OFFSET);

	pr_info("echo  1 > gpio%d\n", of_id->data);
	unsigned int GPSET0 = ioread32(gpio_base+GPSET0_OFFSET);
	iowrite32(GPSET0|(1 << 17), gpio_base+GPSET0_OFFSET);
	
	return 0;
}

static int blink_led_remove(struct platform_device *pdev)
{
	pr_info("Module exit\n");
	pr_info("echo  0 > gpio17\n");
	unsigned int GPCLR0 = ioread32(gpio_base+GPCLR0_OFFSET);
	iowrite32(GPCLR0|(1 << 17), gpio_base+GPCLR0_OFFSET);

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