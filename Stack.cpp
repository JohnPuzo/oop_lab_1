// Stack.cpp
#include "Stack.h"
#include <iostream>


Stack::Stack() : topNode(nullptr) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(std::string text) {
    node* newNode = new node;   
        newNode->text = text;       
        newNode->next = topNode;      
        newNode->prev = nullptr;
    if (!isEmpty()) {
        topNode->prev = newNode;
    }  
    topNode = newNode;
    currNode = newNode;                         
}

void Stack::pop() {
    if (isEmpty()) {
        std::cout<<"Empty Stack";
    }
    node* oldTop = topNode;
    topNode = topNode->next;
    topNode->prev = nullptr;
    delete oldTop;
    currNode = topNode;
}

std::string Stack::top() const {
    if (isEmpty()) {
        std::cout<<"Empty Stack";
    }
    return currNode->text; 
}

bool Stack::isEmpty() const {
    return topNode == nullptr;
}

std::string Stack::forRedo() {
    if (isEmpty()) {
        std::cout<<"Empty Stack";
        return "";
    }
    if (currNode -> next == nullptr){
        return "";
    }
    else{
        currNode = currNode -> prev;
        return currNode -> text;
    }
}

void Stack::deleteRedo(int redoNum) {
    int i;
    for (i=0; i<redoNum; i++){
        pop();
    }
}

void Stack::move() {
    currNode = currNode -> next;
}
