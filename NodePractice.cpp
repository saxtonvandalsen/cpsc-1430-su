#include <iostream>
#include "FancyList.h"
using namespace std;

void displayList();

int main (){

    FancyList newList;

    int choice;
    do {
        displayList();
        cout << "Choose between the options" << endl;
        cin >> choice;

    } while (choice != 6);

    return 0;
}

void displayList(){
    cout << "     Options     " << endl;
    cout << "1. Create a list through appending" << endl;
    cout << "2. Display the list" << endl;
    cout << "3. Reverse the list" << endl;
    cout << "4. Insert a new number in the list" << endl;
    cout << "5. Delete the nth node from the end of the list" << endl;
    cout << "6. Quit the program" << endl;

}