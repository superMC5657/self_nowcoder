/* -*- coding: utf-8 -*-
  !@time: 2019/12/5 21:47
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0008_jump_steps.cpp
 */
#include <environment.h>

class Solution {
public:
    int jumpFloor_recursive(int number) {
        if (number > 0) {
            ++total_num;
        }
        if (number >= 1) {
            jumpFloor_recursive(number - 1);
        }
        if (number >= 2) {
            jumpFloor_recursive(number - 2);
        }
        return total_num;
    }

    int jumpFloor_loop(int number) {
        int preNum = 1;
        int prePreNum = 0;
        int result = 0;
        if (number == 0)
            return 0;
        if (number == 1)
            return 1;
        for (int i = 2; i <= number; i++) {
            result = preNum + prePreNum;
            prePreNum = preNum;
            preNum = result;
        }
        return result;
    }

private:
    int total_num = 0;
};

int fun() {
    Solution solution;
    int number = 6;
    printf("loop=%d,recursive=%d", solution.jumpFloor_loop(number), solution.jumpFloor_recursive(number));
}