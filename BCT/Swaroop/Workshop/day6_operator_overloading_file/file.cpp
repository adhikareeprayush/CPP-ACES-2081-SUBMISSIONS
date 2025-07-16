#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Writing to a file
    ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Hello, File I/O!\n";
        outFile << "This is a test line.\n";
        outFile.close();
    } else {
        cout << "Unable to open file for writing" << endl;
    }

    // Reading from a file
    ifstream inFile("example.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading" << endl;
    }
    return 0;
}