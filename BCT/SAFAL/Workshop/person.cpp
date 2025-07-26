#include <iostream>
using std::cout, std::string, std::endl;
class Person
{
    string name;
    double net_worth;

    public:
    Person(string name, double n_w):name(name), net_worth(n_w){cout << name << " obj created" << endl;}

    ~Person()
    {
        cout << name << " obj destructed" << endl;
    }
};

int main()
{
    Person sagun("sagun", 0);
    {
        Person safal("safal", 1000000);
    }
}