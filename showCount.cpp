#include<iostream>
using namespace std;

class Obj{

    static int count;
     
public:

    Obj(){count++;}

    static int showCount(){
        return count;
    }
};

int Obj::count = 0;

int main(){

    
    Obj ob1 ,ob2 ,ob3;

    cout<<"Number of objects created is: "<<Obj::showCount()<<endl<<endl;

    return 0;
}