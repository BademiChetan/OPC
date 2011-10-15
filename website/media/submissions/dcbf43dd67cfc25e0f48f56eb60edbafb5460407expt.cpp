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
long long phi(long long x) {

	long long ret = 1,i,pow;

	for (i = 2; x != 1; i++) {
		pow = 1;
		while (!(x%i)) {
			x /= i;
			pow *= i;
		}
		ret *= (pow - (pow/i));
	}
	return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,k;
		scanf("%lld %lld",&n,&k);	
		long long b=exp(n,phi(k));
		//printf("%lld\n",b);
		printf("%lld\n",exp(b,k));
	}
	return 0;
}
