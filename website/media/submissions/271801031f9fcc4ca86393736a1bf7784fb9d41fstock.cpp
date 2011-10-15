#include<iostream>
#include<math.h>
using namespace std;
int main()
{
unsigned short int t;
unsigned long int *n,*k;
int s,i;
cin>>t;
n=new unsigned long int [t];
k=new unsigned long int [t];
for(i=0;i<t;i++)
{
cin>>n[i]>>k[i];
if(k[i]/2!=0)
{
n[i]=pow(2,(pow(2,n[i])));
}
}
for(i=0;i<t;i++)
{
cout<<n[i]<<endl;
}
return 0;
}
