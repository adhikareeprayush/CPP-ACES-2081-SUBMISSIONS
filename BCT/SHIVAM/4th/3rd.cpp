// WAP to handle a class person with constructor and destructor
#include <iostream>
using namespace std;
class Person
{
private:
  string name;
  int age;
  string gender;

public:
  // constructor
  // Person(string Name, int Age, string Gender)
  // {
  //   name = Name;
  //   age = Age;
  //   gender = Gender;
  // }
  // Initializer list
  Person(string name, int age, string gender) : name(name), age(age), gender(gender) {};
  Person() : name("Unknown"), age(0) {};
  ~Person() { cout << "Destructor Called" << endl; }
  void show()
  {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
  }
  // // Destructor
  // ~Person()
  // {
  //   cout << "Destructor called ... !!!" << endl;
  // }
};
int main()
{
  Person p1("Shivam", 19, "Male");
  p1.show();
  return 0;
}