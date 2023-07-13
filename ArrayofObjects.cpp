#include<iostream>
#define SIZE 10
using namespace std;

class employee{
    char name[30];
    float age;
public:
    void getdata();
    void putdata();
};

void employee::getdata(){

    cout<<"Enter name : ";
    cin>>name;
    cout<<"Enter age : ";
    cin>>age;
}

void employee::putdata(){
    
    cout<<"Name : "<<name<<endl
        <<"Age : "<<age<<endl;
}

int main(){
    int size;
    do{
    cout<<"Enter number of managers : ";
    cin>>size;
    if(size > SIZE){
        cout<<"\nSize must be less than "<<SIZE<<"!....Re Enter the size ! \n\n";
    }
    }while(size > SIZE);
    employee manager[size];

    for(int i=0;i<size;i++){
        cout<<"\nManager "<<i+1<<endl;
        manager[i].getdata();
    }

    cout<<"...................Manager Details......................\n";
    for(int i=0;i<size;i++){
        cout<<"\nManager "<<i+1<<" :-"<<endl;
        manager[i].putdata();
    }
    return 0;
}