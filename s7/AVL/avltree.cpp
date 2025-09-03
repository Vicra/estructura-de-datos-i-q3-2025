#include "avltree.h"

AVLTree::AVLTree() {
    this->root = nullptr;
}

void AVLTree::insert(int value){
    this->insertNode(this->root, new AVLTreeNode(value));
    return;
}

AVLTreeNode* AVLTree::insertNode(
    AVLTreeNode* currentNode,
    AVLTreeNode* newNode)
{
    if(currentNode == nullptr) return newNode;
    if(currentNode->value == newNode->value){
        delete newNode;
        return currentNode;
    }

    if (newNode->value < currentNode->value){
        currentNode->left = insertNode(currentNode->left, newNode);
    } else if(newNode->value > currentNode->value){
        currentNode->right = insertNode(currentNode->right, newNode);
    }

    // actualizar el height
    currentNode->height = max(
        getHeight(currentNode->left)
        , getHeight(currentNode->right)
    );

    // calcular el bf (factor de balance)


}


int AVLTree::getBalanceFactor(AVLTreeNode*node){
    if(node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

int AVLTree::getHeight(AVLTreeNode*node){
    if(node == nullptr) return 0;
    return node->height;
}

int AVLTree::max(int a, int b){
    return (a > b) ? a : b;
}
