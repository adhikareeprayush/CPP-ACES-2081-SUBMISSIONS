#include <iostream>
using namespace std;
void printMessage(string msg = "Hello, World!")
{
  cout << msg;
}
int main()
{
  printMessage();
  printMessage("\nHello This is Shiv.");
  return 0;
}
