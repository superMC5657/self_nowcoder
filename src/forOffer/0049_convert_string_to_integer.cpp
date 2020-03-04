/* -*- coding: utf-8 -*-
  !@time: 2020/3/5 0:17
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0049_convert_string_to_integer.cpp
 */
#include <environment.h>

class Solution {
public:

    int StrToInt(string str) {
        int m = str.length();
        if (m == 0) return 0;
        long long result = 0;
        int flag = 1;
        int index = str.find_first_not_of(' ');
        if (str[index] == '+' || str[index] == '-')
            flag = str[index++] == '-' ? -1 : 1;
        for (; index < m; index++) {
            if (str[index] >= '0' && str[index] <= '9') {
                result = result * 10 + (str[index] - '0');
                if (result * flag > INT_MAX) {
                    return 0;
                }
                if (result * flag < INT_MIN) {
                    return 0;
                }
            } else {
                result = 0;
                break;
            }
        }
        return (int)result * flag;
    }
};

int fun() {
    string str = "-2147483649";
    printf_s("%d", Solution().StrToInt(str));
    return 0;
}