#include <iostream>
using namespace std;

int main()
{
  int arr[] = {10, 98, 2, 3, 41, 5, 6, 17, 0, 94};
  int size = sizeof(arr) / sizeof(arr[0]);
  int max = arr[0];

  for (int i = 1; i < size; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }

  cout << "The maximum element is: " << max << endl;
  return 0;
}
