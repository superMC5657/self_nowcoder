/* -*- coding: utf-8 -*-
  !@time: 2020/3/3 20:36
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0042_and_two_numbers_for_s.cpp
 */
#include <environment.h>

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) { //此处的&作为与c# 同作用的ref 可修改nums本身
        map<int, int> a;//提供一对一的hash 相当于python词典
        vector<int> b(2, -1);//用来承载结果，初始化一个大小为2，值为-1的容器b
        for (int i = 0; i < array.size(); i++) { //每次a 储存 value:key对 当value符合条件 则去除对应的key 所以time:o(n)
            if (a.count(sum - array[i]) > 0) {
                b[0] = sum - array[i];
                b[1] = array[i];
            }
            a[array[i]] = i;//反过来放入map中，用来获取结果 array的下标
        }
        if (b[0] == -1)
            return {};
        return b;
    }
};

int fun() {
    int sum = 9;
    vector<int> array = {1, 2, 4, 5, 7, 8, 9};
    vector<int> ret = Solution().FindNumbersWithSum(array, sum);
    return 0;
}