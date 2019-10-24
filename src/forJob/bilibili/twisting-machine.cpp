/* -*- coding: utf-8 -*-
  !@time: 2019-10-22 23:45
  !@author: superMC @email: 18758266469@163.com
  !@fileName: twisting.cpp
 */

#include <iostream>
#include <algorithm>

int fun() {
    int n;
    std::cin >> n;
    std::string ret;
    while (1) {
        if (n == 0) {
            break;
        } else if (n % 2 == 1) {
            ret += '2';
            n = (n - 1) / 2;
        } else {
            ret += '3';
            n = (n - 2) / 2;
        }
    }
    reverse(ret.begin(), ret.end());
    std::cout << ret << std::endl;
    return 0;
}