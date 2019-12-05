/* -*- coding: utf-8 -*-
  !@time: 2019-12-06 00:07
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0009_super_jump_steps.cpp
 */
#include <environment.h>


// f(n) = f(n-1)+...f(1) f(n-1) = f(n-2) +...+f(1)
//  f(n) = 2*f(n-1)
//  跳1级，剩下n-1级，则剩下跳法是f(n-1)
//  跳2级，剩下n-2级，则剩下跳法是f(n-2)
class Solution {
public:

    int jumpFloor_recursive(int number) {
        if (number <= 0) {
            return 0;
        } else if (number == 1) {
            return 1;
        } else {
            return 2 * jumpFloor_recursive(number - 1);
        }
    }

};

int fun() {
    Solution solution;
    int number = 5;
    printf("recursive=%d", solution.jumpFloor_recursive(number));
    return 0;
}