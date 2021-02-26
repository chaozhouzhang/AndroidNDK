//
// Created by Administrator on 2/26/2021.
//

//C++程序被组织成类，而类由成员函数和成员变量组成。
//C++程序的组成部分；
//各部分如何协同工作；
//函数及其用途；
//基本输入输出操作。

/**
 * #include
 * Preprocessor directive
 * 预处理器编译指令
 * 预处理器是一个在编译前运行的工具。预处理器编译指令是向预处理器发出的命令，总是以字符#开头。
 * 让预处理器获取指定文件的内容，并将内容放在在编译指令所处的位置。
 * iostream是一个标准头文件，编译器之所以能够编译std::cout，是因为#include <iostream>指示预处理器包含了std::cout的定义。
 * 使用引号而不是尖括号来包含自己创建的头文件。尖括号（<>）通常用于包含标准头文件。
 */
#include <iostream>

int main() {

    /**
     * cout是在名称空间std中定义的一个流，控制台输出流
     * 使用流插入运算符<<将文本Hello World放到这个流中
     * std::endl用于换行，将其插入流中相当于插入回车
     */
    std::cout << "hello world" << std::endl;

    return 0;
}