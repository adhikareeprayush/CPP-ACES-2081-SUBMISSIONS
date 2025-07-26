//square of the number
#include <iostream>
using namespace std;
double square(double num) {
    return num * num;
}
double cube(double num){
    return num*num*num;
}
int main(){
    double num;
    cout<<"enter the number:";
    cin>>num;
    cout<<" the square of the number is:" << square(num) << endl;
    cout<<"the cube of the number is:" << cube(num) << endl;
    return 0;
}