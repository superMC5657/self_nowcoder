/* -*- coding: utf-8 -*-
  !@time: 2020/3/7 2:13
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0055_entry_point_of_a_ring_in_a_linked_list.cpp
 */
#include <environment.h>

using self_envs::ListNode;

class Solution {
public:


    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        if (pHead == nullptr || pHead->next == nullptr)
            return nullptr;
        ListNode *p1 = pHead;
        ListNode *p2 = pHead;
        while (p2 != nullptr && p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) {
                p2 = pHead;
                while (p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                if (p1 == p2)
                    return p1;
            }
        }
        return nullptr;
    }
};

int fun() {
    return 0;
}