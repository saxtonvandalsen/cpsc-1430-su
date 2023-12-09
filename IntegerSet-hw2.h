#include <string>
using namespace std;
#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet {
    public:
        IntegerSet();
        IntegerSet(const int arr[], int size);
        void unionOfSets(const IntegerSet& setA, const IntegerSet& setB);
        void intersectionOfSets(const IntegerSet& setA, const IntegerSet& setB);
        void insertElement(int k);
        void deleteElement(int m);
        void printSet();
        void isEqualTo(const IntegerSet& setA, const IntegerSet& setB);
        void emptySet();
        void inputSet();
        bool validEntry(int entry);

    private:
        int setArray[101];
};

#endif