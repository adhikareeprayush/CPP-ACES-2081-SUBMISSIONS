#include <iostream>
using namespace std;

void reverse(string name){
    string reverse="";
    for(int i=name.length(); i>=0;  i--) {
        reverse+=name[i];
    }
    cout << "Original: " << name << endl;
    cout << "Reverse: " << reverse;
}

int main() {
    string name = "Hello";
    reverse(name);
    return 0;
}