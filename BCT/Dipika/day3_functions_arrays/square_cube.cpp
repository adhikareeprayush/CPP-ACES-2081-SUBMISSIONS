// Calulate square of a number
#include <iostream>
using namespace std;

double square(double num) {
    return num * num;
}

double cube(double num) {
    return num * num * num;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Square of " << num << "=" << square(num) << endl;
    cout << "Cube of " << num << "=" << cube(num) << endl;

    return 0;
}