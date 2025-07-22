#include "linkedlist.h"
#include <iostream>

using std::cout;
using std::endl;

LinkedList::LinkedList() {
    this->first = nullptr;
}

void LinkedList::insertNode(int newValue){
    Node *newNode = new Node(newValue);
    // 1. Caso base: no tiene elementos
    if(this->first == nullptr){
        this->first = newNode;
        return;
    }

    // 2 Caso: Insertar al final de la lista
    else {
        Node* iteratorNode = this->first;
        while(iteratorNode->next != nullptr){
            iteratorNode = iteratorNode->next;
        }
        iteratorNode->next = newNode;
    }
}

void LinkedList::printList(){
    Node* iteratorNode = this->first;
    cout << "Linked List: ";
    while(iteratorNode != nullptr){
        cout << iteratorNode->value;
        if(iteratorNode->next != nullptr){
            cout << ", ";
        }

        iteratorNode = iteratorNode->next;
    }
    cout << endl;
}
