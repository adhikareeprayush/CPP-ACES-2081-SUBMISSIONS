#include <iostream>
using namespace std;

class Complex{
    double real, imag;
    public:
        // Constructor
        Complex(double real, double imag) : real(real), imag(imag) {}
        void display() {
            cout << "x + iy = " << real << " + " << "i" << imag << endl;
        }
        Complex operator +(const Complex& obj) {
            return {obj.real + this->real, obj.imag + this->imag};
        }

        Complex operator *(const Complex& obj) {
            // Use formula

            // return {};
        }
};

int main () {
    Complex c1(4,2);
    Complex c2(6,8);
    Complex c3 = c1 + c2;
    // c3 = c1.operaor+(c2)
    c3.display();
    return 0;
}