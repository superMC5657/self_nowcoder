/* -*- coding: utf-8 -*-
  !@time: 2019-12-18 01:01
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0017_subStructure_of_tree.cpp
 */

#include <selfFun.h>

class Solution {

private:
    bool isChild(TreeNode *A, TreeNode *B) {
        if (!A && B) return false;
        if (!B) return true;
        if (A->val != B->val) return false;

        return isChild(A->left, B->left) && isChild(A->right, B->right);
    }

public:
    bool HasSubtree(TreeNode *A, TreeNode *B) {
        if (!B || !A) return false;
        return isChild(A, B) || isChild(A->left, B) || isChild(A->right, B);
    }
};

int fun() {
    string string1 = "[8,8,7,9,2,null,null,null,null,4,7]";
    string string2 = "[8,9,2]";
    TreeNode *pRoot1 = stringToTreeNode(string1);
    TreeNode *pRoot2 = stringToTreeNode(string2);
    bool isSubTree = Solution().HasSubtree(pRoot1, pRoot2);
    string out = isSubTree ? "true" : "false";
    printf("%s", out.c_str());
    return 0;
}