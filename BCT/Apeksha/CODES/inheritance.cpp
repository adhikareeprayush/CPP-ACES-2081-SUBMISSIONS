#include<iostream>
using namespace std;
class Bird{
    string name;
    public:
    void speak(){
    cout<<"chirp"<<endl;
    }
};
class Duck: public Bird{
int wings;
public:
void speak(){
    cout<<"Quack"<<endl;
}
};
int main(){
    Bird bird1;
    bird1.speak();
    Duck bird2;
    bird2.speak();
    return 0;
}