// #include <iostream>
// using namespace std;
// class Coordinate1
// {
// private:
//   double x1, y1;

// public:
//   Coordinate(double a, double b) : x1(a), y1(b) {}

//   friend Coordinate1 add(Coordinate &a, Coordinate &b);

//   void display()
//   {
//     cout << x1 << y1 << endl;
//   }
// };
// class Coordinate2
// {
// private:
//   double x2, y2;

// public:
//   Coordinate(double c, double d) : x2(c), y2(d) {}

//   friend Coordinate2 add(Coordinate)
// };
// Coordinate add(Coordinate &a, Coordinate &b)
// {
//   Coordinate temp(a.x1 + b.y1);
//   return temp;
// }
// int main()
// {
//   Coordinate c1(2, 3);
//   Coordinate c2(1, 1);

//   Coordinate c3 = add(c1, c2);

//   c3.display();
//   return 0;
// }

#include <iostream>
using namespace std;

class Point
{
  double x, y;

public:
  Point(double x, double y) : x(x), y(y) {}
  void display()
  {
    cout << "Point: " << x << " , " << y << endl;
  }
  bool operator==(Point &p)
  {
    return (x == p.x && y == p.y);
  }
};
int main()
{
  Point p1(4, 5);
  Point p2(4, 5);

  if (p1 == p2)
  {
    cout << "They are equal" << endl;
  }

  else
  {
    cout << "They are NOT Equal" << endl;
  }

  return 0;
}
