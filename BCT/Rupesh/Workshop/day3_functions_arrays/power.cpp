// C++ Program to calculate the n to the power of x.
// Use x = 2 by default.

#include <iostream>
#include <math.h>
using namespace std;

double power(double base, int exponent = 2){
    return pow(base, exponent);
}

int main() {
    cout << "5 ^ 3 = " << power(5, 3) << endl;
    cout << "5 ^ 3 = " << power(5);
    return 0;
}

