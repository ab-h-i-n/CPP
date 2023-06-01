#include<iostream>
using namespace std;
inline int add(int a, int b)
{
return a+b;
}
inline double division(double x, double y)
{
return x/y;
}
inline float difference(float a, float b)
{
return a-b;
}
inline int moduluss(int x, int y)
{
return x%y;
}
inline long int multiplication(long int a, long int b)
{
return a*b;
}
int main()
{
int a,b;
double x,y;
float i,j;
long int e,f;

cout<<"\nEnter 2 integer values for calculating there sum:\n";
cin>>a>>b;
cout<<"\nSum of "<<a<<"and "<<b<<" = "<<add(a,b)<<"\n";

cout<<"\nEnter 2 double values for performing division:\n";
cin>>x>>y;
cout<<"\nValue of "<<x<<" divided by "<<y<<" = "<<division(x,y)<<"\n";

cout<<"\nEnter 2 float values for calculating there difference :\n";
cin>>i>>j;
cout<<"\nDifference between "<<i<<" and "<<j<<" = "<<difference(i,j)<<"\n";

cout<<"\nEnter 2 integer values for calculating there modulus:\n";
cin>>a>>b;
cout<<"\n"<<a<<" modulus "<<b<<" = "<<moduluss(a,b)<<"\n";

cout<<"\nEnter 2 long integer values for calculating there product:\n";
cin>>e>>f;
cout<<"\nProduct of "<<e<<" and "<<f<<" = "<<multiplication(e,f)<<"\n";

return 0;
}