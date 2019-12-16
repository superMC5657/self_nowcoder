#include <environment.h>

/* -*- coding: utf-8 -*-
  !@time: 2019/12/8 18:49
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0012_Integer_power.cpp
 */
class Solution {
public:
    static double Power(double base, int exponent) {
        long long p = abs((long long) exponent);
        double r = 1.0;
        while (p) {
            if (p & 1) {
                r *= base;
            }
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1 / r : r;
    }

};

int fun() {
    cout << Solution::Power(5.0, 3) << endl;
}