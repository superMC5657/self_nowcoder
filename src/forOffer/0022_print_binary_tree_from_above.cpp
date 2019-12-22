/* -*- coding: utf-8 -*-
  !@time: 2019/12/20 22:25
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0022_print_binary_tree_from_above.cpp
 */

#include <selfFun.h>

class Solution {
public://广度优先搜索
    vector<int> printFromTopToBottom(TreeNode *root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.front()->val);
            if (q.front()->left != nullptr)
                q.push(q.front()->left);
            if (q.front()->right != nullptr)
                q.push(q.front()->right);
            q.pop();
        }
        return res;
    }
};

int fun() {
    TreeNode *treeNode = stringToTreeNode("[1,2,3,4,5,6,7,8,9,10,11,12,13,14]");
    for (int i : Solution().printFromTopToBottom(treeNode)) {
        printf("%d ", i);
    }
}