#include<iostream>
using namespace std;
int main()
{	int b,sum=0;
	int t,n,a,t1;
	cin>>t;
	while(t--)
	{ sum=0;
	  cin>>n;
	if(n==1)
	  sum=n;
	  for(int i=0;i<n;i++)
	{	cin>>b;
		sum=sum+b;
	}
	  t1=(n-1)*(n-2);
	  t1=t1/2;
	  sum-=t1;
	  if(sum%2==0)
		cout<<"WIN";
	 else
		cout<<"LOSE";
	}
return 0;
}
