//
// Created by Administrator on 2021/1/27.
//

#include <android/log.h>
#include "family.h"
#include "baby_event_impl.h"
#include "JS_C_convert.h"
using namespace family;


class parent_impl : public family::IParent {
public:
    void Watch(IBabyEvent *event) {
        __android_log_print(ANDROID_LOG_INFO, "family parent_impl", "Watch");
        baby_event_impl *babyEventImpl = new baby_event_impl();
        babyEventImpl->OnBorn(Gender::FEMALE, 52, 6);
        babyEventImpl->OnCry();
        babyEventImpl->OnHungry();
    }

    void SetAge(int age) {
        __android_log_print(ANDROID_LOG_INFO, "family parent_impl", "SetAge");

    }

    void SetEdu(Edu edu) {
        __android_log_print(ANDROID_LOG_INFO, "family parent_impl", "SetEdu");

    }

    void SetWealth(Wealth wealth) {
        __android_log_print(ANDROID_LOG_INFO, "family parent_impl", "SetWealth");
    }
};


extern "C"
IParent *GetParent() {
    //结构体继承需要使用public继承
    //error: cannot cast 'parent_impl' to its private base class 'family::IParent'
    //返回类型要用IParent，和声明一致
    //error: functions that differ only in their return type cannot be overloaded
    parent_impl *parentImpl = new parent_impl();
    return parentImpl;
}
