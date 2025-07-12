#include <iostream>
using namespace std;

class Shapes
{
public:
  virtual double area() = 0; // pure virtual function
  virtual ~Shapes() {}       // virtual destructor for safe polymorphic deletion
};

class Circle : public Shapes
{
private:
  double radius;

public:
  // Constructor
  Circle(double r) : radius(r) {}
  double area() override
  {
    return 3.1415 * radius * radius;
  }
};

class Rectangle : public Shapes
{
private:
  double length, breadth;

public:
  Rectangle(double l, double b) : length(l), breadth(b) {}
  double area() override
  {
    return length * breadth;
  }
};

int main()
{
  Shapes *c1 = new Circle(5);
  Shapes *r1 = new Rectangle(6, 7);

  cout << "Circle area: " << c1->area() << endl;
  cout << "Rectangle area: " << r1->area() << endl;

  delete c1;
  delete r1;
  return 0;
}
