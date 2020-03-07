/* -*- coding: utf-8 -*-
  !@time: 2020/3/5 18:13
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0050__duplicate_numbers_in_array.cpp
 */
#include <environment.h>
#include <selfFun.h>

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false

    bool duplicate(int numbers[], int length, int *duplication) {
        for (int i = 0; i != length; ++i) {
            int index = numbers[i] % length;
            if (numbers[index] >= length) {
                *duplication = index;
                return true;
            }
            numbers[index] += length;
        }
        return false;
    }

};

int fun() {
    int numbers[5] = {1, 2, 3, 4, 1};
    int length = Count(numbers);
    int *duplication, tmp = -1;
    duplication = &tmp;
    printf("%s\n", Solution().duplicate(numbers, length, duplication) ? "true" : "false");
    printf("%d",*duplication);

    return 0;
}