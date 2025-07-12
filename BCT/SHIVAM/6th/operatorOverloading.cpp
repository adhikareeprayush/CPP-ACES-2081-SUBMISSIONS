// COmplex NUmber adding using operator overloading
#include <iostream>
class Complex
{
private:
  double real, img;

public:
  // Constructor
  Complex(double real, double img) : real(real), img(img) {}
  void display()
  {
    cout << "x + iy = " << real << "+" << "i" << img << endl;
  }
  Complex operator+(const Complex &obj)
  {
    return {obj.real + this->real, obj.img + this->img};
  }
  Complex operator*(const Complex &obj) //  (a+ib)*(c+id)
  {
    return {(obj.real + this->img) * (obj.real + this->img)};
  }
};
int main()
{
  Complex c1(6, 7);
  Complex c2(4, 3);
  Complex c3 = c1 + c2;
  // c3 = c1.operator+(c2)
  c3.display();
  return 0;
}
