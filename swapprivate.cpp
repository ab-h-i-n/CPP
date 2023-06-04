#include<iostream>
#include<string>
using namespace std;

class Class_2; 

class Class_1{
    string name;
    int num;

public:
    Class_1() {}
    Class_1(string name, int num): name(name), num(num) {}

    void disp(){
        cout << "Name: " << name << endl
             << "num: " << num << endl;
    }

    friend void swap(Class_1& c1, Class_2& c2);
};

class Class_2{
    string name;
    int num;

public:
    Class_2() {}
    Class_2(string name, int num): name(name), num(num) {}

    void disp(){
        cout << "Name: " << name << endl
             << "num: " << num << endl;
    }

    friend void swap(Class_1& c1, Class_2& c2); 
};

void swap(Class_1& c1, Class_2& c2){ 
    string temp_name = c1.name;
    int temp_num = c1.num;

    c1.name = c2.name;
    c1.num = c2.num;

    c2.name = temp_name;
    c2.num = temp_num;
}

int main(){
    string name;
    int num;

    cout << "Enter the Name for Class 1: ";
    cin >> name;
    cout << "Enter the Number for Class 1: ";
    cin >> num;

    Class_1 c1(name, num);

    cout << endl << "Enter the Name for Class 2: ";
    cin >> name;
    cout << "Enter the Number for Class 2: ";
    cin >> num;

    Class_2 c2(name, num);

    cout << endl << "Class 1:" << endl;
    c1.disp();

    cout << endl << "Class 2:" << endl;
    c2.disp();

    swap(c1, c2);

    cout << endl << "Class 1 after swap:" << endl;
    c1.disp();

    cout << endl << "Class 2 after swap:" << endl;
    c2.disp();

    return 0;
}
