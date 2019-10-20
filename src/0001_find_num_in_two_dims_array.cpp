/* -*- coding: utf-8 -*-
  !@time: 2019-09-16 14:58
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0001_find_num_in_two_dims_array.cpp
 */
#include "environment.h"

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0) {
            return false;
        }
        if (array[0].size() == 0) {
            return false;
        }
        int i = array.size(); //行高
        int cols = array[0].size(); //列宽
        i--; //最底
        int j = 0;
        while (i >= 0 && j < cols) {
            if (target < array[i][j]) {
                i--;
            } else if (target > array[i][j]) {
                j++;
            } else {
                return true;
            }

        }
        return false;
    }


//思路：首先我们选择从左下角开始搜寻，(为什么不从左上角开始搜寻，左上角向右和向下都是递增，
// 那么对于一个点，对于向右和向下会产生一个岔路；如果我们选择从左下脚开始搜寻的话，如果大于就向右，如果小于就向下)。
    bool Find_Template(int target, vector<vector<int> > array) {
        if (array.size() == 0) {
            return false;
        }
        if (array[0].size() == 0) {
            return false;
        }

        // array是二维数组，这里没做判空操作
        int rows = array.size();
        int cols = array[0].size();
        int i = rows - 1, j = 0;//左下角元素坐标
        while (i >= 0 && j < cols) {//使其不超出数组范围
            if (target < array[i][j])
                i--;//查找的元素较少，往上找
            else if (target > array[i][j])
                j++;//查找元素较大，往右找
            else
                return true;//找到
        }
        return false;
    }

};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}


vector<vector<int>> stringToVectorIntegerVector(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    vector<vector<int>> res;
    char delim = ']';
    int i = 0;
    while (getline(ss, item, delim)) {
        if (i == 0) {
            vector<int> tmp = stringToIntegerVector(item + "]");
            res.push_back(tmp);
        } else {
            res.push_back(stringToIntegerVector(item.substr(1, item.size()) + ']'));
        }

        i++;
    }
    return res;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}


int fun() {
    string line = "[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]";
    int target = 5;

    vector<vector<int>> input = stringToVectorIntegerVector(line);
    bool ret = Solution().Find(target, input);
    string out = boolToString(ret);
    cout << out << endl;
    return 0;
}