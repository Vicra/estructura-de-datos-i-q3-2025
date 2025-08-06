#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "dllnode.h"

class DoubleLinkedList
{
public:
    DLLNode *head;
    DoubleLinkedList();

    void push_back(int val);
    void print();
    bool remove(int val);
};

#endif // DOUBLELINKEDLIST_H
