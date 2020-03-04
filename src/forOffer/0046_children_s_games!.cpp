/* -*- coding: utf-8 -*-
  !@time: 2020/3/4 21:42
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0046_children_s_games.cpp
 */
#include <environment.h>

class Solution {
public:
    int findLastNumber(int n, int m) {
        if (n < 1 || m < 1) return -1;
        int array[n];
        int i = -1, step = 0, count = n;
        while (count > 0) {   //跳出循环时将最后一个元素也设置为了-1
            i++;          //指向上一个被删除对象的下一个元素。
            if (i >= n) i = 0;  //模拟环。
            if (array[i] == -1) continue; //跳过被删除的对象。
            step++;                     //记录已走过的。
            if (step == m) {               //找到待删除的对象。
                array[i] = -1;
                step = 0;
                count--;
            }
        }
        return i;//返回跳出循环时的i,即最后一个被设置为-1的元素
    }

    int findLastNumber_recursive(unsigned int n, unsigned int m) {
        if (n == 0)
            return -1;
        if (n == 1)
            return 0;
        else
            return (findLastNumber_recursive(n - 1, m) + m) % n;
    }

};

int fun() {
    int n = 8, m = 9;
    printf("%d\n", Solution().findLastNumber(n, m));
    printf("%d", Solution().findLastNumber_recursive(n, m));
    return 0;
}