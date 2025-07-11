#include<iostream>
using namespace std;
class Complex{
    double real,img;
    public:
    //constructor
   Complex(double r=0, double i=0): real(r),img(i){}
   friend Complex add(Complex &a,Complex &b);
   void display(){
    cout<<real<<"+i"<<img<<endl;
   }
    Complex temp( a.real+b.real,a.img+b.img);

};
int main(){
    Complex c1(3,4,2);
    Complex c2(6,5,2);
    Complex c3=add(c1,c2);
   
    return 0;


}