#include<iostream>
using namespace std;
double square(double num){
    return num*num;
}
double cube(double num){
    return num*num*num;
}
int main(){
    int num;
    cout<<"Enter a number";
    cin>>num;
    cout<<"Square of number is:"<<num;
    cout<<"cube of number is:"<<num;

}