#include<iostream>
using namespace std;
class Car{

   //class attributes or data members

   private:
     string model;
     int capacity;
     string colour;
     double speed;

   //class methods or member functions
    public:
    // Setter --- object ko values initialize garne setter
    void setCar(string model,int capacity,string colour,double speed){
        this->model = model;
        this->capacity = capacity;
        this->colour = colour;
        this->speed = speed;
    }
     void start(){
        cout<<"engine has started!"<<endl;
     }
     void details(){
        cout<<"the model is :"<<model<<endl;
        cout<<"the colour is:"<<colour<<endl;
     }
     //and Getter 
     void getCar(){
        cout<<"the model is :"<<model<<endl;
        cout<<"the colour is:"<<colour<<endl;
     }

     void stop(){
        cout<<"the car has stopped!"<<endl;
     }

};

int main() {
    //object definition and declaration
    Car c1;
    c1.setCar("BMW",5,"black",100);
    c1.getCar();
    
    //copying the details of object c1 to object c2
    Car c2 = c1;
    c2.getCar();
    return 0;
}