//wap using a parameterized constructor and destructor to manage a person class
#include<iostream>
using namespace std;
class Person{
   string name;
   int age;
   string job;
   public:
   //default constructor
   Person(){
    name="unknown";
    age=0;
    job="unknown";
   }
   //paramertized constructor
   Person(string a, int b, string c){
    name= a;
    age = b;
    job = c;
    cout<<"constructor is called!"<<endl;
  }
  //destructor
  ~Person(){
  cout<<"destructor is called!"<<endl;
  }
  void display(){
    cout<<"name:"<<name<<endl<<"age:"<<age<<endl<<"job:"<<job<<endl;
  }
};
int main(){
    Person p1("pratik",18,"teacher");
    p1.display();
    return 0;
}