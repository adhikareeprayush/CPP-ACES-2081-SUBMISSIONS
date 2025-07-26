#include<iostream>
using namespace std;

int main(){
    int a, b;
    try{   //error aauna sakne block lai try block ma halne
        cout<<"Enter a and b:"<<endl;
        cin>>a >>b;
        
        if (b==0){
            throw(0);
        }
    }catch(int e){
        if(e==0){
            cout<<"Divide by 0 detected. Please try again.";
            return 1;
        }
    }
    return 0;
}