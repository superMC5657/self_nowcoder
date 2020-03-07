/* -*- coding: utf-8 -*-
  !@time: 2020/3/8 3:56
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0057_the_next_node_of_the_binary_tree.cpp
 */
#include <environment.h>

using self_envs::TreeLinkNode;


class Solution {
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        if (pNode == nullptr)
            return nullptr;
        if (pNode->right != nullptr) {
            pNode = pNode->right;
            while (pNode->left != nullptr) {
                pNode = pNode->left;
            }
            return pNode;
        }

        while (pNode->next != nullptr) {
            if (pNode->next->left == pNode)
                return pNode->next;
            pNode = pNode->next;
        }
        return nullptr;
    }
    /*

1.二叉树为空，则返回空；
2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。
     */
};

int fun() {
    return 0;
}