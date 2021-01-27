//
// Created by Administrator on 2021/1/27.
//

#ifndef FAMILY_H
#define FAMILY_H


namespace family {
    extern const char *MAJOR_VERSION;
    extern const char *MINOR_VERSION;
    extern const char *BUILD_VERSION;
    extern const char *VERSION;

    void cry();

    void open_eyes();

    enum Gender {
        MALE = 0,//男
        FEMALE = 1//女
    };
    enum Edu {
        JUNIOR = 0,//专科
        REGULAR = 1,//本科
        MASTER = 2,//硕士
    };
    enum Wealth {
        LOW = 0,//低产
        MIDDLE = 1,//中产
        HIGH = 2,//高产
    };
}
namespace family {
    //宝宝相关事件通知
    struct IBabyEvent {
        /**
         * 出生：性别，身高，体重
         * @param gender
         * @param height
         * @param weight
         */
        virtual void OnBorn(Gender gender, int height, int weight) = 0;//出生
        virtual void OnCry() = 0;//哭
        virtual void OnSmile() = 0;//笑
        virtual void OnShit() = 0;//拉臭臭
        virtual void OnPee() = 0;//尿尿
        virtual void OnHungry() = 0;//肚子饿了
        virtual void OnSleep() = 0;//睡着了

    };

    struct IParent {
        /**
         * 监听宝宝事件
         * @param event
         */
        virtual void Watch(IBabyEvent *event) = 0;//监听
        virtual void SetAge(int age) = 0;//年龄
        virtual void SetEdu(Edu edu) = 0;//学历
        virtual void SetWealth(Wealth wealth) = 0;//财富值
    };

    extern "C" IParent* GetParent();
}

#endif //FAMILY_H
