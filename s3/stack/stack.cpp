#include "stack.h"
#include <iostream>

using std::cout;
using std::endl;

Stack::Stack() {
    this->head = nullptr;
}

void Stack::push(StackNode* newNode){
    // 1er caso stack vacio
    if(this->head == nullptr){
        this->head = newNode;
    } else {
        // 2do caso: existen elementos
        newNode->next = this->head;
        this->head = newNode;
    }
}

void Stack::print(){
    StackNode* it = this->head;
    while(it != nullptr){
        cout << it->value;

        if(it->next == nullptr) {
            cout << " -> nullptr";
        } else {
            cout << "->";
        }
        it = it->next;
    }
    cout << endl;
}

int Stack::pop(){
    if(this->head != nullptr) {
        int valueToBePopped = this->head->value;

        StackNode* tmpToBeDeleted = this->head;
        this->head = this->head->next;
        delete tmpToBeDeleted;

        return valueToBePopped;
    } else {
        return -1;
    }
}


int Stack::peek() {
    return (this->head != nullptr)
       ? this->head->value
       : -1;
}
