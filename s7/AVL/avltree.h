#ifndef AVLTREE_H
#define AVLTREE_H
#include "avltreenode.h"

class AVLTree
{
public:
    AVLTreeNode*root;
    AVLTree();

    // functions
    void insert(int value); // wrapper or helper function
    AVLTreeNode* insertNode(AVLTreeNode* currentNode, AVLTreeNode* newNode);

    int getBalanceFactor(AVLTreeNode*node);
    int getHeight(AVLTreeNode*node);
    int max(int a, int b);
};

#endif // AVLTREE_H
