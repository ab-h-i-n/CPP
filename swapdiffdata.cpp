#include<iostream>
using namespace std;

    void swap(int x,int y)
    {
    cout<<"\nBefore swapping integer values\nValue 1 = "<<x<<"\nValue 2 = "<<y;
    int temp;
    temp=x;
    x=y;
    y=temp;
    cout<<"\nAfter swapping integer values\nValue 1 = "<<x<<"\nValue 2 = "<<y;
    }

    void swap(float x,float y)
    {
    cout<<"\n\nBefore swapping float values\nValue 1 = "<<x<<"\nValue 2 = "<<y;
    float temp;
    temp=x;
    x=y;
    y=temp;
    cout<<"\nAfter swapping float values\nValue 1 = "<<x<<"\nValue 2 = "<<y;
    }

    void swap(char x,char y)
    {
    cout<<"\n\nBefore swapping character values\nValue 1 = "<<x<<"\nValue 2 = "<<y;
    char temp;
    temp=x;
    x=y;
    y=temp;
    cout<<"\nAfter swapping character values\nValue 1 = "<<x<<"\nValue 2 = "<<y<<"\n";
    }

int main ()
{
int a,b;
float c,d;
char e,f;

cout<<"\nEnter 2 integer values for swapping : ";
cin>>a>>b;
swap(a,b);
cout<<"\n\nEnter 2 float values for swapping : ";
cin>>c>>d;
swap(c,d);
cout<<"\n\nEnter 2 characters for swapping : ";
cin>>e>>f;
swap(e,f);
return 0;
}