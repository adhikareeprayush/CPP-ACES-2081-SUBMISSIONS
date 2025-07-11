#include <iostream>
using namespace std;


class Animal{
    string kingdom;
    public:
        void display(){
            cout << "Kingdom : " << kingdom << endl;
        }
};

class Mammal : public Animal{

};

class Dog : public Mammal{

};