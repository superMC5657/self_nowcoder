/* -*- coding: utf-8 -*-
  !@time: 2020/3/8 4:41
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0058_different_forms_of_tree.cpp
 */

#include <environment.h>

using self_envs::TreeNode;

class Solution {
public:
    bool isSymmetrical(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return fun(root->left, root->right);

    }

    bool fun(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return left->val == right->val && fun(left->left, right->right) && fun(left->right, right->left);
    }
};

int fun() {
    return 0;
}