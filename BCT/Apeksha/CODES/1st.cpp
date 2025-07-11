#include<iostream>
using namespace std;

class Book{
    private:
    string name;
    int marks;
    public:
    void setdata(int m,string n){
    name=n;
    marks=m;}

void display(){
    cout<<name << marks <<endl;
}
};
int main(){
    Book p;
    p.setdata(32,"Ram");
    p.display();
    return 0;
}