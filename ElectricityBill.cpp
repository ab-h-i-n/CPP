/*41. An electricity board charges the following rates to domestic users todiscourage large
conceptions of energy.
100 units Rs 1.50 p/unit
200 units Rs 1.80 p/unit
Beyond 200 Rs 2.50 p/unit
All users are charged a minimum of Rs 50/-. If the total amount is more than 300
then an additional surcharge of 15% is added. Write a C++ program to read the names of
users, number of units consumed and print out the charge using minimum charge as Default
Argument and class.*/

#include <iostream>
#include <string>

using namespace std;

class ElectricityBill {
private:
    string userName;
    int unitsConsumed;

public:
    ElectricityBill(string name, int units) {
        userName = name;
        unitsConsumed = units;
    }

    float calculateCharge() {
        float charge = 0.0;
        
        if (unitsConsumed <= 100) {
            charge = unitsConsumed * 1.50;
        } else if (unitsConsumed <= 200) {
            charge = unitsConsumed * 1.80;
        } else {
            charge = unitsConsumed * 2.50;
        }
        
        if (charge < 50.0) {
            charge = 50.0;
        }
        
        if (charge > 300) {
            charge += charge * 0.15;
        }
        
        return charge;
    }

    void displayBill() {
        cout << endl<<"User Name: " << userName << endl;
        cout << "Units Consumed: " << unitsConsumed << endl;
        cout << "Charge: Rs " << calculateCharge() << endl;
    }
};

int main() {
    string name;
    int units;

    cout << "Enter user name: ";
    getline(cin, name);

    cout << "Enter units consumed: ";
    cin >> units;

    ElectricityBill bill(name, units);
    bill.displayBill();

    return 0;
}
