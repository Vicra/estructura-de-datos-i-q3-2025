#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <string>
#include "treenode.h"

using std::string;

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

    TreeNode* predecessor(TreeNode* currentNode);
    TreeNode* mostRightChild(TreeNode* currentNode);

    bool remove(int value);
    TreeNode* removeNode(TreeNode* node, int x);
    TreeNode* search(TreeNode* currentNode, int x);

    void print();
    void printTree(TreeNode* currentNode);
    void printCool(string prefix, TreeNode *currentRoot, bool isLeft);

    // metodos de recorrer
    string inorder() {
        return inorderRaw(this->root);
    }

    string preorder() {
        return preorderRaw(this->root);
    }

    string postorder() {
        return postOrderRaw(this->root);
    }

    string inorderRaw(TreeNode* node);
    string preorderRaw(TreeNode* node);
    string postOrderRaw(TreeNode* node);

    int depth(int x);
    int depthRaw(int x, TreeNode* currentNode, int iterations);
};

#endif // BINARYSEARCHTREE_H
