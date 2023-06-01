#include<iostream>
using namespace std;
int factorial(int n)
{
int fact;
if(n==1 || n==0)
{
return 1;
}
fact=n*factorial(n-1); //recursive function
return fact;
}
int main()
{
int n,i,sum=0;
cout<<"\nEnter the number of terms\n";
cin >>n;
for(i=1;i<=n;i++)
{
sum+=factorial(i);
}
cout<<"Sum of factorial of first "<<n<<" number is "<<sum;
return 0;
}