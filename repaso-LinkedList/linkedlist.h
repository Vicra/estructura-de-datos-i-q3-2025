#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"

class LinkedList
{
public:
    Node* head;

    LinkedList();

    // functions
    void pushBack(Node* newNode);
    void print();
};

#endif // LINKEDLIST_H
