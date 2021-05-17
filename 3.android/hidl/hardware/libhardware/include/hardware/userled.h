#ifndef ANDROID_USERLED_HAL_INTERFACE_H
#define ANDROID_USERLED_HAL_INTERFACE_H

#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <hardware/hardware.h>

__BEGIN_DECLS

#define USERLED_HARDWARE_MODULE_ID "userled"

struct userled_device_t {
    struct hw_device_t common;

    int (*read)(char* buffer, int length);
    int (*write)(char* buffer, int length);
    int (*test)(int value);
};

__END_DECLS

#endif  // ANDROID_USERLED_HAL_INTERFACE_H
