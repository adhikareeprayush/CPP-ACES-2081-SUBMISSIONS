// create a vehicle base class and derive car and bike classes with a virtual start function 
#include<iostream>
using namespace std;
class Vehicle{
    public:
    string name;
    virtual void start(){
        cout<<"vehicle started"<<endl;
    }
};
class Car: public Vehicle {
    public:
    void start() override{
         cout<<"car started"<<endl;
    }

};
class Bike: public Vehicle{
    public:
    void start() override{
        cout<<"bike started"<<endl;
    }

};

int main(){
    Bike bike1;
    bike1.start();
    Car car1;
    car1.start();
    Vehicle vehicle1;
    vehicle1.start();
    return 0;
}