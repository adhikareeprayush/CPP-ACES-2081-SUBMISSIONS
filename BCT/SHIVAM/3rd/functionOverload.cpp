#include <iostream>
using namespace std;
int multiply(int a, int b)
{
  cout << "int Function is called.\n";
  return a * b;
}
double multiply(double a, double b)
{
  cout << "double Function is called.\n";
  return a * b;
}
int main()

{
  // int a,b
  double a, b;
  cout << "Enter the Numbers: ";
  cin >> a >> b;

  cout
      << "The answer is : " << multiply(a, b) << endl;
  return 0;
}