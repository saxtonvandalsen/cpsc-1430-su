#include <string>
using namespace std;
#ifndef CAR_H
#define CAR_H

// Declaring class 'Car' in header file
class Car {

    public:
        Car(int yearModel, const string& make);
        int getYearModel() const;
        const string& getMake() const;
        int getSpeed() const;
        void accelerate();
        void brake();

    private:
        int yearModel;
        string make;
        int speed;
};

#endif