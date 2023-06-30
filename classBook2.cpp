#include<iostream>
using namespace std;

class Book{
    int bookNo;
    char bookTitle[20];
    float price;
    float totalCost(int n){
        return price*n;
    }

    public:
    
    void input(){

        cout<<"\nEnter the details :- \n";
        cout<<"\nBook Number : ";
        cin>>bookNo;
        cout<<"\nBook Title : ";
        cin>>bookTitle;
        cout<<"\nBook Price : ";
        cin>>price;
    }

    void purchase(){
        int n;
        cout<<"\nEnter the number of copies to be purchased : ";
        cin>>n;
        cout<<"\nTotal cost : "
            <<totalCost(n)<<"Rs/-"
            <<endl<<endl;
    }
};

int main(){
    Book b1;

    b1.input();
    b1.purchase();

    return 0;
}