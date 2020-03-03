/* -*- coding: utf-8 -*-
 !@time: 2020/3/2 13:11
 !@author: superMC @email: 18758266469@163.com
 !@fileName: operator_bool.cpp
*/
#include <iostream>

using namespace std;

class A {
public:
    A(int a) : _a(a) {}

    operator bool() {
        //在执行把自己当做bool参数时 执行

        cout << "operator bool" << endl;
        return _a;
    }

private:
    int _a;
};

int fun(int argc, char *argv[]) {
    A a(0);
    A b(10);
    if (a)
        cout << "a" << endl;
    if (a == b)//由此可见，在判断if(a == b)时，先把a、b分别转换为bool类型再进行判断。
        cout << "asdasddsa" << endl;
    getchar();
    return 0;
}