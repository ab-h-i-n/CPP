#include <iostream>
using namespace std;

class EMPLOYEE {

    int empNo;
    char empName[20];
    float basic;
    float DA;
    float IT;
    float netSal;

public:
    void readData() {
        cout <<"\nEnter the deatails:- \n";
        cout<<"\nEmployee Number: ";
        cin >> empNo;
        cout <<"\nEmployee Name: ";
        cin>>empName;
        cout<<"\nBasic Salary: ";
        cin >>basic;
    }

    void calculateNetSal() {
        DA = 0.52 * basic;
        float grossSal = basic + DA;
        IT = 0.3 * grossSal;
        netSal = grossSal - IT;
    }

    void printData() {
        cout << "\nEmployee Number: " << empNo << endl
             << "Employee Name: " << empName << endl
             << "Basic Salary: " << basic << endl
             << "DA: " << DA << endl
             << "Income Tax: " << IT << endl
             << "Net Salary: " << netSal << endl<<endl;
    }
};

int main() {
    EMPLOYEE emp;

    emp.readData();
    emp.calculateNetSal();
    cout<<"\n\n-:Details of the employee :-\n";
    emp.printData();

    return 0;
}
