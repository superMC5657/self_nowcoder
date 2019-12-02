/* -*- coding: utf-8 -*-
  !@time: 2019-12-02 02:58
  !@author: superMC @email: 18758266469@163.com
  !@fileName: callBack.cpp
 */
#include<stdio.h>

typedef void(*ptrFun)(char *);//用typedef定义函数指针，也将其成为新的类型
void CallerFun(ptrFun fun)//父函数
{
    printf("==Start callback fun==\n");
    fun("Hi callback function");
    printf("==End callback fun==\n");
}

void CallbackFun(char *num)//回调函数
{
    printf("%s\n", num);
}

int fun() {
    /* 调用 方法一 */
    ptrFun PP = CallbackFun;
    CallerFun(PP);
//    int b = 5;
//    int *a = &b;
//    int **c = &a;

    /* 调用方法二 */
    CallerFun(CallbackFun);//直接作为参数也是没问题的
    return 0;
}