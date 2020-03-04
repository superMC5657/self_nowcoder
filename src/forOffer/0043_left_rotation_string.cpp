/* -*- coding: utf-8 -*-
  !@time: 2020/3/3 21:30
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0043_left_rotation_string.cpp
 */
#include <environment.h>

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int str_len = str.size();
        if (n == 0 || str_len == 0)
            return str;
        n = n % str_len;
        string str1 = str.substr(0, n);
        string str2 = str.substr(n, str_len - n);
        return str2 + str1;
    }
};

int fun() {
    string str = "abcXYZdef";
    str = Solution().LeftRotateString(str, 3);
    printf("%s", str.c_str());
    return 0;
}