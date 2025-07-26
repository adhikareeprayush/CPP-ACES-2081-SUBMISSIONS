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
int find_max(int *num, int n)
{
    int max = *num;
    for (int i = 0; i < n; i++)
    {
        if (*(num + i) > max)
            max = *(num + i);
    }
    return max;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *num = new int[n];
    get_input(num, n);
    int max = find_max(num, n);
    cout << "The maximun number is " << max << endl;
    return 0;
}