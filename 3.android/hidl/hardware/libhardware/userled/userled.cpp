#define LOG_TAG "UserledService"

#include <utils/misc.h>
#include <utils/Log.h>
#include <map>
#include <stdio.h>
#include <hardware/userled.h>

int main()
{
        int err;
        struct hw_module_t* module;
        userled_device_t* dev = NULL;
        int status;
	char test[] = "1";

        printf("[User] debug 1\n");

        err = hw_get_module(USERLED_HARDWARE_MODULE_ID, (hw_module_t const**)&module);
        if (err) {
                printf("hw_get_module() failed (%s)\n", strerror(-err));
        } else {
                printf("[User] debug 2\n");
                if (module->methods->open(module, "", ((hw_device_t**) &dev)) != 0) {
                printf("[User] debug 3n");
                        return 0;
                }
        }

        status = dev->write(test, 1);
        printf("status: %d\n", status);

        return 0;
}

