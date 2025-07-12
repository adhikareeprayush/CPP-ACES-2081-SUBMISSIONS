// Friend Function
#include <iostream>
using namespace std;
class Complex
{
private:
  double real, img;

public:
  Complex(double r = 0, double i = 0) : real(r), img(i) {}

  friend Complex add(Complex &a, Complex &b);

  void display()
  {
    cout << real << " + " << img << " i" << endl;
  }
};

Complex add(Complex &a, Complex &b)
{
  Complex temp(a.real + b.real, a.img + b.img);
  return temp;
}

int main()
{
  Complex c1(4, 2);
  Complex c2(6, 7);

  Complex c3 = add(c1, c2);

  c3.display();

  // Complex c3 = c1 + c2;
  // Complex c3 = c1.add(c2);
  return 0;
}