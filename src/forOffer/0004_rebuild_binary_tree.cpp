/* -*- coding: utf-8 -*-
  !@time: 2019/10/29 21:58
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0004_rebuild_binary_tree.cpp
 */
#include <environment.h>

TreeNode *ConstructCore(int *preStart, int *preEnd, int *vinStart, int *vinEnd) {
    int rootValue = preStart[0];
    TreeNode *root = new TreeNode(preStart[0]);
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

class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() == 0 || vin.size() == 0)
            return nullptr;
        int *preStart = &pre[0];
        int *preEnd = &pre[pre.size() - 1];
        int *vinStart = &vin[0];
        int *vinEnd = &vin[vin.size() - 1];
        return ConstructCore(preStart, preEnd, vinStart, vinEnd);
    }
};

int fun() {
    return 0;
}