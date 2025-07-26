#include <iostream>
#include <cmath>
#include <cctype>

float area_circle(float rad)
{
    return 3.14 * rad * rad;
}
float area_sphere(float rad)
{
    return 4 * 3.14 * rad * rad;
}
float area_rect(float l, float b)
{
    return l * b;
}
float area_tri(float a, float b, float c)
{
    float s = (a + b+ c)/2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

int main()
{
    char ch;
    float area;
    std::cout << "Enter 'c', 's', 'r', 't' for circle, sphere, rectangle and triangle respetively: ";
    std::cin >> ch;
    ch = tolower(ch);
    switch(ch)
    {
        case 'c':
        float rad;
        std::cout << "Enter radius of circle: ";
        std::cin >> rad;
        area = area_circle(rad);
        std::cout << "Area of the circle is: " << area << std::endl;
        break ;

        case 's':
        std::cout << "Enter radius of sphere: ";
        std::cin >> rad;
        area = area_sphere(rad);
        std::cout << "Area of the sphere is: " << area << std::endl;
        break ;

        case 'r':
        float l, b;
        std::cout << "Enter length & breadth of rectangle: ";
        std::cin >> l >> b;
        area = area_rect(l, b);
        std::cout << "Area of the rectangle is: " << area << std::endl;
        break ;

        case 't':
        float a, c;
        std::cout << "Enter sides of triangle: ";
        std::cin >> a >> b >> c ;
        area = area_tri(a, b, c);
        std::cout << "Area of the triangle is: " << area << std::endl;
        break ;

        default:
        std::cout << "Invalid input" ;
        break;
    }
    return 0;
}