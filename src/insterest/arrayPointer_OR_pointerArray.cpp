/* -*- coding: utf-8 -*-
  !@time: 2020/3/1 13:16
  !@author: superMC @email: 18758266469@163.com
  !@fileName: pointer.cpp
 */
#include <environment.h>

int fun() {
    int a = 1, b = 2;
    int *pa = &a;
    int *pb = &b;
    int *p1[10] = {pa, pb};//指针数组 一个全部都是指针的数组
    int temp[10] = {a, b};
    int *pc = temp;
    int (*p2)[10] = &temp;//数组指针 一个数组的指针
    int *pd = new int[10];
    int *pd_copy = pd;
    for (int i = 0; i < 10; ++i) {
        pd[i] = i + 1;
    }
    cout << *(pc + 1) << endl;
    cout << (*p2)[1] << endl;
    delete[] pd; // 不是删除,....
    cout << pd[0] << endl;
    pd = nullptr; //安全代码
    cout << pd_copy[0] << endl;
    return 0;
}