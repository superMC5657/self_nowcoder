/* -*- coding: utf-8 -*-
  !@time: 2019/11/28 14:31
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0005_achieve_queue_by_two_stacks.cpp
 */
#include <environment.h>

class Solution {
public:
    void push(int node) {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }

    }

    int pop() {
        if (stack2.empty()) {
            return NULL;
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int fun() {
    Solution solution;
    for (int i = 0; i < 9; i++) {
        solution.push(i);
    }
    for (int i = 0; i < 9; i++) {
        printf("%d", solution.pop());
    }
    return 0;
}