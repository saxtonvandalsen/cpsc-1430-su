// Saxton Van Dalsen
// Stack.cpp
// Implementation of Stack operations
#include "Stack-lab9.h"
#include <iostream>
using namespace std;

// Constructor that initializes the size for a new Stack
Stack::Stack(int size) {
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

// Destructor to deallocate memory
Stack::~Stack(){
    delete [] stackArray;
}

// Function to push/add a new integer onto the top of the stack
void Stack::push(int num) {
    if(isFull()){
        cout << "The stack is full!" << endl;
    } else {
        top++;
        stackArray[top] = num;
    }
}

// Function to pop and remove the top element from the stack
int Stack::pop() {
    if (isEmpty()){
        cout << "The stack is empty!" << endl;
        return -1;
    } else {
        int returnValue = stackArray[top];
        top--;
        return returnValue;
    }
}

// Checking if stack is full (true), otherwise false
bool Stack::isFull() const {
    return top == stackSize - 1;
}

// Checking if stack is empty (true), otherwise false
bool Stack::isEmpty() const {
    return top == -1;
}