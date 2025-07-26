//A constructor is a special member function that is automatically called when an object is created. It has the same name as the class and no return type.
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int rollNo;

    // Default constructor
    Student() {
        name = "Unknown";
        rollNo = 0;
        cout << "Default constructor called!" << endl;
    }

    // Parameterized constructor
    Student(string n, int r) {
        name = n;
        rollNo = r;
        cout << "Parameterized constructor called!" << endl;
    }

    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }
};

int main() {
    Student s1; // Calls default constructor
    s1.display(); // Output: Name: Unknown, Roll No: 0

    Student s2("Alice", 101); // Calls parameterized constructor
    s2.display(); // Output: Name: Alice, Roll No: 101
    return 0;
}