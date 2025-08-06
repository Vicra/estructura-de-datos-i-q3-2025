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
    dll.print();
    cout << "removing 1" << endl;
    dll.remove(1);
    dll.print();

    dll.push_back(1);
    dll.push_back(2);
    dll.print();
    dll.remove(1);
    cout << "removing 1" << endl;
    dll.print();

    dll.push_back(3);
    dll.print();
    dll.remove(3);
    cout << "removing 3" << endl;
    dll.print();

    dll.push_back(3);
    dll.push_back(4);
    dll.print();
    dll.remove(3);
    cout << "removing 3" << endl;
    dll.print();
    return a.exec();
}
