#include<stdio.h>

long long exp(long long b,long long k)
{
	if(b==0)return 1;
	if(b==1)return 2;

	//printf("%lld \t", b);

	long long t=exp(b/2,k);

	if(b%2==0)return (t*t)%k;
	else return (t*t*2)%k;
	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,k;
		scanf("%lld %lld",&n,&k);	
		long long b=exp(n,k-1);
		//printf("%lld\n",b);
		printf("%lld\n",exp(b,k));
	}
	return 0;
}
