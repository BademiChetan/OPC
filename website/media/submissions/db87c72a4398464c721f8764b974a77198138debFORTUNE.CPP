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
 { int n,a=2;
	double k;

	cin>>n;
	cout<<"\t";
	cin>>k;
	if(n>=1&&k<=(pow(10,9)))
  {
  for(int i=0;i<n;i++)
  a=pow(a,2);
	cout<<(int)a%(int)k;
   cout<<"\n";
  }
  else
  {exit(0);
   }
 }
 }
  else
   exit(0);

	}