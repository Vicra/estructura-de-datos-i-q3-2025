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
    bst.remove(40);
    cout << "removing 40" << endl;
    bst.printCool("", bst.root, false);
    bst.remove(25);

    cout << "removing 25" << endl;
    bst.printCool("", bst.root, false);
    cout << endl;

    return a.exec();
}
