#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    friend Complex add(Complex& a, Complex& b);
    void display(){
        cout << real << "+ i" << imag << endl;
    }
};

Complex add(Complex& a, Complex& b) {
    Complex temp(a.real + b.real, a.imag + b.imag);
    return temp;
}

int main() {
    Complex c1(3.4,2.1);
    Complex c2(3.4,2.1);

    Complex c3 = add(c1,c2);
    c3.display();
    // Complex c3 = c1 + c2;
    // Complex c3 = c1.add(c2);
    return 0;
}