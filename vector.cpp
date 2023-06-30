#include <iostream>
using namespace std;

class Vector {
    float values[10];
    int size;

public:
    Vector(){}
    Vector(int s){
        size = s;
    }

    void createVector() {
        
        cout <<"Enter the values for the vector :- " << endl;
        for (int i = 0; i < size; i++) {
            cout << "Enter value " << i + 1 << ": ";
            cin >>values[i];
        }
    }

    void displayVector(){
        cout << "(";
        for (int i = 0; i < size; i++) {
            cout << int(values[i]);
            if (i != size - 1)
                cout << ", ";
        }
        cout << ")" << endl;
    }

    Vector operator*(float scalar){

        Vector result(size);

        for (int i = 0; i < size; i++) {
            result.values[i] = values[i] * scalar;
        }
        return result;
    }

   friend Vector operator+(Vector v1 , Vector v2);
};

Vector operator+(Vector v1, Vector v2){

    int size = v1.size;
    Vector result(size);

    for (int i = 0; i < size; i++) {
        result.values[i] = v1.values[i] + v2.values[i];
    }
    return result;
}


int main() {
    int size;

    cout <<"Enter the size of the vectors: ";
    cin >> size;
    if(size > 10 || size < 0){
        cout<<"\nSize must be between 0 and 10 !...\n"<<endl;
        main();
    }
    Vector v1(size), v2(size), v3(size);

    cout <<endl<<"Creating Vector 1"<< endl;
    v1.createVector();

    cout <<endl<<"Creating Vector 2"<< endl;
    v2.createVector();

    cout<<endl<<"Vector 1: ";
    v1.displayVector();
    cout<<"Vector 2: ";
    v2.displayVector();

    int choice;
    float scalar;

    do{
        cout<<endl<<"1.Show sum of both vectors"<<endl
            <<"2.Multiply vector 1 by scalar value"<<endl
            <<"3.Multiply vector 2 by scalar value"<<endl
            <<"4.Exit"<<endl
            <<endl<<"Enter your choice : ";

        cin>>choice;

        switch(choice){

            case 1 :v3 = v1 + v2;
                    cout <<endl<<"Sum of Vector 1 and Vector 2: ";
                    v3.displayVector();
                    break;

            case 2 :cout<<endl<<"Enter a scalar value: ";
                    cin >>scalar;
                    v1 = v1 * scalar;
                    cout << "Vector 1 multiplied by "<<scalar<<": ";
                    v1.displayVector();
                    break;

            case 3 :cout<<endl<<"Enter a scalar value: ";
                    cin >> scalar;
                    v2 = v2 * scalar;
                    cout << "Vector 2 multiplied by "<<scalar<<": ";
                    v2.displayVector();
                    break;
            
            case 4 :cout<<endl<<"Exiting..........."<<endl;
                    break;

            default:cout<<endl<<"Invalid choice.......Try again.........."<<endl;
                    break;
        }

    }while(choice != 4);
    return 0;
}
