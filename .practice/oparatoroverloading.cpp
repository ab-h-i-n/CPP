#include<iostream>
using namespace std;

class Complex{
    float real;
    float img;
    string name;
public:
    Complex(){}

    Complex(string obj,float x, float y){
        name = obj;
        real = x;
        img = y;
    }

    void disp(){
        cout<<real<<" + j"<<img<<endl;
    }

    Complex operator+ (Complex c){
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        temp.name = "c3";
        return (temp);
    }

    ~Complex() {
        cout << "Destructor called for Complex object."<<name<< endl;
    }
};

int main(){

    cout<<"at initialization\t" ; Complex c1("c1",3.2 , 8.9) , c2("c2",7.3 , 6.5 ) ,c3 = c1 + c2;

    cout<<"\nc1 Complex Number : ";c1.disp();
    cout<<"\nc2 Complex Number : ";c2.disp();
    cout<<"\nc3 Complex Number : ";c3.disp();

    cout<<"at termination\t" ;
    return 0;

}