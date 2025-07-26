#include<iostream>
using namespace std;
 template <typename T>
 class Complex{
    T real, imag;
    public: 
        Complex(T real, T imag): real(real), imag(imag){}
        void display(){
            cout<< real <<"+i"<<imag <<endl;
        }
 };
 int main(){
    Complex<int> c1(2,32);
    c1.display();
    Complex<float> c2(2.22,4.90);
    c2.display();
    return 0;
 }