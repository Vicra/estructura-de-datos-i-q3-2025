#include <QCoreApplication>
#include "binarysearchtree.h"
#include <iostream>
using std::cout;
using std::endl;

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
    bst.printCool("", bst.root, false);
    cout << "Inorder: " << bst.inorder() << endl;
    cout << "Preorder: " << bst.preorder() << endl;
    cout << "Postorder: " << bst.postorder() << endl;

    // bst.remove(40);
    // cout << "removing 40" << endl;
    // bst.printCool("", bst.root, false);
    // bst.remove(25);

    // cout << "removing 25" << endl;
    // bst.printCool("", bst.root, false);
    // cout << endl;

    // int searchValue = 40;
    // TreeNode* found = bst.search(bst.root, searchValue);
    // if(found != nullptr){
    //     cout << "found: " << found->value << endl;
    // } else {
    //     cout << "nout found value : " << searchValue << endl;
    // }

    return a.exec();
}
