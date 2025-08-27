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
};

#endif // BINARYSEARCHTREE_H
