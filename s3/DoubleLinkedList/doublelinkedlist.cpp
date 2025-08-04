#include "doublelinkedlist.h"

DoubleLinkedList::DoubleLinkedList() {
    this->head = nullptr;
}

void DoubleLinkedList::push_back(int val){
    DLLNode* newNode = new DLLNode(val);
    if(this->head == nullptr){
        this->head = newNode;
    }

    else {
        DLLNode *it = this->head;
        while(it->next != nullptr){
            it = it->next;
        }
        // estoy en el ultimo
        it->next = newNode;
        newNode->prev = it;
    }
}
