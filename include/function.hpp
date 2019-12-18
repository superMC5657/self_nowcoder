#include <environment.h>
#include "bst.h"
#include "VisualTree.h"

typedef int ValueType;
typedef bst::TreeNode<ValueType> NodeType;
VisualTree<NodeType, ValueType> vtree(&NodeType::parent,
                                      &NodeType::left,
                                      &NodeType::right,
                                      &NodeType::val);

void treeNodeToNodeType(self_envs::TreeNode *root, NodeType *new_root) {
    new_root->val = root->val;
    if (root->left != nullptr) {
        new_root->left = new NodeType(0, new_root);
        treeNodeToNodeType(root->left, new_root->left);
    }
    if (root->right != nullptr) {
        new_root->right = new NodeType(0, new_root);
        treeNodeToNodeType(root->right, new_root->right);
    }
}

