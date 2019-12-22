/* -*- coding: utf-8 -*-
  !@time: 2019-12-17 01:28
  !@author: superMC @email: 18758266469@163.com
  !@fileName: subTree_of_tree.cpp
 */


#include <selfFun.h>
#include <function.hpp>

class Solution {
private:
    bool isSame(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot1 == nullptr && pRoot2 == nullptr) {
            return true;
        }
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }
        return pRoot1->val == pRoot2->val && isSame(pRoot1->left, pRoot2->left) && isSame(pRoot1->right, pRoot2->right);
    }

public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (!pRoot2 || !pRoot1) {
            return false;
        }
        bool selfSame = isSame(pRoot1, pRoot2);
        bool leftSame = pRoot1->left ? HasSubtree(pRoot1->left, pRoot2) : false;
        bool rightSame = pRoot1->right ? HasSubtree(pRoot1->right, pRoot2) : false;
        return selfSame || leftSame || rightSame;
    }
};

int fun() {
    string string1 = "[8,8,7,9,2,null,null,null,null,4,7]";
    string string2 = "[8,9,2]";
    TreeNode *pRoot1 = stringToTreeNode(string1);
    TreeNode *pRoot2 = stringToTreeNode(string2);
    NodeType *new_root = new NodeType();
    treeNodeToNodeType(pRoot1, new_root);
    bool isSubTree = Solution().HasSubtree(pRoot1, pRoot2);
    vtree.draw(new_root);
    string out = isSubTree ? "true" : "false";
    printf("%s", out.c_str());
    return 0;
}