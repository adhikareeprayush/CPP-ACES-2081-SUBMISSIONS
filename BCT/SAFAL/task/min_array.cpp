#include <iostream>
using std::cin, std::cout, std::endl;

void get_input(int *num, int n)
{
    cout << "Enter elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> *(num + i);
    }
}
void display(int *num, int n)
{
    cout << "The array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(num + i) << endl;
    }
}
int find_min(int *num, int n)
{
    int min = *num;
    for (int i = 0; i < n; i++)
    {
        if (*(num + i) < min)
            min = *(num + i);
    }
    return min;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *num = new int[n];
    get_input(num, n);
    int max = find_min(num, n);
    cout << "The minimun number is " << max << endl;
    return 0;
}