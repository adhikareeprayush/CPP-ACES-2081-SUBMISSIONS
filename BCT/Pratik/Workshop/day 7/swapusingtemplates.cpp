#include<iostream>
using namespace std;

template <typename T>

void Swap(T &a,T &b){
    T temp;
    temp=a;
    a=b;
    b=temp;
}

int main(){
    int a= 10, b=20;
    cout<<"a and b before swapping:"<<a<<","<<b<<endl;
    Swap(a, b);
    cout<<"a and b after swapping:"<<a<<","<<b<<endl;

    double c=2.98, d=3.98;
    cout<<"c and d before swapping:"<<c<<","<<d<<endl;
    Swap(c, d);
    cout<<"c and d after swapping:"<<c<<","<<d<<endl;

    char m= 'A',n='B';
    cout<<"m and n before swapping:"<<m<<","<<n<<endl;
    Swap(m, n);
    cout<<"m and n after swapping:"<<m<<","<<n<<endl;

    return 0;
}