/* -*- coding: utf-8 -*-
  !@time: 2019-12-15 23:55
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0015_reverse_listNode.cpp
 */
#include <environment.h>

using self_envs::ListNode;

class Solution {
public:
    ListNode *ReverseList(ListNode *pHead) {
        //stack
        stack<ListNode *> listNodeStack;
        while (pHead != nullptr) {
            ListNode *tmp = pHead;
            if (pHead->next == nullptr) {
                listNodeStack.push(tmp);
                break;
            } else {
                pHead = pHead->next;
                tmp->next = nullptr;
                listNodeStack.push(tmp);
            }
        }
        ListNode *ret = new ListNode(0);
        ListNode *next_node = ret;
        while (!listNodeStack.empty()) {
            next_node->next = listNodeStack.top();
            next_node = next_node->next;
            listNodeStack.pop();
        }
        return ret->next;
    }

    ListNode *ReverseList_headInsert(ListNode *pHead) {
        ListNode *h = nullptr;
        while (pHead) {
            ListNode *tmp = pHead->next;
            pHead->next = h;
            h = pHead;
            pHead = tmp;
        }
        return h;
    }
};

int fun() {
    auto *pHead = new ListNode(1);
    ListNode *next_node = pHead;
    for (int i = 2; i < 6; i++) {
        next_node->next = new ListNode(i);
        next_node = next_node->next;
    }
    ListNode *out = Solution().ReverseList_headInsert(pHead);
    return 0;
}