#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree() {
    this->root = nullptr;
}

TreeNode* insertNode(TreeNode* currentNode, TreeNode* newNode){
    if(currentNode == nullptr) return newNode;

    // validar duplicates
    if(currentNode->value == newNode->value)
        return currentNode;

    // case 2: el valor es mayor que el nodo actual
    if(newNode->value > currentNode->value ){
        currentNode->right = insertNode(currentNode->right, newNode);
    } else {
        // caso 3: el valor es menor que el actual
        currentNode->left = insertNode(currentNode->left, newNode);
    }
    return nullptr;
}

bool BinarySearchTree::insert(int value){

    // otro caso base: validar duplicador
    if(this->root != nullptr && this->root->value == value){
        return false;
    }

    TreeNode* newNode = new TreeNode(value);
    // caso base: la raiz esta vacia
    if(this->root == nullptr){
        this->root = newNode;
        return true;
    }

    // case 2: el valor es mayor que el nodo actual
    if(value > this->root->value ){
        this->root->right = this->insertNode(this->root->right, newNode);
        return true;
    } else {
        // caso 3: el valor es menor que el actual
        this->root->left = this->insertNode(this->root->left, newNode);
        return true;
    }
}
