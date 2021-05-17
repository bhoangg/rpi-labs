# include <android/hardware/simple/2.0/ISimphw.h>

# include <hidl/Status.h>

# include <hidl/LegacySupport.h>

# include <utils/misc.h>

# include <hidl/HidlSupport.h>

# include <stdio.h>

using android::hardware::simple::V2_0::ISimphw;
using android::sp;
using android::hardware::hidl_string;

int main()
{

    android::sp<ISimphw> service = ISimphw::getService();
    if(service == nullptr) {
        printf("Failed to get service\n");
        return -1;
    }

    service->helloWorld("JayZhang", [&](hidl_string result) {
                printf("%s\n", result.c_str());
        });

    return 0;
}
