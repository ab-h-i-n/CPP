#include <iostream>
#include <string>

using namespace std;

class Staff {
protected:
    string name;
    int eID;

public:
    Staff() : name(""), eID(0) {}
    Staff(const string& name, int eID) : name(name), eID(eID) {}

    void readInfo() {
        cout << "Name: ";
        cin >> name;
        cout << "Employee ID: ";
        cin >> eID;
    }

    void dispInfo() {
        cout << "Employee ID: " << eID << endl
             << "Employee Name: " << name << endl;
    }
};

class Teacher : public Staff {
    string sub;

public:
    Teacher() : Staff(), sub("") {}
    Teacher(const string& name, int eID, const string& sub) : Staff(name, eID), sub(sub) {}

    void readInfo() {
        Staff::readInfo();
        cout << "Subject: ";
        cin >> sub;
    }

    void dispInfo() {
        Staff::dispInfo();
        cout << "Employee Type: Teacher" << endl
             << "Subject: " << sub << endl << endl;
    }
};

class Typist : public Staff {
protected:
    int typSpeed;

public:
    Typist() : Staff(), typSpeed(0) {}
    Typist(const string& name, int eID, int typSpeed) : Staff(name, eID), typSpeed(typSpeed) {}

    void readInfo() {
        Staff::readInfo();
        cout << "Typing Speed: ";
        cin >> typSpeed;
    }

    void dispInfo() {
        Staff::dispInfo();
        cout << "Typing Speed: " << typSpeed << endl
             << "Employee Type: Typist";
    }
};

class Officer : public Staff {
    string pos;

public:
    Officer() : Staff(), pos("") {}
    Officer(const string& name, int eID, const string& pos) : Staff(name, eID), pos(pos) {}

    void readInfo() {
        Staff::readInfo();
        cout << "Position: ";
        cin >> pos;
    }

    void dispInfo() {
        Staff::dispInfo();
        cout << "Employee Type: Officer" << endl
             << "Position: " << pos << endl << endl;
    }
};

class Regular : protected Typist {
public:
    Regular() : Typist() {}
    Regular(const string& name, int eID, int typSpeed) : Typist(name, eID, typSpeed) {}

    void readInfo(){
        Typist::readInfo();
    }

    void dispInfo() {
        Typist::dispInfo();
        cout << "- Regular" << endl << endl;
    }
};

class Casual : protected Typist {
    float Dwages;

public:
    Casual() : Typist(), Dwages(0.0) {}
    Casual(const string& name, int eID, int typSpeed, float Dwages)
        : Typist(name, eID, typSpeed), Dwages(Dwages) {}

    void readInfo(){
        Typist::readInfo();
        cout<<"Daily Wages : RS ";
        cin>>Dwages;
    }

    void dispInfo() {
        Typist::dispInfo();
        cout << "- Casual" << endl
             << "Daily Wages: " << Dwages << " RS/-" << endl << endl;
    }
};

int main() {
    int nt, np, ntr, ntc;
    cout << "Enter the number of teachers: ";
    cin >> nt;
    cout << "Enter the number of officers: ";
    cin >> np;
    cout << "Enter the number of regular typists: ";
    cin >> ntr;
    cout << "Enter the number of casual typists: ";
    cin >> ntc;

    Regular* R = new Regular[ntr];
    Casual* C = new Casual[ntc];
    Officer* O = new Officer[np];
    Teacher* T = new Teacher[nt];

    for (int i = 0; i < nt; i++) {
        cout << "\n\nEnter Teacher " << (i + 1) << " details:" << endl;
        T[i].readInfo();
    }

    for (int i = 0; i < ntr; i++) {
        cout << "\n\nEnter Regular Typist " << (i + 1) << " details:" << endl;
        R[i].readInfo();
    }

    for (int i = 0; i < ntc; i++) {
        cout << "\n\nEnter Casual Typist " << (i + 1) << " details:" << endl;
        C[i].readInfo();
    }

    for (int i = 0; i < np; i++) {
        cout << "\n\nEnter Officer " << (i + 1) << " details:" << endl;
        O[i].readInfo();
    }

    int choice;
    do {
    
        cout << "\n\nView details of /-" << endl
             << "1. Teachers" << endl
             << "2. Officers" << endl
             << "3. Typist" << endl
             << "0. Exit" << endl
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            for (int i = 0; i < nt; i++) {
                cout << "\nTeacher " << (i + 1)<<endl;
                T[i].dispInfo();
            }
            break;
        }
        case 2: {
            for (int i = 0; i < np; i++) {
                cout << "\nOfficer " << (i + 1)<<endl;
                O[i].dispInfo();
            }
            break;
        }
        case 3: {
            cout << "\n1. Regular" << endl
                 << "2. Casual" << endl
                 << "Select: ";
            int sel;
            cin >> sel;

            switch (sel) {
            case 1: {
                for (int i = 0; i < ntr; i++) {
                    cout << "\nRegular Typist " << (i + 1)<<endl;
                    R[i].dispInfo();
                }
                break;
            }
            case 2: {
                for (int i = 0; i < ntc; i++) {
                    cout << "\nCasual Typist " << (i + 1)<<endl;
                    C[i].dispInfo();
                }
                break;
            }
            default: {
                cout << "Invalid Selection!" << endl;
            }
            }
            break;
        }
        case 0: {
            exit(0);
        }
        default: {
            cout << "Invalid Choice!" << endl;
        }
        }
    } while (choice != 0);

    delete[] T;
    delete[] R;
    delete[] C;
    delete[] O;

    return 0;
}
