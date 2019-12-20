/* -*- coding: utf-8 -*-
  !@time: 2019-12-20 07:44
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0021_stack_push_sequence.cpp
 */
#include <environment.h>

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty() || popV.empty() || pushV.size() != popV.size())
            return false;
        stack<int> s;
        int j = 0;
        for (int i : pushV) {
            s.push(i);
            while (!s.empty() && s.top() == popV[j]) {
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};

int fun() {
    bool out = Solution().IsPopOrder({1, 2, 3}, {3, 2, 1});
    printf("%s", out ? "true" : "false");
    return 0;
}