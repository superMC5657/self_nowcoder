/* -*- coding: utf-8 -*-
  !@time: 2020/3/7 2:43
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0056_remove_duplicate_nodes_in_a_linked_list.cpp
 */
#include <environment.h>
#include <selfFun.h>

using self_envs::ListNode;

class Solution {
public:

    ListNode *deleteDuplication(ListNode *pHead) {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;

        /*---------先为链表创建一个头结点---------*/

        int firstNumber = pHead->val;

        //假设我的头结点数值为-1
        int myFirst = -1;

        //万一链表的头结点也为-1，那么我就改成-2
        if (myFirst == firstNumber) {

            myFirst = -2;
        }
        ListNode *head = new ListNode(myFirst);
        head->next = NULL;
        head->next = pHead;

        ListNode *p = head;
        ListNode *q = head->next;

        while (q) {
            while (q->next && (q->next->val == q->val)) {
                q = q->next;
            }
            if (p->next != q) {

                q = q->next;
                p->next = q;
            } else {
                p = q;
                q = q->next;
            }
        }

        //返回的时候，注意去掉头结点（自己创建的辅助节点）
        return head->next;

    }


    ListNode *deleteDuplication_rec(ListNode *pHead) {
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;


        ListNode *current;

        if (pHead->next->val == pHead->val) {
            current = pHead->next->next;
            while (current != nullptr && current->val == pHead->val)
                current = current->next;
            return deleteDuplication_rec(current);
        } else {
            current = pHead->next;
            pHead->next = deleteDuplication_rec(current);
            return pHead;
        }
    }
};

int fun() {
    ListNode *pHead = stringToListNode("{1,2,2,5}");
    Solution().deleteDuplication(pHead);
    return 0;
}