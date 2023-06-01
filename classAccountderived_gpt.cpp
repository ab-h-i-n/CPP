#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayBalance()  = 0;
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& accNum, double initialBalance, double interest)
        : BankAccount(accNum, initialBalance), interestRate(interest) {}

    void deposit(double amount)
    {
        balance += amount;
        cout<<endl<<"Deposited "<<amount<<" succefully!"<<endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount) {
            balance -= amount;
            cout <<endl<< "Withdrawal of " << amount << " successful." <<endl<<endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void displayBalance() 
    {
        cout << "Savings Account Balance: " << balance << endl;
    }

    void applyCompoundInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Compound interest applied: " << interest << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    double minimumBalance;
    double serviceCharge;

public:
    CurrentAccount(const string& accNum, double initialBalance, double minBalance, double charge)
        : BankAccount(accNum, initialBalance), minimumBalance(minBalance), serviceCharge(charge) {}

    void deposit(double amount)
    {
        balance += amount;
        cout<<endl<<"Deposited "<<amount<<" succefully!"<<endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount) {
            balance -= amount;
            cout <<endl<< "Withdrawal of " << amount << " successful." <<endl<<endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void displayBalance()
    {
        cout << "Current Account Balance: " << balance << endl;
    }

    void checkMinimumBalance() {
        if (balance < minimumBalance) {
            balance -= serviceCharge;
            cout << "Service charge applied due to balance below minimum: " << serviceCharge << endl;
        }
    }
};

int main() {
    SavingsAccount savings("SA001", 5000.0, 0.05);
    CurrentAccount current("CA001", 10000.0, 5000.0, 100.0);


    cout<<endl<<"..........Savings account.........."<<endl;
    savings.displayBalance();
    savings.deposit(2000.0);
    savings.displayBalance();
    savings.withdraw(1500.0);
    savings.applyCompoundInterest();
    savings.displayBalance();

    cout<<endl<<"..........Current account.........."<<endl;
    current.displayBalance();
    current.deposit(5000.0);
    current.displayBalance();
    current.withdraw(10000.0);
    current.checkMinimumBalance();
    current.displayBalance();

    return 0;
}
