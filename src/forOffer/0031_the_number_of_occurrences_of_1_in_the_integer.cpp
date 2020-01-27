/* -*- coding: utf-8 -*-
  !@time: 2019/12/31 1:34
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0031_the_number_of_occurrences_of_1_in_the_integer.cpp
 */
#include <environment.h>

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10)
            ones += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1);
        return ones;

    }
};

int fun() {
    Solution solution;;
    printf("%d", solution.NumberOf1Between1AndN_Solution(10));
    return 0;
}