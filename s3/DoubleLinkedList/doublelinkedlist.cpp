#include "doublelinkedlist.h"
#include <iostream>

using std::cout;
using std::endl;

DoubleLinkedList::DoubleLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
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
        this->tail = newNode;
    }
}

void DoubleLinkedList::print(){
    DLLNode*it = this->head;

    if(this->head == nullptr){
        cout << "head: null" << endl;
    } else {
        cout << "Head: " << this->head->value << endl;
        cout << "null <-";
    }
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
    if(this->tail == nullptr){
        cout << "tail: null" << endl;
    } else {
        cout << "Tail: " << this->tail->value << endl;
    }

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

        // caso: solamente hay un nodo (tail y head son iguales)
        if(this->head->next == nullptr
            && this->head == this->tail){
            this->head = nullptr;
            this->tail = nullptr;

            delete tmpToDelete;
            return true;
        }

        this->head = this->head->next;
        delete tmpToDelete;
        return true;
    }

    // TODO: cuando es la tail



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


void DoubleLinkedList::reverse() {
    // asignar el tail a la head
    this->tail = this->head;

    // asignar temporales (iteradores)
    DLLNode* tmp1 = this->head;
    DLLNode* tmp2 = tmp1->next;

    // reasignar punteros de la cabeza (now tail)
    tmp1->next = nullptr;
    tmp1->prev = tmp2;

    while(tmp2 != nullptr){
        // reasignar punteros de cada nodo interno + la cola
        tmp2->prev = tmp2->next;
        tmp2->next = tmp1;

        //iterar o actualizar temps
        tmp1 = tmp2;
        tmp2 = tmp2->prev; // tmp2 = tmp1->prev;
    }
    // reasignar la cabeza
    this->head = tmp1;
}
