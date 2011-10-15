#include<stdio.h>
long int k;
main()
{
	int t;
	long int i,n,ans,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&k);
		a=1;
		for(i=0;i<n;i++)
		{
		a=(a<<1)%k;
		}		
		
		ans=1;
		for(i=0;i<a;i++)
		{
		ans=(ans<<1)%k;
		}
		printf("%ld\n",ans);
	}
	return 0;
}