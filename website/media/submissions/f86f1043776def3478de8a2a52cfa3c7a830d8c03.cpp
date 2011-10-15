#include <iostream>

using namespace std;

unsigned long long n,k;

unsigned long long power(unsigned long long pw)
{
	unsigned long long ans=1ull,x=2ull;
	
	while(pw)
	{
		if(pw&1)
		  ans*=x;
		ans%=k;
		x*=x;
		x%=k;
		pw>>=1;
	}
	
	return ans;
}

int main(int argc, char **argv)
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<power(power(n))<<endl;
	}
	return 0;
}

