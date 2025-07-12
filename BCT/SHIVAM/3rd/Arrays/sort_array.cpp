// BUbble sort
#include <iostream>
using namespace std;

int main()
{
  int arr[] = {10, 98, 2, 3, 41, 5, 6, 17, 0, 94};
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
