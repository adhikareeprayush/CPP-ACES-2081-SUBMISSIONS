// c++ program to calculaTe the n to the power of x
//use x=2 by default
#include <iostream>
#include <math.h>
using namespace std;
double power(double base, int exponent = 2) //here exponent=2 is the default argument 
                                            // default argument ma ki ta sabai default huna paryo or default wala lai right ma rakhna paryo
{
    return pow(base, exponent);
}
int main(){
    cout << power(5,3) << endl; // 5^3 = 125
    cout << power(5) << endl;   // 5^2 = 25 2 is the default exponent
    return 0;
}