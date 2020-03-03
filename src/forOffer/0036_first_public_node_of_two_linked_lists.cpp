/* -*- coding: utf-8 -*-
  !@time: 2020/3/1 19:09
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0036_first_public_node_of_two_linked_lists.cpp
 */
#include <environment.h>

using self_envs::ListNode;

class Solution {
    int findListLenth(ListNode *pHead1) {
        if (pHead1 == NULL) return 0;
        int sum = 1;
        while (pHead1 = pHead1->next) sum++;
        return sum;
    }

    ListNode *walkStep(ListNode *pHead1, int step) {
        while (step--) {
            pHead1 = pHead1->next;
        }
        return pHead1;
    }

public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        /*
         假定 List1长度: a+n  List2 长度:b+n, 且 a<b
         那么 p1 会先到链表尾部, 这时p2 走到 a+n位置,将p1换成List2头部
         接着p2 再走b+n-(n+a) =b-a 步到链表尾部,这时p1也走到List2的b-a位置，还差a步就到可能的第一个公共节点。
         将p2 换成 List1头部，p2走a步也到可能的第一个公共节点。如果恰好p1==p2,那么p1就是第一个公共节点。  或者p1和p2一起走n步到达列表尾部，二者没有公共节点，退出循环。 同理a>=b.
         时间复杂度O(n+a+b)

        */
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while (p1 != p2) {
            if (p1 != nullptr) p1 = p1->next;
            if (p2 != nullptr) p2 = p2->next;
            if (p1 != p2) {
                if (p1 == nullptr) p1 = pHead2;
                if (p2 == nullptr) p2 = pHead1;
            }
        }
        return p1;

    }

    /*
找出2个链表的长度，然后让长的先走两个链表的长度差，然后再一起走
（因为2个链表用公共的尾部）
*/

    ListNode *FindFirstCommonNode_(ListNode *pHead1, ListNode *pHead2) {
        int len1 = findListLenth(pHead1);
        int len2 = findListLenth(pHead2);
        if (len1 > len2) {
            pHead1 = walkStep(pHead1, len1 - len2);
        } else {
            pHead2 = walkStep(pHead2, len2 - len1);
        }
        while (pHead1 != NULL) {
            if (pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }


};


int fun() {

    return 0;
}