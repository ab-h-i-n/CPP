#include<iostream>
using namespace std;

class Account {

protected:
    string name;
    int accountNumber;
    double balance;
    string type;
    double interestRate = 0.05;

  public:
    Account(){}
    Account(string Name, int AccountNumber, string Type) {
      
      Name = name;
      AccountNumber = accountNumber;
      Type = type;

    }

    void getDetails(){
        cout<<"Name : "<<name
            <<"Account Number : "<<accountNumber
            <<"Type : "<<type
            <<"Balance : "<<getBalance()<<endl;
    }

    void deposit(double amount) {
      balance += amount;
    }

    double getBalance() {
      return balance;
    }

    void computeInterest() {
      balance += balance * interestRate;
    }

    void withdraw(double amount) {
      if (balance < amount) {
        cout << "Insufficient balance!" << endl;
        return;
      }

      balance -= amount;
    }
};



class cur_acct : public Account {

    double minimumBalance = 1000;
    double serviceCharge = 20;

public:

    cur_acct(string Name, int AccountNumber){

        Account(Name , AccountNumber , "Current account");
    }

    void withdraw(double amount) {
      if (balance - amount < minimumBalance) {
        balance -= amount + serviceCharge;
      } else {
        balance -= amount;
      }
    }
    
};


class sav_acct : public Account {

  public:
    sav_acct(string Name, int AccountNumber){

       Account(name , accountNumber , "Savings account");

    }

    void computeInterest() {
      Account::computeInterest();
      balance *= (1 + interestRate);
    }

};

int main(){

    string name;
    int accno;
    char type;

    cout<<endl<<"......Create Account....."<<endl;
    cout<<endl<<"Enter the details : -"<<endl;
    cout<<endl<<"Name : ";
    cin>>name;
    cout<<endl<<"Account Number : ";
    cin>>accno;
    cout<<endl<<"Which type of account ? ";

    do{

    cout<<endl<<"Type (C/S): ";
    cin>>type;

        if(type == 'C' || type == 'c'){

            cur_acct person(name , accno);
        }
        else if(type == 'S' || type == 's')
        {
            sav_acct person(name , accno);
        }
        else{
            cout<<endl<<"Invalid type";
        }
    }while(type != 'C' || type != 'c' || type != 'S' || type != 's');

    cout<<endl<<"1.Deposit"
        <<endl<<"2.Show Balance"
        <<endl<<"3.Withdraw"

}