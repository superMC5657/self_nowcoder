/* -*- coding: utf-8 -*-
  !@time: 2019/12/6 19:37
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0010_rect_cover.cpp
 */
#include <environment.h>
#include <cstdlib>

class Solution {
public:
    int rectCover(int number) {
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
int fun(){
    Solution solution;
    int number = 3;
    system("chcp 65001");
    printf("种类=%d", solution.rectCover(number));
    return 0;
}