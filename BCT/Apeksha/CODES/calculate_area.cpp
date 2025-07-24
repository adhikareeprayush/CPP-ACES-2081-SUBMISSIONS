//C++ program to calculate area of circle,sphere,Rectangle and Triangle using functions

#include<iostream>
using namespace std;
class Circle{
private: int radius;
public:
void setdata(int r)
{
    radius=r;
}
int areaofcircle(int r,int area){
    cout<<"Enter the radius of circle:";
    cin>>r;
    area=3.14*r*r;
    cout<<"The area of circle is:"<<area;
}
};
class Rectangle{
private: int length;
int breadth;
public:
void setdata(int l, int b)
{
    length=l;
    breadth=b;
}
int areaofrectangle(int l,int b,int area)
{
    cout<<"Enter the length and breadth of rectangle";
    cin>>l>>b;
    area=l*b;
    
    cout<<"The area of rectangle is:"<<area;
}
};
class Sphere{
    private:
    int radius;
    public:
    void setdata(int r)
    {
        radius=r;
    }
    int areaofsphere(int r,int area)
    {
        cout<<"Enter the radius of sphere";
        cin>>r;
        area=4/3*3.14*r*r*r;
        cout<<"The area of sphere is:"<<area;
    }
};
int main(int r,int l,int b, int area,int choice){
    Circle c;
    Rectangle rec;
    Sphere s;
    cout<<"Enter the choice number:";
    cout<<"1.Cicle\n2.Rectangle\n3.Sphere";
    cin>>choice;
    if(choice==1){
        c.setdata(r);
        c.areaofcircle(r,area);
    }
    else if(choice==2){
        rec.setdata(l,b);
        rec.areaofrectangle(l,b,area);
    }
    else{
        s.setdata(r);
        s.areaofsphere(r,area);
    }
return 0;
}