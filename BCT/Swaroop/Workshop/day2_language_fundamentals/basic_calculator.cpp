#include <iostream>

using namespace std;

int main() {
    char operation;
    float num1, num2;

    while (true) {
        // Display menu
        cout << "\nBasic Calculator\n";
        cout << "Enter operation (+, -, *, /) or q to quit: ";
        cin >> operation;

        if (operation == 'q') {
            break; // Exit loop
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (operation) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error: Division by zero!" << endl;
                break;
            default:
                cout << "Invalid operation!" << endl;
        }
    }

    return 0;
}
