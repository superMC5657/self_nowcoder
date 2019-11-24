/* -*- coding: utf-8 -*-
  !@time: 2019/10/29 21:58
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0004_rebuild_binary_tree.cpp
 */
#include <environment.h>
#include <function.hpp>

class Solution {
public:
    static self_envs::TreeNode *ConstructCore(int *preStart, int *preEnd, int *vinStart, int *vinEnd) {
        int rootValue = preStart[0];
        auto *root = new self_envs::TreeNode(preStart[0]);
        root->val = rootValue;
        root->left = nullptr;
        root->right = nullptr;
        if (preStart == preEnd) {
            if (vinStart == vinEnd && *preStart == *vinStart)
                return root;
            //else
            //throw std::exception("Invalid input");
        }
        int *rootVin = vinStart;
        while (rootVin <= vinEnd && *rootVin != rootValue)
            ++rootVin;
        //if(rootVin == vinEnd && *rootVin != rootValue)
        //throw std::exception("Invalid input");
        int leftLength = rootVin - vinStart;
        int *preLeftEnd = preStart + leftLength;
        if (leftLength > 0) {
            //构建左子树
            root->left = ConstructCore(preStart + 1, preLeftEnd, vinStart, rootVin - 1);
        }
        if (leftLength < preEnd - preStart) {
            //构建右子树
            root->right = ConstructCore(preLeftEnd + 1, preEnd, rootVin + 1, vinEnd);
        }
        return root;
    }

    static self_envs::TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty()) {
            return nullptr;
        }
        int *preStart = &pre[0];
        int *preEnd = &pre[pre.size() - 1];
        int *vinStart = &vin[0];
        int *vinEnd = &vin[vin.size() - 1];
        return ConstructCore(preStart, preEnd, vinStart, vinEnd);
    }
};

int fun() {

    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> in = {4, 7, 2, 1, 5, 3, 8, 6};
    self_envs::TreeNode *root = Solution::reConstructBinaryTree(pre, in);
    NodeType *new_root = new NodeType();
    treeNodeToNodeType(root, new_root);
    vtree.draw(new_root);
    return 0;
}
