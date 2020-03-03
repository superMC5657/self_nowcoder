/* -*- coding: utf-8 -*-
  !@time: 2020/3/2 11:32
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0037_Number_of_times_the_number_appears_in_the_sorted_array.cpp
 */
#include <environment.h>

class compare {
public:
    compare(int n) : v(n) {}

    bool operator()(const int &m) {
        return m == this->v;
    }

private:
    int v;
};

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.empty())
            return 0;
        int ret = 0;
        int left = 0;
        int right = data.size() - 1;
        int position = (left + right) / 2;
        vector<int> pos;
        while (true) {
            vector<int>::iterator it = std::find_if(pos.begin(), pos.end(), compare(position));
            // vector<int>::iterator it = std::find(pos.begin(), pos.end(), position);
            if (it == pos.end()) {
                pos.push_back(position);
            } else {
                break; // not found
            }
            if (data[position] > k) {
                right = position;
                position = (left + position) / 2;
            } else if (data[position] < k) {
                left = position;
                position = (right + position) / 2;
            } else {
                ret++;
                break;
            }
        }
        //
        for (int i = 1; i <= position; ++i) {
            if (data[position - i] == k) {
                ret++;
            } else {
                break;
            }
        }
        for (int j = 1; j <= data.size() - 1 - position; ++j) {
            if (data[position + j] == k) {
                ret++;
            } else {
                break;
            }
        }
        return ret;
    }

    int GetNumberOfK_stl(vector<int> data, int k) {
        auto resultPair = equal_range(data.begin(), data.end(), k);
        return resultPair.second - resultPair.first;
    }

    int GetNumberOfK_template(vector<int> data, int k) {
        return biSearch(data, k + 0.5) - biSearch(data, k - 0.5);
    }

private:
    int biSearch(const vector<int> &data, double num) {
        int s = 0, e = data.size() - 1;
        while (s <= e) {
            int mid = (e - s) / 2 + s;
            if (data[mid] < num)
                s = mid + 1;
            else if (data[mid] > num)
                e = mid - 1;
        }
        return s;
    }
};

int fun() {
    vector<int> data = {3, 3, 3, 3, 3};
    int k = 3;
    printf("%d", Solution().GetNumberOfK(data, k));
    return 0;
}