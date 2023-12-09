// Saxton Van Dalsen
// Stack.h
// Declaration of Stack class, data members and function prototypes
#ifndef STACK_H
#define STACK_H
using namespace std;

class Stack {
    private:
        int * stackArray;
        int stackSize;
        int top;

    public:
        Stack(int);
        ~Stack();
        void push(int);
        int pop();
        bool isEmpty() const;
        bool isFull() const;
};

#endif