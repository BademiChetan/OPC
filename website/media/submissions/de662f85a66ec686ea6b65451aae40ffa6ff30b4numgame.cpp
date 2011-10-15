#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long n;
		cin>>n;
		long i,j,k,x,sum=0;
		t=n-1;
		for(i=0;i<n;i++)
		{
			cin>>x;
			sum+=x;
		}
		long p=(t*(t+1))/2;
		long ans=sum-p;
		if(ans%2==0) cout<<"LOSE"<<endl;
		else cout<<"WIN"<<endl;
	}
}
