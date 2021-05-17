#include "Hello.h"
#include <log/log.h>
#include <hardware/hardware.h>
#include <hardware/userled.h>

namespace android {
namespace hardware {
namespace hello {
namespace V1_0 {
namespace implementation {

userled_device_t* dev = NULL;

// Methods from ::android::hardware::hello::V1_0::IHello follow.
Return<void> Hello::helloWorld(const hidl_string& name, helloWorld_cb _hidl_cb) {
    // TODO implement
    char buf[100];
    char ledon[] = "1";

    dev->write(ledon, 1);
    ::memset(buf, 0x00, 100);
    ::snprintf(buf, 100, "Hello World, %s", name.c_str());
    hidl_string result(buf);

    _hidl_cb(result);
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

IHello* HIDL_FETCH_IHello(const char* /* name */) {
    int err;
    struct hw_module_t* module;

    ALOGD("hello: [User] debug 1\n");
//    printf("[User] debug 1\n");

    err = hw_get_module(USERLED_HARDWARE_MODULE_ID, (hw_module_t const**)&module);
    if (err) {
            ALOGE("hello: hw_get_module failed: %d", err);
           // printf("hw_get_module() failed (%s)\n", strerror(-err));
    } else {
            ALOGD("hello: [User] debug 2\n");
//            printf("[User] debug 2\n");
            if (module->methods->open(module, "", ((hw_device_t**) &dev)) != 0) {
              ALOGE("hello: [User] debug 3\n");
//            printf("[User] debug 3n");
                    return 0;
            }
    }

    return new Hello();
}
//
}  // namespace implementation
}  // namespace V1_0
}  // namespace hello
}  // namespace hardware
}  // namespace android
