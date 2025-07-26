#include <iostream>
using namespace std;

class Car{
    // Class Attributes or data members
    private:
        string model;
        int capacity;
        string color;
        double speed;

    public:
        // Setter
        void setCar(string model, int capacity, string color, double speed) {
            this->model = model;
            this->capacity = capacity;
            this->color = color;
            this->speed = speed;
        }

        void start() {
            cout << "Engine has has started!" << endl;
        }

        // Getter
        void getModel() {
            cout << "Model : " << model << endl;
        }
        void stop();
};

void Car::stop() {
    cout << "Car stopped!" << endl;
}

int main() {
    // object definition & declaration
    Car car1;
    car1.setCar("Toyota", 5, "Red", 120);
    car1.getModel();


    Car car2 = car1;
    car2.getModel();

    return 0;
}