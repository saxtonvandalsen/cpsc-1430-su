// Saxton Van Dalsen
// OrderedList.cpp
#include <iostream>
#include "OrderedList-lab6.h"
using namespace std;

// Default constructor initializing head to null
OrderedList::OrderedList(){
    head = nullptr;
}

// Copy constructor to make deep copies of the nodes into a new linked list
OrderedList::OrderedList(OrderedList &copyList){
   head = nullptr;
   Node * newNode = nullptr;
   Node * prev = nullptr;
   Node * curr = copyList.head; // Initializing pointer 'curr' to the head of the list passed in for copying

   // Traversing the 'copyList' and copying each of the nodes values
   while (curr != nullptr){
        newNode = new Node; 
        newNode->value = curr->value; // Copying 'curr' node value from 'copyList' to 'newNode' value
        newNode->next = nullptr;
        
        // Set head to newNode if list is empty
        if (!prev){
            head = newNode;
        } else {
            prev->next = newNode; // Setting previous node 'next' to connect to the 'newNode' in the list
        }
        prev = newNode; // Update 'prev' to point to last node in list, setting up for the next iteration
        curr = curr->next; // Advancing 'curr' pointer to the next node for copying
   }
}

// Destructor to deallocate each node from memory
OrderedList::~OrderedList(){
    Node * curr = head; // Initializing current pointer to point to head
    Node * nextNode = nullptr;

    cout << endl << "Deallocating..." << endl;

    // Traversing the linked list and preserving the link to the next node
    while (curr != nullptr){
        nextNode = curr->next; // Setting 'nextNode' to point to the same node as 'curr->next'
        cout << "Deleting " << curr->value << endl;
        delete curr; // Deleting current node
        curr = nextNode; // Current node set to nextNode in the list
    }
    head = nullptr;
    cout << endl;
}

// Function to accept integer input as the data for a new node
void OrderedList::insert(int num){
    Node * newNode = nullptr;
    Node * curr = nullptr;
    Node * prev = nullptr;

    // Allocate memory to create a new node and store integer 'num' there
    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;

    // If list is empty, head points to the newly added node
    if (!head){
        head = newNode;
    } else {
        curr = head;

        while (curr != nullptr && curr->value < num){
                prev = curr; // 'prev' pointer to point to same node as 'curr' pointer
                curr = curr->next; // To traverse 'curr' to the next node in the list
        }

        // Effectively inserting newNode while maintaining non-descending order
        if (prev == nullptr){
            newNode->next = head; // Set the next pointer of 'newNode' to point to current head of the list
            head = newNode; // Update head pointer to point to the new node
        } else {
            prev->next = newNode; // Set the next pointer of 'prev' to point to the 'newNode'
            newNode->next = curr; // Ensuring 'newNode' is either in between 'prev' and 'curr' nodes
        }
    }
}

// Function to print each of the nodes in the list
void OrderedList::printList(){
    Node * curr = nullptr;
    curr = head;

    while (curr != nullptr){

        cout << curr->value << " ";

        curr = curr->next; // Advance current pointer to point to the next node
    }
    cout << endl;
}