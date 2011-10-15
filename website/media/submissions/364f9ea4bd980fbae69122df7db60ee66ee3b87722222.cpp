#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
long int t,s=2,n,a[1000][2],i,j,k,r;
cin>>t;
for(i=0;i<t;i++)
for(j=0;j<2;j++)
cin>>a[i][j];

for(i=0;i<t;i++)
{
  s=2;
  n=a[i][0];
  k=a[i][1];
  r=n%k;
  for(j=0;j<r;j++)
  {
   s=s*s;
   }
   
   cout<<s<<endl;
   }
  
   return 0;
   }
   
   
