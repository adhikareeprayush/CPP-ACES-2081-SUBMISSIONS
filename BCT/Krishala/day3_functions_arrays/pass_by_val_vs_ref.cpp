#include <iostream>
using namespace std;

// Pass by value
void increment(int n) {
    n = n + 1;
}

// Pass by reference
void incrementByReference(int& c) {
    c = ++c;
}

int main() {
    int a = 2;
    increment(a); // Pass By Value
    cout << "a after increment() => " << a << endl;
    incrementByReference(a); // Pass by reference
    cout << "a after incrementByReference() => " << a << endl;
    return 0;
}