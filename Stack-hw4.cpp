// Saxton Van Dalsen
// Stack.cpp
// Implementation of Stack.h operations

#include <iostream>
#include "Stack-hw4.h"
using namespace std;

// Constructor initializes empty stack
Stack::Stack() {
    top = nullptr;
}

// Destructor that destroys the stack
Stack::~Stack() {
    StackNode * curr = top;
    StackNode * nextNode = nullptr;

    while (curr != nullptr) {
        nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    top = nullptr;
}

// Function that adds a value to the stack
void Stack::push(int val) {
    StackNode * curr = nullptr;
    StackNode * newNode = new StackNode;
    newNode->value = val;
    newNode->next = nullptr;

    if (isEmpty()) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
}

// Function that removes a value from the top of the stack
// and returns that value
int Stack::pop() {
    StackNode * nextNode = nullptr;

    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return (EXIT_FAILURE);
    } else {
        int returnPop = top->value;
        nextNode = top->next;
        delete top;
        top = nextNode;
        return returnPop;
    }
}

// Check if stack is empty
bool Stack::isEmpty() {
    return top == nullptr;
}