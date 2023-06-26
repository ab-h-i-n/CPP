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
        }else{
            cout<<"Service charge not applied"<<endl;
        }
    }
};

int main() {
    string savingsAccountNumber;
    double savingsInitialBalance, savingsInterestRate;
    cout << "Enter Savings Account Number: ";
    cin >> savingsAccountNumber;
    cout << "Enter Initial Balance for Savings Account: ";
    cin >> savingsInitialBalance;
    cout << "Enter Interest Rate for Savings Account: ";
    cin >> savingsInterestRate;
    SavingsAccount savings(savingsAccountNumber, savingsInitialBalance, savingsInterestRate);

    string currentAccountNumber;
    double currentInitialBalance, currentMinimumBalance, currentServiceCharge;
    cout << "Enter Current Account Number: ";
    cin >> currentAccountNumber;
    cout << "Enter Initial Balance for Current Account: ";
    cin >> currentInitialBalance;
    cout << "Enter Minimum Balance for Current Account: ";
    cin >> currentMinimumBalance;
    cout << "Enter Service Charge for Current Account: ";
    cin >> currentServiceCharge;
    CurrentAccount current(currentAccountNumber, currentInitialBalance, currentMinimumBalance, currentServiceCharge);

    int choice;
    double amount;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Deposit to Savings Account" << endl;
        cout << "2. Withdraw from Savings Account" << endl;
        cout << "3. Display Savings Account Balance" << endl;
        cout << "4. Apply Compound Interest to Savings Account" << endl;

        cout << "5. Deposit to Current Account" << endl;
        cout << "6. Withdraw from Current Account" << endl;
        cout << "7. Display Current Account Balance" << endl;
        cout << "8. Check Minimum Balance and Apply Service Charge" << endl;
        cout << "9. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


    switch (choice) {
    case 1: // Deposit to Savings Account
        cout << "Enter amount to deposit: ";
        cin >> amount;
        savings.deposit(amount);
        break;

    case 2: // Withdraw from Savings Account
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        savings.withdraw(amount);
        break;

    case 3: // Display Savings Account Balance
        savings.displayBalance();
        break;

    case 4: // Apply Compound Interest to Savings Account
        savings.applyCompoundInterest();
        break;

    case 5: // Deposit to Current Account
        cout << "Enter amount to deposit: ";
        cin >> amount;
        current.deposit(amount);
        break;

    case 6: // Withdraw from Current Account
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        current.withdraw(amount);
        break;

    case 7: // Display Current Account Balance
        current.displayBalance();
        break;

    case 8: // Check Minimum Balance and Apply Service Charge
        current.checkMinimumBalance();
        break;

    case 9: // Quit
        cout << "Exiting program..." << endl;
        return 0;

    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
}

}
   return 0;
}

