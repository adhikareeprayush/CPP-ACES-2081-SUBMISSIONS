// A simple program to swap values.
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}
int main()
{
  int a = 6, b = 7;
  cout << "a and b before swapping : " << a << " , " << b << endl;
  swap(a, b);
  cout << "a and b after swapping : " << a << " , " << b << endl;

  float c = 6.67, d = 7.76;
  cout << " c and d before swapping : " << c << " , " << d << endl;
  swap(c, d);
  cout << " c and d after swapping : " << c << " , " << d << endl;

    return 0;
}