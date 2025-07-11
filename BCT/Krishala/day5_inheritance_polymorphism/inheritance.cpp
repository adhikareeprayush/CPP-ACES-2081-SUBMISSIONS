#include <iostream>
using namespace std;

class Bird{ // Base class
    string name;
    public:
        virtual void speak() {
            cout << "Chirp" << endl;
        }
};

class Duck : public Bird { // Derived Class
    int wings;
    public:
        void speak() override{
            cout << "Quack" << endl;
        }
};

int main() {
    Bird bird1;
    bird1.speak();

    Duck duck1;
    duck1.speak();

    return 0;
}
