#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList
{
private:
    Node *first;
public:
    LinkedList();

    void insertNode(int newValue);
    void printList();
};

#endif // LINKEDLIST_H
