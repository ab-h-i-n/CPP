#include<iostream>
using namespace std;
 class student{

    int admno;
    char name[20];
    float eng,maths,science,total;
    float ctotal(){
            return eng + maths + science;
        }

    public:

        void Takedata(){
            cout<<"\nEnter admno : ";
            cin>>admno;
            cout<<"\nEnter name : ";
            cin>>name;
            cout<<"\nEnter the marks of :\n";
            cout<<"\n\tEnglish : ";
            cin>>eng;
            cout<<"\n\tMaths : ";
            cin>>maths;
            cout<<"\n\tScience : ";
            cin>>science;

            total = ctotal();
        }
        
        void Showdata(){
            cout<<endl<<endl
                <<"Admno : "<<admno<<endl
                <<"Name : "<<name<<endl
                <<"English : "<<eng<<endl
                <<"Maths : "<<maths<<endl
                <<"Science : "<<science<<endl
                <<"Total : "<<total<<endl<<endl;
        }

 };

 int main(){

    student s1;

    s1.Takedata();
    cout<<"\n\nDetails of Students";
    s1.Showdata();
 
 }