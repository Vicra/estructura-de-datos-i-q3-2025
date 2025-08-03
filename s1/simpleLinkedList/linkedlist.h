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
    bool deleteValue(int valueToDelete);
};

// adding new code

#endif // LINKEDLIST_H
