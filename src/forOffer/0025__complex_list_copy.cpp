/* -*- coding: utf-8 -*-
  !@time: 2019-12-24 01:15
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0025__complex_list_copy.cpp
 */
#include <environment.h>

using self_envs::RandomListNode;

class Solution {
public:
    RandomListNode *Clone(RandomListNode *pHead) {
        if (pHead == nullptr) return nullptr;
        RandomListNode *pHead_copy = pHead;
        RandomListNode *head = new RandomListNode(0);
        RandomListNode *head1 = head;

        unordered_map<RandomListNode *, RandomListNode *> mp;
        typedef std::pair<RandomListNode *, RandomListNode *> rPair;
        while (pHead_copy) {
            RandomListNode *tmp = new RandomListNode(pHead_copy->label);
            mp.insert(rPair(pHead_copy, tmp));
            head1->next = tmp;
            head1 = head1->next;
            if (!pHead_copy->next)
                break;
            pHead_copy = pHead_copy->next;
        }
        pHead_copy = pHead;
        head1 = head;
        while (pHead_copy) {
            head1 = head1->next;
            head1->random = mp[pHead_copy->random];
            if (!pHead_copy->next)
                break;
            pHead_copy = pHead_copy->next;
        }

        return head->next;
    }
};

class Solution_template {
public:
    RandomListNode *Clone(RandomListNode *pHead) {
        if (!pHead) return NULL;
        nodeClone(pHead);
        connectRandom(pHead);
        return reconnect(pHead);
    }


//[1]复制结点，插入到原结点后方
    void nodeClone(RandomListNode *head) {
        RandomListNode *pNode = head;
        while (pNode != NULL) {
            RandomListNode *pClone = new RandomListNode(pNode->label);
            pClone->next = pNode->next;
            pNode->next = pClone;
            pNode = pClone->next;
        }
    }

//[2]还原新结点的random指针
    void connectRandom(RandomListNode *head) {
        RandomListNode *pNode = head;

        while (pNode != NULL) {
            RandomListNode *pClone = pNode->next;
            if (pNode->random) {
                pClone->random = pNode->random->next;
            }
            pNode = pClone->next;
        }
    }

//[3]拆分
    RandomListNode *reconnect(RandomListNode *head) {
        RandomListNode *pNode = head;
        RandomListNode *result = head->next;
        while (pNode != NULL) {
            RandomListNode *pClone = pNode->next;
            pNode->next = pClone->next;
            pNode = pNode->next;
            if (pNode != NULL)
                pClone->next = pNode->next;

        }
        return result;
    }

};

int fun() {
    srand(time(NULL));
    int low = 0, high = 3;

    RandomListNode *head = new RandomListNode(0);
    vector<RandomListNode *> v;
    RandomListNode *input = head;
    v.push_back(input);
    for (int i = 1; i < high + 1; ++i) {
        input->next = new RandomListNode(i);
        v.push_back(input->next);
        input = input->next;
    }
    input = head;
    for (int j = 1; j < high + 2; ++j) {
        int rnum = rand() % (high - low + 1) + low;
        input->random = v[rnum];
        input = input->next;
    }
    RandomListNode *out = Solution().Clone(head);
    return 0;


}