// Saxton Van Dalsen
// hw3.cpp
// Purpose: Displaying the user with a menu of options to choose from until they choose to quit. After the user creates
// a new list they will be able to perform multiple functions on it several times including reversing the list and deleting
// an nth node from the end of the list through user input. The user will be able to print the list however many times they
// choose. After exiting the program they will be able to see the deallocation of each node in the list.
#include <iostream>
#include "FancyList.h"
using namespace std;

void displayMenu();
void appendingInsertion(FancyList &appendList);

int main() {

// Creating a new list object
FancyList newList;

int choice;
// Displaying the menu with options for the user until they choose to quit
do{
    displayMenu();
    cout << endl << "Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            appendingInsertion(newList);
            break;
        case 2:
            cout << "Current list is: ";
            newList.displayList();
            break;
        case 3:
            cout << "Current list after reversing is: ";
            newList.reverseList();
            newList.displayList();
            break;
        case 4:
            int nthInput;
            cout << "Delete the n-th node from the end of the list, your n is: ";
            cin >> nthInput;
            newList.deleteNthNode(nthInput);
            cout << "Current list after deleting the " << nthInput << "-th node from the end is: ";
            newList.displayList();
            break;
        case 5:
            break;
        default:
            break;
    }
} while (choice != 5);

return 0;
}

// Function to display a menu of options for the user
void displayMenu(){
    cout << "********* FancyList Menu *********" << endl;
    cout << "1. Create a list" << endl;
    cout << "2. Display the list" << endl;
    cout << "3. Reverse the list" << endl;
    cout << "4. Delete the n-th node from the end of the list" << endl;
    cout << "5. Exit the program" << endl;
}

// Function to ask for user input for appending a new linked list
void appendingInsertion(FancyList& appendList){

    int inputNum;
    while (true){
        cout << "Type a number for appending (type x to stop): ";
        cin >> inputNum;
        // Checking if input failed to avoid infinite loop
        if(cin.fail()){
            
            // Clearing previous input
            cin.clear();
            string newInput;
            cin >> newInput;

            if (newInput == "x"){
            break;
            }
        } else {
            // Inserting user input into the current linked list
            appendList.appendListNode(inputNum);
        }
    }
    cout << endl;
}