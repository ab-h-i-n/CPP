#include <iostream>
#include <string>
using namespace std;

class pntr_obj {
    int roll_no;
    string name;

public:
    void set_data(int roll, string& student_name) {
        this->roll_no = roll;
        this->name = student_name;
    }

    void print() {
        cout << "Object with roll number " << this->roll_no << " and name " << this->name
             << " invoked the print() function." << endl;
    }
};

int main() {
    pntr_obj obj1, obj2, obj3;

    obj1.set_data(1, "Alice");
    obj2.set_data(2, "Bob");
    obj3.set_data(3, "Charlie");

    obj1.print();
    obj2.print();
    obj3.print();

    return 0;
}
