#include "linkedlist.h"
#include <exception>
#include <iostream>
#include <string>

using std::exception;
using std::cout;
using std::string;
using std::to_string;

LinkedList::LinkedList() {
    this->head = nullptr;
}

bool LinkedList::addNode(int val){
    try {
        Node*newNode = new Node(val);
        if(this->head == nullptr){
            this->head = newNode;
            return true;
        } else {
            Node*iterator = this->head;
            while(iterator->next != nullptr){
                iterator = iterator->next;
            }

            iterator->next = newNode;
            return true;
        }
    } catch (std::exception e) {
        cout << "error" ;
        return false;
    }
}

string LinkedList::printList(){
    string list = "";
    Node*iterator = this->head;
    while(iterator!= nullptr){
        list += iterator->value;
        if(iterator->next != nullptr){
            list += "," ;
        }
        iterator = iterator->next;
    }
    return list;
}

vector<string> LinkedList::getItems() {
    vector<string> items;
    Node* current = head;

    while (current != nullptr) {
        items.push_back(to_string(current->value));
        current = current->next;
    }

    return items;
}

