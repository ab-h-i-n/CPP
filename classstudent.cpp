#include<iostream>
using namespace std;

 class student{

    int admno;
    char name[20];
    float eng,maths,science,total;
    float ctotal(){

            if(eng<40 || maths<40 || science<40){
                return 0;
            }else{
                return eng+maths+science;
            }
        }

    public:

        float check(string sub,float mark){

            cout<<endl<<sub<<" : ";
            cin>>mark;
            if(mark > 100 || mark < 0){
                cout<<"Mark should be between 100 and 0 !.......Re-Enter !";
                return 0;
            }else{
                return mark;
            }
        }

        void Takedata(){
            cout<<"\nEnter admno : ";
            cin>>admno;
            cout<<"\nEnter name : ";
            cin>>name;
            cout<<"\nEnter the marks of :\n";

            do{eng = check("English",eng);}while(eng == 0);
            do{maths = check("Maths",maths);}while(maths == 0);
            do{science = check("Science",science);}while(science == 0);

            
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
                if(total == 0){
                    cout<<"You failed the examination!"<<endl;
                }else{
                    cout<<"You Passed the examination!"<<endl;
                }
                
        }

 };

 int main(){

    student s1;

    s1.Takedata();
    cout<<"\n\nDetails of Student";
    s1.Showdata();
 
 }