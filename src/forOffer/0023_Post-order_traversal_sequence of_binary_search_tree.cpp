/* -*- coding: utf-8 -*-
  !@time: 2019-12-23 07:25
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0023_Post.cpp
 */

#include <selfFun.h>

class Solution {
private:
    static bool judge(vector<int> sequence, int start, int root) {
        if (root <= start) {
            return true;
        }
        int start_copy = start;
        while (sequence[start] < sequence[root]) start++;
        int sep_num = start;
        while (sequence[start] > sequence[root]) start++;
        if (start < root) return false;
        if (!judge(sequence, start_copy, sep_num - 1))
            return false;
        return judge(sequence, sep_num, root - 1);
    }

public:
    bool verifySquenceOfBST(const vector<int> &a) {
        if (!a.size()) return false;
        return judge(a, 0, a.size() - 1);
    }
};


int fun() {
    string str = "[1,3,2,5,8,6,7]";
    Solution solution;
    vector<int> input = stringToIntegerVector(str);
    bool ret = solution.verifySquenceOfBST(input);
    printf("%s", ret ? "true" : "false");
    return 0;
}