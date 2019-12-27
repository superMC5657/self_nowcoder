/* -*- coding: utf-8 -*-
  !@time: 2019/12/27 0:52
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0027_string_permutation.cpp
 */
#include <environment.h>
#include <algorithm>

class Solution {
private:
    static vector<string> insert_permutation(const vector<string> &pre_dp_str, char c) {
        vector<string> sub_dp_str;
        for (auto &j : pre_dp_str) {
            for (int i = 0; i <= j.size(); ++i) {
                string tmp = j;
                tmp.insert(j.size() - i, 1, c);
                if (std::find(sub_dp_str.begin(), sub_dp_str.end(), tmp) == sub_dp_str.end()) {
                    sub_dp_str.emplace_back(tmp);
                }
            }
        }
        return sub_dp_str;
    }

public:
    vector<string> Permutation(const string &str) {
        if (str.empty()) {
            return {};
        }
        vector<vector<string>> dp_str_all;
        int i = 0;
        for (char c:str) {
            if (i == 0) {
                vector<string> sub_dp_str = {str.substr(0, 1)};
                dp_str_all.emplace_back(sub_dp_str);
            } else {
                dp_str_all.emplace_back(insert_permutation(dp_str_all[i - 1], c));
            }
            i++;
        }
        vector<string> ret = dp_str_all[dp_str_all.size() - 1];
        std::stable_sort(ret.begin(), ret.end());
        return ret;
    }
};

int fun() {
    Solution solution;
    vector<string> output = solution.Permutation("abc");
    for (const auto &i : output) {
        cout << i << "\n";
    }
    cout << endl;
    return 0;
}