/* -*- coding: utf-8 -*-
  !@time: 2019/12/18 19:08
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0018_mirror_binaryTree.cpp
 */
#include <selfFun.h>
#include <function.hpp>

using self_envs::TreeNode;
using std::swap;

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot) {
//            TreeNode *tmp = pRoot->right;
//            pRoot->right = pRoot->left;
//            pRoot->left = tmp;
            swap(pRoot->left, pRoot->right);
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};

int fun() {
    string str = "[8,8,7,9,2,null,null,null,null,4,7]";
    TreeNode *pRoot = stringToTreeNode(str);
    auto *nodeType = new NodeType();
    treeNodeToNodeType(pRoot, nodeType);
    vtree.draw(nodeType);
    Solution().Mirror(pRoot);
    treeNodeToNodeType(pRoot, nodeType);
    vtree.draw(nodeType);
    return 0;
}