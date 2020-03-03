/* -*- coding: utf-8 -*-
  !@time: 2020/3/3 0:37
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0041_sequential_continuous_positive_numbers.cpp
 */
#include <environment.h>

class Solution {
public:

    //双指针
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > allRes;
        int phigh = 2, plow = 1;

        while (phigh > plow) {
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;
            if (cur < sum)
                phigh++;

            if (cur == sum) {
                vector<int> res;
                for (int i = plow; i <= phigh; i++)
                    res.push_back(i);
                allRes.push_back(res);
                plow++;
            }

            if (cur > sum)
                plow++;
        }

        return allRes;
    }


    vector<vector<int> > FindContinuousSequence_(int sum) {
        vector<vector<int>> arr;
        if (sum < 2) return arr;

        int n = (int) sqrt(2 * sum);
        for (int i = n; i >= 2; --i) {
            if (sum % i * 2 == i || (i & 1 && !(sum % i))) {
                vector<int> list;
                for (int k = 0, startData = sum / i - (i - 1) / 2; k < i; ++k, ++startData) {
                    list.push_back(startData);
                }
                arr.push_back(list);
            }
        }
        return arr;
    }
};

int fun() {
    return 0;
}