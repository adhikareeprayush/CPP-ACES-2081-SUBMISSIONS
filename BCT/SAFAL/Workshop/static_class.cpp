#include <iostream>
using namespace std;

class Class
{
    string title, author;
    double price;
    static int count;

    public:
    Class()
    {
        count++;
        cout << "Obj " << count << " created" << endl;
    }
    static void getCount()
    {
        cout << count << endl;
    }
};
int Class::count= 0;

int main()
{
    Class c1, c2, c3;
    Class::getCount();
    return 0;
}