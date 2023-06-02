#include <iostream>
using namespace std;

class Vector {
    int x, y, z;

public:
    Vector() : x(0), y(0), z(0) {}
    Vector(int a, int b, int c) : x(a), y(b), z(c) {}

    friend Vector operator*(const Vector& v1, const Vector& v2);
    friend void printVector(const Vector& v);
    friend void readVector(Vector& v);
};

Vector operator*(const Vector& v1, const Vector& v2) {
    int x = v1.x * v2.x;
    int y = v1.y * v2.y;
    int z = v1.z * v2.z;
    return Vector(x, y, z);
}

void printVector(const Vector& v) {
    cout << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
}

void readVector(Vector& v) {
    cout << "Enter the x-coordinate: ";
    cin >> v.x;
    cout << "Enter the y-coordinate: ";
    cin >> v.y;
    cout << "Enter the z-coordinate: ";
    cin >> v.z;
}

int main() {
    Vector v1, v2, v3;

    cout << "Enter the values for vector v1:\n";
    readVector(v1);
    cout << "Enter the values for vector v2:\n";
    readVector(v2);

    v3 = v1 * v2;

    cout << "Result of v1 * v2: ";
    printVector(v3);

    return 0;
}
