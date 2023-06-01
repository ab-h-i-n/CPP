#include<iostream>
using namespace std;

inline int Square(int n){
    return n*n;
}

int main(){
    int a;
    cout<<"\nEnter the number : ";
    cin>>a;
    cout<<"\nSquare of the number is : "<<Square(a)<<endl;

    return 0;
}