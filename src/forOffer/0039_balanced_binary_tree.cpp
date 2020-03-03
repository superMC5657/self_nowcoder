/* -*- coding: utf-8 -*-
  !@time: 2020/3/2 21:42
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0039_balanced_binary_tree.cpp
 */
#include <environment.h>
#include <selfFun.h>

using self_envs::TreeNode;

class Solution {
public:
    bool IsBalanced_Solution(TreeNode *pRoot) {
        if (pRoot == nullptr) return true;
        int depth = 0;
        return IsBalanced_Solution(pRoot, depth);
    }

    bool IsBalanced_Solution(TreeNode *pRoot, int &pDepth) {
        if (pRoot == nullptr) {
            pDepth = 0;
            return true;
        }
        int left = 0, right = 0;
        if (IsBalanced_Solution(pRoot->left, left) && IsBalanced_Solution(pRoot->right, right)) {
            int diff = left - right;
            if (abs(diff) <= 1) {
                pDepth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
};

int fun() {
    TreeNode *root = stringToTreeNode("[3,9,20,null,null,15,7]");
    printf("%s", Solution().IsBalanced_Solution(root) ? "true" : "false");
    return 0;
}