#include <iostream>
using namespace std;
int main()
{
  int a, b;
  try
  {
    cout << "Enter Numbers a and b : " << endl;
    cin >> a >> b;

    if (b == 0)
    {
      throw(0);
    }
  }
  catch (int e)
  {
    if (e == 0)
    {
      cout << "Divide by 0 detected, Please Retry";
      return 1;
    }
  }

  return 0;
}