#include<iostream>
using namespace std;

void deleteElement(int a[], int& n) {
    int x, i, j;
    cout << "\nEnter the element you want to delete: ";
    cin >> x;

    bool found = false;

    for (i = 0, j = 0; i < n; i++) {
        if (a[i] != x) {
            a[j] = a[i];
            j++;
        } else {
            found = true;
        }
    }

    if (found) {
        cout << "\nNew array after deletion:\n";
        for (i = 0; i < j; i++) {
            cout << a[i] << "\t";
        }
        n = j;
    } else {
        cout << "\nThe element is not found in the array.\n";
    }

    char choice;
    cout << "\nDo you want to delete another element? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        deleteElement(a, n);
    } else if (choice == 'N' || choice == 'n') {
        return;
    } else {
        cout << "\nInvalid choice. Please try again.\n";
        deleteElement(a, n);
    }
}

int main() {
    int n, i;
    cout << "How many elements do you want to enter: ";
    cin >> n;
    
    int a[n];
    cout << "\nEnter the elements of the array: ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    deleteElement(a, n);
    
    return 0;
}
