/* -*- coding: utf-8 -*-
  !@time: 2019-09-17 12:58
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0002_replaceSpace.cpp
 */
#include <cstring>
#include "environment.h"

class Solution {
public:
    void replaceSpace(char *str, int length) {
        for (int i = 0; i < length; i++) {
            if (*(str + i) == ' ') {
                length += 2;
                int j = length - 1;
                while (j - 2 > i) {//移动空格之后的char
                    *(str + j) = *(str + j - 2);
                    j--;
                }
                *(str + i) = '%';
                *(str + i + 1) = '2';
                *(str + i + 2) = '0';
            }
        }
    }
};

int fun() {
    char str[40] = "we are happy";
    int length = std::strlen(str);
    Solution().replaceSpace(str, length);
    length = std::strlen(str);
    for (int i = 0; i < length; i++) {
        cout << *(str + i);
    }
    cout << endl;
    return 0;
}