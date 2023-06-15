// #include <iostream>
// using namespace std;

// void deleteElement(int a[], int& n) {
//     int x, i, j;
//     cout << "\nEnter the element you want to delete: ";
//     cin >> x;

//     bool found = false;

//     for (i = 0, j = 0; i < n; i++) {
//         if (a[i] != x) {
//             a[j] = a[i];
//             j++;
//         } else {
//             found = true;
//         }
//     }

//     if (found) {
//         cout << "\nNew array after deletion:\n";
//         for (i = 0; i < j; i++) {
//             cout << a[i] << "\t";
//         }
//         n = j;
//     } else {
//         if (n != 0) {
//             cout << "\nThe element is not found in the array.\n";
//         } else {
//             cout << "\nArray is empty.\n";
//             exit(0);
//         }
//     }

//     char choice;
//     cout << "\nDo you want to delete another element? (Y/N): ";
//     cin >> choice;

//     if (choice == 'Y' || choice == 'y') {
//         deleteElement(a, n);
//     } else if (choice == 'N' || choice == 'n') {
//         return;
//     } else {
//         cout << "\nInvalid choice. Please try again.\n";
//         deleteElement(a, n);
//     }
// }

// int main() {
//     int n, i;
//     cout << "How many elements do you want to enter: ";
//     cin >> n;

//     int* a = new int[n];
//     cout << "\nEnter the elements of the array: ";
//     for (i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     deleteElement(a, n);

//     delete[] a;  // Free the dynamically allocated memory

//     return 0;
// }


#include <iostream>
using namespace std;

void deleteElement(int a[], int& n) {

    int x, i, j, choice;
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
        cout << "\nNew array is ";
        n = j;
        if(n!=0){
            cout<<endl;
            for (i = 0; i < j; i++)
                cout << a[i] << "\t";
        }
        else{
            cout<<"empty"<<endl;
            return;
        }
    } else {
        cout << "\nThe element is not found in the array.\n";
    }

    do{

    cout << "\nDo you want to delete another element?\n"
         << "1. Yes\n"
         << "2. No\n"
         << "Enter your choice: ";
    cin >> choice;

    switch(choice){
        case 1 : deleteElement(a,n); break;
        case 2 : return; break;
        default : cout<<"\nInvalid choice....Try again....\n";break;
    }

    }while(choice!=2);
}

int main() {
    int n, i;
    cout << "\nHow many elements do you want to enter: ";
    cin >> n;

    int a[n];
    cout << "\nEnter the elements of the array: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    deleteElement(a, n);

    return 0;
}
