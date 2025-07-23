#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class LinkedList
{
private:
    Node* head;
public:
    LinkedList();

    bool addNode(int val);
    string printList();
    vector<string> getItems();
};

#endif // LINKEDLIST_H
