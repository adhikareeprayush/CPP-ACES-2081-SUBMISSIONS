#include <iostream>
using std::cin, std::cout, std::endl;

int main()
{
    float a, b;

    try
    {
        cout << "Enter 2 numbers: ";
        cin >> a >> b;

        if (b == 0)
            throw "Division by zero error!";

        cout << "Result of a/b is: " << a / b << endl;
    }
    catch (const char* e)
    {
        cout << "Error: " << e << endl;
        main();
    }

    return 0;
}
