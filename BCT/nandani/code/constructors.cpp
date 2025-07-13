#include<iostream>
using namespace std;
class PC{
    string model;
    static int count;
public:
PC(){
    count++;
}
PC(string model){
    this->model=model;
    count++;
}
static void increment_count(){
    count++;
}
static int getcount(){
    return count;
}
};
int PC::count=0;
int main(){
    PC obj1,obj2;
    cout<< obj1.getcount();
    return 0;
}