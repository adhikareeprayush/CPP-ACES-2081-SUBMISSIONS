// Calculate Square of a number;
#include <iostream>
using namespace std;
double cube(int n)
{
  return n * n * n;
}
double square(int n)
{
  return n * n;
}
int main()
{
  int n;
  cout << "Enter the Number: ";
  cin >> n;

  cout << "Square of the number is " << " = " << square(n) << endl;
  cout << "Cube of the number is " << " = " << cube(n) << endl;
  return 0;
}