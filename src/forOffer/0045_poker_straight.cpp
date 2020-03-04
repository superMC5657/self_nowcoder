/* -*- coding: utf-8 -*-
  !@time: 2020/3/4 14:38
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0045_poker_straight.cpp
 */
#include <environment.h>

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.empty()) return false;
        sort(numbers.begin(), numbers.end());
        int zeros = 0, i = 0;
        while (i < numbers.size() && numbers[i] == 0) {
            zeros++;
            i++;
        }
        for (; i < numbers.size() - 1; i++) {
            if (numbers[i + 1] == numbers[i]) return false;
            zeros -= (numbers[i + 1] - numbers[i] - 1);
        }
        return zeros >= 0;
    }
};

int fun() {
    vector<int> numbers = {1, 12, 0, 11, 10};
    printf("%s", Solution().IsContinuous(numbers) ? "true" : "false");
    return 0;
}