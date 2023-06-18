/*32.Create two classes DM and DB, which store the value of distances. DM stores distances in
meters and centimeters and DB in feet and inches. Write a program that can read values for
the class objects and add one object of DM with another object of DB. Use a friend function
to carry out addition operation. The object that stores the result may be a DM object or DB
object, depending on the units in which the results are required. The display should be in
the format of feet and inches or meters and centimeters depending on the object on display.*/


#include <iostream>
using namespace std;

class DB;

class DM {
    int meters;
    int centimeters;

public:
    DM() : meters(0), centimeters(0) {}

    void readData() {
        cout << "Enter distance in meters: ";
        cin >> meters;
        cout << "Enter distance in centimeters: ";
        cin >> centimeters;
    }

    void displayData() const {
        cout << "Distance: " << meters << " meters, " << centimeters << " centimeters" << endl;
    }

    friend DM addDistance(const DM& dm, const DB& db);
};

class DB {
    int feet;
    int inches;

public:
    DB() : feet(0), inches(0) {}

    void readData() {
        cout << "Enter distance in feet: ";
        cin >> feet;
        cout << "Enter distance in inches: ";
        cin >> inches;
    }

    void displayData() const {
        cout << "Distance: " << feet << " feet, " << inches << " inches" << endl;
    }

    friend DM addDistance(const DM& dm, const DB& db);
};

DM addDistance(const DM& dm, const DB& db) {
    DM result;
    int totalCentimeters = dm.meters * 100 + dm.centimeters + (db.feet * 12 + db.inches) * 2.54;
    result.meters = totalCentimeters / 100;
    result.centimeters = totalCentimeters % 100;
    return result;
}

int main() {
    DM dm;
    DB db;

    cout << "Enter distance in meters and centimeters:-"<< endl<<endl;
    dm.readData();

    cout << "\n\nEnter distance in feet and inches:-"<<endl<< endl;
    db.readData();

    DM result = addDistance(dm, db);

    cout << "Result: ";
    result.displayData();

    return 0;
}
