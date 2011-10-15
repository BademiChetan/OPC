#include<cstdio>
#include<cmath>
using namespace std;
long long mod(long long a,long long b)
{
	long long p=2,ans=1;
	while(a)
	{
		if(a & 1)
		{
			ans=(ans*p)%b;
		}
		a=a>>1;
		p=(p*p)%b;
	}
	return ans;
}
int main()
{
	long long T,N,K,a,s;
	scanf("%Ld",&T);
	while(T--)
	{
		s=0;
		scanf("%Ld%Ld",&N,&K);
		if((N*(N+1)/2)%K==0) s=1;
		a=mod(N,1000000007);
		a+=1000000007;
		a=((a-2)%1000000007)/K;
		a=(a+1+s)%1000000007;
		printf("%Ld\n",a);
	}
}
