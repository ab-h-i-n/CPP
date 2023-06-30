//31.Write a program to read and display the employee information (name, designation, age,date of birth, date of joining, etc.) using pointer to object and container class.

#include <iostream>
#include <string>

using namespace std;

class Employee {

    string name;
    string designation;
    int age;
    string dateOfBirth;
    string dateOfJoining;

public:
    void readData() {
        cout << "\n\nEnter Employee Details:" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Designation: ";
        cin >> designation;
        cout << "Age: ";
        cin >> age;
        cout << "Date of Birth: ";
        cin >> dateOfBirth;
        cout << "Date of Joining: ";
        cin >> dateOfJoining;
    }

    void printData() {
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Age: " << age << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Date of Joining: " << dateOfJoining << endl;
    }
};

int main() {

    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Employee* employees[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        employees[i] = new Employee();
        employees[i]->readData();
    }

    cout << "\n\nEmployee Information:\n" << endl;
    for (int i = 0; i < numEmployees; i++) {
        cout<<"\nEmployee "<<(i+1)<<endl;
        employees[i]->printData();
    }

    // Clean up memory
    for (int i = 0; i < numEmployees; i++) {
        delete employees[i];
    }

    return 0;

}
