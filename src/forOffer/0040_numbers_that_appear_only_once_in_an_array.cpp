/* -*- coding: utf-8 -*-
  !@time: 2020/3/3 0:21
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0040_numbers_that_appear_only_once_in_an_array.cpp
 */
#include <environment.h>

class Solution {
public:
    void FindNumsAppearOnce_hash(vector<int> data, int *num1, int *num2) {
        unordered_map<int, int> map;
        for (int i = 0; i < data.size(); i++)
            map[data[i]]++;
        vector<int> v;
        for (int i = 0; i < data.size(); i++)
            if (map[data[i]] == 1)
                v.push_back(data[i]);
        *num1 = v[0];
        *num2 = v[1];
    }

    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
        if (data.size() < 2) return;
        int myxor = 0;
        int flag = 1;
        for (int i : data)
            myxor ^= i;
        while ((myxor & flag) == 0) flag <<= 1;
        *num1 = myxor;
        *num2 = myxor;
        for (int i : data) {
            if ((flag & i) == 0) *num2 ^= i;
            else *num1 ^= i;
        }
    }
};

int fun() {
    return 0;
}