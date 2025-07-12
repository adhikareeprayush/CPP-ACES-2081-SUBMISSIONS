// C++ Program to calculate area of circle, sphere and rectangle and triangle.
#include <iostream>
#include <cmath>
using namespace std;
double cArea(double r)
{
  return 3.14 * r * r;
}
double sArea(double r)
{
  return 4 * 3.14 * r * r;
}
double rArea(int l, int b)
{
  return l * b;
}
double tArea(int a, int b, int c, int s)
{
  s = a + b + c;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
  double RC, RS, RR, RT;

  cout << "Enter Radius of circle: ";
  cin >> RC;
  cout << "Enter Radius of square: ";
  cin >> RS;
  cout << "Enter Radius of rectangle: ";
  cin >> RR;
  cout << "Enter Radius of triangle: ";
  cin >> RT;

  double circleArea = cArea(RC);
  cout << "Area is : " << circleArea << endl;

  double sphereArea = sArea(RS);
  cout << "Area is : " << sphereArea << endl;

  double rectangleArea = rArea(RR);
  cout << "Area is : " << rectangleArea << endl;

  double triangleArea = tArea(RT);
  cout << "Area is : " << triangleArea << endl;

  return 0;
}
