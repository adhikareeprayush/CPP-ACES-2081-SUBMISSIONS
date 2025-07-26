//implement a class with a static member to track the number of objects created


#include<iostream>
using namespace std;
class Object{
    string name;
    static int count;

    public:
    Object(){
      count++;
    }
      Object(string name){
        this->name = name;
        count++;
      }

      static int getCount(){
        return count;
      }
};
int Object::count=0;


int main(){
  Object o1,o2;
  cout<< o1.getCount();
  return 0;
}