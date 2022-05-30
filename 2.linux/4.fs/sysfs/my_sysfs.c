#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/fs.h>

MODULE_DESCRIPTION("My sysfs module");
MODULE_AUTHOR("BINH HOANG");
MODULE_LICENSE("GPL");

static struct kobject *my_kobject = NULL;
static struct my_data {
	int foo;
	char bar[500];
};

static char bar[500];

static ssize_t my_sysfs_data_show(struct kobject *kobj, struct kobj_attribute *attr,
                      char *buf)
{
        return sprintf(buf, "%s\n", bar);
}

static ssize_t my_sysfs_data_store(struct kobject *kobj, struct kobj_attribute *attr,
                      const char *buf, size_t count)
{
        sscanf(buf, "%s", bar);
        return count;
}

static struct kobj_attribute my_attr = __ATTR(my_sysfs_data, S_IWUSR|S_IRUSR , my_sysfs_data_show, my_sysfs_data_store);

static int sys_init(void)
{
	pr_info("sys_init\n");

	int err = -1;

	// create /sys/my_sysfs
	my_kobject = kobject_create_and_add("my_sysfs", NULL);
	if(!my_kobject){
		pr_err("can not create /sys/my_sysfs\n");
		return -ENOMEM;
	}

	err = sysfs_create_file(my_kobject, &my_attr.attr);
	if(err<0)
	{
		pr_err("can not create /sys/my_sysfs/my_sysfs_data\n");
		goto err_create_file;
	}

	return 0;

err_create_file:
	kobject_put(my_kobject);
	return err;
}

static void sys_exit(void)
{
	pr_info("sys_exit\n");
	kobject_put(my_kobject);
	sysfs_remove_file(my_kobject, &my_attr.attr);
}

module_init(sys_init);
module_exit(sys_exit);

