// Saxton Van Dalsen
// Stack.h
// Description: Header file for a linked list-based stack of integers.

#ifndef STACK_H
#define STACK_H

class Stack {
    private:
        struct StackNode {
            int value;
            StackNode * next;
        };
    StackNode * top;

    public:
        Stack();
        ~Stack();
        void push(int);
        int pop();
        bool isEmpty();
};

#endif