#include<iostream>
using namespace std;
class Shape{
private:
string name;
public:
virtual void area()=0;
};
class Circle:public Shape{
    double radius;
    public:
    Circle(double radius):radius(radius){}
    void area() override{
        cout<<"area of circle : "<<3.14*radius*radius<<endl;
    }
};
class Rectangle:public Shape{
    double length;
    double breadth;
    public:
    Rectangle(double length,double breadth):length(length),breadth(breadth){}
    void area() override{
        cout<<"area of rectangle : "<<length*breadth;
    }
};