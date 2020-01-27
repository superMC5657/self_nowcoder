/* -*- coding: utf-8 -*-
  !@time: 2020/1/7 23:15
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0033_ugly_number.cpp
 */
#include <environment.h>

class Solution {
public:
    static int GetUglyNumber_Solution(int index) {
        int n = index;
        vector<int> dp(n + 1);
        dp[1] = 1;
        int index2 = 1; //此下标对应的数乘2刚好大于上一个丑数，此下标之前的数乘2都小于等于上一个丑数
        int index3 = 1; //类似上方，乘2变成乘3
        int index5 = 1; //类似上方，乘3变成乘5
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(min(dp[index2] * 2, dp[index3] * 3), dp[index5] * 5);
            while (dp[index2] * 2 <= dp[i]) ++index2;
            while (dp[index3] * 3 <= dp[i]) ++index3;
            while (dp[index5] * 5 <= dp[i]) ++index5;
        }
        return dp[n];
    }
};

int fun() {
    printf("%s", to_string(Solution::GetUglyNumber_Solution(5)).c_str());
    return 0;
}