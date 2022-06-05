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
static char trig[500];

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

static ssize_t my_sysfs_trigger_show(struct kobject *kobj, struct kobj_attribute *attr,
                      char *buf)
{
        return sprintf(buf, "%s\n", trig);
}

static ssize_t my_sysfs_trigger_store(struct kobject *kobj, struct kobj_attribute *attr,
                      const char *buf, size_t count)
{
        sscanf(buf, "%s", trig);
	if (strcmp(trig, "read") == 0){
		sysfs_notify(my_kobject, NULL, "data");
	}
    return count;
}

static struct kobj_attribute my_data = __ATTR(data, S_IWUSR|S_IRUSR , my_sysfs_data_show, my_sysfs_data_store);
static struct kobj_attribute my_trigger = __ATTR(trigger, S_IWUSR|S_IRUSR , my_sysfs_trigger_show, my_sysfs_trigger_store);

static int sys_init(void)
{
	int8_t err = -1;

	pr_info("sys_init\n");
	// create /sys/my_sysfs
	my_kobject = kobject_create_and_add("my_sysfs", NULL);
	if(!my_kobject){
		pr_err("can not create /sys/my_sysfs\n");
		return -ENOMEM;
	}

	err = sysfs_create_file(my_kobject, &my_data.attr);
	if(err<0)
	{
		pr_err("can not create /sys/my_sysfs/data\n");
		goto err_create_file;
	}

	err = sysfs_create_file(my_kobject, &my_trigger.attr);
	if(err<0)
	{
		pr_err("can not create /sys/my_sysfs/trigger\n");
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
	sysfs_remove_file(my_kobject, &my_data.attr);
	sysfs_remove_file(my_kobject, &my_trigger.attr);
	kobject_put(my_kobject);
}

module_init(sys_init);
module_exit(sys_exit);
