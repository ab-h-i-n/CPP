/*42. Write a C++ program to find the volumes of a Rectangular box (length * width * height),
Cylinder (3.14 * radius^2 * height) and Cube (side^3) using the concepts of Class and
Function Overloading.*/

#include<iostream>
using namespace std;

class Shape{
    const float pi = 3.14;
public:

    void CalcV(float l , float w , float h ){
        cout<<"\nVolume of the Reactangular box : "<<l*w*h<<endl;
    }

    void CalcV(float r , float h){
        cout<<"\nVolume of the Cylinder : "<<(pi*r*r*h)<<endl;
    }

    void CalcV(float S){
        cout<<"\nVolume of the Cube : "<<(S*S*S)<<endl;
    }
};

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


        switch(choice){
            case 1:{
                Shape rect;
                float len,wid,hei;
                cout<<endl<<"..................Rectangular Box..................."<<endl
                        <<"Length of the rectangular box : ";
                cin>>len;
                cout<<"Width of the rectangular box :";
                cin>>wid;
                cout<<"Height of the rectangular box : ";
                cin>>hei;
                rect.CalcV(len,wid,hei);
                break;
            }
            case 2 :{
                Shape cyl;
                float hei,rad;
                cout<<endl<<"..................Cylinder..................."<<endl
                        <<"Radius of the cylinder : ";
                cin>>rad;

                cout<<"Height of the cylinder : ";
                cin>>hei;

                cyl.CalcV(rad,hei);
                break;
            }
            case 3 :{
                Shape cub;
                float side;
                cout<<endl<<"..................Cube..................."<<endl
                        <<"Side of the cube : ";
                cin>>side;
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