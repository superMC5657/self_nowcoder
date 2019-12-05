/* -*- coding: utf-8 -*-
  !@time: 2019/12/5 21:47
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0008_jump_steps.cpp
 */
#include <environment.h>

// 跳到n 上一步肯定是n-2或n-1,所以求得n-2和n-1两者的解法相加即可,斐波那契数列(0,1,2)级不满足,需要的次数(0,1,2)
class Solution {
public:
    int jumpFloor_recursive(int number) {
        if (number <= 0) {
            return 0;
        } else if (number == 1) {
            return 1;
        } else if (number == 2) {
            return 2;
        } else {
            return jumpFloor_recursive(number - 1) + jumpFloor_recursive(number - 2);
        }
    }

    int jumpFloor_loop(int number) {
        int preNum = 2; //2
        int prePreNum = 1; //1
        int result = 0;
        if (number == 0)
            return 0;
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;
        for (int i = 3; i <= number; i++) {
            result = preNum + prePreNum;
            prePreNum = preNum;
            preNum = result;
        }
        return result;
    }

};

int fun() {
    Solution solution;
    int number = 5;
    printf("loop=%d,recursive=%d", solution.jumpFloor_loop(number), solution.jumpFloor_recursive(number));
    return 0;
}