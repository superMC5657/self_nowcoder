/* -*- coding: utf-8 -*-
  !@time: 2019/11/21 19:57
  !@author: superMC @email: 18758266469@163.com
  !@fileName: PosSetter.h
 */
#ifndef SELF_NOWCODER_POSSETTER_H
#define SELF_NOWCODER_POSSETTER_H

#include "InfoH.h"

template<class TreeNode>
class PosSetter {
public:
    PosSetter(TreeNode *TreeNode::* p, TreeNode *TreeNode::* l, TreeNode *TreeNode::* r) :
            parent(p), left(l), right(r) {
    }

    void operator()(TreeNode *node) {
        TreeNode *p = node->*parent;
        if (p != NULL) {
            if (node == p->*left) { node->pos = p->pos - 1; }
            if (node == p->*right) { node->pos = p->pos + 1; }
        }
    }

private:
    TreeNode *TreeNode::*parent;
    TreeNode *TreeNode::*left;
    TreeNode *TreeNode::*right;
};


#endif //SELF_NOWCODER_POSSETTER_H
