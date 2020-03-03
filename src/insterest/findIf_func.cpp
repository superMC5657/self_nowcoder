/* -*- coding: utf-8 -*-
  !@time: 2020/3/2 12:58
  !@author: superMC @email: 18758266469@163.com
  !@fileName: findIf_func.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

struct C {
    C() : v1(0), v2(0) {}

    C(const int &val1, const int &val2) : v1(val1), v2(val2) {

    }

    C operator()(const int &val1, const int &val2) { //重载构造方法
        v1 = val1;
        v2 = val2;
        return *this;
    }

    ~C() = default;

    int v1;
    int v2;
};


template<int n> //只能传入常数
class CComp {
public:
    bool operator()(const C &lhs) {
        return (lhs.v2 == n);
    }
};

int fun(int argc, char *argv[]) {
    vector<C> cv;
    C val;
    C c(1, 2);
    cv.emplace_back(0, 10);
    cv.push_back(val(1, 100));
    cv.push_back(val(2, 52));
    cv.push_back(val(3, 25));
    cv.push_back(val(4, 75));
    cv.push_back(val(5, 84));
    cv.push_back(val(6, 33));

    auto cvIter = find_if(cv.begin(), cv.end(), CComp<75>());
    cout << cvIter->v1 << "  " << cvIter->v2 << endl;
    cout << endl;

    system("PAUSE");
    return 0;
}