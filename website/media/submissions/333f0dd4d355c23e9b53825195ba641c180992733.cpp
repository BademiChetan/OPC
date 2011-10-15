#include <iostream>
#include <cmath>

using namespace std;

unsigned long long n;

unsigned long long power(unsigned long long pw, unsigned long long k)
{
	unsigned long long ans=1ull,x=2ull;
	
	while(pw)
	{
		if(pw&1ull)
		  ans*=x;
		ans%=k;
		x*=x;
		x%=k;
		pw>>=1;
	}
	
	return ans%k;
}

int main(int argc, char **argv)
{
	int t;
	unsigned long long k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<power(power(n,(unsigned long long)floor(log2(k))),k)<<endl;
	}
	return 0;
}

