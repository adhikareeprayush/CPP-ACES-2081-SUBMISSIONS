#include <iostream>

float sq(float num){
    return num * num;
}
float cube(float num){
    return num * num *num ;
}
int main()
{
    float num;
    std::cout <<"Enter the number: ";
    std::cin >> num;
    std::cout << "The square of " << num << " is " << sq(num) << std::endl;
    std::cout << "The cube of " << num << " is " << cube(num) << std::endl;
    return 0;
}