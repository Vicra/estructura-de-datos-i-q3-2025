#include <QCoreApplication>
#include "binarysearchtree.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(40);
    bst.insert(25);
    bst.insert(40);

    try
    {
        bst.successor(bst.root->right->right->right);
    }
    catch (const std::exception& e){

    }

    return a.exec();
}
