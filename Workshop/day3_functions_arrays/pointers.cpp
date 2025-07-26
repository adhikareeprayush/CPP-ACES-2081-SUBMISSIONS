#include <iostream> 
using namespace std;
int main() {
    int a = 10;
    int* b = &a;
    // b = address of a
    // *(address) => value at address

    // * - dereferencing operator
    // & - addressof  

    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    cout << "b = " << b << endl;
    cout << "&b = " << &b << endl;
    cout << "*b = " << *b << endl;

    
    return 0;
}