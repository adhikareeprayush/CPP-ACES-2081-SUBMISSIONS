// C++ Program to calculate area of Circle, Sphere, Rectangle and Triangle using
// Functions

#include <iostream>
#define PI 3.14
using namespace std;

double calculateArea(int shape) {
    float area;
    if(shape == 1) {
        double radius;
        cout << "Enter the radius : ";
        cin >> radius;
        area = PI * radius * radius;
    }
    return area;
}


int main() {
    int choice;
    cout << "1. Circle\n2. Sphere\n3. Rectangle\n4. Triangle" << endl;
    cout << "Enter The Shape Number : " << endl;

    switch(choice) {
        case 1:
            // circle PI * r * r

            break;
        case 2: 
            // sphere
            break;
        case 3:
            // Rectangle
            break;
        case 4:
            // triangle 
            break;
        default: 
            cout << "Invalid choice" << endl;
    }

    return 0;
}
