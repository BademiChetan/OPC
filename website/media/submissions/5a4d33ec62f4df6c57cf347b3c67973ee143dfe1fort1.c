#include<stdio.h>
long powmod(long a,long b,long m)   //Function to calculate (a^b)mod m
{
	long result=1,power=a;
	if(b==0)
		return 1%m;
	while(b>0)
	{
		if(b%2==1)
			result = (result*power)%m;
		power=(power*power)%m;
		b=b/2;
	}
	if(result==1)
	   return power;
	else
	   return result;

}
int main()
{
	int t;
	long n,k,r;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		scanf("%ld",&k);
		r=powmod(2,1<<n,k);
		printf("%ld\n",r);
	}
	return 0;
}