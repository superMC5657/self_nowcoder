/* -*- coding: utf-8 -*-
  !@time: 2020/3/4 23:16
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0047_n_sum.cpp
 */
#include <environment.h>

class Solution {
public:
    int Sum_Solution(int n) {
        int ret = n;
        ret && (ret += Sum_Solution(n - 1)); //&&就是逻辑与，逻辑与有个短路特点，前面为假，后面不计算。
        return ret;
    }
};

int fun() {
    return 0;
}