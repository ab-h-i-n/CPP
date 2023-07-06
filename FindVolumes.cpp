/*42. Write a C++ program to find the volumes of a Rectangular box (length * width * height),
Cylinder (3.14 * radius^2 * height) and Cube (side^3) using the concepts of Class and
Function Overloading.*/

#include<iostream>
using namespace std;

class Shape{
    const float pi = 3.14;
public:

    void CalcV(float l , float w , float h ){
        cout<<"\nVolume of the Reactangular box : "<<l*w*h<<" cm^3"<<endl;
    }

    void CalcV(float r , float h){
        cout<<"\nVolume of the Cylinder : "<<(pi*r*r*h)<<" cm^3"<<endl;
    }

    void CalcV(float S){
        cout<<"\nVolume of the Cube : "<<(S*S*S)<<" cm^3"<<endl;
    }
};

float InputV(string value , string shape){

    float val;

    do{
    cout<<value<<" of the "<<shape<<" : ";
    cin>>val;
    if(val <= 0){
        cout<<value<<" of the "<<shape<<" should be greater than 0!...."<<endl;
    }
    }while(val <= 0);

    return val;
}

int main(){

    while(true){
        cout<<"...........Volume Calculator.............."<<endl;
        cout<<"\n1.Rectangle Box"<<endl
            <<"2.Cylinder"<<endl
            <<"3.Cube"<<endl
            <<"0.Exit"<<endl
            <<"Enter your choice : ";
        int choice;
        cin>>choice;

        string shape;

        switch(choice){
            case 1:{
                Shape rect;
                float len,wid,hei;
                shape = "Rectangular box";
                cout<<endl<<"..................Rectangular Box..................."<<endl;
                len = InputV("Length",shape);
                wid = InputV("Width",shape);
                hei = InputV("Height",shape);
                rect.CalcV(len,wid,hei);
                break;
            }
            case 2 :{
                Shape cyl;
                float hei,rad;
                shape = "Cylinder";
                cout<<endl<<"..................Cylinder..................."<<endl;
                hei = InputV("Height",shape);
                rad = InputV("Radius",shape);
                cyl.CalcV(rad,hei);
                break;
            }
            case 3 :{
                Shape cub;
                float side;
                shape = "Cube";
                cout<<endl<<"..................Cube..................."<<endl;
                side = InputV("Side",shape);
                cub.CalcV(side);
                break;
            }
            case 0:{
                cout<<endl<<"Exiting........................."<<endl;
                exit(0);
                break;
            }
            default:{
                cout<<endl<<"Invalid choice...............Re-Try.............."<<endl;
            }
        }
    }
    return 0;
}