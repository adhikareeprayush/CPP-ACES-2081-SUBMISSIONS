#include<iostream>
using namespace std;
class Person{
private: int age;string name;
public:
Person(string name,int age):name(name),age(age){}

Person(): name("Unknown"),age(0){}
~Person(){cout <<"Deconstructor called"<<endl;}
};
int main(){
    Person person1("Ram",20);
    return 0;
}