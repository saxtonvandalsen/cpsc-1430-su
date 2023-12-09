// Saxton Van Dalsen
// lab9.cpp
// Purpose: This program utilizes stack and queue operations to reverse a given 'k' values from a queue of integers
// while maintaining the original order of the other integers
#include "Queue-lab9.h"
#include "Stack-lab9.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[]) {

    // Array of 10 integers
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Print out original array
    cout << "Original   array: [";
    for (int i = 0; i < 10; i++) {
        cout << arr[i];
        if (i < 9) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Instantiating new queue object of size 10
    Queue newQueue(10);

    // Enqueuing the 10 elements of the array into newQueue
    for (int i = 0; i < 10; i++) {
        newQueue.enqueue(arr[i]);
    }

    // Instantiating new stack object of size 10
    Stack newStack(10);

    // To access the first command-line argument after program name,
    // assigning integer k
    int k = atoi(argv[1]);
    int count = 0;

    // Setting (size minus k) to aid in correctly reversing
    // queue for given integer k using stack & queue operations
    k = 10 - k;

    // Checking if input in command line is out of range
    if (k < 0 || k > 10) {
        cout << "Error: Input is out of the array's range." << endl;
        return 0;
    }

    // Dequeuing (size mius k) values and pushing them into the newStack
    while (count < k && !newQueue.isEmpty()){
        newStack.push(newQueue.dequeue());
    }

    // Popping (size minus k) values and enqueuing them into NewQueue
    while (!newStack.isEmpty()){
        newQueue.enqueue(newStack.pop());
    }

    // Dequeing requested k values and pushing them into newStack
    for (int i = 0; i < k; i++){
        newStack.push(newQueue.dequeue());
    }
    
    // Popping requested k values and enqueuing them into newQueue
    while(!newStack.isEmpty()){
        newQueue.enqueue(newStack.pop());
    }

    // Printing out reverse order of k integers
    cout << "Reversed first 8: [";
    for ( int i = 0; i < 10; i++){
        cout << newQueue.dequeue();
        if (i < 9) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}