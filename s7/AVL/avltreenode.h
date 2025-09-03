#ifndef AVLTREENODE_H
#define AVLTREENODE_H

class AVLTreeNode
{
public:
    AVLTreeNode(int value);

    int value;
    int height;
    AVLTreeNode*left;
    AVLTreeNode*right;
};

#endif // AVLTREENODE_H
