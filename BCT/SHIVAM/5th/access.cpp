#include <iostream>
class Bird
{
public:
  std::string name;
  void speak()
  {
    std::cout << "Speak" << std::endl;
  }
  Bird(const std::string &name) : name(name) {};
  ~Bird()
  {
    cout << "Base class Destructor called." << endl;
  }
};
class Duck : public Bird
{
public:
  int wings;

public:
  // Constructor  of derived class
  Duck(std::string name, int wings) : Bird(name), wings(wings) {};
  void displayDuck()
  {
    std::cout << "Name: " << name << ",  Wings: " << wings << std::endl;
  }
  // Destructor of derived class
  ~Duck()
  {
    std::cout << "Derived class Destructor called from the class Duck." << std::endl;
  }
};
int main()
{
  Duck duck1("DuckTheDuck", 6);
  duck1.displayDuck();
  return 0;
}