/* -*- coding: utf-8 -*-
  !@time: 2019/12/15 23:00
  !@author: superMC @email: 18758266469@163.com
  !@fileName: K.cpp
 */
#include <selfFun.h>

using self_envs::ListNode;

class Solution {
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        int length = 1;
        ListNode *tmp = pListHead;
        while (tmp->next != nullptr && tmp != nullptr) {
            tmp = tmp->next;
            length++;
        }
        if (length < k) {
            return nullptr;
        } else if (length == k) {
            return pListHead;
        }
        int del_num_th = length - k;
        ListNode *res = pListHead;
        for (int i = 0; i < del_num_th; i++) {
            res = res->next;
        }
        return res;
    }
};


int fun() {
    string str = "[1,2,3,4,5]";
    ListNode *new_listNode = stringToListNode(str);
    ListNode *ret = Solution().FindKthToTail(new_listNode, 1);
    cout << ret->val;

}