// Saxton Van Dalsen
// hw4.cpp
// Description: A program that completes two operations. The first operation uses 'stack' operations that handles a 
// mathematical expression given by the user and returns its value. The second operation processes a given .txt file 
// that is converted to an array. From there 'queue' operations are implemented to calculate the average of the numbers
// in a sliding window which slides from the beginning to the end of the array.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include "Queue.h"
#include "Stack.h"
using namespace std;

// Function prototypes
int evaluateExpression(const string& expression);
void calculateWindowAvg(ifstream& inputFile, int N);

int main (int argc, char *argv[]) {

    string expression;
    cout << "****Showcasing the first task****" << endl;

    // Continue to evaluate math expression until user
    // types '#'
    while (true) {
        cout << setw(41) << "Type the expression (type # to quit):";
        getline(cin, expression);
        
        if (expression == "#"){
            cout << endl;
            break;
        }

        int result = evaluateExpression(expression);
        cout << setw(36) << "The value of this expression is " << result << endl << endl;

    }

    // To access the second command-line argument after .txt file,
    // assigning integer 'windowSize' as the argument
    int windowSizeN = atoi(argv[2]);

    // Opening .txt file
    ifstream inputFile("task2_input.txt");
    
    cout << "****Showcasing the second task****" << endl;

    // To calculate a given sliding window average of an array
    // produced from an .txt file
    calculateWindowAvg(inputFile, windowSizeN);

    // Closing the file
    inputFile.close();

    return 0;
}

// Function to evaluate a mathematical expressin and return its result value
int evaluateExpression(const string& expression) {
    Stack intStack;
    int currentNumber = 0;
    char lastOperator = '+';

    // Iterate through the given expression
    for (char ch : expression) {
        if (isdigit(ch)) {
            // Process single or multi-digit character, subtracting by 
            // ASCII character value to get its integer value
            currentNumber = currentNumber * 10 + (ch - '0');
        } else if (ch == '+' || ch == '-') {
            // Process the previous number based on the last operator
            if (lastOperator == '+') {
                intStack.push(currentNumber);
            } else if (lastOperator == '-') {
                intStack.push(-currentNumber);
            }

            // Update the last operator to current operator
            lastOperator = ch;
            currentNumber = 0;
        }
    }

    // Process the last number in the expression
    if (lastOperator == '+') {
        intStack.push(currentNumber);
    } else if (lastOperator == '-') {
        intStack.push(-currentNumber);
    }

    // Evaluating the final result by popping each value off and
    // accumulating the result variable
    int result = 0;
    while (!intStack.isEmpty()) {
        result += intStack.pop();
    }

    return result;
}

// Function that processses a given .txt file and given window size 'N'
// that processes the .txt file into an array and returns the average of each sliding window
void calculateWindowAvg(ifstream& inputFile, int N) {
    Queue windowQueue;

    int num;
    int sum = 0;

    cout << setw(39) << "The average in each window of size " << N << " are " << "[ ";

    // Initialize the window size and handle array correctly
    for (int i = 0; i < N; ++i) {
        if (inputFile >> num) {
            windowQueue.enqueue(num);
            sum += num;
        } 
    }

    // Output the average of the first window
    cout << sum / N << " ";

    // Process the rest of the array until empty
    while (inputFile >> num) {
        // Dequeue the oldest element and enqueue the current element
        sum = sum - windowQueue.dequeue() + num;
        windowQueue.enqueue(num);

        // Output the average of the current window
        cout << sum / N << " ";
    }

    cout << "]" << endl;
}