#include<iostream>
using namespace std;
class Planet{
    private:
    int x;
    int y;
    int z;
    int w;
    public:
    void mars(int weight,int &rweight,int age,int &rage)
    {
        x=weight;
        y=rweight;
        rweight=weight*0.38;
        z=age;
        rage=age/1.88;
        w=rage;
    }
void jupiter(int weight,int &rweight,int age,int &rage)
    {
        x=weight;
        y=rweight;
        rweight=weight*2.4;
        z=age;
        rage=age/11.86;
        w=rage;
    }
    void venus(int weight,int &rweight,int age,int &rage)
    {
        x=weight;
        y=rweight;
        rweight=weight*0.90;
        z=age;
        rage=age/0.615;
        w=rage;
    }
    
};
class Traveller{
    private: string name;
    int age;
    int weight;
    int rage;
    int rweight;
public:
void setData(string n, int a, int w, int ra, int rw) {
    name = n;
    age = a;
    weight = w;
    rage = ra;
    rweight = rw;
}

void display(){
    name=name;
    age=age;
    rage=rage;
    weight=weight;
    rweight=rweight;
    cout<<"**************************"<<endl;
cout<<"+-----Traveller---Card-----+\n";
cout<<"|-----Name: "<<name<<"\n";
cout<<"|-----Age in earth: "<<age<<"\n";
cout<<"|-----Age in Mars: "<<rage<<"\n";
cout<<"|-----weight in earth:"<<weight<<"\n";
cout<<"|-----weight in mars:"<<rweight<<"\n";
    cout<<"**************************"<<endl;
cout<<"Enjoy your visit beyond the earth**";


}

};
int main(){
int age;
string name;
getline(cin >> ws, name); 
int weight;
int rweight;
int rage;
int i;



    cout<<"Enter your name"<<endl;
     getline(cin >> ws, name);
    cout<<"Enter the age"<<endl;
    cin>>age;
    cout<<"Enter your weight"<<endl;
    cin>>weight;
    cout<<"Which planet do you want to travel??"<<endl;
    cout<<"1.Mars  2.Jupiter  3.Venus"<<endl;
    cin>>i;
    if(i==1){
         Planet p;
    p.mars(weight,rweight,age,rage);
    }
    else if(i==2){
         Planet p;
    p.jupiter(weight,rweight,age,rage);
    }
    else if (i==3){
         Planet p;
    p.venus(weight,rweight,age,rage);
   }
    Traveller t;
    t.setData(name, age, weight, rage, rweight);

    t.display();

    return 0;
}
