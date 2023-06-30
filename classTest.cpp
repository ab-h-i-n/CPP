/*35.Define a class TEST in C++ with following description:
Private Members
TestCode of type integer
Description of type string
NoCandidate of type integer
CenterReqd (number of centers required) of type integer
A member function CALCNTR() to calculate and return the number of centers as
(NoCandidates/100+1)
Public Members
- A function SCHEDULE() to allow user to enter values for TestCode, Description,
NoCandidate & call function CALCNTR() to calculate the number of Centres
- A function DISPTEST() to allow user to view the content of all the data members*/

#include<iostream>
#include<cstring>
using namespace std;

class Test{

int tCode;
string Desc;
int noCand;
int CentReq;

int CALCNTR(){
    return ((noCand/100)+1);
}

public: 

    void SCHEDULE(){
        cout<<"\t-: Enter the details :-"<<endl<<endl;
        cout<<"Test Code : ";
        cin>>tCode;
        cout<<"Description : ";
        cin.ignore(); // Ignore the newline character left in the input stream
        getline(cin,Desc);
        cout<<"Number of Candidates required : ";
        cin>>noCand;
        CentReq  = CALCNTR();
    }

    void DISPTEST(){
        cout<<"\n\n\t-: Details :-"<<endl<<endl
            <<"Test Code : "<<tCode<<endl
            <<"Description : "<<Desc<<endl
            <<"Number of Candidates : "<<noCand<<endl
            <<"Number of Centers Required : "<<CentReq<<endl<<endl;
    }

};

int main(){

    Test test;

    test.SCHEDULE();
    test.DISPTEST();

    return 0;
}