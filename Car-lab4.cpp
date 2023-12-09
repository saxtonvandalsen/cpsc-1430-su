 #include <iostream>
#include "Car-lab4.h"
using namespace std;

// 'Car' constructor that accepts two parameters and points to member variables
Car::Car(int yearModel, const string& make){
    this->yearModel = yearModel;
    this->make = make;
    this->speed = 0;
}

// Member function to get 'yearModel'
int Car::getYearModel() const{
    return this->yearModel;
}

// Member function to get 'make'
const string& Car::getMake() const{
    return this->make;
}

// Member function to get 'speed'
int Car::getSpeed() const{
    return this->speed;
}

// Member function to accelerate 'speed' by 5
void Car::accelerate(){
    this->speed = this->speed + 5;
}

// Member function to brake 'speed' by 5
void Car::brake(){
    this->speed = this->speed - 5;
}