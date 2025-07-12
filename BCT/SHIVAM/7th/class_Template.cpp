/*
 * Program: Class Template for Complex Numbers
 * Description: Demonstrates the use of class templates to create a generic
 *              Complex number class that can work with different data types
 *              (int, float, double, etc.)
 * Date: July 5, 2025
 */

#include <iostream>
using namespace std;

template <typename T>
class Complex
{
private:
  T real, img;

public:
  Complex(T real, T img) : real(real), img(img) {}
  void display()
  {
    cout << real << " + i " << img << endl;
  }
};
int main()
{
  Complex<int> c1(6, 7);
  c1.display();
  Complex<float> c2(6.67, 7.76);
  c2.display();
  return 0;
}