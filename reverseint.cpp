#include<iostream>
using namespace std;

class number{

    int num;
    
    public:


        void getnum(){
            cout<<"Enter a integer : ";
            cin>>num;
        }
    
        int reverse(){
            int r ,rev =0;
            while(num!=0){
            r = num%10;
            rev = (rev*10)+r;
            num /=10;
            }
            return rev;
        }

};

int main(){
    number n;
    n.getnum();
    cout<<"\nReverse of the integer : "<<n.reverse()<<endl;
}