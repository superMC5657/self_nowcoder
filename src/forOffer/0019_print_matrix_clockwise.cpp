/* -*- coding: utf-8 -*-
  !@time: 2019/12/18 20:13
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0019_print_matrix_clockwise.cpp
 */
#include <selfFun.h>

class Solution {
private:
    vector<int> singleCircle(vector<vector<int>> &matrix, int x, int y, int lengthX_axis, int lengthY_axis) {
        vector<int> circle_matrix;


        for (int i = x; i < lengthX_axis - x - 1; ++i) {
            circle_matrix.push_back(matrix[y][i]);
        }
        for (int j = y; j < lengthY_axis - y - 1; ++j) {
            circle_matrix.push_back(matrix[j][lengthX_axis - x - 1]);
        }
        //如果 行或列其中有一
        if (lengthX_axis - 2 * x == 1 || lengthY_axis - 2 * y == 1)
            circle_matrix.push_back(matrix[lengthY_axis - y - 1][lengthX_axis - x - 1]);

        if (lengthY_axis - 2 * y > 1 && lengthX_axis - 2 * x > 1) {
            for (int i = x; i < lengthX_axis - x - 1; ++i) {
                circle_matrix.push_back(matrix[lengthY_axis - y - 1][lengthX_axis - i - 1]);
            }
            for (int j = y; j < lengthY_axis - y - 1; ++j) {
                circle_matrix.push_back(matrix[lengthY_axis - j - 1][x]);
            }
        }


        if (lengthX_axis - 2 * (x + 1) > 0 && lengthY_axis - 2 * (y + 1) > 0) {
            vector<int> next_matrix = singleCircle(matrix, x + 1, y + 1, lengthX_axis, lengthY_axis);
            vector<int> ret;
            ret.insert(ret.end(), circle_matrix.begin(), circle_matrix.end());
            ret.insert(ret.end(), next_matrix.begin(), next_matrix.end());
            return ret;
        } else {
            return circle_matrix;
        }
    }

public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        int lengthX_axis = matrix[0].size();
        int lengthY_axis = matrix.size();
        int x = 0, y = 0;
        vector<int> ret = singleCircle(matrix, x, y, lengthX_axis, lengthY_axis);
        return ret;
    }
};

int fun() {
    string str = "[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]";
    vector<vector<int>> input = stringToVectorVectorInteger(str);
    vector<int> out = Solution().printMatrix(input);
    for (int iter : out) {
        printf("%d ", iter);
    }
    return 0;
}