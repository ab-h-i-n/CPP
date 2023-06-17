#include <iostream>
using namespace std;

class Staff {
protected:
    string name;
    int eID;

public:
    Staff(const string& name, int eID) : name(name), eID(eID) {}

    void dispInfo() {
        cout << "Employee ID : " << eID << endl
            << "Employee Name : " << name << endl;
    }
};

class Teacher : public Staff {
    string sub;

public:
    Teacher(const string& name, int eID, const string& sub) : Staff(name, eID), sub(sub) {}

    void dispInfo() {
        Staff::dispInfo();
        cout << "Employee Type : Teacher" << endl;
        cout << "Subject : " << sub << endl << endl;
    }
};

class Typist : public Staff {
protected:
    int typSpeed;

public:
    Typist(const string& name, int eID, int typSpeed) : Staff(name, eID), typSpeed(typSpeed) {}

    void dispInfo() {
        Staff::dispInfo();
        cout << "Typing Speed : " << typSpeed << endl;
        cout << "Employee Type : Typist";
    }
};

class Officer : public Staff {
    string pos;

public:
    Officer(const string& name, int eID, const string& pos) : Staff(name, eID), pos(pos) {}

    void dispInfo() {
        Staff::dispInfo();
        cout << "Employee Type : Officer" << endl;
        cout << "Position : " << pos << endl << endl;
    }
};

class Regular : protected Typist {
public:
    Regular(const string& name, int eID, int typSpeed) : Typist(name, eID, typSpeed) {}

    void dispInfo() {
        Typist::dispInfo();
        cout << "- Regular" << endl << endl;
    }
};

class Casual : protected Typist {
    float Dwages;

public:
    Casual(const string& name, int eID, int typSpeed, float Dwages)
        : Typist(name, eID, typSpeed), Dwages(Dwages) {}

    void dispInfo() {
        Typist::dispInfo();
        cout << "- Casual" << endl;
        cout << "Daily Wages : " << Dwages <<" RS/-"<< endl << endl;
    }
};

int main() {
    Teacher T1("Naruto", 1, "C++");
    Regular R1("Saske", 2, 80);
    Casual C1("Itachi", 3, 90, 2000);
    Officer O1("Light", 4, "Vice Chairman");

    T1.dispInfo();
    R1.dispInfo();
    C1.dispInfo();
    O1.dispInfo();

    return 0;
}
