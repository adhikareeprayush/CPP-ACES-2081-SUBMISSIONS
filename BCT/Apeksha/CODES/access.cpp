#include<iostream>
using namespace std;
class Bird{
    public:
    string name;
    
    Bird(string name): name(name){}
    void speak(){
    cout<<"chirp"<<endl;
    }
};
class Duck: public Bird{
int wings;
public:
Duck(string name,int wings): Bird(name),wings(wings){}
void speak(){
    cout<<"Quack"<<endl;
}
void displayduck(){
cout<<"name:" << name <<"Wings: " <<wings<<endl;}
};
