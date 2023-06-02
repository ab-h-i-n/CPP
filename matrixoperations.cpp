#include<iostream>
using namespace std;

class Matrix{
    int rows, columns;
    int A[100][100];
public:

    Matrix() {}
    Matrix(int r, int c) {
        rows = r;
        columns = c;
    }

    void readMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cin >> A[i][j];
            }
        }
    }

    void displayMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << "\t" << A[i][j];
            }
            cout << endl;
        }
    }

    Matrix operator+ (Matrix b) {
        Matrix temp(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                temp.A[i][j] = A[i][j] + b.A[i][j];
            }
        }
        return temp;
    }

    Matrix operator- (Matrix b) {
        Matrix temp(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                temp.A[i][j] = A[i][j] - b.A[i][j];
            }
        }
        return temp;
    }

    friend Matrix operator* (Matrix a , Matrix b);
};

Matrix operator* (Matrix a,Matrix b) {
            Matrix temp(a.rows, b.columns);
            for (int i = 0; i < a.rows; i++) {
                for (int j = 0; j < b.columns; j++) {
                    temp.A[i][j] = 0;
                    for (int k = 0; k < a.columns; k++) {
                        temp.A[i][j] += a.A[i][k] * b.A[k][j];
                    }
                }
            }
            return temp;
    }

int main() {

    int m, n;

    cout << "Enter the order of the matrix 1: ";
    cin >> m >> n;
    Matrix m1(m, n);
    Matrix m2(m, n);

    cout << "\nEnter the elements of matrix 1: ";
    m1.readMatrix();

    cout << "\nEnter the elements of matrix 2: ";
    m2.readMatrix();

    cout << "\n\tMatrix 1\n";
    m1.displayMatrix();
    cout << endl << endl;
    cout << "\n\tMatrix 2\n";
    m2.displayMatrix();

    int choice;
    Matrix m3;
    do {
        cout << "\n\n.....Matrix Operations....." << endl
            << "1. Addition" << endl
            << "2. Subtraction" << endl
            << "3. Multiplication" << endl
            << "4. Exit" << endl
            << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            m3 = m1 + m2;
            cout<<"\n\nAddition of two matrices: \n";
            m3.displayMatrix();
            break;
        case 2:
            m3 = m1 - m2;
            cout<<"\n\nSubtraction of two matrices: \n";
            m3.displayMatrix();
            break;
        case 3:
            m3 = m1 * m2;
            cout<<"\n\nMultiplication of two matrices: \n";
            m3.displayMatrix();
            break;
        case 4:
            cout << "\nExiting.........";
            break;
        default:
            cout << "\nInvalid Choice.....Try again....\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
