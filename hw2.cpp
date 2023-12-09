// Saxton Van Dalsen
// hw2.cpp
// Purpose: To create objects that represent a set of integer in the range of 0 to 100,
// the program uses an internal array to track elements is they belong to the set marked as 1 or 0 if not.
#include <iostream>
#include "IntegerSet-hw2.h"
using namespace std;

int main (){

    // Taking user input for the elements of the first set
    cout << "Enter set A: " << endl;
    IntegerSet setA;
    setA.inputSet();

    // Taking user input for the elements of the second set
    cout << "Enter set B: " << endl;
    IntegerSet setB;
    setB.inputSet();

    // Evaluating the union of elements in the two user-inputted sets
    cout << "Union of A and B is:" << endl;
    IntegerSet unionSet;
    unionSet.unionOfSets(setA, setB);
    unionSet.printSet();

    // Evaluating the intersection of elements in the two user-inputted sets
    cout << "Intersection of A and B is: " << endl;
    IntegerSet intersectionSet;
    intersectionSet.intersectionOfSets(setA, setB);

    // Evaluating if the two user-inputted sets are equal to each other
    IntegerSet checkSets;
    checkSets.isEqualTo(setA, setB);

    // Taking user input for a new integer into the set
    int insertVal;
    cout << "What element would you like to insert into set A?:";
    cin >> insertVal;
    setA.insertElement(insertVal);
    cout << "Set A is now:" << endl;
    setA.printSet();

    // Testing deleting newly inserted integer
    cout << "Deleting " << insertVal << " from set A..." << endl;
    setA.deleteElement(insertVal);
    cout << "Set A is now:" << endl;
    setA.printSet();

    // Hardcoded array to test valid entrys with the bounds limits
    cout << "Now creating a set of specific values and testing the bounds limits." << endl;
    int testArray[10] = {25, 67, 2, 9, 99, 105, 45, -5, 100, 1};
    cout << "Creating array of size 10: {25, 67, 2, 9, 99, 105, 45, -5 , 100 , 1}" << endl;;
    IntegerSet setC(testArray, 10);
    setC.validEntry(105);
    setC.validEntry(-5);
    
    // Printing out Set C
    cout << endl << "Set C is:" << endl;
    setC.printSet();
    
    return 0;
}