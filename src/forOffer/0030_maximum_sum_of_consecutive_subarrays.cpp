/* -*- coding: utf-8 -*-
  !@time: 2019/12/31 0:53
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0030_maximum_sum_of_consecutive_subArrays.cpp
 */
#include <environment.h>

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ans = array[0];
        int sum = 0;
        for (int &i : array) {
            sum += i;
            ans = max(sum, ans);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }

};


int fun() {
    Solution solution;;
    printf("%d", solution.FindGreatestSumOfSubArray({1, 2, 3, 4, 5, 6, -1, 0, 1, 2, 5, 4, 8, 6, 1}));
}