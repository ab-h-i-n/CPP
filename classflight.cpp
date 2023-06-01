#include<iostream>
using namespace std;

class Flight{
    int fNo;
    string Destination;
    float Distance;
    float Fuel;

    void CALFUEL(){
        if(Distance<=1000){Fuel = 500;}
        else if(Distance > 1000 && Distance <=2000){Fuel = 1100;}
        else{Fuel = 2200;}
    }

public:

    void FEEDINFO(){
        cout<<endl<<"Enter the details:-"<<endl;
        cout<<endl<<"Flight Number : "; cin>>fNo;
        cout<<endl<<"Destination : ";cin>>Destination;
        cout<<endl<<"Distance : ";cin>>Distance; CALFUEL();
    }

    void SHOWINFO(){
        cout<<endl<<endl<<"Details:-"<<endl;
        cout<<endl<<"Flight Number : "<<fNo;
        cout<<endl<<"Destination : "<<Destination;
        cout<<endl<<"Distance : "<<Distance;
        cout<<endl<<"Fuel required : "<<Fuel<<endl<<endl;
    }
};

int main(){
    Flight u1;

    u1.FEEDINFO();
    u1.SHOWINFO();
}