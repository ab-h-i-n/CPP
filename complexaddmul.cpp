#include<iostream>
using namespace std;

class Complex{
    float real;
    float img;
public:
    Complex(){}

    Complex(float x, float y){
        real = x;
        img = y;
    }

    void disp(){
        cout<<real<<" + i"<<img;
    }

    Complex operator+ (Complex c){
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return (temp);
    }

    Complex operator* (Complex c){
        Complex temp;
        temp.real = real * c.real;
        temp.img = img * c.img;
        return(temp);
    }
};

int main(){

    cout<<"\nEnter the real part and imginary part of complex number 1 : ";
    float a, b ; cin>>a>>b;
    cout<<"\nEnter the real part and imginary part of complex number 2 : ";
    float c, d ; cin>>c>>d;

    Complex c1(a,b) , c2(c,d);
    
    int choice;
    Complex c3;

    do{

        cout<<"\nOpertaions........"<<endl
            <<"1.Addition"<<endl
            <<"2.Multiplication"<<endl
            <<"3.Exit"<<endl<<endl
            <<"Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1 : c3 = c1 + c2;
                     cout<<"\nSum of Complex numbers ";
                     c1.disp();
                     cout<<" and ";
                     c2.disp();
                     cout<<" = ";
                     c3.disp();
                     cout<<endl<<endl;
                     break;
            case 2 : c3 = c1 * c2;
                     cout<<"\nProduct of Complex numbers ";
                     c1.disp();
                     cout<<" and ";
                     c2.disp();
                     cout<<" = ";
                     c3.disp();
                     cout<<endl<<endl;
                     break;

            case 3 : cout<<"\nExiting........"; break;
            default : cout<<"\nInvalid choice ......Try again.......";break;
        }

    }while(choice != 3);
    


    return 0;

}