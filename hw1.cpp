// Saxton Van Dalsen
// hw1.cpp
// Purpose: This program 
// Input: 
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>
using namespace std;

// Struct to hold each variable for the data given
struct CovidInfo {

    string stateName;
    int cases;
    int deaths;
};

// 
CovidInfo* covidData(const string& fileName, int& numStates){

    ifstream inputFile(fileName);

    // Checking user's input for the file
    if (!inputFile) {
        cout << "Error couldn't open file!" << endl;
        return nullptr;
    }

    // To count the number of lines in the file
    numStates = 0;
    string line;
    while (getline(inputFile, line, ',')) {
        numStates++;
    }

    cout << numStates;

    // Dynamically allocating memory for an array of objects
    CovidInfo* arrayData = new CovidInfo[numStates];

    for (int i = 0; i < numStates; i++){
        getline(inputFile, arrayData[i].stateName, ',');
        inputFile >> arrayData[i].cases;
        inputFile.ignore(); // Ignore the comma
        inputFile >> arrayData[i].deaths;
    }

    inputFile.close();
    return arrayData;
}

void displayMenu();
void displayStates(const CovidInfo* arrayData, int numStates);


int main(){

    // Requesting user input of file name
    string fileName;
    cout << "Please enter the input file name: ";
    cin >> fileName;

    int numStates;
    CovidInfo* arrayData = covidData(fileName, numStates);

    if (arrayData == nullptr){
        cout << "Error couldn't open file!" << endl;
        return 1;
    }

    int choice;

    // Displays menu of options to choose from until user quits
    do {
        displayMenu();
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice){
            case 1: 
                displayStates(arrayData, numStates);
                break;
            case 2:
                cout << "2\n";
                break;
            case 3:
                cout << "3\n";
                break;
            case 4:
                cout << "4\n";
                break;
            case 5:
                cout << "5\n";
                break;
            default:
                break;
        }
    }
    while (choice != 5);

    // Delete allocated memory from array
    delete[] arrayData;

    return 0;
}

// Function to display menu of options for user input
void displayMenu(){
    cout << "************Menu************" << endl;
    cout << "1.  Display the COVID info all states" << endl;
    cout << "2.  Display the COVID info of the state has the most cases" << endl;
    cout << "3.  Display the COVID info of the state has the most deaths" << endl;
    cout << "4.  Display the statistics of all states" << endl;
    cout << "5.  Exit the program" << endl;
}

void displayStates(const CovidInfo* arrayData, int numStates){

    cout << numStates;

    for (int i = 0; i < numStates; i++){
        cout << "State: " << arrayData[i].stateName << endl;
    }
}

void covidStatistics(const CovidInfo* arrayData, int numStates){

    for (int i = 0; i < numStates; i++){
    int totalCases = 0;
    totalCases += arrayData[i].cases;
    int avgCases = totalCases / arrayData[i].cases;
    cout << "(a) There are " << totalCases << " cases in total, " << avgCases << " on average" << endl;
    }

    for (int i = 0; i < numStates; i++){
    int totalDeaths = 0;
    totalDeaths += arrayData[i].deaths;
    int avgDeaths = totalDeaths / arrayData[i].deaths;
    cout << "(b) There are " << totalDeaths << " deaths in total, " << avgDeaths << " on average" << endl;

    }


}