/* -*- coding: utf-8 -*-
  !@time: 2019-12-23 01:50
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 0024_Binary_tree_neutralization_to_a_certain_value_path.cpp
 */
#include <selfFun.h>
#include <function.hpp>

class Solution {
    void dfs(TreeNode *root, int s, vector<vector<int>> &ret, vector<int> &trace) {
        trace.push_back(root->val);
        if (!root->left && !root->right) { //确认是否为叶子节点
            if (s == root->val)
                ret.push_back(trace);
        }
        if (root->left)
            dfs(root->left, s - root->val, ret, trace);
        if (root->right)
            dfs(root->right, s - root->val, ret, trace);
        trace.pop_back(); // 传递引用之后 不符合规则的路径回退
    }

public:
    vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
        vector<vector<int>> ret;
        vector<int> trace;
        if (root)
            dfs(root, expectNumber, ret, trace);
        return ret;
    }
};

int fun() {
    string str("[1,2,3,4,5,6,7,8,2,3,0,1,0]");
    int num = 11;
    TreeNode *input = stringToTreeNode(str);
    NodeType *showInput = new NodeType();
    treeNodeToNodeType(input, showInput);
    vtree.draw(showInput);
    vector<vector<int>> findOut = Solution().FindPath(input, num);
    for (auto &i : findOut) {
        for (int j : i) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}