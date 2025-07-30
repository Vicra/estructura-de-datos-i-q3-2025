#include <QCoreApplication>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LinkedList l;
    l.insertNode(5);
    l.insertNode(6);
    l.insertNode(6);
    l.insertNode(7);
    l.printList();
    l.deleteValue(6);
    l.printList();

    return a.exec();
}
