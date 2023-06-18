/*34.Write a C++ program to count the number of persons inside a bank, by increasing count
whenever a person enters a bank, using an increment (++) operator overloading function,
and decrease the count whenever a person leaves the bank using a decrement(--) operator
overloading function inside a class*/

#include<iostream>
using namespace std;

class Bank{

int count;

public:

    Bank():count(0){}

    void operator++(){
        count++;
    }

    void operator--(){
        count--;
    }

    int getCount(){
        return count;
    }

};

int main(){

    Bank person;
    int sel;

    do{

        cout<<"\nNumber of Person inside bank : "<<person.getCount()<<endl<<endl
            <<"1.Enter Bank"<<endl
            <<"2.Leave Bank"<<endl
            <<"0.Exit"<<endl
            <<"Select : ";
        cin>>sel;

        switch(sel){

            case 0 :{
                exit(0);
                break;
            }
            case 1 : {
                ++person;
                break;
            }
            case 2:{
                int count = person.getCount();
                if(count > 0){
                    --person;
                }else{
                    cout<<"\nThere are 0 persons inside the bank to leave!"<<endl;
                }
                break;
            }
            default:{
                cout<<"Invalid Selection!"<<endl;
            }
        }

    }while(sel!=0);

    return 0;
}