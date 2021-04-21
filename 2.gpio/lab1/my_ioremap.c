#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/io.h>

#define GPIO_BASE_ADDR  0x3F200000
#define MEM_SZ          0x100

#define GPFSEL1_OFFSET  0x04
#define GPSET0_OFFSET   0x1C
#define GPCLR0_OFFSET   0x28

void __iomem *gpio_base;

static int dummy_init(void)
{
	pr_info("Module init\n");

	gpio_base = ioremap(GPIO_BASE_ADDR, MEM_SZ);
	if(gpio_base == NULL)
	{
		pr_err("Can not map to virtual address\n");
		return -ENOMEM;
	}
	pr_info("gpio_base address: 0x%x\n",gpio_base);
	
	pr_info("set gpio17 is output\n");
	unsigned int GPFSEL1 = ioread32(gpio_base+GPFSEL1_OFFSET);
	iowrite32((GPFSEL1&(~(7 << 21)))|(1 <<21), gpio_base+GPFSEL1_OFFSET);

	pr_info("echo  1 > gpio17\n");
	unsigned int GPSET0 = ioread32(gpio_base+GPSET0_OFFSET);
	iowrite32(GPSET0|(1 << 17), gpio_base+GPSET0_OFFSET);

	return 0;
}

static void dummy_exit(void)
{
	pr_info("Module exit\n");
	pr_info("echo  0 > gpio17\n");
	unsigned int GPCLR0 = ioread32(gpio_base+GPCLR0_OFFSET);
	iowrite32(GPCLR0|(1 << 17), gpio_base+GPCLR0_OFFSET);

	iounmap(gpio_base);
}

module_init(dummy_init);
module_exit(dummy_exit);

MODULE_DESCRIPTION("My ioremap module");
MODULE_AUTHOR("BINH HOANG");
MODULE_LICENSE("GPL");
