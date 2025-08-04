#ifndef DLLNODE_H
#define DLLNODE_H

class DLLNode
{
public:
    int value;
    DLLNode *prev;
    DLLNode *next;
    DLLNode(int val);
};

#endif // DLLNODE_H
