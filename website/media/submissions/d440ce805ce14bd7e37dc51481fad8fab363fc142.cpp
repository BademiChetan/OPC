#include<iostream>
using namespace std;
int main()
{ int b,sum;
	 int t,n,a;
	 int t1=0;
	cin>>t;
	while(t--)
	{ sum=0;
          n=0;
	  cin>>n;
	  for(int i=0;i<n;i++)
	{	cin>>b;
		sum=sum+b;
	}
	  t1=(n-1)*(n);
	  t1=t1/2;
	  sum-=t1;
	  if(sum%2==0)
		cout<<"LOSE\n";
	 else
		cout<<"WIN\n";
	}
return 0;
}
