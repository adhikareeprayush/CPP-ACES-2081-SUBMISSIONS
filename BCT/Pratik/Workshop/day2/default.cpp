// string as default argument
// C++ program to demonstrate the use of default arguments with strings
#include<iostream>
using namespace std;
void printMessage(string str=" hello world") // default message
{
    cout << str << endl;
}
int main() {
    printMessage(); // prints "hello world"
    printMessage("hello pratik"); // prints custom message
    return 0;
}