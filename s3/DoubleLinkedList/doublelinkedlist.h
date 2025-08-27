#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "dllnode.h"

class DoubleLinkedList
{
public:
    DLLNode *head;
    DLLNode *tail;
    DoubleLinkedList();

    void push_back(int val);
    void print();
    bool remove(int val);
    void reverse();
    void insertAfterNode(DLLNode* node, int value);
    bool deletePredecessor(DLLNode* node);
};

#endif // DOUBLELINKEDLIST_H
