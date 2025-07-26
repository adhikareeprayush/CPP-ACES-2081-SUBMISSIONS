#include <iostream>
using namespace std;
class Person {
public:
    virtual void display() = 0;
};

class Teacher : public Person {
public:
    void display() override { // Override base class function
        cout << "I am a Teacher" << endl;
    }
};

int main() {
    Person* p;
    Teacher t;
    p = &t; // Base class pointer pointing to derived class object
    p->display(); // Output: I am a Teacher (due to virtual function)
    return 0;
}