/*33.Create a base class called shape. Use this class to store two double type values that could be
used to compute the area of figures. Derive three specific classes called triangle, rectangle
and circle from the base shape. Add to the base class, a member function get_data() to
initialize base class data members and another member function display_area() to compute
and display the area of figures. Make the display_area() as a virtual function and redefine
this function in the derived classes to suit their requirements.
Using these four classes, design a program that will accept dimensions of a triangle or a
rectangle or a circle interactively, and display the area. The two values given as input will be
treated as lengths of two sides in the case of rectangles, and base and height in the case of
triangles. For a circle we need only one value as input, that is its radius, but the get_data()
function in the base class requires two values to be passed. Make necessary arrangement to
handle this and use the following formulae to calculate the area of the figures:
Area of rectangle = x*y
Area of triangle = 1⁄2 * x*y
Area of circle = 1⁄2*π〖*r〗^2*/

#include<iostream>
using namespace std;

class Shape{

protected:
    
    double x,y;

public:

    void get_data(){
        cout<<"\nEnter the value for X : ";
        cin>>x;
        cout<<"Enter the value for Y : ";
        cin>>y;
    }

    virtual void display_area() = 0;
};

class Rectangle : public Shape{

public: 

    void display_area(){

        cout<<"\nArea of Rectangle : "<<(x*y)<<endl;
    }
};

class Triangle : public Shape{

public:

    void display_area(){

        cout<<"\nArea of Triangle : "<<((1.0/2.0)*x*y)<<endl;
    }
};

class Circle : public Shape{

public:

    void get_data(){

        cout<<"\nEnter the radius of the circle : ";
        cin>>x;
    }

    void display_area(){

        cout<<"\nArea of the Circle : "<<(3.14*x*x)<<endl;
    }
};

int main(){

    Rectangle r1;
    Triangle t1;
    Circle c1;
    int choice;

    do{

    cout<<"\n.......Find Area........"<<endl<<endl
        <<"1.Rectangle"<<endl
        <<"2.Triangle"<<endl
        <<"3.Circle"<<endl
        <<"0.Exit"<<endl
        <<"Enter choice : ";
    cin>>choice;

    switch(choice){

        case 1 : {
            r1.get_data();
            r1.display_area();
            break;
        }
        case 2 :{
            t1.get_data();
            t1.display_area();
            break;
        }
        case 3:{
            c1.get_data();
            c1.display_area();
            break;
        }
        case 0:{
            exit(0);
            break;
        }
        default:{
            cout<<"Invalid Choice!"<<endl;
        }
    }
    
    }while(choice != 0);

    return 0;
}