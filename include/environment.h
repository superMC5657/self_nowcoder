/* -*- coding: utf-8 -*-
  !@time: 2019-09-16 15:00
  !@author: superMC @email: 18758266469@163.com
  !@fileName: environment.h
 */

#ifndef SELF_LEETCODE_ENVIROMENT_H
#define SELF_LEETCODE_ENVIROMENT_H

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <map>
#include <queue>
#include <functional>

using std::stack;
using std::unordered_map;
using std::map;
using std::pair;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;
using std::stringstream;
using std::sort;
using std::map;
using std::max;
using std::min;
using std::function;
namespace self_envs {
    struct ListNode {
        int val;
        ListNode *next;

        //make me can use ListNode(5)
        //lambda;
        explicit ListNode(int x) : val(x), next(nullptr) {
        }
    };

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    struct Node {
        int val;
        vector<Node *> neighbors;

        Node() = default;

        explicit Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node *> _neighbors) {
            val = _val;
            neighbors = std::move(_neighbors);
        }
    };
}
#endif //SELF_LEETCODE_ENVIROMENT_H
