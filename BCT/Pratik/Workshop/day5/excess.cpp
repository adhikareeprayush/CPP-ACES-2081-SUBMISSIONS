#include<iostream>
using namespace std;

class Bird{ //Base class
    public: 
    string name;
    Bird(string name): name(name){}
    int legs;
    public:
      void speak(){
        cout<<"chirp"<<endl;
      }
};
class Duck : public Bird{ // Derived class
    int wings;
    public:
    Duck(string name,int wings) : Bird(name), wings(wings) {}
      void speak(){
        cout<<"Quack"<<endl;
      }
      void displayDuck(){
        cout<<"name:"<<name<<"wings:"<<wings<<endl;
      }
    };

    int main(){
    return 0;
}