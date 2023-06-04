#include<iostream>
using namespace std;

class Car {
    string name;
    string color;

public:
    Car() {}
    Car(const Car& c) {
        name = c.name;
        color = c.color;
    }
    Car(string name, string color): name(name), color(color) {}

    void disp() {
        cout << "Name: " << name << endl
             << "Colour: " << color << endl<<endl;
    }
};

int main() {
    string name, color;

    cout << "Enter name of Car 1: ";
    cin >> name;
    cout << "Enter color of Car 1: ";
    cin >> color; 
    
    Car c1(name, color);
    Car c2 = c1;

    cout <<endl<<"Car 1:-" << endl;
    c1.disp();

    cout <<endl<<"Car 2 (copied):-" << endl;
    c2.disp();

    return 0;
}
