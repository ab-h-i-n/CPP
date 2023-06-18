#include <iostream>
using namespace std;

class PersonalInfo {
    string name;
    string dob;
    string bldgrp;

public:
    void dispInfo() {
        cout << "\n\nPersonal Details:-" << endl
             << "Name: " << name << endl
             << "Date Of Birth: " << dob << endl
             << "Blood Group: " << bldgrp<<endl;
    }

    void inpInfo() {
        cout << "Enter details:" << endl;
        cout << "Name: ";
        getline(cin, name);
        cout << "Date Of Birth: ";
        getline(cin, dob);
        cout << "Blood Group: ";
        getline(cin, bldgrp);
    }
};

class PhysicalInfo {
    double height;
    double weight;

public:
    void dispInfo() {
        cout << "Height: " << height << endl
             << "Weight: " << weight<<endl;
    }

    void inpInfo() {
        cout << "Height: ";
        cin >> height;
        cout << "Weight: ";
        cin >> weight;
    }
};

class PolicyInfo {
    string address;
    string policyNo;

public:
    void dispInfo() {
        cout << "Contact Address: " << address << endl
             << "Policy Number: " << policyNo<<endl;
    }

    void inpInfo() {
        cout << "Contact Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Policy Number: ";
        cin.ignore();
        getline(cin, policyNo);
    }
};

class PersonalDB : public PersonalInfo, public PhysicalInfo, public PolicyInfo {
    string phoneNumber;
    string panId;

public:
    void dispInfo() {
        PersonalInfo::dispInfo();
        PhysicalInfo::dispInfo();
        PolicyInfo::dispInfo();
        cout << "Phone Number: " << phoneNumber << endl
             << "PAN ID: " << panId << endl;
    }

    void inpInfo() {
        PersonalInfo::inpInfo();
        PhysicalInfo::inpInfo();
        PolicyInfo::inpInfo();
        cout << "Phone Number: ";
        cin >> phoneNumber;
        cout << "PAN ID: ";
        cin>>panId;
    }
};

int main() {
    PersonalDB pdb;
    
    pdb.inpInfo();
    pdb.dispInfo();

    return 0;
}
