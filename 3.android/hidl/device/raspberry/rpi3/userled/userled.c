#define LOG_TAG "userled"

#include <hardware/userled.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <cutils/log.h>
#include <cutils/atomic.h>
#include <cutils/properties.h>
#include <string.h>
#include <unistd.h>

int fd;

int userled_read(char* buffer, int length)
{
    int retval;

    ALOGD("User Led - read()for %d bytes called", length);

    retval = read(fd, buffer, length);    

    return retval;
}

int userled_write(char* buffer, int length)
{
    int retval;

    ALOGD("User Led - write()for %d bytes called", length);

    retval = write(fd, buffer, length);

    return retval;
}

int userled_test(int value)
{
    return value;
}

static int open_userled(const struct hw_module_t* module, char const* name,
        struct hw_device_t** device)
{
    struct userled_device_t *dev = malloc(sizeof(struct userled_device_t));
    memset(dev, 0, sizeof(*dev));

    dev->common.tag = HARDWARE_DEVICE_TAG;
    dev->common.version = 0;
    dev->common.module = (struct hw_module_t*)module;
    dev->read = userled_read;
    dev->write = userled_write;
    dev->test = userled_test;

    *device = &dev->common;

    fd = open("/sys/class/leds/led0/brightness", O_RDWR);
    if (fd < 0) {
        ALOGE("can not open user-led file\n");
    }
    ALOGD("User Led has been initialized");

    return 0;
}


static struct hw_module_methods_t userled_module_methods = {
    .open = open_userled
};

struct userled_module_t {
    struct hw_module_t common;
};

struct userled_module_t HAL_MODULE_INFO_SYM = {
    .common={
    	.tag = HARDWARE_MODULE_TAG,
    	.version_major = 1,
    	.version_minor = 0,
    	.id = USERLED_HARDWARE_MODULE_ID,
    	.name = "User Led Module",
    	.author = "Binh Hoang.",
    	.methods = &userled_module_methods,
	}
};

