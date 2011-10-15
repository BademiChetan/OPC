#include<stdio.h>
long int k;
long square(long n) { return (n*n)%k; }
long fastexp(long base,long power) {
if (power == 0)
return 1;
else if (power%2 == 0)
return square(fastexp(base,power/2));
else
return (base * (fastexp(base,power-1)))%k;
}
main()
{
	int t;
	long int n,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		ans=fastexp(2,fastexp(2,n));
		printf("%ld\n",ans);
	}
	return 0;
}