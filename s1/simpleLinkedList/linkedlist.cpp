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

bool LinkedList::deleteValue(int valueToDelete){
    // caso base 0: lista vacia
    if(this->first == nullptr) {
        return false;
    }

    // 1er caso: es la cabeza
    if(this->first->value == valueToDelete){
        Node* tmpToDelete = this->first;

        // reasignar la cabeza
        this->first = this->first->next;
        delete tmpToDelete;
    }

    else {
        Node* it = this->first;
        while(it->next != nullptr){
            if(it->next->value == valueToDelete){
                // encontre
                Node* tmpToDelete = it->next;

                // actualizar el next de it
                it->next = tmpToDelete->next;

                // liberar la memoria
                delete tmpToDelete;
                return true;
            }
            it = it->next;
        }
    }
    return false;

}
