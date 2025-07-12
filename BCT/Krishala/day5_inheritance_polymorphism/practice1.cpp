#include <iostream>
using namespace std;

class Vehicle{
    public:
        virtual void start() {
            cout << "Vehicle Started" << endl;
        }
};

class Car : public Vehicle {
    public:
        void start() override {
            cout << "Car Started" << endl;
        }
};

class Bike : public Vehicle {
    public:
        void start() override {
            cout << "Bike Started" << endl;
        }
};

int main() {
    Bike bike1;
    bike1.start();
    return 0;
}
