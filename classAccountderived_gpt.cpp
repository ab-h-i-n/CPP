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
    virtual void withdraw() = 0;
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

    void withdraw()
    {   double amount;
        if (balance > 0) {
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            if(balance >= amount){
                balance -= amount;
                cout <<endl<< "Withdrawal of " << amount << " successful." <<endl<<endl;
            }else{
                cout<<"Insufficient balance."<<endl;
            }
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

    void withdraw()
    {   double amount;
        if (balance > 0) {
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            if(balance >= amount){
                balance -= amount;
                cout <<endl<< "Withdrawal of " << amount << " successful." <<endl<<endl;
                checkMinimumBalance();
            }else{
                cout<<"Insufficient balance."<<endl;
            }
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
void displayMenu() {
    cout << "Welcome to the Bank!" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Current Account" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double amount;
    string savingsAccountNumber, currentAccountNumber;
    double savingsInitialBalance, savingsInterestRate = 2.3;
    double currentInitialBalance, currentMinimumBalance = 500, currentServiceCharge = 20;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter savings account number: ";
                cin >> savingsAccountNumber;

                cout << "Enter initial balance for savings account: ";
                cin >> savingsInitialBalance;

                SavingsAccount savings(savingsAccountNumber, savingsInitialBalance, savingsInterestRate);

                cout << endl << "..........Savings account.........." << endl;
                savings.displayBalance();
                do{
                    cout << "1. Deposit" << endl;
                    cout << "2. Withdraw" << endl;
                    cout << "3. Apply Compound Interest" << endl;
                    cout << "4. Go back to the main menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter the amount to deposit: ";
                            cin >> amount;
                            savings.deposit(amount);
                            savings.displayBalance();
                            break;
                        case 2:
                            savings.withdraw();
                            savings.displayBalance();
                            break;
                        case 3:
                            savings.applyCompoundInterest();
                            savings.displayBalance();
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            break;
                    }
                }while(choice != 4);

                break;
            }
            case 2: {
                cout << "Enter current account number: ";
                cin >> currentAccountNumber;

                cout << "Enter initial balance for current account: ";
                cin >> currentInitialBalance;

                CurrentAccount current(currentAccountNumber, currentInitialBalance, currentMinimumBalance, currentServiceCharge);

                cout << endl << "..........Current account.........." << endl;
                current.displayBalance();
                do{
                    cout << "1. Deposit" << endl;
                    cout << "2. Withdraw" << endl;
                    cout << "3. Check Balance" << endl;
                    cout << "4. Go back to the main menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            cout << "Enter the amount to deposit: ";
                            cin >> amount;
                            current.deposit(amount);
                            current.displayBalance();
                            break;
                        case 2:
                            current.withdraw();
                            current.displayBalance();
                            break;
                        case 3:
                            current.displayBalance();
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            break;
                    }
                }while(choice != 4);
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

    } while (choice != 3);

    return 0;
}
