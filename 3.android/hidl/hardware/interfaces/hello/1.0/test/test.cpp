# include <android/hardware/hello/1.0/IHello.h>

# include <hidl/Status.h>

# include <hidl/LegacySupport.h>

# include <utils/misc.h>

# include <hidl/HidlSupport.h>

# include <stdio.h>

using android::hardware::hello::V1_0::IHello;
using android::sp;
using android::hardware::hidl_string;

int main()
{

    android::sp<IHello> service = IHello::getService();
    if(service == nullptr) {
        printf("Failed to get service\n");
        return -1;
    }

    service->helloWorld("JayZhang", [&](hidl_string result) {
                printf("%s\n", result.c_str());
        });

    return 0;
}
