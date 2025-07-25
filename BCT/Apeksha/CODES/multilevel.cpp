#include<iostream>
using namespace std;
class Animal{
private:
string name;
public:
void display(){
cout<<"it lives on earth"<<endl;
}
};
class Mammal:public Animal{
};
class Dog:public Mammal{};