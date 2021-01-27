//
// Created by Administrator on 2021/1/27.
//
// 注意： 该代码是C++程序， 请放在.cpp文件中， 这样确保是C++编译器


#include <stdio.h>

/**
 *
 *  extern "C"针对不是C编译器/链接器， 而是C++编译器/链接器------>在C++编译器编译的时候， 按C规范编译， 在C++链接器链接的时候， 按C规范查找/链接。
 */
extern "C" void fun(); // 暂时骗过C++编译器, 并对链接器说， 你要按照C规范链接， 去找_fun, 而不是"?fun@@YAXXZ"