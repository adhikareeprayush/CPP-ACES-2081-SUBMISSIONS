#include<iostream>
using namespace std;
class Vehicle{
    private: 
    string name;
    public:
    virtual void start(){
    cout <<"It is a vehicle"<<endl;
    }
};
class Bike: public Vehicle
{
    public:
    void start()override{
        cout<<"It is a bike"<<endl;
    }
};
class Car:public Vehicle
{
    public:
    void start() override{
    cout<<"it is a car"<<endl;
}
};