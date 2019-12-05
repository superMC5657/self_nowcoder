/* -*- coding: utf-8 -*-
  !@time: 2019-12-02 23:42
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0007_fibonacci_sequence.cpp
 */
#include <environment.h>

class Solution {
public:
    int Fibonacci_recursive(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 1;
        } else {
            return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
        }
    }

    int Fibonacci_loop(int n) {
        int preNum = 1;
        int prePreNum = 0;
        int result = 0;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        for (int i = 2; i <= n; i++) {
            result = preNum + prePreNum;
            prePreNum = preNum;
            preNum = result;
        }
        return result;

    }

    int Fibonacci(int n) {
        return n <= 0 ? 0 : (pow((1 + sqrt(5)) / 2.0, n) - pow((1 - sqrt(5)) / 2.0, n)) / sqrt(5);
    }

};

int fun() {
    Solution solution;
    int n = 3;
    int ret_loop, ret_rec, ret;
    for (int i = 0; i < 10; i++) {
        //ret_rec = solution.Fibonacci_recursive(n);
        ret_loop = solution.Fibonacci_loop(n);
        ret = solution.Fibonacci(i);
        printf("%d\t", ret);
    }

    return 0;
}