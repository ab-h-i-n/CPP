#include <iostream>
using namespace std;

class Staff {
protected:
    string name;
    int eID;

public:
    Staff() : name(""), eID(0) {}
    Staff(const string& name, int eID) : name(name), eID(eID) {}

    void dispInfo() {
        cout << "Employee ID : " << eID << endl
             << "Employee Name : " << name << endl;
    }
};

class Teacher : public Staff {
    string sub;

public:
    Teacher() : Staff(), sub("") {}
    Teacher(const string& name, int eID, const string& sub) : Staff(name, eID), sub(sub) {}

    void dispInfo() {
        Staff::dispInfo();
        cout << "Employee Type : Teacher" << endl
             << "Subject : " << sub << endl << endl;
    }
};

class Typist : public Staff {
protected:
    int typSpeed;

public:
    Typist() : Staff(), typSpeed(0) {}
    Typist(const string& name, int eID, int typSpeed) : Staff(name, eID), typSpeed(typSpeed) {}

    void dispInfo() {
        Staff::dispInfo();
        cout << "Typing Speed : " << typSpeed << endl
             << "Employee Type : Typist";
    }
};

class Officer : public Staff {
    string pos;

public:
    Officer() : Staff(), pos("") {}
    Officer(const string& name, int eID, const string& pos) : Staff(name, eID), pos(pos) {}

    void dispInfo() {
        Staff::dispInfo();
        cout << "Employee Type : Officer" << endl
             << "Position : " << pos << endl << endl;
    }
};

class Regular : protected Typist {
public:
    Regular() : Typist() {}
    Regular(const string& name, int eID, int typSpeed) : Typist(name, eID, typSpeed) {}

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

    void dispInfo() {
        Typist::dispInfo();
        cout << "- Casual" << endl
             << "Daily Wages : " << Dwages << " RS/-" << endl << endl;
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
        string name, subject;
        int eID;
        cout << "Enter Teacher " << (i + 1) << " details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Employee ID: ";
        cin >> eID;
        cout << "Subject: ";
        cin.ignore();
        getline(cin, subject);
        T[i] = Teacher(name, eID, subject);
    }

    for (int i = 0; i < ntr; i++) {
        string name;
        int eID, typSpeed;
        cout << "Enter Regular Typist " << (i + 1) << " details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Employee ID: ";
        cin >> eID;
        cout << "Typing Speed: ";
        cin >> typSpeed;
        R[i] = Regular(name, eID, typSpeed);
    }

    for (int i = 0; i < ntc; i++) {
        string name;
        int eID, typSpeed;
        float Dwages;
        cout << "Enter Casual Typist " << (i + 1) << " details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Employee ID: ";
        cin >> eID;
        cout << "Typing Speed: ";
        cin >> typSpeed;
        cout << "Daily Wages: ";
        cin >> Dwages;
        C[i] = Casual(name, eID, typSpeed, Dwages);
    }

    for (int i = 0; i < np; i++) {
        string name, position;
        int eID;
        cout << "Enter Officer " << (i + 1) << " details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Employee ID: ";
        cin >> eID;
        cout << "Position: ";
        cin.ignore();
        getline(cin, position);
        O[i] = Officer(name, eID, position);
    }

    int choice;
    do {
        cout << "View details of /-" << endl
            << "1. Teachers" << endl
            << "2. Officers" << endl
            << "3. Typist" << endl
            << "0. Exit" << endl
            << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            for (int i = 0; i < nt; i++) {
                cout << "\nTeacher " << (i + 1);
                T[i].dispInfo();
            }
            break;
        }
        case 2: {
            for (int i = 0; i < np; i++) {
                cout << "\nOfficer " << (i + 1);
                O[i].dispInfo();
            }
            break;
        }
        case 3: {
            cout << "1. Regular" << endl
                << "2. Casual" << endl
                << "Select: ";
            int sel;
            cin >> sel;

            switch (sel) {
            case 1: {
                for (int i = 0; i < ntr; i++) {
                    cout << "\nRegular Typist " << (i + 1);
                    R[i].dispInfo();
                }
                break;
            }
            case 2: {
                for (int i = 0; i < ntc; i++) {
                    cout << "\nCasual Typist " << (i + 1);
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
