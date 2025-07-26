//swap using references
#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int main(){
    int a= 10, b=20;
    cout<<"a and b before swapping:"<<a<<","<<b<<endl;
    swap(a,b);
    cout<<"a and b after swapping:"<<a<<","<<b<<endl;
    return 0;
}