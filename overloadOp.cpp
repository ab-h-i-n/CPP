#include <iostream>
using namespace std;

class Vector {
    int x, y, z;

public:
    Vector() : x(0), y(0), z(0) {}
    Vector(int a, int b, int c) : x(a), y(b), z(c) {}

    friend Vector operator*(const Vector& v1, const Vector& v2);
    friend ostream& operator<<(ostream& os, const Vector& v);
    friend istream& operator>>(istream& is, Vector& v);
};

Vector operator*(const Vector& v1, const Vector& v2) {
    int x = v1.x * v2.x;
    int y = v1.y * v2.y;
    int z = v1.z * v2.z;
    return Vector(x, y, z);
}

ostream& operator<<(ostream& os, const Vector& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

istream& operator>>(istream& is, Vector& v) {
    cout << "Enter the x-coordinate: ";
    is >> v.x;
    cout << "Enter the y-coordinate: ";
    is >> v.y;
    cout << "Enter the z-coordinate: ";
    is >> v.z;
    return is;
}

int main() {
    Vector v1, v2, v3;

    cout << "Enter the values for vector v1:\n";
    cin >> v1;
    cout << "Enter the values for vector v2:\n";
    cin >> v2;

    cout<<"\n\nVector 1 : "<<v1;
    cout<<"\nVector 2 : "<<v2;
    

    v3 = v1 * v2;

    cout<<"\n\nResult of v1 * v2: "<<v3<<endl;

    return 0;
}
