#include <iostream>
using namespace std;

class Distance {

    int feet;
    float inches;

public:
    void set(int ft, float in) {
        feet = ft;
        inches = in;
    }

    void disp() {
        cout << "\nDistance: " << feet << " feet, " << inches << " inches" << endl;
    }

    static Distance add(Distance d1 , Distance d2) {
        Distance result;
        result.feet = d1.feet + d2.feet;
        result.inches = d1.inches + d2.inches;

        if (result.inches >= 12.0) {

            result.feet += result.inches / 12.0;
            result.inches -= int((result.inches / 12.0)) * 12.0;

        }
        return result;
    }
};

int main() {

    Distance d1, d2, d3;
    int feet ;
    float inches;

    cout<<"Distance 1:-"<<endl;
    cout<<"Enter the value of Feet : ";
    cin>>feet;
    cout<<"Enter the value of Inches : ";
    cin>>inches;
    d1.set(feet,inches);

    cout<<"\nDistance 2:-"<<endl;
    cout<<"Enter the value of Feet : ";
    cin>>feet;
    cout<<"Enter the value of Inches : ";
    cin>>inches;
    d2.set(feet,inches);

    d3 = Distance::add(d1 , d2);

    d1.disp();
    d2.disp();
    cout<<"\nSUM : ";
    d3.disp();

    return 0;
}
