#include <iostream>
#include <iomanip> // For I/O manipulators

using namespace std;

int main() {
    float pi = 3.14159265;

    cout << "Without manipulators:\n";
    cout << "Pi = " << pi << endl;

    cout << "\nWith manipulators:\n";
    cout << fixed << setprecision(2);
    cout << "Pi = " << pi << endl;

    cout << setw(10) << "Name" << setw(10) << "Score" << endl;
    cout << setw(10) << "Alice" << setw(10) << 95 << endl;
    cout << setw(10) << "Bob" << setw(10) << 88 << endl;

    return 0;
}
