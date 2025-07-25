#include <iostream>
using namespace std;
int main()
{
  Teacher t;
  Person *p = &t;
  p->display();
  return 0;
}