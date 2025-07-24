#include <iostream>
using namespace std;

int main()
{
  int arr[] = {10, 98, 2, 3, 41, 5, 6, 17, 0, 94};
  int n = sizeof(arr) / sizeof(arr[0]);
  int min = arr[0];

  for (int i = 1; i < n; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
  }

  cout << "The minimum element is: " << min << endl;
  return 0;
}
