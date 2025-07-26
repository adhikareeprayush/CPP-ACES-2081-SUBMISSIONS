#include<iostream>
using namespace std;

class Bird{ //Base class
    string name;
    public:
      void speak(){
        cout<<"chirp"<<endl;
      }
};
class Duck : public Bird{ // Derived class
    int wings;
    public:
      void speak(){
        cout<<"Quack"<<endl;
      }
};

int main(){
    Bird bird1;
    bird1.speak();

    Duck duck1;
    duck1.speak();
    return 0;
}