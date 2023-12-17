#include "Dog.h"
#include <iostream>

using namespace std;

class Dog : public Animal {
public:
    Dog(){}
    void bark()
    {
        cout << "woof woof" << endl;
    }
};