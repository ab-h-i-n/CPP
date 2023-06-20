#include <iostream>
using namespace std;

class Complex {


    float real;
    float imaginary;

public:
    void set(float realPart, float imaginaryPart) {
        real = realPart;
        imaginary = imaginaryPart;
    }

    void disp() {
        cout << real << " + " << imaginary << "i" << endl;
    }

    static Complex sum(Complex c1, Complex c2) {
        Complex result;
        result.real = c1.real + c2.real;
        result.imaginary = c1.imaginary + c2.imaginary;
        return result;
    }
};

int main() {
    Complex c1, c2, c3;
    float real , imaginary;

    cout<<"Enter the real part of complex number 1 : ";
    cin>>real;
    cout<<"Enter the imaginary part of complex number 1: ";
    cin>>imaginary;

    c1.set(real, imaginary);


    cout<<"\nEnter the real part of complex number 2 : ";
    cin>>real;
    cout<<"Enter the imaginary part of complex number 2: ";
    cin>>imaginary;

    c2.set(real, imaginary);

    c3 = Complex::sum(c1,c2);

    cout << "Complex number 1: ";
    c1.disp();

    cout << "Complex number 2: ";
    c2.disp();

    cout << "Sum of complex numbers: ";
    c3.disp();

    return 0;
}
