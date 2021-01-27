//
// Created by Administrator on 2021/1/27.
//

#include <android/log.h>
#include "family.h"

#ifndef NDK_FAMILY_IMPL_H
#define NDK_FAMILY_IMPL_H

#endif //NDK_FAMILY_IMPL_H


using namespace family;


extern void CallbackFunc(const std::string &cb, bool);


class family_impl : public family::IBabyEvent {


    void OnBorn(Gender gender, int height, int weight) {
        __android_log_print(ANDROID_LOG_INFO, "family IBabyEvent", "OnBorn");
    }

};