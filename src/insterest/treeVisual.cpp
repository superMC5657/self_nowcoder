/* -*- coding: utf-8 -*-
  !@time: 2019/11/21 20:59
  !@author: superMC @email: 18758266469@163.com
  !@fileName: treeVisual.cpp
 */
#include <iostream>
#include <ctime>
#include "bst.h"
#include "VisualTree.h"

using bst::TreeNode;
using bst::BSTree;

int fun() {
    typedef int ValueType;
    typedef TreeNode<ValueType> NodeType;

    BSTree<ValueType> tree;
    VisualTree<NodeType, ValueType> vtree(&NodeType::parent,
                                          &NodeType::left,
                                          &NodeType::right,
                                          &NodeType::val);

    int num = 15;

    srand(time(nullptr));
    for (int i = 0; i < num; ++i) {
        ValueType v = rand() % 1000;  // 随机生成一个[0，1000)的数
        tree.insert(v);
        std::cout << "insert : " << v << std::endl;
    }
    vtree.draw(tree.root());
    return 0;
}