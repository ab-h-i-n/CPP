#include<iostream>
using namespace std;
int checkMark(float sub){

    if(sub > 100 || sub < 0){
        cout<<"Mark should be between 0 and 100!...Try again...\n";
        return 0;
    }//else{
    //     if(sub < 40){
    //         cout<<"\nYou failed the exam ! "<<endl;
    //         exit(0);
    //     }
    // }
    return 1;
}

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

            int check;
            cout<<"\nEnter the marks of :\n";

            do{
                cout<<"\n\tEnglish : ";
                cin>>eng;
                check = checkMark(eng);
            }while(check != 1);

            do{
                cout<<"\n\tMaths : ";
                cin>>maths;
                check = checkMark(maths);
            }while(check != 1);

            do{
                cout<<"\n\tScience : ";
                cin>>science;
                check = checkMark(science);
            }while(check != 1);

            
            total = ctotal();
        }
        
        void Showdata(){
            cout<<endl<<endl
                <<"Admno : "<<admno<<endl
                <<"Name : "<<name<<endl
                <<"English : "<<eng<<endl
                <<"Maths : "<<maths<<endl
                <<"Science : "<<science<<endl
                <<"Total : "<<total<<" / 300"<<endl<<endl
                <<"You Passed the exam !"<<endl<<endl;
                
        }

 };

 int main(){

    student s1;

    s1.Takedata();
    cout<<"\n\nDetails of Student";
    s1.Showdata();
 
 }