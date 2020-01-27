/* -*- coding: utf-8 -*-
  !@time: 2020/1/7 6:51
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0032_arrange_the_array_to_the_smallest_number.cpp
 */
#include <environment.h>

class Solution {
private:
    static bool cmp(int x, int y) {
        return to_string(x) + to_string(y) < to_string(y) + to_string(x);
    }

public:

    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string ans;
        for (int number : numbers)
            ans += to_string(number);
        return ans;
    }
};

int fun() {
    printf(Solution().PrintMinNumber({32, 15, 1, 4, 1, 5, 6, 7, 10}).c_str());
    return 0;
}