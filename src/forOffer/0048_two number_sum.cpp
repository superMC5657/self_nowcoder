/* -*- coding: utf-8 -*-
  !@time: 2020/3/4 23:27
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0048_two.cpp
 */
#include <environment.h>

class Solution {
public:
    int Add(int num1, int num2) {
        int n1, n2;
        n1 = (num1 & num2) << 1;
        n2 = num1 ^ num2;
        while (n1 & n2) {
            num1 = n1;
            num2 = n2;
            n1 = (num1 & num2) << 1;
            n2 = num1 ^ num2;
        }
        return n1 | n2;

    }
};

int fun() {
    printf("%d", Solution().Add(5, 6));
    return 0;
}