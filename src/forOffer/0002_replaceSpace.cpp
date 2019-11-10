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

    // 指向字符数组的字符指针str，字符数组长度length
    void replaceSpace_template(char *str, int length) {

        // 边界检查1：判断字符数组是否为空
        if (str = NULL)
            return;
        // 遍历字符串，统计空格个数、替换前字符个数、替换后字符个数
        int CountOfBlanks = 0; // 空格个数
        int Originallength = 0;// 替换前字符个数
        int len = 0;           // 替换后字符个数

        for (int i = 0; str[i] != '\0'; ++i) {
            Originallength++;
            if (str[i] == ' ')
                ++CountOfBlanks;
        }

        len = Originallength + 2 * CountOfBlanks;

        // 边界检查2：判断字符数组是否越界
        if (len + 1 > length)
            return;

        // 替换空格
        char *pStr1 = str + Originallength;// 字符指针指向原始字符串的末尾
        char *pStr2 = str + len;           // 字符指针指向替换后字符串的末尾

        while (pStr1 != pStr2)         // 替换结束的条件
        {
            if (*pStr1 == ' ') {
                *pStr2-- = '0';
                *pStr2-- = '2';
                *pStr2-- = '%';
            } else {
                *pStr2-- = *pStr1;
            }
            --pStr1;
        }
    }

};

int fun() {
    char str[40] = "we are happy";
    int length = std::strlen(str);
    Solution().replaceSpace_template(str, length);
    cout << *str << endl;
}