// Inheritance concept.
#include <iostream>
class Bird
{
  std::string name;

public:
  void speak()
  {
    std::cout << "Chirp" << std::endl;
  }
};
class Duck : public Bird
{
};
int main()
{
  return 0;
}