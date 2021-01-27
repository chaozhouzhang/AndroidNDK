//
// Created by Administrator on 2021/1/27.
//
#include <jni.h>
#include <string>
#include "family.h"
#include "baby_event_impl.h"

using namespace family;


static baby_event_impl babyEventImpl;


extern "C"
JNIEXPORT void JNICALL
Java_android_stack_ndk_Family_init(JNIEnv *env, jclass clazz, jobject context) {
    family::GetParent()->Watch(&babyEventImpl);
    family::GetParent()->SetAge(30);
    family::GetParent()->SetEdu(family::Edu::MASTER);
    family::GetParent()->SetWealth(family::Wealth::MIDDLE);
}