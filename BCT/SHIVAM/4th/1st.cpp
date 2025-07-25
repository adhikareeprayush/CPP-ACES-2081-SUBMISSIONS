#include <iostream>
using namespace std;
class Car
{
  // Class Attributes or data Members
public:
  string model;
  string name;
  int capacity;
  string color;
  double speed;
  // Constructor --> Parameterized
  Car(string N, string M, int capacity, string color, double S)
  {
    name = N;
    model = M;
    this->capacity = capacity;
    this->color = color;
    speed = S;
  }
  // Class Methods or Member Functions
  void setCar(string N, string tempModel, int capacity, string color, double speed)
  {
    name = N;
    model = tempModel;
    // Using "this pointer" to differentiate
    this->capacity = capacity;
    this->color = color;
    this->speed = speed;
  }
  // Destructor
  ~Car()
  {
    cout << "!!!...Destructor Called ....." << endl;
  }

  void start()
  {
    cout << "....Vroom Vroommm.......!!!" << endl;
  }
  void details()
  {
    cout << "\n.........Here's your Baby'ss Specifications...........\n";
    cout << "--> Name of the car is : " << name << endl;
    cout << "--> Model : " << model << endl;
    cout << "--> Capacity of the car is  : " << capacity << endl;
    cout << "--> It's sexy color is : " << color << endl;
    cout << "--> Speed of the baby is : " << speed << endl;
    cout << "\n...............................................................\n";
  }
  void stop()
  {
    cout << "Stoppeddd.......!!!";
  }
  // As a standalone function outside the class:
  void deleteCar(Car *car)
  {
    delete car;
  }
};
int main()
{
  // object definition
  Car car1("Mustang GT", "Classic", 6767, "HOT RED", 670);

  car1.start();
  car1.details();

  return 0;
}