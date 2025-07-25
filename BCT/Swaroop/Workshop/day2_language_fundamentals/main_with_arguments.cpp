#include <iostream>

using namespace std;

/*
    This program demonstrates how to use command-line arguments (argc and argv).
    It prints the number of arguments passed and their values.
*/

int main(int argc, char* argv[]) {
    cout << "Total number of arguments (argc): " << argc << endl;

    // Loop through all the arguments
    for (int i = 0; i < argc; ++i) {
        cout << "Argument " << i << ": " << argv[i] << endl;
    }

    // Example use case: print two numbers passed and add them
    if (argc == 3) {
        int num1 = atoi(argv[1]); // Convert string to int
        int num2 = atoi(argv[2]);

        cout << "Sum: " << num1 + num2 << endl;
    } else if (argc > 1) {
        cout << "\nTip: To add two numbers, run the program like this:\n";
        cout << "./main_with_args 10 20\n";
    }

    return 0;
}
