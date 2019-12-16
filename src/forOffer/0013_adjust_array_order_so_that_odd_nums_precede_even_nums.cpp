/* -*- coding: utf-8 -*-
  !@time: 2019/12/12 14:20
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0013_adjust_array_order_so_that_odd_nums_precede_even_nums.cpp
 */
#include <environment.h>
#include <unordered_set>

using std::swap;

class Solution {
private:
    static bool isOk(int n) {
        return ((n & 1) == 1);
    }

public:
    vector<int> reOrderArray(vector<int> &array) {
        vector<int> oddNums, evenNums;
        for (vector<int>::const_iterator iter = array.cbegin(); iter != array.cend(); iter++) {
            if (*iter % 2 != 0) {
                oddNums.push_back(*iter);
            } else {
                evenNums.push_back(*iter);
            }
        }
        vector<int> ret;
        ret.insert(ret.end(), oddNums.begin(), oddNums.end());
        ret.insert(ret.end(), evenNums.begin(), evenNums.end());
        return ret;
    }

    void reOrderArray_bubble(vector<int> &array) {
        for (int i = 0; i < array.size(); i++) {
            for (int j = array.size() - 1; j > i; j--) {
                if (array[j] % 2 != 0 && array[j - 1] % 2 == 0) //前偶后奇交换
                {
                    swap(array[j], array[j - 1]);
                }
            }
        }
    }

    void reOrderArray_bool(vector<int> &array) {
        stable_partition(array.begin(), array.end(), [](int n) -> bool { return ((n & 1) == 1); });
        //stable_partition(array.begin(), array.end(), isOk);
    }
};


int fun() {
    vector<int> array = {-1, 0, -3, 2, 4};
    vector<int> array_copy(array); //深copy
    vector<int> out = Solution().reOrderArray(array);
    for (vector<int>::const_iterator iter = out.cbegin(); iter != out.cend(); iter++) {
        printf("%d ", *iter);
    }
    printf("\n");
    Solution().reOrderArray_bubble(array);
    for (vector<int>::const_iterator iter = array.cbegin(); iter != array.cend(); iter++) {
        printf("%d ", *iter);
    }
    printf("\n");
    Solution().reOrderArray_bool(array_copy);
    for (vector<int>::const_iterator iter = array_copy.cbegin(); iter != array_copy.cend(); iter++) {
        printf("%d ", *iter);
    }
    return 0;
}