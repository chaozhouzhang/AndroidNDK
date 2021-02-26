#ifndef __JS_C_CONVERT_H__
#define __JS_C_CONVERT_H__

#include <string.h>
#include <string>
#include <jni.h>
/**
 * 函数原型
void *memcpy(void *destin, void *source, unsigned n);
参数
destin-- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针。
source-- 指向要复制的数据源，类型强制转换为 void* 指针。
n-- 要被复制的字节数。
返回值
该函数返回一个指向目标存储区destin的指针。
功能
从源source所指的内存地址的起始位置开始拷贝n个字节到目标destin所指的内存地址的起始位置中。
所需头文件
C：#include<string.h>
C++：#include<cstring>
 */
/**
 * 此头文件需要被include了，才能在IDE中正常显示，否则IDE会报错
 */
/**
 * jstring 转 std::string
 * @param env
 * @param jstr
 * @return
 */
__inline std::string js2c(JNIEnv *env, jstring jstr) {
    std::string str = "";
    if (jstr == NULL)
        return str;
    //获取String类
    jclass clsstring = env->FindClass("java/lang/String");
    //获取utf-8编码
    jstring strencode = env->NewStringUTF("utf-8");
    //获取String类的getBytes方法
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    //调用String类的getBytes方法得到byte数组
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    //获取byte数组长度
    jsize alen = env->GetArrayLength(barr);
    //获取bytes数组元素
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    //如果bytes数组长度大于0
    if (alen > 0) {
        //分配大小
        str.resize(alen);
        //memcpy指的是C和C++使用的内存拷贝函数，函数原型为void *memcpy(void *destin, void *source, unsigned n)；
        //函数的功能是从源内存地址的起始位置开始拷贝若干个字节到目标内存地址中，即从源source中拷贝n个字节到目标destin中。
        memcpy((char *) str.data(), ba, alen);
    }
    //释放byte数组元素
    env->ReleaseByteArrayElements(barr, ba, 0);
    return str;
}
/**
 * char* 转 jstring
 * @param env
 * @param pat
 * @return
 */
__inline jstring c2js(JNIEnv *env, const char *pat) {
    //獲取String類
    jclass strClass = env->FindClass("java/lang/String");
    //获取String的构造方法
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    //获取字符串的长度strlen
    //新建一个byte数组
    jbyteArray bytes = env->NewByteArray(strlen(pat));
    //设置byte数组范围
    env->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte *) pat);
    //utf编码
    jstring encoding = env->NewStringUTF("utf-8");
    //创建一个String对象
    return (jstring) env->NewObject(strClass, ctorID, bytes, encoding);
}

#endif //__JS_C_CONVERT_H__
