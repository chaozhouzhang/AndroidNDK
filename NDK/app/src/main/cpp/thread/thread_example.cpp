//
// Created by Administrator on 2021/1/28.
//

#include <jni.h>
#include <pthread.h>
#include <android/log.h>
#include "thread_example.h"


struct ThreadArgs {
    int id;
    int num;

    ThreadArgs(int id, int num) : id(id), num(num) {}
};


void *doInThread(void *args) {
    /*子线程中*/
    /**
     * static_cast是一个c++运算符，功能是把一个表达式转换为某种类型，但没有运行时类型检查来保证转换的安全性。
     */
    ThreadArgs *threadArgs = static_cast<ThreadArgs *>(args);
    __android_log_print(ANDROID_LOG_INFO, "Java_android_stack_ndk_ThreadExample_demoThread",
                        "ThreadArgs %d %d", threadArgs->id, threadArgs->num);
    return nullptr;
}


extern "C"
JNIEXPORT void JNICALL
Java_android_stack_ndk_ThreadExample_demoThread(JNIEnv *env, jclass clazz) {
    pthread_t handle;
    ThreadArgs *threadArgs = new ThreadArgs(1, 2);
    int result = pthread_create(&handle, NULL, doInThread, threadArgs); /*返回0则表示创建成功*/
    __android_log_print(ANDROID_LOG_INFO, "Java_android_stack_ndk_ThreadExample_demoThread",
                        "thread create %s", result == 0 ? "success" : "fail");
}