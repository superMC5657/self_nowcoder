/* -*- coding: utf-8 -*-
  !@time: 2020/1/11 上午10:02
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0034_the_first_character_that_appears_only_once.cpp
 */
#include <environment.h>

class Solution {
public:
    int FirstNotRepeatingChar(string str) {

        map<char, int> mp;
        for (char i : str)
            mp[i]++;
        for (int i = 0; i < str.size(); ++i) {
            if (mp[str[i]] == 1)
                return i;
        }
        return -1;
    }
};

int fun() {
    string str = "Hello World";
    int ret = Solution().FirstNotRepeatingChar(str);
    printf("%d", ret);
    return 0;
}