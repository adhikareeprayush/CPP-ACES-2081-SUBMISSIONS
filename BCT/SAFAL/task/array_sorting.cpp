#include <iostream>
using std::cin, std::cout, std::endl;

void get_input(int* num, int n)
{
    cout <<"Enter elements of array:" <<endl;
    for(int i=0; i<n; i++)
    {
        cin >> *(num + i);
    }
}
void display(int* num, int n)
{
    cout << "The array is: " <<endl;
    for(int i = 0; i < n; i++)
    {
        cout << *(num+i) << endl;
    }
}
void sort(int* num, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if( *(num + i) > *(num + j))
            {
                int temp = *(num + i);
                *(num + i) = *(num + j);
                *(num + j) = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *num = new int[n];
    get_input(num, n);
    sort(num, n);
    display(num, n);
    return 0;
}