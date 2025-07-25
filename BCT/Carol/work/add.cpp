#include<iostream>
using namespace std;
class Complex{
    double real,img;
    public:
    //constructor
   Complex(double real, double img): real(real),img(img){}
   void display(){
    cout<<"x+iy="<<real<<"+"<<"i"<<img<<endl;

   }
   Complex operator+(const Complex&obj){
    return{obj.real+this->real,obj.img+this->img};
   }
};
int main(){
    Complex c1(4,2);
    Complex c2(5,2);
    Complex c3=c1 + c2;
    c3.display();
    return 0;


}