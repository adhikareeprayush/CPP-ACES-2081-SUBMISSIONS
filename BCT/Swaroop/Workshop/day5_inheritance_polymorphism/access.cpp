#include <iostream>
using namespace std;

class Bird{ // Base class
    protected:
        string name;
    public:
        Bird(string name) : name(name) {}
        void speak() {
            cout << "Chirp" << endl;
        }
};

class Duck : public Bird { // Derived Class
    int wings;
    public:
        Duck(string name, int wings) : Bird(name), wings(wings) {}
        void speak() {
            cout << "Quack" << endl;
        }
        void displayDuck() {
            cout << "Name: " << name << " Wings: " << wings << endl;
        }
};


int main() {
    Duck duck1("Duck123", 2);
    duck1.displayDuck();
    return 0;
}