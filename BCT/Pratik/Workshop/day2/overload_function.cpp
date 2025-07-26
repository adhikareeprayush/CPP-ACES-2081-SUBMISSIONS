#include<iostream>
using namespace std;
int multiply(int a, int b){
    return a*b;
}
double multiply(double a, double b){
    return a*b;
}
int main(){
    cout<<"3*2=" << multiply(3, 2) << endl;
    cout<<"3.5*2.5=" << multiply(3.5,2.5) << endl;
    return 0;
}

// double ra int huda double is executed according to overloading of function