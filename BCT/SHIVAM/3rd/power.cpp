// C++ program to calculate n to the power of x.
// Use x=2 by default.
#include <iostream>
#include <cmath>
using namespace std;
double power(double base, int exponent = 2)
{
  return pow(base, exponent);
}
int main()
{
  double base;
  int exponent;
  cout << "Enter base : ";
  cin >> base;
  cout << "Enter exponent: ";
  cin >> exponent;
  cout << "The answer is = " << power(base, exponent) << endl;
  return 0;
}