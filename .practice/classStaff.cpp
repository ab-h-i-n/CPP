#include <iostream>
#include <cstdlib>
using namespace std;

class Staff {
protected:
    string name;
    int eID;

public:
    Staff(){}
    Staff(const string& name, int eID) : name(name), eID(eID) {}

    void dispInfo() {
        cout << "Employee ID : " << eID << endl
            << "Employee Name : " << name << endl;
    }

    void inpInfo(){
        cout<<"Enter details/-"<<endl;
        cout<<"Employee Name : ";
        cin>>name;
        cout<<"Employee ID : ";
        cin>>eID;
    }
};

class Teacher : public Staff {
    string sub;

public:
    Teacher(){}
    Teacher(const string& name, int eID, const string& sub) : Staff(name, eID), sub(sub) {}

    void dispInfo() {
        Staff::dispInfo();
        cout << "Employee Type : Teacher" << endl;
        cout << "Subject : " << sub << endl << endl;
    }

    void inpInfo(){
        Staff::inpInfo();
        cout<<"Subject : ";
        cin>>sub;
    }
};

class Typist : public Staff {
protected:
    int typSpeed;

public:
    Typist(){}
    Typist(const string& name, int eID, int typSpeed) : Staff(name, eID), typSpeed(typSpeed) {}

    void dispInfo() {
        Staff::dispInfo();
        cout << "Typing Speed : " << typSpeed << endl;
        cout << "Employee Type : Typist" << endl;
    }

    void inpInfo(){
        Staff::inpInfo();
        cout<<"Typing Speed : ";
        cin>>typSpeed;
    }
};

class Officer : public Staff {
    string pos;

public:
    Officer(){}
    Officer(const string& name, int eID, const string& pos) : Staff(name, eID), pos(pos) {}

    void dispInfo() {
        Staff::dispInfo();
        cout << "Employee Type : Officer" << endl;
        cout << "Position : " << pos << endl << endl;
    }

    void inpInfo(){
        Staff::inpInfo();
        cout<<"Position : ";
        cin>>pos;
    }
};

class Regular : protected Typist {
public:
    Regular(){}
    Regular(const string& name, int eID, int typSpeed) : Typist(name, eID, typSpeed) {}

    void dispInfo() {
        Typist::dispInfo();
        cout << "- Regular" << endl << endl;
    }

    void inpInfo(){
        Typist::inpInfo();
    }
};

class Casual : protected Typist {
    float Dwages;

public:
    Casual(){}
    Casual(const string& name, int eID, int typSpeed, float Dwages)
        : Typist(name, eID, typSpeed), Dwages(Dwages) {}

    void dispInfo() {
        Typist::dispInfo();
        cout << "- Casual" << endl;
        cout << "Daily Wages : " << Dwages <<" RS/-"<< endl << endl;
    }

    void inpInfo(){
        Typist::inpInfo();
        cout<<"Daily Wages : ";
        cin>>Dwages;
    }
};

int main() {

    Teacher *T;
    Regular *R;
    Casual *C;
    Officer *O;

    menu:
    system("clear");
    int choice = 0;
    cout<<"Enter the details of /-"<<endl
        <<"1.Teacher"<<endl
        <<"2.Officer"<<endl
        <<"3.Typist"<<endl
        <<"4.Exit"<<endl
        <<"Enter your choice : ";
    cin>>choice;

    int n;
    switch (choice)
    {
        case 1 : {
            system("clear");
            cout<<"Enter the number of Teachers: ";
            cin>>n;

            T = new Teacher[n];

            for(int i=0;i<n;i++){
                cout<<endl<<"Teacher "<<(i+1)<<endl;
                T[i].inpInfo();
            }

            int select;
            case1:
            cout<<"\n1.Show details of Teachers"<<endl
                <<"2.Go to Main menu"<<endl
                <<"Enter your choice : "; cin>>select;
            
            switch(select){

                case 1 : {
                    for(int i =0 ;i<n;i++){
                        cout<<"\nTeacher "<<(i+1)<<endl;
                        T[i].dispInfo();
                    }
                    cout<<endl<<endl;
                    goto case1;
                    break;
                }
                case 2 :{
                    goto menu;
                }
                default:{
                    cout<<"Invalid Option!"<<endl;
                    goto case1;
                }
            }
            break;
        }
        case 2:{
            system("clear");
            cout<<"Enter the number of Officers: ";
            cin>>n;

            O = new Officer[n];

            for(int i=0;i<n;i++){
                cout<<endl<<"Officer "<<(i+1)<<endl;
                O[i].inpInfo();
            }

            int select;
            case2:
            cout<<"\n1.Show details of Officer"<<endl
                <<"2.Go to Main menu"<<endl
                <<"Enter your choice : "; cin>>select;
            
            switch(select){

                case 1 : {
                    for(int i =0 ;i<n;i++){
                        cout<<"\nOfficer "<<(i+1)<<endl;
                        O[i].dispInfo();
                    }
                    cout<<endl<<endl;
                    goto case2;
                    break;
                }
                case 2 :{
                    goto menu;
                }
                default:{
                    cout<<"Invalid Option!"<<endl;
                    goto case2;
                }
            }
            break;
        }
        case 3 : {
            system("clear");
            cout<<"Which type:/-"<<endl;
            cout<<"1.Regular"<<endl
                <<"2.Casual"<<endl
                <<"3.Go to Main menu"<<endl
                <<"Enter your choice : ";
                int select;
                cin>>select;

            switch(select){
                
            }
        }
        default:
        {
            cout<<"Invalid option!"<<endl;
        }
    }

    return 0;
}
