// Saxton Van Dalsen
// lab4.cpp
// Purpose: Implementing a class 'Car' across multiple files and running a driver program to display the 
// capabilities of the class 'Car'

#include <iostream>
#include "Car-lab4.h"
using namespace std;

int main(){

    // Creating new 'Car' object
    Car myCar(2012, "Volkswagen");

    // Calling accelerating function and getting each current speed
    for(int i = 0; i < 5; i++){
        myCar.accelerate();
        cout << "Current speed after accelerating the " << myCar.getYearModel() << " " << myCar.getMake() 
        << " is " << myCar.getSpeed() << endl;
    }
    cout << endl;

    // Calling brake function and getting each current speed
    for (int i = 0; i < 5; i++){
        myCar.brake();
        cout << "Current speed after braking the " << myCar.getYearModel() << " " << myCar.getMake() 
        << " is " << myCar.getSpeed() << endl;
    }
    
    return 0;
}