#include "avltreenode.h"

AVLTreeNode::AVLTreeNode(int value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}
