//Create an abstract class Shape with a pure virtual function area and derive Circle and Rectangle classes to implement it.

#include<iostream>
using namespace std;
class Shape{    //shape-abstract class because it contains pure virtual function
    public:
    virtual void area()=0;
};
class Circle : public Shape{
    double radius;
    public:
        Circle(double radius): radius(radius) {}
            void area() override{
                cout<<"area of circle:"<<3.14*radius*radius<<endl;
            }
        };
class Rect : public Shape{
   double length, breadth;
   public:
   Rect(double length,double breadth): length(length),breadth(breadth){}
    void area() override{
        cout<<"area of rectangle:"<<length*breadth<<endl;
    }
   };
int main()
{
    return 0;
}