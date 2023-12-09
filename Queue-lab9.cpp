// Saxton Van Dalsen
// Queue.cpp
// Implementation of Queue operations
#include "Queue-lab9.h"
#include <iostream>

// Constructor that initializes size for a new Queue
Queue::Queue(int size){
    queueArray = new int[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}

// Destructor to deallocate memory
Queue::~Queue(){
    delete [] queueArray;
}

// Function to enqueue/add new integer to the rear of the queue
void Queue::enqueue(int num){
    if (isFull()){
        cout << "The queue is full!" << endl;
    } else {
        rear = (rear + 1) % queueSize;
        queueArray[rear] = num;
        numItems++;
    }
}

// Function to dequeue/remove an integer from the front of the queue
int Queue::dequeue() {
    if (isEmpty()){
        cout << "The stack is empty!" << endl;
        return -1;
    } else {
        front = (front + 1) % queueSize;
        numItems--;
        return queueArray[front];
    }
}

// Check if queue is empty (true), otherwise false
bool Queue::isEmpty() const {
    return numItems == 0;
}

// Check if queue is full (true), otherwise false
bool Queue::isFull() const {
    return numItems == queueSize;
}