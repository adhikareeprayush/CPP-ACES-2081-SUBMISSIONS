// c++ program to calculatre the area of a circle, sphere, rectangle and triangle
// functions
// #include <iostream>
// #include <cmath>
// using namespace std;
// #define pi 3.14
// double areacir(double r){
//     return pi*r*r;
// }
// double areasphe(double r){
//     return 4*pi*r*r;
// }
// double arearec(double l,double b){
//     return l*b;
// }
// double areatri(double b, double h){
//     return (0.5*h*b);
// }
// int main(){
//     double r,l,b,h;
//     cout <<"enter the radius of circle:";
//     cin>>r;
//     cout <<"enter the radius of sphere:";
//     cin>>r; 
//     cout <<"enter the length and breadth of rectangle:";
//     cin>>l>>b;      
//     cout <<"enter the base and height of triangle:";
//     cin>>b>>h;        
//     cout<<"the area of circle is:"<<areacir(r)<<endl;
//     cout<<"the area of sphere is:"<<areasphe(r)<<endl;
//     cout<<"the area of rectangle is:"<<arearec(l,b)<<endl;  
//     cout<<"the area of triangle is:"<<areatri(b,h)<<endl;
//     return 0;
// }
#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.14

double calculateArea(double l, double b,double r, double h, int choice) {
    float area;
    if(choice==1){
        cout<<" enter the radius of circle: ";
        cin>>r;
        area= pi*r*r;
    }
    else if(choice==2){
        cout<<" enter the radius of sphere: ";
        cin>>r;
        area= 4*pi*r*r;
    }
    else if(choice==3){
        cout<<" enter the length and breadth of rectangle: ";
        cin>>l>>b;
        area= l*b;
    }
    else if(choice==4){
        cout<<" enter the base and height of triangle: ";
        cin>>b>>h;
        area= 0.5*b*h;
    }
    else{
        cout << "Invalid choice!" << endl;
        // return -1; // Indicating an error
    }

    return area;
}   
int main(){
     int choice;
     cout<< "1.circle\n2.sphere\n3.rectangle\n4.triangle\n";
     cout<< "Enter your choice: " << endl;
    switch(choice){
        case 1:
            //
            break;
        case 2:
            //
            break;
        case 3:
            //
            break;
        case 4:
            //
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}