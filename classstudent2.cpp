#include<iostream>
using namespace std;

class Student{

    class Date{
        public:
        int day;
        int month;
        int year;
    };

    class Age{
        public:
        int age;
    };

    char name[20];
    int rollno;
    char sex;
    Date dob;
    Age age;


    public:
        void readData(){
            cout<<"\nEnter the details :-\n";
            cout<<"\nName: ";
            cin>>name;
            cout<<"\nRoll no: ";
            cin>>rollno;
            cout<<"Sex(M/F) :";
            cin>>sex;
            cout<<"Date of Birth (DD MM YYYY) : ";
            cin>>dob.day>>dob.month>>dob.year;
            cout<<"Age : ";
            cin>>age.age;
        }

        void printData() {
            cout << "Name: " << name << endl
                 << "Roll No: "<<rollno<< endl
                 << "Sex: " << sex << endl
                 << "Date of Birth: " << dob.day << "/" << dob.month << "/" << dob.year << endl
                 << "Age: " << age.age << endl;
                 
        }
};

int main() {

    int n;
    cout<<"\nEnter the number of students : ";
    cin>>n;

    Student students[n];

    for (int i=0; i<n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].readData();
    }

    cout <<"\nStudent Details:\n";
    for (int i=0;i<n; i++) {
        cout<<"\nStudent "<<(i+1)<<endl<<endl;
        students[i].printData();
        cout<<endl<<endl;
    }

    return 0;
}