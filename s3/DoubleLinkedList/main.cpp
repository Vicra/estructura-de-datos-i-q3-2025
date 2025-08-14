#include <QCoreApplication>
#include "doublelinkedlist.h"
#include <iostream>
using std::cout;
using std::endl;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DoubleLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.print();
    dll.reverse();
    dll.print();

    cout << "removing 2" << endl;
    dll.remove(2);
    dll.print();
    cout << "removing 1" << endl;
    dll.remove(1);
    dll.print();
    return a.exec();
}
