//c++ program to calculate n to the power of x
//use x=2 by default
#include<iostream>
#include<math.h>
using namespace std;
double power(double base, int exponent=2)
{
return pow(base,exponent);
}
int main(){
    cout<<"5^3="<<power(5,3);
    cout<<"5^2="<<power(5);
return 0;
}