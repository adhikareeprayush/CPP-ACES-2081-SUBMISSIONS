#include<iostream>
using namespace std;

class Car{
    //class attributes
    private:
    string model;
    int capacity;
    string color;
    int speed;
    //class methods or member functions
    public:
    void setcar(string model,int capacity,string color,int speed){
       this -> model=model;
        this ->capacity=capacity;
         this -> color=color;
         this -> speed=speed;
    }
    void start(){
        cout<<"Engine has started!"<<endl;

    }
    void details(){
        cout<<"enter model of car"<<endl;
        cin>>model;
        cout<<"enter capcacity of car"<<endl;
        cin>>capacity;
        cout<<"enter color of car"<<endl;
        cin>>color;
        cout<<"enter the speed of the car"<<endl;
        cin>>speed;
        cout<<"The model of car is: "<<model<<endl<<"The capacity of car is: "<<capacity<<endl<<"The color of car is: "<<color<<endl<<"The speed of  car is: "<<speed<<endl;


    }
void stop();
};
void Car::stop(){
    cout<<"the car has stopped";
}

int main(){
    Car car1;
    car1.start();

    car1.details();
    return 0;
}