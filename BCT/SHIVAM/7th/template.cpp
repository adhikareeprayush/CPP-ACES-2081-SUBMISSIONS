/*
 * Program: Function Template for Finding Maximum
 * Description: Demonstrates the use of function templates to create a generic
 *              Max function that can work with different data types
 *              (int, float, double, etc.)
s * Date: July 5, 2025
 */
#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b)
{
  T max = a > b ? a : b;
  return max;
}

int main()
{
  int a = 10, b = 20;
  cout << " Max from : " << a << " , " << b << " is: " << Max<int>(a, b) << endl;

  float c = 10.32, d = 6.67;
  cout << " Max from : " << c << " , " << d << " is  : " << Max<float>(c, d) << endl;
  return 0;
}
