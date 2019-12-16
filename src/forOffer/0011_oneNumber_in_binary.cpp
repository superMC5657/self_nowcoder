/* -*- coding: utf-8 -*-
  !@time: 2019/12/6 20:00
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0011_oneNumber_in_binary.cpp
 */
#include <environment.h>
#include <bitset>

using std::bitset;

class Solution {
public:

    int NumberOf1(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n >> i & 1)
                count++;
        }
        return count;
    }

    int bitNumberOf1(int n) {
        return bitset<32>(n).count();
    }

//        for (vector<int>::const_iterator iter = array.cend()-1; iter != array.cbegin()-1; iter--) { //逆序
//            printf("%d", *iter);
//        }

};

int fun() {
    int n = 5;
    printf("%d = %d , %d = %d", n, Solution().bitNumberOf1(n), 0 - n, Solution().bitNumberOf1(0 - n));
}
