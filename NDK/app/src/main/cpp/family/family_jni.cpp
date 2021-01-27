//
// Created by Administrator on 2021/1/27.
//
#include <jni.h>
#include <string>
#include "family.h"
#include "family_impl.h"

using namespace family;


static family_impl familyImpl;


extern "C"
JNIEXPORT jstring JNICALL
Java_android_stack_ndk_Family_init(JNIEnv *env, jclass clazz, jobject context, jstring str) {
    family::GetParent()->Watch(&familyImpl);
    family::GetParent()->SetAge(30);
    family::GetParent()->SetEdu(family::Edu::MASTER);
    family::GetParent()->SetWealth(family::Wealth::MIDDLE);
}