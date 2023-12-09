#include <iostream>
#include "IntegerSet.h"
using namespace std;

// Empty-set constructor initializing an array to all zeros
IntegerSet::IntegerSet(){

    for(int i = 0; i <= 100; i++){
        setArray[i] = 0;    
    }
}

// Constructor that takes in an array and the size of the array to initialize a set object
IntegerSet::IntegerSet(const int arr[], int size){

    // Initially setting the set object as an empty set
    for (int i = 0; i < size; i++){
        setArray[i] = 0;
    }

    // Initializing set object by the given arguments within array size of 0 to 100
    for (int i = 0; i < size; i++){
        if (arr[i] >= 0 && arr[i] <= 100){
            setArray[arr[i]] = 1;
        }
    }
}

// Creating a third set that is set-theoretic union of two given sets passed as arguments
void IntegerSet::unionOfSets(const IntegerSet& setA, const IntegerSet& setB){

    // Evaluating the elements from the existing arrays 
    for (int i = 0; i <= 100; i++){
        // Checking if an element of either or both sets is 1
        if (setA.setArray[i] == 1 || setB.setArray[i] == 1){
            setArray[i] = 1;
        } else {
            setArray[i] = 0; // Set to 0 if the element is 0 in each of the sets
        }
    }
}

// Creating a third set that is set-theoretic intersections of two given sets passed as arguments
void IntegerSet::intersectionOfSets(const IntegerSet& setA, const IntegerSet& setB){

    bool checkInt;
    cout << "{";
    for (int i = 0; i <= 100; i++){
        // Checking if arrays have a 1 at index i for intersection of their current elements
        if (setA.setArray[i] == 1 && setB.setArray[i] == 1){
            setArray[i] = 1; 
            if (checkInt){ // If there is an intersection from both arrays print out the element
                cout << " " << i;
            }
        } else {
            setArray[i] = 0;
        }
    }
    cout << (checkInt ? " }" : "- }") << endl << endl;
}

// Function to insert a new integer into a set
void IntegerSet::insertElement(int k){

    if(k >=0 && k <= 100){
        setArray[k] = 1;
    }
}

// Function to delete an integer from a set
void IntegerSet::deleteElement(int m){

    if(m >= 0 && m <= 100){
        setArray[m] = 0;
    }
}

// Function that prints a set as a list for only elements that are present in the set
void IntegerSet::printSet(){

    cout << "{";
    bool checkInt = false;
    // Evaluating if an element in the array has a value of 1
    for (int i = 0; i <= 100; i++){
        if(setArray[i] == 1){
            if(!checkInt){
                cout << " " << i; // Print out value if the position 'i' has a value of 1
            }
            checkInt = false;
        }
    }
    cout << (checkInt ? "- }" : " }") << endl << endl;
}

// Function that evaluates two functions passed in if they're equal
void IntegerSet::isEqualTo(const IntegerSet& setA, const IntegerSet& setB){

    bool equalTo = true;
    for (int i = 0; i <= 100; i++){
        // Evaluating each element in both sets to verify if they have equal integers
        if (setA.setArray[i] != setB.setArray[i]){
            equalTo = false;
            break;
        }
    }
    if (!equalTo){
        cout << "Set A is not equal to set B" << endl;
    }
    else {
        cout << "Set A is equal to set B" << endl;
    }
}

// Function that sets all elements of the set to 0
void IntegerSet::emptySet(){
    for(int i = 0; i <= 100; i++){
        setArray[i] = 0;
    }
}

// Function that reads values from user input into the set
void IntegerSet::inputSet(){
    
    int inputValue;
    cout << "Enter an element (Type x to stop): ";
    while (true){
        cin >> inputValue;
        // Checking if input value failed
        if (cin.fail()){

            // Clearing previous input for new user input
            cin.clear();
            string newInput;
            cin >> newInput;

            // If entered "x" break from the loop
            if (newInput == "x"){
                break;
            }
        }
        else if (inputValue < 0 || inputValue > 100){
            cout << "Error input value out of 0 to 100 range" << endl;
        }
        else{
            setArray[inputValue] = 1; // Setting element in the set to '1' if its a valid input
            cout << "Enter an element (Type x to stop): ";
        }
    }
    cout << "Entry complete" << endl << endl;
}

// Function to determine if an input was a valid entry into the set
bool IntegerSet::validEntry(int entry){
    if (entry >= 0 && entry <= 100){
        cout << "Valid insert of " << entry << " attempted!" << endl;
        return true;
    } else {
        cout << "Invalid insert of " << entry << " attempted!" << endl;
        return false;
    }
}