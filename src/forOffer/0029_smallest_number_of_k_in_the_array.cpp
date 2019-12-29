/* -*- coding: utf-8 -*-
  !@time: 2019-12-29 16:12
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0029_smallest_number_of_k_in_the_array.cpp
 */
#include <environment.h>
#include <set>

using std::multiset;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

    }
};


class Solution_redBlackTree {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = input.size();
        if (len <= 0 || k > len) return vector<int>();

        //仿函数中的greater<T>模板，从大到小排序
        multiset<int, std::greater<int> > leastNums;
        vector<int>::iterator vec_it = input.begin();
        for (; vec_it != input.end(); vec_it++) {
            //将前k个元素插入集合
            if (leastNums.size() < k)
                leastNums.insert(*vec_it);
            else {
                //第一个元素是最大值
                multiset<int, std::greater<int> >::iterator
                        greatest_it = leastNums.begin();
                //如果后续元素<第一个元素，删除第一个，加入当前元素
                if (*vec_it < *(leastNums.begin())) {
                    leastNums.erase(greatest_it);
                    leastNums.insert(*vec_it);
                }
            }
        }

        return vector<int>(leastNums.begin(), leastNums.end());
    }
};

class Solution_fastSort {
public:
    void swap(int &fir, int &sec) {
        int temp = fir;
        fir = sec;
        sec = temp;
    }

    int getPartition(vector<int> &input, int start, int end) {
        if (input.empty() || start > end) return -1;
        int temp = input[end];
        int j = start - 1;
        for (int i = start; i < end; ++i) {
            if (input[i] <= temp) {
                ++j;
                if (i != j) swap(input[i], input[j]);
            }
        }
        swap(input[j + 1], input[end]);
        return (j + 1);
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (input.empty() || k > input.size() || k <= 0) return result;

        int start = 0;
        int end = input.size() - 1;
        int index = getPartition(input, start, end);

        while (index != (k - 1)) {
            if (index > (k - 1)) {
                end = index - 1;
                index = getPartition(input, start, end);
            } else {
                start = index + 1;
                index = getPartition(input, start, end);
            }
        }

        for (int i = 0; i < k; ++i) {
            result.push_back(input[i]);
        }

        return result;
    }
};

class Solution_heap {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        int len = input.size();
        if (input.empty() || k <= 0 || len < k) return result;

        multiset<int, std::greater<int> > leastNumbers; // 从大到小排序
        multiset<int, std::greater<int> >::iterator
                iterGreater; // 定义迭代器

        vector<int>::iterator iter = input.begin();
        for (; iter != input.end(); ++iter) {
            // 将前k个数直接插入进multiset中，注意是小于K
            if (leastNumbers.size() < k) {
                leastNumbers.insert(*iter);
            } else {
                // 因为设置的从大到小排序，故multiset中第一个位置的元素即为最大值
                iterGreater = leastNumbers.begin();

                // 如果input中当前元素比multiset中最大元素小，则替换；即保持multiset中这k个元素是最小的。
                if (*iter < *(leastNumbers.begin())) {
                    // 替换掉当前最大值
                    leastNumbers.erase(iterGreater);
                    leastNumbers.insert(*iter);
                }
            }
        }

        for (iterGreater = leastNumbers.begin(); iterGreater != leastNumbers.end(); ++iterGreater) {
            result.push_back(*iterGreater); // 将multiset中这k个元素输出
        }

        return result;
    }
}; //maybe rebBlackTree

int fun() {

}
