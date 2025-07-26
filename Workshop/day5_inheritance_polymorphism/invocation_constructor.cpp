#include <iostream>
using namespace std;

class Bird{ // Base class
    protected:
        string name;
    public:
        Bird(string name) : name(name) {
            cout << "Base Class Constructor Called" << endl;
        }
        ~Bird(){
            cout << "Base Class Destructor Called" << endl;
        }
        virtual void speak(){
            cout << "Chirp" << endl;
        } 
};

class Duck : public Bird { // Derived Class
    int wings;
    public:
        Duck(string name, int wings) : Bird(name), wings(wings) {
            cout << "Derived Class Constructor Called" << endl;
        }
        ~Duck(){
            cout << "Derived Class Destructor Called" << endl;
        }
        void speak() {
            cout << "Quack" << endl;
        }
        void displayDuck() {
            cout << "Name: " << name << " Wings: " << wings << endl;
        }
};


int main() {
    Duck duck1("Duck123", 2);
    return 0;
}