#include <iostream>

void printMessage(std::string msg = "Hello !")
{
    std::cout << msg << std::endl;
}
int main()
{
    printMessage();
    printMessage("Namaste");
    return 0;
}