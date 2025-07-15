#include <iostream>
using namespace std;

class Car{
    string model;
    static int count;

    public:
        Car() {
            count++;
        }
        Car(string model) {
            this->model = model;
            count++;
        }
   
        static int getCount() {
            return count;
        }
};

int Car::count = 0;

int main() {
    Car obj1, obj2;
    cout << obj1.getCount();
}