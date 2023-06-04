#include <iostream>
#include <string>
using namespace std;

class Salary {
protected:
    double hra;
    double cca;
    double bp;
    double total;

public:
    Salary() {}

    void calculateTotal() {
        double da = 0.3 * bp;
        hra = 0.1 * bp;
        cca = 200;
        total = 12 * (bp + da + hra + cca);
    }

    void display() {
        cout << "Basic Pay: " << bp << endl;
        cout << "HRA: " << hra << endl;
        cout << "DA: " << 0.3 * bp << endl;
        cout << "CCA: " << cca << endl;
        cout << "Total: " << total << endl;
    }

    void acceptData() {
        cout << "Enter Basic Pay: ";
        cin >> bp;
    }
};

class Tax {
protected:
    string name;

public:
    Tax() {}

    void acceptData() {
        cout << "Enter Name: ";
        cin >> name;
    }

    void display() {
        cout << "Name: " << name << endl;
    }

    string getName() const {
        return name;
    }
};

class Income_tax : public Salary, public Tax {
public:
    void calculateTax() {
        double yearlyIncome = total;
        double taxRate = 0.0;

        if (yearlyIncome > 60000 && yearlyIncome <= 80000) {
            taxRate = 0.2;
        } else if (yearlyIncome > 80000 && yearlyIncome <= 100000) {
            taxRate = 0.3;
        } else if (yearlyIncome > 100000) {
            taxRate = 0.4;
        }

        double incomeTax = taxRate * yearlyIncome;
        cout << "Income Tax: " << incomeTax << endl;
    }
};

int main() {
    Income_tax records[100];
    int count = 0;
    int choice;

    do {
        cout << "1. Add Record" << endl;
        cout << "2. Modify Record" << endl;
        cout << "3. Delete Record" << endl;
        cout << "4. Search Records" << endl;
        cout << "5. Display Record" << endl;
        cout << "6. Calculate Tax" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                if (count < 100) {
                    records[count].Salary::acceptData();
                    records[count].Tax::acceptData();
                    records[count].calculateTotal();
                    count++;
                } else {
                    cout << "Array is full. Cannot add more records." << endl;
                }
                break;
            }
            case 2: {
                int index;
                cout << "Enter the index of the record to modify: ";
                cin >> index;
                if (index >= 0 && index < count) {
                    records[index].Salary::acceptData();
                    records[index].calculateTotal();
                } else {
                    cout << "Invalid index. No record found." << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "Enter the index of the record to delete: ";
                cin >> index;
                if (index >= 0 && index < count) {
                    for (int i = index; i < count - 1; i++) {
                        records[i] = records[i + 1];
                    }
                    count--;
                    cout << "Record deleted." << endl;
                } else {
                    cout << "Invalid index. No record found." << endl;
                }
                break;
            }
            case 4: {
                string searchName;
                cout << "Enter the name to search for: ";
                cin >> searchName;

                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (records[i].Tax::getName() == searchName) {
                        records[i].Salary::display();
                        found = true;
                    }
                }

                if (!found) {
                    cout << "No record found with the given name." << endl;
                }
                break;
            }
            case 5: {
                for (int i = 0; i < count; i++) {
                    records[i].Salary::display();
                }
                break;
            }
            case 6: {
                int index;
                cout << "Enter the index of the record to calculate tax: ";
                cin >> index;
                if (index >= 0 && index < count) {
                    records[index].calculateTax();
                } else {
                    cout << "Invalid index. No record found." << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}
