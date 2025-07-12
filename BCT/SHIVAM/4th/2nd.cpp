// Program to keep track of how many objects created using static member
#include <iostream>
using namespace std;

class Department
{
  int id;
  string name;
  int objNo;
  static int count;

public:
  Department(int i, string n)
  {
    id = i;
    name = n;
    objNo = ++count;
    cout << "This is the " << objNo << "  Object" << endl;
  }

  ~Department()
  {
    cout << "Object " << objNo << " goes out of the scope\n";
  }
};

int Department::count = 0;

int main()
{
  Department d1(101, "Computers");
  Department d2(102, "Mechanical");

  return 0;
}
