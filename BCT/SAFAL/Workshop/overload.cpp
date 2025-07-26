#include <iostream>

class Complex
{
    double real, image;

    public:
        Complex():real(0), image(0){}
        Complex(double real, double image):real(real), image(image){}

        Complex operator +(Complex complex)
        {
            Complex result;
            result.real = real + complex.real;
            result.image = image + complex.image;
            return result;
        }

        Complex operator -(Complex complex)
        {
            Complex result;
            result.real = real - complex.real;
            result.image = image - complex.image;
            return result;
        }
        Complex operator *(Complex complex)
        {
            Complex result;
            result.real = real * complex.real - image * complex.image;
            result.image = real * complex.image + image * complex.real;
            return result;
        }

        friend std::ostream& operator<<(std::ostream& out, Complex complex)
        {
            std::cout << complex.real << " + " <<complex.image << "i "<< std::endl;
            return out;
        }
};

int main()
{
    Complex c1(10, 11);
    Complex c2(12, 13);
    std::cout << c1;
    std::cout << c2;
    Complex c3 = c1 + c2;
    std::cout << c3;
    Complex c4 = c1 - c2;
    std::cout << c4;
    Complex c5 = c1 * c2;
    std::cout << c5;
}