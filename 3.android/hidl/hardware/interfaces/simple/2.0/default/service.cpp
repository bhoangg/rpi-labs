#define LOG_TAG "android.hardware.simple@2.0-service"

#include <android/hardware/simple/2.0/ISimphw.h>
#include <hidl/LegacySupport.h>
#include <hidl/HidlTransportSupport.h>

#include "Simphw.h"

using android::hardware::simple::V2_0::ISimphw;
using android::hardware::simple::V2_0::implementation::Simphw;
using android::hardware::defaultPassthroughServiceImplementation;
using android::hardware::joinRpcThreadpool;
using android::hardware::configureRpcThreadpool;
using android::sp;

int main()
{
	sp<ISimphw> service = new Simphw();
	configureRpcThreadpool(1, true);
	if(android::OK !=  service->registerAsService())
		return 1;

	joinRpcThreadpool();

	return 0;
}
