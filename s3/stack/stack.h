#ifndef STACK_H
#define STACK_H

#include "stacknode.h"

class Stack
{
public:
    StackNode* head;
    Stack();

    void push(StackNode* newNode);
    void print();
    int pop();
    int peek();
};

#endif // STACK_H
