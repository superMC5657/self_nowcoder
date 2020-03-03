/* -*- coding: utf-8 -*-
  !@time: 2020/3/2 21:02
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0038_the_depth_of_the_binary_tree.cpp
 */
#include <environment.h>
#include <selfFun.h>

using self_envs::TreeNode;


class Solution {
    int ret = 0;
public:
    int TreeDepth(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return 0;
        get_localDepth(pRoot, 1);
        return ret;
    }

    void get_localDepth(TreeNode *pRoot, int preDepth) {
        if (pRoot->left == nullptr && pRoot->right == nullptr) {
            ret = max(ret, preDepth);
        }
        if (pRoot->right != nullptr) {
            get_localDepth(pRoot->right, preDepth + 1);
        }
        if (pRoot->left != nullptr) {
            get_localDepth(pRoot->left, preDepth + 1);
        }
    }

};

int fun() {
    TreeNode *input = stringToTreeNode("{1,2,3}");
    printf("%d", Solution().TreeDepth(input));
    return 0;
}