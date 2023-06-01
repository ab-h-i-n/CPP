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
        cout << "Distance: " << feet << " feet, " << inches << " inches" << endl;
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

    d1.set(5, 9.5);
    d2.set(3, 6.25);

    d3 = Distance::add(d1 , d2);

    d1.disp();
    d2.disp();
    cout<<"\nSUM : ";
    d3.disp();

    return 0;
}
