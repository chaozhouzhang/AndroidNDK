//
// Created by Administrator on 2021/1/27.
//

#include <android/log.h>
#include "family.h"

#ifndef NDK_FAMILY_IMPL_H
#define NDK_FAMILY_IMPL_H

#endif //NDK_FAMILY_IMPL_H


using namespace family;


/**
 * 一般是因为该类继承的抽象类中，有未实现的纯虚函数。
 * allocating an object of abstract class type "IBabyEvent"
 *
 */
class baby_event_impl : public family::IBabyEvent {

public:
    void OnBorn(Gender gender, int height, int weight) {
        __android_log_print(ANDROID_LOG_INFO, "family baby_event_impl", "OnBorn");
    }

    void OnCry() {

        __android_log_print(ANDROID_LOG_INFO, "family baby_event_impl", "OnCry");
    }

    void OnSmile() {

        __android_log_print(ANDROID_LOG_INFO, "family baby_event_impl", "OnSmile");
    }

    void OnShit() {

        __android_log_print(ANDROID_LOG_INFO, "family baby_event_impl", "OnShit");
    }

    void OnPee() {

        __android_log_print(ANDROID_LOG_INFO, "family baby_event_impl", "OnPee");
    }

    void OnHungry() {

        __android_log_print(ANDROID_LOG_INFO, "family baby_event_impl", "OnHungry");
    }

    void OnSleep() {

        __android_log_print(ANDROID_LOG_INFO, "family baby_event_impl", "OnSleep");
    }

};