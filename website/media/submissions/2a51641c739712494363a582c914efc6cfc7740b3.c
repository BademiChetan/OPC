#include<stdio.h>
int main()
{
	long long int i,n,sum,k;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		sum = 1;
		for(i=0;i<k-1;i++)
			sum = sum*2;
		printf("%lld\n",sum);
	}
	
	return 0;
}
