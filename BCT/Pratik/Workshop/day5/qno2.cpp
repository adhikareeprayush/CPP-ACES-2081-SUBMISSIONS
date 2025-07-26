//implement multilevel inheritance with a chain Animal -> Mammal -> Dog
#include<iostream>
using namespace std;
class Animal{
    string kingdom;
    public:
        void display(){
            cout<<"Kingdom:"<<kingdom<<endl;
        }

};
class Mammal : public Animal{

};
class  Dog : Mammal{

};

int main(){
    Mammal m1;

    return 0;
}