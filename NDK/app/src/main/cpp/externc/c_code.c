//
// Created by Administrator on 2021/1/27.
//

// 注意： 该代码是C程序， 请放在.c文件中， 这样确保是C编译器

#include <stdio.h>

/**
 * 如果不添加此声明，在编译的时候讲会报错：
 * error: conflicting types for 'fun'
 */
void fun();

int main()
{
    fun();
    return 0;
}

void fun(){
    printf("ok\n");
}