/* -*- coding: utf-8 -*-
  !@time: 2020/2/26 14:50
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0035_reverse_order_pairs_in_an_array.cpp
 */
#include <environment.h>

class Solution {
    //程序的主体函数
    int InversePairCore(vector<int> &data, int *&copy, int start, int end) {
        if (start == end) {
            copy[start] = data[start];
            return 0;
        }
        //将数组拆分成两部分
        int length = (end - start) / 2;//这里使用的下标法，下面要用来计算逆序个数；也可以直接使用mid=（start+end）/2
        //分别计算左边部分和右边部分
        int left = InversePairCore(data, copy, start, start + length) % 1000000007;
        int right = InversePairCore(data, copy, start + length + 1, end) % 1000000007;
        //进行逆序计算
        int i = start + length;//前一个数组的最后一个下标
        int j = end;//后一个数组的下标
        int index = end;//辅助数组下标，从最后一个算起
        int count = 0;
        while (i >= start && j >= start + length + 1) {
            if (data[i] > data[j]) {
                copy[index--] = data[i--];
                //统计长度
                count += j - start - length;
                if (count >= 1000000007)//数值过大求余
                    count %= 1000000007;
            } else {
                copy[index--] = data[j--];
            }
        }
        for (; i >= start; --i) {
            copy[index--] = data[i];
        }
        for (; j >= start + length + 1; --j) {
            copy[index--] = data[j];
        }
        //排序
        for (int i = start; i <= end; i++) {
            data[i] = copy[i];
        }
        //返回最终的结果
        return (count + left + right) % 1000000007;
    }

public:
    //暴力
    int InversePairs_violence(vector<int> data) {
        if (data.empty()) {
            return -1;
        }
        long long ret = 0;
        for (int i = 0; i < data.size(); ++i) {
            for (int j = i + 1; j < data.size(); ++j) {
                if (data[i] > data[j]) {
                    ret++;
                }
            }
        }
        return ret % 1000000007;

    }

    //归并排序
    int inversepairs_merge(vector<int> data) {
        if (data.size() <= 1) return 0;//如果少于等于1个元素，直接返回0
        int *copy = new int[data.size()];
        //初始化该数组，该数组作为存放临时排序的结果，最后要将排序的结果复制到原数组中
        for (unsigned int i = 0; i < data.size(); i++)
            copy[i] = 0;
        //调用递归函数求解结果
        int count = InversePairCore(data, copy, 0, data.size() - 1);
        delete[] copy;//删除临时数组
        return count;
    }
};

int fun() {
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0};
    int ret = Solution().inversepairs_merge(data);
    printf("%d", ret);
    return 0;
}