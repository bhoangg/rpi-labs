#include "Simphw.h"

#if 0
#include <log/log.h>
#include <hardware/hardware.h>
#include <hardware/userled.h>
#endif

namespace android {
namespace hardware {
namespace simple {
namespace V2_0 {
namespace implementation {

// Methods from ::android::hardware::simple::V2_0::ISimphw follow.
Return<void> Simphw::helloWorld(const hidl_string& name, helloWorld_cb _hidl_cb) {
    // TODO implement
    char buf[100];

#if 0   
    {
	int err; 
        char ledon[] = "1";
        userled_device_t* dev = NULL;
        struct hw_module_t* module;

        ALOGD("hello: [User] debug 1\n");

        err = hw_get_module(USERLED_HARDWARE_MODULE_ID, (hw_module_t const**)&module);
        if (err) {
            ALOGE("hello: hw_get_module failed: %d", err);
        } else {
            ALOGD("hello: [User] debug 2\n");
            if (module->methods->open(module, "", ((hw_device_t**) &dev)) != 0) {
            ALOGE("hello: [User] debug 3\n");
            return Void();
            }
        }

        dev->write(ledon, 1);
    }
#endif

    ::memset(buf, 0x00, 100);
    ::snprintf(buf, 100, "Hello World, %s", name.c_str());
    hidl_string result(buf);

    _hidl_cb(result);
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//ISimphw* HIDL_FETCH_ISimphw(const char* /* name */) {
    //return new Simphw();
//}
//
}  // namespace implementation
}  // namespace V2_0
}  // namespace simple
}  // namespace hardware
}  // namespace android
