// Saxton Van Dalsen
// Queue.h
// Declaration of Queue class, data members and function prototypes
#ifndef QUEUE_H
#define QUEUE_H
using namespace std;

class Queue {
    private:
        int * queueArray;
        int queueSize;
        int front;
        int rear;
        int numItems;
    
    public:
        Queue(int);
        ~Queue();
        void enqueue(int);
        int dequeue();
        bool isEmpty() const;
        bool isFull() const;
};

#endif