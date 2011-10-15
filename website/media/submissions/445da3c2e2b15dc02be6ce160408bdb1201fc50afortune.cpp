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

int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<modulo(4,n,k)<<endl;
	}
	return 0;
}
