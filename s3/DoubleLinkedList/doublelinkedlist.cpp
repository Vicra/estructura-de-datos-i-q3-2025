#include "doublelinkedlist.h"
#include <iostream>

using std::cout;
using std::endl;

DoubleLinkedList::DoubleLinkedList() {
    this->head = nullptr;
}

void DoubleLinkedList::push_back(int val){
    DLLNode* newNode = new DLLNode(val);
    // 1er caso no contiene elementos
    if(this->head == nullptr){
        this->head = newNode;
    }

    // 2do caso : contiene elementos
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

void DoubleLinkedList::print(){
    DLLNode*it = this->head;
    cout << "null <-";
    while(it != nullptr){
        cout << it->value;
        if(it->next != nullptr){
            cout << "=";
        } else {
            cout << "-> null";
        }
        it = it->next;
    }
    cout << endl;
}

bool DoubleLinkedList::remove(int val){
    // 1er caso no tiene elementos
    if(this->head == nullptr){
        return false;
    }

    // 2do caso : borrar la cabeza
    if(this->head->value == val){
        DLLNode* tmpToDelete = this->head;
        if(this->head->next != nullptr){
            this->head->next->prev = nullptr;
        }
        this->head = this->head->next;
        delete tmpToDelete;
        return true;
    }

    // 3er caso: no es la cabeza
    DLLNode*it = this->head;
    while(it->next != nullptr){
        if(it->next->value == val){
            DLLNode* tempToDelete = it->next;
            it->next = tempToDelete->next;
            if(tempToDelete->next != nullptr){
                tempToDelete->next->prev = it;
            }
            delete tempToDelete;
            return true;
        }
        it = it->next;
    }
    return false;

}
