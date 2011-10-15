#include<iostream>

using namespace std;


long long modulo(long long a, long long b, long long c)
{
	long long x=1, y=a;
	while(b>0)
	{
		if(b%2 == 1)
		{
			x=(x*y)%c;
		}
		y=(y*y)%c;
		b/=2;
	}
	return x%c;
}

long long bruteforce(long long b, long long c)
{
	int i;
	long long ans=2;
	for(i=1;i<=b;i++)
	{
		ans=ans*ans;
		if(ans>=c)
			ans=ans%c;
	}
	return ans;
}

int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long cc=modulo(2,n,k);
		cout<<modulo(2,cc,k)<<"\n";
		
		//cout<<bruteforce(n,k)<<endl;
	}
	return 0;
}