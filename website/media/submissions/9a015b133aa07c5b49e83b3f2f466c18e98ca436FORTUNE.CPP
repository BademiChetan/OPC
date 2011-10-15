#include<iostream.h>
#include<math.h>
#include<stdlib.h>
void main()
{ int t;
cin>>t;
cout<<"\n";
if (1<=t<=1000)
{
 for (int i=0;i<t;i++)
 { int n;
   double k;

   cin>>n;
   cout<<"\t";
   cin>>k;
   if(n>=1&&k<=10^9)
  { n=pow(2,n);
   cout<<(int)n%(int)k;
  }
  else
  {exit(0);
   }
 }
 }
  else
   exit(0);

   }