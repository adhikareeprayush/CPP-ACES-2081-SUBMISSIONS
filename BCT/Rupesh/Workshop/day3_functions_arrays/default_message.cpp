#include <iostream>
using namespace std;

void printMessage(string str = "Hello World!") {
    cout << str << endl;
}

int main () {
    printMessage();
    printMessage("Hello Harry!");
    return 0;
}