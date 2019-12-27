/* -*- coding: utf-8 -*-
  !@time: 2019-12-27 14:13
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0028_number_that_appears_more_than_half_of_the_array.cpp
 */

#include <environment.h>

class Solution {
    typedef unordered_map<int, int> uMap;
public:
    int MoreThanHalfNum_Solution(const vector<int> &numbers) {
        if (numbers.empty()) {
            return 0;
        }
        uMap mp;
        int threshold = numbers.size() / 2 + 1;
        for (auto &num : numbers) {
            if (mp.find(num) == mp.end()) {
                mp.insert(std::make_pair(num, 1));
            } else {
                mp[num]++;
            }
            for (auto &iter :mp) {
                if (iter.second >= threshold) {
                    return iter.first;
                }
            }
        }
        return 0;
    }
};

int fun() {
    vector<int> input = {1, 2, 3, 4, 4, 4};
    int output = Solution().MoreThanHalfNum_Solution(input);
    printf("%d", output);
    return 0;
}