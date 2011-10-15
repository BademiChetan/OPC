# include<iostream>
# include<stdio.h>
# include<string.h>
int main()
{
	unsigned long long t,n,k,res=2,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)
			res=(res*res);
		res=res%k;
		printf("%lld\n",res);
		res=2;
	}
	return(0);
}
		
