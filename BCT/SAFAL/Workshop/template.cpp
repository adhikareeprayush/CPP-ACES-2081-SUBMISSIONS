#include <iostream>

template<typename T>
T max(T a, T b)
{
    return (a>b)? a : b;
}


int main()
{
    int a=5, b=6;
    std::cout << "Max no is " << max<int>(a, b) <<std::endl;
}