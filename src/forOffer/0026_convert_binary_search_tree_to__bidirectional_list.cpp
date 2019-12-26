/* -*- coding: utf-8 -*-
  !@time: 2019/12/26 23:52
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0026_convert_binary_search_tree_to__bidirectional_list.cpp
 */
#include <selfFun.h>

class Solution {
    TreeNode *bList = new TreeNode(-1);

    void dfs(TreeNode *pRootOfTree) {
        if (pRootOfTree) {
            dfs(pRootOfTree->left);
            bList->right = pRootOfTree;
            pRootOfTree->left = bList;
            bList = bList->right;
            dfs(pRootOfTree->right);
        }
    }

public:
    TreeNode *convert(TreeNode *pRootOfTree) {
        if (!pRootOfTree) {
            return nullptr;
        }
        TreeNode *bListHead = bList;
        dfs(pRootOfTree);

        bListHead = bListHead->right;
        bListHead->left = nullptr;
        return bListHead;
    }
};

class Solution_template {
private:
    void convertHelper(TreeNode *cur, TreeNode *&pre) {
        if (cur == nullptr) return;

        convertHelper(cur->left, pre);

        cur->left = pre;
        if (pre) pre->right = cur;
        pre = cur;

        convertHelper(cur->right, pre);
    }

public:
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (pRootOfTree == nullptr) return nullptr;
        TreeNode *pre = nullptr;

        convertHelper(pRootOfTree, pre);

        TreeNode *res = pRootOfTree;
        while (res->left)
            res = res->left;
        return res;
    }

};

int fun() {
    TreeNode *input = stringToTreeNode("[2,1,3]");
    TreeNode *output = Solution().convert(input);
    return 0;
}