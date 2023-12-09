// Saxton Van Dalsen
// lab6.cpp
// Purpose: This program takes user input to create linked lists that also creates deep copies of the nodes in those lists
// while displaying these lists in non-descending order and propering deallocating each of the nodes in the linked lists
#include <iostream>
#include <iomanip>
#include "OrderedList-lab6.h"
using namespace std;

void displayInsertion(OrderedList& list);

int main(){

// Creating a new list and getting user input for the data of the nodes
OrderedList listA;
cout << "Asking user to type and create listA..." << endl;
displayInsertion(listA);

cout << endl << "listA is:\t\t" << setw(5);
listA.printList();

// Making a deep copy of the nodes from 'listA' into a new linked list
OrderedList listB(listA);
cout << "listB is coping from listA: ";
listB.printList();

cout << endl << "Asking user to type and add more to listB..." << endl;
displayInsertion(listB);

cout << endl << "listA is now: ";
listA.printList();

cout << "listB is now: ";
listB.printList();

return 0;
}

// Function to ask user for input in creating a new linked list
void displayInsertion(OrderedList& list){

    int input;
    while (true){
        cout << "Type a number for insertion (type x to stop): ";
        cin >> input;
        // Checking if input value failed to avoid infinite loop
        if (cin.fail()){

            // Clearing previous input
            cin.clear();
            string newInput;
            cin >> newInput;

            if (newInput == "x"){
            break;
            }
        } else {
            list.insert(input); // Inserting user input value into the current linked list
        }
    }
}