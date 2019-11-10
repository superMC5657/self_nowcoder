/* -*- coding: utf-8 -*-
  !@time: 2019/10/23 19:57
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0003_print_list_from_start_to_finish.cpp
 */
#include <environment.h>

class Solution {
public:
    static vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> ret;
        if (head == nullptr) {
            return {};
        }
        while (head != nullptr) {
            ret.push_back(head->val);
            if (head->next == nullptr) {
                break;
            } else {
                head = head->next;
            }
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

int fun() {

}