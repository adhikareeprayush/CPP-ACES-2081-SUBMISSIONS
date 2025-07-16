#include <iostream>
using namespace std;

class Car{
    string model;
    double speed;

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

        void getCar() {
            cout << "Model : " << model << " Speed: " << speed << endl;
        }

};

int main() {
    Car car1; // no parameters
    Car car2 = {"Toyota", 21};
    Car car3("BMW",120);

    car1.getCar();
    car2.getCar();
    car3.getCar();

    Car car4(car2);
    car4.getCar();

    return 0;
}