#include<iostream>
using namespace std;

template<typename T>
T mymax(T a, T b){
    T max= a>b?a:b;
    return max;
}

int main(){
    int a= 10, b=20;
    cout<<"max from:"<<a<<", "<<b<<" is "<<mymax(a,b)<<endl;
    float c=10.98, d= 10.99;
    cout<<"max from:"<<c<<", "<<d<<" is "<<mymax(c,d)<<endl;
    return 0;
}
