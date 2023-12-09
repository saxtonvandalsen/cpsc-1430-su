// Saxton Van Dalsen
// Queue.cpp
// Implementation of Queue.h operations

#include <iostream>
#include "Queue-hw4.h"
using namespace std;

// Constructor initializes empty queue
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

// Destructor that destroys the queue
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
    rear = nullptr;
}

// Inserting a value at rear of the queue
void Queue::enqueue(int num) {
    QueueNode * newNode = new QueueNode;
    newNode->value = num;
    newNode->next = nullptr;

    if(isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}

// Removing value from the front of the queue and returns the value
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return (EXIT_FAILURE);
    } else {
        int returnValue = front->value;

        QueueNode * nextNode = front;
        front = front->next;
        delete nextNode;
        numItems--;

        return returnValue;
    }
}

// Check if queue is empty
bool Queue::isEmpty() const {
    return numItems == 0;
}