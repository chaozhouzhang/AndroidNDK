//
// Created by Administrator on 2021/1/28.
//

#ifndef NDK_STRUCT_EXAMPLE_H
#define NDK_STRUCT_EXAMPLE_H

struct _StructExample {

};


struct StructExampleInterface {
    void *fun;
    int (*fun)(_StructExample *);
};


#endif //NDK_STRUCT_EXAMPLE_H
