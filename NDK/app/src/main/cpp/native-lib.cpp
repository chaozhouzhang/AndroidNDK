#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_android_stack_ndk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello NDK.";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jint JNICALL
Java_android_stack_ndk_MainActivity_plus(JNIEnv *env, jclass clazz, jint a, jint b) {
    // TODO: implement plus()
    jint sum = a+b;
    return sum;
}

