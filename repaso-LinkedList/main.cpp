#include <QCoreApplication>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LinkedList l;
    l.pushBack(new Node(1));
    l.pushBack(new Node(2));
    l.pushBack(new Node(3));
    l.print();

    return a.exec();
}
