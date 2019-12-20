/* -*- coding: utf-8 -*-
  !@time: 2019-12-20 07:25
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0020_Stack_contain_min_function.cpp
 */
#include <environment.h>

class Solution {
private:
    stack<int> stack1, stack2;

public:
    void push(int value) {
        stack1.push(value);
        if (stack2.empty())
            stack2.push(value);
        else if (value <= stack2.top()) {
            stack2.push(value);
        }
    }

    void pop() {
        if (stack1.top() == stack2.top())
            stack2.pop();
        stack1.pop();

    }

    int top() {
        return stack1.top();
    }

    int min() {
        return stack2.top();
    }

};

int fun() {
    Solution solution;
    for (int i = 0; i < 9; ++i) {
        solution.push(i);
    }
    for (int j = 0; j < 10; j += 2) {
        solution.pop();
    }
    printf("%d,%d", solution.top(), solution.min());
    return 0;
}