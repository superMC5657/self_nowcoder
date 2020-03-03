/* -*- coding: utf-8 -*-
  !@time: 2020/3/2 13:18
  !@author: superMC @email: 18758266469@163.com
  !@fileName: bool_operator.cpp
 */
#include <iostream>

using namespace std;

class A {
public:
    A(int a) : _a(a) {}


    operator bool() {
        cout << "operator bool " << _a << endl;
        return _a;

    }

    bool operator==(const bool &other) {
        cout << "bool operator==(const bool &rhs)" << endl;
        return (bool) _a == other;

    }
    bool operator==(const A &other) {
        cout << "bool operator==(const A &other)" << endl;
        return this->_a == other._a;
    }


private:

    int _a;
};

int fun(int argc, char *argv[]) {
    A a(0);
    A b(10);
    A c(20);
    if (a == true) //true 作为bool 调用第二种
        cout << "a == true" << endl;
    if (b == c) //语法从右向左
        cout << "b == c" << endl; //c作为 A 调用第三种
    getchar();
    return 0;
}