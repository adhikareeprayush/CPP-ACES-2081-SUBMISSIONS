#include<iostream>
using namespace std;
void increment(int n)
{
    n=n+1;

}
void incrementbyreference(int& c)
{
    c=++c;
}
int main(){
    int a=2;
    increment(a);
    cout<<"a after increment()=>"<<a<<endl;
    incrementbyreference(a);
    cout<<"a after incrementbyreference()=>"<<a<<endl;
return 0;

}