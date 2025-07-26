#include <iostream>
using std::cin, std::cout, std::endl, std::string;
class Car
{
    private:
    static int count;
    string model;
    int capacity;
    string color;

    public:
    Car (string mod, int cap, string col): model(mod), capacity(cap), color(col){}

    Car(Car& obj)
    {
        
        model = obj.model;
        capacity = obj.capacity;
        color = obj.color;
    }
    ~Car(){count++;cout <<model << " destructed "<< count << endl ;}

    void start()
    {
        cout << "Engine started "<< endl;
    }
    void details()
    {
        cout << "Model: " << this->model << "\nColor: "<< this->color << "\nCapacity: "<< this->capacity << endl;
    }
    void stop()
    {
        cout << "Engine stopped "<< endl;
    }
};
int Car::count = 0;
int main()
{
    Car car1("Land-rover", 880, "Red");
    car1.start();
    car1.details();
    car1.stop();
    {
        Car car2(car1);
    }
    cout <<"----------" <<endl;
    return 0;
}