#include<iostream>
using namespace std;
int main()
{
unsigned short int t;
unsigned long int *x,*y;
int i;
cin>>t;
x=new unsigned long int[t];
y=new unsigned long int[t];
for(i=0;i<t;i++)
{
cin>>x[i]>>y[i];
}
for(i=0;i<t;i++)
{
if(x[i]>y[i])
{
cout<<x[i]+y[i]<<endl;
}
else
{
cout<<y[i]-x[i]<<endl;
}
}
return 0;
}
