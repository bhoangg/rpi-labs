# define LOG_TAG "android.hardware.hello@1.0-service"

# include <android/hardware/hello/1.0/IHello.h>

# include <hidl/LegacySupport.h>

using android::hardware::hello::V1_0::IHello;
using android::hardware::defaultPassthroughServiceImplementation;

int main() {
    return defaultPassthroughServiceImplementation<IHello>();
}
