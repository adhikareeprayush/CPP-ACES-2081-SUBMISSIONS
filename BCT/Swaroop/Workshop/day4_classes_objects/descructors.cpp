#include <iostream>
using namespace std;

class Car{
    string model;
    double speed;
    static int wheel;
    public:
        // constructor 
        Car() {
            model = "Unknown";
            speed = 0;    
        }

        Car(string model, double speed) {
            this->model = model;
            this->speed = speed;
        }

        // Copy Constructor
        Car(Car& obj) {
            this->model = obj.model;
            this->speed = obj.speed;
        }
        
        static void setWheel() {
            wheel = 4;
        }

        void getCar() {
            cout << "Model : " << model << " Speed: " << speed << endl;
        }

        ~Car() {
            cout << "Destructor called" << endl;
        }

        // void deleteObject(Car* car) {
        //     delete car;
        // }

};


int main() {
    Car car1;
    car1.getCar();
    Car car2;
    car1.getCar();

    return 0;
}


