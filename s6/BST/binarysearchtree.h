#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "treenode.h"

class BinarySearchTree
{

public:
    TreeNode* root;
    BinarySearchTree();

    // functions
    bool insert(int value);
    TreeNode* insertNode(TreeNode* currentNode, TreeNode* newNode);

    TreeNode* successor(TreeNode* currentNode);
    TreeNode* mostLeftChild(TreeNode* currentNode);
};

#endif // BINARYSEARCHTREE_H
