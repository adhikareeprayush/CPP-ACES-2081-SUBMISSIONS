#include <iostream>
using namespace std;
class Vehicle
{
public:
  virtual void start() = 0;
};

class Car : public Vehicle
{
public:
  void start() override
  {
    cout << "THe car is starting...." << endl;
  }
};
class Bike : public Vehicle
{
public:
  void start() override
  {
    cout << "Bike is starting..." << endl;
  }
};
int main()
{

  Bike *b = new Bike; // Allocate memory and create Bike object
  Car *c = new Car;

  b->start();
  c->start();

  delete b;
  delete c;
  return 0;
}