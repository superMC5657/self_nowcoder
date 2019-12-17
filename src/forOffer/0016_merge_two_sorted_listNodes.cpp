/* -*- coding: utf-8 -*-
  !@time: 2019-12-17 01:22
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0016_merge_two_sorted_listNodes.cpp
 */

#include <selfFun.h>

class Solution {
public:
    static ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        auto *res = new ListNode(-1);
        ListNode *tmp = res;
        while (pHead1 != nullptr && pHead2 != nullptr) {
            if (pHead1->val <= pHead2->val) {
                ListNode *head_tmp = pHead1;
                if (pHead1->next == nullptr) {
                    tmp->next = head_tmp;
                    head_tmp->next = pHead2;
                    break;
                }
                pHead1 = pHead1->next;
                head_tmp->next = nullptr;
                tmp->next = head_tmp;

            } else {
                ListNode *head_tmp = pHead2;
                if (pHead2->next == nullptr) {
                    tmp->next = head_tmp;
                    head_tmp->next = pHead1;
                    break;
                }
                pHead2 = pHead2->next;
                head_tmp->next = nullptr;
                tmp->next = head_tmp;
            }
            tmp = tmp->next;
        }
        delete tmp;
        return res->next;
    }

    ListNode *Merge_template(ListNode *pHead1, ListNode *pHead2);
};


ListNode *Solution::Merge_template(ListNode *pHead1, ListNode *pHead2) {
    if ((pHead1 == nullptr) && (pHead2 == nullptr))
        return nullptr;
    if ((pHead1 == nullptr) || (pHead2 == nullptr))
        return (pHead1 == nullptr) ? pHead2 : pHead1;
    ListNode *res;
    if (pHead1->val < pHead2->val) {
        res = pHead1;
        pHead1 = pHead1->next;
        res->next = Merge_template(pHead1, pHead2);
    } else {
        res = pHead2;
        pHead2 = pHead2->next;
        res->next = Merge_template(pHead1, pHead2);
    }
    return res;
}

int fun() {
    Solution solution;
    ListNode *pHead1 = stringToListNode("{1,3,5}");
    ListNode *pHead2 = stringToListNode("{2,4,6}");
    ListNode *ret = solution.Merge_template(pHead1, pHead2);
    printf("%s", listNodeToString(ret).c_str());
    return 0;
}