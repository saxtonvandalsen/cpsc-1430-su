// Saxton Van Dalsen
// Queue.h
// Description: Header file for linked list-based queue of integers.

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    private:
        struct QueueNode {
            int value;
            QueueNode * next;
        };
    QueueNode * front;
    QueueNode * rear;
    int numItems;
    
    public:
        Queue();
        ~Queue();
        void enqueue(int);
        int dequeue();
        bool isEmpty() const;
};

#endif