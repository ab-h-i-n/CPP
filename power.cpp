#include<iostream>
using namespace std;
void power(double m , int n)
{
    int i,p=1;
    for(i=0;i<n;i++)
        p *= m;
    cout<<m<<" raise to "<<n<<" is : "<<p<<"\n";
}
int main()
{
    double m;
    int n,choice;
    void power(double m, int n=4);
    top:

    cout<<"1.Only m \n2.m and n\nEnter your choice : ";
    cin>>choice;
    
    switch (choice)
    {
    case 1 : cout<<"\nEnter the value for m (default value for n = 4): ";
             cin>>m;
             power(m);
             break;
    case 2 : cout<<"\nEnter the value for m and n : ";
             cin>>m>>n;
             power(m,n);
             break;
    default: cout<<"\nInvalid choice\n\n";
             goto top;
    }    
    return 0;
}

