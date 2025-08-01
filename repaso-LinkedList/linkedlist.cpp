#include "linkedlist.h"
#include <iostream>
using std::cout;
using std::endl;

LinkedList::LinkedList() {
    this->head = nullptr;
}

void LinkedList::pushBack(Node* newNode){
    // 1er caso : lista vacia
    if(this->head == nullptr){
        this->head = newNode;
    } else {
        // 2do caso: lista contiene elementos

        // necesita llegar al ultimo elemento
        Node* iterator = this->head;
        while(iterator->next != nullptr){
            // seguir iterando
            iterator = iterator->next;
        }
        // el iterator esta en el ultimo
        iterator->next = newNode;
    }
}

void LinkedList::print(){
    Node* iterator = this->head;
    while(iterator != nullptr){
        cout << iterator->value << ",";
        iterator = iterator->next;
    }
    cout << endl;
}


// 1->2->null
// insert (3)
// 1->2->3->null
