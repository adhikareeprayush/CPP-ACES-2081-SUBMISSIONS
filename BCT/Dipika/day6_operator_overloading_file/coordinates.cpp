#include <iostream>
using namespace std;

class Point{
    double x, y;
    public: 
        Point(double x, double y) : x(x), y(y) {}
        void display() {
            cout << "Point: " << x << "," << y << endl;
        }
        bool operator==(Point& p) {
            return(x == p.x && y == p.y);
        }
};

int main() {
    Point p1(3,4);
    Point p2(5,4);
    if(p1==p2) {
        cout << "They are equal" << endl;
    } else {
        cout << "They are not equal" << endl;
    }
    return 0;
}