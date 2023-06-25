/*42. Write a program for developing a matrix class which can handle integer matrices of different
dimensions. Also overload the operator for addition, multiplication & comparison of
matrices.*/

#include<iostream>
using namespace std;

class Matrix{
    int rows;
    int columns;
    int A[20][20];

public:

    Matrix():rows(0),columns(0){}

    int getRow(){return rows;}

    bool checkRC(int rows){
        if(rows > 20 || rows <= 0 )
            return false;
        else
            return true;
    }

    void getData(){

        bool valid = false;

        do{
            cout<<"Enter the number of rows: ";
            cin>>rows;
            valid = checkRC(rows);
            if(!valid){
                cout<<"Maximum rows allowed is 20!......Re-Try!"<<endl;
            }
        }while(!valid);

        do{
            cout<<"\nEnter the number of columns: ";
            cin>>columns;
            valid = checkRC(columns);
            if(!valid){
                cout<<"Maximum columns allowed is 20!......Re-Try!"<<endl;
            }
        }while(!valid);

        cout<<"Enter the elements:-\n";
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                cin>>A[i][j];
            }
        }
    }

    void disp(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                cout<<A[i][j]<<"\t";
            }
            cout<<endl;
        }
    }

    Matrix operator+(Matrix& m){

        if(m.rows != rows || m.columns != columns){
            cout<<"\nMatrix addition not possible ! , Order of the both matrix is not same !"<<endl;
            return Matrix();
        }

        Matrix temp;

        temp.columns = columns;
        temp.rows = rows;

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                temp.A[i][j] = A[i][j] + m.A[i][j];
            }
        }

        return temp;
    }

    Matrix operator*(Matrix& m){

        if(columns != m.rows){
            cout<<"\nMatrix multiplication not possible number of column of 1st matrix should be equal to number of row of 2nd matrix !"<<endl;
            return Matrix();
        }

        Matrix temp;

        temp.rows = rows;
        temp.columns = columns;

        for(int i=0;i<rows;i++){
            for(int j=0;j<m.columns;j++){
                temp.A[i][j] = 0;
                for(int k=0;k<columns;k++){
                    temp.A[i][j] += A[i][k] * m.A[k][j];
                }
            }
        }

        return temp;
    }

    bool operator==(Matrix& m){

        if(rows == m.rows || columns == m.columns){
            return false;
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(A[i][j] != m.A[i][j]){
                    return false;
                }
            }
        }
    }
};

int main(){

    Matrix m1,m2,m3;

    cout<<"Enter the details of Matrix 1 :- \n";
    m1.getData();
    cout<<"\nEnter the details of Matrix 2 :- \n";
    m2.getData();

    cout<<endl<<"Matrix 1:-"<<endl;
    m1.disp();
    cout<<endl<<"Matrix 2:-"<<endl;
    m2.disp();
    
    while(true){

        cout<<"\n\n1.Addition"<<endl
            <<"2.Multiplication"<<endl
            <<"3.Comparison"<<endl
            <<"0.Exit"<<endl;
        int choice;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){

            case 1 : {
                m3 = m1 + m2;
                if(m3.getRow() != 0){
                    cout<<"\nSum of Matrix 1 and Matrix 2 is :-"<<endl;
                    m3.disp();
                }
                break;
            }
            case 2 :{
                m3 = m1 * m2;
                if(m3.getRow() != 0){
                    cout<<"\nMultiplication of Matrix 1 and Matrix 2 is :-"<<endl;
                    m3.disp();
                }
                break;
            }
            case 3 :{
                if(m1 == m2){
                    cout<<"\nBoth matrices are equal!"<<endl;
                }else{
                    cout<<"\nBoth matrices are not equal!"<<endl;
                }
                break;
            }
            case 0 :{
                cout<<"\nExiting.........."<<endl<<endl;
                exit(0);
                break;
            }
            default : cout<<"\nInvalid choice..........Re-Try....!"<<endl;
        }

    }
    
    
}