#include <iostream>
using namespace std;

class Person{
    string name;
    int age;

    public: 
        Person(string name, int age) : name(name), age(age) {}
        Person(): name("Unknown"),age(0) {}
        ~Person(){ cout << "Destructor called" << endl; }
};

int main() {
    Person person1("Ram", 20);
    return 0;
}