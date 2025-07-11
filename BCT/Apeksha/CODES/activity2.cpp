#include<iostream>
using namespace std;
class Point{
    int x;
    int y;
    public:
    Point(double x,double y):x(x),y(y){}

    void display(){
        cout<<x<<","<<y;
    }
bool operator==(Point&p){
    return (x==p.x&&y==p.y);
}
};
int main(){
    Point p1(3,4);
    Point p2(5,6);
    if(p1==p2){
        cout<<"They are equal"<<endl;

    }
    else{
        cout<<"They are not equal"<<endl;
    }

    return 0;
}