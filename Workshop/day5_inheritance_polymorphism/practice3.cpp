#include <iostream>
using namespace std;

class Shape{
    public:
        virtual void area() = 0; // Pure virtual function
};

class Circle : public Shape {
    double radius;
    public:
        Circle(double radius) : radius(radius) {}
        void area() override {
            cout << "Area of circle : " << 3.14 * radius * radius << endl;
        }
};

class Rectangle : public Shape {
    double length, breadth;
    public:
        Rectangle(double length, double breadth) : length(length),breadth(breadth) {}
        void area() override {
            cout << "Area of Rectangle : " << length * breadth;
        }
};