/* -*- coding: utf-8 -*-
  !@time: 2020/3/7 1:32
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0052__regular_expression_match.cpp
 */
#include <environment.h>
#include <selfFun.h>
#include <c++/cstring>

class Solution {
public:
    bool match(char *str, char *pattern) {

        int parttern_length = strlen(pattern);
        int str_length = strlen(str);
        if (0 == parttern_length) {
            return str_length == 0;
        }
        vector<vector<int >> flag(static_cast<unsigned int>(str_length + 1), vector<int>(
                static_cast<unsigned int>(parttern_length + 1), 0));
        flag[0][0] = 1;
        for (int i = 0; i <= str_length; i++) {
            for (int j = 1; j <= parttern_length; j++) {
                if (j > 1 && pattern[j - 1] == '*') {
                    if (i > 0) {
                        flag[i][j] = flag[i - 1][j] && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.');
                    }
                    flag[i][j] = flag[i][j] || flag[i][j - 2];
                } else if (i > 0) {
                    flag[i][j] = flag[i - 1][j - 1] && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
                }
            }
        }
        return flag[str_length][parttern_length];
    }

};

int fun() {
    return 0;
}