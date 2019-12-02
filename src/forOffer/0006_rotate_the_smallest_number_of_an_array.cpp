/* -*- coding: utf-8 -*-
  !@time: 2019/11/28 16:21
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0006_rotate_the_smallest_number_of_an_array.cpp
 */

#include <environment.h>

class Solution {
public:
    int minNumberInRotateArray_(vector<int> rotateArray) {
        if (rotateArray.empty()) {
            return 0;
        }
        for (int i = 0; i < rotateArray.size() - 1; i++) {
            if (rotateArray[i + 1] < rotateArray[i]) {
                return rotateArray[i + 1];
            }
        }
        return rotateArray[0];
    }

    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) {
            return 0;
        }
        int left = 0, right = rotateArray.size() - 1;
        while (left < right) {
            //确认子数组是否是类似1,1,2,4,5,..,7的非递减数组
            if (rotateArray[left] < rotateArray[right]) {
                return rotateArray[left];
            }

            int mid = left + (right - left) / 2;
            //如果左半数组为有序数组
            if (rotateArray[left] < rotateArray[mid]) {
                left = mid + 1;
            }
                //如果右半数组为有序数组
            else if (rotateArray[mid] < rotateArray[right]) {
                right = mid;
            }
                //否则，rotateArray[left] == rotateArray[mid] == rotateArray[right]
            else {
                ++left;
            }
        }
        return rotateArray[left];
    }
};

int fun() {
    Solution solution;
    vector<int> rotateArray = {5, 6, 7, 7, 8, 9, 10, 1, 2, 3};
    int ret = solution.minNumberInRotateArray(rotateArray);
    printf("%d", ret);
}