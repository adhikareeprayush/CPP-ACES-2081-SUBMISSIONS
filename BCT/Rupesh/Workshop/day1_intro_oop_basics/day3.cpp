// C++ program to calculte area of circle, shpere, rectangle and triangle
// Functions 
#include<iostream>
#define PI 3.14;

using namespace std;

double CaculateArea(int shape)
    {
        float area;
        if(shape == 1)
        {
            double radius;
            cout<<"Enter the radius: "<<endl;
            cin>>radius;
            area = PI;
        }

        return area;
    }
int main()
{
    int choice;
    cout<<"Enter the shape number: "<<endl;
    cout<<"1. Circle\n2. Sphere\n3. Rectangle\4.Traingle"<<endl;
  

    return 0;
}