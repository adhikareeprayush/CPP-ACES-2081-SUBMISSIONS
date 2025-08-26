//A destructor is a special member function called automatically when an object goes out of scope or is explicitly deleted.
//It has the same name as the class, prefixed with a tilde (~), and no parameters or return type.
#include <iostream>
using namespace std;

class Test {
public:
    Test() {
        cout << "Constructor called!" << endl;
    }

    ~Test() {
        cout << "Destructor called!" << endl;
    }
};

int main() {
    Test t1; // Constructor called
    // When t1 goes out of scope, destructor is called
    return 0;
}