#include <jni.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <android/log.h>

static const char* LOG_CATEGORY = "LogService-native";

static const char *className = "com/binhht/logservice/LogService";

JNIEXPORT void JNICALL stringFromJNI( JNIEnv *env, jobject thisObj, jstring inJNIStr) {
    // Step 1: Convert the JNI String (jstring) into C-String (char*)
    const char *inCStr = env->GetStringUTFChars(inJNIStr, NULL);

    if (NULL == inCStr) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_CATEGORY ,"Can not get message");
        return;
    }

    // Step 2: Perform its intended operations
    __android_log_print(ANDROID_LOG_DEBUG, LOG_CATEGORY ,"%s", inCStr);
    env->ReleaseStringUTFChars(inJNIStr, inCStr);  // release resources
}

static JNINativeMethod gJni_Methods_table[] = {
        {"stringFromJNI", "(Ljava/lang/String;)V", (void*)stringFromJNI},
};

static int jniRegisterNativeMethods(JNIEnv* env, const char* className,
                                    const JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;

    __android_log_print(ANDROID_LOG_INFO,"JNI","Registering %s natives\n", className);
    clazz = (env)->FindClass( className);
    if (clazz == NULL) {
        __android_log_print(ANDROID_LOG_ERROR,"JNI","Native registration unable to find class '%s'\n", className);
        return -1;
    }

    int result = 0;
    if ((env)->RegisterNatives(clazz, gJni_Methods_table, numMethods) < 0) {
        __android_log_print(ANDROID_LOG_ERROR,"JNI","RegisterNatives failed for '%s'\n", className);
        result = -1;
    }

    (env)->DeleteLocalRef(clazz);
    return result;
}

jint JNI_OnLoad(JavaVM* vm, void* reserved){
    __android_log_print(ANDROID_LOG_INFO, "JNI", "enter jni_onload");

    JNIEnv* env = NULL;
    jint result = -1;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    jniRegisterNativeMethods(env, className, gJni_Methods_table, sizeof(gJni_Methods_table) / sizeof(JNINativeMethod));

    return JNI_VERSION_1_4;
}

