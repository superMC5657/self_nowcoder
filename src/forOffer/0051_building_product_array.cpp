/* -*- coding: utf-8 -*-
  !@time: 2020/3/6 21:21
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0051_building_product_array.cpp
 */
#include <environment.h>

class Solution {
public:
    vector<int> multiply(const vector<int> &A) {
        if (A.empty())
            return A;
        vector<int> b(A.size(), 1);
        int tmp = 1;
        for (int i = 1; i < A.size(); ++i) {
            tmp = tmp * A[i - 1];
            b[i] = tmp;
        }
        tmp = 1;
        for (int j = A.size() - 2; j >= 0; --j) {
            tmp = tmp * A[j + 1];
            b[j] = tmp * b[j];
        }
        return b;
    }
};

int fun() {
    vector<int> A = {1, 2, 3, 4, 5};
    Solution().multiply(A);

    return 0;
}