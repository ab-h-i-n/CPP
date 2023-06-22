/*36.Develop a C++ program to create a database of the personal information system containing
the following information Name, Date of Birth, Blood group, Policy No. , Height, weight,
Contact Address, Mobile No., pan id number etc. Design a base class with name, date of
birth, blood group and another base class consisting of the data member such as height and
weight design one more base class consist of policy number and contact address the derived
class contain the member of the mobile number and pan id number.*/

#include <iostream>
#include<string>
using namespace std;

class PersonalInfo {
    string name;
    string dob;
    string bldgrp;

public:

bool checkBldgrp() {

    if ((bldgrp == "A+" || bldgrp == "a+")||
    (bldgrp == "A-" || bldgrp == "a-")||
    (bldgrp == "B+" || bldgrp == "b+")||
    (bldgrp == "AB+"|| bldgrp == "ab+")||
    (bldgrp == "AB-"|| bldgrp == "ab-")||
    (bldgrp == "O+" || bldgrp == "o+")||
    (bldgrp == "O-" || bldgrp == "o-")){
        return true;
    }else {
        return false;
    }
}

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

        bool valid;
        do{

            cout << "Blood Group: ";
            getline(cin, bldgrp);
            valid = checkBldgrp();
            if(!valid)
                cout<<"Not an Valid Blood Group!..Re-Try!"<<endl;
        }while(!valid);
    }
};

class PhysicalInfo {
    double height;
    double weight;

public:

bool checkHeight(){

    if(height < 80){
        return false;
    }else if(height > 200){
        return false;
    }else{
        return true;
    }
}

bool checkWeight(){
    if(weight < 20){
        return false;
    }else if(weight > 300){
        return false;
    }else{
        return true;
    }
}
    void dispInfo() {
        cout << "Height: " << height << endl
             << "Weight: " << weight<<endl;
    }

    void inpInfo() {

        bool validH;

        do{
            cout << "Height(in Cm): ";
            cin >> height;
            validH = checkHeight();
            if(!validH)
                cout<<"Height should be between 80cm and 200cm !....Re-Try !"<<endl;
        }while(!validH);
    
        bool validW;

        do{
            cout << "Weight(in Kg): ";
            cin >> weight;
            validW = checkWeight();
            if(!validW)
                cout<<"Height should be between 20kg and 300kg....Re-Try!"<<endl;
        }while(!validW);
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

bool checktendigit(string value){

    int len = value.length();

    if(len == 10){
        return true;
    }else{
        return false;
    }
}

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

        bool validate;

        do{
            cout << "Phone Number(10 digit): +91 ";
            cin >> phoneNumber;
            validate = checktendigit(phoneNumber);
            if(!validate)
                cout<<"Not a valid 10 digit phone number....! Re-Enter ! "<<endl;
        }while(!validate);

        do{
            cout << "PAN ID(10 digit): ";
            cin>>panId;
            validate = checktendigit(panId);
            if(!validate)
                cout<<"Not a valid 10 digit PAN ID....! Re-Enter ! "<<endl;
        }while(!validate);
    }
};

int main() {
    PersonalDB pdb;
    
    pdb.inpInfo();
    pdb.dispInfo();

    return 0;
}
