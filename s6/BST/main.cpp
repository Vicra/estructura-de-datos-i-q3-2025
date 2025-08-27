#include <QCoreApplication>
#include "binarysearchtree.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BinarySearchTree bst;
    bst.insert(3);
    bst.insert(4);
    bst.insert(2);

    return a.exec();
}
