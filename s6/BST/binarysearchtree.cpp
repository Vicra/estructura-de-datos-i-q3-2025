#include "binarysearchtree.h"
#include <iostream>

using std::cout;
using std::endl;

BinarySearchTree::BinarySearchTree() {
    this->root = nullptr;
}

TreeNode* BinarySearchTree::insertNode(TreeNode* currentNode, TreeNode* newNode){
    if(currentNode == nullptr) return newNode;

    // case 2: el valor es mayor que el nodo actual
    if(newNode->value > currentNode->value ){
        currentNode->right = insertNode(currentNode->right, newNode);
    } else if(newNode->value < currentNode->value ) {
        // caso 3: el valor es menor que el actual
        currentNode->left = insertNode(currentNode->left, newNode);
    } else {
        delete newNode;
    }
    return currentNode;
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

TreeNode* BinarySearchTree::successor(TreeNode* currentNode){
    if(currentNode == nullptr) return nullptr;

    return mostLeftChild(currentNode->right);
}


TreeNode* BinarySearchTree::mostLeftChild(TreeNode* currentNode){
    if(currentNode == nullptr) return nullptr;
    if(currentNode->left == nullptr){
        return currentNode;
    }
    else {
        return mostLeftChild(currentNode->left);
    }
}

TreeNode* BinarySearchTree::predecessor(TreeNode* currentNode){
    if(currentNode == nullptr) return nullptr;

    return mostRightChild(currentNode->left);
}


TreeNode* BinarySearchTree::mostRightChild(TreeNode* currentNode){
    if(currentNode == nullptr) return nullptr;
    if(currentNode->right == nullptr){
        return currentNode;
    }
    else {
        return mostRightChild(currentNode->right);
    }
}


bool BinarySearchTree::remove(int value){
    this->root = removeNode(this->root, value);
    return true;
}


TreeNode* BinarySearchTree::removeNode(TreeNode* node, int x){
    // caso 1: nodo es nullptr
    if(node == nullptr) return nullptr;

    // caso 2: x es menor que el nodo actual
    if(x < node->value) {
        node->left = removeNode(node->left, x);
        return node;
    }
    // caso 3: x es mayor que el nodo actual
    else if(x > node->value){
        node->right = removeNode(node->right, x);
        return node;
    }
    // caso 4: x es igual al nodo actual
    else {
        // caso 4a: solamente tiene un hijo derecho
        if(node->left == nullptr && node->right != nullptr){
            TreeNode* rightChild = node->right;
            delete node;
            return rightChild;
        }

        // caso 4b: solamente tiene un hijo izquierdo
        else if(node->left != nullptr && node->right == nullptr){
            TreeNode* leftChild = node->left;
            delete node;
            return leftChild;
        }

        // caso 4c: no tiene hijos, es nodo hoja
        else if(node->left == nullptr && node->right == nullptr){
            delete node;
            return nullptr;
        }

        // caso 4d: tengo 2 hijos
        else {
            TreeNode* predeccessor = this->predecessor(node);
            node->value = predeccessor->value;
            node->left = this->removeNode(node->left, node->value);

            /*** Caso con sucesor
             *
             *  TreeNode* successor = this->successor(node);
             *  node->value = successor->value;
             *  node->right = this->removeNode(node->right, node->value);
             ***/
            return node;
        }
    }
}


TreeNode* BinarySearchTree::search(TreeNode* currentNode, int x){
    if(currentNode == nullptr) return nullptr;
    if(currentNode->value == x){
        return currentNode;
    }

    else if(x < currentNode->value){
        return search(currentNode->left, x);
    }
    else {
        return search(currentNode->right, x);
    }
}


void BinarySearchTree::print(){
    this->printTree(this->root);
    cout << endl;
}

void BinarySearchTree::printTree(TreeNode* currentNode){
    if(currentNode == nullptr) cout << " null ";
    else {
        cout << currentNode->value << ", " ;
        cout << " L : "; printTree(currentNode->left);
        cout << " R : "; printTree(currentNode->right);
    }
}

void BinarySearchTree::printCool(string prefix, TreeNode *currentRoot, bool isLeft)
{
    if( currentRoot != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout << currentRoot->value << endl;

        // enter the next tree level - left and right branch
        printCool( prefix + (isLeft ? "│   " : "    "), currentRoot->left, true);
        printCool( prefix + (isLeft ? "│   " : "    "), currentRoot->right, false);
    }
    else {
        cout << prefix;
        cout << (isLeft ? "├─" : "└─" );
        cout << "nil" << endl;
    }
}
